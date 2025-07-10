void __usercall stlp_std::priv::__introsort_loop<unsigned int *,unsigned int,int,stlp_std::less<unsigned int>>(
        stlp_std::less<unsigned int> a1@<sil>,
        unsigned int *__first,
        unsigned int *__last,
        unsigned int *__formal,
        int __depth_limit,
        unsigned int *__comp)
{
  unsigned int *v6; // ebx
  unsigned int v8; // ecx
  int v9; // kr00_4
  unsigned int v10; // edx
  unsigned int *v11; // eax
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
        stlp_std::priv::__partial_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
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
      v12 = *(v6 - 1);
      if ( *__first >= v10 )
      {
        if ( v8 < v12 )
          goto LABEL_8;
        if ( v10 < v12 )
LABEL_10:
          v11 = v6 - 1;
      }
      else if ( v10 >= v12 )
      {
        if ( v8 < v12 )
          goto LABEL_10;
LABEL_8:
        v11 = __first;
      }
      __depth_limit = __depth_limita;
      v13 = stlp_std::priv::__unguarded_partition<void const * *,void const *,stlp_std::less<void const *>>(
              __first,
              v6,
              *v11,
              (stlp_std::less<unsigned int>)__comp);
      stlp_std::priv::__introsort_loop<unsigned int *,unsigned int,int,stlp_std::less<unsigned int>>(
        v13,
        v6,
        0,
        __depth_limita,
        (stlp_std::less<unsigned int>)__comp);
      v6 = v13;
    }
    while ( (int)(((char *)v13 - (char *)__first) & 0xFFFFFFFC) > 64 );
  }
}
