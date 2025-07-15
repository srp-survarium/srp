unsigned int __usercall wcsupr_s_l_stat@<eax>(
        wchar_t *wsrc@<ebx>,
        unsigned int sizeInWords,
        localeinfo_struct *plocinfo)
{
  int *v3; // eax
  unsigned int v5; // ecx
  wchar_t *i; // eax
  wchar_t v7; // cx
  int v8; // eax
  int v9; // ecx
  unsigned int v10; // eax
  void *v11; // esp
  wchar_t *v12; // eax
  int v13; // esi
  unsigned int v14; // [esp-4h] [ebp-18h]
  _DWORD v15[2]; // [esp+0h] [ebp-14h] BYREF
  int dstsize; // [esp+8h] [ebp-Ch]
  wchar_t *wdst; // [esp+Ch] [ebp-8h]

  if ( !wsrc )
    goto LABEL_2;
  if ( wcsnlen(wsrc, sizeInWords) >= sizeInWords )
  {
    *wsrc = 0;
LABEL_2:
    v3 = _errno();
    v14 = 22;
LABEL_3:
    *v3 = v14;
    _invalid_parameter((unsigned int)wsrc, v14, 0);
    return v14;
  }
  v5 = plocinfo->locinfo->lc_handle[2];
  if ( v5 )
  {
    v8 = __crtLCMapStringW(plocinfo, v5, 0x200u, wsrc, -1, 0, 0, plocinfo->locinfo->lc_codepage);
    v9 = v8;
    dstsize = v8;
    if ( !v8 )
    {
      *_errno() = 42;
      return *_errno();
    }
    if ( sizeInWords < v8 )
    {
      *wsrc = 0;
      v3 = _errno();
      v14 = 34;
      goto LABEL_3;
    }
    if ( v8 <= 0 || 0xFFFFFFE0 / v8 < 2 )
    {
      wdst = 0;
      goto LABEL_28;
    }
    v10 = 2 * v8 + 8;
    if ( v10 > 0x400 )
    {
      v12 = (wchar_t *)malloc(2 * v9 + 8);
      if ( v12 )
      {
        *(_DWORD *)v12 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v11 = alloca(v10);
      v12 = (wchar_t *)v15;
      if ( v15 )
      {
        v15[0] = 52428;
LABEL_25:
        v12 += 4;
      }
    }
    v9 = dstsize;
    wdst = v12;
LABEL_28:
    if ( wdst )
    {
      if ( __crtLCMapStringW(
             plocinfo,
             plocinfo->locinfo->lc_handle[2],
             0x200u,
             wsrc,
             -1,
             wdst,
             v9,
             plocinfo->locinfo->lc_codepage) )
      {
        v13 = wcscpy_s(wsrc, sizeInWords, wdst);
      }
      else
      {
        *_errno() = 42;
        v13 = 42;
      }
      _freea(wdst);
      return v13;
    }
    *_errno() = 12;
    return *_errno();
  }
  for ( i = wsrc; *i; ++i )
  {
    v7 = *i;
    if ( *i >= 0x61u && v7 <= 0x7Au )
      *i = v7 - 32;
  }
  return 0;
}
