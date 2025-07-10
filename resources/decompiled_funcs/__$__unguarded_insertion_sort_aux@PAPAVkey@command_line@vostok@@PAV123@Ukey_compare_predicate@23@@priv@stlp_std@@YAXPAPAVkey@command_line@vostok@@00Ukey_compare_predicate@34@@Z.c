void __usercall stlp_std::priv::__unguarded_insertion_sort_aux<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key_compare_predicate *a1@<edi>,
        vostok::command_line::key **__first,
        vostok::command_line::key **__last)
{
  const vostok::command_line::key **v3; // ebx
  const vostok::command_line::key *v4; // esi
  const vostok::command_line::key *v5; // edi
  const vostok::command_line::key **v6; // ebp
  const vostok::command_line::key **i; // ebx
  vostok::command_line::key_compare_predicate *v8; // [esp-Ch] [ebp-10h]

  v3 = (const vostok::command_line::key **)__first;
  if ( __first != __last )
  {
    v8 = a1;
    while ( 1 )
    {
      v4 = *v3;
      v5 = *(v3 - 1);
      v6 = v3;
      for ( i = v3 - 1; vostok::command_line::key_compare_predicate::operator()(v4, v5, v8); --i )
      {
        *v6 = v5;
        v5 = *(i - 1);
        v6 = i;
      }
      *v6 = v4;
      if ( ++__first == __last )
        break;
      v3 = (const vostok::command_line::key **)__first;
    }
  }
}
