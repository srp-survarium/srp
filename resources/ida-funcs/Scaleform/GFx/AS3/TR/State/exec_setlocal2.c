void __thiscall Scaleform::GFx::AS3::TR::State::exec_setlocal2(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_OpStack; // esi

  p_OpStack = &this->OpStack;
  Scaleform::GFx::AS3::Value::Assign(
    this->Registers.Data.Data + 2,
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]);
  *this->RegistersAlive.pData |= 4u;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &p_OpStack->Data,
    p_OpStack->Data.Size - 1);
}
