void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::Event_0_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_events::Event *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_events::Event *, bool *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_events::Event::bubblesGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,0,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_events::Event::bubblesGet;
  dword_8F20DC = 0;
  return result;
}
