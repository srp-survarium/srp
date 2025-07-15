double __usercall _rtinfnpop@<st0>(int a1@<ebp>)
{
  double result; // st7

  result = *(double *)&_infinity;
  *(_BYTE *)(a1 - 144) = 3;
  return result;
}
