void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::Event_3_unsigned_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_utils::Timer *this, int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_utils::Timer *, int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_utils::Timer::repeatCountGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,3,unsigned long>::Method) = Scaleform::GFx::AS3::Instances::fl_utils::Timer::repeatCountGet;
  dword_8F1FD4 = 0;
  return result;
}
