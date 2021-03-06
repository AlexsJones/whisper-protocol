/*********************************************************************************
 *     File Name           :     test/test_objects.c
 *     Created By          :     anon
 *     Creation Date       :     [2015-12-17 13:15]
 *     Last Modified       :     [2016-06-09 13:41]
 *     Description         :      
 **********************************************************************************/
#include "wpprotocol.h"
#include "wpmux.h"
#include "wpmessage.pb-c.h"
#include <jnxc_headers/jnx_check.h>
#include <jnxc_headers/jnx_log.h>
#include <jnxc_headers/jnx_thread.h>
#define TESTPORT "9092"

static jnx_size *msg_size;
jnx_char *generate_message_str() {
  Wpmessage *message;
  jnx_char *data = malloc(strlen("Hello"));
  bzero(data,6);
  memcpy(data,"Hello",6);
  wp_generation_state w = wpprotocol_generate_message(&message,"00000000000001","001","002",
      data,6,SELECTED_ACTION__CREATE_SESSION);

  JNXCHECK(w == E_WGS_OKAY);
  free(data);
  jnx_size s = wpmessage__get_packed_size(message);
  jnx_char *obuffer = malloc(s);
  msg_size = wpmessage__pack(message,obuffer);
  return obuffer;
}
Wpmessage *generate_message() {
  Wpmessage *message= NULL;
  jnx_size *osize;
  jnx_char *data = malloc(strlen("Hello"));
  bzero(data,6);
  memcpy(data,"Hello",6);
  wp_generation_state w = wpprotocol_generate_message(&message,"00000000000001","001","002",
      data,6,SELECTED_ACTION__CREATE_SESSION);

  Wpaction *a = message->action;
  Wpcontextdata *contextdata = a->contextdata;

  JNXCHECK(contextdata->has_rawdata);
  if(contextdata->has_rawdata) {
    printf("lenth of value: %d\n", contextdata->rawdata.len);
    printf("content: %s\n", contextdata->rawdata.data);
  }
  JNXCHECK(w == E_WGS_OKAY);
  JNXCHECK(message);
  return message;
}
static int has_emitted = 0;
void test_mux_cb(Wpmessage *message) {
  JNXLOG(LDEBUG,"Emitting message...");
  has_emitted = 1;
}
void test_mux_create() {

  wp_mux *m = wpprotocol_mux_create(TESTPORT,AF_INET,test_mux_cb,NULL);
  JNXCHECK(m);
  wpprotocol_mux_destroy(&m);
}
void test_mux_tick() {
  wp_mux *m = wpprotocol_mux_create(TESTPORT,AF_INET,test_mux_cb,NULL);
  JNXCHECK(m);
  JNXLOG(LDEBUG,"Ticking..."); 
  wpprotocol_mux_tick(m); 
  JNXCHECK(m->out_queue->count == 0); 
  JNXCHECK(m->in_queue->count == 0); 
  wpprotocol_mux_destroy(&m);
}
void test_mux_outqueue() {

  wp_mux *m = wpprotocol_mux_create(TESTPORT,AF_INET,test_mux_cb,NULL);
  Wpmessage *message;
  jnx_char *data = malloc(strlen("Hello"));
  bzero(data,6);
  memcpy(data,"Hello",6);
  wp_generation_state w = wpprotocol_generate_message(&message,"00000000000001","001","002",
      data,6,SELECTED_ACTION__CREATE_SESSION);

  JNXCHECK(message);
  JNXLOG(LDEBUG,"generated message: length of value: %d", message->action->contextdata->rawdata.len);
  JNXLOG(LDEBUG,"generated message: %s",message->action->contextdata->rawdata.data); 
  free(data);

  jnx_stack_push(m->out_queue,message);
  
  JNXLOG(LDEBUG,"Ticking..."); 
  Wpmessage *o;
  JNXCHECK(m->out_queue->count == 1); 
  wpprotocol_mux_pop(m,&o);
  JNXCHECK(m->out_queue->count == 0); 

  JNXCHECK(o->action->contextdata->has_rawdata);
  printf("lenth of value: %d\n", o->action->contextdata->rawdata.len);
  printf("%s\n",o->action->contextdata->rawdata.data); 
  
  JNXCHECK(o);
  //wpmessage__free_unpacked(o,NULL);
  JNXCHECK(m->in_queue->count == 0); 
  wpprotocol_mux_destroy(&m);
}
void test_inqueue() {
  wp_mux *m = wpprotocol_mux_create(TESTPORT,AF_INET,test_mux_cb,NULL);
  JNXCHECK(m);

  Wpmessage *d = generate_message();
  JNXCHECK(E_WMS_OKAY == wpprotocol_mux_push(m,d));
  wpmessage__free_unpacked(d,NULL);
  JNXLOG(LDEBUG,"deleted reference to local message pointer");
  JNXLOG(LDEBUG,"Ticking...");
  wpprotocol_mux_tick(m); 

  JNXCHECK(has_emitted == 1); 
  wpprotocol_mux_destroy(&m);

}
void worker(void *args) {
  wp_mux *m = args;
  jnx_socket *t = jnx_socket_tcp_create(AF_INET);
  jnx_char *msg = generate_message_str();

  jnx_socket_tcp_send(t,"127.0.0.1",TESTPORT,msg,msg_size);
  jnx_socket_destroy(&t);
  free(msg);
}
void test_typical_use() {

  has_emitted = 0;
  wp_mux *m = wpprotocol_mux_create(TESTPORT,AF_INET,test_mux_cb,NULL);
  JNXCHECK(m);

  worker(m);
  wpprotocol_mux_tick(m); 
  wpprotocol_mux_tick(m); 

  Wpmessage *outmessage;
  wp_mux_state state = wpprotocol_mux_pop(m,&outmessage);
  JNXCHECK(state == E_WMS_OKAY);
  Wpmessage *output = outmessage;
  JNXCHECK(output);
  JNXCHECK(output->action);
  Wpaction *a = output->action;
  Wpcontextdata *contextdata = a->contextdata;

  JNXCHECK(contextdata->has_rawdata);
  if(contextdata->has_rawdata) {
    printf("lenth of value: %d\n", contextdata->rawdata.len);
    printf("content: %s\n", contextdata->rawdata.data);
  }

  JNXCHECK(strcmp(contextdata->rawdata.data,"Hello") == 0);
  JNXCHECK(output);  
  wpprotocol_mux_destroy(&m);
}
int main(int argc, char **argv) {
  JNXLOG(LDEBUG,"text_mux_create");
  test_mux_create();
  JNXLOG(LDEBUG,"test_mux_tick");
  test_mux_tick();
  JNXLOG(LDEBUG,"test_mux_outqueue");
  test_mux_outqueue();
  JNXLOG(LDEBUG,"test_inqueue");
  test_inqueue();
  JNXLOG(LDEBUG,"test_typical_use");
  test_typical_use();
  return 0;
}
