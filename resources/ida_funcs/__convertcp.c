char *__cdecl __convertcp(UINT fromCP, UINT toCP, char *lpSrcStr, int *pcchSrc, char *lpDestStr, int cchDest)
{
  int v6; // esi
  int v7; // eax
  bool v8; // cc
  unsigned int v9; // eax
  void *v10; // esp
  unsigned __int16 *v11; // eax
  char *v13; // ebx
  char *v14; // eax
  int v15; // eax
  _DWORD v16[3]; // [esp+0h] [ebp-40h] BYREF
  LPSTR lpMultiByteStr; // [esp+Ch] [ebp-34h]
  int *v18; // [esp+10h] [ebp-30h]
  int sb; // [esp+14h] [ebp-2Ch]
  unsigned __int8 *buf; // [esp+18h] [ebp-28h]
  int cchSrc; // [esp+1Ch] [ebp-24h]
  char *cbuffer; // [esp+20h] [ebp-20h]
  unsigned __int16 *wbuffer; // [esp+24h] [ebp-1Ch]
  _cpinfo cpi; // [esp+28h] [ebp-18h] BYREF

  buf = (unsigned __int8 *)lpSrcStr;
  v18 = pcchSrc;
  cchSrc = *pcchSrc;
  lpMultiByteStr = lpDestStr;
  cbuffer = 0;
  sb = 0;
  if ( fromCP != toCP )
  {
    if ( GetCPInfo(fromCP, &cpi) && cpi.MaxCharSize == 1 && GetCPInfo(toCP, &cpi) && cpi.MaxCharSize == 1 )
    {
      v6 = cchSrc;
      sb = 1;
      if ( cchSrc == -1 )
      {
        strlen(buf);
        v6 = v7 + 1;
      }
      v8 = v6 <= 0;
    }
    else
    {
      v6 = MultiByteToWideChar(fromCP, 1u, (LPCCH)buf, cchSrc, 0, 0);
      v8 = v6 <= 0;
      if ( !v6 )
        return 0;
    }
    if ( v8 || (unsigned int)v6 > 0x7FFFFFF0 )
    {
      wbuffer = 0;
LABEL_21:
      if ( wbuffer )
      {
        memset((int)wbuffer, 0, 2 * v6);
        if ( MultiByteToWideChar(fromCP, 1u, (LPCCH)buf, cchSrc, wbuffer, v6) )
        {
          v13 = lpMultiByteStr;
          if ( lpMultiByteStr )
          {
            if ( WideCharToMultiByte(toCP, 0, wbuffer, v6, lpMultiByteStr, cchDest, 0, 0) )
              cbuffer = v13;
          }
          else if ( sb || (v6 = WideCharToMultiByte(toCP, 0, wbuffer, v6, 0, 0, 0, 0)) != 0 )
          {
            v14 = (char *)_calloc_crt(1u, v6);
            cbuffer = v14;
            if ( v14 )
            {
              v15 = WideCharToMultiByte(toCP, 0, wbuffer, v6, v14, v6, 0, 0);
              if ( v15 )
              {
                if ( cchSrc != -1 )
                  *v18 = v15;
              }
              else
              {
                free(cbuffer);
                cbuffer = 0;
              }
            }
          }
        }
        _freea(wbuffer);
        return cbuffer;
      }
      return 0;
    }
    v9 = 2 * v6 + 8;
    if ( v9 > 0x400 )
    {
      v11 = (unsigned __int16 *)malloc(2 * v6 + 8);
      if ( v11 )
      {
        *(_DWORD *)v11 = 56797;
        goto LABEL_18;
      }
    }
    else
    {
      v10 = alloca(v9);
      v11 = (unsigned __int16 *)v16;
      if ( v16 )
      {
        v16[0] = 52428;
LABEL_18:
        v11 += 4;
      }
    }
    wbuffer = v11;
    goto LABEL_21;
  }
  return cbuffer;
}
