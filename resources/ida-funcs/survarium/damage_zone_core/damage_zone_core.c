void __usercall survarium::damage_zone_core::damage_zone_core(survarium::damage_zone_core *this@<ecx>, int a2@<esi>)
{
  survarium::collision_sensor *v2; // ecx
  _DWORD *v3; // eax

  vostok::resources::unmanaged_resource::unmanaged_resource(this, (_DWORD *)a2, fs_iterator_class);
  survarium::collision_sensor::collision_sensor(v2, a2 + 264);
  *(_DWORD *)(a2 + 300) = &survarium::hit_initiator::`vftable';
  *(_BYTE *)(a2 + 304) = -1;
  *(_BYTE *)(a2 + 305) = 1;
  *(_DWORD *)(a2 + 312) = &survarium::player_actions_subscriber::`vftable';
  *(_DWORD *)(a2 + 316) = &survarium::tickable_object::`vftable';
  *(_DWORD *)(a2 + 328) = &survarium::serializable_object::`vftable';
  *(_DWORD *)(a2 + 328) = &survarium::damage_zone_core::`vftable'{for `survarium::serializable_object'};
  *v3 = &survarium::damage_zone_core::`vftable'{for `survarium::collision_geometry_subscriber'};
  *(_DWORD *)(a2 + 312) = &survarium::damage_zone_core::`vftable'{for `survarium::player_actions_subscriber'};
  *(_DWORD *)(a2 + 316) = &survarium::damage_zone_core::`vftable'{for `survarium::tickable_object'};
  *(_DWORD *)a2 = &survarium::damage_zone_core::`vftable'{for `vostok::resources::unmanaged_resource'};
  *(_DWORD *)(a2 + 268) = &survarium::damage_zone_core::`vftable'{for `survarium::link_resolver'};
  *(_DWORD *)(a2 + 300) = &survarium::damage_zone_core::`vftable'{for `survarium::hit_initiator'};
  *(_DWORD *)(a2 + 344) = 0;
  *(_DWORD *)(a2 + 348) = 0;
  *(_DWORD *)(a2 + 352) = 0;
  *(_DWORD *)(a2 + 376) = 0;
  *(_DWORD *)(a2 + 380) = 0;
  *(_DWORD *)(a2 + 408) = 0;
  *(_DWORD *)(a2 + 412) = 0;
  *(_DWORD *)(a2 + 424) = 0;
  *(_DWORD *)(a2 + 428) = 0;
  *(_DWORD *)(a2 + 432) = 0;
  *(_DWORD *)(a2 + 436) = 0;
  *(_DWORD *)(a2 + 440) = 0;
  *(_DWORD *)(a2 + 460) = -1;
  *(_BYTE *)(a2 + 464) = 1;
  *(_BYTE *)(a2 + 465) = 0;
  *(_DWORD *)(a2 + 468) = 0;
  memset((void *)(a2 + 472), 0, 0x50u);
  *(_DWORD *)(a2 + 376) = 0;
  *(_DWORD *)(a2 + 384) = 0;
  *(_DWORD *)(a2 + 368) = 0;
  *(_DWORD *)(a2 + 372) = 0;
  *(_DWORD *)(a2 + 360) = 0;
  *(_DWORD *)(a2 + 364) = 0;
  *(_DWORD *)(a2 + 408) = 0;
  *(_DWORD *)(a2 + 416) = 0;
  *(_DWORD *)(a2 + 400) = 0;
  *(_DWORD *)(a2 + 404) = 0;
  *(_DWORD *)(a2 + 392) = 0;
  *(_DWORD *)(a2 + 396) = 0;
}
