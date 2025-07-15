int __cdecl _crtGetStringTypeA_stat(
        DWORD dwInfoType,
        char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        UINT code_page,
        LCID lcid,
        int bError)
{
  int v7; // ecx
  int v8; // eax
  wchar_t *v9; // ebx
  int v10; // edi
  int v11; // eax
  int v12; // edi
  unsigned int v13; // eax
  void *v14; // esp
  wchar_t *v15; // eax
  int v16; // eax
  char *v18; // esi
  UINT v19; // eax
  char *v20; // eax
  BOOL StringTypeA; // edi
  _DWORD v22[3]; // [esp+0h] [ebp-14h] BYREF
  unsigned __int16 CharType[2]; // [esp+Ch] [ebp-8h] BYREF

  v8 = f_use_1;
  v9 = 0;
  v10 = v7;
  if ( !f_use_1 )
  {
    if ( GetStringTypeW(1u, &FLOAT_0_0, 1, CharType) )
    {
      f_use_1 = 1;
      goto LABEL_10;
    }
    if ( GetLastError() == 120 )
    {
      v8 = 2;
      f_use_1 = 2;
    }
    else
    {
      v8 = f_use_1;
    }
  }
  if ( v8 != 2 && v8 )
  {
    if ( v8 != 1 )
      return 0;
LABEL_10:
    *(_DWORD *)CharType = 0;
    if ( !code_page )
      code_page = *(_DWORD *)(*(_DWORD *)v10 + 4);
    v11 = MultiByteToWideChar(code_page, 8 * (bError != 0) + 1, lpSrcStr, cchSrc, 0, 0);
    v12 = v11;
    if ( !v11 )
      return 0;
    if ( v11 <= 0 || (unsigned int)v11 > 0x7FFFFFF0 )
      goto LABEL_22;
    v13 = 2 * v11 + 8;
    if ( v13 > 0x400 )
    {
      v15 = (wchar_t *)malloc(2 * v12 + 8);
      if ( v15 )
      {
        *(_DWORD *)v15 = 56797;
        goto LABEL_20;
      }
    }
    else
    {
      v14 = alloca(v13);
      v15 = (wchar_t *)v22;
      if ( v22 )
      {
        v22[0] = 52428;
LABEL_20:
        v15 += 4;
      }
    }
    v9 = v15;
LABEL_22:
    if ( v9 )
    {
      memset((int)v9, 0, 2 * v12);
      v16 = MultiByteToWideChar(code_page, 1u, lpSrcStr, cchSrc, v9, v12);
      if ( v16 )
        *(_DWORD *)CharType = GetStringTypeW(dwInfoType, v9, v16, lpCharType);
      _freea(v9);
      return *(_DWORD *)CharType;
    }
    return 0;
  }
  v18 = 0;
  if ( !lcid )
    lcid = *(_DWORD *)(*(_DWORD *)v10 + 20);
  if ( !code_page )
    code_page = *(_DWORD *)(*(_DWORD *)v10 + 4);
  v19 = __ansicp(lcid);
  if ( v19 == -1 )
    return 0;
  if ( v19 != code_page )
  {
    v20 = __convertcp(code_page, v19, lpSrcStr, &cchSrc, 0, 0);
    v18 = v20;
    if ( !v20 )
      return 0;
    lpSrcStr = v20;
  }
  StringTypeA = GetStringTypeA(lcid, dwInfoType, lpSrcStr, cchSrc, lpCharType);
  if ( v18 )
    free(v18);
  return StringTypeA;
}
