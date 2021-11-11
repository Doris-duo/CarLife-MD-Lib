// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CarlifeOilProto.proto

#ifndef PROTOBUF_CarlifeOilProto_2eproto__INCLUDED
#define PROTOBUF_CarlifeOilProto_2eproto__INCLUDED

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
void  protobuf_AddDesc_CarlifeOilProto_2eproto();
void protobuf_AssignDesc_CarlifeOilProto_2eproto();
void protobuf_ShutdownFile_CarlifeOilProto_2eproto();

class CarlifeOil;

// ===================================================================

class CarlifeOil : public ::google::protobuf::Message {
 public:
  CarlifeOil();
  virtual ~CarlifeOil();

  CarlifeOil(const CarlifeOil& from);

  inline CarlifeOil& operator=(const CarlifeOil& from) {
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
  static const CarlifeOil& default_instance();

  void Swap(CarlifeOil* other);

  // implements Message ----------------------------------------------

  CarlifeOil* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CarlifeOil& from);
  void MergeFrom(const CarlifeOil& from);
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

  // required int32 level = 1;
  inline bool has_level() const;
  inline void clear_level();
  static const int kLevelFieldNumber = 1;
  inline ::google::protobuf::int32 level() const;
  inline void set_level(::google::protobuf::int32 value);

  // required int32 range = 2;
  inline bool has_range() const;
  inline void clear_range();
  static const int kRangeFieldNumber = 2;
  inline ::google::protobuf::int32 range() const;
  inline void set_range(::google::protobuf::int32 value);

  // optional bool lowFuleWarning = 3;
  inline bool has_lowfulewarning() const;
  inline void clear_lowfulewarning();
  static const int kLowFuleWarningFieldNumber = 3;
  inline bool lowfulewarning() const;
  inline void set_lowfulewarning(bool value);

  // @@protoc_insertion_point(class_scope:com.baidu.carlife.protobuf.CarlifeOil)
 private:
  inline void set_has_level();
  inline void clear_has_level();
  inline void set_has_range();
  inline void clear_has_range();
  inline void set_has_lowfulewarning();
  inline void clear_has_lowfulewarning();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 level_;
  ::google::protobuf::int32 range_;
  bool lowfulewarning_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_CarlifeOilProto_2eproto();
  friend void protobuf_AssignDesc_CarlifeOilProto_2eproto();
  friend void protobuf_ShutdownFile_CarlifeOilProto_2eproto();

  void InitAsDefaultInstance();
  static CarlifeOil* default_instance_;
};
// ===================================================================


// ===================================================================

// CarlifeOil

// required int32 level = 1;
inline bool CarlifeOil::has_level() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CarlifeOil::set_has_level() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CarlifeOil::clear_has_level() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CarlifeOil::clear_level() {
  level_ = 0;
  clear_has_level();
}
inline ::google::protobuf::int32 CarlifeOil::level() const {
  return level_;
}
inline void CarlifeOil::set_level(::google::protobuf::int32 value) {
  set_has_level();
  level_ = value;
}

// required int32 range = 2;
inline bool CarlifeOil::has_range() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CarlifeOil::set_has_range() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CarlifeOil::clear_has_range() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CarlifeOil::clear_range() {
  range_ = 0;
  clear_has_range();
}
inline ::google::protobuf::int32 CarlifeOil::range() const {
  return range_;
}
inline void CarlifeOil::set_range(::google::protobuf::int32 value) {
  set_has_range();
  range_ = value;
}

// optional bool lowFuleWarning = 3;
inline bool CarlifeOil::has_lowfulewarning() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void CarlifeOil::set_has_lowfulewarning() {
  _has_bits_[0] |= 0x00000004u;
}
inline void CarlifeOil::clear_has_lowfulewarning() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void CarlifeOil::clear_lowfulewarning() {
  lowfulewarning_ = false;
  clear_has_lowfulewarning();
}
inline bool CarlifeOil::lowfulewarning() const {
  return lowfulewarning_;
}
inline void CarlifeOil::set_lowfulewarning(bool value) {
  set_has_lowfulewarning();
  lowfulewarning_ = value;
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

#endif  // PROTOBUF_CarlifeOilProto_2eproto__INCLUDED
