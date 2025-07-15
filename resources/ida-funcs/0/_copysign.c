double __cdecl _copysign(long double x, long double y)
{
  double v3; // [esp+0h] [ebp-8h]

  LODWORD(v3) = LODWORD(x);
  HIDWORD(v3) = HIDWORD(y) ^ (HIDWORD(x) ^ HIDWORD(y)) & 0x7FFFFFFF;
  return v3;
}
