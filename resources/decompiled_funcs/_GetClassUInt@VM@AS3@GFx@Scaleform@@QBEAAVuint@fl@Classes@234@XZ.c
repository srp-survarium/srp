Scaleform::GFx::AS3::Classes::fl::uint *__thiscall Scaleform::GFx::AS3::VM::GetClassUInt(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // esi

  pObject = this->TraitsUint.pObject->ITraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->InitOnDemand(pObject);
  return (Scaleform::GFx::AS3::Classes::fl::uint *)pObject->pConstructor.pObject;
}
