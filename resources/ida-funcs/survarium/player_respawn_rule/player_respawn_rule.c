void __thiscall survarium::player_respawn_rule::player_respawn_rule(
        survarium::player_respawn_rule *this,
        const unsigned int respawn_interval_time_in_ms,
        const vostok::configs::binary_config *project_cfg,
        vostok::physics::world *physics_world,
        vostok::physics::world *physics_worlda)
{
  stlp_std::map<unsigned int,survarium::respawn_point_core *,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *> > > *v5; // ebx
  vostok::configs::binary_config_value *v6; // eax
  vostok::configs::binary_config_value *v7; // eax
  const vostok::configs::binary_config_value *v8; // eax
  int v9; // edi
  const char *v10; // esi
  char *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // ecx
  char *v13; // ecx
  int v14; // eax
  int v15; // esi
  const char *v16; // [esp+0h] [ebp-28h]
  const char *v17; // [esp+4h] [ebp-24h]
  unsigned int v18; // [esp+8h] [ebp-20h]
  char v19; // [esp+Fh] [ebp-19h]
  vostok::configs::binary_config_value *pointer; // [esp+10h] [ebp-18h]
  int i; // [esp+14h] [ebp-14h]
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  survarium::game_match_rule_base::game_match_rule_base(
    this,
    (_DWORD *)respawn_interval_time_in_ms,
    player_respawn_rule_type);
  *(_DWORD *)respawn_interval_time_in_ms = &survarium::player_respawn_rule::`vftable'{for `vostok::resources::unmanaged_resource'};
  *(_DWORD *)(respawn_interval_time_in_ms + 264) = &survarium::player_respawn_rule::`vftable'{for `survarium::link_resolver'};
  v5 = (stlp_std::map<unsigned int,survarium::respawn_point_core *,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *> > > *)(respawn_interval_time_in_ms + 272);
  *(_DWORD *)(respawn_interval_time_in_ms + 272) = 0;
  *(_DWORD *)(respawn_interval_time_in_ms + 276) = 0;
  *(_DWORD *)(respawn_interval_time_in_ms + 280) = 0;
  *(_DWORD *)(respawn_interval_time_in_ms + 284) = 0;
  *(_DWORD *)(respawn_interval_time_in_ms + 276) = 0;
  *(_DWORD *)(respawn_interval_time_in_ms + 288) = 0;
  *(_BYTE *)(respawn_interval_time_in_ms + 292) = v19;
  *(_BYTE *)(respawn_interval_time_in_ms + 272) = 0;
  *(_DWORD *)(respawn_interval_time_in_ms + 280) = respawn_interval_time_in_ms + 272;
  *(_DWORD *)(respawn_interval_time_in_ms + 284) = respawn_interval_time_in_ms + 272;
  *(_DWORD *)(respawn_interval_time_in_ms + 376) = 0;
  *(_DWORD *)(respawn_interval_time_in_ms + 380) = project_cfg;
  memset((void *)(respawn_interval_time_in_ms + 296), 0xFFu, 0x50u);
  v6 = vostok::configs::binary_config_value::operator[](
         (vostok::configs::binary_config_value *)physics_world[66].__vftable,
         "server_objects");
  pointer = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      v6,
                                                      "respawn_points")->data.pointer;
  v7 = vostok::configs::binary_config_value::operator[](
         (vostok::configs::binary_config_value *)physics_world[66].__vftable,
         "server_objects");
  v8 = vostok::configs::binary_config_value::operator[](v7, "respawn_points");
  v9 = (int)v8->data.pointer + 24 * v8->count;
  for ( i = v9;
        pointer != (vostok::configs::binary_config_value *)v9;
        *stlp_std::map<unsigned int,survarium::respawn_point_core *,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *>>>::operator[]<unsigned int>(
           v5,
           (unsigned int *)(v15 + 4)) = (stlp_std::priv::_Rb_tree_node_base *)v15 )
  {
    v10 = (const char *)survarium::g_allocator;
    v11 = type_info::raw_name(&survarium::respawn_point_core `RTTI Type Descriptor');
    v13 = vostok::memory::doug_lea_allocator::malloc_impl(v12, (int)v10, 0x2Cu, v11, v16, v17, v18);
    if ( v13 )
    {
      survarium::respawn_point_core::respawn_point_core(
        (survarium::respawn_point_core *)v13,
        physics_worlda,
        (unsigned int)v5,
        (const char *)&savedregs,
        v10);
      v9 = i;
      v15 = v14;
    }
    else
    {
      v15 = 0;
    }
    survarium::respawn_point_core::load(
      (survarium::respawn_point_core *)v13,
      (const vostok::configs::binary_config_value *)v15,
      pointer++);
  }
}
