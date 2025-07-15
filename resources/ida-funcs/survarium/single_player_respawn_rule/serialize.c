void __thiscall survarium::single_player_respawn_rule::serialize(
        survarium::single_player_respawn_rule *this,
        vostok::network_core::buffer_writer *writer,
        survarium::single_player_respawn_rule *time_offset)
{
  boost::array<unsigned int,20> *p_m_player_death_times; // esi
  int v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // [esp+Ch] [ebp-4h] BYREF

  p_m_player_death_times = &this->m_player_death_times;
  v4 = 20;
  do
  {
    v5 = p_m_player_death_times->elems[0];
    if ( p_m_player_death_times->elems[0] != -1 )
    {
      this = time_offset;
      v5 += (unsigned int)time_offset;
    }
    v6 = v5;
    vostok::network_core::buffer_writer::w<unsigned int>(
      (unsigned __int8 *)&v6,
      (vostok::network_core::buffer_writer *)this,
      writer,
      ".\\player_respawn_rule.cpp",
      (const char *)0x14E,
      "survarium::single_player_respawn_rule::serialize",
      "m_player_death_times[i] != u32(-1) ? m_player_death_times[i] + time_offset : m_player_death_times[i]");
    p_m_player_death_times = (boost::array<unsigned int,20> *)((char *)p_m_player_death_times + 4);
    --v4;
  }
  while ( v4 );
}
