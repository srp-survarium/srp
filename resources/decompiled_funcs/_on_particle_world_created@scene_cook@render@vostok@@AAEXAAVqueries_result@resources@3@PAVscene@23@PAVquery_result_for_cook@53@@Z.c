void __thiscall vostok::render::scene_cook::on_particle_world_created(
        vostok::render::scene_cook *this,
        vostok::resources::queries_result *result,
        vostok::configs::binary_config *created_resource,
        vostok::resources::query_result_for_cook *in_out_query)
{
  vostok::configs::binary_config *m_object; // edi
  vostok::configs::binary_config *v5; // eax
  vostok::particle::world *v6; // ecx
  vostok::particle::world *m_class_id; // eax
  vostok::particle::world *v8; // eax
  vostok::resources::query_result_for_cook *v9; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp-Ch] [ebp-1Ch] BYREF
  const vostok::resources::memory_type *v11; // [esp-8h] [ebp-18h]
  unsigned int v12; // [esp-4h] [ebp-14h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13; // [esp+Ch] [ebp-4h] BYREF

  v13.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v13,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result->m_queries[0].m_unmanaged_resource);
  m_object = v13.m_object;
  v5 = 0;
  if ( v13.m_object )
  {
    v5 = v13.m_object;
    _InterlockedExchangeAdd(&v13.m_object->m_reference_count, 1u);
  }
  v6 = (vostok::particle::world *)v5;
  m_class_id = (vostok::particle::world *)created_resource[3].m_class_id;
  created_resource[3].m_class_id = (vostok::resources::class_id_enum)v6;
  if ( m_class_id && !_InterlockedExchangeAdd(&m_class_id->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_class_id->vostok::resources::unmanaged_intrusive_base,
      m_class_id);
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  v8 = (vostok::particle::world *)created_resource[3].m_class_id;
  v12 = 976;
  v11 = &vostok::resources::nocache_memory;
  *((_DWORD *)&created_resource[2].m_memory_type_data + 1) = v8;
  v10.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v10,
    created_resource);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    in_out_query,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v10.m_object,
    v11,
    v12);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v9,
    (int)in_out_query,
    result_success,
    assert_on_fail_true,
    0);
}
