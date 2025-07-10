void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_geom::Matrix3D::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_geom::Matrix3D *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_geom::Matrix3D *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D> *Instance; // eax

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_geom::Matrix3D::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D> *)&t,
               t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}
