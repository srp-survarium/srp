Scaleform::GFx::Text::IMEStyle *__thiscall Scaleform::GFx::Text::IMEStyle::operator=(
        Scaleform::GFx::Text::IMEStyle *this,
        const Scaleform::GFx::Text::IMEStyle *__that)
{
  Scaleform::GFx::Text::IMEStyle *result; // eax

  result = this;
  this->HighlightStyles[0].BackgroundColor.Raw = __that->HighlightStyles[0].BackgroundColor.Raw;
  this->HighlightStyles[0].TextColor.Raw = __that->HighlightStyles[0].TextColor.Raw;
  this->HighlightStyles[0].UnderlineColor.Raw = __that->HighlightStyles[0].UnderlineColor.Raw;
  this->HighlightStyles[0].Flags = __that->HighlightStyles[0].Flags;
  this->HighlightStyles[1] = __that->HighlightStyles[1];
  this->HighlightStyles[2] = __that->HighlightStyles[2];
  this->HighlightStyles[3] = __that->HighlightStyles[3];
  this->HighlightStyles[4] = __that->HighlightStyles[4];
  this->PresenceMask = __that->PresenceMask;
  return result;
}
