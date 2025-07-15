void __thiscall vostok::collision::collision_cook::on_triangle_mesh_collision_loaded(
        vostok::collision::collision_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::query_result_for_cook *parent_query)
{
  unsigned int v3; // edi
  unsigned int v4; // esi
  vostok::collision::triangle_mesh_buffer *v5; // ecx
  vostok::configs::binary_config *v6; // eax
  vostok::configs::binary_config *v7; // esi
  vostok::resources::query_result_for_cook *v8; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp-Ch] [ebp-84h] BYREF
  const vostok::resources::memory_type *v10; // [esp-8h] [ebp-80h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v11; // [esp-4h] [ebp-7Ch] BYREF
  vostok::memory::chunk_reader::chunk_type *v12; // [esp+0h] [ebp-78h]
  unsigned int v13; // [esp+4h] [ebp-74h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> object; // [esp+10h] [ebp-68h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v15; // [esp+14h] [ebp-64h] BYREF
  unsigned int chunk_id; // [esp+18h] [ebp-60h] BYREF
  unsigned int v17; // [esp+1Ch] [ebp-5Ch] BYREF
  vostok::resources::pinned_ptr_const<unsigned char> indices_ptr; // [esp+20h] [ebp-58h] BYREF
  vostok::resources::pinned_ptr_const<unsigned char> vertices_ptr; // [esp+2Ch] [ebp-4Ch] BYREF
  vostok::memory::chunk_reader indices_chunk_reader; // [esp+38h] [ebp-40h] BYREF
  vostok::memory::chunk_reader vertices_chunk_reader; // [esp+58h] [ebp-20h] BYREF

  v15.m_object = 0;
  if ( data->m_result == 1 )
  {
    object.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &object,
      &data->m_queries[0].m_managed_resource);
    v11.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &v11,
      &object);
    vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
      &vertices_ptr,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v11.m_object);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
    v15.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &v15,
      &data->m_queries[1].m_managed_resource);
    v11.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &v11,
      &v15);
    vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
      &indices_ptr,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v11.m_object);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v15);
    vertices_chunk_reader.m_reader.m_data = vertices_ptr.m_data;
    vertices_chunk_reader.m_reader.m_pointer = vertices_ptr.m_data;
    indices_chunk_reader.m_reader.m_data = indices_ptr.m_data;
    indices_chunk_reader.m_reader.m_pointer = indices_ptr.m_data;
    vertices_chunk_reader.m_reader.m_size = vertices_ptr.m_size;
    memset(&vertices_chunk_reader.m_chunks, 0, 16);
    indices_chunk_reader.m_reader.m_size = indices_ptr.m_size;
    memset(&indices_chunk_reader.m_chunks, 0, 16);
    v3 = vostok::memory::chunk_reader::chunk_size(
           (vostok::memory::chunk_reader *)0x19,
           (const unsigned int)&chunk_id,
           v12);
    v4 = vostok::memory::chunk_reader::chunk_size((vostok::memory::chunk_reader *)0x1A, (const unsigned int)&v17, v12);
    v5 = (vostok::collision::triangle_mesh_buffer *)vostok::memory::g_resources_unmanaged_allocator.call_malloc(
                                                      &vostok::memory::g_resources_unmanaged_allocator,
                                                      352);
    if ( v5 )
      vostok::collision::triangle_mesh_buffer::triangle_mesh_buffer(
        v5,
        &vostok::memory::g_resources_unmanaged_allocator,
        (const vostok::math::float3 *)vertices_chunk_reader.m_reader.m_pointer,
        v3 / 0xC,
        (const unsigned int *)indices_chunk_reader.m_reader.m_pointer,
        v4 >> 2,
        (const unsigned int *)v12,
        v13);
    else
      v6 = 0;
    v7 = 0;
    if ( v6 )
    {
      v7 = v6;
      _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
    }
    v11.m_object = (vostok::resources::managed_resource *)320;
    v10 = &vostok::resources::nocache_memory;
    v9.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v9,
      v7);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      parent_query,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v9.m_object,
      v10,
      (unsigned int)v11.m_object);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v8,
      result_success,
      assert_on_fail_true,
      error_type_unset);
    if ( v7 )
    {
      if ( !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v7->vostok::resources::unmanaged_intrusive_base, v7);
    }
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&indices_ptr);
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&vertices_ptr);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      result_error,
      assert_on_fail_true,
      error_type_cook_failed);
  }
}
