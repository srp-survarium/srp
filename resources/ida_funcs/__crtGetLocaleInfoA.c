int __cdecl __crtGetLocaleInfoA(
        localeinfo_struct *plocinfo,
        LCID Locale,
        LCTYPE LCType,
        char *lpLCData,
        int cchData,
        UINT code_page)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  result = _crtGetLocaleInfoA_stat(&_loc_update.localeinfo, Locale, LCType, lpLCData, cchData, code_page);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}
