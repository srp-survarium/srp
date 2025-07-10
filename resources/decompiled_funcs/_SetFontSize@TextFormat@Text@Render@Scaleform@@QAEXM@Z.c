void __thiscall Scaleform::Render::Text::TextFormat::SetFontSize(
        Scaleform::Render::Text::TextFormat *this,
        float fontSize)
{
  this->PresentMask |= 8u;
  if ( fontSize >= 3276.800048828125 )
    this->FontSize = -1;
  else
    this->FontSize = (int)(fontSize * 20.0);
}
