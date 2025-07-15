void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *Instance; // eax

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *)&t,
               t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}
