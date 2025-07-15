void __thiscall Scaleform::GFx::AS3::TR::State::exec_dup(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // ebx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_OpStack; // edi
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::VM *VMRef; // ecx

  pTracer = this->pTracer;
  p_OpStack = &this->OpStack;
  ValueTraits = Scaleform::GFx::AS3::TR::State::GetValueTraits(
                  this,
                  &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]);
  VMRef = pTracer->CF->pFile->VMRef;
  if ( ValueTraits == VMRef->TraitsBoolean.pObject->ITraits.pObject
    || ValueTraits == VMRef->TraitsVoid.pObject
    || ValueTraits == VMRef->TraitsNull.pObject
    || Scaleform::GFx::AS3::Tracer::IsNumericType(pTracer, ValueTraits) )
  {
    pTracer->WCode->Data.Data[pTracer->WCode->Data.Size - 1] = 105;
  }
  if ( (_S15 & 1) == 0 )
  {
    _S15 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &p_OpStack->Data,
    &v);
  Scaleform::GFx::AS3::TR::State::SetBackOpValueUnsafe(this, &p_OpStack->Data.Data[this->OpStack.Data.Size - 2]);
}
