void __usercall stlp_std::__push_heap<char const * *,int,char const *,bool (__cdecl *)(char const *,char const *)>(
        int __holeIndex@<eax>,
        const char **__first,
        int __topIndex,
        const char *__val,
        bool (__cdecl *__comp)(const char *, const char *))
{
  int v5; // edi
  int v6; // esi
  bool v7; // cc

  v5 = __holeIndex;
  v6 = (__holeIndex - 1) / 2;
  if ( __holeIndex > __topIndex )
  {
    do
    {
      if ( !__comp(__first[v6], __val) )
        break;
      __first[v5] = __first[v6];
      v5 = v6;
      v7 = v6 <= __topIndex;
      v6 = (v6 - 1) / 2;
    }
    while ( !v7 );
  }
  __first[v5] = __val;
}
