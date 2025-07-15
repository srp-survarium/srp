void __thiscall Scaleform::Render::Text::TextFormat::SetKerning(
        Scaleform::Render::Text::TextFormat *this,
        bool kerning)
{
  if ( kerning )
    this->FormatFlags |= 8u;
  else
    this->FormatFlags &= ~8u;
  this->PresentMask |= 0x80u;
}
