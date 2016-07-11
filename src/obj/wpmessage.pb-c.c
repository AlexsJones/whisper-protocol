/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: wpmessage.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "wpmessage.pb-c.h"
void   wpmessage__init
                     (Wpmessage         *message)
{
  static Wpmessage init_value = WPMESSAGE__INIT;
  *message = init_value;
}
size_t wpmessage__get_packed_size
                     (const Wpmessage *message)
{
  assert(message->base.descriptor == &wpmessage__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t wpmessage__pack
                     (const Wpmessage *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &wpmessage__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t wpmessage__pack_to_buffer
                     (const Wpmessage *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &wpmessage__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Wpmessage *
       wpmessage__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Wpmessage *)
     protobuf_c_message_unpack (&wpmessage__descriptor,
                                allocator, len, data);
}
void   wpmessage__free_unpacked
                     (Wpmessage *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &wpmessage__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   wpaction__init
                     (Wpaction         *message)
{
  static Wpaction init_value = WPACTION__INIT;
  *message = init_value;
}
size_t wpaction__get_packed_size
                     (const Wpaction *message)
{
  assert(message->base.descriptor == &wpaction__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t wpaction__pack
                     (const Wpaction *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &wpaction__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t wpaction__pack_to_buffer
                     (const Wpaction *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &wpaction__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Wpaction *
       wpaction__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Wpaction *)
     protobuf_c_message_unpack (&wpaction__descriptor,
                                allocator, len, data);
}
void   wpaction__free_unpacked
                     (Wpaction *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &wpaction__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   wpcontextdata__init
                     (Wpcontextdata         *message)
{
  static Wpcontextdata init_value = WPCONTEXTDATA__INIT;
  *message = init_value;
}
size_t wpcontextdata__get_packed_size
                     (const Wpcontextdata *message)
{
  assert(message->base.descriptor == &wpcontextdata__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t wpcontextdata__pack
                     (const Wpcontextdata *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &wpcontextdata__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t wpcontextdata__pack_to_buffer
                     (const Wpcontextdata *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &wpcontextdata__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Wpcontextdata *
       wpcontextdata__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Wpcontextdata *)
     protobuf_c_message_unpack (&wpcontextdata__descriptor,
                                allocator, len, data);
}
void   wpcontextdata__free_unpacked
                     (Wpcontextdata *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &wpcontextdata__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor wpmessage__field_descriptors[4] =
{
  {
    "id",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Wpmessage, id),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "sender",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Wpmessage, sender),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "recipient",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Wpmessage, recipient),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "action",
    4,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Wpmessage, action),
    &wpaction__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned wpmessage__field_indices_by_name[] = {
  3,   /* field[3] = action */
  0,   /* field[0] = id */
  2,   /* field[2] = recipient */
  1,   /* field[1] = sender */
};
static const ProtobufCIntRange wpmessage__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor wpmessage__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "wpmessage",
  "Wpmessage",
  "Wpmessage",
  "",
  sizeof(Wpmessage),
  4,
  wpmessage__field_descriptors,
  wpmessage__field_indices_by_name,
  1,  wpmessage__number_ranges,
  (ProtobufCMessageInit) wpmessage__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const SelectedAction wpaction__action__default_value = SELECTED_ACTION__CREATE_SESSION;
static const ProtobufCFieldDescriptor wpaction__field_descriptors[2] =
{
  {
    "action",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(Wpaction, action),
    &selected_action__descriptor,
    &wpaction__action__default_value,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "contextdata",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Wpaction, contextdata),
    &wpcontextdata__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned wpaction__field_indices_by_name[] = {
  0,   /* field[0] = action */
  1,   /* field[1] = contextdata */
};
static const ProtobufCIntRange wpaction__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor wpaction__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "wpaction",
  "Wpaction",
  "Wpaction",
  "",
  sizeof(Wpaction),
  2,
  wpaction__field_descriptors,
  wpaction__field_indices_by_name,
  1,  wpaction__number_ranges,
  (ProtobufCMessageInit) wpaction__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor wpcontextdata__field_descriptors[1] =
{
  {
    "rawdata",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    offsetof(Wpcontextdata, has_rawdata),
    offsetof(Wpcontextdata, rawdata),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned wpcontextdata__field_indices_by_name[] = {
  0,   /* field[0] = rawdata */
};
static const ProtobufCIntRange wpcontextdata__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor wpcontextdata__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "wpcontextdata",
  "Wpcontextdata",
  "Wpcontextdata",
  "",
  sizeof(Wpcontextdata),
  1,
  wpcontextdata__field_descriptors,
  wpcontextdata__field_indices_by_name,
  1,  wpcontextdata__number_ranges,
  (ProtobufCMessageInit) wpcontextdata__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCEnumValue selected_action__enum_values_by_number[5] =
{
  { "CREATE_SESSION", "SELECTED_ACTION__CREATE_SESSION", 0 },
  { "RESPONDING_CREATED_SESSION", "SELECTED_ACTION__RESPONDING_CREATED_SESSION", 1 },
  { "SHARING_SESSION_KEY", "SELECTED_ACTION__SHARING_SESSION_KEY", 2 },
  { "COMPLETED_SESSION", "SELECTED_ACTION__COMPLETED_SESSION", 3 },
  { "COMMUNICATING_SESSION", "SELECTED_ACTION__COMMUNICATING_SESSION", 4 },
};
static const ProtobufCIntRange selected_action__value_ranges[] = {
{0, 0},{0, 5}
};
static const ProtobufCEnumValueIndex selected_action__enum_values_by_name[5] =
{
  { "COMMUNICATING_SESSION", 4 },
  { "COMPLETED_SESSION", 3 },
  { "CREATE_SESSION", 0 },
  { "RESPONDING_CREATED_SESSION", 1 },
  { "SHARING_SESSION_KEY", 2 },
};
const ProtobufCEnumDescriptor selected_action__descriptor =
{
  PROTOBUF_C__ENUM_DESCRIPTOR_MAGIC,
  "selectedAction",
  "selectedAction",
  "SelectedAction",
  "",
  5,
  selected_action__enum_values_by_number,
  5,
  selected_action__enum_values_by_name,
  1,
  selected_action__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};