int __cdecl comp(float *a, float *b)
{
  if ( *b >= (double)*a )
    return *b > (double)*a;
  else
    return (*b > (double)*a) - 1;
}
