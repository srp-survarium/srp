void __usercall stlp_std::priv::__final_insertion_sort<char const * *,bool (__cdecl *)(char const *,char const *)>(
        const char **__first@<eax>,
        bool (__cdecl *a2)(const char *, const char *)@<ebx>,
        const char **__last)
{
  const char **j; // esi
  const char **k; // esi
  const char **i; // esi
  bool (__cdecl *v7)(const char *, const char *); // [esp-4h] [ebp-10h]
  bool (__cdecl *v8)(const char *, const char *); // [esp+0h] [ebp-Ch]

  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    if ( __first != __last )
    {
      for ( i = __first + 1; i != __last; ++i )
        stlp_std::priv::__linear_insert<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
          __first,
          i,
          *i,
          v8);
    }
  }
  else
  {
    v7 = a2;
    for ( j = __first + 1; j != __first + 16; ++j )
      stlp_std::priv::__linear_insert<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
        __first,
        j,
        *j,
        v7);
    for ( k = __first + 16; k != __last; ++k )
      stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
        k,
        *k,
        v8);
  }
}
