BOOL __thiscall Scaleform::GFx::AS3::Tracer::IsAnyType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *VMRef; // eax

  VMRef = this->CF->pFile->VMRef;
  return tr == VMRef->TraitsObject.pObject->ITraits.pObject || tr == VMRef->TraitsClassClass.pObject->ITraits.pObject;
}
