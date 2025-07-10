unsigned int __cdecl _cftoe_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  unsigned int result; // eax
  unsigned int v7; // eax
  _strflt retstrflt; // [esp+Ch] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2(*(_CRT_DOUBLE *)&pvalue->x, &retstrflt, resstr, 0x16u);
  if ( buf && sizeInBytes )
  {
    if ( sizeInBytes == -1 )
      v7 = -1;
    else
      v7 = sizeInBytes - (retstrflt.sign == 45) - (ndec > 0);
    result = _fptostr(&buf[(retstrflt.sign == 45) + (ndec > 0)], v7, ndec + 1, &retstrflt);
    if ( result )
      *buf = 0;
    else
      return cftoe2_l(buf, sizeInBytes, ndec, caps, &retstrflt, 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, (unsigned int)buf, 0x16u);
    return 22;
  }
  return result;
}
