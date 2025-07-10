void __usercall stlp_std::priv::__introsort_loop<void const * *,void const *,int,stlp_std::less<void const *>>(
        stlp_std::less<void const *> a1@<sil>,
        const void **__first,
        const void **__last,
        const void **__formal,
        int __depth_limit,
        const void **__comp)
{
  const void **v6; // ebx
  const void *v8; // ecx
  int v9; // kr00_4
  const void *v10; // edx
  const void **v11; // eax
  unsigned int v12; // ebp
  unsigned int *v13; // esi
  int __depth_limita; // [esp+18h] [ebp+10h]

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    do
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<void const * *,void const *,stlp_std::less<void const *>>(
          __first,
          v6,
          v6,
          __comp,
          a1);
        return;
      }
      v8 = *__first;
      v9 = v6 - __first;
      v10 = __first[v9 / 2];
      v11 = &__first[v9 / 2];
      __depth_limita = __depth_limit - 1;
      v12 = (unsigned int)*(v6 - 1);
      if ( *__first >= v10 )
      {
        if ( (unsigned int)v8 < v12 )
          goto LABEL_8;
        if ( (unsigned int)v10 < v12 )
LABEL_10:
          v11 = v6 - 1;
      }
      else if ( (unsigned int)v10 >= v12 )
      {
        if ( (unsigned int)v8 < v12 )
          goto LABEL_10;
LABEL_8:
        v11 = __first;
      }
      __depth_limit = __depth_limita;
      v13 = stlp_std::priv::__unguarded_partition<void const * *,void const *,stlp_std::less<void const *>>(
              (unsigned int *)v6,
              (unsigned int)*v11,
              (unsigned int *)__first);
      stlp_std::priv::__introsort_loop<void const * *,void const *,int,stlp_std::less<void const *>>(
        (const void **)v13,
        v6,
        0,
        __depth_limita,
        (stlp_std::less<void const *>)__comp);
      v6 = (const void **)v13;
    }
    while ( (int)(((char *)v13 - (char *)__first) & 0xFFFFFFFC) > 64 );
  }
}
