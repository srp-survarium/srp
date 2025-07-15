int __cdecl __crtLCMapStringW(
        localeinfo_struct *plocinfo,
        LCID Locale,
        DWORD dwMapFlags,
        const wchar_t *lpSrcStr,
        int cchSrc,
        wchar_t *lpDestStr,
        int cchDest)
{
  int v7; // eax
  const wchar_t *v8; // ecx
  int v9; // edx
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  v7 = cchSrc;
  if ( cchSrc > 0 )
  {
    v8 = lpSrcStr;
    v9 = cchSrc;
    while ( 1 )
    {
      --v9;
      if ( !*v8 )
        break;
      ++v8;
      if ( !v9 )
      {
        v9 = -1;
        break;
      }
    }
    v7 = cchSrc - v9 - 1;
  }
  result = LCMapStringW(Locale, dwMapFlags, lpSrcStr, v7, lpDestStr, cchDest);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}
