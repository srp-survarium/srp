void __thiscall vostok::animation::bi_spline_skeleton_animation_baked_cook::create_resource(
        vostok::animation::bi_spline_skeleton_animation_baked_cook *this,
        vostok::resources::query_result_for_cook *in_out_query,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::vfs::base_node<1> *file_size; // eax
  const char *m_data; // eax
  vostok::configs::binary_config *v5; // esi
  vostok::resources::query_result_for_cook *v6; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp-Ch] [ebp-1Ch] BYREF
  const vostok::resources::memory_type *v8; // [esp-8h] [ebp-18h]
  vostok::vfs::base_node<1> *v9; // [esp-4h] [ebp-14h]
  _DWORD v10[2]; // [esp+8h] [ebp-8h] BYREF

  v10[0] = 0;
  if ( in_out_query->m_fat_it.m_node )
  {
    file_size = (vostok::vfs::base_node<1> *)vostok::vfs::vfs_iterator::get_file_size(&in_out_query->m_fat_it);
  }
  else
  {
    m_data = in_out_query->m_creation_data_from_user.m_data;
    v10[1] = in_out_query->m_creation_data_from_user.m_size;
    v10[0] = m_data;
    file_size = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)v10);
  }
  vostok::animation::create_baked_animation_in_place(
    in_out_unmanaged_resource_buffer.m_data + 272,
    (const unsigned int)file_size);
  v5 = (vostok::configs::binary_config *)in_out_unmanaged_resource_buffer.m_data;
  if ( in_out_unmanaged_resource_buffer.m_data )
  {
    vostok::resources::unmanaged_resource::unmanaged_resource(
      (vostok::resources::unmanaged_resource *)in_out_unmanaged_resource_buffer.m_data,
      1u);
    v5->__vftable = (vostok::configs::binary_config_vtbl *)&vostok::animation::bi_spline_skeleton_animation_baked::`vftable';
    v5->m_root = 0;
  }
  else
  {
    v5 = 0;
  }
  v9 = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&in_out_unmanaged_resource_buffer);
  v8 = &vostok::resources::managed_memory;
  v7.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v7,
    v5);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    in_out_query,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v7.m_object,
    v8,
    (unsigned int)v9);
  vostok::resources::query_result_for_cook::finish_query_impl(v6, result_success, assert_on_fail_true, error_type_unset);
}
