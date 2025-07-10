double __thiscall Scaleform::Render::Text::LineBuffer::Line::GetBaseLineOffset(
        Scaleform::Render::Text::LineBuffer::Line *this)
{
  if ( (this->MemSize & 0x80000000) == 0 )
    return (float)this->Data32.BaseLineOffset;
  else
    return (float)this->Data8.BaseLineOffset;
}
