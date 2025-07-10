int __usercall vostok::memory::compare@<eax>(
        vostok::vfs::vfs_iterator *buffer2@<eax>,
        vostok::vfs::vfs_iterator *buffer1)
{
  vostok::vfs::base_node<1> *v3; // esi
  vostok::vfs::base_node<1> *v5; // esi
  vostok::vfs::base_node<1> *v6; // esi
  vostok::sound::encoded_sound_interface *v7; // edi
  vostok::sound::encoded_sound_interface *v8; // ecx
  int v9; // eax

  v3 = vostok::mutable_buffer::size(buffer1);
  if ( v3 < vostok::mutable_buffer::size(buffer2) )
    return -1;
  v5 = vostok::mutable_buffer::size(buffer1);
  if ( vostok::mutable_buffer::size(buffer2) < v5 )
    return 1;
  if ( !vostok::mutable_buffer::size(buffer1) )
    return 0;
  v6 = vostok::mutable_buffer::size(buffer1);
  v7 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)buffer2);
  v8 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)buffer1);
  if ( (unsigned int)v6 < 4 )
  {
LABEL_9:
    if ( !v6 )
      return 0;
  }
  else
  {
    while ( v8->__vftable == v7->__vftable )
    {
      v6 = (vostok::vfs::base_node<1> *)((char *)v6 - 4);
      v7 = (vostok::sound::encoded_sound_interface *)((char *)v7 + 4);
      v8 = (vostok::sound::encoded_sound_interface *)((char *)v8 + 4);
      if ( (unsigned int)v6 < 4 )
        goto LABEL_9;
    }
  }
  v9 = LOBYTE(v8->__vftable) - LOBYTE(v7->__vftable);
  if ( v9 )
    return (v9 >> 31) | 1;
  if ( (unsigned int)v6 <= 1 )
    return 0;
  v9 = BYTE1(v8->__vftable) - BYTE1(v7->__vftable);
  if ( v9 )
    return (v9 >> 31) | 1;
  if ( (unsigned int)v6 <= 2 )
    return 0;
  v9 = BYTE2(v8->__vftable) - BYTE2(v7->__vftable);
  if ( v9 )
    return (v9 >> 31) | 1;
  if ( (unsigned int)v6 > 3 )
  {
    v9 = HIBYTE(v8->__vftable) - HIBYTE(v7->__vftable);
    return (v9 >> 31) | 1;
  }
  return 0;
}
