unsigned int __thiscall Scaleform::GFx::AMP::MessageAppControl::IsToggleMemReport(
        Scaleform::GFx::AMP::MessageAppControl *this)
{
  return (this->OptionBits >> 18) & 1;
}
