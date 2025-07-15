int __thiscall survarium::kd_stats_rule::winner_team(survarium::kd_stats_rule *this)
{
  __int16 *v2; // eax
  unsigned __int16 v4; // [esp+4h] [ebp-8h] BYREF
  unsigned __int16 v5; // [esp+6h] [ebp-6h]
  int v6; // [esp+8h] [ebp-4h]

  v4 = 0;
  v5 = 0;
  LOBYTE(v6) = 0;
  if ( !this->m_players_count )
    return 2;
  do
  {
    v2 = (__int16 *)(&v4
                   + ((*(survarium::base_player_vtbl **)((char *)&survarium::game_world_core::player(
                                                                    (survarium::game_world_core *)this->m_game_world_core,
                                                                    v6)->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                                       + (_DWORD)&loc_11066
                                                       + 2))[6].deserialize != 0));
    *v2 += this->m_kd_stats[(unsigned __int8)v6].kills;
    LOBYTE(v6) = v6 + 1;
  }
  while ( (unsigned __int8)v6 < this->m_players_count );
  if ( v5 < v4 )
    return 0;
  if ( v5 > v4 )
    return 1;
  else
    return 2;
}
