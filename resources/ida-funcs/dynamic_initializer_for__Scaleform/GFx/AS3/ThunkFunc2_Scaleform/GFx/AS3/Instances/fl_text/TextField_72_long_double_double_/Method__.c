void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_text::TextField_72_long_double_double_::Method__())(Scaleform::GFx::AS3::Instances::fl_text::TextField *this, int *result, long double x, long double y)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *, long double, long double); // eax

  result = Scaleform::GFx::AS3::Instances::fl_text::TextField::getLineIndexAtPoint;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_text::TextField,72,long,double,double>::Method) = Scaleform::GFx::AS3::Instances::fl_text::TextField::getLineIndexAtPoint;
  dword_8F144C = 0;
  return result;
}
