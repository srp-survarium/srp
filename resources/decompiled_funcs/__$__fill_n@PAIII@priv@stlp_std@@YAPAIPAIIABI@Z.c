unsigned int *__fastcall stlp_std::priv::__fill_n<unsigned int *,unsigned int,unsigned int>(
        unsigned int __n,
        unsigned int *__val,
        unsigned int *__first)
{
  unsigned int *result; // eax

  for ( result = __first; __n; ++result )
  {
    *result = *__val;
    --__n;
  }
  return result;
}
