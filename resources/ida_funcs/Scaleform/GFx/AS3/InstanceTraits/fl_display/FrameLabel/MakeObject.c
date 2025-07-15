void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_display::FrameLabel::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_display::FrameLabel *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::FrameLabel *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::FrameLabel> *Instance; // eax

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_display::FrameLabel::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::FrameLabel> *)&t,
               t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}
