void __cdecl vostok::math::change_matrix_orientation(
        const vostok::math::float4x4 *rotation_matrix,
        vostok::math::float4x4 *matrix_to_rotate)
{
  survarium::game_camera *v2; // ecx
  vostok::math::float3 *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  survarium::game_camera *v6; // ecx
  _DWORD *v7; // eax
  vostok::math::float3 *v8; // eax
  vostok::math::float4x4 result; // [esp+1Ch] [ebp-58h] BYREF
  vostok::math::float3 v10; // [esp+5Ch] [ebp-18h] BYREF
  vostok::math::float3 pos; // [esp+68h] [ebp-Ch]

  survarium::weapon_user_dead_state::finalize(v2);
  pos = *v3;
  vostok::math::float3::float3(&v10, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  v5 = v4;
  survarium::weapon_user_dead_state::finalize(v6);
  *v7 = *v5;
  v7[1] = v5[1];
  v7[2] = v5[2];
  qmemcpy(
    (void *)matrix_to_rotate,
    vostok::math::operator*(&result, matrix_to_rotate, rotation_matrix),
    sizeof(vostok::math::float4x4));
  survarium::weapon_user_dead_state::finalize(0);
  *v8 = pos;
}
