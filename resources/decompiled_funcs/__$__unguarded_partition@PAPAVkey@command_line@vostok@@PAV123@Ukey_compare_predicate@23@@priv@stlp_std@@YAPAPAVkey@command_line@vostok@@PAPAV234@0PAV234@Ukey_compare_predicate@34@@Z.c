vostok::command_line::key **__cdecl stlp_std::priv::__unguarded_partition<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key **__first,
        vostok::command_line::key **__last,
        vostok::command_line::key *__pivot)
{
  const vostok::command_line::key *v5; // esi
  const vostok::command_line::key *v6; // edi
  const vostok::command_line::key *v7; // edi
  vostok::command_line::key *v8; // eax
  vostok::command_line::key_compare_predicate *v10; // [esp+0h] [ebp-10h]
  vostok::command_line::key_compare_predicate *v11; // [esp+0h] [ebp-10h]

  while ( 1 )
  {
    if ( vostok::command_line::key_compare_predicate::operator()(*__first, __pivot, v10) )
    {
      do
      {
        v5 = __first[1];
        ++__first;
      }
      while ( vostok::command_line::key_compare_predicate::operator()(v5, __pivot, v11) );
    }
    v6 = *--__last;
    if ( vostok::command_line::key_compare_predicate::operator()(__pivot, v6, v11) )
    {
      do
        v7 = *--__last;
      while ( vostok::command_line::key_compare_predicate::operator()(__pivot, v7, v10) );
    }
    if ( __first >= __last )
      break;
    v8 = *__first;
    *__first = *__last;
    *__last = v8;
    ++__first;
  }
  return __first;
}
