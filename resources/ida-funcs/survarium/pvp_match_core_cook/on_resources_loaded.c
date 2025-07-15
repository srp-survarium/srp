void __thiscall survarium::pvp_match_core_cook::on_resources_loaded(
        survarium::pvp_match_core_cook *this,
        survarium::animations_registry::animations_tuple *data,
        survarium::pvp_match_core_query_user_data user_data,
        vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *physics_world)
{
  vostok::particle::particle_system_instance_impl *m_object; // esi
  void *v5; // esp
  void *v6; // esp
  survarium::animations_registry::animations_tuple *m_begin; // esi
  survarium::animations_registry::animations_tuple *m_end; // ecx
  survarium::animations_registry::animations_tuple *v9; // edi
  survarium::animations_registry::animations_tuple *v10; // edi
  survarium::animations_registry::animations_tuple *v11; // eax
  void *v12; // esp
  vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *v13; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v14; // eax
  survarium::pure_game_effect_emitter_base *v15; // edi
  _DWORD *p_m_object; // esi
  survarium::pure_game_effect_emitter_base *players_count; // esi
  void *v18; // esp
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v19; // eax
  int v20; // eax
  unsigned int v21; // esi
  const char *v22; // eax
  survarium::animations_registry::animations_tuple *unmanaged_memory; // eax
  int v24; // esi
  const char *v25; // eax
  survarium::animations_registry::animations_tuple *v26; // eax
  survarium::animations_registry::animations_tuple *v27; // eax
  survarium::animations_registry::animations_tuple *v28; // eax
  survarium::animations_registry::animations_tuple *v29; // ebx
  survarium::animations_registry::animations_tuple *v30; // ecx
  survarium::animations_registry::animations_tuple *v31; // eax
  survarium::animations_registry::animations_tuple *v32; // eax
  const char *v33; // eax
  void *v34; // eax
  survarium::pure_game_effect_emitter_base *v35; // ecx
  survarium::pure_game_effect_emitter_base *v36; // eax
  vostok::resources::resource_ptr<survarium::game_match_rule_base,vostok::resources::unmanaged_intrusive_base> *v37; // edi
  vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *v38; // edi
  unsigned int id; // eax
  vostok::resources::query_result_for_cook *v40; // ecx
  vostok::resources::query_result_for_cook *v41; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v42; // [esp-7530Ch] [ebp-75384h] BYREF
  const vostok::resources::memory_type *v43; // [esp-75308h] [ebp-75380h]
  unsigned int v44; // [esp-75304h] [ebp-7537Ch]
  _BYTE v45[240000]; // [esp-75300h] [ebp-75378h] BYREF
  _BYTE v46[240016]; // [esp-3A980h] [ebp-3A9F8h] BYREF
  survarium::animations_registry::animations_tuple *v47; // [esp+10h] [ebp-68h]
  survarium::animations_registry::animations_tuple *v48[3]; // [esp+14h] [ebp-64h] BYREF
  survarium::animations_registry::animations_tuple *v49; // [esp+20h] [ebp-58h] BYREF
  survarium::animations_registry::animations_tuple *v50; // [esp+24h] [ebp-54h]
  vostok::buffer_vector<survarium::animations_registry::animations_tuple> v51; // [esp+28h] [ebp-50h] BYREF
  vostok::buffer_vector<survarium::animations_registry::animations_tuple> v52; // [esp+34h] [ebp-44h] BYREF
  survarium::animations_registry::animations_tuple *v53; // [esp+40h] [ebp-38h]
  survarium::pvp_match_core_cook *v54; // [esp+44h] [ebp-34h]
  vostok::resources::resource_ptr<survarium::game_material_manager,vostok::resources::unmanaged_intrusive_base> game_material_manager; // [esp+48h] [ebp-30h] BYREF
  survarium::animations_registry::animations_tuple *m_max_end; // [esp+4Ch] [ebp-2Ch]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v57; // [esp+50h] [ebp-28h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v58; // [esp+54h] [ebp-24h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v59; // [esp+58h] [ebp-20h] BYREF
  int v60; // [esp+5Ch] [ebp-1Ch]
  vostok::resources::resource_ptr<survarium::game_match_rule_base,vostok::resources::unmanaged_intrusive_base> *rules_end; // [esp+60h] [ebp-18h]
  int v62; // [esp+64h] [ebp-14h]
  vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *players_end; // [esp+68h] [ebp-10h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v64; // [esp+6Ch] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v65; // [esp+70h] [ebp-8h]
  int v66; // [esp+74h] [ebp-4h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v67; // [esp+80h] [ebp+8h]
  vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *players_begin; // [esp+9Ch] [ebp+24h]
  survarium::pure_game_effect_emitter_base *players_begina; // [esp+9Ch] [ebp+24h]

  v66 = 0;
  v54 = this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v58,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data[25]);
  vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<survarium::server_game_project,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v58,
    (vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&game_material_manager);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v58);
  v62 = 2;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v58,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data[86].third_view);
  m_object = (vostok::particle::particle_system_instance_impl *)v58.m_object;
  v64.m_object = 0;
  if ( v58.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v64);
    v64.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v58);
  user_data.animations_registry->m_has_been_queried = 0;
  user_data.animations_registry->m_is_valid = 1;
  v5 = alloca((int)&loc_3A97E + 2);
  v50 = (survarium::animations_registry::animations_tuple *)&v46[(_DWORD)&loc_3A97E + 2];
  v6 = alloca((int)&loc_3A97E + 2);
  m_begin = user_data.animations_registry->m_animations.m_begin;
  user_data.animations_registry->m_animations.m_begin = (survarium::animations_registry::animations_tuple *)v46;
  m_end = user_data.animations_registry->m_animations.m_end;
  user_data.animations_registry->m_animations.m_end = (survarium::animations_registry::animations_tuple *)v46;
  m_max_end = user_data.animations_registry->m_animations.m_max_end;
  user_data.animations_registry->m_animations.m_max_end = v50;
  v50 = m_max_end;
  v9 = user_data.animations_registry->m_indices.m_begin;
  user_data.animations_registry->m_indices.m_begin = (survarium::animations_registry::animations_tuple *)v45;
  v58.m_object = (survarium::pure_game_effect_emitter_base *)v9;
  v47 = v9;
  v10 = user_data.animations_registry->m_indices.m_end;
  user_data.animations_registry->m_indices.m_end = (survarium::animations_registry::animations_tuple *)v45;
  v11 = user_data.animations_registry->m_indices.m_max_end;
  v53 = m_begin;
  v48[2] = m_begin;
  v49 = m_end;
  m_max_end = v10;
  v48[0] = v10;
  user_data.animations_registry->m_indices.m_max_end = (survarium::animations_registry::animations_tuple *)&v45[(_DWORD)&loc_3A97E + 2];
  v48[1] = v11;
  if ( m_begin != m_end )
  {
    vostok::buffer_vector<survarium::animations_registry::animations_tuple>::destroy(m_begin, &v49);
    v49 = m_begin;
    if ( m_begin )
      vostok::memory::g_resources_unmanaged_allocator.call_free(
        &vostok::memory::g_resources_unmanaged_allocator,
        m_begin,
        "survarium::pvp_match_core_cook::on_resources_loaded",
        ".\\pvp_match_core_cook.cpp",
        87u);
  }
  if ( (survarium::animations_registry::animations_tuple *)v58.m_object != m_max_end )
  {
    vostok::buffer_vector<survarium::animations_registry::animations_tuple>::destroy(
      (survarium::animations_registry::animations_tuple *)v58.m_object,
      v48);
    v48[0] = (survarium::animations_registry::animations_tuple *)v58.m_object;
    if ( v58.m_object )
      vostok::memory::g_resources_unmanaged_allocator.call_free(
        &vostok::memory::g_resources_unmanaged_allocator,
        v58.m_object,
        "survarium::pvp_match_core_cook::on_resources_loaded",
        ".\\pvp_match_core_cook.cpp",
        94u);
  }
  v60 = !user_data.is_loopback + 3;
  v12 = alloca(4 * v60);
  rules_end = (vostok::resources::resource_ptr<survarium::game_match_rule_base,vostok::resources::unmanaged_intrusive_base> *)v45;
  if ( !user_data.is_loopback != -3 )
  {
    v65 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v45;
    players_end = (vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *)&data[129].third_view;
    v57.m_object = (survarium::pure_game_effect_emitter_base *)(!user_data.is_loopback + 3);
    do
    {
      if ( v65 )
      {
        v13 = players_end;
        ++v62;
        players_end += 184;
        v66 |= 1u;
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v59,
          (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v13[55]);
        v14 = v65;
        v15 = v59.m_object;
        v65->m_object = 0;
        if ( v15 )
        {
          p_m_object = &v14->m_object;
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(v14);
          *p_m_object = v15;
          _InterlockedExchangeAdd(&v15->m_reference_count, 1u);
        }
      }
      if ( (v66 & 1) != 0 )
      {
        v66 &= ~1u;
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v59);
      }
      v65->m_object->__vftable[1].unlink_child_resource(
        v65->m_object,
        (vostok::resources::resource_base *)user_data.animations_registry);
      ++v65;
      --v57.m_object;
    }
    while ( v57.m_object );
  }
  players_count = (survarium::pure_game_effect_emitter_base *)user_data.match_options->players_count;
  v59.m_object = players_count;
  v18 = alloca(4 * (_DWORD)players_count);
  players_end = (vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *)v45;
  if ( players_count )
  {
    m_end = data;
    v65 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v45;
    v62 = (int)(&data[6].id + 184 * v62);
    m_max_end = (survarium::animations_registry::animations_tuple *)players_count;
    do
    {
      if ( v65 )
      {
        v19 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)v62;
        v62 += 736;
        v66 |= 2u;
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v57,
          v19 + 55);
        vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
          v65,
          (vostok::particle::particle_system_instance_impl *)v57.m_object);
      }
      if ( (v66 & 2) != 0 )
      {
        v66 &= ~2u;
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v57);
      }
      survarium::base_player::register_animations(
        (survarium::base_player *)m_end,
        (int)v65->m_object,
        user_data.animations_registry);
      ++v65;
      m_max_end = (survarium::animations_registry::animations_tuple *)((char *)m_max_end - 1);
    }
    while ( m_max_end );
  }
  survarium::animations_registry::actualize(
    (survarium::animations_registry *)m_end,
    (survarium::animations_registry::animations_tuple *)user_data.animations_registry);
  v20 = user_data.animations_registry->m_animations.m_end - user_data.animations_registry->m_animations.m_begin;
  v44 = (unsigned int)&__type_info_root_node;
  v21 = v20;
  m_max_end = (survarium::animations_registry::animations_tuple *)(user_data.animations_registry->m_indices.m_end
                                                                 - user_data.animations_registry->m_indices.m_begin);
  v22 = type_info::name(
          &survarium::animations_registry::animations_tuple `RTTI Type Descriptor',
          &__type_info_root_node);
  unmanaged_memory = (survarium::animations_registry::animations_tuple *)vostok::resources::allocate_unmanaged_memory(
                                                                           v21 * 12,
                                                                           v22);
  v51.m_max_end = &unmanaged_memory[v21];
  v24 = (int)m_max_end;
  v51.m_begin = unmanaged_memory;
  v51.m_end = unmanaged_memory;
  v25 = type_info::name(
          &survarium::animations_registry::animations_tuple `RTTI Type Descriptor',
          &__type_info_root_node);
  v52.m_begin = (survarium::animations_registry::animations_tuple *)vostok::resources::allocate_unmanaged_memory(
                                                                      v24 * 12,
                                                                      v25);
  v52.m_end = v52.m_begin;
  v52.m_max_end = &v52.m_begin[v24];
  vostok::buffer_vector<survarium::animations_registry::animations_tuple>::operator=(
    &v51,
    &user_data.animations_registry->m_animations);
  vostok::buffer_vector<survarium::animations_registry::animations_tuple>::operator=(
    &v52,
    &user_data.animations_registry->m_indices);
  v26 = user_data.animations_registry->m_animations.m_begin;
  user_data.animations_registry->m_animations.m_begin = v51.m_begin;
  v57.m_object = (survarium::pure_game_effect_emitter_base *)v26;
  v51.m_begin = v26;
  v27 = user_data.animations_registry->m_animations.m_end;
  user_data.animations_registry->m_animations.m_end = v51.m_end;
  v51.m_end = v27;
  v28 = user_data.animations_registry->m_animations.m_max_end;
  user_data.animations_registry->m_animations.m_max_end = v51.m_max_end;
  v29 = user_data.animations_registry->m_indices.m_begin;
  v30 = v52.m_end;
  v51.m_max_end = v28;
  user_data.animations_registry->m_indices.m_begin = v52.m_begin;
  v31 = user_data.animations_registry->m_indices.m_end;
  user_data.animations_registry->m_indices.m_end = v30;
  v52.m_end = v31;
  v32 = user_data.animations_registry->m_indices.m_max_end;
  user_data.animations_registry->m_indices.m_max_end = v52.m_max_end;
  v52.m_begin = v29;
  v52.m_max_end = v32;
  v33 = type_info::name(&survarium::pvp_match_core `RTTI Type Descriptor', &__type_info_root_node);
  v34 = vostok::resources::allocate_unmanaged_memory(0x140u, v33);
  v35 = (survarium::pure_game_effect_emitter_base *)v44;
  if ( v34 )
  {
    survarium::pvp_match_core::pvp_match_core(
      (survarium::pvp_match_core *)v54->m_is_server,
      (int)v34,
      v54->m_is_server,
      *(const vostok::resources::resource_ptr<survarium::server_game_project,vostok::resources::unmanaged_intrusive_base> **)&user_data.is_loopback,
      (const vostok::resources::resource_ptr<survarium::server_game_project,vostok::resources::unmanaged_intrusive_base> *)user_data.match_options,
      (const vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&game_material_manager,
      &v64,
      user_data.bullet_manager_engine,
      physics_world,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)players_end,
      (const vostok::resources::resource_ptr<survarium::game_match_rule_base,vostok::resources::unmanaged_intrusive_base> *)&players_end[(int)v59.m_object],
      rules_end,
      &rules_end[v60]);
    m_max_end = (survarium::animations_registry::animations_tuple *)v36;
  }
  else
  {
    m_max_end = 0;
  }
  if ( v60 )
  {
    v37 = rules_end;
    players_begin = (vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *)v60;
    do
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v37++);
      players_begin = (vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *)((char *)players_begin - 1);
    }
    while ( players_begin );
  }
  if ( v59.m_object )
  {
    v38 = players_end;
    players_begina = v59.m_object;
    do
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v38++);
      players_begina = (survarium::pure_game_effect_emitter_base *)((char *)players_begina - 1);
    }
    while ( players_begina );
  }
  id = data[2].id;
  v44 = 320;
  v43 = &vostok::resources::nocache_memory;
  v42.m_object = v35;
  v67 = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)id;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v42,
    (survarium::pure_game_effect_emitter_base *)m_max_end);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v40,
    v67,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v42.m_object,
    v43,
    v44);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v41,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v67,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
  vostok::buffer_vector<survarium::animations_registry::animations_tuple>::destroy(v29, &v52.m_end);
  vostok::buffer_vector<survarium::animations_registry::animations_tuple>::destroy(
    (survarium::animations_registry::animations_tuple *)v57.m_object,
    &v51.m_end);
  vostok::buffer_vector<survarium::animations_registry::animations_tuple>::destroy(
    (survarium::animations_registry::animations_tuple *)v58.m_object,
    v48);
  vostok::buffer_vector<survarium::animations_registry::animations_tuple>::destroy(v53, &v49);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v64);
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&game_material_manager);
}
