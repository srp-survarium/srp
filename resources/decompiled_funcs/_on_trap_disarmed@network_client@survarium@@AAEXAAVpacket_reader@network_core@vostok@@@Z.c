void __usercall survarium::network_client::on_trap_disarmed(
        survarium::network_client *this@<esi>,
        vostok::network_core::packet_reader *packet@<eax>)
{
  const unsigned __int8 *m_pointer; // edx
  char v3; // cl
  unsigned __int8 v4; // bl
  unsigned __int8 v5; // cl
  unsigned __int8 index; // [esp+9h] [ebp-5h]
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> player; // [esp+Ah] [ebp-4h] BYREF

  m_pointer = packet->m_pointer;
  v3 = *m_pointer++;
  packet->m_pointer = m_pointer;
  LOBYTE(player.m_object) = v3;
  v4 = *m_pointer++;
  packet->m_pointer = m_pointer;
  v5 = *m_pointer;
  packet->m_pointer = m_pointer + 1;
  index = v5;
  this->get_player(this, &player, (const unsigned __int8)player.m_object);
  survarium::booby_trap_set::on_trap_disarmed_message(
    (survarium::booby_trap_set *)player.m_object->m_inventory.m_object->m_slots[v4].item.m_object,
    index);
  if ( player.m_object && !_InterlockedExchangeAdd(&player.m_object->m_reference_count, 0xFFFFFFFF) )
  {
    if ( player.m_object )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &player.m_object->vostok::resources::unmanaged_intrusive_base,
        &player.m_object->vostok::resources::unmanaged_resource);
    else
      vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)0x1F0, 0);
  }
}
