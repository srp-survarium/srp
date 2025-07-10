unsigned int __thiscall Scaleform::GFx::Stream::IsVerboseParseShape(Scaleform::GFx::Stream *this)
{
  return (this->ParseFlags >> 4) & 1;
}
