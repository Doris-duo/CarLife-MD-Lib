// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CarlifeBTPairInfoProto.proto

#ifndef PROTOBUF_CarlifeBTPairInfoProto_2eproto__INCLUDED
#define PROTOBUF_CarlifeBTPairInfoProto_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace com {
namespace baidu {
namespace carlife {
namespace protobuf {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_CarlifeBTPairInfoProto_2eproto();
void protobuf_AssignDesc_CarlifeBTPairInfoProto_2eproto();
void protobuf_ShutdownFile_CarlifeBTPairInfoProto_2eproto();

class CarlifeBTPairInfo;

// ===================================================================

class CarlifeBTPairInfo : public ::google::protobuf::Message {
 public:
  CarlifeBTPairInfo();
  virtual ~CarlifeBTPairInfo();

  CarlifeBTPairInfo(const CarlifeBTPairInfo& from);

  inline CarlifeBTPairInfo& operator=(const CarlifeBTPairInfo& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CarlifeBTPairInfo& default_instance();

  void Swap(CarlifeBTPairInfo* other);

  // implements Message ----------------------------------------------

  CarlifeBTPairInfo* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CarlifeBTPairInfo& from);
  void MergeFrom(const CarlifeBTPairInfo& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string address = 1;
  inline bool has_address() const;
  inline void clear_address();
  static const int kAddressFieldNumber = 1;
  inline const ::std::string& address() const;
  inline void set_address(const ::std::string& value);
  inline void set_address(const char* value);
  inline void set_address(const char* value, size_t size);
  inline ::std::string* mutable_address();
  inline ::std::string* release_address();
  inline void set_allocated_address(::std::string* address);

  // optional string passKey = 2;
  inline bool has_passkey() const;
  inline void clear_passkey();
  static const int kPassKeyFieldNumber = 2;
  inline const ::std::string& passkey() const;
  inline void set_passkey(const ::std::string& value);
  inline void set_passkey(const char* value);
  inline void set_passkey(const char* value, size_t size);
  inline ::std::string* mutable_passkey();
  inline ::std::string* release_passkey();
  inline void set_allocated_passkey(::std::string* passkey);

  // optional string hash = 3;
  inline bool has_hash() const;
  inline void clear_hash();
  static const int kHashFieldNumber = 3;
  inline const ::std::string& hash() const;
  inline void set_hash(const ::std::string& value);
  inline void set_hash(const char* value);
  inline void set_hash(const char* value, size_t size);
  inline ::std::string* mutable_hash();
  inline ::std::string* release_hash();
  inline void set_allocated_hash(::std::string* hash);

  // optional string randomizer = 4;
  inline bool has_randomizer() const;
  inline void clear_randomizer();
  static const int kRandomizerFieldNumber = 4;
  inline const ::std::string& randomizer() const;
  inline void set_randomizer(const ::std::string& value);
  inline void set_randomizer(const char* value);
  inline void set_randomizer(const char* value, size_t size);
  inline ::std::string* mutable_randomizer();
  inline ::std::string* release_randomizer();
  inline void set_allocated_randomizer(::std::string* randomizer);

  // required string uuid = 5;
  inline bool has_uuid() const;
  inline void clear_uuid();
  static const int kUuidFieldNumber = 5;
  inline const ::std::string& uuid() const;
  inline void set_uuid(const ::std::string& value);
  inline void set_uuid(const char* value);
  inline void set_uuid(const char* value, size_t size);
  inline ::std::string* mutable_uuid();
  inline ::std::string* release_uuid();
  inline void set_allocated_uuid(::std::string* uuid);

  // required string name = 6;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 6;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // required int32 status = 7;
  inline bool has_status() const;
  inline void clear_status();
  static const int kStatusFieldNumber = 7;
  inline ::google::protobuf::int32 status() const;
  inline void set_status(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:com.baidu.carlife.protobuf.CarlifeBTPairInfo)
 private:
  inline void set_has_address();
  inline void clear_has_address();
  inline void set_has_passkey();
  inline void clear_has_passkey();
  inline void set_has_hash();
  inline void clear_has_hash();
  inline void set_has_randomizer();
  inline void clear_has_randomizer();
  inline void set_has_uuid();
  inline void clear_has_uuid();
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_status();
  inline void clear_has_status();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* address_;
  ::std::string* passkey_;
  ::std::string* hash_;
  ::std::string* randomizer_;
  ::std::string* uuid_;
  ::std::string* name_;
  ::google::protobuf::int32 status_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(7 + 31) / 32];

  friend void  protobuf_AddDesc_CarlifeBTPairInfoProto_2eproto();
  friend void protobuf_AssignDesc_CarlifeBTPairInfoProto_2eproto();
  friend void protobuf_ShutdownFile_CarlifeBTPairInfoProto_2eproto();

  void InitAsDefaultInstance();
  static CarlifeBTPairInfo* default_instance_;
};
// ===================================================================


// ===================================================================

// CarlifeBTPairInfo

// required string address = 1;
inline bool CarlifeBTPairInfo::has_address() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CarlifeBTPairInfo::set_has_address() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CarlifeBTPairInfo::clear_has_address() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CarlifeBTPairInfo::clear_address() {
  if (address_ != &::google::protobuf::internal::kEmptyString) {
    address_->clear();
  }
  clear_has_address();
}
inline const ::std::string& CarlifeBTPairInfo::address() const {
  return *address_;
}
inline void CarlifeBTPairInfo::set_address(const ::std::string& value) {
  set_has_address();
  if (address_ == &::google::protobuf::internal::kEmptyString) {
    address_ = new ::std::string;
  }
  address_->assign(value);
}
inline void CarlifeBTPairInfo::set_address(const char* value) {
  set_has_address();
  if (address_ == &::google::protobuf::internal::kEmptyString) {
    address_ = new ::std::string;
  }
  address_->assign(value);
}
inline void CarlifeBTPairInfo::set_address(const char* value, size_t size) {
  set_has_address();
  if (address_ == &::google::protobuf::internal::kEmptyString) {
    address_ = new ::std::string;
  }
  address_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* CarlifeBTPairInfo::mutable_address() {
  set_has_address();
  if (address_ == &::google::protobuf::internal::kEmptyString) {
    address_ = new ::std::string;
  }
  return address_;
}
inline ::std::string* CarlifeBTPairInfo::release_address() {
  clear_has_address();
  if (address_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = address_;
    address_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void CarlifeBTPairInfo::set_allocated_address(::std::string* address) {
  if (address_ != &::google::protobuf::internal::kEmptyString) {
    delete address_;
  }
  if (address) {
    set_has_address();
    address_ = address;
  } else {
    clear_has_address();
    address_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string passKey = 2;
inline bool CarlifeBTPairInfo::has_passkey() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CarlifeBTPairInfo::set_has_passkey() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CarlifeBTPairInfo::clear_has_passkey() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CarlifeBTPairInfo::clear_passkey() {
  if (passkey_ != &::google::protobuf::internal::kEmptyString) {
    passkey_->clear();
  }
  clear_has_passkey();
}
inline const ::std::string& CarlifeBTPairInfo::passkey() const {
  return *passkey_;
}
inline void CarlifeBTPairInfo::set_passkey(const ::std::string& value) {
  set_has_passkey();
  if (passkey_ == &::google::protobuf::internal::kEmptyString) {
    passkey_ = new ::std::string;
  }
  passkey_->assign(value);
}
inline void CarlifeBTPairInfo::set_passkey(const char* value) {
  set_has_passkey();
  if (passkey_ == &::google::protobuf::internal::kEmptyString) {
    passkey_ = new ::std::string;
  }
  passkey_->assign(value);
}
inline void CarlifeBTPairInfo::set_passkey(const char* value, size_t size) {
  set_has_passkey();
  if (passkey_ == &::google::protobuf::internal::kEmptyString) {
    passkey_ = new ::std::string;
  }
  passkey_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* CarlifeBTPairInfo::mutable_passkey() {
  set_has_passkey();
  if (passkey_ == &::google::protobuf::internal::kEmptyString) {
    passkey_ = new ::std::string;
  }
  return passkey_;
}
inline ::std::string* CarlifeBTPairInfo::release_passkey() {
  clear_has_passkey();
  if (passkey_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = passkey_;
    passkey_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void CarlifeBTPairInfo::set_allocated_passkey(::std::string* passkey) {
  if (passkey_ != &::google::protobuf::internal::kEmptyString) {
    delete passkey_;
  }
  if (passkey) {
    set_has_passkey();
    passkey_ = passkey;
  } else {
    clear_has_passkey();
    passkey_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string hash = 3;
inline bool CarlifeBTPairInfo::has_hash() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void CarlifeBTPairInfo::set_has_hash() {
  _has_bits_[0] |= 0x00000004u;
}
inline void CarlifeBTPairInfo::clear_has_hash() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void CarlifeBTPairInfo::clear_hash() {
  if (hash_ != &::google::protobuf::internal::kEmptyString) {
    hash_->clear();
  }
  clear_has_hash();
}
inline const ::std::string& CarlifeBTPairInfo::hash() const {
  return *hash_;
}
inline void CarlifeBTPairInfo::set_hash(const ::std::string& value) {
  set_has_hash();
  if (hash_ == &::google::protobuf::internal::kEmptyString) {
    hash_ = new ::std::string;
  }
  hash_->assign(value);
}
inline void CarlifeBTPairInfo::set_hash(const char* value) {
  set_has_hash();
  if (hash_ == &::google::protobuf::internal::kEmptyString) {
    hash_ = new ::std::string;
  }
  hash_->assign(value);
}
inline void CarlifeBTPairInfo::set_hash(const char* value, size_t size) {
  set_has_hash();
  if (hash_ == &::google::protobuf::internal::kEmptyString) {
    hash_ = new ::std::string;
  }
  hash_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* CarlifeBTPairInfo::mutable_hash() {
  set_has_hash();
  if (hash_ == &::google::protobuf::internal::kEmptyString) {
    hash_ = new ::std::string;
  }
  return hash_;
}
inline ::std::string* CarlifeBTPairInfo::release_hash() {
  clear_has_hash();
  if (hash_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = hash_;
    hash_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void CarlifeBTPairInfo::set_allocated_hash(::std::string* hash) {
  if (hash_ != &::google::protobuf::internal::kEmptyString) {
    delete hash_;
  }
  if (hash) {
    set_has_hash();
    hash_ = hash;
  } else {
    clear_has_hash();
    hash_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string randomizer = 4;
inline bool CarlifeBTPairInfo::has_randomizer() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void CarlifeBTPairInfo::set_has_randomizer() {
  _has_bits_[0] |= 0x00000008u;
}
inline void CarlifeBTPairInfo::clear_has_randomizer() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void CarlifeBTPairInfo::clear_randomizer() {
  if (randomizer_ != &::google::protobuf::internal::kEmptyString) {
    randomizer_->clear();
  }
  clear_has_randomizer();
}
inline const ::std::string& CarlifeBTPairInfo::randomizer() const {
  return *randomizer_;
}
inline void CarlifeBTPairInfo::set_randomizer(const ::std::string& value) {
  set_has_randomizer();
  if (randomizer_ == &::google::protobuf::internal::kEmptyString) {
    randomizer_ = new ::std::string;
  }
  randomizer_->assign(value);
}
inline void CarlifeBTPairInfo::set_randomizer(const char* value) {
  set_has_randomizer();
  if (randomizer_ == &::google::protobuf::internal::kEmptyString) {
    randomizer_ = new ::std::string;
  }
  randomizer_->assign(value);
}
inline void CarlifeBTPairInfo::set_randomizer(const char* value, size_t size) {
  set_has_randomizer();
  if (randomizer_ == &::google::protobuf::internal::kEmptyString) {
    randomizer_ = new ::std::string;
  }
  randomizer_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* CarlifeBTPairInfo::mutable_randomizer() {
  set_has_randomizer();
  if (randomizer_ == &::google::protobuf::internal::kEmptyString) {
    randomizer_ = new ::std::string;
  }
  return randomizer_;
}
inline ::std::string* CarlifeBTPairInfo::release_randomizer() {
  clear_has_randomizer();
  if (randomizer_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = randomizer_;
    randomizer_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void CarlifeBTPairInfo::set_allocated_randomizer(::std::string* randomizer) {
  if (randomizer_ != &::google::protobuf::internal::kEmptyString) {
    delete randomizer_;
  }
  if (randomizer) {
    set_has_randomizer();
    randomizer_ = randomizer;
  } else {
    clear_has_randomizer();
    randomizer_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required string uuid = 5;
inline bool CarlifeBTPairInfo::has_uuid() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void CarlifeBTPairInfo::set_has_uuid() {
  _has_bits_[0] |= 0x00000010u;
}
inline void CarlifeBTPairInfo::clear_has_uuid() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void CarlifeBTPairInfo::clear_uuid() {
  if (uuid_ != &::google::protobuf::internal::kEmptyString) {
    uuid_->clear();
  }
  clear_has_uuid();
}
inline const ::std::string& CarlifeBTPairInfo::uuid() const {
  return *uuid_;
}
inline void CarlifeBTPairInfo::set_uuid(const ::std::string& value) {
  set_has_uuid();
  if (uuid_ == &::google::protobuf::internal::kEmptyString) {
    uuid_ = new ::std::string;
  }
  uuid_->assign(value);
}
inline void CarlifeBTPairInfo::set_uuid(const char* value) {
  set_has_uuid();
  if (uuid_ == &::google::protobuf::internal::kEmptyString) {
    uuid_ = new ::std::string;
  }
  uuid_->assign(value);
}
inline void CarlifeBTPairInfo::set_uuid(const char* value, size_t size) {
  set_has_uuid();
  if (uuid_ == &::google::protobuf::internal::kEmptyString) {
    uuid_ = new ::std::string;
  }
  uuid_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* CarlifeBTPairInfo::mutable_uuid() {
  set_has_uuid();
  if (uuid_ == &::google::protobuf::internal::kEmptyString) {
    uuid_ = new ::std::string;
  }
  return uuid_;
}
inline ::std::string* CarlifeBTPairInfo::release_uuid() {
  clear_has_uuid();
  if (uuid_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = uuid_;
    uuid_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void CarlifeBTPairInfo::set_allocated_uuid(::std::string* uuid) {
  if (uuid_ != &::google::protobuf::internal::kEmptyString) {
    delete uuid_;
  }
  if (uuid) {
    set_has_uuid();
    uuid_ = uuid;
  } else {
    clear_has_uuid();
    uuid_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required string name = 6;
inline bool CarlifeBTPairInfo::has_name() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void CarlifeBTPairInfo::set_has_name() {
  _has_bits_[0] |= 0x00000020u;
}
inline void CarlifeBTPairInfo::clear_has_name() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void CarlifeBTPairInfo::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& CarlifeBTPairInfo::name() const {
  return *name_;
}
inline void CarlifeBTPairInfo::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void CarlifeBTPairInfo::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void CarlifeBTPairInfo::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* CarlifeBTPairInfo::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* CarlifeBTPairInfo::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void CarlifeBTPairInfo::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required int32 status = 7;
inline bool CarlifeBTPairInfo::has_status() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void CarlifeBTPairInfo::set_has_status() {
  _has_bits_[0] |= 0x00000040u;
}
inline void CarlifeBTPairInfo::clear_has_status() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void CarlifeBTPairInfo::clear_status() {
  status_ = 0;
  clear_has_status();
}
inline ::google::protobuf::int32 CarlifeBTPairInfo::status() const {
  return status_;
}
inline void CarlifeBTPairInfo::set_status(::google::protobuf::int32 value) {
  set_has_status();
  status_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf
}  // namespace carlife
}  // namespace baidu
}  // namespace com

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_CarlifeBTPairInfoProto_2eproto__INCLUDED
