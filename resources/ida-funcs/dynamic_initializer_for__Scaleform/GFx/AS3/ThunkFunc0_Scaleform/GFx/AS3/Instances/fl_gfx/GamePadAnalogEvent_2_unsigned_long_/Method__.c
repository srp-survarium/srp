void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent_2_unsigned_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *this, unsigned int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *, unsigned int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent::controllerIdxGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,2,unsigned long>::Method) = Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent::controllerIdxGet;
  dword_8F3524 = 0;
  return result;
}
