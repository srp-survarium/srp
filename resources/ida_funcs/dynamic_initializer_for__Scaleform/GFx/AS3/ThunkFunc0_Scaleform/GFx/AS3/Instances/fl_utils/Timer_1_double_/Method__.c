void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_utils::Timer_1_double_::Method__())(Scaleform::GFx::AS3::Instances::fl_utils::Timer *this, long double *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_utils::Timer *, long double *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_utils::Timer::delayGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,1,double>::Method) = Scaleform::GFx::AS3::Instances::fl_utils::Timer::delayGet;
  dword_AAC36C = 0;
  return result;
}
