int __thiscall Scaleform::GFx::Stream::ReadSInt(Scaleform::GFx::Stream *this, int bitcount)
{
  int result; // eax

  result = Scaleform::GFx::Stream::ReadUInt(this, bitcount);
  if ( ((1 << (bitcount - 1)) & result) != 0 )
    return (-1 << bitcount) | result;
  return result;
}
