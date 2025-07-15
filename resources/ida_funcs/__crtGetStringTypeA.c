int __cdecl __crtGetStringTypeA(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        unsigned int code_page,
        int lcid,
        int bError)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  result = _crtGetStringTypeA_stat(dwInfoType, lpSrcStr, cchSrc, lpCharType, code_page, lcid, bError);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}
