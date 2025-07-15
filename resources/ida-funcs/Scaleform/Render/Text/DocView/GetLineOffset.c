unsigned int __thiscall Scaleform::Render::Text::DocView::GetLineOffset(
        Scaleform::Render::Text::DocView *this,
        unsigned int lineIndex)
{
  Scaleform::Render::Text::LineBuffer::Line *v3; // eax
  int MemSize; // ecx
  unsigned int result; // eax

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  if ( this == (Scaleform::Render::Text::DocView *)-48 )
    return -1;
  if ( lineIndex >= this->mLineBuffer.Lines.Data.Size )
    return -1;
  if ( (lineIndex & 0x80000000) != 0 )
    return -1;
  v3 = this->mLineBuffer.Lines.Data.Data[lineIndex];
  MemSize = v3->MemSize;
  result = v3->Data32.TextPos;
  if ( MemSize < 0 )
  {
    result &= 0xFFFFFFu;
    if ( result == 0xFFFFFF )
      return -1;
  }
  return result;
}
