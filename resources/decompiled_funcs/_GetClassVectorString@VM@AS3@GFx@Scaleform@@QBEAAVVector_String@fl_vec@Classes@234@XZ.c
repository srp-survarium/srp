Scaleform::GFx::AS3::Classes::fl_vec::Vector_String *__thiscall Scaleform::GFx::AS3::VM::GetClassVectorString(
        Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // esi

  pObject = this->TraitsVector_String.pObject->ITraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->InitOnDemand(pObject);
  return (Scaleform::GFx::AS3::Classes::fl_vec::Vector_String *)pObject->pConstructor.pObject;
}
