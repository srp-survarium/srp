void __thiscall Scaleform::Render::Text::DocView::SetFontScaleFactor(Scaleform::Render::Text::DocView *this, float f)
{
  if ( f == 1.0 )
  {
    this->RTFlags &= ~4u;
    this->FontScaleFactor = 20;
  }
  else
  {
    this->RTFlags |= 4u;
    this->FontScaleFactor = (int)(f * 20.0);
  }
}
