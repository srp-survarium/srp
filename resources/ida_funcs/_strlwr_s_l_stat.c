int __cdecl _strlwr_s_l_stat(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int *v3; // eax
  int v4; // esi
  unsigned int v5; // ecx
  char *i; // ecx
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  int v14; // [esp-4h] [ebp-1Ch]
  _DWORD v15[3]; // [esp+0h] [ebp-18h] BYREF
  int dstsize; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *dst; // [esp+10h] [ebp-8h]

  if ( !string )
    goto LABEL_2;
  if ( strnlen(string, sizeInBytes) >= sizeInBytes )
  {
    *string = 0;
LABEL_2:
    v3 = _errno();
    v14 = 22;
LABEL_3:
    v4 = v14;
    *v3 = v14;
    _invalid_parameter(0, 0, 0, 0, 0);
    return v4;
  }
  v5 = plocinfo->locinfo->lc_handle[2];
  if ( v5 )
  {
    v9 = __crtLCMapStringA(plocinfo, v5, 0x100u, string, -1, 0, 0, plocinfo->locinfo->lc_codepage, 1);
    v10 = v9;
    dstsize = v9;
    if ( !v9 )
    {
      *_errno() = 42;
      return *_errno();
    }
    if ( sizeInBytes < v9 )
    {
      *string = 0;
      v3 = _errno();
      v14 = 34;
      goto LABEL_3;
    }
    if ( v9 <= 0 || !(0xFFFFFFE0 / v9) )
    {
      dst = 0;
      goto LABEL_28;
    }
    v11 = v9 + 8;
    if ( (unsigned int)(v10 + 8) > 0x400 )
    {
      v13 = (unsigned __int8 *)malloc(v10 + 8);
      if ( v13 )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)v15;
      if ( v15 )
      {
        v15[0] = 52428;
LABEL_25:
        v13 += 8;
      }
    }
    v10 = dstsize;
    dst = v13;
LABEL_28:
    if ( dst )
    {
      if ( __crtLCMapStringA(
             plocinfo,
             plocinfo->locinfo->lc_handle[2],
             0x100u,
             string,
             -1,
             (char *)dst,
             v10,
             plocinfo->locinfo->lc_codepage,
             1) )
      {
        v4 = strcpy_s(string, sizeInBytes, (const char *)dst);
      }
      else
      {
        *_errno() = 42;
        v4 = 42;
      }
      _freea(dst);
      return v4;
    }
    *_errno() = 12;
    return *_errno();
  }
  for ( i = string; *i; ++i )
  {
    v7 = *i;
    if ( *i >= 65 && v7 <= 90 )
      *i = v7 + 32;
  }
  return 0;
}
