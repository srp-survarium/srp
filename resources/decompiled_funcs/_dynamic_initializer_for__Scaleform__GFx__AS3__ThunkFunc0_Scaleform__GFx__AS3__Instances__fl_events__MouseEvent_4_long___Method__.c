void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::MouseEvent_4_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *this, int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::clickCountGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,4,long>::Method) = Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::clickCountGet;
  dword_AAD88C = 0;
  return result;
}
