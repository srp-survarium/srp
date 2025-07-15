void __thiscall vostok::render::skeleton_model_instance_cook::on_all_subresources_ready(
        vostok::render::skeleton_model_instance_cook *this,
        vostok::render::skeleton_model_instance_cook_data *cook_data)
{
  vostok::memory::doug_lea_allocator *v2; // esi
  char *v3; // eax
  vostok::memory::doug_lea_allocator *v4; // ecx
  char *v5; // eax
  vostok::render::skeleton_model_instance *v6; // ecx
  survarium::pure_game_effect_emitter_base *v7; // eax
  vostok::buffer_vector<vostok::math::float4x4> *p_unlink_child_resource; // ebx
  vostok::math::float4x4 *v9; // ecx
  int v10; // eax
  vostok::math::float4x4 *v11; // eax
  vostok::math::float4x4 *v12; // edi
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v13; // edi
  vostok::resources::query_result_for_cook *v14; // ecx
  vostok::resources::query_result_for_cook *v15; // ecx
  vostok::memory::doug_lea_allocator *v16; // esi
  vostok::memory::doug_lea_allocator *v17; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v18; // [esp-Ch] [ebp-6Ch] BYREF
  const vostok::resources::memory_type *v19; // [esp-8h] [ebp-68h]
  unsigned int v20; // [esp-4h] [ebp-64h]
  const char *v21; // [esp+0h] [ebp-60h]
  const char *v22; // [esp+4h] [ebp-5Ch]
  unsigned int v23; // [esp+8h] [ebp-58h]
  survarium::pure_game_effect_emitter_base *object; // [esp+10h] [ebp-50h]
  unsigned int v25; // [esp+14h] [ebp-4Ch]
  unsigned int v26; // [esp+18h] [ebp-48h]
  vostok::resources::query_result_for_cook *parent_query; // [esp+1Ch] [ebp-44h]
  vostok::math::float4x4 v28; // [esp+20h] [ebp-40h] BYREF

  v2 = vostok::render::g_allocator;
  parent_query = cook_data->parent_query;
  v3 = type_info::raw_name(&vostok::render::skeleton_model_instance `RTTI Type Descriptor');
  v5 = vostok::memory::doug_lea_allocator::malloc_impl(v4, (int)v2, 0x110u, v3, v21, v22, v23);
  if ( v5 )
  {
    vostok::render::skeleton_model_instance::skeleton_model_instance(v6, v5);
    object = v7;
  }
  else
  {
    object = 0;
  }
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&cook_data->render_model,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&object[1]);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&cook_data->skeleton,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&object[1].type);
  p_unlink_child_resource = (vostok::buffer_vector<vostok::math::float4x4> *)&object[1].__vftable[275].unlink_child_resource;
  vostok::buffer_vector<vostok::math::float4x4>::resize(
    p_unlink_child_resource,
    (*((_DWORD *)object[1].__vftable[788].log_string + 81) - *((_DWORD *)object[1].__vftable[788].log_string + 80)) >> 6);
  v10 = (char *)p_unlink_child_resource->m_end - (char *)p_unlink_child_resource->m_begin;
  v26 = 0;
  if ( v10 >> 6 )
  {
    v25 = 0;
    do
    {
      v11 = vostok::math::float4x4::identity(v9, &v28);
      v12 = &p_unlink_child_resource->m_begin[v25 / 0x40];
      ++v26;
      v25 += 64;
      qmemcpy(v12, v11, sizeof(vostok::math::float4x4));
      v9 = 0;
    }
    while ( v26 < p_unlink_child_resource->m_end - p_unlink_child_resource->m_begin );
  }
  v20 = 272;
  v19 = &vostok::resources::nocache_memory;
  v18.m_object = (survarium::pure_game_effect_emitter_base *)v9;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v18,
    object);
  v13 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent_query;
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v14,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)parent_query,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v18.m_object,
    v19,
    v20);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v15,
    v13,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
  v16 = vostok::render::g_allocator;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&cook_data->skeleton);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&cook_data->render_model);
  vostok::memory::doug_lea_allocator::free_impl(v17, (int)v16, (char *)&cook_data->render_model_ready, v21, v22, v23);
}
