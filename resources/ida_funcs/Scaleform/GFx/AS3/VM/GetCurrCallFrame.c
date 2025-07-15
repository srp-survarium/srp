const Scaleform::GFx::AS3::CallFrame *__thiscall Scaleform::GFx::AS3::VM::GetCurrCallFrame(
        Scaleform::GFx::AS3::VM *this)
{
  return &this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(this->CallStack.Size - 1) & 0x3F];
}
