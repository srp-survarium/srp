void __userpurge vostok::resources::query_result::copy_data_to_resource(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>,
        vostok::const_buffer data)
{
  _DWORD *v4; // ebx
  unsigned __int8 *v5; // esi
  vostok::vfs::base_node<1> *v6; // eax
  unsigned __int8 **v7; // eax
  vostok::vfs::vfs_iterator *v8; // esi
  unsigned __int8 *v9; // edi
  vostok::vfs::base_node<1> *v10; // ebx
  unsigned __int8 *v11; // ebp
  bool v12; // zf
  const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v13; // eax
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v14; // ecx
  vostok::mutable_buffer *v15; // ecx
  vostok::vfs::vfs_iterator *v16; // esi
  unsigned __int8 *m_hashset; // edi
  vostok::vfs::base_node<1> *v18; // ebx
  unsigned __int8 *v19; // ebp
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v20; // [esp-4h] [ebp-40h] BYREF
  vostok::mutable_buffer object; // [esp+10h] [ebp-2Ch] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> dest_resource; // [esp+18h] [ebp-24h] BYREF
  vostok::mutable_buffer buffer; // [esp+1Ch] [ebp-20h] BYREF
  vostok::mutable_buffer result; // [esp+24h] [ebp-18h] BYREF
  vostok::resources::pinned_ptr_mutable<unsigned char> dest_buffer; // [esp+2Ch] [ebp-10h] BYREF

  v4 = (_DWORD *)(a2 + 636);
  if ( vostok::mutable_buffer::operator bool((vostok::mutable_buffer *)(a2 + 636)) )
  {
    v5 = (unsigned __int8 *)(*v4 + *(_DWORD *)(a2 + 672));
    v6 = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&data);
    boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
      &buffer,
      v5,
      (unsigned int)v6);
    v8 = (vostok::vfs::vfs_iterator *)v7;
    v9 = *v7;
    v10 = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&data);
    v11 = (unsigned __int8 *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
    vostok::mutable_buffer::size(v8);
    memcpy(v9, v11, (unsigned int)v10);
  }
  else
  {
    if ( !*(_DWORD *)(a2 + 164)
      || (v12 = !vostok::vfs::vfs_iterator::is_compressed((vostok::vfs::vfs_iterator *)(a2 + 160)),
          v13 = (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 628),
          v12) )
    {
      v13 = (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 632);
    }
    dest_resource.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &dest_resource,
      v13);
    object.m_data = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&object,
      &dest_resource);
    v20.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &v20,
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&object);
    vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
      v14,
      &dest_buffer.m_resource,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v20.m_object);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&object);
    boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
      &object,
      (unsigned __int8 *)dest_buffer.m_data,
      dest_buffer.m_size);
    v15 = *(vostok::mutable_buffer **)(a2 + 672);
    buffer = object;
    v16 = (vostok::vfs::vfs_iterator *)vostok::operator+(&result, &buffer, v15);
    m_hashset = (unsigned __int8 *)v16->m_hashset;
    v18 = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&data);
    v19 = (unsigned __int8 *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
    vostok::mutable_buffer::size(v16);
    memcpy(m_hashset, v19, (unsigned int)v18);
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&dest_buffer);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&dest_resource);
  }
}
