void __usercall stlp_std::__make_heap<vostok::command_line::key * *,vostok::command_line::key_compare_predicate,vostok::command_line::key *,int>(
        vostok::command_line::key **__first@<edi>,
        vostok::command_line::key **__last,
        vostok::command_line::key_compare_predicate *a3)
{
  int v3; // ebx
  int v4; // esi
  vostok::command_line::key *v5; // eax

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  stlp_std::__adjust_heap<vostok::command_line::key * *,int,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
    __first,
    v4,
    v3,
    __first[v4],
    *a3);
  while ( v4 )
  {
    v5 = __first[--v4];
    stlp_std::__adjust_heap<vostok::command_line::key * *,int,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
      __first,
      v4,
      v3,
      v5,
      *a3);
  }
}
