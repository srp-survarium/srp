void __thiscall survarium::game_world::clear_player_spawn_info(survarium::game_world *this)
{
  survarium::simple_game_project *m_object; // ecx
  stlp_std::priv::_Rb_tree_node_base *M_left; // eax
  survarium::map<unsigned int,survarium::respawn_point_core *,stlp_std::less<unsigned int> > *i; // esi

  m_object = this->m_game_project.m_object;
  M_left = m_object->m_respawn_points._M_t._M_header._M_data._M_left;
  for ( i = &m_object->m_respawn_points;
        M_left != (stlp_std::priv::_Rb_tree_node_base *)i;
        M_left = stlp_std::priv::_Rb_global<bool>::_M_increment(M_left) )
  {
    M_left[1]._M_parent[2]._M_color = 0;
  }
}
