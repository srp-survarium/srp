void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_utils::ByteArray_16_double_::Method__())(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this, long double *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, long double *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readDouble;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,16,double>::Method) = Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readDouble;
  dword_8F0B3C = 0;
  return result;
}
