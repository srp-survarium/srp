void __thiscall vostok::render::tracer_model_instance_cook::on_model_ready(
        vostok::render::tracer_model_instance_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_parent_query; // esi
  vostok::resources::query_result_for_cook *v3; // ecx
  vostok::memory::doug_lea_allocator *v4; // esi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  vostok::resources::unmanaged_resource *v8; // ecx
  char *v9; // ebx
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::math::float4x4 *v11; // ecx
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v12; // edi
  vostok::resources::query_result_for_cook *v13; // ecx
  vostok::resources::query_result_for_cook *v14; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v15; // [esp-Ch] [ebp-64h] BYREF
  const vostok::resources::memory_type *v16; // [esp-8h] [ebp-60h]
  unsigned int v17; // [esp-4h] [ebp-5Ch]
  const char *v18; // [esp+0h] [ebp-58h]
  const char *v19; // [esp+4h] [ebp-54h]
  unsigned int v20; // [esp+8h] [ebp-50h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v21; // [esp+Ch] [ebp-4Ch] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v22; // [esp+10h] [ebp-48h] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v23; // [esp+14h] [ebp-44h]
  vostok::math::float4x4 v24; // [esp+18h] [ebp-40h] BYREF

  m_parent_query = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)data->m_parent_query;
  v23 = m_parent_query;
  if ( vostok::resources::query_result_for_user::is_successful(
         (vostok::resources::query_result_for_user *)this,
         (int)data->m_queries) )
  {
    v4 = vostok::render::g_allocator;
    v5 = type_info::raw_name(&vostok::render::tracer_model_instance `RTTI Type Descriptor');
    v7 = vostok::memory::doug_lea_allocator::malloc_impl(v6, (int)v4, 0x150u, v5, v18, v19, v20);
    v9 = v7;
    if ( v7 )
    {
      vostok::resources::unmanaged_resource::unmanaged_resource(v8, v7, fs_iterator_class);
      *(_DWORD *)v9 = &vostok::render::tracer_model_instance::`vftable';
      *((_DWORD *)v9 + 82) = 0;
      *((_DWORD *)v9 + 83) = -1;
    }
    else
    {
      v9 = 0;
    }
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v22,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::particle::particle_system_instance_impl *)v22.m_object;
    v21.m_object = 0;
    if ( v22.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v21);
      v21.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v22);
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v21.m_object->m_lods,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v9
    + 82);
    qmemcpy(v9 + 264, vostok::math::float4x4::identity(v11, &v24), 0x40u);
    *((_DWORD *)v9 + 83) = 0;
    v17 = 336;
    v16 = &vostok::resources::nocache_memory;
    v15.m_object = 0;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v15,
      (survarium::pure_game_effect_emitter_base *)v9);
    v12 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v23;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v13,
      v23,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v15.m_object,
      v16,
      v17);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v14,
      v12,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v21);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      v3,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
  }
}
