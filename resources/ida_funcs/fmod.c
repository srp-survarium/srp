double __cdecl fmod(double X, double Y)
{
  double result; // st7

  _ctrandisp2(*(unsigned __int64 *)&X, *(unsigned __int64 *)&Y);
  return result;
}


long double __cdecl fmod(float _X, float _Y)
{
  return fmodf(_X, _Y);
}
