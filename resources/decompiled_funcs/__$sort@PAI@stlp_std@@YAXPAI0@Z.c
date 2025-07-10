void __usercall stlp_std::sort<unsigned int *>(
        unsigned int *__first@<edi>,
        stlp_std::less<unsigned int> a2@<sil>,
        unsigned int *__last)
{
  int v3; // eax
  int i; // ecx
  stlp_std::less<unsigned int> v5; // [esp-10h] [ebp-14h]

  if ( __first != __last )
  {
    v3 = __last - __first;
    for ( i = 0; v3 != 1; ++i )
      v3 >>= 1;
    stlp_std::priv::__introsort_loop<unsigned int *,unsigned int,int,stlp_std::less<unsigned int>>(
      __first,
      __last,
      0,
      2 * i,
      (stlp_std::less<unsigned int>)__last);
    if ( __last - __first <= 16 )
    {
      stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        __first,
        __last,
        __last,
        a2);
    }
    else
    {
      stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        __first,
        __first + 16,
        __last,
        a2);
      stlp_std::priv::__unguarded_insertion_sort_aux<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        __first + 16,
        __last,
        __last,
        v5);
    }
  }
}
