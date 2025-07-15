void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::MouseEvent_2_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, bool *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::buttonDownGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,2,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::buttonDownGet;
  dword_AAD92C = 0;
  return result;
}
