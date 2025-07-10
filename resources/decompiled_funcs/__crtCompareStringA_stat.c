int __fastcall _crtCompareStringA_stat(
        localeinfo_struct *plocinfo,
        const char *lpString1,
        LCID Locale,
        DWORD dwCmpFlags,
        int cchCount1,
        char *lpString2,
        int cchCount2,
        UINT code_page)
{
  int v10; // edx
  int result; // eax
  unsigned __int8 *LeadByte; // eax
  unsigned __int8 v13; // dl
  unsigned __int8 *i; // eax
  unsigned __int8 v15; // dl
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // eax
  void *v19; // esp
  wchar_t *v20; // eax
  int v21; // eax
  int v22; // ebx
  unsigned int v23; // eax
  void *v24; // esp
  WCHAR *v25; // edi
  WCHAR *v26; // eax
  char *v27; // edi
  char *v28; // ebx
  UINT v29; // eax
  UINT v30; // esi
  char *v31; // eax
  int v32; // esi
  _DWORD v34[2]; // [esp+0h] [ebp-38h] BYREF
  int v35; // [esp+8h] [ebp-30h] BYREF
  int buff_size1; // [esp+Ch] [ebp-2Ch]
  int retcode; // [esp+10h] [ebp-28h]
  LPCCH lpMultiByteStr; // [esp+14h] [ebp-24h]
  wchar_t *wbuffer1; // [esp+18h] [ebp-20h]
  char *string; // [esp+1Ch] [ebp-1Ch]
  _cpinfo lpCPInfo; // [esp+20h] [ebp-18h] BYREF

  lpMultiByteStr = lpString1;
  string = lpString2;
  if ( !f_use_3 )
  {
    if ( CompareStringW(0, 0, &FLOAT_0_0, 1, &FLOAT_0_0, 1) )
    {
      f_use_3 = 1;
    }
    else if ( GetLastError() == 120 )
    {
      f_use_3 = 2;
    }
  }
  if ( cchCount1 <= 0 )
  {
    if ( cchCount1 < -1 )
      return 0;
  }
  else
  {
    cchCount1 = strncnt(lpString1, cchCount1);
  }
  v10 = cchCount2;
  if ( cchCount2 <= 0 )
  {
    if ( cchCount2 < -1 )
      return 0;
  }
  else
  {
    v10 = strncnt(string, cchCount2);
    cchCount2 = v10;
  }
  if ( f_use_3 == 2 || !f_use_3 )
  {
    v27 = 0;
    v28 = 0;
    if ( !Locale )
      Locale = plocinfo->locinfo->lc_handle[2];
    if ( !code_page )
      code_page = plocinfo->locinfo->lc_codepage;
    v29 = __ansicp(Locale);
    v30 = v29;
    if ( v29 == -1 )
      return 0;
    if ( v29 != code_page )
    {
      v28 = __convertcp(code_page, v29, (char *)lpMultiByteStr, &cchCount1, 0, 0);
      if ( !v28 )
        return 0;
      v31 = __convertcp(code_page, v30, string, &cchCount2, 0, 0);
      v27 = v31;
      if ( !v31 )
      {
        free(v28);
        return 0;
      }
      lpMultiByteStr = v28;
      string = v31;
    }
    v32 = CompareStringA(Locale, dwCmpFlags, lpMultiByteStr, cchCount1, string, cchCount2);
    if ( v28 )
    {
      free(v28);
      free(v27);
    }
    return v32;
  }
  result = 1;
  if ( f_use_3 != 1 )
    return 0;
  retcode = 0;
  if ( !code_page )
    code_page = plocinfo->locinfo->lc_codepage;
  if ( cchCount1 && v10 )
  {
LABEL_44:
    v16 = MultiByteToWideChar(code_page, 9u, lpString1, cchCount1, 0, 0);
    v17 = v16;
    buff_size1 = v16;
    if ( !v16 )
      return 0;
    if ( v16 <= 0 || 0xFFFFFFE0 / v16 < 2 )
    {
      wbuffer1 = 0;
LABEL_55:
      if ( wbuffer1 )
      {
        if ( MultiByteToWideChar(code_page, 1u, lpMultiByteStr, cchCount1, wbuffer1, v17) )
        {
          v21 = MultiByteToWideChar(code_page, 9u, string, cchCount2, 0, 0);
          v22 = v21;
          if ( v21 )
          {
            if ( v21 <= 0 || 0xFFFFFFE0 / v21 < 2 )
            {
              v25 = 0;
LABEL_67:
              if ( v25 )
              {
                if ( MultiByteToWideChar(code_page, 1u, string, cchCount2, v25, v22) )
                  retcode = CompareStringW(Locale, dwCmpFlags, wbuffer1, buff_size1, v25, v22);
                _freea(v25);
              }
              goto error_cleanup_2;
            }
            v23 = 2 * v21 + 8;
            if ( v23 > 0x400 )
            {
              v26 = (WCHAR *)malloc(2 * v22 + 8);
              if ( v26 )
              {
                *(_DWORD *)v26 = 56797;
                v26 += 4;
              }
              v25 = v26;
              goto LABEL_67;
            }
            v24 = alloca(v23);
            if ( v34 )
            {
              v34[0] = 52428;
              v25 = (WCHAR *)&v35;
              goto LABEL_67;
            }
          }
        }
error_cleanup_2:
        _freea(wbuffer1);
        return retcode;
      }
      return 0;
    }
    v18 = 2 * v16 + 8;
    if ( v18 > 0x400 )
    {
      v20 = (wchar_t *)malloc(2 * v17 + 8);
      if ( v20 )
      {
        *(_DWORD *)v20 = 56797;
        goto LABEL_52;
      }
    }
    else
    {
      v19 = alloca(v18);
      v20 = (wchar_t *)v34;
      if ( v34 )
      {
        v34[0] = 52428;
LABEL_52:
        v20 += 4;
      }
    }
    wbuffer1 = v20;
    goto LABEL_55;
  }
  if ( cchCount1 == v10 )
    return 2;
  if ( v10 <= 1 )
  {
    if ( cchCount1 > 1 )
      return 3;
    if ( !GetCPInfo(code_page, &lpCPInfo) )
      return 0;
    if ( cchCount1 > 0 )
    {
      if ( lpCPInfo.MaxCharSize >= 2 )
      {
        LeadByte = lpCPInfo.LeadByte;
        if ( lpCPInfo.LeadByte[0] )
        {
          while ( 1 )
          {
            v13 = LeadByte[1];
            if ( !v13 )
              break;
            if ( (unsigned int)*lpString1 >= *LeadByte && (unsigned int)*lpString1 <= v13 )
              return 2;
            LeadByte += 2;
            if ( !*LeadByte )
              return 3;
          }
        }
      }
      return 3;
    }
    if ( cchCount2 > 0 )
    {
      if ( lpCPInfo.MaxCharSize >= 2 )
      {
        for ( i = lpCPInfo.LeadByte; *i; i += 2 )
        {
          v15 = i[1];
          if ( !v15 )
            break;
          if ( (unsigned __int8)*string >= *i && (unsigned __int8)*string <= v15 )
            return 2;
        }
      }
      return 1;
    }
    goto LABEL_44;
  }
  return result;
}
