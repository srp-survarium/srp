void __thiscall vostok::collision::collision_cook::on_triangle_mesh_collision_loaded(
        vostok::collision::collision_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent_query)
{
  vostok::resources::pinned_ptr_mutable<unsigned char> *v3; // ecx
  vostok::resources::managed_resource *v4; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v5; // ecx
  vostok::memory::chunk_reader *v6; // ecx
  vostok::memory::chunk_reader *v7; // ecx
  vostok::memory::chunk_reader *v8; // ecx
  vostok::memory::chunk_reader *v9; // ecx
  vostok::collision::geometry *v10; // eax
  survarium::pure_game_effect_emitter_base *v11; // ecx
  vostok::particle::particle_system_instance_impl *v12; // esi
  vostok::resources::query_result_for_cook *v13; // ecx
  vostok::resources::query_result_for_cook *v14; // ecx
  vostok::resources::pinned_ptr_const<unsigned char> *v15; // ecx
  vostok::resources::pinned_ptr_const<unsigned char> *v16; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v17; // [esp-Ch] [ebp-8Ch] BYREF
  const vostok::resources::memory_type *v18; // [esp-8h] [ebp-88h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v19; // [esp-4h] [ebp-84h] BYREF
  vostok::memory::chunk_reader::chunk_type v20; // [esp+0h] [ebp-80h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v21; // [esp+Ch] [ebp-74h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v22; // [esp+10h] [ebp-70h] BYREF
  unsigned __int8 *v23; // [esp+14h] [ebp-6Ch]
  unsigned int v24; // [esp+18h] [ebp-68h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr; // [esp+1Ch] [ebp-64h] BYREF
  unsigned __int8 *dataa; // [esp+20h] [ebp-60h]
  unsigned int size; // [esp+24h] [ebp-5Ch]
  const unsigned __int8 *v28[3]; // [esp+28h] [ebp-58h] BYREF
  const unsigned __int8 *v29[3]; // [esp+34h] [ebp-4Ch] BYREF
  vostok::memory::chunk_reader v30; // [esp+40h] [ebp-40h] BYREF
  vostok::memory::chunk_reader v31; // [esp+60h] [ebp-20h] BYREF

  if ( data->m_result == 1 )
  {
    v19.m_object = (vostok::resources::managed_resource *)this;
    vostok::resources::query_result_for_user::get_managed_resource(&data->m_queries[0], &v19);
    vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
      v3,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&ptr,
      v19);
    v19.m_object = v4;
    vostok::resources::query_result_for_user::get_managed_resource(&data->m_queries[1], &v19);
    vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
      v5,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&v22,
      v19);
    vostok::memory::chunk_reader::chunk_reader(&v30, dataa, v6, size, v20);
    vostok::memory::chunk_reader::chunk_reader(&v31, v23, v7, v24, v20);
    vostok::memory::chunk_reader::open_reader(v8, &v30, v29, (vostok::memory::chunk_reader::chunk_type *)0x19, v20);
    vostok::memory::chunk_reader::open_reader(v9, &v31, v28, (vostok::memory::chunk_reader::chunk_type *)0x1A, v20);
    v10 = vostok::collision::new_triangle_mesh_geometry(
            &vostok::memory::g_resources_unmanaged_allocator,
            (const vostok::math::float3 *)v29[1],
            (unsigned int)v29[2] / 0xC,
            (const unsigned int *)v28[1],
            (unsigned int)v28[2] >> 2);
    v21.m_object = 0;
    v12 = (vostok::particle::particle_system_instance_impl *)v10;
    if ( v10 )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v21);
      v21.m_object = v12;
      v11 = (survarium::pure_game_effect_emitter_base *)_InterlockedExchangeAdd(&v12->m_reference_count, 1u);
    }
    v19.m_object = (vostok::resources::managed_resource *)320;
    v18 = &vostok::resources::nocache_memory;
    v17.m_object = v11;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v17,
      (survarium::pure_game_effect_emitter_base *)v21.m_object);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v13,
      parent_query,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v17.m_object,
      v18,
      (unsigned int)v19.m_object);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v14,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent_query,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v21);
    vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(v15);
    vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(v16);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
