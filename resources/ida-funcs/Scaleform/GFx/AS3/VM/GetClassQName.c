Scaleform::GFx::AS3::Classes::fl::QName *__thiscall Scaleform::GFx::AS3::VM::GetClassQName(
        Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // esi

  pObject = this->TraitsQName.pObject->ITraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->InitOnDemand(pObject);
  return (Scaleform::GFx::AS3::Classes::fl::QName *)pObject->pConstructor.pObject;
}
