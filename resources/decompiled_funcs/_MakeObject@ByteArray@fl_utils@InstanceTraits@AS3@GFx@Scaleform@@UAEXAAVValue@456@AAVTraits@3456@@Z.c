void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *Instance; // eax

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *)&t,
               t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}
