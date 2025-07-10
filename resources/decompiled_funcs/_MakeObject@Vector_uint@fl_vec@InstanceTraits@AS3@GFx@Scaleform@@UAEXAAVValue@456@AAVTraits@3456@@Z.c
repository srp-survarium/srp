void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *Instance; // eax

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *)&t,
               t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}
