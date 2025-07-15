Scaleform::GFx::AS3::Classes::fl_vec::Vector_double *__thiscall Scaleform::GFx::AS3::VM::GetClassVectorNumber(
        Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // esi

  pObject = this->TraitsVector_Number.pObject->ITraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->InitOnDemand(pObject);
  return (Scaleform::GFx::AS3::Classes::fl_vec::Vector_double *)pObject->pConstructor.pObject;
}
