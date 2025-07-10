int __fastcall stlp_std::priv::__lg<int>(int __n)
{
  int result; // eax

  for ( result = 0; __n != 1; ++result )
    __n >>= 1;
  return result;
}
