BOOL __cdecl __crtGetStringTypeW(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const wchar_t *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType)
{
  BOOL result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  result = cchSrc >= -1 && GetStringTypeW(dwInfoType, lpSrcStr, cchSrc, lpCharType);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}
