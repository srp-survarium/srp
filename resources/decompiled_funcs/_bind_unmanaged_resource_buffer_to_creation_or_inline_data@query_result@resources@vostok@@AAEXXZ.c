void __usercall vostok::resources::query_result::bind_unmanaged_resource_buffer_to_creation_or_inline_data(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>)
{
  vostok::vfs::base_node<1> *v2; // eax
  unsigned __int8 *v3; // eax
  unsigned int m_size; // edx
  unsigned __int8 *v5; // eax
  unsigned int v6; // ecx
  vostok::vfs::base_node<1> *v7; // [esp-4h] [ebp-20h]
  vostok::vfs::base_node<1> *v8; // [esp-4h] [ebp-20h]
  vostok::const_buffer inline_data; // [esp+8h] [ebp-14h] BYREF
  vostok::mutable_buffer v10; // [esp+10h] [ebp-Ch] BYREF

  if ( *(_DWORD *)(a2 + 164)
    && (v2 = vostok::vfs::vfs_iterator::data_node((vostok::vfs::vfs_iterator *)(a2 + 160)),
        vostok::vfs::base_node<1>::is_inlined(v2))
    && !vostok::vfs::vfs_iterator::is_compressed((vostok::vfs::vfs_iterator *)(a2 + 160)) )
  {
    vostok::const_buffer::const_buffer((vostok::mutable_buffer *)&inline_data);
    vostok::vfs::vfs_iterator::get_inline_data((vostok::vfs::vfs_iterator *)(a2 + 160), &inline_data);
    v7 = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&inline_data);
    v3 = (unsigned __int8 *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&inline_data);
    boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
      &v10,
      v3,
      (unsigned int)v7);
    m_size = v10.m_size;
    *(_DWORD *)(a2 + 636) = v10.m_data;
    *(_DWORD *)(a2 + 640) = m_size;
  }
  else
  {
    v8 = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)(a2 + 208));
    v5 = (unsigned __int8 *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 208));
    boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
      &v10,
      v5,
      (unsigned int)v8);
    v6 = v10.m_size;
    *(_DWORD *)(a2 + 636) = v10.m_data;
    *(_DWORD *)(a2 + 640) = v6;
  }
}
