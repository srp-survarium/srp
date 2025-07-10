void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_display::MovieClip::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_display::MovieClip *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::MovieClip *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::MovieClip> *Instance; // eax

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_display::MovieClip::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::MovieClip> *)&t,
               t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}
