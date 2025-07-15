void __thiscall vostok::render::static_render_model_instance_cook::on_sub_resources_loaded(
        vostok::render::static_render_model_instance_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_parent_query; // edi
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  char *v8; // eax
  vostok::render::render_model_instance_impl *v9; // ecx
  char *v10; // esi
  int *v11; // edx
  vostok::configs::binary_config_value *v12; // eax
  vostok::variant<32> *v13; // ecx
  survarium::pure_game_effect_emitter_base *v14; // edi
  vostok::render::static_render_model_instance *v15; // ecx
  int v16; // ecx
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v17; // edi
  vostok::resources::query_result_for_cook *v18; // ecx
  vostok::resources::query_result_for_cook *v19; // ecx
  _BYTE v20[28]; // [esp-1Ch] [ebp-4Ch] BYREF
  const char *v21; // [esp+0h] [ebp-30h]
  const char *v22; // [esp+4h] [ebp-2Ch]
  unsigned int v23; // [esp+8h] [ebp-28h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v24; // [esp+Ch] [ebp-24h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v25; // [esp+10h] [ebp-20h] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v26; // [esp+14h] [ebp-1Ch]
  _BYTE v27[24]; // [esp+18h] [ebp-18h] BYREF

  m_result = (vostok::resources::query_result_for_cook *)data->m_result;
  m_parent_query = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)data->m_parent_query;
  v26 = m_parent_query;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v25,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::particle::particle_system_instance_impl *)v25.m_object;
    v24.m_object = 0;
    if ( v25.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v24);
      v24.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v25);
    v5 = vostok::render::g_allocator;
    v6 = type_info::raw_name(&vostok::render::static_render_model_instance `RTTI Type Descriptor');
    v8 = vostok::memory::doug_lea_allocator::malloc_impl(v7, (int)v5, 0x270u, v6, v21, v22, v23);
    v10 = v8;
    if ( v8 )
    {
      vostok::render::render_model_instance_impl::render_model_instance_impl(v9, (int)v8);
      *(_DWORD *)v10 = &vostok::render::static_render_model_instance::`vftable';
      *((_DWORD *)v10 + 152) = 0;
      v10[612] = 0;
      *((_DWORD *)v10 + 154) = 0;
      v25.m_object = (survarium::pure_game_effect_emitter_base *)v10;
    }
    else
    {
      v25.m_object = 0;
    }
    if ( v26[66].m_object )
    {
      vostok::configs::binary_config_value::binary_config_value((vostok::configs::binary_config_value *)v9, (int)v27);
      vostok::variant<32>::try_get<vostok::configs::binary_config_value>(v13, *v11, v12);
      *(vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)v20 = v25;
      qmemcpy(&v20[4], v27, 0x18u);
      vostok::render::static_render_model_instance::add_sectors_holder(0, *(vostok::configs::binary_config_value *)v20);
    }
    *(_DWORD *)&v20[24] = v9;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20[24],
      &v24);
    v14 = v25.m_object;
    vostok::render::static_render_model_instance::assign_original(
      v15,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v25.m_object,
      *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20[24]);
    *(_DWORD *)&v20[24] = 624;
    *(_DWORD *)&v20[20] = &vostok::resources::nocache_memory;
    *(_DWORD *)&v20[16] = v16;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v20[16],
      v14);
    v17 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v26;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v18,
      v26,
      *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20[16],
      *(const vostok::resources::memory_type **)&v20[20],
      *(unsigned int *)&v20[24]);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v19,
      v17,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v24);
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
