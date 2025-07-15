void __thiscall survarium::player_respawn_rule::on_match_finished(survarium::player_respawn_rule *this)
{
  stlp_std::priv::_Rb_tree_node_base *M_left; // esi
  survarium::map<unsigned int,survarium::respawn_point_core *,stlp_std::less<unsigned int> > *i; // ebp
  stlp_std::priv::_Rb_tree_node_base *M_parent; // ebx
  survarium::collision_sensor *v4; // ecx
  survarium::player_respawn_rule *v5; // [esp-Ch] [ebp-14h]

  M_left = this->m_respawn_points._M_t._M_header._M_data._M_left;
  for ( i = &this->m_respawn_points; M_left != (stlp_std::priv::_Rb_tree_node_base *)i; this = v5 )
  {
    M_parent = M_left[1]._M_parent;
    survarium::collision_sensor::remove((survarium::collision_sensor *)this, (int)M_parent[2]._M_parent);
    survarium::collision_sensor::remove(v4, (int)M_parent[2]._M_left);
    M_left = stlp_std::priv::_Rb_global<bool>::_M_increment(M_left);
  }
}
