double __cdecl _copysign(long double x, long double y)
{
  double retval; // [esp+0h] [ebp-8h]

  LODWORD(retval) = LODWORD(x);
  HIDWORD(retval) = HIDWORD(y) ^ (HIDWORD(x) ^ HIDWORD(y)) & 0x7FFFFFFF;
  return retval;
}
