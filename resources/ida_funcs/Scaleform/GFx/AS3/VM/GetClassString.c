Scaleform::GFx::AS3::Classes::fl::String *__thiscall Scaleform::GFx::AS3::VM::GetClassString(
        Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // esi

  pObject = this->TraitsString.pObject->ITraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->InitOnDemand(pObject);
  return (Scaleform::GFx::AS3::Classes::fl::String *)pObject->pConstructor.pObject;
}
