void __cdecl _mbstowcs_l_helper(wchar_t *pwcs, char *s, unsigned int n, localeinfo_struct *plocinfo)
{
  wchar_t *v4; // esi
  unsigned int v5; // ecx
  char *v6; // eax
  unsigned __int8 *v7; // esi
  unsigned __int8 v8; // al
  _LocaleUpdate v9; // [esp+8h] [ebp-14h] BYREF
  unsigned int i; // [esp+18h] [ebp-4h]

  v4 = pwcs;
  i = 0;
  if ( pwcs )
  {
    if ( !n )
      return;
    *pwcs = 0;
  }
  if ( !s )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, (int)pwcs);
    return;
  }
  _LocaleUpdate::_LocaleUpdate(&v9, plocinfo);
  if ( !pwcs )
  {
    if ( v9.localeinfo.locinfo->lc_handle[2] )
    {
      if ( !MultiByteToWideChar(v9.localeinfo.locinfo->lc_codepage, 9u, s, -1, 0, 0) )
      {
        *_errno() = 42;
LABEL_31:
        if ( v9.updated )
          v9.ptd->_ownlocale &= ~2u;
        return;
      }
    }
    else
    {
      strlen((unsigned __int8 *)s);
    }
LABEL_34:
    if ( v9.updated )
      v9.ptd->_ownlocale &= ~2u;
    return;
  }
  if ( v9.localeinfo.locinfo->lc_handle[2] )
  {
    if ( !MultiByteToWideChar(v9.localeinfo.locinfo->lc_codepage, 9u, s, -1, pwcs, n) )
    {
      if ( GetLastError() != 122 )
        goto LABEL_19;
      v7 = (unsigned __int8 *)s;
      for ( i = n; i; ++v7 )
      {
        v8 = *v7;
        --i;
        if ( !v8 )
          break;
        if ( _isleadbyte_l(v8, &v9.localeinfo) )
        {
          if ( !*++v7 )
            goto LABEL_19;
        }
      }
      if ( !MultiByteToWideChar(v9.localeinfo.locinfo->lc_codepage, 1u, s, v7 - (unsigned __int8 *)s, pwcs, n) )
      {
LABEL_19:
        *_errno() = 42;
        *pwcs = 0;
        goto LABEL_31;
      }
    }
    goto LABEL_34;
  }
  if ( n )
  {
    while ( 1 )
    {
      v5 = i;
      v6 = &s[i];
      *v4 = (unsigned __int8)s[i];
      if ( !*v6 )
        break;
      ++v4;
      i = v5 + 1;
      if ( v5 + 1 >= n )
        goto LABEL_11;
    }
    if ( v9.updated )
      v9.ptd->_ownlocale &= ~2u;
  }
  else
  {
LABEL_11:
    if ( v9.updated )
      v9.ptd->_ownlocale &= ~2u;
  }
}
