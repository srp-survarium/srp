void __thiscall survarium::player_respawn_rule::on_match_ready(
        survarium::player_respawn_rule *this,
        const unsigned int __formal)
{
  stlp_std::priv::_Rb_tree_node_base *M_left; // ebx
  survarium::map<unsigned int,survarium::respawn_point_core *,stlp_std::less<unsigned int> > *i; // ebp
  stlp_std::priv::_Rb_tree_node_base *M_parent; // edi
  survarium::collision_sensor *v5; // ecx
  survarium::player_respawn_rule *v6; // [esp-Ch] [ebp-14h]

  M_left = this->m_respawn_points._M_t._M_header._M_data._M_left;
  for ( i = &this->m_respawn_points; M_left != (stlp_std::priv::_Rb_tree_node_base *)i; this = v6 )
  {
    M_parent = M_left[1]._M_parent;
    survarium::collision_sensor::insert(
      (survarium::collision_sensor *)this,
      (int)M_parent[2]._M_parent,
      *(vostok::physics::world **)&M_parent[2]._M_color);
    survarium::collision_sensor::insert(v5, (int)M_parent[2]._M_left, *(vostok::physics::world **)&M_parent[2]._M_color);
    M_left = stlp_std::priv::_Rb_global<bool>::_M_increment(M_left);
  }
}
