void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_utils::ByteArray_22_unsigned_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this, unsigned int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, unsigned int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readUnsignedByte;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,22,unsigned long>::Method) = Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readUnsignedByte;
  dword_8F0B4C = 0;
  return result;
}
