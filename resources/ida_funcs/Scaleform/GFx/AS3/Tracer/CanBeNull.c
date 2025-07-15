int __thiscall Scaleform::GFx::AS3::Tracer::CanBeNull(
        Scaleform::GFx::AS3::Tracer *this,
        const Scaleform::GFx::AS3::InstanceTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *VMRef; // eax

  VMRef = this->CF->pFile->VMRef;
  if ( tr == VMRef->TraitsInt.pObject->ITraits.pObject
    || tr == VMRef->TraitsUint.pObject->ITraits.pObject
    || tr == VMRef->TraitsNumber.pObject->ITraits.pObject
    || tr == VMRef->TraitsBoolean.pObject->ITraits.pObject )
  {
    return 0;
  }
  else
  {
    return 2;
  }
}
