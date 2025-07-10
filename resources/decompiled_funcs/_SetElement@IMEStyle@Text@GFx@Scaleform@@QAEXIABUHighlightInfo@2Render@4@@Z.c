void __thiscall Scaleform::GFx::Text::IMEStyle::SetElement(
        Scaleform::GFx::Text::IMEStyle *this,
        unsigned int n,
        const Scaleform::Render::Text::HighlightInfo *hinfo)
{
  this->PresenceMask |= 1 << n;
  this->HighlightStyles[n] = *hinfo;
}
