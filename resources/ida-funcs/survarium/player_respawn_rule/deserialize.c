void __thiscall survarium::player_respawn_rule::deserialize(
        survarium::player_respawn_rule *this,
        vostok::network_core::buffer_reader *reader,
        const unsigned int time_offset)
{
  const unsigned __int8 *m_pointer; // eax
  boost::array<unsigned int,20> *p_m_player_respawn_times; // edx
  const unsigned __int8 *v6; // esi
  int v7; // eax
  stlp_std::priv::_Rb_tree_node_base *M_left; // eax
  bool i; // zf
  stlp_std::priv::_Rb_tree_node_base *M_parent; // ecx
  const unsigned __int8 *v11; // esi
  const unsigned __int8 *v12; // edx
  stlp_std::priv::_Rb_tree_node_base *v13; // esi
  stlp_std::priv::_Rb_tree_node_base *v14; // ecx
  const unsigned __int8 *v15; // esi
  survarium::map<unsigned int,survarium::respawn_point_core *,stlp_std::less<unsigned int> > *p_m_respawn_points; // [esp+Ch] [ebp-8h]
  int v17; // [esp+10h] [ebp-4h]
  unsigned int v18; // [esp+1Ch] [ebp+8h]
  int v19; // [esp+1Ch] [ebp+8h]
  unsigned __int8 v20; // [esp+1Fh] [ebp+Bh]
  unsigned __int8 v21; // [esp+23h] [ebp+Fh]

  m_pointer = reader->m_pointer;
  v18 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->m_respawn_random.m_seed = v18;
  p_m_player_respawn_times = &this->m_player_respawn_times;
  v19 = 20;
  do
  {
    v6 = reader->m_pointer;
    v17 = *(_DWORD *)v6;
    reader->m_pointer = v6 + 4;
    if ( v17 == -1 )
      v7 = -1;
    else
      v7 = time_offset + v17;
    p_m_player_respawn_times->elems[0] = v7;
    p_m_player_respawn_times = (boost::array<unsigned int,20> *)((char *)p_m_player_respawn_times + 4);
    --v19;
  }
  while ( v19 );
  M_left = this->m_respawn_points._M_t._M_header._M_data._M_left;
  p_m_respawn_points = &this->m_respawn_points;
  for ( i = M_left == (stlp_std::priv::_Rb_tree_node_base *)&this->m_respawn_points;
        !i;
        i = M_left == (stlp_std::priv::_Rb_tree_node_base *)p_m_respawn_points )
  {
    M_parent = M_left[1]._M_parent;
    v11 = reader->m_pointer;
    v12 = v11 + 1;
    v20 = *v11;
    v13 = M_parent[2]._M_parent;
    reader->m_pointer = v12;
    v13[2]._M_color = v20;
    v14 = M_parent[2]._M_left;
    v15 = reader->m_pointer;
    v21 = *v15;
    reader->m_pointer = v15 + 1;
    v14[2]._M_color = v21;
    M_left = stlp_std::priv::_Rb_global<bool>::_M_increment(M_left);
  }
}
