void __thiscall survarium::single_player_respawn_rule::deserialize(
        survarium::single_player_respawn_rule *this,
        vostok::network_core::buffer_reader *reader,
        const unsigned int time_offset)
{
  boost::array<unsigned int,20> *p_m_player_death_times; // ecx
  int v5; // ebx
  const unsigned __int8 *m_pointer; // esi
  int v7; // eax
  int v8; // [esp+14h] [ebp+8h]

  p_m_player_death_times = &this->m_player_death_times;
  v5 = 20;
  do
  {
    m_pointer = reader->m_pointer;
    v8 = *(_DWORD *)m_pointer;
    reader->m_pointer = m_pointer + 4;
    if ( v8 == -1 )
      v7 = -1;
    else
      v7 = time_offset + v8;
    p_m_player_death_times->elems[0] = v7;
    p_m_player_death_times = (boost::array<unsigned int,20> *)((char *)p_m_player_death_times + 4);
    --v5;
  }
  while ( v5 );
}
