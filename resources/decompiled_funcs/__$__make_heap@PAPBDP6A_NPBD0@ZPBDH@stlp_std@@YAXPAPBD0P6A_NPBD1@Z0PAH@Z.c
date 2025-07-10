void __usercall stlp_std::__make_heap<char const * *,bool (__cdecl *)(char const *,char const *),char const *,int>(
        const char **__first@<eax>,
        const char **__last,
        bool (__cdecl *__comp)(const char *, const char *))
{
  int v4; // ebx
  int v5; // esi
  const char *v6; // ecx

  v4 = __last - __first;
  v5 = (v4 - 2) / 2;
  stlp_std::__adjust_heap<char const * *,int,char const *,bool (__cdecl *)(char const *,char const *)>(
    __first,
    v5,
    v4,
    __first[v5],
    __comp);
  while ( v5 )
  {
    v6 = __first[--v5];
    stlp_std::__adjust_heap<char const * *,int,char const *,bool (__cdecl *)(char const *,char const *)>(
      __first,
      v5,
      v4,
      v6,
      __comp);
  }
}
