void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher_2_bool_Scaleform::GFx::ASString_const___::Method__())(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, bool *result, Scaleform::GFx::ASString *type)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *, bool *, Scaleform::GFx::ASString *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::hasEventListener;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher,2,bool,Scaleform::GFx::ASString const &>::Method) = Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::hasEventListener;
  dword_AADA3C = 0;
  return result;
}
