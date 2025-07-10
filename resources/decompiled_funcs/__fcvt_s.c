int __cdecl _fcvt_s(char *result, unsigned int sizeInChars, _CRT_DOUBLE value, int ndec, int *decpt, int *sign)
{
  _strflt *v7; // eax
  int v8; // edx
  int v9; // ecx
  _strflt strfltstruct; // [esp+Ch] [ebp-34h] BYREF
  int *v11; // [esp+1Ch] [ebp-24h]
  int *v12; // [esp+20h] [ebp-20h]
  char resultstring[24]; // [esp+24h] [ebp-1Ch] BYREF

  v12 = decpt;
  v11 = sign;
  if ( result && sizeInChars && (*result = 0, decpt) && sign )
  {
    v7 = _fltout2(value, &strfltstruct, resultstring, 0x16u);
    v8 = v7->decpt;
    v9 = v8 + ndec;
    if ( ndec > 0 && v8 > 0 && v9 < ndec )
      v9 = 0x7FFFFFFF;
    return fpcvt(sizeInChars, v7, v9, result, v12, v11);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, (unsigned int)result, 0x16u);
    return 22;
  }
}
