void __usercall vostok::animation::hand_to_weapon_ik_solver::hand_to_weapon_ik_solver(
        vostok::animation::hand_to_weapon_ik_solver *this@<ecx>,
        int a2@<esi>)
{
  vostok::animation::hand_to_weapon_ik_solver::hand *v2; // edi
  int i; // ebx

  v2 = (vostok::animation::hand_to_weapon_ik_solver::hand *)a2;
  for ( i = 1; i >= 0; --i )
    vostok::animation::hand_to_weapon_ik_solver::hand::hand(v2++);
  *(_DWORD *)(a2 + 1256) = &vostok::animation::linear_interpolator::`vftable';
  *(float *)(a2 + 1260) = s_aim_transition_time;
  *(_DWORD *)(a2 + 1268) = 0;
  *(_DWORD *)(a2 + 1272) = 0;
}
