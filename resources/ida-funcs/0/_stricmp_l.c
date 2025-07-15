unsigned int __usercall _stricmp_l@<eax>(int a1@<edi>, int a2@<esi>, char *dst, char *src, localeinfo_struct *plocinfo)
{
  unsigned int result; // eax
  char *v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // esi
  unsigned int v9; // eax
  _LocaleUpdate v10; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v10, plocinfo);
  if ( dst )
  {
    v6 = src;
    if ( src )
    {
      if ( v10.localeinfo.locinfo->lc_handle[2] )
      {
        do
        {
          v7 = _tolower_l((unsigned __int8)*dst++, &v10.localeinfo);
          v8 = v7;
          v9 = _tolower_l((unsigned __int8)*v6++, &v10.localeinfo);
        }
        while ( v8 && v8 == v9 );
        result = v8 - v9;
      }
      else
      {
        result = __ascii_stricmp(dst, src);
      }
      if ( v10.updated )
        v10.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(0, 0, a2);
      if ( v10.updated )
        v10.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, a2);
    if ( v10.updated )
      v10.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}
