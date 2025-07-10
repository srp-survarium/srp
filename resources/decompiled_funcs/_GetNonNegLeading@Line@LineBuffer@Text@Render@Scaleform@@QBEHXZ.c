int __thiscall Scaleform::Render::Text::LineBuffer::Line::GetNonNegLeading(
        Scaleform::Render::Text::LineBuffer::Line *this)
{
  int result; // eax

  if ( (this->MemSize & 0x80000000) == 0 )
  {
    LOWORD(result) = this->Data32.Leading;
    if ( (__int16)result > 0 )
      return (__int16)result;
  }
  else
  {
    LOBYTE(result) = this->Data8.Leading;
    if ( (char)result > 0 )
      return (char)result;
  }
  return 0;
}
