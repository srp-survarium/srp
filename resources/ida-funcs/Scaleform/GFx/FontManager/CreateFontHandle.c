Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *__thiscall Scaleform::GFx::FontManager::CreateFontHandle(
        Scaleform::GFx::FontManager *this,
        char *pfontName,
        unsigned int matchFontFlags,
        bool allowListOfFonts,
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *searchInfo)
{
  char *v6; // edi
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *FontHandleFromName; // ebx
  int v8; // eax
  int v9; // ebp
  int v10; // esi
  char *v11; // eax
  char buf[128]; // [esp+4h] [ebp-80h] BYREF

  if ( !allowListOfFonts )
    return Scaleform::GFx::FontManager::CreateFontHandleFromName(this, pfontName, matchFontFlags, searchInfo);
  v6 = pfontName;
  FontHandleFromName = 0;
  do
  {
    strchr(v6, 0x2Cu);
    v9 = v8;
    if ( v8 )
    {
      v10 = v8 - (_DWORD)v6;
      if ( (unsigned int)(v8 - (_DWORD)v6) > 0x7F )
        continue;
      strncpy_s(buf, 0x7Fu, v6, v8 - (_DWORD)v6);
      buf[v10] = 0;
      v11 = buf;
      v6 = (char *)(v9 + 1);
    }
    else
    {
      v11 = v6;
    }
    FontHandleFromName = Scaleform::GFx::FontManager::CreateFontHandleFromName(this, v11, matchFontFlags, searchInfo);
    if ( FontHandleFromName )
      return FontHandleFromName;
  }
  while ( v9 );
  return FontHandleFromName;
}
