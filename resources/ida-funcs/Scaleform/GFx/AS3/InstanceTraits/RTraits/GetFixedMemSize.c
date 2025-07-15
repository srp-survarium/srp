int __thiscall Scaleform::GFx::AS3::InstanceTraits::RTraits::GetFixedMemSize(
        Scaleform::GFx::AS3::InstanceTraits::RTraits *this)
{
  const Scaleform::GFx::AS3::Traits *pObject; // ecx

  pObject = this->pParent.pObject;
  if ( pObject )
    return pObject->GetFixedMemSize(pObject);
  else
    return 32;
}
