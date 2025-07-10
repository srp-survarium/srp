void __thiscall Scaleform::GFx::AS3::TR::State::exec_if_boolean(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int *bcp,
        int opcode)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // esi
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_OpStack; // edi
  int offset; // [esp+18h] [ebp+8h]

  pTracer = this->pTracer;
  p_OpStack = &this->OpStack;
  if ( Scaleform::GFx::AS3::Tracer::IsBooleanType(this->pTracer, &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]) )
    pTracer->WCode->Data.Data[pTracer->WCode->Data.Size - 1] = (opcode != 17) + 51;
  offset = Scaleform::GFx::AS3::Abc::ReadS24<unsigned char>(pTracer->pCode, bcp);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &p_OpStack->Data,
    p_OpStack->Data.Size - 1);
  Scaleform::GFx::AS3::Tracer::StoreOffset(pTracer, *bcp, this, offset, -1);
}
