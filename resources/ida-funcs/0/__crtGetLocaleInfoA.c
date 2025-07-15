int __cdecl __crtGetLocaleInfoA(
        localeinfo_struct *plocinfo,
        LCID Locale,
        LCTYPE LCType,
        char *lpLCData,
        int cchData,
        unsigned int code_page)
{
  int result; // eax
  _LocaleUpdate v7; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v7, plocinfo);
  result = _crtGetLocaleInfoA_stat(&v7.localeinfo, Locale, LCType, lpLCData, cchData, code_page);
  if ( v7.updated )
    v7.ptd->_ownlocale &= ~2u;
  return result;
}
