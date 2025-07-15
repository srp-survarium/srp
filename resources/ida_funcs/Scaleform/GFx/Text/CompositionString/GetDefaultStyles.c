Scaleform::GFx::Text::IMEStyle *__cdecl Scaleform::GFx::Text::CompositionString::GetDefaultStyles(
        Scaleform::GFx::Text::IMEStyle *result)
{
  Scaleform::GFx::Text::IMEStyle *v1; // eax

  v1 = result;
  result->HighlightStyles[1].UnderlineColor.Raw = 0;
  result->HighlightStyles[1].TextColor.Raw = 0;
  result->HighlightStyles[1].BackgroundColor.Raw = 0;
  result->HighlightStyles[1].Flags = 0;
  result->HighlightStyles[2].UnderlineColor.Raw = 0;
  result->HighlightStyles[2].TextColor.Raw = 0;
  result->HighlightStyles[2].BackgroundColor.Raw = 0;
  result->HighlightStyles[2].Flags = 0;
  result->HighlightStyles[3].UnderlineColor.Raw = 0;
  result->HighlightStyles[3].TextColor.Raw = 0;
  result->HighlightStyles[3].BackgroundColor.Raw = 0;
  result->HighlightStyles[3].Flags = 0;
  result->HighlightStyles[4].UnderlineColor.Raw = 0;
  result->HighlightStyles[4].TextColor.Raw = 0;
  result->HighlightStyles[4].BackgroundColor.Raw = 0;
  result->HighlightStyles[4].Flags = 0;
  result->PresenceMask = 1;
  result->HighlightStyles[0].BackgroundColor.Raw = 0;
  result->HighlightStyles[0].TextColor.Raw = 0;
  result->HighlightStyles[0].UnderlineColor.Raw = 0;
  result->HighlightStyles[0].Flags = 3;
  result->PresenceMask |= 2u;
  result->HighlightStyles[1].BackgroundColor.Raw = 0;
  result->HighlightStyles[1].TextColor.Raw = 0;
  result->HighlightStyles[1].UnderlineColor.Raw = 0;
  result->HighlightStyles[1].Flags = 2;
  result->PresenceMask |= 4u;
  result->HighlightStyles[2].BackgroundColor.Raw = 0;
  result->HighlightStyles[2].TextColor.Raw = 0;
  result->HighlightStyles[2].UnderlineColor.Raw = 0;
  result->HighlightStyles[2].Flags = 1;
  result->PresenceMask |= 8u;
  result->HighlightStyles[3].BackgroundColor.Raw = -16777216;
  result->HighlightStyles[3].TextColor.Raw = -1;
  result->HighlightStyles[3].UnderlineColor.Raw = 0;
  result->HighlightStyles[3].Flags = 24;
  result->PresenceMask |= 0x10u;
  result->HighlightStyles[4].BackgroundColor.Raw = 0;
  result->HighlightStyles[4].TextColor.Raw = 0;
  result->HighlightStyles[4].UnderlineColor.Raw = 65280;
  result->HighlightStyles[4].Flags = 33;
  return v1;
}
