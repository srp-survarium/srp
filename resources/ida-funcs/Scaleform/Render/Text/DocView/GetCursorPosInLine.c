unsigned int __thiscall Scaleform::Render::Text::DocView::GetCursorPosInLine(
        Scaleform::Render::Text::DocView *this,
        unsigned int lineIndex,
        float x)
{
  if ( lineIndex >= this->mLineBuffer.Lines.Data.Size )
    return -1;
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  return Scaleform::Render::Text::DocView::GetCursorPosInLineByOffset(this, lineIndex, x);
}
