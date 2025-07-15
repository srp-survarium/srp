void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_gfx::IMECandidateListStyle::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_gfx::IMECandidateListStyle *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_gfx::IMECandidateListStyle *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::IMECandidateListStyle> *Instance; // eax

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_gfx::IMECandidateListStyle::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::IMECandidateListStyle> *)&t,
               t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}
