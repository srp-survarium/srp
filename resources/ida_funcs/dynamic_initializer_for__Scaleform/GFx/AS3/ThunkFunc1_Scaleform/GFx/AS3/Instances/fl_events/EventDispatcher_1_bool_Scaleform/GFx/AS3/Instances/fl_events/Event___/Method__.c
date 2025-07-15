void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher_1_bool_Scaleform::GFx::AS3::Instances::fl_events::Event___::Method__())(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, bool *result, Scaleform::GFx::AS3::Instances::fl_events::Event *event)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *, bool *, Scaleform::GFx::AS3::Instances::fl_events::Event *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::dispatchEvent;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher,1,bool,Scaleform::GFx::AS3::Instances::fl_events::Event *>::Method) = Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::dispatchEvent;
  dword_AADC6C = 0;
  return result;
}
