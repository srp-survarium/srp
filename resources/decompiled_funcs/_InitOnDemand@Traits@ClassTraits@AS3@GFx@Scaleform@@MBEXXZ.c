void __thiscall Scaleform::GFx::AS3::ClassTraits::Traits::InitOnDemand(Scaleform::GFx::AS3::ClassTraits::Traits *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // ecx

  pObject = this->ITraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->InitOnDemand(pObject);
}
