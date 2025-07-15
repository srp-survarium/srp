int __cdecl _wcstombs_l_helper(char *s, wchar_t *pwcs, unsigned int n, localeinfo_struct *plocinfo)
{
  char *v4; // edi
  int result; // eax
  threadlocaleinfostruct *locinfo; // esi
  __int16 v7; // cx
  unsigned int v8; // ecx
  const wchar_t *v9; // eax
  int v10; // eax
  unsigned int v11; // edi
  int v12; // eax
  int v13; // edx
  char v14; // cl
  const wchar_t *lpWideCharStr; // [esp+Ch] [ebp-2Ch]
  unsigned int count; // [esp+14h] [ebp-24h]
  _LocaleUpdate _loc_update; // [esp+18h] [ebp-20h] BYREF
  int defused; // [esp+28h] [ebp-10h] BYREF
  char buffer[8]; // [esp+2Ch] [ebp-Ch] BYREF

  v4 = (char *)pwcs;
  lpWideCharStr = pwcs;
  count = 0;
  defused = 0;
  if ( s && !n )
    return 0;
  if ( !pwcs )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return -1;
  }
  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  if ( !s )
  {
    if ( !_loc_update.localeinfo.locinfo->lc_handle[2] )
    {
      result = wcslen(pwcs);
      goto LABEL_15;
    }
    result = WideCharToMultiByte(_loc_update.localeinfo.locinfo->lc_codepage, 0, pwcs, -1, 0, 0, 0, &defused);
    if ( result && !defused )
    {
LABEL_54:
      --result;
LABEL_15:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    goto LABEL_34;
  }
  locinfo = _loc_update.localeinfo.locinfo;
  if ( _loc_update.localeinfo.locinfo->lc_handle[2] )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max == 1 )
    {
      v8 = n;
      if ( n )
      {
        v9 = pwcs;
        do
        {
          if ( !*v9 )
            break;
          ++v9;
          --v8;
        }
        while ( v8 );
        if ( v8 && !*v9 )
          n = v9 - pwcs + 1;
      }
      result = WideCharToMultiByte(_loc_update.localeinfo.locinfo->lc_codepage, 0, pwcs, n, s, n, 0, &defused);
      if ( result && !defused )
      {
        if ( s[result - 1] )
          goto LABEL_15;
        goto LABEL_54;
      }
    }
    else
    {
      v10 = WideCharToMultiByte(_loc_update.localeinfo.locinfo->lc_codepage, 0, pwcs, -1, s, n, 0, &defused);
      v11 = v10;
      if ( v10 )
      {
        if ( !defused )
        {
          result = v10 - 1;
          goto LABEL_15;
        }
      }
      else if ( !defused && GetLastError() == 122 )
      {
LABEL_46:
        if ( v11 < n )
        {
          v12 = WideCharToMultiByte(locinfo->lc_codepage, 0, lpWideCharStr, 1, buffer, locinfo->mb_cur_max, 0, &defused);
          if ( !v12 || defused || (unsigned int)v12 > 5 )
            goto LABEL_34;
          if ( v12 + v11 <= n )
          {
            v13 = 0;
            while ( 1 )
            {
              v14 = buffer[v13];
              s[v11] = v14;
              if ( !v14 )
                break;
              ++v13;
              ++v11;
              if ( v13 >= v12 )
              {
                ++lpWideCharStr;
                goto LABEL_46;
              }
            }
          }
        }
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return v11;
      }
    }
LABEL_34:
    *_errno() = 42;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return -1;
  }
  if ( n )
  {
    while ( *(_WORD *)v4 <= 0xFFu )
    {
      result = count;
      s[count] = *v4;
      v7 = *(_WORD *)v4;
      v4 += 2;
      if ( !v7 )
        goto LABEL_15;
      ++count;
      if ( result + 1 >= n )
        goto LABEL_12;
    }
    goto LABEL_34;
  }
LABEL_12:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return count;
}
