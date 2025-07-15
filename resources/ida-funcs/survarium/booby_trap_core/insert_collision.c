void __usercall survarium::booby_trap_core::insert_collision(survarium::booby_trap_core *this@<ecx>, int a2@<edi>)
{
  survarium::usable_object *v2; // ecx
  int v3; // ecx
  int v4; // eax

  survarium::collision_sensor::insert(
    (survarium::collision_sensor *)this,
    a2 + 16,
    *(vostok::physics::world **)(a2 + 480));
  survarium::usable_object::insert(
    v2,
    (survarium::collision_geometry_subscriber *)(a2 + 52),
    *(vostok::physics::world **)(a2 + 480));
  if ( *(_BYTE *)(*(_DWORD *)(a2 + 484) + 336) )
  {
    v3 = *(_DWORD *)(a2 + 480);
    v4 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(a2 + 8) = v3;
    *(_DWORD *)(v4 + 12) = a2;
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v3 + 44))(
      v3,
      *(_DWORD *)(a2 + 4),
      *(unsigned __int16 *)(a2 + 12),
      *(unsigned __int16 *)(a2 + 14));
  }
}
