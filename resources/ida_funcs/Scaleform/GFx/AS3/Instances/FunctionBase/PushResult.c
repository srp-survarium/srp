void __thiscall Scaleform::GFx::AS3::Instances::FunctionBase::PushResult(
        Scaleform::GFx::AS3::Instances::FunctionBase *this,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::ValueStack *p_OpStack; // eax
  bool v3; // zf
  Scaleform::GFx::AS3::Value *pCurrent; // eax

  p_OpStack = &this->pTraits.pObject->pVM->OpStack;
  v3 = p_OpStack->pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
  pCurrent = p_OpStack->pCurrent;
  if ( !v3 )
  {
    *pCurrent = *value;
    if ( (value->Flags & 0x1F) > 9 )
    {
      if ( (value->Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(value);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(value);
    }
  }
}
