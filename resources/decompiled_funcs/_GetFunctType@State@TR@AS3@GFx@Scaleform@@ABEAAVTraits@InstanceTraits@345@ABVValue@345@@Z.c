Scaleform::GFx::AS3::InstanceTraits::Traits *__thiscall Scaleform::GFx::AS3::TR::State::GetFunctType(
        Scaleform::GFx::AS3::TR::State *this,
        const Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *result; // eax

  switch ( value->Flags & 0x1F )
  {
    case 5u:
      result = this->pTracer->CF->pFile->VMRef->TraitsFunction.pObject->ThunkTraits.pObject;
      break;
    case 7u:
    case 0x11u:
      result = this->pTracer->CF->pFile->VMRef->TraitsFunction.pObject->VTableTraits.pObject;
      break;
    case 0x10u:
      result = this->pTracer->CF->pFile->VMRef->TraitsFunction.pObject->ThunkFunctionTraits.pObject;
      break;
    default:
      result = this->pTracer->CF->pFile->VMRef->TraitsFunction.pObject->ITraits.pObject;
      break;
  }
  return result;
}
