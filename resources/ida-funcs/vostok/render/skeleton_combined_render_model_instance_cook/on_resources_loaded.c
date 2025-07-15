void __thiscall vostok::render::skeleton_combined_render_model_instance_cook::on_resources_loaded(
        vostok::render::skeleton_combined_render_model_instance_cook *this,
        vostok::resources::queries_result *data,
        vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *parent)
{
  vostok::resources::queries_result *m_object; // esi
  vostok::memory::doug_lea_allocator *v4; // esi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  vostok::render::skeleton_render_model_instance *v8; // ecx
  survarium::pure_game_effect_emitter_base *v9; // eax
  survarium::pure_game_effect_emitter_base *v10; // edi
  vostok::render::skeleton_render_model_instance *v11; // ecx
  survarium::pure_game_effect_emitter_base *v12; // ecx
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v13; // edi
  vostok::resources::query_result_for_cook *v14; // ecx
  vostok::resources::query_result_for_cook *v15; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v16; // [esp-Ch] [ebp-1Ch] BYREF
  const vostok::resources::memory_type *v17; // [esp-8h] [ebp-18h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v18[4]; // [esp-4h] [ebp-14h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v19; // [esp+Ch] [ebp-4h] BYREF

  if ( data->m_result == 1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v19,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::resources::queries_result *)v19.m_object;
    data = 0;
    if ( v19.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
      data = m_object;
      _InterlockedExchangeAdd((volatile signed __int32 *)&m_object->m_queries[0].m_target_quality_level, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v19);
    v4 = vostok::render::g_allocator;
    v5 = type_info::raw_name(&vostok::render::skeleton_render_model_instance `RTTI Type Descriptor');
    v7 = vostok::memory::doug_lea_allocator::malloc_impl(
           v6,
           (int)v4,
           0x62C8u,
           v5,
           (const char *const)v18[1].m_object,
           (const char *const)v18[2].m_object,
           (const unsigned int)v18[3].m_object);
    if ( v7 )
    {
      vostok::render::skeleton_render_model_instance::skeleton_render_model_instance(v8, (int)v7);
      v19.m_object = v9;
    }
    else
    {
      v19.m_object = 0;
    }
    v18[0].m_object = (vostok::particle::particle_system_instance_impl *)v8;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      v18,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
    v10 = v19.m_object;
    vostok::render::skeleton_render_model_instance::assign_original(
      v11,
      (vostok::resources::resource_ptr<vostok::render::skeleton_render_model,vostok::resources::unmanaged_intrusive_base>)v19.m_object,
      v18[0]);
    v18[0].m_object = (vostok::particle::particle_system_instance_impl *)25288;
    v17 = &vostok::resources::nocache_memory;
    v16.m_object = v12;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v16,
      v10);
    v13 = parent;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v14,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)parent,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v16.m_object,
      v17,
      (unsigned int)v18[0].m_object);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v15,
      v13,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  }
  else
  {
    vostok::resources::check_queries_result(data);
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)v18[0].m_object,
      parent,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
