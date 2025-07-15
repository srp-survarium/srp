char __thiscall Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        const Scaleform::GFx::AS3::ClassTraits::Traits *other)
{
  const Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // esi

  pObject = other;
  if ( this == other )
    return 1;
  if ( other )
  {
    while ( !pObject->ITraits.pObject->SupportsInterface(pObject->ITraits.pObject, this->ITraits.pObject) )
    {
      pObject = (const Scaleform::GFx::AS3::ClassTraits::Traits *)pObject->pParent.pObject;
      if ( pObject == this )
        break;
      if ( !pObject )
        return 0;
    }
    return 1;
  }
  return 0;
}
