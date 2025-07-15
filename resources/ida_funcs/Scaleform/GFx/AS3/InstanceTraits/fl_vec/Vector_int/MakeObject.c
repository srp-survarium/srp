void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> *Instance; // eax

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> *)&t,
               t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}
