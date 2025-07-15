long double __usercall Scaleform::SFstrtod@<st0>(int a1@<edi>, char *string, char **tailptr)
{
  char v3; // bl
  char *v4; // eax
  char _Dst[348]; // [esp+4h] [ebp-15Ch] BYREF

  v3 = *localeconv()->decimal_point;
  if ( v3 == 46 )
    return strtod(string, tailptr);
  strcpy_s(a1, _Dst, 348, string);
  v4 = _Dst;
  if ( _Dst[0] )
  {
    while ( *v4 != 46 )
    {
      if ( !*++v4 )
        return strtod(_Dst, tailptr);
    }
    *v4 = v3;
  }
  return strtod(_Dst, tailptr);
}
