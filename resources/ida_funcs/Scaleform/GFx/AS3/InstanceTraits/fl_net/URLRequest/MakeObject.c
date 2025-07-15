void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_net::URLRequest::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_net::URLRequest *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_net::URLRequest *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLRequest> *Instance; // eax

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_net::URLRequest::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLRequest> *)&t,
               t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}
