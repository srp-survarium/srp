unsigned int __thiscall Scaleform::GFx::AMP::MessageAppControl::IsDebugStep(
        Scaleform::GFx::AMP::MessageAppControl *this)
{
  return (this->OptionBits >> 14) & 1;
}
