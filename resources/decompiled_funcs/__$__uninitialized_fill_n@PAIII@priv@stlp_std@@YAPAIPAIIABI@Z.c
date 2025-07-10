unsigned int *__usercall stlp_std::priv::__uninitialized_fill_n<unsigned int *,unsigned int,unsigned int>@<eax>(
        unsigned int *__first@<edx>,
        unsigned int __n@<eax>,
        unsigned int *__x@<esi>)
{
  unsigned int *result; // eax
  int i; // ecx

  result = &__first[__n];
  for ( i = result - __first; i > 0; ++__first )
  {
    *__first = *__x;
    --i;
  }
  return result;
}
