void __thiscall vostok::resources::unmanaged_allocation_cook::create_resource(
        vostok::resources::unmanaged_allocation_cook *this,
        vostok::resources::query_result_for_cook *in_out_query,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::configs::binary_config *m_data; // esi
  vostok::vfs::base_node<1> *v5; // edi
  vostok::resources::query_result_for_cook *v6; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp-Ch] [ebp-18h] BYREF
  const vostok::resources::memory_type *v8; // [esp-8h] [ebp-14h]
  vostok::vfs::base_node<1> *v9; // [esp-4h] [ebp-10h]
  int v10; // [esp+8h] [ebp-4h]

  m_data = (vostok::configs::binary_config *)in_out_unmanaged_resource_buffer.m_data;
  v10 = 0;
  if ( in_out_unmanaged_resource_buffer.m_data )
  {
    v5 = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&raw_file_data);
    vostok::resources::unmanaged_resource::unmanaged_resource(m_data, 1u);
    m_data->__vftable = (vostok::configs::binary_config_vtbl *)&vostok::resources::unmanaged_allocation_resource::`vftable';
    m_data->m_root = (vostok::configs::binary_config_value *)v5;
  }
  else
  {
    m_data = 0;
  }
  v9 = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&in_out_unmanaged_resource_buffer);
  v8 = &vostok::resources::unmanaged_memory;
  v7.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v7,
    m_data);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    in_out_query,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v7.m_object,
    v8,
    (unsigned int)v9);
  vostok::resources::query_result_for_cook::finish_query_impl(v6, result_success, assert_on_fail_true, error_type_unset);
}
