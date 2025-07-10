void __usercall stlp_std::__push_heap<char const * *,int,char const *,vostok::render::shader_macros_dort_predicate>(
        int __holeIndex@<eax>,
        const char **__first,
        int __topIndex,
        const char *__val)
{
  int v4; // esi
  int v5; // eax

  v4 = __holeIndex;
  v5 = (__holeIndex - 1) / 2;
  if ( v4 <= __topIndex )
  {
    __first[v4] = __val;
  }
  else
  {
    while ( strcmp(__first[v5], __val) < 0 )
    {
      __first[v4] = __first[v5];
      v4 = v5;
      v5 = (v5 - 1) / 2;
      if ( v4 <= __topIndex )
      {
        __first[v4] = __val;
        return;
      }
    }
    __first[v4] = __val;
  }
}
