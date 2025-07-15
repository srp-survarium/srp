char __usercall survarium::booby_trap_set_core::try_to_place_trap@<al>(
        survarium::booby_trap_set_core *this@<ecx>,
        int a2@<edi>)
{
  survarium::booby_trap_set_core *v2; // ecx
  survarium::booby_trap_core *inactive_trap; // esi
  int v5; // eax
  survarium::booby_trap_core *v6; // ecx
  vostok::math::float4x4 transform; // [esp+8h] [ebp-40h] BYREF

  inactive_trap = survarium::booby_trap_set_core::find_inactive_trap(this, a2);
  if ( !inactive_trap )
  {
    inactive_trap = survarium::booby_trap_set_core::find_disarmed_trap(v2, a2);
    if ( !inactive_trap )
    {
      inactive_trap = survarium::booby_trap_set_core::find_oldest_placed_trap(v2, a2);
      if ( !inactive_trap )
        return 0;
    }
  }
  if ( !survarium::booby_trap_set_core::get_visible_place_transform(v2, (vostok::math::float4x4 *)a2, &transform) )
    return 0;
  if ( inactive_trap->m_trap_state )
    survarium::booby_trap_core::remove(inactive_trap);
  v5 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 272) + 376) + 12))(*(_DWORD *)(*(_DWORD *)(a2 + 272) + 376));
  survarium::booby_trap_core::insert(v6, (int)inactive_trap, &transform, *(_DWORD *)(v5 + 736));
  return 1;
}
