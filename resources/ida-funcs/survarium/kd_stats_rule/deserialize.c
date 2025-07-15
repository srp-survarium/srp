void __thiscall survarium::kd_stats_rule::deserialize(
        survarium::kd_stats_rule *this,
        vostok::network_core::buffer_reader *reader,
        const unsigned int __formal)
{
  unsigned __int8 i; // bl
  vostok::vfs::vfs_association *v5; // edi

  for ( i = 0; i < this->m_players_count; LOBYTE(v5[34].type) = vostok::network_core::buffer_reader::r<bool>(reader) )
  {
    this->m_kd_stats[i].kills = vostok::network_core::buffer_reader::r<unsigned short>(reader);
    v5 = (survarium::kd_stats_rule *)((char *)this + 8 * i);
    HIWORD(v5[34].__vftable) = vostok::network_core::buffer_reader::r<unsigned short>(reader);
    ++i;
  }
}
