void __thiscall vostok::render::skeleton_combined_model_cook::on_config_loaded(
        vostok::render::skeleton_combined_model_cook *this,
        vostok::resources::queries_result *result,
        vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *parent)
{
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v3; // edi
  vostok::memory::doug_lea_allocator *v4; // esi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  vostok::render::skeleton_combined_cook_data *v8; // ecx
  vostok::render::skeleton_combined_cook_data *v9; // eax
  vostok::render::skeleton_combined_cook_data *v10; // ebx
  vostok::resources::queries_result *m_object; // esi
  vostok::render::skeleton_combined_model_cook *v12; // [esp-4h] [ebp-1Ch]
  const char *v13; // [esp+0h] [ebp-18h]
  const char *v14; // [esp+4h] [ebp-14h]
  unsigned int v15; // [esp+8h] [ebp-10h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v17; // [esp+14h] [ebp-4h] BYREF

  v3 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)result;
  if ( result->m_result == 1 )
  {
    v4 = vostok::render::g_allocator;
    v5 = type_info::raw_name(&vostok::render::skeleton_combined_cook_data `RTTI Type Descriptor');
    v7 = vostok::memory::doug_lea_allocator::malloc_impl(v6, (int)v4, 0x1C98u, v5, v13, v14, v15);
    if ( v7 )
    {
      vostok::render::skeleton_combined_cook_data::skeleton_combined_cook_data(v8, (int)v7, 1);
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v17,
      v3 + 75);
    m_object = (vostok::resources::queries_result *)v17.m_object;
    result = 0;
    if ( v17.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
      result = m_object;
      _InterlockedExchangeAdd((volatile signed __int32 *)&m_object->m_queries[0].m_target_quality_level, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v17);
    vostok::render::build_from_config(
      (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&result,
      v10);
    vostok::render::skeleton_combined_model_cook::query_resources_by_data(
      v12,
      __SPAIR64__((unsigned int)parent, (unsigned int)this),
      (int)v10);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      parent,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
