int __cdecl _cftof_l(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v6; // eax
  _strflt retstrflt; // [esp+Ch] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2(*(_CRT_DOUBLE *)&pvalue->x, &retstrflt, resstr, 0x16u);
  if ( buf && (v6 = sizeInBytes) != 0 )
  {
    if ( sizeInBytes != -1 )
      v6 = sizeInBytes - (retstrflt.sign == 45);
    result = _fptostr(&buf[retstrflt.sign == 45], v6, ndec + retstrflt.decpt, &retstrflt);
    if ( result )
      *buf = 0;
    else
      return cftof2_l(buf, &retstrflt, sizeInBytes, ndec, 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, (unsigned int)buf, 0x16u);
    return 22;
  }
  return result;
}
