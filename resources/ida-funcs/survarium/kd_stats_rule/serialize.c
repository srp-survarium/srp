void __thiscall survarium::kd_stats_rule::serialize(
        survarium::kd_stats_rule *this,
        vostok::network_core::buffer_writer *writer,
        const unsigned int __formal)
{
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network_core::buffer_writer *v5; // ecx
  unsigned __int8 i; // [esp+13h] [ebp-5h]
  vostok::vfs::vfs_association *v7; // [esp+14h] [ebp-4h]

  for ( i = 0; i < this->m_players_count; ++i )
  {
    vostok::network_core::buffer_writer::w<unsigned short>(
      (unsigned __int8 *)&this->m_kd_stats[i],
      (vostok::network_core::buffer_writer *)this,
      writer,
      ".\\kd_stats_rule.cpp",
      (const char *)0x2A,
      "survarium::kd_stats_rule::serialize",
      "m_kd_stats[i].kills");
    v7 = (survarium::kd_stats_rule *)((char *)this + 8 * i);
    vostok::network_core::buffer_writer::w<unsigned short>(
      (unsigned __int8 *)&v7[34].__vftable + 2,
      v4,
      writer,
      ".\\kd_stats_rule.cpp",
      (const char *)0x2B,
      "survarium::kd_stats_rule::serialize",
      "m_kd_stats[i].deaths");
    vostok::network_core::buffer_writer::w<bool>(
      (const bool *)&v7[34].type,
      v5,
      writer,
      ".\\kd_stats_rule.cpp",
      (const char *)0x2C,
      "survarium::kd_stats_rule::serialize",
      "m_kd_stats[i].online");
  }
}
