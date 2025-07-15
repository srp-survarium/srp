int __cdecl _cftof_l(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v6; // eax
  _strflt flt; // [esp+Ch] [ebp-2Ch] BYREF
  char resultstr[24]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2(*(_CRT_DOUBLE *)&pvalue->x, &flt, resultstr, 0x16u);
  if ( buf && (v6 = sizeInBytes) != 0 )
  {
    if ( sizeInBytes != -1 )
      v6 = sizeInBytes - (flt.sign == 45);
    result = _fptostr(&buf[flt.sign == 45], v6, ndec + flt.decpt, &flt);
    if ( result )
      *buf = 0;
    else
      return cftof2_l(buf, &flt, sizeInBytes, ndec, 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, (int)buf, 22);
    return 22;
  }
  return result;
}
