void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc3_Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot_6_double_double_double_double_::Method__())(Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *this, long double *result, long double x, long double y, long double maxDistance)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *, long double *, long double, long double, long double); // eax

  result = Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::hitTestTextNearPos;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,6,double,double,double,double>::Method) = Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::hitTestTextNearPos;
  dword_AACBAC = 0;
  return result;
}
