Scaleform::GFx::AS3::Classes::fl::Array *__thiscall Scaleform::GFx::AS3::VM::GetClassArray(
        Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // esi

  pObject = this->TraitsArray.pObject->ITraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->InitOnDemand(pObject);
  return (Scaleform::GFx::AS3::Classes::fl::Array *)pObject->pConstructor.pObject;
}
