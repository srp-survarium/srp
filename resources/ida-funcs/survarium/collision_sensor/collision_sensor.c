void __usercall survarium::collision_sensor::collision_sensor(survarium::collision_sensor *this@<ecx>, int a2@<eax>)
{
  *(_DWORD *)(a2 + 4) = &survarium::link_resolver::`vftable';
  *(_DWORD *)a2 = &survarium::collision_sensor::`vftable'{for `survarium::collision_geometry_subscriber'};
  *(_DWORD *)(a2 + 4) = &survarium::collision_sensor::`vftable'{for `survarium::link_resolver'};
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_BYTE *)(a2 + 28) = 0;
}
