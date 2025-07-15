void __usercall _strnicmp_l(
        const char *a1@<edi>,
        int a2@<esi>,
        char *dst,
        char *src,
        unsigned int count,
        localeinfo_struct *plocinfo)
{
  int v6; // eax
  int v7; // esi
  int v8; // eax
  _LocaleUpdate v9; // [esp+Ch] [ebp-10h] BYREF

  if ( count )
  {
    _LocaleUpdate::_LocaleUpdate(&v9, plocinfo);
    if ( dst && (a1 = src) != 0 )
    {
      if ( count <= 0x7FFFFFFF )
      {
        if ( v9.localeinfo.locinfo->lc_handle[2] )
        {
          do
          {
            v6 = _tolower_l((unsigned __int8)*dst++, &v9.localeinfo);
            v7 = v6;
            v8 = _tolower_l(*(unsigned __int8 *)a1++, &v9.localeinfo);
            --count;
          }
          while ( count && v7 && v7 == v8 );
        }
        else
        {
          __ascii_strnicmp((unsigned __int8 *)dst, (unsigned __int8 *)src, count);
        }
        if ( v9.updated )
          v9.ptd->_ownlocale &= ~2u;
      }
      else
      {
        *_errno() = 22;
        _invalid_parameter(0, (int)src, 0x7FFFFFFF);
        if ( v9.updated )
          v9.ptd->_ownlocale &= ~2u;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(0, (int)a1, a2);
      if ( v9.updated )
        v9.ptd->_ownlocale &= ~2u;
    }
  }
}
