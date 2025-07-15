int __usercall fpcvt@<eax>(
        unsigned int sizeInChars@<edx>,
        _strflt *pflt@<edi>,
        int digits@<ecx>,
        char *result,
        int *decpt,
        int *sign)
{
  int v6; // eax
  int v7; // esi
  int v9; // eax

  if ( digits <= 0 )
    v6 = 0;
  else
    v6 = digits;
  if ( sizeInChars < v6 + 2 )
  {
    v7 = 34;
    *_errno() = 34;
    _invalid_parameter(0, (int)pflt, 34);
    return v7;
  }
  v9 = sizeInChars - 2;
  if ( digits <= (int)(sizeInChars - 2) )
    v9 = digits;
  v7 = _fptostr(result, sizeInChars, v9, pflt);
  if ( v7 )
  {
    *_errno() = v7;
    return v7;
  }
  *sign = pflt->sign == 45;
  *decpt = pflt->decpt;
  return 0;
}
