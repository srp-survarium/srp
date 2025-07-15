int __cdecl _ecvt_s(char *result, unsigned int sizeInChars, _CRT_DOUBLE value, int ndigit, int *decpt, int *sign)
{
  int v6; // eax
  _strflt *v7; // eax
  _strflt strfltstruct; // [esp+Ch] [ebp-34h] BYREF
  int *v9; // [esp+1Ch] [ebp-24h]
  int digits; // [esp+20h] [ebp-20h]
  char resultstring[24]; // [esp+24h] [ebp-1Ch] BYREF

  digits = ndigit;
  v9 = sign;
  if ( result && sizeInChars && (*result = 0, decpt) && sign )
  {
    v7 = _fltout2(value, &strfltstruct, resultstring, 0x16u);
    v6 = fpcvt(sizeInChars, v7, digits, result, decpt, v9);
    if ( digits > (int)(sizeInChars - 2) )
      digits = sizeInChars - 2;
    if ( digits >= 0 )
    {
      if ( result[digits] )
        result[digits] = 0;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, (unsigned int)decpt, 0x16u);
    return 22;
  }
  return v6;
}
