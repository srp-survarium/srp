void __usercall stlp_std::priv::__insertion_sort<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key_compare_predicate *a1@<edi>,
        vostok::command_line::key **__first,
        vostok::command_line::key **__last,
        vostok::command_line::key **a4)
{
  const vostok::command_line::key *const *v4; // eax
  vostok::command_line::key **v5; // ebx
  signed int v6; // ebp
  vostok::command_line::key *v7; // esi
  vostok::command_line::key_compare_predicate *v8; // [esp-Ch] [ebp-14h]
  vostok::command_line::key_compare_predicate __comp; // [esp+4h] [ebp-4h]

  v4 = (const vostok::command_line::key *const *)__first;
  v5 = __first + 1;
  if ( __first + 1 != __last )
  {
    v8 = a1;
    v6 = 4;
    while ( 1 )
    {
      v7 = *v5;
      __comp = *(vostok::command_line::key_compare_predicate *)a4;
      if ( vostok::command_line::key_compare_predicate::operator()(*v5, *v4, v8) )
      {
        if ( v6 > 0 )
          memmove((unsigned __int8 *)&v5[v6 / 0xFFFFFFFC + 1], (unsigned __int8 *)__first, v6);
        *__first = v7;
      }
      else
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
          v5,
          v7,
          __comp);
      }
      ++v5;
      v6 += 4;
      if ( v5 == __last )
        break;
      v4 = (const vostok::command_line::key *const *)__first;
    }
  }
}
