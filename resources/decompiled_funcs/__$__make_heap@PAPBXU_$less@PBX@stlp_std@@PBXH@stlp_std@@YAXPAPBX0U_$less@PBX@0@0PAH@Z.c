void __usercall stlp_std::__make_heap<void const * *,stlp_std::less<void const *>,void const *,int>(
        const void **__first@<edi>,
        const void **__last,
        stlp_std::less<void const *> __comp)
{
  int v3; // ebx
  int v4; // esi
  const void *v5; // eax

  v3 = __last - __first;
  if ( v3 >= 2 )
  {
    v4 = (v3 - 2) / 2;
    stlp_std::__adjust_heap<void const * *,int,void const *,stlp_std::less<void const *>>(
      (unsigned int *)__first,
      v4,
      __last - __first,
      (unsigned int)__first[v4],
      (stlp_std::less<unsigned int>)__comp.gap0);
    while ( v4 )
    {
      v5 = __first[--v4];
      stlp_std::__adjust_heap<void const * *,int,void const *,stlp_std::less<void const *>>(
        (unsigned int *)__first,
        v4,
        v3,
        (unsigned int)v5,
        (stlp_std::less<unsigned int>)__comp.gap0);
    }
  }
}
