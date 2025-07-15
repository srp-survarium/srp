int __cdecl _cftoe_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v7; // eax
  _strflt flt; // [esp+Ch] [ebp-2Ch] BYREF
  char resultstr[24]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2(*(_CRT_DOUBLE *)&pvalue->x, &flt, resultstr, 0x16u);
  if ( buf && sizeInBytes )
  {
    if ( sizeInBytes == -1 )
      v7 = -1;
    else
      v7 = sizeInBytes - (flt.sign == 45) - (ndec > 0);
    result = _fptostr(&buf[(flt.sign == 45) + (ndec > 0)], v7, ndec + 1, &flt);
    if ( result )
      *buf = 0;
    else
      return cftoe2_l(buf, sizeInBytes, ndec, caps, &flt, 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, (int)buf, 22);
    return 22;
  }
  return result;
}
