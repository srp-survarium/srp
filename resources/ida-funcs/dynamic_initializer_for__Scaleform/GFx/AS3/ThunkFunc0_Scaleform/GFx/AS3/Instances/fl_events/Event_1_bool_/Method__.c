void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::Event_1_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_events::Event *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_events::Event *, bool *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_events::Event::cancelableGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,1,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_events::Event::cancelableGet;
  dword_AADC2C = 0;
  return result;
}
