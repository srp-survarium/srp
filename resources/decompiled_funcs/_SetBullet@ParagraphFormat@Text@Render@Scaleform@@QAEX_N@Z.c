void __thiscall Scaleform::Render::Text::ParagraphFormat::SetBullet(
        Scaleform::Render::Text::ParagraphFormat *this,
        bool bullet)
{
  if ( bullet )
    this->PresentMask |= 0x8000u;
  else
    this->PresentMask &= ~0x8000u;
  this->PresentMask |= 0x80u;
}
