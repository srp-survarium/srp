Scaleform::Render::Color *__thiscall Scaleform::Render::Text::HighlightInfo::GetBackgroundColor(
        Scaleform::Render::Text::HighlightInfo *this,
        Scaleform::Render::Color *result)
{
  Scaleform::Render::Text::HighlightInfo *v2; // eax
  unsigned int Raw; // ecx
  Scaleform::Render::Color *v4; // eax
  Scaleform::Render::Text::HighlightInfo *v5; // [esp+0h] [ebp-4h] BYREF

  v5 = this;
  v2 = this;
  if ( (this->Flags & 8) == 0 )
  {
    v5 = 0;
    v2 = (Scaleform::Render::Text::HighlightInfo *)&v5;
  }
  Raw = v2->BackgroundColor.Raw;
  v4 = result;
  result->Raw = Raw;
  return v4;
}
