void __usercall stlp_std::__adjust_heap<vostok::command_line::key * *,int,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key_compare_predicate *a1@<edi>,
        vostok::command_line::key **__first,
        int __holeIndex,
        int __len,
        vostok::command_line::key *__val,
        vostok::command_line::key_compare_predicate __comp)
{
  int v6; // ebp
  int v7; // ebx
  bool v8; // zf
  vostok::command_line::key_compare_predicate *v9; // [esp-8h] [ebp-10h]

  v6 = __holeIndex;
  v7 = 2 * __holeIndex + 2;
  v8 = v7 == __len;
  if ( v7 < __len )
  {
    v9 = a1;
    do
    {
      if ( vostok::command_line::key_compare_predicate::operator()(__first[v7], __first[v7 - 1], v9) )
        --v7;
      __first[v6] = __first[v7];
      v6 = v7;
      v7 = 2 * v7 + 2;
      v8 = v7 == __len;
    }
    while ( v7 < __len );
  }
  if ( v8 )
  {
    __first[v6] = __first[v7 - 1];
    v6 = v7 - 1;
  }
  stlp_std::__push_heap<vostok::command_line::key * *,int,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
    __first,
    v6,
    __holeIndex,
    __val,
    __comp);
}
