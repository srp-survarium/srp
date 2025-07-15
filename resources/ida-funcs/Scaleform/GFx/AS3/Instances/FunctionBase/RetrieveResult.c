void __thiscall Scaleform::GFx::AS3::Instances::FunctionBase::RetrieveResult(
        Scaleform::GFx::AS3::Instances::FunctionBase *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::ValueStack *p_OpStack; // esi

  p_OpStack = &this->pTraits.pObject->pVM->OpStack;
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
  }
  *result = *p_OpStack->pCurrent--;
}
