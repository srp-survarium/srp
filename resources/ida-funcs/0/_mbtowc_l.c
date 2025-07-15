int __cdecl _mbtowc_l(wchar_t *pwc, const char *s, unsigned int n, localeinfo_struct *plocinfo)
{
  int result; // eax
  threadlocaleinfostruct *locinfo; // eax
  int mb_cur_max; // ecx
  bool v7; // zf
  _LocaleUpdate v8; // [esp+8h] [ebp-10h] BYREF

  if ( !s || !n )
    return 0;
  if ( !*s )
  {
    if ( pwc )
      *pwc = 0;
    return 0;
  }
  _LocaleUpdate::_LocaleUpdate(&v8, plocinfo);
  if ( !v8.localeinfo.locinfo->lc_handle[2] )
  {
    if ( pwc )
      *pwc = *(unsigned __int8 *)s;
    goto LABEL_11;
  }
  if ( _isleadbyte_l(*s, &v8.localeinfo) )
  {
    locinfo = v8.localeinfo.locinfo;
    mb_cur_max = v8.localeinfo.locinfo->mb_cur_max;
    if ( mb_cur_max > 1
      && (int)n >= mb_cur_max
      && (v7 = MultiByteToWideChar(v8.localeinfo.locinfo->lc_codepage, 9u, s, mb_cur_max, pwc, pwc != 0) == 0,
          locinfo = v8.localeinfo.locinfo,
          !v7)
      || n >= locinfo->mb_cur_max && s[1] )
    {
      result = locinfo->mb_cur_max;
      if ( v8.updated )
        v8.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  else if ( MultiByteToWideChar(v8.localeinfo.locinfo->lc_codepage, 9u, s, 1, pwc, pwc != 0) )
  {
LABEL_11:
    if ( v8.updated )
      v8.ptd->_ownlocale &= ~2u;
    return 1;
  }
  *_errno() = 42;
  if ( v8.updated )
    v8.ptd->_ownlocale &= ~2u;
  return -1;
}
