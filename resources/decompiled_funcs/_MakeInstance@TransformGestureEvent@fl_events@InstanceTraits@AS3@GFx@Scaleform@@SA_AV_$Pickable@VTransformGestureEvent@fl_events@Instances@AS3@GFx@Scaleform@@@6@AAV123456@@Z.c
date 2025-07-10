Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent> *__cdecl Scaleform::GFx::AS3::InstanceTraits::fl_events::TransformGestureEvent::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_events::TransformGestureEvent *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *v2; // eax
  Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *v3; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent> *v4; // eax

  v2 = (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v3 = (Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *)v2;
  if ( v2 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::GestureEvent(v2, t);
    v4 = result;
    v3->LocalOffsetY = 0.0;
    v3->LocalOffsetX = 0.0;
    v3->OffsetY = 0.0;
    v3->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent_vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent::`vftable';
    v3->OffsetX = 0.0;
    v3->LocalInitialized = 0;
    result->pV = v3;
    v3->ScaleY = 1.0;
    v3->ScaleX = 1.0;
    v3->Rotation = 0.0;
  }
  else
  {
    v4 = result;
    result->pV = 0;
  }
  return v4;
}
