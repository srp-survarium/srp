void __thiscall survarium::base_network_client::attach_to_player_cc(
        survarium::base_network_client *this,
        char *arguments)
{
  survarium::player *v3; // ecx
  survarium::base_network_client *v4; // ecx
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> v5; // [esp-4h] [ebp-14h] BYREF
  int player_id; // [esp+Ch] [ebp-4h] BYREF

  if ( sscanf_s(arguments, "%d", &player_id) != -1 && (unsigned __int8)player_id < 0x14u )
  {
    this->get_player(
      this,
      (vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)&arguments,
      player_id);
    if ( arguments )
    {
      v5.m_object = v3;
      vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(
        &v5,
        (const vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)&arguments,
        (survarium::profile_player_character *)v3);
      survarium::base_network_client::attach_to_player(v4, (int)this, v5);
    }
    vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)&arguments);
  }
}
