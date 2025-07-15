Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *__thiscall Scaleform::GFx::FontManager::CreateFontHandle(
        Scaleform::GFx::FontManager *this,
        __m128i *pfontName,
        unsigned int matchFontFlags,
        bool allowListOfFonts,
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *searchInfo)
{
  char *v6; // edi
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *FontHandleFromName; // ebx
  int v8; // eax
  int v9; // ebp
  int v10; // esi
  __m128i *v11; // eax
  char _Dst[128]; // [esp+4h] [ebp-80h] BYREF

  if ( !allowListOfFonts )
    return Scaleform::GFx::FontManager::CreateFontHandleFromName(this, pfontName, matchFontFlags, searchInfo);
  v6 = (char *)pfontName;
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
      strncpy_s((int)v6, _Dst, 127, v6, v8 - (_DWORD)v6);
      _Dst[v10] = 0;
      v11 = (__m128i *)_Dst;
      v6 = (char *)(v9 + 1);
    }
    else
    {
      v11 = (__m128i *)v6;
    }
    FontHandleFromName = Scaleform::GFx::FontManager::CreateFontHandleFromName(this, v11, matchFontFlags, searchInfo);
    if ( FontHandleFromName )
      return FontHandleFromName;
  }
  while ( v9 );
  return FontHandleFromName;
}
