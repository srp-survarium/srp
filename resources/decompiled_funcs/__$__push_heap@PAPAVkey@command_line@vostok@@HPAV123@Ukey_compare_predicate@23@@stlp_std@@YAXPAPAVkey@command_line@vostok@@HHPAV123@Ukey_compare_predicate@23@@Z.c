void __usercall stlp_std::__push_heap<vostok::command_line::key * *,int,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key *__val@<eax>,
        vostok::command_line::key_compare_predicate *a2@<esi>,
        vostok::command_line::key **__first,
        int __holeIndex,
        int __topIndex)
{
  int v5; // ebp
  int v7; // ebx
  vostok::command_line::key *v8; // esi
  bool v9; // cc
  vostok::command_line::key_compare_predicate *v10; // [esp-4h] [ebp-10h]

  v5 = __holeIndex;
  v7 = (__holeIndex - 1) / 2;
  if ( __holeIndex <= __topIndex )
  {
    __first[__holeIndex] = __val;
  }
  else
  {
    v10 = a2;
    while ( 1 )
    {
      v8 = __first[v7];
      if ( !vostok::command_line::key_compare_predicate::operator()(v8, __val, v10) )
        break;
      __first[v5] = v8;
      v5 = v7;
      v9 = v7 <= __topIndex;
      v7 = (v7 - 1) / 2;
      if ( v9 )
      {
        __first[v5] = __val;
        return;
      }
    }
    __first[v5] = __val;
  }
}
