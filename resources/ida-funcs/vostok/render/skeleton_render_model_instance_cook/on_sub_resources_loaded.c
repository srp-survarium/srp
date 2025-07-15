void __thiscall vostok::render::skeleton_render_model_instance_cook::on_sub_resources_loaded(
        vostok::render::skeleton_render_model_instance_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_parent_query; // edi
  vostok::resources::queries_result *m_object; // esi
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  char *v8; // eax
  vostok::render::skeleton_render_model_instance *v9; // ecx
  survarium::pure_game_effect_emitter_base *v10; // eax
  survarium::pure_game_effect_emitter_base *v11; // edi
  vostok::render::skeleton_render_model_instance *v12; // ecx
  survarium::pure_game_effect_emitter_base *v13; // ecx
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v14; // edi
  vostok::resources::query_result_for_cook *v15; // ecx
  vostok::resources::query_result_for_cook *v16; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v17; // [esp-Ch] [ebp-20h] BYREF
  const vostok::resources::memory_type *v18; // [esp-8h] [ebp-1Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v19[4]; // [esp-4h] [ebp-18h] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v20; // [esp+Ch] [ebp-8h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v21; // [esp+10h] [ebp-4h] BYREF

  m_result = (vostok::resources::query_result_for_cook *)data->m_result;
  m_parent_query = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)data->m_parent_query;
  v20 = m_parent_query;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v21,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::resources::queries_result *)v21.m_object;
    data = 0;
    if ( v21.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
      data = m_object;
      _InterlockedExchangeAdd((volatile signed __int32 *)&m_object->m_queries[0].m_target_quality_level, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v21);
    v5 = vostok::render::g_allocator;
    v6 = type_info::raw_name(&vostok::render::skeleton_render_model_instance `RTTI Type Descriptor');
    v8 = vostok::memory::doug_lea_allocator::malloc_impl(
           v7,
           (int)v5,
           0x62C8u,
           v6,
           (const char *const)v19[1].m_object,
           (const char *const)v19[2].m_object,
           (const unsigned int)v19[3].m_object);
    if ( v8 )
    {
      vostok::render::skeleton_render_model_instance::skeleton_render_model_instance(v9, (int)v8);
      v21.m_object = v10;
    }
    else
    {
      v21.m_object = 0;
    }
    v19[0].m_object = (vostok::particle::particle_system_instance_impl *)v9;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      v19,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
    v11 = v21.m_object;
    vostok::render::skeleton_render_model_instance::assign_original(
      v12,
      (vostok::resources::resource_ptr<vostok::render::skeleton_render_model,vostok::resources::unmanaged_intrusive_base>)v21.m_object,
      v19[0]);
    v19[0].m_object = (vostok::particle::particle_system_instance_impl *)25288;
    v18 = &vostok::resources::nocache_memory;
    v17.m_object = v13;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v17,
      v11);
    v14 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v20;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v15,
      v20,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v17.m_object,
      v18,
      (unsigned int)v19[0].m_object);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v16,
      v14,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
