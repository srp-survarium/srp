Scaleform::GFx::AS3::Classes::fl_vec::Vector *__thiscall Scaleform::GFx::AS3::VM::GetClassVector(
        Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // esi

  pObject = this->TraitsVector.pObject->ITraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->InitOnDemand(pObject);
  return (Scaleform::GFx::AS3::Classes::fl_vec::Vector *)pObject->pConstructor.pObject;
}
