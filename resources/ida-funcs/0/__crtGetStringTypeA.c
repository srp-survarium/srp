int __cdecl __crtGetStringTypeA(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        UINT code_page,
        LCID lcid,
        int bError)
{
  int result; // eax
  _LocaleUpdate v9; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v9, plocinfo);
  result = _crtGetStringTypeA_stat(dwInfoType, lpSrcStr, cchSrc, lpCharType, code_page, lcid, bError);
  if ( v9.updated )
    v9.ptd->_ownlocale &= ~2u;
  return result;
}
