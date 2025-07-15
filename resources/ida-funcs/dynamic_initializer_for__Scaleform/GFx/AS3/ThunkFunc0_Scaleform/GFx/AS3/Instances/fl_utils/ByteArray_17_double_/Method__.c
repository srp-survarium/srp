void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_utils::ByteArray_17_double_::Method__())(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this, long double *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, long double *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readFloat;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,17,double>::Method) = Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readFloat;
  dword_8F0A4C = 0;
  return result;
}
