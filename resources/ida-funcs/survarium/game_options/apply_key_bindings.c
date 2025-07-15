void __thiscall survarium::game_options::apply_key_bindings(survarium::game_options *this)
{
  vostok::fixed_string<32> *p_new_binded_key; // edi
  const char *m_begin; // ebx
  vostok::buffer_string *v3; // ecx
  char *v4; // esi
  vostok::console_commands::console_command *v5; // ebx
  const char *v6; // eax
  vostok::strings::detail::tuples *v7; // ecx
  vostok::strings::detail::tuples *v8; // ecx
  const char *v9; // eax
  vostok::strings::detail::tuples *v10; // ecx
  void *v11; // esp
  vostok::strings::detail::tuples *v12; // ecx
  survarium::key_binder *v13; // [esp-4h] [ebp-4Ch]
  survarium::key_binder *v14; // [esp-4h] [ebp-4Ch]
  char v15[12]; // [esp+0h] [ebp-48h] BYREF
  vostok::strings::detail::tuples v16; // [esp+Ch] [ebp-3Ch] BYREF
  int v17; // [esp+40h] [ebp-8h]
  char *v18; // [esp+44h] [ebp-4h]

  p_new_binded_key = &survarium::key_bind_descriptions[0].new_binded_key;
  v17 = 41;
  do
  {
    m_begin = p_new_binded_key->m_begin;
    if ( vostok::strings::compare(p_new_binded_key->m_begin, p_new_binded_key[1].m_begin) )
    {
      vostok::fs_new::path_string_impl::assignf(
        &p_new_binded_key[1].m_begin,
        v3,
        (vostok::buffer_string *)&stru_7F9BE8.allocator,
        m_begin);
      v4 = p_new_binded_key->m_begin;
      if ( vostok::strings::compare(p_new_binded_key->m_begin, uri) )
      {
        v5 = vostok::console_commands::find("bind");
        v9 = survarium::key_binder::id_to_action_name(
               v14,
               *(survarium::game_action_id *)&p_new_binded_key[-1].m_buffer[16]);
        vostok::strings::detail::tuples::tuples(v10, &v16, v9, " ", v4);
      }
      else
      {
        v5 = vostok::console_commands::find("unbind");
        v6 = survarium::key_binder::id_to_action_name(
               v13,
               *(survarium::game_action_id *)&p_new_binded_key[-1].m_buffer[16]);
        vostok::strings::detail::tuples::tuples(v7, &v16, v6);
      }
      v11 = alloca(vostok::strings::detail::tuples::size(v8, (unsigned int *)&v16));
      v18 = v15;
      vostok::strings::detail::tuples::concat(v12, (int)&v16, v15);
      v5->execute(v5, v18);
    }
    p_new_binded_key = (vostok::fixed_string<32> *)((char *)p_new_binded_key + 104);
    --v17;
  }
  while ( v17 );
}
