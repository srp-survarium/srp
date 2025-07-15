void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_display::Stage_42_bool_Scaleform::GFx::AS3::Instances::fl_events::Event___::Method__())(Scaleform::GFx::AS3::Instances::fl_display::Stage *this, bool *result, Scaleform::GFx::AS3::Instances::fl_events::Event *event)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, bool *, Scaleform::GFx::AS3::Instances::fl_events::Event *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_display::Stage::dispatchEvent;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,42,bool,Scaleform::GFx::AS3::Instances::fl_events::Event *>::Method) = Scaleform::GFx::AS3::Instances::fl_display::Stage::dispatchEvent;
  dword_AAE684 = 0;
  return result;
}
