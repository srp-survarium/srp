int __cdecl __crtLCMapStringA(
        localeinfo_struct *plocinfo,
        unsigned int Locale,
        DWORD dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        unsigned int code_page,
        int bError)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  result = _crtLCMapStringA_stat(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest, code_page, bError);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}
