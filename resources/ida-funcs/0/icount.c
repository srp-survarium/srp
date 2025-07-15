int __fastcall icount(unsigned int v)
{
  int result; // eax

  for ( result = 0; v; v >>= 1 )
    result += v & 1;
  return result;
}
