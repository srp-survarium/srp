void __thiscall Scaleform::GFx::AS3::TR::State::exec_pushwith(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_ScopeStack; // esi
  void *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value result; // [esp+4h] [ebp-10h] BYREF

  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
    &this->OpStack,
    &result);
  p_ScopeStack = &this->ScopeStack;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &p_ScopeStack->Data,
    &result);
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags & 0x200) != 0 )
    {
      pWeakProxy = result.Bonus.pWeakProxy;
      if ( result.Bonus.pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
  }
  p_ScopeStack->Data.Data[p_ScopeStack->Data.Size - 1].Flags |= 0x100u;
}
