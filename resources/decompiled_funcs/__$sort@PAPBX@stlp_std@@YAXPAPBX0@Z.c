void __usercall stlp_std::sort<void const * *>(const void **__first@<edi>, const void **__last)
{
  int v2; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v2 = __last - __first;
    for ( i = 0; v2 != 1; ++i )
      v2 >>= 1;
    stlp_std::priv::__introsort_loop<void const * *,void const *,int,stlp_std::less<void const *>>(
      __first,
      __last,
      0,
      2 * i,
      (stlp_std::less<void const *>)__last);
    if ( __last - __first <= 16 )
    {
      stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        (unsigned int *)__first,
        (unsigned int *)__last);
    }
    else
    {
      stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        (unsigned int *)__first,
        (unsigned int *)__first + 16);
      stlp_std::priv::__unguarded_insertion_sort_aux<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        (unsigned int *)__first + 16,
        (unsigned int *)__last);
    }
  }
}
