int __fastcall _ilog(unsigned int v)
{
  int result; // eax

  for ( result = 0; v; v >>= 1 )
    ++result;
  return result;
}
