void __thiscall vostok::core::configs::binary_config_cook_impl::create_resource(
        vostok::core::configs::binary_config_cook_impl *this,
        vostok::resources::query_result_for_cook *in_out_query,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  char *m_data; // esi
  const unsigned __int8 *v5; // eax
  vostok::configs::binary_config *v6; // eax
  vostok::configs::binary_config *v7; // esi
  vostok::resources::query_result_for_cook *v8; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp-Ch] [ebp-18h] BYREF
  const vostok::resources::memory_type *v10; // [esp-8h] [ebp-14h]
  vostok::vfs::base_node<1> *v11; // [esp-4h] [ebp-10h]
  int v12; // [esp+8h] [ebp-4h]

  v12 = 0;
  m_data = in_out_unmanaged_resource_buffer.m_data;
  if ( in_out_unmanaged_resource_buffer.m_data )
  {
    v11 = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&raw_file_data);
    v5 = (const unsigned __int8 *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&raw_file_data);
    vostok::core::configs::binary_config::binary_config(
      (vostok::core::configs::binary_config *)m_data,
      v5,
      (unsigned int)v11,
      &vostok::memory::g_resources_unmanaged_allocator);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  v11 = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&in_out_unmanaged_resource_buffer);
  v10 = &vostok::resources::nocache_memory;
  v9.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v9,
    v7);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    in_out_query,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v9.m_object,
    v10,
    (unsigned int)v11);
  vostok::resources::query_result_for_cook::finish_query_impl(v8, result_success, assert_on_fail_true, error_type_unset);
}
