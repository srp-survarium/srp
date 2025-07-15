int __cdecl _wcstombs_s_l(
        unsigned int *pConvertedChars,
        char *dst,
        unsigned int sizeInBytes,
        wchar_t *src,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  unsigned int v6; // eax
  unsigned int v7; // eax
  int *v9; // eax
  unsigned int v10; // eax
  int v11; // [esp-4h] [ebp-14h]
  int v12; // [esp+Ch] [ebp-4h]

  v12 = 0;
  if ( dst )
  {
    if ( sizeInBytes )
      goto LABEL_3;
LABEL_15:
    v9 = _errno();
    v11 = 22;
LABEL_16:
    *v9 = v11;
    _invalid_parameter(0, sizeInBytes, v11);
    return v11;
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
  v10 = v7 + 1;
  if ( dst )
  {
    if ( v10 > sizeInBytes )
    {
      if ( n != -1 )
      {
        *dst = 0;
        if ( sizeInBytes <= v10 )
        {
          v9 = _errno();
          v11 = 34;
          goto LABEL_16;
        }
      }
      v10 = sizeInBytes;
      v12 = 80;
    }
    dst[v10 - 1] = 0;
  }
  if ( pConvertedChars )
    *pConvertedChars = v10;
  return v12;
}
