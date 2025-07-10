double __fastcall rtforexpinf(char a1)
{
  double result; // st7

  if ( !a1 )
    return *(double *)&_infinity;
  _rtzeronpop();
  return result;
}
