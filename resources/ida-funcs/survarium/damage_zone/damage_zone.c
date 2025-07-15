void __userpurge survarium::damage_zone::damage_zone(
        survarium::damage_zone *this@<ecx>,
        int a2@<esi>,
        survarium::game_world *game_world)
{
  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  survarium::damage_zone_core::damage_zone_core((survarium::damage_zone_core *)(a2 + 264));
  *(_DWORD *)(a2 + 264) = &survarium::damage_zone::`vftable'{for `survarium::collision_geometry_subscriber'};
  *(_DWORD *)a2 = &survarium::damage_zone::`vftable';
  *(_DWORD *)(a2 + 268) = &survarium::damage_zone::`vftable'{for `survarium::link_resolver'};
  *(_DWORD *)(a2 + 300) = &survarium::damage_zone::`vftable'{for `survarium::hit_initiator'};
  *(_DWORD *)(a2 + 312) = &survarium::damage_zone::`vftable'{for `survarium::player_actions_subscriber'};
  *(_DWORD *)(a2 + 536) = 0;
  *(_DWORD *)(a2 + 540) = 0;
  *(_DWORD *)(a2 + 544) = 0;
  *(_DWORD *)(a2 + 548) = game_world;
}
