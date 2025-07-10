void __usercall stlp_std::sort_heap<void const * *,stlp_std::less<void const *>>(
        const void **__first@<esi>,
        const void **__last@<eax>,
        stlp_std::less<void const *> __comp)
{
  int v3; // eax
  unsigned int v4; // ecx
  int v5; // edi

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(unsigned int *)((char *)__first + v3 - 4);
      *(const void **)((char *)__first + v3 - 4) = *__first;
      v5 = v3 - 4;
      stlp_std::__adjust_heap<void const * *,int,void const *,stlp_std::less<void const *>>(
        (unsigned int *)__first,
        0,
        (v3 - 4) >> 2,
        v4,
        (stlp_std::less<unsigned int>)__comp.gap0);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}
