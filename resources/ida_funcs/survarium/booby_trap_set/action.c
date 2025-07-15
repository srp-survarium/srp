void __thiscall survarium::booby_trap_set::action(survarium::booby_trap_set *this, bool key_down)
{
  survarium::base_network_client *m_network_client; // ecx
  unsigned __int8 id; // dl
  survarium::player *m_object; // eax

  m_network_client = this->m_game_world->m_game->m_network_client;
  if ( !m_network_client->has_bandwidth(m_network_client) && !key_down )
    survarium::booby_trap_set_core::try_place_trap(this);
  id = this->m_inventory->m_holder->cast_to_base_player(this->m_inventory->m_holder)->id;
  m_object = this->m_game_world->m_game->m_network_client->m_current_player.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && m_object->id == id )
  {
    if ( this->m_amount )
      survarium::booby_trap_set::toggle_ghost_model(this, key_down);
  }
}
