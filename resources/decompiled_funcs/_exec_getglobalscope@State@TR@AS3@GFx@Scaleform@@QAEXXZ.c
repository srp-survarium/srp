void __thiscall Scaleform::GFx::AS3::TR::State::exec_getglobalscope(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *GlobalObject; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value result; // [esp+4h] [ebp-10h] BYREF

  GlobalObject = Scaleform::GFx::AS3::Tracer::GetGlobalObject(this->pTracer, &result, this);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->OpStack.Data,
    GlobalObject);
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags & 0x200) != 0 )
    {
      pWeakProxy = result.Bonus.pWeakProxy;
      --result.Bonus.pWeakProxy->RefCount;
      if ( !pWeakProxy->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
  }
}
