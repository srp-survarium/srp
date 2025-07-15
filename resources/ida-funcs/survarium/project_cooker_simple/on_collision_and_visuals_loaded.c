void __thiscall survarium::project_cooker_simple::on_collision_and_visuals_loaded(
        survarium::project_cooker_simple *this,
        vostok::resources::queries_result *data,
        survarium::pure_game_effect_emitter_base *project)
{
  survarium::pure_game_effect_emitter_base *v3; // ebx
  survarium::pure_game_effect_emitter_base *v4; // ecx
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v5; // eax
  survarium::pure_game_effect_emitter_base *m_object; // esi
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v7; // eax
  survarium::pure_game_effect_emitter_base *v8; // esi
  survarium::pure_game_effect_emitter_base *v9; // ecx
  survarium::pure_game_effect_emitter_base *v10; // edi
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_parent_query; // ebx
  vostok::resources::query_result_for_cook *v12; // ecx
  vostok::resources::query_result_for_cook *v13; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v14; // [esp-Ch] [ebp-34h] BYREF
  const vostok::resources::memory_type *v15; // [esp-8h] [ebp-30h]
  unsigned int v16; // [esp-4h] [ebp-2Ch]
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v17; // [esp+10h] [ebp-18h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v18; // [esp+14h] [ebp-14h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v19; // [esp+18h] [ebp-10h] BYREF
  vostok::resources::query_result *v20; // [esp+1Ch] [ebp-Ch]
  int v21; // [esp+20h] [ebp-8h]
  vostok::resources::query_result *m_queries; // [esp+24h] [ebp-4h]

  v3 = project;
  v4 = 0;
  v20 = 0;
  if ( project->m_children_resources.m_thread_id )
  {
    v21 = 0;
    m_queries = data->m_queries;
    do
    {
      v17 = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(v21 + v3->m_children_resources.m_lock);
      v5 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)m_queries++;
      v18.m_object = (survarium::pure_game_effect_emitter_base *)((char *)&v4->__vftable + 1);
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v19,
        v5 + 55);
      m_object = v19.m_object;
      project = 0;
      if ( v19.m_object )
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&project);
        project = m_object;
        _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&project,
        v17 + 17);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&project);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v19);
      v20 = (vostok::resources::query_result *)((char *)v20 + 1);
      v21 += 76;
      v4 = v18.m_object;
    }
    while ( (unsigned int)v20 < v3->m_children_resources.m_thread_id );
  }
  m_queries = 0;
  if ( v3[1].m_reference_count )
  {
    v21 = 0;
    v20 = &data->m_queries[(_DWORD)v4];
    do
    {
      v17 = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(v21 + *((_DWORD *)&v3[1].m_memory_type_data + 1));
      v7 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)v20++;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v18,
        v7 + 55);
      v8 = v18.m_object;
      project = 0;
      if ( v18.m_object )
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&project);
        project = v8;
        _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&project,
        v17 + 16);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&project);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v18);
      m_queries = (vostok::resources::query_result *)((char *)m_queries + 1);
      v21 += 68;
    }
    while ( (unsigned int)m_queries < v3[1].m_reference_count );
  }
  BYTE1(v3[1].m_sub_fat.m_object) = 1;
  LOBYTE(v3[1].m_sub_fat.m_object) = 1;
  if ( survarium::simple_game_project::all_loaded((survarium::simple_game_project *)v4, (int)v3) )
  {
    v16 = 488;
    v15 = &vostok::resources::nocache_memory;
    v14.m_object = v9;
    v10 = (survarium::pure_game_effect_emitter_base *)&v3->m_children_resources.gapC;
    m_parent_query = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)data->m_parent_query;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v14,
      v10);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v12,
      m_parent_query,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v14.m_object,
      v15,
      v16);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v13,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)data->m_parent_query,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
  }
}
