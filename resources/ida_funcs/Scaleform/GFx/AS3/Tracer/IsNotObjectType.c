BOOL __thiscall Scaleform::GFx::AS3::Tracer::IsNotObjectType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *VMRef; // eax

  VMRef = this->CF->pFile->VMRef;
  return tr == VMRef->TraitsInt.pObject->ITraits.pObject
      || tr == VMRef->TraitsUint.pObject->ITraits.pObject
      || tr == VMRef->TraitsNumber.pObject->ITraits.pObject
      || tr == VMRef->TraitsBoolean.pObject->ITraits.pObject
      || tr == VMRef->TraitsVoid.pObject
      || tr == VMRef->TraitsString.pObject->ITraits.pObject;
}
