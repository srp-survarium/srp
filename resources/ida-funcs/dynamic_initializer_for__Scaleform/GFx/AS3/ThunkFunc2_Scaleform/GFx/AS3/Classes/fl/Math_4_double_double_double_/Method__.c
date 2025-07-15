void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl::Math_4_double_double_double_::Method__())(Scaleform::GFx::AS3::Classes::fl::Math *this, long double *result, long double y, long double x)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double, long double); // eax

  result = Scaleform::GFx::AS3::Classes::fl::Math::atan2;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl::Math,4,double,double,double>::Method) = Scaleform::GFx::AS3::Classes::fl::Math::atan2;
  dword_8F1A24 = 0;
  return result;
}
