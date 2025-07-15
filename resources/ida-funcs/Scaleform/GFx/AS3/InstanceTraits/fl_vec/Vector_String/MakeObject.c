void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *Instance; // eax

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *)&t,
               t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}
