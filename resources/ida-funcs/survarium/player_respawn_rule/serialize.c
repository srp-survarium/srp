void __thiscall survarium::player_respawn_rule::serialize(
        survarium::player_respawn_rule *this,
        vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *time_offset)
{
  vostok::network_core::buffer_writer *v4; // ecx
  unsigned int v5; // eax
  stlp_std::priv::_Rb_tree_node_base *M_left; // edi
  survarium::map<unsigned int,survarium::respawn_point_core *,stlp_std::less<unsigned int> > *p_m_respawn_points; // ebx
  stlp_std::priv::_Rb_tree_node_base *M_parent; // esi
  survarium::players_checker *v9; // ecx
  stlp_std::priv::_Rb_tree_node_base *v10; // eax
  vostok::network_core::buffer_writer *v11; // [esp-4h] [ebp-1Ch]
  boost::array<unsigned int,20> *p_m_player_respawn_times; // [esp+Ch] [ebp-Ch]
  unsigned int v13; // [esp+10h] [ebp-8h] BYREF
  unsigned int m_seed; // [esp+14h] [ebp-4h] BYREF

  m_seed = this->m_respawn_random.m_seed;
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&m_seed,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\player_respawn_rule.cpp",
    (const char *)0xE6,
    "survarium::player_respawn_rule::serialize",
    "m_respawn_random.seed( )");
  p_m_player_respawn_times = &this->m_player_respawn_times;
  m_seed = 20;
  do
  {
    v5 = p_m_player_respawn_times->elems[0];
    if ( p_m_player_respawn_times->elems[0] != -1 )
    {
      v4 = time_offset;
      v5 += (unsigned int)time_offset;
    }
    v13 = v5;
    vostok::network_core::buffer_writer::w<unsigned int>(
      (unsigned __int8 *)&v13,
      v4,
      writer,
      ".\\player_respawn_rule.cpp",
      (const char *)0xEA,
      "survarium::player_respawn_rule::serialize",
      "m_player_respawn_times[i]!=u32(-1) ? m_player_respawn_times[i] + time_offset : m_player_respawn_times[i]");
    p_m_player_respawn_times = (boost::array<unsigned int,20> *)((char *)p_m_player_respawn_times + 4);
    --m_seed;
  }
  while ( m_seed );
  M_left = this->m_respawn_points._M_t._M_header._M_data._M_left;
  p_m_respawn_points = &this->m_respawn_points;
  while ( M_left != (stlp_std::priv::_Rb_tree_node_base *)p_m_respawn_points )
  {
    M_parent = M_left[1]._M_parent;
    survarium::players_checker::serialize((survarium::players_checker *)v4, (int)M_parent[2]._M_parent, writer);
    survarium::players_checker::serialize(v9, (int)M_parent[2]._M_left, writer);
    v10 = stlp_std::priv::_Rb_global<bool>::_M_increment(M_left);
    v4 = v11;
    M_left = v10;
  }
}
