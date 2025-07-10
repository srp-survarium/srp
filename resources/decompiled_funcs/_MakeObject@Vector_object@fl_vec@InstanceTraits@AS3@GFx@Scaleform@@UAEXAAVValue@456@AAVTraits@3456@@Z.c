void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *Instance; // eax

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&t,
               t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}
