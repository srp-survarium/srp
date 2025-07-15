int __thiscall ilog2(char *v)
{
  int result; // eax
  unsigned int i; // ecx

  result = 0;
  if ( v )
  {
    for ( i = (unsigned int)(v - 1); i; i >>= 1 )
      ++result;
  }
  return result;
}
