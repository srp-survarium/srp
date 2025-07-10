void __usercall stlp_std::__adjust_heap<char const * *,int,char const *,bool (__cdecl *)(char const *,char const *)>(
        const char **__first@<edi>,
        int __holeIndex,
        int __len,
        const char *__val,
        bool (__cdecl *__comp)(const char *, const char *))
{
  int v5; // ebx
  int v6; // esi
  bool i; // zf

  v5 = __holeIndex;
  v6 = 2 * __holeIndex + 2;
  for ( i = v6 == __len; v6 < __len; i = v6 == __len )
  {
    if ( __comp(__first[v6], __first[v6 - 1]) )
      --v6;
    __first[v5] = __first[v6];
    v5 = v6;
    v6 = 2 * v6 + 2;
  }
  if ( i )
  {
    __first[v5] = __first[v6 - 1];
    v5 = v6 - 1;
  }
  stlp_std::__push_heap<char const * *,int,char const *,bool (__cdecl *)(char const *,char const *)>(
    __first,
    v5,
    __holeIndex,
    __val,
    __comp);
}
