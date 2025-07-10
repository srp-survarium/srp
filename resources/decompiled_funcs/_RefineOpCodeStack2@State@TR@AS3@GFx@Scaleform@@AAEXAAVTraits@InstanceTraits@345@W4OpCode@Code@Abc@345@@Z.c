void __thiscall Scaleform::GFx::AS3::TR::State::RefineOpCodeStack2(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *type,
        Scaleform::GFx::AS3::Abc::Code::OpCode op)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_OpStack; // edi
  Scaleform::GFx::AS3::Value::TraceNullType CanBeNull; // eax
  void *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value _2; // [esp+8h] [ebp-10h] BYREF

  p_OpStack = &this->OpStack;
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
    &this->OpStack,
    &_2);
  if ( Scaleform::GFx::AS3::TR::State::GetValueTraits(this, &p_OpStack->Data.Data[p_OpStack->Data.Size - 1]) == type
    && Scaleform::GFx::AS3::TR::State::GetValueTraits(this, &_2) == type )
  {
    this->pTracer->WCode->Data.Data[this->pTracer->WCode->Data.Size - 1] = op;
  }
  else
  {
    CanBeNull = Scaleform::GFx::AS3::Tracer::CanBeNull(this->pTracer, type);
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(this, type, CanBeNull);
  }
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
