Scaleform::Render::Color *__thiscall Scaleform::Render::Text::HighlightInfo::GetTextColor(
        Scaleform::Render::Text::HighlightInfo *this,
        Scaleform::Render::Color *result)
{
  Scaleform::Render::Color *v2; // eax

  v2 = result;
  if ( (this->Flags & 0x10) != 0 )
    *result = this->TextColor;
  else
    result->Raw = 0;
  return v2;
}
