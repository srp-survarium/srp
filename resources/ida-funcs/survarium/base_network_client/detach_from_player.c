void __thiscall survarium::base_network_client::detach_from_player(survarium::base_network_client *this)
{
  survarium::game *m_game; // ebp
  int *p_m_current_player; // esi
  survarium::player *m_object; // eax
  survarium::game *v5; // ecx
  _DWORD *v6; // ebp
  survarium::game_world_ui *v7; // ecx
  survarium::player *v8; // [esp-8h] [ebp-14h]

  m_game = this->m_game;
  p_m_current_player = (int *)&this->m_current_player;
  m_object = this->m_current_player.m_object;
  v5 = 0;
  v6 = &m_game->m_game_world.__vftable;
  if ( m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      *(int *)((char *)&dword_1141C + (_DWORD)m_object) = 0;
      *(survarium::player_vtbl **)((char *)&m_object->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                 + (_DWORD)&loc_11403
                                 + 5) = 0;
      *(survarium::player_vtbl **)((char *)&m_object->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                 + (_DWORD)&loc_1140A
                                 + 2) = 0;
      *(_DWORD *)(*(int *)((char *)&dword_11410 + (_DWORD)m_object) + 13616) = 0;
      v8 = (survarium::player *)&v6[140 * *(unsigned __int8 *)(*p_m_current_player + 304) + 597];
      survarium::player::set_effect_presenter(v8, *p_m_current_player, (survarium::base_game_effect_presenter *)v8);
      vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base>::operator=(
        (vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)p_m_current_player,
        0);
      survarium::game_world_ui::clear_player(v7, (int)(v6 + 129));
      if ( this->m_is_spectator )
        survarium::game::hide_player_name(v5, (int)this->m_game);
    }
  }
  survarium::game_world::switch_to_free_fly_camera((survarium::game_world *)v5, v6);
}
