double __thiscall Scaleform::Render::Text::DocView::GetTextHeight(Scaleform::Render::Text::DocView *this)
{
  unsigned int TextHeight; // esi

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  TextHeight = this->TextHeight;
  if ( TextHeight )
    return (double)TextHeight;
  else
    return 0.0;
}
