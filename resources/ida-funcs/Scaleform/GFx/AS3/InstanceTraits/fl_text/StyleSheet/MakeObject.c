void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_text::StyleSheet::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_text::StyleSheet *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_text::StyleSheet *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet> *Instance; // eax

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_text::StyleSheet::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet> *)&t,
               t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}
