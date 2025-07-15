void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_system::Domain::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_system::Domain *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_system::Domain *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::Domain> *Instance; // eax

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_system::Domain::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::Domain> *)&t,
               t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}
