void __usercall stlp_std::__adjust_heap<char const * *,int,char const *,vostok::tips_sorting_predicate>(
        const char **__first@<edi>,
        int __holeIndex,
        int __len,
        const char *__val,
        vostok::tips_sorting_predicate __comp)
{
  int v5; // eax
  int v6; // esi
  bool v7; // zf
  unsigned __int8 *v8; // ebp
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // ecx
  const char *v13; // eax
  unsigned __int8 *v14; // [esp+4h] [ebp-8h]
  int __topIndex; // [esp+8h] [ebp-4h]

  v5 = __holeIndex;
  v6 = 2 * __holeIndex + 2;
  v7 = v6 == __len;
  __topIndex = __holeIndex;
  if ( v6 < __len )
  {
    do
    {
      v8 = (unsigned __int8 *)__first[v6 - 1];
      v14 = (unsigned __int8 *)__first[v6];
      strstr(v14, (unsigned __int8 *)__comp.editor_str);
      v10 = v9;
      strstr(v8, (unsigned __int8 *)__comp.editor_str);
      if ( v10 - (int)v14 < v11 - (int)v8 )
        --v6;
      v12 = __holeIndex;
      v13 = __first[v6];
      __holeIndex = v6;
      v6 = 2 * v6 + 2;
      v7 = v6 == __len;
      __first[v12] = v13;
    }
    while ( v6 < __len );
    v5 = __holeIndex;
  }
  if ( v7 )
  {
    __first[v5] = __first[v6 - 1];
    v5 = v6 - 1;
  }
  stlp_std::__push_heap<char const * *,int,char const *,vostok::tips_sorting_predicate>(
    __first,
    v5,
    __topIndex,
    __val,
    __comp);
}
