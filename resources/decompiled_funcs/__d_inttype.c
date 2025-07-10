int __cdecl _d_inttype(long double y)
{
  if ( (_fpclass(y) & 0x90) != 0 || _frnd(y) != y )
    return 0;
  if ( _frnd(y * 0.5) == y * 0.5 )
    return 2;
  return 1;
}
