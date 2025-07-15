unsigned int __thiscall Scaleform::GFx::Stream::IsVerboseParseAction(Scaleform::GFx::Stream *this)
{
  return (this->ParseFlags >> 1) & 1;
}
