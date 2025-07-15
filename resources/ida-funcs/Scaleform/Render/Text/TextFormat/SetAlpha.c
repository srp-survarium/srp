void __thiscall Scaleform::Render::Text::TextFormat::SetAlpha(
        Scaleform::Render::Text::TextFormat *this,
        unsigned __int8 alpha)
{
  this->ColorV = this->ColorV & 0xFFFFFF | (alpha << 24);
  this->PresentMask |= 0x400u;
}
