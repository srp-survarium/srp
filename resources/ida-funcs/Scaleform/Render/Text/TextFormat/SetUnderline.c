void __thiscall Scaleform::Render::Text::TextFormat::SetUnderline(
        Scaleform::Render::Text::TextFormat *this,
        bool underline)
{
  if ( underline )
    this->FormatFlags |= 4u;
  else
    this->FormatFlags &= ~4u;
  this->PresentMask |= 0x40u;
}
