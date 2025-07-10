void __usercall stlp_std::__adjust_heap<char const * *,int,char const *,vostok::render::shader_macros_dort_predicate>(
        const char **__first@<edi>,
        int __holeIndex@<eax>,
        int __len,
        const char *__val,
        vostok::render::shader_macros_dort_predicate __comp)
{
  int v6; // esi
  bool v7; // zf
  bool v8; // cc
  int __topIndex; // [esp+Ch] [ebp+4h]

  v6 = 2 * __holeIndex + 2;
  v7 = v6 == __len;
  v8 = v6 < __len;
  __topIndex = __holeIndex;
  if ( v8 )
  {
    do
    {
      if ( strcmp(__first[v6], __first[v6 - 1]) < 0 )
        --v6;
      __first[__holeIndex] = __first[v6];
      __holeIndex = v6;
      v6 = 2 * v6 + 2;
      v7 = v6 == __len;
    }
    while ( v6 < __len );
  }
  if ( v7 )
  {
    __first[__holeIndex] = __first[v6 - 1];
    __holeIndex = v6 - 1;
  }
  stlp_std::__push_heap<char const * *,int,char const *,vostok::render::shader_macros_dort_predicate>(
    __first,
    __holeIndex,
    __topIndex,
    __val,
    __comp);
}
