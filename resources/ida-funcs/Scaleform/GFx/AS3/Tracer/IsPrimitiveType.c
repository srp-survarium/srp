BOOL __thiscall Scaleform::GFx::AS3::Tracer::IsPrimitiveType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *VMRef; // esi

  VMRef = this->CF->pFile->VMRef;
  return tr == VMRef->TraitsBoolean.pObject->ITraits.pObject
      || tr == VMRef->TraitsVoid.pObject
      || tr == VMRef->TraitsNull.pObject
      || Scaleform::GFx::AS3::Tracer::IsNumericType(this, tr)
      || tr == VMRef->TraitsString.pObject->ITraits.pObject;
}
