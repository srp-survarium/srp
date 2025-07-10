void __usercall stlp_std::priv::__partial_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        unsigned int *__first@<eax>,
        unsigned int *__middle,
        unsigned int *__last,
        unsigned int *__formal)
{
  unsigned int *i; // edi
  unsigned int v6; // eax
  unsigned int *v7; // [esp+0h] [ebp-10h]
  int *v8; // [esp+4h] [ebp-Ch]

  stlp_std::__make_heap<unsigned int *,stlp_std::less<unsigned int>,unsigned int,int>(
    __first,
    __middle,
    (stlp_std::less<unsigned int>)__formal,
    v7,
    v8);
  for ( i = __middle; i < __last; ++i )
  {
    v6 = *i;
    if ( *i < *__first )
    {
      *i = *__first;
      stlp_std::__adjust_heap<void const * *,int,void const *,stlp_std::less<void const *>>(
        __first,
        0,
        __middle - __first,
        v6,
        (stlp_std::less<unsigned int>)__formal);
    }
  }
  stlp_std::sort_heap<unsigned int *,stlp_std::less<unsigned int>>(
    __first,
    __middle,
    (stlp_std::less<unsigned int>)__formal);
}
