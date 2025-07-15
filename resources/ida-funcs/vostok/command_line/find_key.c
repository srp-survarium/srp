vostok::command_line::key *__cdecl vostok::command_line::find_key(char *key_name)
{
  vostok::fixed_string<512> *v1; // ecx
  vostok::intrusive_list<vostok::command_line::key,vostok::command_line::key *,552,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy> *v2; // ecx
  vostok::buffer_string v4[43]; // [esp+8h] [ebp-21Ch] BYREF
  int v5; // [esp+214h] [ebp-10h]
  vostok::intrusive_list<vostok::command_line::key,vostok::command_line::key *,552,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::command_line::command_line_key_finder> pred; // [esp+21Ch] [ebp-8h] BYREF

  vostok::fixed_string<512>::fixed_string<512>(v1, v4, key_name);
  v5 = 0;
  pred.m_predicate_ref = (vostok::command_line::command_line_key_finder *)v4;
  vostok::intrusive_list<vostok::command_line::key,vostok::command_line::key *,552,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::command_line::key,vostok::command_line::key *,552,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::command_line::command_line_key_finder>>(
    v2,
    (int)s_command_line_keys,
    &pred);
  return (vostok::command_line::key *)v5;
}
