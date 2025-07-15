int __thiscall Scaleform::Render::TreeText::GetAlignment(Scaleform::Render::TreeText *this)
{
  int v1; // eax
  _BYTE pdestParaFmt[22]; // [esp+4h] [ebp-18h] BYREF

  v1 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                             + 20)
                 + 144);
  if ( v1 )
  {
    *(_DWORD *)pdestParaFmt = 1;
    memset(&pdestParaFmt[4], 0, 16);
    Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
      *(Scaleform::Render::Text::StyledText **)(v1 + 8),
      0,
      (Scaleform::Render::Text::ParagraphFormat *)pdestParaFmt,
      0,
      0xFFFFFFFF);
    if ( (pdestParaFmt[18] & 1) != 0 )
    {
      switch ( (*(_DWORD *)&pdestParaFmt[18] >> 9) & 3 )
      {
        case 1:
          Scaleform::Render::Text::ParagraphFormat::FreeTabStops((Scaleform::Render::Text::ParagraphFormat *)pdestParaFmt);
          return 1;
        case 2:
          Scaleform::Render::Text::ParagraphFormat::FreeTabStops((Scaleform::Render::Text::ParagraphFormat *)pdestParaFmt);
          return 3;
        case 3:
          Scaleform::Render::Text::ParagraphFormat::FreeTabStops((Scaleform::Render::Text::ParagraphFormat *)pdestParaFmt);
          return 2;
      }
    }
    Scaleform::Render::Text::ParagraphFormat::FreeTabStops((Scaleform::Render::Text::ParagraphFormat *)pdestParaFmt);
  }
  return 0;
}
