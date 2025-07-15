char __userpurge survarium::lobby_client::read_enumerate_inventory_info@<al>(
        vostok::network_core::packet_reader *reader@<edi>,
        survarium::lobby_client *this)
{
  const unsigned __int8 *m_pointer; // eax
  unsigned int v3; // ebx
  survarium::inventory_item_instance __x; // [esp+10h] [ebp-10h] BYREF

  m_pointer = reader->m_pointer;
  v3 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  memset(&__x, 0, 14);
  stlp_std::priv::_Impl_vector<survarium::inventory_item_instance,vostok::vectora_allocator<survarium::inventory_item_instance>>::resize(
    &this->m_inventory_item_instances._M_impl,
    v3,
    &__x);
  if ( v3 )
  {
    memcpy(
      (unsigned __int8 *)this->m_inventory_item_instances._M_impl._M_start,
      (unsigned __int8 *)reader->m_pointer,
      16 * v3);
    reader->m_pointer += 16 * v3;
  }
  return 1;
}
