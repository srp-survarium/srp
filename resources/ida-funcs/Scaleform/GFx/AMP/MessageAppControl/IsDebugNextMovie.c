unsigned int __thiscall Scaleform::GFx::AMP::MessageAppControl::IsDebugNextMovie(
        Scaleform::GFx::AMP::MessageAppControl *this)
{
  return (this->OptionBits >> 17) & 1;
}
