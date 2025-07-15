void __thiscall survarium::base_network_client::attach_to_player_cc(
        survarium::base_network_client *this,
        char *arguments)
{
  vostok::particle::particle_system_instance_impl *v3; // ecx
  survarium::game_world *v4; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v5; // [esp-4h] [ebp-18h] BYREF
  int v6; // [esp+10h] [ebp-4h] BYREF

  if ( sscanf_s(arguments, "%d", &v6) != -1 && (unsigned __int8)v6 < 0x14u )
  {
    this->get_active_player(
      this,
      (vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)&arguments,
      v6);
    if ( arguments )
    {
      v5.m_object = v3;
      vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v5,
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&arguments);
      ((void (__thiscall *)(survarium::base_network_client *, vostok::particle::particle_system_instance_impl *))this->attach_to_player)(
        this,
        v5.m_object);
      survarium::game_world::switch_to_player_camera(v4, (int)&this->m_game->m_game_world, 1);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&arguments);
  }
}
