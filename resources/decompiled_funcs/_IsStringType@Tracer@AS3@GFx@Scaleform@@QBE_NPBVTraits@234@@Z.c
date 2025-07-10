bool __thiscall Scaleform::GFx::AS3::Tracer::IsStringType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *tr)
{
  return tr == this->CF->pFile->VMRef->TraitsString.pObject->ITraits.pObject;
}
