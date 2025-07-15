void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseCursorEvent::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseCursorEvent *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseCursorEvent *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent> *Instance; // eax

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseCursorEvent::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent> *)&t,
               t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}
