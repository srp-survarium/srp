double __usercall _rtinfnpopse@<st0>(int a1@<ebp>)
{
  double result; // st7

  result = *(double *)&_infinity;
  *(_BYTE *)(a1 - 144) = 2;
  return result;
}
