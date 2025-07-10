char __usercall vostok::resources::query_result::check_file_crc@<al>(
        vostok::resources::query_result *this@<ecx>,
        vostok::vfs::vfs_iterator *a2@<esi>)
{
  vostok::resources::query_result *v2; // ecx
  const char *v4; // eax
  unsigned int v5; // ebx
  unsigned int file_hash; // ebp
  char *v7; // edi
  vostok::sound::encoded_sound_interface *v8; // eax
  vostok::resources::query_result *v9; // ecx
  unsigned int raw_file_size; // [esp-8h] [ebp-2Ch]
  vostok::const_buffer pinned_file; // [esp+10h] [ebp-14h] BYREF
  vostok::mutable_buffer v12; // [esp+18h] [ebp-Ch] BYREF

  if ( !vostok::vfs::vfs_iterator::is_archive(a2 + 10) )
    return 1;
  vostok::resources::query_result::pin_compressed_or_raw_file(v2, a2, &pinned_file);
  raw_file_size = vostok::vfs::vfs_iterator::get_raw_file_size(a2 + 10);
  v4 = (const char *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&pinned_file);
  v5 = vostok::fs_new::crc32(v4, raw_file_size, 0);
  file_hash = vostok::vfs::vfs_iterator::get_file_hash(a2 + 10);
  if ( a2[10].m_node && vostok::vfs::vfs_iterator::is_compressed(a2 + 10) )
  {
    vostok::resources::query_result::unpin_compressed_file(
      (vostok::resources::query_result *)&pinned_file,
      (int)a2,
      (vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&pinned_file);
    return v5 == file_hash;
  }
  else
  {
    v7 = (char *)a2[42].m_hashset
       + (unsigned int)vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&pinned_file);
    v8 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&pinned_file);
    boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
      &v12,
      (unsigned __int8 *)((char *)v8 - (char *)a2[42].m_hashset),
      (unsigned int)v7);
    vostok::resources::query_result::unpin_raw_buffer(
      v9,
      (int)a2,
      (vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v12);
    return v5 == file_hash;
  }
}
