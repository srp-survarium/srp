BOOL __thiscall survarium::network_client::is_player_local(survarium::network_client *this, unsigned __int8 player_id)
{
  survarium::player *m_object; // eax

  m_object = this->m_local_player.m_object;
  return m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
      && m_object->id == player_id;
}
