int __thiscall Scaleform::GFx::AMP::MessageAppControl::IsDebugStepOut(Scaleform::GFx::AMP::MessageAppControl *this)
{
  return HIWORD(this->OptionBits) & 1;
}
