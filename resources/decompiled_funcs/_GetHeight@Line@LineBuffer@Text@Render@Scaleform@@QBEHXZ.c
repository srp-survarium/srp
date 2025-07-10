unsigned int __thiscall Scaleform::Render::Text::LineBuffer::Line::GetHeight(
        Scaleform::Render::Text::LineBuffer::Line *this)
{
  if ( (this->MemSize & 0x80000000) == 0 )
    return this->Data32.Height;
  else
    return this->Data8.Height;
}
