char *__cdecl __convertcp(UINT fromCP, UINT toCP, char *lpSrcStr, int *pcchSrc, char *lpDestStr, int cchDest)
{
  int v6; // esi
  int v7; // eax
  bool v8; // cc
  unsigned int v9; // eax
  void *v10; // esp
  wchar_t *v11; // eax
  LPSTR v13; // ebx
  unsigned __int8 *v14; // eax
  int v15; // eax
  _DWORD v16[3]; // [esp+0h] [ebp-40h] BYREF
  LPSTR lpMultiByteStr; // [esp+Ch] [ebp-34h]
  int *v18; // [esp+10h] [ebp-30h]
  int v19; // [esp+14h] [ebp-2Ch]
  unsigned __int8 *buf; // [esp+18h] [ebp-28h]
  int cbMultiByte; // [esp+1Ch] [ebp-24h]
  void *pointer; // [esp+20h] [ebp-20h]
  LPWSTR lpWideCharStr; // [esp+24h] [ebp-1Ch]
  _cpinfo CPInfo; // [esp+28h] [ebp-18h] BYREF

  buf = (unsigned __int8 *)lpSrcStr;
  v18 = pcchSrc;
  cbMultiByte = *pcchSrc;
  lpMultiByteStr = lpDestStr;
  pointer = 0;
  v19 = 0;
  if ( fromCP != toCP )
  {
    if ( GetCPInfo(fromCP, &CPInfo) && CPInfo.MaxCharSize == 1 && GetCPInfo(toCP, &CPInfo) && CPInfo.MaxCharSize == 1 )
    {
      v6 = cbMultiByte;
      v19 = 1;
      if ( cbMultiByte == -1 )
      {
        strlen(buf);
        v6 = v7 + 1;
      }
      v8 = v6 <= 0;
    }
    else
    {
      v6 = MultiByteToWideChar(fromCP, 1u, (LPCCH)buf, cbMultiByte, 0, 0);
      v8 = v6 <= 0;
      if ( !v6 )
        return 0;
    }
    if ( v8 || (unsigned int)v6 > 0x7FFFFFF0 )
    {
      lpWideCharStr = 0;
LABEL_21:
      if ( lpWideCharStr )
      {
        memset((int)lpWideCharStr, 0, 2 * v6);
        if ( MultiByteToWideChar(fromCP, 1u, (LPCCH)buf, cbMultiByte, lpWideCharStr, v6) )
        {
          v13 = lpMultiByteStr;
          if ( lpMultiByteStr )
          {
            if ( WideCharToMultiByte(toCP, 0, lpWideCharStr, v6, lpMultiByteStr, cchDest, 0, 0) )
              pointer = v13;
          }
          else if ( v19 || (v6 = WideCharToMultiByte(toCP, 0, lpWideCharStr, v6, 0, 0, 0, 0)) != 0 )
          {
            v14 = _calloc_crt(1u, v6);
            pointer = v14;
            if ( v14 )
            {
              v15 = WideCharToMultiByte(toCP, 0, lpWideCharStr, v6, (LPSTR)v14, v6, 0, 0);
              if ( v15 )
              {
                if ( cbMultiByte != -1 )
                  *v18 = v15;
              }
              else
              {
                free(pointer);
                pointer = 0;
              }
            }
          }
        }
        _freea(lpWideCharStr);
        return (char *)pointer;
      }
      return 0;
    }
    v9 = 2 * v6 + 8;
    if ( v9 > 0x400 )
    {
      v11 = (wchar_t *)malloc(2 * v6 + 8);
      if ( v11 )
      {
        *(_DWORD *)v11 = 56797;
        goto LABEL_18;
      }
    }
    else
    {
      v10 = alloca(v9);
      v11 = (wchar_t *)v16;
      if ( v16 )
      {
        v16[0] = 52428;
LABEL_18:
        v11 += 4;
      }
    }
    lpWideCharStr = v11;
    goto LABEL_21;
  }
  return (char *)pointer;
}
