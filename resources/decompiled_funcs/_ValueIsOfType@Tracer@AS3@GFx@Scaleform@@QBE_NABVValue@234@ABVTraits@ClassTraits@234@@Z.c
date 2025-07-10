char __thiscall Scaleform::GFx::AS3::Tracer::ValueIsOfType(
        Scaleform::GFx::AS3::Tracer *this,
        const Scaleform::GFx::AS3::Value *value,
        const Scaleform::GFx::AS3::ClassTraits::Traits *type)
{
  unsigned int v3; // edx
  const Scaleform::GFx::AS3::InstanceTraits::Traits *InstanceTraits; // eax

  v3 = value->Flags & 0x1F;
  if ( v3 == 9 )
    return Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(type, value->value.VS._1.CTr);
  if ( v3 == 13 )
    return Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(
             type,
             *(const Scaleform::GFx::AS3::ClassTraits::Traits **)(value->value.VS._1.VInt + 20));
  InstanceTraits = Scaleform::GFx::AS3::Tracer::GetInstanceTraits(this, value);
  return Scaleform::GFx::AS3::InstanceTraits::Traits::IsParentTypeOf(type->ITraits.pObject, InstanceTraits);
}
