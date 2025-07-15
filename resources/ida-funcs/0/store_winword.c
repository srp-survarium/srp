int __cdecl store_winword(
        localeinfo_struct *plocinfo,
        int field_code,
        const tm *tmptr,
        char **out,
        unsigned int *count,
        __lc_time_data *lc_time)
{
  char *ww_ldatefmt; // edi
  int (__stdcall *v7)(LCID, DWORD, const SYSTEMTIME *, LPCSTR, LPSTR, int); // ecx
  unsigned __int16 tm_min; // dx
  int v9; // eax
  int v10; // eax
  void *v11; // esp
  char *v12; // eax
  char *v13; // ebx
  int i; // eax
  char *v15; // edx
  int v16; // eax
  signed __int8 v18; // al
  int v19; // edx
  char *v20; // ecx
  char v21; // al
  char *v22; // edi
  unsigned __int8 v23; // al
  char *v24; // edi
  unsigned int ww_lcid; // [esp-18h] [ebp-44h]
  _DWORD v26[3]; // [esp+0h] [ebp-2Ch] BYREF
  SYSTEMTIME Date; // [esp+Ch] [ebp-20h] BYREF
  int v28; // [esp+1Ch] [ebp-10h]
  char *v29; // [esp+20h] [ebp-Ch]
  unsigned int v30; // [esp+24h] [ebp-8h]

  if ( field_code )
  {
    if ( field_code == 1 )
      ww_ldatefmt = lc_time->ww_ldatefmt;
    else
      ww_ldatefmt = lc_time->ww_timefmt;
  }
  else
  {
    ww_ldatefmt = lc_time->ww_sdatefmt;
  }
  if ( lc_time->ww_caltype == 1 )
    goto LABEL_22;
  v7 = GetDateFormatA;
  if ( field_code == 2 )
    v7 = GetTimeFormatA;
  Date.wYear = LOWORD(tmptr->tm_year) + 1900;
  Date.wMonth = LOWORD(tmptr->tm_mon) + 1;
  Date.wDay = tmptr->tm_mday;
  Date.wHour = tmptr->tm_hour;
  tm_min = tmptr->tm_min;
  Date.wSecond = tmptr->tm_sec;
  Date.wMilliseconds = 0;
  ww_lcid = lc_time->ww_lcid;
  v29 = (char *)v7;
  Date.wMinute = tm_min;
  v9 = v7(ww_lcid, 0, &Date, ww_ldatefmt, 0, 0);
  v28 = v9;
  if ( !v9 )
    goto LABEL_22;
  v10 = v9 + 8;
  if ( v10 > 1024 )
  {
    v12 = (char *)malloc(v10);
    if ( !v12 )
      goto LABEL_16;
    *(_DWORD *)v12 = 56797;
  }
  else
  {
    v11 = alloca(v10);
    v12 = (char *)v26;
    if ( !v26 )
      goto LABEL_16;
    v26[0] = 52428;
  }
  v12 += 8;
LABEL_16:
  v30 = (unsigned int)v12;
  if ( v12 )
  {
    v13 = v12;
    for ( i = ((int (__stdcall *)(unsigned int, _DWORD, SYSTEMTIME *, char *, char *, int))v29)(
                lc_time->ww_lcid,
                0,
                &Date,
                ww_ldatefmt,
                v12,
                v28)
            - 1; i > 0; i = v16 - 1 )
    {
      if ( !*count )
        break;
      v15 = *out;
      v28 = i;
      *v15 = *v13;
      ++*out;
      v16 = v28;
      ++v13;
      --*count;
    }
    _freea((_DWORD *)v30);
    return 1;
  }
LABEL_22:
  v18 = *ww_ldatefmt;
  while ( *ww_ldatefmt )
  {
    if ( !*count )
      return 1;
    v19 = 0;
    v30 = 0;
    v20 = ww_ldatefmt;
    do
    {
      ++v20;
      ++v19;
    }
    while ( *v20 == v18 );
    v29 = v20;
    if ( v18 > 100 )
    {
      switch ( v18 )
      {
        case 'h':
          if ( v19 == 1 )
          {
            v30 = 1;
LABEL_119:
            v21 = 73;
LABEL_120:
            if ( !expandtime(v21, tmptr, out, plocinfo, count, lc_time, v30) )
              return 0;
LABEL_121:
            ww_ldatefmt = v29;
            goto LABEL_38;
          }
          if ( v19 == 2 )
            goto LABEL_119;
          break;
        case 'm':
          if ( v19 == 1 )
          {
            v30 = 1;
LABEL_114:
            v21 = 77;
            goto LABEL_120;
          }
          if ( v19 == 2 )
            goto LABEL_114;
          break;
        case 's':
          if ( v19 == 1 )
          {
            v30 = 1;
LABEL_109:
            v21 = 83;
            goto LABEL_120;
          }
          if ( v19 == 2 )
            goto LABEL_109;
          break;
        case 't':
          if ( tmptr->tm_hour > 11 )
            v24 = lc_time->ampm[1];
          else
            v24 = lc_time->ampm[0];
          if ( v19 == 1 && *count )
          {
            if ( _isleadbyte_l(*v24, plocinfo) && *count > 1 )
            {
              if ( !v24[1] )
                return 0;
              *(*out)++ = *v24;
              --*count;
              ++v24;
            }
            *(*out)++ = *v24;
            --*count;
          }
          else
          {
            while ( *v24 && *count )
            {
              if ( _isleadbyte_l(*v24, plocinfo) && *count > 1 )
              {
                if ( !v24[1] )
                  return 0;
                *(*out)++ = *v24;
                --*count;
                ++v24;
              }
              *(*out)++ = *v24++;
              --*count;
            }
          }
          goto LABEL_121;
        case 'y':
          if ( v19 == 2 )
          {
            v21 = 121;
            goto LABEL_120;
          }
          if ( v19 == 4 )
          {
            v21 = 89;
            goto LABEL_120;
          }
          break;
      }
    }
    else
    {
      switch ( v18 )
      {
        case 'd':
          switch ( v19 )
          {
            case 1:
              v30 = 1;
LABEL_77:
              v21 = 100;
              goto LABEL_120;
            case 2:
              goto LABEL_77;
            case 3:
              v21 = 97;
              goto LABEL_120;
            case 4:
              v21 = 65;
              goto LABEL_120;
          }
          break;
        case '\'':
          ww_ldatefmt += v19;
          if ( (v19 & 1) != 0 )
          {
            v23 = *ww_ldatefmt;
            if ( !*ww_ldatefmt )
              return 1;
            while ( *count )
            {
              if ( v23 == 39 )
              {
                ++ww_ldatefmt;
                goto LABEL_38;
              }
              if ( _isleadbyte_l(v23, plocinfo) && *count > 1 )
              {
                if ( !ww_ldatefmt[1] )
                  return 0;
                *(*out)++ = *ww_ldatefmt;
                --*count;
                ++ww_ldatefmt;
              }
              *(*out)++ = *ww_ldatefmt++;
              --*count;
              v23 = *ww_ldatefmt;
              if ( !*ww_ldatefmt )
                goto LABEL_38;
            }
          }
          goto LABEL_38;
        case 'A':
          goto LABEL_53;
        case 'H':
          if ( v19 == 1 )
          {
            v30 = 1;
LABEL_52:
            v21 = 72;
            goto LABEL_120;
          }
          if ( v19 == 2 )
            goto LABEL_52;
          break;
        case 'M':
          switch ( v19 )
          {
            case 1:
              v30 = 1;
LABEL_47:
              v21 = 109;
              goto LABEL_120;
            case 2:
              goto LABEL_47;
            case 3:
              v21 = 98;
              goto LABEL_120;
            case 4:
              v21 = 66;
              goto LABEL_120;
          }
          break;
        case 'a':
LABEL_53:
          if ( !__ascii_stricmp(ww_ldatefmt, "am/pm") )
          {
            v22 = ww_ldatefmt + 5;
            goto LABEL_57;
          }
          if ( !__ascii_stricmp(ww_ldatefmt, "a/p") )
          {
            v22 = ww_ldatefmt + 3;
LABEL_57:
            v29 = v22;
          }
          v21 = 112;
          goto LABEL_120;
      }
    }
    if ( _isleadbyte_l(v18, plocinfo) && *count > 1 )
    {
      if ( !ww_ldatefmt[1] )
        return 0;
      *(*out)++ = *ww_ldatefmt;
      --*count;
      ++ww_ldatefmt;
    }
    *(*out)++ = *ww_ldatefmt++;
    --*count;
LABEL_38:
    v18 = *ww_ldatefmt;
  }
  return 1;
}
