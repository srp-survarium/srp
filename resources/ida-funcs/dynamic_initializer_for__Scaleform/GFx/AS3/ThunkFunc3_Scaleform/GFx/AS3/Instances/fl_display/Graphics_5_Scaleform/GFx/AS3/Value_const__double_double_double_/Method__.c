void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc3_Scaleform::GFx::AS3::Instances::fl_display::Graphics_5_Scaleform::GFx::AS3::Value_const__double_double_double_::Method__())(Scaleform::GFx::AS3::Instances::fl_display::Graphics *this, const Scaleform::GFx::AS3::Value *result, long double x, long double y, long double radius)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_display::Graphics *, const Scaleform::GFx::AS3::Value *, long double, long double, long double); // eax

  result = Scaleform::GFx::AS3::Instances::fl_display::Graphics::drawCircle;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_display::Graphics,5,Scaleform::GFx::AS3::Value const,double,double,double>::Method) = Scaleform::GFx::AS3::Instances::fl_display::Graphics::drawCircle;
  dword_AAE3A4 = 0;
  return result;
}
