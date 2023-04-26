// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: game/proto/list.proto

#ifndef PROTOBUF_INCLUDED_game_2fproto_2flist_2eproto
#define PROTOBUF_INCLUDED_game_2fproto_2flist_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_game_2fproto_2flist_2eproto 

namespace protobuf_game_2fproto_2flist_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_game_2fproto_2flist_2eproto
namespace List {
class E2L_UploadLoading;
class E2L_UploadLoadingDefaultTypeInternal;
extern E2L_UploadLoadingDefaultTypeInternal _E2L_UploadLoading_default_instance_;
}  // namespace List
namespace google {
namespace protobuf {
template<> ::List::E2L_UploadLoading* Arena::CreateMaybeMessage<::List::E2L_UploadLoading>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace List {

enum LIST_RECV_MESSAGETYPE {
  E2L_UPLOAD_LOADING_MESSAGE = 0,
  LIST_RECV_MESSAGETYPE_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  LIST_RECV_MESSAGETYPE_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool LIST_RECV_MESSAGETYPE_IsValid(int value);
const LIST_RECV_MESSAGETYPE LIST_RECV_MESSAGETYPE_MIN = E2L_UPLOAD_LOADING_MESSAGE;
const LIST_RECV_MESSAGETYPE LIST_RECV_MESSAGETYPE_MAX = E2L_UPLOAD_LOADING_MESSAGE;
const int LIST_RECV_MESSAGETYPE_ARRAYSIZE = LIST_RECV_MESSAGETYPE_MAX + 1;

const ::google::protobuf::EnumDescriptor* LIST_RECV_MESSAGETYPE_descriptor();
inline const ::std::string& LIST_RECV_MESSAGETYPE_Name(LIST_RECV_MESSAGETYPE value) {
  return ::google::protobuf::internal::NameOfEnum(
    LIST_RECV_MESSAGETYPE_descriptor(), value);
}
inline bool LIST_RECV_MESSAGETYPE_Parse(
    const ::std::string& name, LIST_RECV_MESSAGETYPE* value) {
  return ::google::protobuf::internal::ParseNamedEnum<LIST_RECV_MESSAGETYPE>(
    LIST_RECV_MESSAGETYPE_descriptor(), name, value);
}
enum LIST_SEND_MESSAGETYPE {
  L2C_ENTRY_CHOICE_MESSAGE = 0,
  LIST_SEND_MESSAGETYPE_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  LIST_SEND_MESSAGETYPE_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool LIST_SEND_MESSAGETYPE_IsValid(int value);
const LIST_SEND_MESSAGETYPE LIST_SEND_MESSAGETYPE_MIN = L2C_ENTRY_CHOICE_MESSAGE;
const LIST_SEND_MESSAGETYPE LIST_SEND_MESSAGETYPE_MAX = L2C_ENTRY_CHOICE_MESSAGE;
const int LIST_SEND_MESSAGETYPE_ARRAYSIZE = LIST_SEND_MESSAGETYPE_MAX + 1;

const ::google::protobuf::EnumDescriptor* LIST_SEND_MESSAGETYPE_descriptor();
inline const ::std::string& LIST_SEND_MESSAGETYPE_Name(LIST_SEND_MESSAGETYPE value) {
  return ::google::protobuf::internal::NameOfEnum(
    LIST_SEND_MESSAGETYPE_descriptor(), value);
}
inline bool LIST_SEND_MESSAGETYPE_Parse(
    const ::std::string& name, LIST_SEND_MESSAGETYPE* value) {
  return ::google::protobuf::internal::ParseNamedEnum<LIST_SEND_MESSAGETYPE>(
    LIST_SEND_MESSAGETYPE_descriptor(), name, value);
}
// ===================================================================

class E2L_UploadLoading : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:List.E2L_UploadLoading) */ {
 public:
  E2L_UploadLoading();
  virtual ~E2L_UploadLoading();

  E2L_UploadLoading(const E2L_UploadLoading& from);

  inline E2L_UploadLoading& operator=(const E2L_UploadLoading& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  E2L_UploadLoading(E2L_UploadLoading&& from) noexcept
    : E2L_UploadLoading() {
    *this = ::std::move(from);
  }

  inline E2L_UploadLoading& operator=(E2L_UploadLoading&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const E2L_UploadLoading& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const E2L_UploadLoading* internal_default_instance() {
    return reinterpret_cast<const E2L_UploadLoading*>(
               &_E2L_UploadLoading_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(E2L_UploadLoading* other);
  friend void swap(E2L_UploadLoading& a, E2L_UploadLoading& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline E2L_UploadLoading* New() const final {
    return CreateMaybeMessage<E2L_UploadLoading>(NULL);
  }

  E2L_UploadLoading* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<E2L_UploadLoading>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const E2L_UploadLoading& from);
  void MergeFrom(const E2L_UploadLoading& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(E2L_UploadLoading* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string ipInfo = 1;
  void clear_ipinfo();
  static const int kIpInfoFieldNumber = 1;
  const ::std::string& ipinfo() const;
  void set_ipinfo(const ::std::string& value);
  #if LANG_CXX11
  void set_ipinfo(::std::string&& value);
  #endif
  void set_ipinfo(const char* value);
  void set_ipinfo(const char* value, size_t size);
  ::std::string* mutable_ipinfo();
  ::std::string* release_ipinfo();
  void set_allocated_ipinfo(::std::string* ipinfo);

  // int64 updateTime = 3;
  void clear_updatetime();
  static const int kUpdateTimeFieldNumber = 3;
  ::google::protobuf::int64 updatetime() const;
  void set_updatetime(::google::protobuf::int64 value);

  // int32 loadingWeight = 2;
  void clear_loadingweight();
  static const int kLoadingWeightFieldNumber = 2;
  ::google::protobuf::int32 loadingweight() const;
  void set_loadingweight(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:List.E2L_UploadLoading)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr ipinfo_;
  ::google::protobuf::int64 updatetime_;
  ::google::protobuf::int32 loadingweight_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_game_2fproto_2flist_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// E2L_UploadLoading

// string ipInfo = 1;
inline void E2L_UploadLoading::clear_ipinfo() {
  ipinfo_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& E2L_UploadLoading::ipinfo() const {
  // @@protoc_insertion_point(field_get:List.E2L_UploadLoading.ipInfo)
  return ipinfo_.GetNoArena();
}
inline void E2L_UploadLoading::set_ipinfo(const ::std::string& value) {
  
  ipinfo_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:List.E2L_UploadLoading.ipInfo)
}
#if LANG_CXX11
inline void E2L_UploadLoading::set_ipinfo(::std::string&& value) {
  
  ipinfo_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:List.E2L_UploadLoading.ipInfo)
}
#endif
inline void E2L_UploadLoading::set_ipinfo(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  ipinfo_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:List.E2L_UploadLoading.ipInfo)
}
inline void E2L_UploadLoading::set_ipinfo(const char* value, size_t size) {
  
  ipinfo_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:List.E2L_UploadLoading.ipInfo)
}
inline ::std::string* E2L_UploadLoading::mutable_ipinfo() {
  
  // @@protoc_insertion_point(field_mutable:List.E2L_UploadLoading.ipInfo)
  return ipinfo_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* E2L_UploadLoading::release_ipinfo() {
  // @@protoc_insertion_point(field_release:List.E2L_UploadLoading.ipInfo)
  
  return ipinfo_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void E2L_UploadLoading::set_allocated_ipinfo(::std::string* ipinfo) {
  if (ipinfo != NULL) {
    
  } else {
    
  }
  ipinfo_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ipinfo);
  // @@protoc_insertion_point(field_set_allocated:List.E2L_UploadLoading.ipInfo)
}

// int32 loadingWeight = 2;
inline void E2L_UploadLoading::clear_loadingweight() {
  loadingweight_ = 0;
}
inline ::google::protobuf::int32 E2L_UploadLoading::loadingweight() const {
  // @@protoc_insertion_point(field_get:List.E2L_UploadLoading.loadingWeight)
  return loadingweight_;
}
inline void E2L_UploadLoading::set_loadingweight(::google::protobuf::int32 value) {
  
  loadingweight_ = value;
  // @@protoc_insertion_point(field_set:List.E2L_UploadLoading.loadingWeight)
}

// int64 updateTime = 3;
inline void E2L_UploadLoading::clear_updatetime() {
  updatetime_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 E2L_UploadLoading::updatetime() const {
  // @@protoc_insertion_point(field_get:List.E2L_UploadLoading.updateTime)
  return updatetime_;
}
inline void E2L_UploadLoading::set_updatetime(::google::protobuf::int64 value) {
  
  updatetime_ = value;
  // @@protoc_insertion_point(field_set:List.E2L_UploadLoading.updateTime)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace List

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::List::LIST_RECV_MESSAGETYPE> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::List::LIST_RECV_MESSAGETYPE>() {
  return ::List::LIST_RECV_MESSAGETYPE_descriptor();
}
template <> struct is_proto_enum< ::List::LIST_SEND_MESSAGETYPE> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::List::LIST_SEND_MESSAGETYPE>() {
  return ::List::LIST_SEND_MESSAGETYPE_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_game_2fproto_2flist_2eproto