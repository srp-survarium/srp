int __cdecl __crtLCMapStringA(
        localeinfo_struct *plocinfo,
        LCID Locale,
        DWORD dwMapFlags,
        char *lpSrcStr,
        int cchSrc,
        wchar_t *lpDestStr,
        int cchDest,
        UINT code_page,
        int bError)
{
  int result; // eax
  _LocaleUpdate v10; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v10, plocinfo);
  result = _crtLCMapStringA_stat(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest, code_page, bError);
  if ( v10.updated )
    v10.ptd->_ownlocale &= ~2u;
  return result;
}
