unsigned int __thiscall Scaleform::GFx::AMP::MessageAppControl::IsToggleAmpRecording(
        Scaleform::GFx::AMP::MessageAppControl *this)
{
  return (this->OptionBits >> 2) & 1;
}
