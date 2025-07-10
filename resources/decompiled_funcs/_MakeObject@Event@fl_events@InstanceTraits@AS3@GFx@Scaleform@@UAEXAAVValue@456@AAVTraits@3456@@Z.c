void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_events::Event *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_events::Event *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::Event> *Instance; // eax

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&t,
               t);
  Scaleform::GFx::AS3::Value::Pick(result, &Instance->pV->Scaleform::GFx::AS3::Instances::fl::Object);
}
