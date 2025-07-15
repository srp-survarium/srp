int __cdecl _crtLCMapStringA_stat(
        LCID Locale,
        DWORD dwMapFlags,
        char *lpSrcStr,
        int cchSrc,
        wchar_t *lpDestStr,
        int cchDest,
        UINT code_page,
        int bError)
{
  int v8; // ecx
  int v9; // esi
  int v10; // ecx
  char *v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // edi
  unsigned int v15; // eax
  void *v16; // esp
  wchar_t *v17; // eax
  int v18; // eax
  int v19; // ecx
  unsigned int v20; // eax
  void *v21; // esp
  wchar_t *v22; // esi
  wchar_t *v23; // eax
  int v24; // eax
  int v26; // eax
  char *v27; // eax
  int v28; // eax
  int v29; // esi
  unsigned int v30; // eax
  void *v31; // esp
  char *v32; // edi
  char *v33; // eax
  _DWORD v34[2]; // [esp+0h] [ebp-20h] BYREF
  int v35; // [esp+8h] [ebp-18h] BYREF
  int fromCP; // [esp+Ch] [ebp-14h]
  void *pointer; // [esp+10h] [ebp-10h]
  LPWSTR lpWideCharStr; // [esp+14h] [ebp-Ch]
  int cchWideChar; // [esp+18h] [ebp-8h] BYREF

  v9 = v8;
  if ( !f_use_0 )
  {
    if ( LCMapStringW(0, 0x100u, &FLOAT_0_0, 1, 0, 0) )
    {
      f_use_0 = 1;
    }
    else if ( GetLastError() == 120 )
    {
      f_use_0 = 2;
    }
  }
  if ( cchSrc > 0 )
  {
    v10 = cchSrc;
    v11 = lpSrcStr;
    while ( 1 )
    {
      --v10;
      if ( !*v11 )
        break;
      ++v11;
      if ( !v10 )
      {
        v10 = -1;
        break;
      }
    }
    v12 = cchSrc - v10 - 1;
    if ( v12 < cchSrc )
      v12 = cchSrc - v10;
    cchSrc = v12;
  }
  if ( f_use_0 != 2 && f_use_0 )
  {
    if ( f_use_0 == 1 )
    {
      cchWideChar = 0;
      if ( !code_page )
        code_page = *(_DWORD *)(*(_DWORD *)v9 + 4);
      v13 = MultiByteToWideChar(code_page, 8 * (bError != 0) + 1, lpSrcStr, cchSrc, 0, 0);
      v14 = v13;
      if ( v13 )
      {
        if ( v13 <= 0 || 0xFFFFFFE0 / v13 < 2 )
        {
          lpWideCharStr = 0;
LABEL_30:
          if ( lpWideCharStr )
          {
            if ( MultiByteToWideChar(code_page, 1u, lpSrcStr, cchSrc, lpWideCharStr, v14) )
            {
              v18 = LCMapStringW(Locale, dwMapFlags, lpWideCharStr, v14, 0, 0);
              v19 = v18;
              cchWideChar = v18;
              if ( v18 )
              {
                if ( (dwMapFlags & 0x400) != 0 )
                {
                  if ( cchDest )
                  {
                    if ( v18 <= cchDest )
                      LCMapStringW(Locale, dwMapFlags, lpWideCharStr, v14, lpDestStr, cchDest);
                  }
                  goto LABEL_53;
                }
                if ( v18 <= 0 || 0xFFFFFFE0 / v18 < 2 )
                {
                  v22 = 0;
LABEL_46:
                  if ( v22 )
                  {
                    if ( LCMapStringW(Locale, dwMapFlags, lpWideCharStr, v14, v22, cchWideChar) )
                    {
                      if ( cchDest )
                        v24 = WideCharToMultiByte(code_page, 0, v22, cchWideChar, (LPSTR)lpDestStr, cchDest, 0, 0);
                      else
                        v24 = WideCharToMultiByte(code_page, 0, v22, cchWideChar, 0, 0, 0, 0);
                      cchWideChar = v24;
                    }
                    _freea(v22);
                  }
                  goto LABEL_53;
                }
                v20 = 2 * v18 + 8;
                if ( v20 > 0x400 )
                {
                  v23 = (wchar_t *)malloc(2 * v19 + 8);
                  if ( v23 )
                  {
                    *(_DWORD *)v23 = 56797;
                    v23 += 4;
                  }
                  v22 = v23;
                  goto LABEL_46;
                }
                v21 = alloca(v20);
                if ( v34 )
                {
                  v34[0] = 52428;
                  v22 = (wchar_t *)&v35;
                  goto LABEL_46;
                }
              }
            }
LABEL_53:
            _freea(lpWideCharStr);
            return cchWideChar;
          }
          return 0;
        }
        v15 = 2 * v13 + 8;
        if ( v15 > 0x400 )
        {
          v17 = (wchar_t *)malloc(2 * v14 + 8);
          if ( v17 )
          {
            *(_DWORD *)v17 = 56797;
            goto LABEL_27;
          }
        }
        else
        {
          v16 = alloca(v15);
          v17 = (wchar_t *)v34;
          if ( v34 )
          {
            v34[0] = 52428;
LABEL_27:
            v17 += 4;
          }
        }
        lpWideCharStr = v17;
        goto LABEL_30;
      }
    }
    return 0;
  }
  lpWideCharStr = 0;
  pointer = 0;
  if ( !Locale )
    Locale = *(_DWORD *)(*(_DWORD *)v9 + 20);
  if ( !code_page )
    code_page = *(_DWORD *)(*(_DWORD *)v9 + 4);
  v26 = __ansicp(Locale);
  fromCP = v26;
  if ( v26 == -1 )
    return 0;
  if ( v26 == code_page )
  {
    v29 = LCMapStringA(Locale, dwMapFlags, lpSrcStr, cchSrc, (LPSTR)lpDestStr, cchDest);
    goto LABEL_78;
  }
  v27 = __convertcp(code_page, v26, lpSrcStr, &cchSrc, 0, 0);
  lpWideCharStr = (LPWSTR)v27;
  if ( !v27 )
    return 0;
  v28 = LCMapStringA(Locale, dwMapFlags, v27, cchSrc, 0, 0);
  cchWideChar = v28;
  if ( v28 )
  {
    if ( v28 <= 0 )
    {
      v32 = 0;
    }
    else
    {
      v30 = v28 + 8;
      if ( v30 > 0x400 )
      {
        v33 = (char *)malloc(v30);
        if ( v33 )
        {
          *(_DWORD *)v33 = 56797;
          v33 += 8;
        }
        v32 = v33;
      }
      else
      {
        v31 = alloca(v30);
        if ( !v34 )
          goto LABEL_63;
        v34[0] = 52428;
        v32 = (char *)&v35;
      }
    }
    if ( v32 )
    {
      memset((int)v32, 0, cchWideChar);
      cchWideChar = LCMapStringA(Locale, dwMapFlags, (LPCSTR)lpWideCharStr, cchSrc, v32, cchWideChar);
      if ( cchWideChar )
      {
        pointer = __convertcp(fromCP, code_page, v32, &cchWideChar, (char *)lpDestStr, cchDest);
        v29 = pointer != 0 ? cchWideChar : 0;
      }
      else
      {
        v29 = 0;
      }
      _freea(v32);
      goto LABEL_78;
    }
  }
LABEL_63:
  v29 = 0;
LABEL_78:
  if ( lpWideCharStr )
    free(lpWideCharStr);
  if ( pointer && lpDestStr != pointer )
    free(pointer);
  return v29;
}
