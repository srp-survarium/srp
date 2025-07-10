char __thiscall Scaleform::Render::Text::DocView::ForceReformat(Scaleform::Render::Text::DocView *this)
{
  if ( (this->RTFlags & 3) == 0 )
    return 0;
  Scaleform::Render::Text::DocView::Format(this);
  this->RTFlags &= 0xFCu;
  return 1;
}
