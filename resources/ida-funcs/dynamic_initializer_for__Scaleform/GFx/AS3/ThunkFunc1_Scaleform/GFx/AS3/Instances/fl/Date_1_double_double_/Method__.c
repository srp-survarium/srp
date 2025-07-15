void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl::Date_1_double_double_::Method__())(Scaleform::GFx::AS3::Instances::fl::Date *this, long double *result, double millisecond)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *, double); // eax

  result = Scaleform::GFx::AS3::Instances::fl::Date::AS3setTime;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,1,double,double>::Method) = Scaleform::GFx::AS3::Instances::fl::Date::AS3setTime;
  dword_8F1C5C = 0;
  return result;
}
