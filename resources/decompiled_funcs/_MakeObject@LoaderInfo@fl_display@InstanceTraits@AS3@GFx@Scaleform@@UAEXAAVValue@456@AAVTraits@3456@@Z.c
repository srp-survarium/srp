void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_display::LoaderInfo::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_display::LoaderInfo *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::LoaderInfo *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo> *Instance; // eax

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_display::LoaderInfo::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo> *)&t,
               t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}
