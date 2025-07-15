unsigned int __cdecl _wcstombs_l_helper(char *s, wchar_t *pwcs, unsigned int n, localeinfo_struct *plocinfo)
{
  char *v4; // edi
  unsigned int result; // eax
  threadlocaleinfostruct *locinfo; // esi
  __int16 v7; // cx
  unsigned int v8; // ecx
  wchar_t *v9; // eax
  int v10; // eax
  unsigned int v11; // edi
  int v12; // eax
  int v13; // edx
  char v14; // cl
  const wchar_t *v15; // [esp+Ch] [ebp-2Ch]
  int v16; // [esp+14h] [ebp-24h]
  _LocaleUpdate v17; // [esp+18h] [ebp-20h] BYREF
  int UsedDefaultChar; // [esp+28h] [ebp-10h] BYREF
  char MultiByteStr[8]; // [esp+2Ch] [ebp-Ch] BYREF

  v4 = (char *)pwcs;
  v15 = pwcs;
  v16 = 0;
  UsedDefaultChar = 0;
  if ( s && !n )
    return 0;
  if ( !pwcs )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, (int)s);
    return -1;
  }
  _LocaleUpdate::_LocaleUpdate(&v17, plocinfo);
  if ( !s )
  {
    if ( !v17.localeinfo.locinfo->lc_handle[2] )
    {
      result = wcslen(pwcs);
      goto LABEL_15;
    }
    result = WideCharToMultiByte(v17.localeinfo.locinfo->lc_codepage, 0, pwcs, -1, 0, 0, 0, &UsedDefaultChar);
    if ( result && !UsedDefaultChar )
    {
LABEL_54:
      --result;
LABEL_15:
      if ( v17.updated )
        v17.ptd->_ownlocale &= ~2u;
      return result;
    }
    goto LABEL_34;
  }
  locinfo = v17.localeinfo.locinfo;
  if ( v17.localeinfo.locinfo->lc_handle[2] )
  {
    if ( v17.localeinfo.locinfo->mb_cur_max == 1 )
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
      result = WideCharToMultiByte(v17.localeinfo.locinfo->lc_codepage, 0, pwcs, n, s, n, 0, &UsedDefaultChar);
      if ( result && !UsedDefaultChar )
      {
        if ( s[result - 1] )
          goto LABEL_15;
        goto LABEL_54;
      }
    }
    else
    {
      v10 = WideCharToMultiByte(v17.localeinfo.locinfo->lc_codepage, 0, pwcs, -1, s, n, 0, &UsedDefaultChar);
      v11 = v10;
      if ( v10 )
      {
        if ( !UsedDefaultChar )
        {
          result = v10 - 1;
          goto LABEL_15;
        }
      }
      else if ( !UsedDefaultChar && GetLastError() == 122 )
      {
LABEL_46:
        if ( v11 < n )
        {
          v12 = WideCharToMultiByte(
                  locinfo->lc_codepage,
                  0,
                  v15,
                  1,
                  MultiByteStr,
                  locinfo->mb_cur_max,
                  0,
                  &UsedDefaultChar);
          if ( !v12 || UsedDefaultChar || (unsigned int)v12 > 5 )
            goto LABEL_34;
          if ( v12 + v11 <= n )
          {
            v13 = 0;
            while ( 1 )
            {
              v14 = MultiByteStr[v13];
              s[v11] = v14;
              if ( !v14 )
                break;
              ++v13;
              ++v11;
              if ( v13 >= v12 )
              {
                ++v15;
                goto LABEL_46;
              }
            }
          }
        }
        if ( v17.updated )
          v17.ptd->_ownlocale &= ~2u;
        return v11;
      }
    }
LABEL_34:
    *_errno() = 42;
    if ( v17.updated )
      v17.ptd->_ownlocale &= ~2u;
    return -1;
  }
  if ( n )
  {
    while ( *(_WORD *)v4 <= 0xFFu )
    {
      result = v16;
      s[v16] = *v4;
      v7 = *(_WORD *)v4;
      v4 += 2;
      if ( !v7 )
        goto LABEL_15;
      ++v16;
      if ( result + 1 >= n )
        goto LABEL_12;
    }
    goto LABEL_34;
  }
LABEL_12:
  if ( v17.updated )
    v17.ptd->_ownlocale &= ~2u;
  return v16;
}
