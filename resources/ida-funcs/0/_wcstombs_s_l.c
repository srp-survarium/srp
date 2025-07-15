int __cdecl _wcstombs_s_l(
        unsigned int *pConvertedChars,
        char *dst,
        unsigned int sizeInBytes,
        wchar_t *src,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  unsigned int v6; // eax
  int v7; // eax
  int *v9; // eax
  int v10; // esi
  unsigned int v11; // eax
  int v12; // [esp-4h] [ebp-14h]
  int retvalue; // [esp+Ch] [ebp-4h]

  retvalue = 0;
  if ( dst )
  {
    if ( sizeInBytes )
      goto LABEL_3;
LABEL_15:
    v9 = _errno();
    v12 = 22;
LABEL_16:
    v10 = v12;
    *v9 = v12;
    _invalid_parameter(0, 0, 0, 0, 0);
    return v10;
  }
  if ( sizeInBytes )
    goto LABEL_15;
LABEL_3:
  if ( dst )
    *dst = 0;
  if ( pConvertedChars )
    *pConvertedChars = 0;
  v6 = n;
  if ( n > sizeInBytes )
    v6 = sizeInBytes;
  if ( v6 > 0x7FFFFFFF )
    goto LABEL_15;
  v7 = _wcstombs_l_helper(dst, src, v6, plocinfo);
  if ( v7 == -1 )
  {
    if ( dst )
      *dst = 0;
    return *_errno();
  }
  v11 = v7 + 1;
  if ( dst )
  {
    if ( v11 > sizeInBytes )
    {
      if ( n != -1 )
      {
        *dst = 0;
        if ( sizeInBytes <= v11 )
        {
          v9 = _errno();
          v12 = 34;
          goto LABEL_16;
        }
      }
      v11 = sizeInBytes;
      retvalue = 80;
    }
    dst[v11 - 1] = 0;
  }
  if ( pConvertedChars )
    *pConvertedChars = v11;
  return retvalue;
}
