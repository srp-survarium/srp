void __thiscall Scaleform::GFx::AS3::TR::State::exec_pop(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_OpStack; // esi
  Scaleform::GFx::AS3::Tracer *pTracer; // edi
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::VM *VMRef; // ecx

  p_OpStack = &this->OpStack;
  pTracer = this->pTracer;
  ValueTraits = Scaleform::GFx::AS3::TR::State::GetValueTraits(
                  this,
                  &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]);
  VMRef = pTracer->CF->pFile->VMRef;
  if ( ValueTraits == VMRef->TraitsBoolean.pObject->ITraits.pObject
    || ValueTraits == VMRef->TraitsVoid.pObject
    || ValueTraits == VMRef->TraitsNull.pObject
    || Scaleform::GFx::AS3::Tracer::IsNumericType(pTracer, ValueTraits) )
  {
    pTracer->WCode->Data.Data[pTracer->WCode->Data.Size - 1] = 107;
  }
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &p_OpStack->Data,
    p_OpStack->Data.Size - 1);
}
