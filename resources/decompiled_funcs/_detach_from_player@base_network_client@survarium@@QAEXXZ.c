void __thiscall survarium::base_network_client::detach_from_player(survarium::base_network_client *this)
{
  survarium::player *m_object; // esi
  survarium::player *v3; // eax
  survarium::game_world_ui *p_game_ui; // esi
  survarium::game_world_ui *v5; // ecx

  m_object = this->m_current_player.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    survarium::player::detach_controller((survarium::player *)this, (int)m_object);
    v3 = this->m_current_player.m_object;
    this->m_current_player.m_object = 0;
    if ( v3 )
    {
      if ( !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &v3->vostok::resources::unmanaged_intrusive_base,
          &v3->vostok::resources::unmanaged_resource);
    }
    p_game_ui = &this->m_game->m_game_world.game_ui;
    survarium::game_world_ui::show_ammo_indicator(p_game_ui, 0);
    survarium::game_world_ui::show_quick_slots(v5, p_game_ui, 0);
  }
}
