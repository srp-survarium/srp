BOOL __cdecl __crtGetStringTypeW(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const wchar_t *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType)
{
  BOOL result; // eax
  _LocaleUpdate v6; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v6, plocinfo);
  result = cchSrc >= -1 && GetStringTypeW(dwInfoType, lpSrcStr, cchSrc, lpCharType);
  if ( v6.updated )
    v6.ptd->_ownlocale &= ~2u;
  return result;
}
