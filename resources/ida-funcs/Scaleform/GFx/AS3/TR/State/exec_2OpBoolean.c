void __thiscall Scaleform::GFx::AS3::TR::State::exec_2OpBoolean(Scaleform::GFx::AS3::TR::State *this)
{
  void *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value _2; // [esp+4h] [ebp-10h] BYREF

  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
    &this->OpStack,
    &_2);
  Scaleform::GFx::AS3::TR::State::ConvertOpTo(
    this,
    this->pTracer->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject,
    NotNull);
  if ( (_2.Flags & 0x1F) > 9 )
  {
    if ( (_2.Flags & 0x200) != 0 )
    {
      pWeakProxy = _2.Bonus.pWeakProxy;
      if ( _2.Bonus.pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_2);
    }
  }
}
