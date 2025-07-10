void __userpurge survarium::network_client::process_player_respawn(
        vostok::network_core::packet_reader *packet@<eax>,
        survarium::network_client *this)
{
  survarium::network_client *v2; // ebp
  const unsigned __int8 *m_pointer; // eax
  unsigned __int8 v5; // bl
  survarium::network_client *v6; // ecx
  survarium::network_client *v7; // eax
  survarium::base_network_client *v8; // ecx
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> v9; // [esp-4h] [ebp-14h] BYREF

  v2 = this;
  m_pointer = packet->m_pointer;
  LOBYTE(this) = *m_pointer;
  v5 = (unsigned __int8)this;
  v6 = this;
  packet->m_pointer = m_pointer + 1;
  v2->get_player(
    v2,
    (vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)&this,
    (const unsigned __int8)v6);
  ((void (__thiscall *)(survarium::network_client *, vostok::network_core::packet_reader *))this->__vftable[1].disconnect)(
    this,
    packet);
  if ( !v2->m_net_players.elems[v5].is_connected )
    v2->m_net_players.elems[v5].is_connected = 1;
  v7 = this;
  if ( this->m_login_client.m_sign_up_info.account_name[21]
    && v2->m_game_status == game_status_inprocess
    && v2->m_is_time_synchronized_first_time )
  {
    v9.m_object = (survarium::player *)v5;
    vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(
      &v9,
      (const vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)&this,
      (survarium::profile_player_character *)v5);
    survarium::base_network_client::attach_to_player(v8, v9);
    v7 = this;
  }
  if ( v7
    && !_InterlockedExchangeAdd(
          (volatile signed __int32 *)&v7->m_login_client.m_net_client_account_password[90],
          0xFFFFFFFF) )
  {
    if ( this )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)&this->m_login_client.m_net_client_account_password[90],
        (vostok::resources::unmanaged_resource *)&this->m_login_client.m_on_sign_out.functor);
    else
      vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)0x1F0, 0);
  }
}
