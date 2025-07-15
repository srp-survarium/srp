void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_events::TransformGestureEvent::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_events::TransformGestureEvent *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_events::TransformGestureEvent *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent> *Instance; // eax

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_events::TransformGestureEvent::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent> *)&t,
               t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}
