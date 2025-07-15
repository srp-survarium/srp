Scaleform::GFx::AS3::Classes::fl_vec::Vector_int *__thiscall Scaleform::GFx::AS3::VM::GetClassVectorSInt(
        Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // esi

  pObject = this->TraitsVector_int.pObject->ITraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->InitOnDemand(pObject);
  return (Scaleform::GFx::AS3::Classes::fl_vec::Vector_int *)pObject->pConstructor.pObject;
}
