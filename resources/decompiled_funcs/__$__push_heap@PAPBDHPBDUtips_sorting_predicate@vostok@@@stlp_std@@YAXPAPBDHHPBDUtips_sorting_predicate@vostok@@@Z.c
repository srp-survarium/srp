void __usercall stlp_std::__push_heap<char const * *,int,char const *,vostok::tips_sorting_predicate>(
        int __holeIndex@<eax>,
        const char **__first,
        int __topIndex,
        char *__val,
        vostok::tips_sorting_predicate __comp)
{
  int v6; // edi
  int v7; // esi
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  bool v11; // cc
  unsigned __int8 *__firsta; // [esp+10h] [ebp+4h]

  v6 = __holeIndex;
  v7 = (__holeIndex - 1) / 2;
  if ( __holeIndex <= __topIndex )
  {
    __first[__holeIndex] = __val;
  }
  else
  {
    do
    {
      __firsta = (unsigned __int8 *)__first[v7];
      strstr(__firsta, (unsigned __int8 *)__comp.editor_str);
      v9 = v8;
      strstr((unsigned __int8 *)__val, (unsigned __int8 *)__comp.editor_str);
      if ( v9 - (int)__firsta >= v10 - (int)__val )
        break;
      __first[v6] = __first[v7];
      v6 = v7;
      v11 = v7 <= __topIndex;
      v7 = (v7 - 1) / 2;
    }
    while ( !v11 );
    __first[v6] = __val;
  }
}
