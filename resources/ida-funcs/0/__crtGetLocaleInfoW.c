int __cdecl __crtGetLocaleInfoW(
        localeinfo_struct *plocinfo,
        LCID Locale,
        LCTYPE LCType,
        wchar_t *lpLCData,
        int cchData)
{
  int result; // eax
  _LocaleUpdate v6; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v6, plocinfo);
  result = GetLocaleInfoW(Locale, LCType, lpLCData, cchData);
  if ( v6.updated )
    v6.ptd->_ownlocale &= ~2u;
  return result;
}
