unsigned int __thiscall Scaleform::Render::Text::DocView::GetLineLength(
        Scaleform::Render::Text::DocView *this,
        signed int lineIndex,
        bool *phasNewLine)
{
  Scaleform::Render::Text::LineBuffer *p_mLineBuffer; // esi
  Scaleform::Render::Text::LineBuffer::Line *v5; // eax

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  p_mLineBuffer = &this->mLineBuffer;
  if ( p_mLineBuffer && lineIndex < p_mLineBuffer->Lines.Data.Size && lineIndex >= 0 )
  {
    if ( phasNewLine )
      *phasNewLine = Scaleform::Render::Text::LineBuffer::Line::HasNewLine(p_mLineBuffer->Lines.Data.Data[lineIndex]);
    v5 = p_mLineBuffer->Lines.Data.Data[lineIndex];
    if ( (v5->MemSize & 0x80000000) == 0 )
      return v5->Data32.TextLength;
    else
      return HIBYTE(v5->Data8.TextPosAndLength);
  }
  else
  {
    if ( phasNewLine )
      *phasNewLine = 0;
    return -1;
  }
}
