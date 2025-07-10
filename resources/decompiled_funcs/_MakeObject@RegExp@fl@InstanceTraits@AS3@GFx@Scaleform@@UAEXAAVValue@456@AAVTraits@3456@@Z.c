void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl::RegExp::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl::RegExp *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl::RegExp *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::RegExp> *Instance; // eax

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl::RegExp::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::RegExp> *)&t,
               t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}
