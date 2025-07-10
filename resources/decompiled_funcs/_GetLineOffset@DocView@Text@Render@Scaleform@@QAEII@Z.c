unsigned int __thiscall Scaleform::Render::Text::DocView::GetLineOffset(
        Scaleform::Render::Text::DocView *this,
        int lineIndex)
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
  if ( lineIndex < 0 )
    return -1;
  v3 = this->mLineBuffer.Lines.Data.Data[lineIndex];
  MemSize = v3->MemSize;
  result = v3->Data32.TextPos;
  if ( MemSize < 0 )
  {
    result &= (unsigned int)&vostok::memory::s_CRT_arena[5574199];
    if ( (unsigned __int8 *)result == &vostok::memory::s_CRT_arena[5574199] )
      return -1;
  }
  return result;
}
