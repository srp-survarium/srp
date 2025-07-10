float *__cdecl stlp_std::priv::__uninitialized_fill_n<float *,unsigned int,float>(
        float *__first,
        unsigned int __n,
        const float *__x)
{
  int i; // [esp+4h] [ebp-10h]
  float *v5; // [esp+8h] [ebp-Ch]

  v5 = __first;
  for ( i = (int)(4 * __n) >> 2; i > 0; --i )
    *v5++ = *__x;
  return &__first[__n];
}
