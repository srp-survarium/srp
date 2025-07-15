double __thiscall Scaleform::Render::Text::LineBuffer::Line::GetDescent(
        Scaleform::Render::Text::LineBuffer::Line *this)
{
  int Height; // edx
  float BaseLineOffset; // [esp+4h] [ebp-4h]

  if ( (this->MemSize & 0x80000000) == 0 )
    Height = this->Data32.Height;
  else
    Height = this->Data8.Height;
  if ( (this->MemSize & 0x80000000) == 0 )
    BaseLineOffset = (float)this->Data32.BaseLineOffset;
  else
    BaseLineOffset = (float)this->Data8.BaseLineOffset;
  return (float)((double)Height - BaseLineOffset);
}
