int __cdecl __crtGetLocaleInfoW(
        localeinfo_struct *plocinfo,
        LCID Locale,
        LCTYPE LCType,
        wchar_t *lpLCData,
        int cchData)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  result = GetLocaleInfoW(Locale, LCType, lpLCData, cchData);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}
