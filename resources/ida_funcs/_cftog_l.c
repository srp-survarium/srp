unsigned int __cdecl _cftog_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  unsigned int result; // eax
  unsigned int v7; // ecx
  BOOL v8; // eax
  char *v9; // edi
  _strflt retstrflt; // [esp+Ch] [ebp-30h] BYREF
  int g_magnitude; // [esp+1Ch] [ebp-20h]
  char resstr[24]; // [esp+20h] [ebp-1Ch] BYREF

  _fltout2(*(_CRT_DOUBLE *)&pvalue->x, &retstrflt, resstr, 0x16u);
  if ( buf && (v7 = sizeInBytes) != 0 )
  {
    g_magnitude = retstrflt.decpt - 1;
    v8 = retstrflt.sign == 45;
    v9 = &buf[v8];
    if ( sizeInBytes != -1 )
      v7 = sizeInBytes - v8;
    result = _fptostr(v9, v7, ndec, &retstrflt);
    if ( result )
    {
      *buf = 0;
    }
    else if ( retstrflt.decpt - 1 < -4 || retstrflt.decpt - 1 >= ndec )
    {
      return cftoe2_l(buf, sizeInBytes, ndec, caps, &retstrflt, 1, plocinfo);
    }
    else
    {
      if ( g_magnitude < retstrflt.decpt - 1 )
        v9[strlen(v9) - 1] = 0;
      return cftof2_l(buf, &retstrflt, sizeInBytes, ndec, 1, plocinfo);
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, 0x16u, (unsigned int)buf);
    return 22;
  }
  return result;
}
