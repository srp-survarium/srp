void __usercall stlp_std::priv::__partial_sort<void const * *,void const *,stlp_std::less<void const *>>(
        const void **__first@<eax>,
        const void **__middle,
        const void **__last,
        const void **__formal)
{
  unsigned int *v5; // ebx
  unsigned int v6; // eax
  const void **v7; // [esp+0h] [ebp-10h]
  int *v8; // [esp+4h] [ebp-Ch]

  stlp_std::__make_heap<void const * *,stlp_std::less<void const *>,void const *,int>(
    __first,
    __middle,
    (stlp_std::less<void const *>)__formal,
    v7,
    v8);
  v5 = (unsigned int *)__middle;
  if ( __middle < __last )
  {
    do
    {
      v6 = *v5;
      if ( *v5 < (unsigned int)*__first )
      {
        *v5 = (unsigned int)*__first;
        stlp_std::__adjust_heap<void const * *,int,void const *,stlp_std::less<void const *>>(
          (unsigned int *)__first,
          0,
          __middle - __first,
          v6,
          (stlp_std::less<unsigned int>)__formal);
      }
      ++v5;
    }
    while ( v5 < (unsigned int *)__last );
  }
  stlp_std::sort_heap<void const * *,stlp_std::less<void const *>>(
    __first,
    __middle,
    (stlp_std::less<void const *>)__formal);
}
