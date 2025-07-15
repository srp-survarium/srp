void __thiscall survarium::network_client::apply_use_physics_controller_for_current(survarium::network_client *this)
{
  boost::array<survarium::player_desc,20> *p_m_net_players; // edi
  int v3; // ebx
  survarium::player *p_m_prev_in_global_list; // esi

  p_m_net_players = &this->m_net_players;
  v3 = 20;
  do
  {
    if ( p_m_net_players->elems[0].player.m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      p_m_prev_in_global_list = 0;
      if ( p_m_net_players->elems[0].player.m_object != (vostok::resources::unmanaged_resource *)288 )
      {
        p_m_prev_in_global_list = (survarium::player *)&p_m_net_players->elems[0].player.m_object[-2].m_prev_in_global_list;
        _InterlockedExchangeAdd(&p_m_prev_in_global_list->m_reference_count, 1u);
      }
      survarium::player::set_use_physics_controller_for_current(
        p_m_prev_in_global_list,
        this->m_use_physics_controller_for_current);
      if ( p_m_prev_in_global_list )
      {
        if ( !_InterlockedExchangeAdd(&p_m_prev_in_global_list->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(
            &p_m_prev_in_global_list->vostok::resources::unmanaged_intrusive_base,
            &p_m_prev_in_global_list->vostok::resources::unmanaged_resource);
      }
    }
    p_m_net_players = (boost::array<survarium::player_desc,20> *)((char *)p_m_net_players + 8);
    --v3;
  }
  while ( v3 );
}
