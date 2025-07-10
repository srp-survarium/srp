void __thiscall Scaleform::GFx::AS3::TR::State::exec_hasnext(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_OpStack; // esi
  Scaleform::GFx::AS3::Value val; // [esp+8h] [ebp-10h] BYREF

  p_OpStack = &this->OpStack;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &p_OpStack->Data,
    p_OpStack->Data.Size - 1);
  val.value.VS._1.VInt = (int)this->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject;
  val.Bonus.pWeakProxy = 0;
  val.Flags = 8;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &p_OpStack->Data,
    &val);
}
