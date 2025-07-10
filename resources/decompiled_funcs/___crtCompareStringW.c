int __cdecl __crtCompareStringW(
        localeinfo_struct *plocinfo,
        LCID Locale,
        DWORD dwCmpFlags,
        const wchar_t *lpString1,
        int cchCount1,
        const wchar_t *lpString2,
        int cchCount2)
{
  int v7; // esi
  int v8; // edx
  int result; // eax
  int v10; // esi
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  v7 = cchCount1;
  v8 = cchCount2;
  if ( cchCount1 > 0 )
    v7 = wcsncnt(lpString1, cchCount1);
  if ( v8 > 0 )
    v8 = wcsncnt(lpString2, v8);
  if ( v7 && v8 )
  {
    result = CompareStringW(Locale, dwCmpFlags, lpString1, v7, lpString2, v8);
  }
  else
  {
    v10 = v7 - v8;
    if ( v10 )
      result = 2 * (v10 >= 0) + 1;
    else
      result = 2;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}
