void __userpurge survarium::game_world_ui::initialize_base_points(
        vostok::network_core::packet_reader *packet@<esi>,
        survarium::game_world_ui *this)
{
  const unsigned __int8 *m_pointer; // eax
  int v3; // ecx
  const unsigned __int8 *v4; // eax
  unsigned int v5; // edi
  stlp_std::priv::_Rb_tree_node_base *v6; // ebp
  unsigned int v7; // ecx
  stlp_std::priv::_Rb_tree_node_base *v8; // ebx
  bool v9; // zf
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *v10; // eax
  survarium::game_world_ui *v11; // ecx
  int v12; // [esp+Ch] [ebp-14h]
  unsigned int point_id; // [esp+10h] [ebp-10h] BYREF
  survarium::base_point_stats stats; // [esp+14h] [ebp-Ch]

  m_pointer = packet->m_pointer;
  v3 = *(_DWORD *)m_pointer;
  packet->m_pointer = m_pointer + 4;
  if ( v3 )
  {
    v12 = v3;
    do
    {
      v4 = packet->m_pointer;
      v5 = *(_DWORD *)v4;
      v4 += 4;
      packet->m_pointer = v4;
      v6 = *(stlp_std::priv::_Rb_tree_node_base **)v4;
      v4 += 4;
      packet->m_pointer = v4;
      v7 = *(_DWORD *)v4;
      v4 += 4;
      packet->m_pointer = v4;
      v8 = *(stlp_std::priv::_Rb_tree_node_base **)v4;
      packet->m_pointer = v4 + 4;
      v9 = this->m_game_mode == capture_neutral_base;
      point_id = v5;
      stats.team_points_amount = v7;
      stats.capture_progress = (unsigned int)v8;
      if ( !v9 || v6 == (stlp_std::priv::_Rb_tree_node_base *)2 )
      {
        v10 = stlp_std::map<unsigned int,survarium::base_point_stats,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::base_point_stats>>>::operator[]<unsigned int>(
                (stlp_std::map<unsigned int,survarium::base_point_stats,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::base_point_stats> > > *)&point_id,
                (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *)&this->m_base_points);
        *(_QWORD *)&v10->_M_node = *(_QWORD *)&stats.team_points_amount;
        v10[2]._M_node = v6;
        survarium::game_world_ui::set_base_capture_progress(
          v11,
          (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *)this,
          v8,
          v5);
      }
      --v12;
    }
    while ( v12 );
  }
}
