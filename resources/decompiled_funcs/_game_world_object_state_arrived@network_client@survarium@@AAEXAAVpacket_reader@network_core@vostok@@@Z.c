void __usercall survarium::network_client::game_world_object_state_arrived(
        survarium::network_client *this@<ecx>,
        vostok::network_core::packet_reader *reader@<esi>)
{
  const unsigned __int8 *m_pointer; // eax
  survarium::player *m_object; // edx
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> player; // [esp+8h] [ebp-4h] BYREF

  m_pointer = reader->m_pointer;
  LOBYTE(player.m_object) = *m_pointer;
  m_object = player.m_object;
  reader->m_pointer = m_pointer + 1;
  this->get_player(this, &player, (const unsigned __int8)m_object);
  survarium::base_player::deserialize_game_world_object(player.m_object, reader);
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
