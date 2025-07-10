char __thiscall Scaleform::GFx::AS3::InstanceTraits::Traits::IsParentTypeOf(
        Scaleform::GFx::AS3::InstanceTraits::Traits *this,
        const Scaleform::GFx::AS3::InstanceTraits::Traits *other)
{
  const Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // esi

  pObject = other;
  if ( this == other )
    return 1;
  if ( other )
  {
    while ( !pObject->SupportsInterface((Scaleform::GFx::AS3::InstanceTraits::Traits *)pObject, this) )
    {
      pObject = (const Scaleform::GFx::AS3::InstanceTraits::Traits *)pObject->pParent.pObject;
      if ( pObject == this )
        break;
      if ( !pObject )
        return 0;
    }
    return 1;
  }
  return 0;
}
