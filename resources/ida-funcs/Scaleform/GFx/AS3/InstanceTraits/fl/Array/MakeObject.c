void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl::Array *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl::Array *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *v3; // eax

  v3 = Scaleform::GFx::AS3::InstanceTraits::MakeInstance<Scaleform::GFx::AS3::InstanceTraits::fl::Array>(
         (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)&t,
         t);
  Scaleform::GFx::AS3::Value::Pick(result, v3->pV);
}
