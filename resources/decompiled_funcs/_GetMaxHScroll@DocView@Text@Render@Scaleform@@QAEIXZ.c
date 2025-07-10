unsigned int __thiscall Scaleform::Render::Text::DocView::GetMaxHScroll(Scaleform::Render::Text::DocView *this)
{
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  return Scaleform::Render::Text::DocView::GetMaxHScrollValue(this);
}
