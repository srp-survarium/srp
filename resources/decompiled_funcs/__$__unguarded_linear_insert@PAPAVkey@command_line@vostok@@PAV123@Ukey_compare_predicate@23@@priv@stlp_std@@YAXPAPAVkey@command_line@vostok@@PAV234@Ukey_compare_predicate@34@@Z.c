void __usercall stlp_std::priv::__unguarded_linear_insert<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key *__val@<eax>,
        vostok::command_line::key **__last)
{
  vostok::command_line::key **v2; // ebp
  const vostok::command_line::key *v3; // edi
  vostok::command_line::key **v4; // ebx
  vostok::command_line::key_compare_predicate *v6; // [esp+0h] [ebp-10h]
  vostok::command_line::key_compare_predicate *v7; // [esp+0h] [ebp-10h]

  v2 = __last;
  v3 = *(__last - 1);
  v4 = __last - 1;
  if ( vostok::command_line::key_compare_predicate::operator()(__val, v3, v6) )
  {
    do
    {
      *v2 = (vostok::command_line::key *)v3;
      v3 = *(v4 - 1);
      v2 = v4--;
    }
    while ( vostok::command_line::key_compare_predicate::operator()(__val, v3, v7) );
  }
  *v2 = __val;
}
