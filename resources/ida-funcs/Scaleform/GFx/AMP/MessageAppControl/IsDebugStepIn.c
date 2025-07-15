unsigned int __thiscall Scaleform::GFx::AMP::MessageAppControl::IsDebugStepIn(
        Scaleform::GFx::AMP::MessageAppControl *this)
{
  return (this->OptionBits >> 15) & 1;
}
