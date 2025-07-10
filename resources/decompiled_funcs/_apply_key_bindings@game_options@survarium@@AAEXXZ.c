void __thiscall survarium::game_options::apply_key_bindings(survarium::game_options *this)
{
  vostok::fixed_string<32> *p_new_binded_key; // esi
  vostok::console_commands::console_command *v2; // ebx
  const char *v3; // eax
  vostok::strings::detail::tuples *v4; // ecx
  void *v5; // esp
  vostok::strings::detail::tuples *v6; // ecx
  vostok::strings::detail::tuples *p_STR_JOINA_tuples_unique_identifier; // ecx
  const char *v8; // edi
  vostok::strings::detail::tuples *v9; // ecx
  void *v10; // esp
  vostok::strings::detail::tuples *v11; // ecx
  bool v12; // zf
  const char *v13; // [esp-8h] [ebp-84h]
  char *m_begin; // [esp-4h] [ebp-80h]
  survarium::key_binder *v15[3]; // [esp+0h] [ebp-7Ch] BYREF
  vostok::strings::detail::tuples v16; // [esp+Ch] [ebp-70h] BYREF
  vostok::strings::detail::tuples STR_JOINA_tuples_unique_identifier; // [esp+40h] [ebp-3Ch] BYREF
  int v18; // [esp+74h] [ebp-8h]
  vostok::fixed_string<32> *v19; // [esp+78h] [ebp-4h]

  p_new_binded_key = &survarium::key_bind_descriptions[0].new_binded_key;
  v19 = &survarium::key_bind_descriptions[0].new_binded_key;
  v18 = 33;
  do
  {
    if ( strcmp(p_new_binded_key->m_begin, p_new_binded_key[1].m_begin) )
    {
      vostok::buffer_string::assignf(p_new_binded_key + 1, "%s", p_new_binded_key->m_begin);
      if ( !strcmp(p_new_binded_key->m_begin, (const char *)&buf) )
      {
        v2 = vostok::console_commands::find("unbind");
        v3 = survarium::key_binder::id_to_action_name(*(survarium::game_action_id *)&v19[-1].m_buffer[16], v15[0]);
        memset(&STR_JOINA_tuples_unique_identifier.m_strings[1], 0, 40);
        STR_JOINA_tuples_unique_identifier.m_count = 1;
        if ( v3 )
          v4 = (vostok::strings::detail::tuples *)strlen(v3);
        else
          v4 = 0;
        STR_JOINA_tuples_unique_identifier.m_strings[0].first = v3;
        STR_JOINA_tuples_unique_identifier.m_strings[0].second = (unsigned int)v4;
        v5 = alloca(vostok::strings::detail::tuples::size(v4, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
        vostok::strings::detail::tuples::size(v6, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
        p_STR_JOINA_tuples_unique_identifier = &STR_JOINA_tuples_unique_identifier;
      }
      else
      {
        v2 = vostok::console_commands::find("bind");
        m_begin = v19->m_begin;
        v8 = survarium::key_binder::id_to_action_name(
               *(survarium::game_action_id *)&v19[-1].m_buffer[16],
               (survarium::key_binder *)&stru_95AF78);
        vostok::strings::detail::tuples::tuples(&v16, v8, v13, m_begin);
        v10 = alloca(vostok::strings::detail::tuples::size(v9, (unsigned int *)&v16));
        vostok::strings::detail::tuples::size(v11, (unsigned int *)&v16);
        p_STR_JOINA_tuples_unique_identifier = &v16;
      }
      vostok::strings::detail::tuples::concat((char *)v15, p_STR_JOINA_tuples_unique_identifier);
      v2->execute(v2, (const char *)v15);
      p_new_binded_key = v19;
    }
    p_new_binded_key = (vostok::fixed_string<32> *)((char *)p_new_binded_key + 104);
    v12 = v18-- == 1;
    v19 = p_new_binded_key;
  }
  while ( !v12 );
}
