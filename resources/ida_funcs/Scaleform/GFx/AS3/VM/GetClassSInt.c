Scaleform::GFx::AS3::Classes::fl::int_ *__thiscall Scaleform::GFx::AS3::VM::GetClassSInt(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // esi

  pObject = this->TraitsInt.pObject->ITraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->InitOnDemand(pObject);
  return (Scaleform::GFx::AS3::Classes::fl::int_ *)pObject->pConstructor.pObject;
}
