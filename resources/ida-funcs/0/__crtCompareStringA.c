int __cdecl __crtCompareStringA(
        localeinfo_struct *plocinfo,
        unsigned int Locale,
        DWORD dwCmpFlags,
        const char *lpString1,
        int cchCount1,
        char *lpString2,
        int cchCount2,
        unsigned int code_page)
{
  int result; // eax
  _LocaleUpdate v9; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v9, plocinfo);
  result = _crtCompareStringA_stat(
             &v9.localeinfo,
             lpString1,
             Locale,
             dwCmpFlags,
             cchCount1,
             lpString2,
             cchCount2,
             code_page);
  if ( v9.updated )
    v9.ptd->_ownlocale &= ~2u;
  return result;
}
