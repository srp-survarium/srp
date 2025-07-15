const Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::Text::DocView::GetViewRect(
        Scaleform::Render::Text::DocView *this)
{
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  return &this->ViewRect;
}
