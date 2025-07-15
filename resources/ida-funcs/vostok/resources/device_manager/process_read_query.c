char __userpurge vostok::resources::device_manager::process_read_query@<al>(
        vostok::vfs::vfs_iterator *query@<esi>,
        vostok::resources::device_manager *this,
        vostok::fs_new::synchronous_device_interface *file,
        const vostok::fs_new::synchronous_device_interface *device)
{
  vostok::resources::query_result *file_offs; // ebx
  unsigned int v5; // edx
  unsigned int v6; // ebp
  vostok::vfs::vfs_iterator *v7; // edi
  unsigned __int8 *v8; // eax
  char v9; // bl
  vostok::mutable_buffer v11; // [esp-4h] [ebp-38h]
  bool v12; // [esp+4h] [ebp-30h]
  vostok::mutable_buffer file_data; // [esp+10h] [ebp-24h] BYREF
  vostok::const_buffer result; // [esp+18h] [ebp-1Ch] BYREF
  vostok::vfs::vfs_iterator fat_it; // [esp+20h] [ebp-14h] BYREF

  vostok::vfs::vfs_iterator::vfs_iterator(&fat_it, query + 10);
  file_offs = (vostok::resources::query_result *)vostok::vfs::vfs_iterator::get_file_offs(&fat_it);
  v6 = v5;
  v7 = (vostok::vfs::vfs_iterator *)vostok::resources::query_result::pin_compressed_or_raw_file(
                                      (vostok::resources::query_result *)&result,
                                      query,
                                      &result);
  v11.m_data = (char *)vostok::mutable_buffer::size(v7);
  v8 = (unsigned __int8 *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v7);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    &file_data,
    v8,
    (unsigned int)v11.m_data);
  v11.m_data = (char *)file_data.m_size;
  v9 = vostok::resources::device_manager::do_async_operation(
         (void **)&this->__vftable,
         file,
         (vostok::resources::device_manager *)query,
         file_offs,
         __PAIR64__((unsigned int)file_data.m_data, v6),
         v11,
         v12);
  if ( v9 )
    query[42].m_node = (vostok::vfs::base_node<1> *)((char *)query[42].m_node
                                                   + (unsigned int)vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&file_data));
  return v9;
}
