Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent> *__cdecl Scaleform::GFx::AS3::InstanceTraits::fl_events::PressAndTapGestureEvent::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_events::PressAndTapGestureEvent *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *v2; // eax
  Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *v3; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent> *v4; // eax

  v2 = (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v3 = (Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *)v2;
  if ( v2 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::GestureEvent(v2, t);
    v4 = result;
    v3->TapLocalY = 0.0;
    v3->TapLocalX = 0.0;
    v3->TapStageY = 0.0;
    v3->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent_vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent::`vftable';
    v3->TapStageX = 0.0;
    v3->LocalInitialized = 0;
    v3->TapStageSet = 0;
    result->pV = v3;
  }
  else
  {
    v4 = result;
    result->pV = 0;
  }
  return v4;
}
