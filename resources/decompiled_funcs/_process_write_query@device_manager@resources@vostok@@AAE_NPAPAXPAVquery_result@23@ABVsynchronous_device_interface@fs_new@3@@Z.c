char __userpurge vostok::resources::device_manager::process_write_query@<al>(
        vostok::vfs::vfs_iterator *query@<esi>,
        vostok::resources::device_manager *this,
        vostok::fs_new::synchronous_device_interface *file,
        const vostok::fs_new::synchronous_device_interface *device)
{
  vostok::resources::query_result *file_offs; // edi
  char v5; // al
  bool v6; // bl
  int v7; // edx
  vostok::resources::query_result *v8; // ecx
  unsigned __int8 *v9; // eax
  vostok::resources::query_result *v10; // ecx
  char *v11; // edi
  vostok::sound::encoded_sound_interface *v12; // eax
  vostok::mutable_buffer v14; // [esp-4h] [ebp-7Ch] BYREF
  bool v15; // [esp+4h] [ebp-74h]
  vostok::uninitialized_reference<vostok::resources::pinned_ptr_const<unsigned char> > resource_to_save; // [esp+8h] [ebp-70h] BYREF
  vostok::vfs::vfs_iterator fat_it; // [esp+20h] [ebp-58h] BYREF
  vostok::const_buffer result; // [esp+30h] [ebp-48h] BYREF
  vostok::mutable_buffer v19; // [esp+38h] [ebp-40h] BYREF
  unsigned __int64 file_pos; // [esp+40h] [ebp-38h]
  vostok::mutable_buffer v21; // [esp+48h] [ebp-30h] BYREF
  vostok::mutable_buffer v22; // [esp+50h] [ebp-28h] BYREF
  vostok::const_buffer v23; // [esp+58h] [ebp-20h] BYREF
  vostok::const_buffer v24; // [esp+60h] [ebp-18h] BYREF
  vostok::const_buffer src_data; // [esp+68h] [ebp-10h] BYREF
  vostok::resources::save_generated_data *data; // [esp+70h] [ebp-8h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> resource; // [esp+74h] [ebp-4h] BYREF
  char out_result_3; // [esp+87h] [ebp+Fh]

  vostok::const_buffer::const_buffer((vostok::mutable_buffer *)&src_data);
  file_offs = 0;
  v5 = (int)query[43].m_hashset & 8;
  v6 = v5 == 8;
  resource_to_save.m_variable = (vostok::resources::pinned_ptr_const<unsigned char> *)&resource_to_save;
  resource_to_save.m_initialized = 0;
  HIDWORD(file_pos) = 0;
  resource_to_save.m_construction_started = 0;
  if ( v5 == 8 )
  {
    data = (vostok::resources::save_generated_data *)query[14].m_hashset;
    vostok::const_buffer::const_buffer(&v24, &data->m_data);
    if ( v24.m_data || v24.m_size )
    {
      vostok::const_buffer::const_buffer(&v23, &data->m_data);
      src_data = v23;
    }
    else
    {
      resource.m_object = 0;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
        &resource,
        &data->m_resource);
      v14.m_data = 0;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v14,
        &resource);
      vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
        (vostok::resources::pinned_ptr_const<unsigned char> *)&resource_to_save,
        (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v14.m_data);
      _InterlockedExchange(&resource_to_save.m_initialized, 1);
      boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
        &v22,
        (unsigned __int8 *)resource_to_save.m_variable->m_data,
        resource_to_save.m_variable->m_size);
      src_data = (vostok::const_buffer)v22;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&resource);
    }
  }
  else
  {
    vostok::vfs::vfs_iterator::vfs_iterator(&fat_it, query + 10);
    file_offs = (vostok::resources::query_result *)vostok::vfs::vfs_iterator::get_file_offs(&fat_it);
    HIDWORD(file_pos) = v7;
    src_data = *vostok::resources::query_result::pin_compressed_or_raw_file(v8, query, &result);
  }
  v14.m_data = (char *)vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&src_data);
  v9 = (unsigned __int8 *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_data);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    &v21,
    v9,
    (unsigned int)v14.m_data);
  v14.m_data = (char *)v21.m_size;
  out_result_3 = vostok::resources::device_manager::do_async_operation(
                   (void **)&this->__vftable,
                   file,
                   (vostok::resources::device_manager *)query,
                   file_offs,
                   __PAIR64__((unsigned int)v21.m_data, HIDWORD(file_pos)),
                   v14,
                   v15);
  if ( !v6 )
  {
    if ( query[10].m_node && vostok::vfs::vfs_iterator::is_compressed(query + 10) )
    {
      vostok::resources::query_result::unpin_compressed_file(
        v10,
        (int)query,
        (vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_data);
    }
    else
    {
      v11 = (char *)query[42].m_hashset
          + (unsigned int)vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&src_data);
      v12 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_data);
      boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
        &v19,
        (unsigned __int8 *)((char *)v12 - (char *)query[42].m_hashset),
        (unsigned int)v11);
      vostok::resources::query_result::unpin_raw_buffer(
        (vostok::resources::query_result *)&v19,
        (int)query,
        (vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v19);
    }
  }
  if ( resource_to_save.m_initialized )
  {
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)resource_to_save.m_variable);
    resource_to_save.m_initialized = 0;
  }
  return out_result_3;
}
