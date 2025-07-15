unsigned int __thiscall Scaleform::GFx::AMP::MessageAppControl::IsToggleInstructionProfile(
        Scaleform::GFx::AMP::MessageAppControl *this)
{
  return (this->OptionBits >> 4) & 1;
}
