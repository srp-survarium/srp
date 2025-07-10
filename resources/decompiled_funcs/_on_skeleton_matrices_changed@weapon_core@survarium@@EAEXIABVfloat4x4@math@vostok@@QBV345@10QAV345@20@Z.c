void __thiscall survarium::weapon_core::on_skeleton_matrices_changed(
        survarium::weapon_core *this,
        unsigned int current_time_in_ms,
        const vostok::math::float4x4 *weapon_transform,
        const vostok::math::float4x4 *const weapon_matrices_begin,
        const vostok::math::float4x4 *const weapon_matrices_end,
        const vostok::math::float4x4 *user_transform,
        vostok::math::float4x4 *const user_matrices_begin,
        vostok::math::float4x4 *const user_matrices_end,
        const vostok::math::float4x4 *user_weapon_transform)
{
  _BYTE *v9; // eax
  _BYTE v10[64]; // [esp-D0h] [ebp-E0h] BYREF
  const vostok::math::float4x4 *v11; // [esp-90h] [ebp-A0h]
  const vostok::math::float4x4 *v12; // [esp-8Ch] [ebp-9Ch]
  _BYTE v13[64]; // [esp-88h] [ebp-98h] BYREF
  vostok::math::float4x4 *v14; // [esp-48h] [ebp-58h]
  vostok::math::float4x4 *v15; // [esp-44h] [ebp-54h]
  _BYTE v16[64]; // [esp-40h] [ebp-50h] BYREF
  survarium::weapon_core *thisa; // [esp+8h] [ebp-8h]
  char v18; // [esp+Fh] [ebp-1h]

  thisa = this;
  v18 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v9 )
  {
    qmemcpy(v16, user_weapon_transform, sizeof(v16));
    v15 = user_matrices_end;
    v14 = user_matrices_begin;
    qmemcpy(v13, user_transform, sizeof(v13));
    v12 = weapon_matrices_end;
    v11 = weapon_matrices_begin;
    qmemcpy(v10, weapon_transform, sizeof(v10));
    survarium::weapon_user_dead_state::finalize(0);
  }
}
