void __cdecl stlp_std::priv::__partial_sort<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key **__first,
        vostok::command_line::key **__middle,
        vostok::command_line::key **__last,
        vostok::command_line::key **__formal)
{
  const vostok::command_line::key **v4; // ebx
  vostok::command_line::key **v5; // esi
  int v6; // ebp
  const vostok::command_line::key *v7; // edi
  vostok::command_line::key *v8; // esi
  vostok::command_line::key_compare_predicate *v9; // [esp+0h] [ebp-14h]

  v4 = (const vostok::command_line::key **)__middle;
  v5 = __first;
  v6 = __middle - __first;
  if ( v6 >= 2 )
    stlp_std::__make_heap<vostok::command_line::key * *,vostok::command_line::key_compare_predicate,vostok::command_line::key *,int>(
      __first,
      __middle);
  if ( __middle < __last )
  {
    do
    {
      v7 = *v5;
      v8 = (vostok::command_line::key *)*v4;
      if ( vostok::command_line::key_compare_predicate::operator()(*v4, v7, v9) )
      {
        *v4 = v7;
        stlp_std::__adjust_heap<vostok::command_line::key * *,int,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
          __first,
          0,
          v6,
          v8,
          (vostok::command_line::key_compare_predicate)__formal);
      }
      v5 = __first;
      ++v4;
    }
    while ( v4 < (const vostok::command_line::key **)__last );
    v4 = (const vostok::command_line::key **)__middle;
  }
  stlp_std::sort_heap<vostok::command_line::key * *,vostok::command_line::key_compare_predicate>(
    v5,
    (vostok::command_line::key **)v4,
    (vostok::command_line::key_compare_predicate)__formal);
}
