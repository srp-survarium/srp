void __userpurge vostok::resources::query_result::unpin_raw_file(
        vostok::resources::query_result *this@<ecx>,
        int a2@<edi>,
        vostok::vfs::vfs_iterator *pinned_raw_file)
{
  char *v3; // esi
  vostok::sound::encoded_sound_interface *v4; // eax
  vostok::resources::query_result *v5; // ecx
  vostok::mutable_buffer v6; // [esp+8h] [ebp-8h] BYREF

  v3 = (char *)vostok::mutable_buffer::size(pinned_raw_file) + *(_DWORD *)(a2 + 672);
  v4 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)pinned_raw_file);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    &v6,
    (unsigned __int8 *)v4 - *(_DWORD *)(a2 + 672),
    (unsigned int)v3);
  vostok::resources::query_result::unpin_raw_buffer(
    v5,
    a2,
    (vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v6);
}
