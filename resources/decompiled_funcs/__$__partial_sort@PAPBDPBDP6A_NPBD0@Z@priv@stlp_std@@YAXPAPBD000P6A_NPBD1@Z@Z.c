void __usercall stlp_std::priv::__partial_sort<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
        const char **__first@<eax>,
        const char **__middle,
        const char **__last,
        const char **__formal)
{
  const char **v4; // esi
  int v6; // ebx
  const char *v7; // [esp-8h] [ebp-18h]

  v4 = __middle;
  v6 = __middle - __first;
  if ( v6 >= 2 )
    stlp_std::__make_heap<char const * *,bool (__cdecl *)(char const *,char const *),char const *,int>(
      __first,
      __middle,
      (bool (__cdecl *)(const char *, const char *))__formal);
  if ( __middle < __last )
  {
    do
    {
      if ( ((unsigned __int8 (__cdecl *)(const char *, _DWORD))__formal)(*v4, *__first) )
      {
        v7 = *v4;
        *v4 = *__first;
        stlp_std::__adjust_heap<char const * *,int,char const *,bool (__cdecl *)(char const *,char const *)>(
          __first,
          0,
          v6,
          v7,
          (bool (__cdecl *)(const char *, const char *))__formal);
      }
      ++v4;
    }
    while ( v4 < __last );
  }
  stlp_std::sort_heap<char const * *,bool (__cdecl *)(char const *,char const *)>(
    __first,
    __middle,
    (bool (__cdecl *)(const char *, const char *))__formal);
}
