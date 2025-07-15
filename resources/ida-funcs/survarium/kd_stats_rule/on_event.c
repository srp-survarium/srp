void __thiscall survarium::kd_stats_rule::on_event(
        survarium::kd_stats_rule *this,
        survarium::event_id_type event_id,
        unsigned __int8 *event_args,
        const unsigned int __formal)
{
  unsigned __int16 *p_deaths; // eax
  unsigned __int8 v5; // al
  survarium::game_world_core **p_m_game_world_core; // esi
  void (__thiscall *deserialize)(survarium::base_player *, vostok::network_core::buffer_reader *, vostok::network_core::buffer_reader *, const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *, const unsigned int, const unsigned int, const bool); // ebx
  survarium::player_kd_stat *v8; // eax

  if ( event_id == player_killed_event )
  {
    p_deaths = &this->m_kd_stats[event_args[1]].deaths;
    ++*p_deaths;
    v5 = *event_args;
    if ( *event_args != 0xFF && v5 != event_args[1] )
    {
      p_m_game_world_core = (survarium::game_world_core **)&this->m_game_world_core;
      deserialize = (*(survarium::base_player_vtbl **)((char *)&survarium::game_world_core::player(
                                                                  (survarium::game_world_core *)this->m_game_world_core,
                                                                  v5)->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                                     + (_DWORD)&loc_11066
                                                     + 2))[6].deserialize;
      if ( deserialize != (*(survarium::base_player_vtbl **)((char *)&survarium::game_world_core::player(
                                                                        *p_m_game_world_core,
                                                                        event_args[1])->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                                           + (_DWORD)&loc_11066
                                                           + 2))[6].deserialize )
      {
        v8 = &this->m_kd_stats[*event_args];
        ++v8->kills;
      }
    }
  }
}
