void __usercall stlp_std::priv::__introsort_loop<char const * *,char const *,int,bool (__cdecl *)(char const *,char const *)>(
        bool (__cdecl *a1)(const char *, const char *)@<edi>,
        const char **__first,
        const char **__last,
        const char **__formal,
        int __depth_limit,
        bool (__cdecl *__comp)(const char *, const char *))
{
  const char **v6; // ebx
  const char **v7; // eax
  const char **v8; // edi

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v7 = (const char **)stlp_std::priv::__median<char const *,bool (__cdecl *)(char const *,char const *)>(
                            __first,
                            &__first[(v6 - __first) / 2],
                            v6 - 1,
                            __comp);
      v8 = stlp_std::priv::__unguarded_partition<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
             __first,
             v6,
             *v7,
             __comp);
      stlp_std::priv::__introsort_loop<char const * *,char const *,int,bool (__cdecl *)(char const *,char const *)>(
        v8,
        v6,
        0,
        __depth_limit,
        __comp);
      v6 = v8;
      if ( (int)(((char *)v8 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    stlp_std::priv::__partial_sort<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
      __first,
      v6,
      v6,
      (const char **)__comp,
      a1);
  }
}
