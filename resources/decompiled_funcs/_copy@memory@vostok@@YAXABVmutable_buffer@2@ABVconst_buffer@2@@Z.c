void __usercall vostok::memory::copy(
        vostok::vfs::vfs_iterator *destination@<edi>,
        vostok::vfs::vfs_iterator *source@<eax>)
{
  unsigned __int8 *m_hashset; // ebx
  vostok::vfs::base_node<1> *v4; // ebp
  unsigned __int8 *v5; // esi

  m_hashset = (unsigned __int8 *)destination->m_hashset;
  v4 = vostok::mutable_buffer::size(source);
  v5 = (unsigned __int8 *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)source);
  vostok::mutable_buffer::size(destination);
  memcpy(m_hashset, v5, (unsigned int)v4);
}
