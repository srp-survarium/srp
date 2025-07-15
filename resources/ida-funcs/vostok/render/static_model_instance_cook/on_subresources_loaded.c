void __thiscall vostok::render::static_model_instance_cook::on_subresources_loaded(
        vostok::render::static_model_instance_cook *this,
        vostok::resources::queries_result *data,
        vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *parent_query)
{
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  char *v6; // eax
  vostok::resources::unmanaged_resource *v7; // ecx
  char *v8; // esi
  char *v9; // ebx
  vostok::particle::particle_system_instance_impl *m_object; // esi
  survarium::pure_game_effect_emitter_base *v11; // ecx
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v12; // edi
  vostok::resources::query_result_for_cook *v13; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v14; // [esp-Ch] [ebp-2Ch] BYREF
  assert_on_fail_bool v15; // [esp-8h] [ebp-28h]
  vostok::resources::cook_base::result_enum v16; // [esp-4h] [ebp-24h]
  const char *v17; // [esp+0h] [ebp-20h]
  const char *v18; // [esp+4h] [ebp-1Ch]
  unsigned int v19; // [esp+8h] [ebp-18h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v20; // [esp+10h] [ebp-10h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v21; // [esp+14h] [ebp-Ch] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v22; // [esp+18h] [ebp-8h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v23; // [esp+1Ch] [ebp-4h] BYREF

  if ( data->m_result == 1 )
  {
    v3 = vostok::render::g_allocator;
    v4 = type_info::raw_name(&vostok::render::static_model_instance `RTTI Type Descriptor');
    v6 = vostok::memory::doug_lea_allocator::malloc_impl(v5, (int)v3, 0x110u, v4, v17, v18, v19);
    v8 = v6;
    v9 = 0;
    if ( v6 )
    {
      vostok::resources::unmanaged_resource::unmanaged_resource(v7, v6, fs_iterator_class);
      *(_DWORD *)v8 = &vostok::render::static_model_instance::`vftable';
      *((_DWORD *)v8 + 66) = 0;
      *((_DWORD *)v8 + 67) = 0;
      v9 = v8;
    }
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v22,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::particle::particle_system_instance_impl *)v22.m_object;
    v23.m_object = 0;
    if ( v22.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v23);
      v23.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v23,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v9
    + 66);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v23);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v22);
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)v9
    + 67,
      0);
    if ( data->m_size > 1 )
    {
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v20,
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[1].m_unmanaged_resource);
      vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
        &v21,
        v20.m_object);
      vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
        &v21,
        (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)v9
      + 67);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v21);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20);
    }
    v16 = 272;
    v15 = (assert_on_fail_bool)&vostok::resources::nocache_memory;
    v14.m_object = v11;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v14,
      (survarium::pure_game_effect_emitter_base *)v9);
    v12 = parent_query;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v13,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)parent_query,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v14.m_object,
      (const vostok::resources::memory_type *)v15,
      v16);
    v16 = result_fail;
    v15 = assert_on_fail_true;
    v14.m_object = (survarium::pure_game_effect_emitter_base *)3;
  }
  else
  {
    v12 = parent_query;
    v16 = result_out_of_memory|0x8;
    v15 = assert_on_fail_true;
    v14.m_object = (survarium::pure_game_effect_emitter_base *)1;
  }
  vostok::resources::query_result_for_cook::finish_query_impl(
    (vostok::resources::query_result_for_cook *)this,
    v12,
    (vostok::resources::cook_base::result_enum)v14.m_object,
    v15,
    v16);
}
