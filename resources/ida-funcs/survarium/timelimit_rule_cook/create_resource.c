survarium::timelimit_rule_core *__thiscall survarium::timelimit_rule_cook::create_resource(
        survarium::timelimit_rule_cook *this,
        const survarium::timelimit_rule_query_data *data,
        unsigned int *out_resource_size)
{
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  survarium::game_match_rule_base *v8; // ecx
  char *v9; // esi
  survarium::game *m_game; // ebx
  const char *v12; // [esp+0h] [ebp-Ch]
  const char *v13; // [esp+4h] [ebp-8h]
  unsigned int v14; // [esp+8h] [ebp-4h]

  v3 = survarium::g_allocator;
  *out_resource_size = 320;
  v5 = type_info::raw_name(&survarium::timelimit_rule `RTTI Type Descriptor');
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(v6, (int)v3, 0x140u, v5, v12, v13, v14);
  v9 = v7;
  if ( !v7 )
    return 0;
  m_game = this->m_game;
  survarium::timelimit_rule_core::timelimit_rule_core((survarium::timelimit_rule_core *)v7, data->match_options, v8);
  *(_DWORD *)v9 = &survarium::timelimit_rule::`vftable'{for `vostok::resources::unmanaged_resource'};
  *((_DWORD *)v9 + 66) = &survarium::timelimit_rule::`vftable'{for `survarium::link_resolver'};
  *((_DWORD *)v9 + 78) = m_game;
  return (survarium::timelimit_rule_core *)v9;
}
