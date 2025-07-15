unsigned int __thiscall Scaleform::GFx::AMP::MessageAppControl::IsDebugPause(
        Scaleform::GFx::AMP::MessageAppControl *this)
{
  return (this->OptionBits >> 13) & 1;
}
