void __cdecl _mbstowcs_l_helper(wchar_t *pwcs, char *s, unsigned int n, localeinfo_struct *plocinfo)
{
  wchar_t *v4; // esi
  int v5; // ecx
  const char *v6; // eax
  char *v7; // esi
  unsigned __int8 v8; // al
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-14h] BYREF
  int charcnt; // [esp+18h] [ebp-4h]

  v4 = pwcs;
  charcnt = 0;
  if ( pwcs )
  {
    if ( !n )
      return;
    *pwcs = 0;
  }
  if ( !s )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return;
  }
  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  if ( !pwcs )
  {
    if ( _loc_update.localeinfo.locinfo->lc_handle[2] )
    {
      if ( !MultiByteToWideChar(_loc_update.localeinfo.locinfo->lc_codepage, 9u, s, -1, 0, 0) )
      {
        *_errno() = 42;
LABEL_31:
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return;
      }
    }
    else
    {
      strlen((unsigned __int8 *)s);
    }
LABEL_34:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  if ( _loc_update.localeinfo.locinfo->lc_handle[2] )
  {
    if ( !MultiByteToWideChar(_loc_update.localeinfo.locinfo->lc_codepage, 9u, s, -1, pwcs, n) )
    {
      if ( GetLastError() != 122 )
        goto LABEL_19;
      v7 = s;
      charcnt = n;
      if ( n )
      {
        do
        {
          v8 = *v7;
          --charcnt;
          if ( !v8 )
            break;
          if ( _isleadbyte_l(v8, &_loc_update.localeinfo) )
          {
            if ( !*++v7 )
              goto LABEL_19;
          }
          ++v7;
        }
        while ( charcnt );
      }
      if ( !MultiByteToWideChar(_loc_update.localeinfo.locinfo->lc_codepage, 1u, s, v7 - s, pwcs, n) )
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
      v5 = charcnt;
      v6 = &s[charcnt];
      *v4 = (unsigned __int8)s[charcnt];
      if ( !*v6 )
        break;
      ++v4;
      charcnt = v5 + 1;
      if ( v5 + 1 >= n )
        goto LABEL_11;
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
LABEL_11:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
}
