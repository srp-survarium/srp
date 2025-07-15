void __thiscall vostok::core::configs::binary_config_cook::on_binary_config_loaded(
        vostok::core::configs::binary_config_cook *this,
        vostok::configs::binary_config *data,
        vostok::resources::query_result_for_cook *parent_query)
{
  vostok::configs::binary_config *m_object; // esi
  vostok::resources::unmanaged_resource *v4; // esi
  vostok::resources::query_result_for_cook *v5; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v6; // [esp-Ch] [ebp-18h] BYREF
  const vostok::resources::memory_type *v7; // [esp-8h] [ebp-14h]
  unsigned int v8; // [esp-4h] [ebp-10h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+8h] [ebp-4h] BYREF

  v9.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v9,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data[1].m_reconstruction_size
  + 1);
  m_object = v9.m_object;
  data = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
    v9.m_object);
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  v4 = data;
  v8 = 280;
  v7 = &vostok::resources::nocache_memory;
  v6.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v6,
    data);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    parent_query,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v6.m_object,
    v7,
    v8);
  vostok::resources::query_result_for_cook::finish_query_impl(v5, result_success, assert_on_fail_true, error_type_unset);
  if ( v4 )
  {
    if ( !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
  }
}
