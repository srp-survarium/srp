double __fastcall rtforatn20(__int16 a1)
{
  double result; // st7

  if ( (_BYTE)a1 )
  {
    result = 3.141592653589793238;
    if ( HIBYTE(a1) )
      result = -3.141592653589793238;
  }
  else
  {
    result = 0.0;
    if ( HIBYTE(a1) )
      return -0.0;
  }
  postv();
  return result;
}
