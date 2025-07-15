int __fastcall ilog_1(unsigned int v)
{
  int result; // eax

  for ( result = 0; v; v >>= 1 )
    ++result;
  return result;
}
