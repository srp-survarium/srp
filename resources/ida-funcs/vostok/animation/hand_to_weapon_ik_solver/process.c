void __userpurge vostok::animation::hand_to_weapon_ik_solver::process(
        vostok::animation::hand_to_weapon_ik_solver *this@<ecx>,
        int a2@<edi>,
        const vostok::math::float4x4 *current_time_in_ms,
        vostok::math::float4x4 *weapon_matrices,
        char is_first_view,
        vostok::math::float4x4 *user_matrices)
{
  vostok::animation::hand_to_weapon_ik_solver *v6; // ecx
  int v7; // esi
  vostok::animation::hand_to_weapon_ik_solver *v8; // ecx
  vostok::math::float4x4 bone; // [esp+8h] [ebp-80h] BYREF
  vostok::math::float4x4 matrices; // [esp+48h] [ebp-40h] BYREF

  vostok::animation::get_bone_matrix_in_object_space(
    *(const vostok::animation::skeleton **)(a2 + 1268),
    &bone,
    (const vostok::animation::skeleton_bone *)(28 * *(_DWORD *)(a2 + 1264) + *(_DWORD *)(a2 + 1268) + 272),
    user_matrices);
  v7 = a2;
  do
  {
    if ( *(_BYTE *)(v7 + 624)
      || (v6 = (vostok::animation::hand_to_weapon_ik_solver *)((char *)current_time_in_ms - *(_DWORD *)(v7 + 600)),
          (unsigned int)v6 < 0x12C) )
    {
      vostok::animation::hand_to_weapon_ik_solver::get_hand_target_transform(
        v6,
        (vostok::math::float4x4 *)a2,
        &matrices,
        (_DWORD *)v7,
        current_time_in_ms,
        &bone,
        user_matrices,
        weapon_matrices,
        is_first_view);
      vostok::animation::hand_to_weapon_ik_solver::process_hand(
        v8,
        (const vostok::animation::hand_to_weapon_ik_solver::hand *)a2,
        (const vostok::math::float4x4 *)v7,
        &matrices,
        (int)user_matrices);
    }
    v7 += 628;
  }
  while ( v7 != a2 + 1256 );
}
