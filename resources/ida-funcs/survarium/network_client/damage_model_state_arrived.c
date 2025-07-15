void __usercall survarium::network_client::damage_model_state_arrived(
        survarium::network_client *this@<ecx>,
        vostok::network_core::packet_reader *packet@<esi>)
{
  const unsigned __int8 *m_pointer; // eax
  survarium::player *m_object; // edx
  const vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> *v4; // eax
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> player; // [esp+8h] [ebp-4h] BYREF

  m_pointer = packet->m_pointer;
  LOBYTE(player.m_object) = *m_pointer;
  m_object = player.m_object;
  packet->m_pointer = m_pointer + 1;
  this->get_player(this, &player, (const unsigned __int8)m_object);
  v4 = player.m_object->damage_model(player.m_object);
  survarium::damage_model::deserialize(v4->m_object, packet);
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
