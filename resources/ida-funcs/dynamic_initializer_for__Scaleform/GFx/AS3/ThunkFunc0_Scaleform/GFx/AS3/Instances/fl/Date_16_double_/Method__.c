void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::Date_16_double_::Method__())(Scaleform::GFx::AS3::Instances::fl::Date *this, long double *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *); // eax

  result = Scaleform::GFx::AS3::Instances::fl::Date::AS3getUTCMilliseconds;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,16,double>::Method) = Scaleform::GFx::AS3::Instances::fl::Date::AS3getUTCMilliseconds;
  dword_8F1D74 = 0;
  return result;
}
