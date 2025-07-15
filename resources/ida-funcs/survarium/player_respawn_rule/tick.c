void __thiscall survarium::player_respawn_rule::tick(
        survarium::player_respawn_rule *this,
        unsigned int time_delta_in_ms,
        unsigned int current_time_in_ms)
{
  survarium::player_respawn_rule *v3; // ebx
  boost::array<unsigned int,20> *p_m_player_respawn_times; // esi
  stlp_std::priv::_Rb_tree_node_base *i; // edi
  stlp_std::priv::_Rb_tree_node_base *M_parent; // esi
  stlp_std::priv::_Rb_tree_node_base *v7; // eax
  boost::array<unsigned int,20> *v8; // esi
  survarium::base_player **v9; // eax
  survarium::player_respawn_rule *v10; // ecx
  survarium::player_respawn_rule *v11; // [esp-8h] [ebp-1Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v12; // [esp+8h] [ebp-Ch] BYREF
  int v13; // [esp+Fh] [ebp-5h]
  char v14; // [esp+13h] [ebp-1h]
  unsigned __int8 v15; // [esp+1Ch] [ebp+8h]

  v3 = this;
  v14 = 0;
  LOBYTE(v13) = 0;
  p_m_player_respawn_times = &this->m_player_respawn_times;
  do
  {
    if ( p_m_player_respawn_times->elems[0] != -1 && current_time_in_ms == p_m_player_respawn_times->elems[0] )
    {
      survarium::game_world_core::active_player_ptr(
        (survarium::game_world_core *)this,
        &v12,
        (vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *)v3->m_game_world_core,
        v13);
      if ( HIBYTE(v12.m_object->m_skeleton_model.m_object) )
        v12.m_object->__vftable[1].log_string(v12.m_object, (vostok::fixed_string<512> *)1);
      v14 = 1;
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v12);
    }
    LOBYTE(v13) = v13 + 1;
    p_m_player_respawn_times = (boost::array<unsigned int,20> *)((char *)p_m_player_respawn_times + 4);
  }
  while ( (unsigned __int8)v13 < 0x14u );
  if ( v14 )
  {
    for ( i = v3->m_respawn_points._M_t._M_header._M_data._M_left;
          i != (stlp_std::priv::_Rb_tree_node_base *)&v3->m_respawn_points;
          i = v7 )
    {
      M_parent = i[1]._M_parent;
      (*(void (__thiscall **)(stlp_std::priv::_Rb_tree_node_base *, unsigned int, unsigned int))(*(_DWORD *)M_parent[2]._M_parent
                                                                                               + 20))(
        M_parent[2]._M_parent,
        time_delta_in_ms,
        current_time_in_ms);
      (*(void (__thiscall **)(stlp_std::priv::_Rb_tree_node_base *, unsigned int, unsigned int))(*(_DWORD *)M_parent[2]._M_left
                                                                                               + 20))(
        M_parent[2]._M_left,
        time_delta_in_ms,
        current_time_in_ms);
      v7 = stlp_std::priv::_Rb_global<bool>::_M_increment(i);
      this = v11;
    }
    v15 = 0;
    v8 = &v3->m_player_respawn_times;
    do
    {
      if ( v8->elems[0] != -1 && current_time_in_ms == v8->elems[0] )
      {
        v8->elems[0] = -1;
        v9 = (survarium::base_player **)survarium::game_world_core::active_player_ptr(
                                          (survarium::game_world_core *)this,
                                          &v12,
                                          (vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *)v3->m_game_world_core,
                                          v15);
        survarium::player_respawn_rule::spawn_player(v10, (int)v3, *v9, current_time_in_ms);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v12);
      }
      ++v15;
      v8 = (boost::array<unsigned int,20> *)((char *)v8 + 4);
    }
    while ( v15 < 0x14u );
  }
}
