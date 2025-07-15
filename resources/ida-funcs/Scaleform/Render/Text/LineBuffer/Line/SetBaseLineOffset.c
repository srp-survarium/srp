void __thiscall Scaleform::Render::Text::LineBuffer::Line::SetBaseLineOffset(
        Scaleform::Render::Text::LineBuffer::Line *this,
        float baseLine)
{
  double v2; // st7

  v2 = baseLine;
  if ( (this->MemSize & 0x80000000) == 0 )
    this->Data32.BaseLineOffset = (int)v2;
  else
    this->Data8.BaseLineOffset = (int)v2;
}
