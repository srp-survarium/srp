void __userpurge survarium::network_client::set_game_status(
        survarium::game_status status@<eax>,
        survarium::network_client *this)
{
  survarium::game_world *v3; // ecx
  survarium::game *m_game; // ebx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v5; // [esp-4h] [ebp-10h] BYREF

  this->m_game_status = status;
  if ( this->m_local_player.m_object )
  {
    v3 = (survarium::game_world *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      if ( this->m_current_player.m_object != this->m_local_player.m_object )
      {
        v5.m_object = (vostok::particle::particle_system_instance_impl *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
        vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v5,
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_local_player);
        ((void (__thiscall *)(survarium::network_client *, vostok::particle::particle_system_instance_impl *))this->attach_to_player)(
          this,
          v5.m_object);
      }
      m_game = this->m_game;
      if ( this->m_game_status == game_status_inprocess )
        survarium::game_world::switch_to_player_camera(v3, (int)&m_game->m_game_world, 1);
      else
        survarium::game_world::switch_to_warmup_camera(v3, (int)&m_game->m_game_world);
    }
  }
}
