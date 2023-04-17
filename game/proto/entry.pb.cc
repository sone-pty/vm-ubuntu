// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: game/proto/entry.proto

#include "game/proto/entry.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace Entry {
constexpr C2E_LoginRequest::C2E_LoginRequest(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : account_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , passwd_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct C2E_LoginRequestDefaultTypeInternal {
  constexpr C2E_LoginRequestDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~C2E_LoginRequestDefaultTypeInternal() {}
  union {
    C2E_LoginRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT C2E_LoginRequestDefaultTypeInternal _C2E_LoginRequest_default_instance_;
constexpr E2C_LoginResponse::E2C_LoginResponse(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : responsetype_(0)
{}
struct E2C_LoginResponseDefaultTypeInternal {
  constexpr E2C_LoginResponseDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~E2C_LoginResponseDefaultTypeInternal() {}
  union {
    E2C_LoginResponse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT E2C_LoginResponseDefaultTypeInternal _E2C_LoginResponse_default_instance_;
}  // namespace Entry
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_game_2fproto_2fentry_2eproto[2];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_game_2fproto_2fentry_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_game_2fproto_2fentry_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_game_2fproto_2fentry_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Entry::C2E_LoginRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Entry::C2E_LoginRequest, account_),
  PROTOBUF_FIELD_OFFSET(::Entry::C2E_LoginRequest, passwd_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Entry::E2C_LoginResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Entry::E2C_LoginResponse, responsetype_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::Entry::C2E_LoginRequest)},
  { 7, -1, sizeof(::Entry::E2C_LoginResponse)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Entry::_C2E_LoginRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Entry::_E2C_LoginResponse_default_instance_),
};

const char descriptor_table_protodef_game_2fproto_2fentry_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\026game/proto/entry.proto\022\005Entry\"3\n\020C2E_L"
  "oginRequest\022\017\n\007account\030\001 \001(\t\022\016\n\006passwd\030\002"
  " \001(\t\"H\n\021E2C_LoginResponse\0223\n\014responseTyp"
  "e\030\001 \001(\0162\035.Entry.ENTRY_MESSAGE_RESPONSE*/"
  "\n\026ENTRY_RECV_MESSAGETYPE\022\025\n\021C2E_LOGIN_ME"
  "SSAGE\020\000*1\n\026ENTRY_SEND_MESSAGETYPE\022\027\n\023E2C"
  "_LOGIN_R_MESSAGE\020\000*O\n\026ENTRY_MESSAGE_RESP"
  "ONSE\022\006\n\002OK\020\000\022\026\n\022PASSWD_AUTH_FAILED\020\001\022\025\n\021"
  "NO_ACCOUNT_RECORD\020\002b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_game_2fproto_2fentry_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_game_2fproto_2fentry_2eproto = {
  false, false, 347, descriptor_table_protodef_game_2fproto_2fentry_2eproto, "game/proto/entry.proto", 
  &descriptor_table_game_2fproto_2fentry_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_game_2fproto_2fentry_2eproto::offsets,
  file_level_metadata_game_2fproto_2fentry_2eproto, file_level_enum_descriptors_game_2fproto_2fentry_2eproto, file_level_service_descriptors_game_2fproto_2fentry_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_game_2fproto_2fentry_2eproto_getter() {
  return &descriptor_table_game_2fproto_2fentry_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_game_2fproto_2fentry_2eproto(&descriptor_table_game_2fproto_2fentry_2eproto);
namespace Entry {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ENTRY_RECV_MESSAGETYPE_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_game_2fproto_2fentry_2eproto);
  return file_level_enum_descriptors_game_2fproto_2fentry_2eproto[0];
}
bool ENTRY_RECV_MESSAGETYPE_IsValid(int value) {
  switch (value) {
    case 0:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ENTRY_SEND_MESSAGETYPE_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_game_2fproto_2fentry_2eproto);
  return file_level_enum_descriptors_game_2fproto_2fentry_2eproto[1];
}
bool ENTRY_SEND_MESSAGETYPE_IsValid(int value) {
  switch (value) {
    case 0:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ENTRY_MESSAGE_RESPONSE_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_game_2fproto_2fentry_2eproto);
  return file_level_enum_descriptors_game_2fproto_2fentry_2eproto[2];
}
bool ENTRY_MESSAGE_RESPONSE_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}


// ===================================================================

class C2E_LoginRequest::_Internal {
 public:
};

C2E_LoginRequest::C2E_LoginRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Entry.C2E_LoginRequest)
}
C2E_LoginRequest::C2E_LoginRequest(const C2E_LoginRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  account_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_account().empty()) {
    account_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_account(), 
      GetArenaForAllocation());
  }
  passwd_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_passwd().empty()) {
    passwd_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_passwd(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:Entry.C2E_LoginRequest)
}

inline void C2E_LoginRequest::SharedCtor() {
account_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
passwd_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

C2E_LoginRequest::~C2E_LoginRequest() {
  // @@protoc_insertion_point(destructor:Entry.C2E_LoginRequest)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void C2E_LoginRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  account_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  passwd_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void C2E_LoginRequest::ArenaDtor(void* object) {
  C2E_LoginRequest* _this = reinterpret_cast< C2E_LoginRequest* >(object);
  (void)_this;
}
void C2E_LoginRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void C2E_LoginRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void C2E_LoginRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:Entry.C2E_LoginRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  account_.ClearToEmpty();
  passwd_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* C2E_LoginRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string account = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_account();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Entry.C2E_LoginRequest.account"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string passwd = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_passwd();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Entry.C2E_LoginRequest.passwd"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* C2E_LoginRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Entry.C2E_LoginRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string account = 1;
  if (!this->_internal_account().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_account().data(), static_cast<int>(this->_internal_account().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Entry.C2E_LoginRequest.account");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_account(), target);
  }

  // string passwd = 2;
  if (!this->_internal_passwd().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_passwd().data(), static_cast<int>(this->_internal_passwd().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Entry.C2E_LoginRequest.passwd");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_passwd(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Entry.C2E_LoginRequest)
  return target;
}

size_t C2E_LoginRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Entry.C2E_LoginRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string account = 1;
  if (!this->_internal_account().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_account());
  }

  // string passwd = 2;
  if (!this->_internal_passwd().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_passwd());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData C2E_LoginRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    C2E_LoginRequest::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*C2E_LoginRequest::GetClassData() const { return &_class_data_; }

void C2E_LoginRequest::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<C2E_LoginRequest *>(to)->MergeFrom(
      static_cast<const C2E_LoginRequest &>(from));
}


void C2E_LoginRequest::MergeFrom(const C2E_LoginRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Entry.C2E_LoginRequest)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_account().empty()) {
    _internal_set_account(from._internal_account());
  }
  if (!from._internal_passwd().empty()) {
    _internal_set_passwd(from._internal_passwd());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void C2E_LoginRequest::CopyFrom(const C2E_LoginRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Entry.C2E_LoginRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool C2E_LoginRequest::IsInitialized() const {
  return true;
}

void C2E_LoginRequest::InternalSwap(C2E_LoginRequest* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &account_, GetArenaForAllocation(),
      &other->account_, other->GetArenaForAllocation()
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &passwd_, GetArenaForAllocation(),
      &other->passwd_, other->GetArenaForAllocation()
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata C2E_LoginRequest::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_game_2fproto_2fentry_2eproto_getter, &descriptor_table_game_2fproto_2fentry_2eproto_once,
      file_level_metadata_game_2fproto_2fentry_2eproto[0]);
}

// ===================================================================

class E2C_LoginResponse::_Internal {
 public:
};

E2C_LoginResponse::E2C_LoginResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Entry.E2C_LoginResponse)
}
E2C_LoginResponse::E2C_LoginResponse(const E2C_LoginResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  responsetype_ = from.responsetype_;
  // @@protoc_insertion_point(copy_constructor:Entry.E2C_LoginResponse)
}

inline void E2C_LoginResponse::SharedCtor() {
responsetype_ = 0;
}

E2C_LoginResponse::~E2C_LoginResponse() {
  // @@protoc_insertion_point(destructor:Entry.E2C_LoginResponse)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void E2C_LoginResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void E2C_LoginResponse::ArenaDtor(void* object) {
  E2C_LoginResponse* _this = reinterpret_cast< E2C_LoginResponse* >(object);
  (void)_this;
}
void E2C_LoginResponse::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void E2C_LoginResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void E2C_LoginResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:Entry.E2C_LoginResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  responsetype_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* E2C_LoginResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .Entry.ENTRY_MESSAGE_RESPONSE responseType = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_responsetype(static_cast<::Entry::ENTRY_MESSAGE_RESPONSE>(val));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* E2C_LoginResponse::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Entry.E2C_LoginResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .Entry.ENTRY_MESSAGE_RESPONSE responseType = 1;
  if (this->_internal_responsetype() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_responsetype(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Entry.E2C_LoginResponse)
  return target;
}

size_t E2C_LoginResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Entry.E2C_LoginResponse)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .Entry.ENTRY_MESSAGE_RESPONSE responseType = 1;
  if (this->_internal_responsetype() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_responsetype());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData E2C_LoginResponse::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    E2C_LoginResponse::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*E2C_LoginResponse::GetClassData() const { return &_class_data_; }

void E2C_LoginResponse::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<E2C_LoginResponse *>(to)->MergeFrom(
      static_cast<const E2C_LoginResponse &>(from));
}


void E2C_LoginResponse::MergeFrom(const E2C_LoginResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Entry.E2C_LoginResponse)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_responsetype() != 0) {
    _internal_set_responsetype(from._internal_responsetype());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void E2C_LoginResponse::CopyFrom(const E2C_LoginResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Entry.E2C_LoginResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool E2C_LoginResponse::IsInitialized() const {
  return true;
}

void E2C_LoginResponse::InternalSwap(E2C_LoginResponse* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(responsetype_, other->responsetype_);
}

::PROTOBUF_NAMESPACE_ID::Metadata E2C_LoginResponse::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_game_2fproto_2fentry_2eproto_getter, &descriptor_table_game_2fproto_2fentry_2eproto_once,
      file_level_metadata_game_2fproto_2fentry_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Entry
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Entry::C2E_LoginRequest* Arena::CreateMaybeMessage< ::Entry::C2E_LoginRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Entry::C2E_LoginRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::Entry::E2C_LoginResponse* Arena::CreateMaybeMessage< ::Entry::E2C_LoginResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Entry::E2C_LoginResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
