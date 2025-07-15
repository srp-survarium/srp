void __thiscall survarium::player_respawn_rule_cook::on_resources_loaded(
        survarium::player_respawn_rule_cook *this,
        vostok::resources::queries_result *data,
        const unsigned __int8 respawn_time,
        const bool single_player,
        vostok::physics::world *physics_world)
{
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  survarium::game_match_rule_base *v8; // ecx
  char *v9; // esi
  survarium::pure_game_effect_emitter_base *v10; // eax
  unsigned int v11; // ecx
  char *v12; // eax
  vostok::memory::doug_lea_allocator *v13; // ecx
  char *v14; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_parent_query; // ebx
  survarium::pure_game_effect_emitter_base *v16; // ecx
  vostok::resources::query_result_for_cook *v17; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v18; // [esp-4h] [ebp-1Ch] BYREF
  const char *v19; // [esp+0h] [ebp-18h]
  const char *v20; // [esp+4h] [ebp-14h]
  unsigned int v21; // [esp+8h] [ebp-10h]
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v22; // [esp+Ch] [ebp-Ch] BYREF
  vostok::resources::memory_usage_type v23; // [esp+10h] [ebp-8h] BYREF

  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v23.size,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<survarium::server_game_project,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v23.size,
    &v22);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v23.size);
  v5 = survarium::g_allocator;
  if ( single_player )
  {
    v6 = type_info::raw_name(&survarium::single_player_respawn_rule `RTTI Type Descriptor');
    v9 = vostok::memory::doug_lea_allocator::malloc_impl(v7, (int)v5, 0x168u, v6, v19, v20, v21);
    if ( v9 )
    {
      survarium::game_match_rule_base::game_match_rule_base(v8, v9, player_respawn_rule_type);
      *((_DWORD *)v9 + 88) = 0;
      *(_DWORD *)v9 = &survarium::single_player_respawn_rule::`vftable'{for `vostok::resources::unmanaged_resource'};
      *((_DWORD *)v9 + 66) = &survarium::single_player_respawn_rule::`vftable'{for `survarium::link_resolver'};
      memset(v9 + 272, 0xFFu, 0x50u);
      v10 = (survarium::pure_game_effect_emitter_base *)v9;
    }
    else
    {
      v10 = 0;
    }
    v11 = 360;
  }
  else
  {
    v12 = type_info::raw_name(&survarium::player_respawn_rule `RTTI Type Descriptor');
    v14 = vostok::memory::doug_lea_allocator::malloc_impl(v13, (int)v5, 0x188u, v12, v19, v20, v21);
    if ( v14 )
      survarium::player_respawn_rule::player_respawn_rule(
        (survarium::player_respawn_rule *)(1000 * respawn_time),
        (const unsigned int)v14,
        (const vostok::configs::binary_config *)(1000 * respawn_time),
        (vostok::physics::world *)v22.m_object->m_config.m_object,
        physics_world);
    else
      v10 = 0;
    v11 = 392;
  }
  m_parent_query = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)data->m_parent_query;
  v18.m_object = (survarium::pure_game_effect_emitter_base *)v11;
  v23.type = &vostok::resources::nocache_memory;
  v23.size = v11;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v18,
    v10);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(&v23, v16, m_parent_query, v18);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v17,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v22);
}
