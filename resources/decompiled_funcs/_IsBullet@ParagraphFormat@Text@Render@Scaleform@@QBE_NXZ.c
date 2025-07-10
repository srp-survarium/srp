BOOL __thiscall Scaleform::Render::Text::ParagraphFormat::IsBullet(Scaleform::Render::Text::ParagraphFormat *this)
{
  return (this->PresentMask & 0x80u) != 0 && (this->PresentMask & 0x8000) != 0;
}
