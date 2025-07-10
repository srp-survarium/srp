double __thiscall Scaleform::Render::Text::DocView::GetTextWidth(Scaleform::Render::Text::DocView *this)
{
  unsigned int TextWidth; // esi

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  TextWidth = this->TextWidth;
  if ( TextWidth )
    return (double)TextWidth;
  else
    return 0.0;
}
