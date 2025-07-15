void __thiscall vostok::render::skeleton_combined_model_instance_cook::on_resources_loaded(
        vostok::render::skeleton_combined_model_instance_cook *this,
        vostok::resources::queries_result *data,
        vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *parent_query)
{
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v3; // edi
  vostok::resources::query_result_for_cook *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  char *v8; // eax
  vostok::render::skeleton_model_instance *v9; // ecx
  survarium::pure_game_effect_emitter_base *v10; // eax
  vostok::particle::particle_system_instance_impl *m_object; // esi
  survarium::pure_game_effect_emitter_base *v12; // ebx
  vostok::particle::particle_system_instance_impl *v13; // esi
  survarium::pure_game_effect_emitter_base_vtbl *v14; // ebx
  int v15; // eax
  vostok::buffer_vector<vostok::math::float4x4> *p_unlink_child_resource; // ebx
  vostok::math::float4x4 *v17; // ecx
  int v18; // eax
  vostok::math::float4x4 *v19; // eax
  char *v20; // edi
  vostok::resources::query_result_for_cook *v21; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v22; // [esp-Ch] [ebp-6Ch] BYREF
  assert_on_fail_bool v23; // [esp-8h] [ebp-68h]
  vostok::resources::cook_base::result_enum v24; // [esp-4h] [ebp-64h]
  const char *v25; // [esp+0h] [ebp-60h]
  const char *v26; // [esp+4h] [ebp-5Ch]
  unsigned int v27; // [esp+8h] [ebp-58h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v28; // [esp+Ch] [ebp-54h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v29; // [esp+10h] [ebp-50h] BYREF
  survarium::pure_game_effect_emitter_base *object; // [esp+14h] [ebp-4Ch]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v31; // [esp+18h] [ebp-48h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v32; // [esp+1Ch] [ebp-44h] BYREF
  vostok::math::float4x4 v33; // [esp+20h] [ebp-40h] BYREF

  if ( data->m_result == 1 )
  {
    v5 = vostok::render::g_allocator;
    v6 = type_info::raw_name(&vostok::render::skeleton_model_instance `RTTI Type Descriptor');
    v8 = vostok::memory::doug_lea_allocator::malloc_impl(v7, (int)v5, 0x110u, v6, v25, v26, v27);
    if ( v8 )
    {
      vostok::render::skeleton_model_instance::skeleton_model_instance(v9, v8);
      object = v10;
    }
    else
    {
      object = 0;
    }
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v31,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::particle::particle_system_instance_impl *)v31.m_object;
    v28.m_object = 0;
    if ( v31.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v28);
      v28.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    v12 = object + 1;
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v28,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&object[1]);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v28);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v31);
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v32,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[1].m_unmanaged_resource);
    v13 = (vostok::particle::particle_system_instance_impl *)v32.m_object;
    v29.m_object = 0;
    if ( v32.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v29);
      v29.m_object = v13;
      _InterlockedExchangeAdd(&v13->m_reference_count, 1u);
    }
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v29,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&object[1].type);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v29);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v32);
    v14 = v12->__vftable;
    v15 = *((_DWORD *)v14[788].log_string + 81) - *((_DWORD *)v14[788].log_string + 80);
    p_unlink_child_resource = (vostok::buffer_vector<vostok::math::float4x4> *)&v14[275].unlink_child_resource;
    vostok::buffer_vector<vostok::math::float4x4>::resize(p_unlink_child_resource, v15 >> 6);
    v18 = (char *)p_unlink_child_resource->m_end - (char *)p_unlink_child_resource->m_begin;
    v28.m_object = 0;
    if ( v18 >> 6 )
    {
      v29.m_object = 0;
      do
      {
        v19 = vostok::math::float4x4::identity(v17, &v33);
        v20 = (char *)v29.m_object + (unsigned int)p_unlink_child_resource->m_begin;
        ++v28.m_object;
        v29.m_object = (vostok::particle::particle_system_instance_impl *)((char *)v29.m_object + 64);
        qmemcpy(v20, v19, 0x40u);
        v17 = 0;
      }
      while ( (unsigned int)v28.m_object < p_unlink_child_resource->m_end - p_unlink_child_resource->m_begin );
    }
    v24 = 272;
    v23 = (assert_on_fail_bool)&vostok::resources::nocache_memory;
    v22.m_object = (survarium::pure_game_effect_emitter_base *)v17;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v22,
      object);
    v3 = parent_query;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v21,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)parent_query,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v22.m_object,
      (const vostok::resources::memory_type *)v23,
      v24);
    v24 = result_fail;
    v23 = assert_on_fail_true;
    v22.m_object = (survarium::pure_game_effect_emitter_base *)3;
  }
  else
  {
    vostok::resources::check_queries_result(data);
    v3 = parent_query;
    v4 = (vostok::resources::query_result_for_cook *)v24;
    v24 = result_out_of_memory|0x8;
    v23 = assert_on_fail_true;
    v22.m_object = (survarium::pure_game_effect_emitter_base *)1;
  }
  vostok::resources::query_result_for_cook::finish_query_impl(
    v4,
    v3,
    (vostok::resources::cook_base::result_enum)v22.m_object,
    v23,
    v24);
}
