int __cdecl _ecvt_s(char *result, unsigned int sizeInChars, _CRT_DOUBLE value, int ndigit, int *decpt, int *sign)
{
  int v6; // eax
  _strflt *v7; // eax
  _strflt flt; // [esp+Ch] [ebp-34h] BYREF
  int *v9; // [esp+1Ch] [ebp-24h]
  int v10; // [esp+20h] [ebp-20h]
  char resultstr[24]; // [esp+24h] [ebp-1Ch] BYREF

  v10 = ndigit;
  v9 = sign;
  if ( result && sizeInChars && (*result = 0, decpt) && sign )
  {
    v7 = _fltout2(value, &flt, resultstr, 0x16u);
    v6 = fpcvt(sizeInChars, v7, v10, result, decpt, v9);
    if ( v10 > (int)(sizeInChars - 2) )
      v10 = sizeInChars - 2;
    if ( v10 >= 0 )
    {
      if ( result[v10] )
        result[v10] = 0;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, (int)decpt, 22);
    return 22;
  }
  return v6;
}
