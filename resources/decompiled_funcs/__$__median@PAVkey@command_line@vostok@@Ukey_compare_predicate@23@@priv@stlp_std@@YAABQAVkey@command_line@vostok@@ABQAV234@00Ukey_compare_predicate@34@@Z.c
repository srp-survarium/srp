const vostok::command_line::key *const *__cdecl stlp_std::priv::__median<vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        const vostok::command_line::key *const *__a,
        const vostok::command_line::key *const *__b,
        const vostok::command_line::key *const *__c)
{
  const vostok::command_line::key *v3; // ebx
  const vostok::command_line::key *v4; // ebp
  const vostok::command_line::key *v5; // esi
  const vostok::command_line::key *v6; // edi
  const vostok::command_line::key *const *result; // eax
  const vostok::command_line::key *v8; // edi
  bool v9; // zf
  vostok::command_line::key_compare_predicate *v10; // [esp+0h] [ebp-10h]
  vostok::command_line::key_compare_predicate *v11; // [esp+0h] [ebp-10h]
  vostok::command_line::key_compare_predicate *v12; // [esp+0h] [ebp-10h]
  vostok::command_line::key_compare_predicate *v13; // [esp+0h] [ebp-10h]

  v3 = *__b;
  v4 = *__a;
  v5 = *__a;
  if ( vostok::command_line::key_compare_predicate::operator()(*__a, *__b, v10) )
  {
    v6 = *__c;
    if ( !vostok::command_line::key_compare_predicate::operator()(v3, *__c, v11) )
    {
      if ( vostok::command_line::key_compare_predicate::operator()(v4, v6, v12) )
        return __c;
      return __a;
    }
    return __b;
  }
  v8 = *__c;
  if ( vostok::command_line::key_compare_predicate::operator()(v5, *__c, v11) )
    return __a;
  v9 = !vostok::command_line::key_compare_predicate::operator()(v3, v8, v13);
  result = __c;
  if ( v9 )
    return __b;
  return result;
}
