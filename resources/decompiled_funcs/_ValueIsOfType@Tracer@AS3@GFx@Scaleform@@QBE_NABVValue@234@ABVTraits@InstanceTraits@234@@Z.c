char __thiscall Scaleform::GFx::AS3::Tracer::ValueIsOfType(
        Scaleform::GFx::AS3::Tracer *this,
        const Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::InstanceTraits::Traits *type)
{
  const Scaleform::GFx::AS3::InstanceTraits::Traits *InstanceTraits; // eax

  InstanceTraits = Scaleform::GFx::AS3::Tracer::GetInstanceTraits(this, value);
  return Scaleform::GFx::AS3::InstanceTraits::Traits::IsParentTypeOf(type, InstanceTraits);
}
