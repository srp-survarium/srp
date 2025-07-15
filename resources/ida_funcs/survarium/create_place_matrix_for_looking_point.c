vostok::math::float4x4 *__cdecl survarium::create_place_matrix_for_looking_point(
        vostok::math::float4x4 *result,
        const vostok::math::float3 *hit_point,
        const vostok::math::float3 *normal)
{
  survarium::game_camera *v3; // ecx
  const vostok::math::float3 *v4; // eax
  vostok::math::float3_pod *v5; // ecx
  survarium::game_camera *v6; // ecx
  vostok::math::float3 *v7; // eax
  _DWORD *v8; // esi
  _DWORD *v9; // eax
  survarium::game_camera *v10; // ecx
  _DWORD *v11; // esi
  _DWORD *v12; // eax
  survarium::game_camera *v13; // ecx
  vostok::math::float3_pod *v14; // esi
  _DWORD *v15; // eax
  const vostok::math::float3_pod *v16; // eax
  vostok::math::float3 *v17; // eax
  survarium::game_camera *v18; // ecx
  int v19; // eax
  survarium::game_camera *v20; // ecx
  _DWORD *v21; // esi
  _DWORD *v22; // eax
  survarium::game_camera *v23; // ecx
  vostok::math::float3 v25; // [esp+A8h] [ebp-CCh] BYREF
  char v26; // [esp+B7h] [ebp-BDh]
  vostok::math::float3 v27; // [esp+B8h] [ebp-BCh] BYREF
  vostok::math::float3_pod v28; // [esp+C4h] [ebp-B0h] BYREF
  float *v29; // [esp+D0h] [ebp-A4h]
  vostok::math::float3_pod *right; // [esp+D4h] [ebp-A0h]
  float v31[2]; // [esp+D8h] [ebp-9Ch] BYREF
  survarium::game_camera *v32; // [esp+E0h] [ebp-94h]
  const vostok::math::float3 *forward_candidate; // [esp+E4h] [ebp-90h]
  _BYTE v34[132]; // [esp+E8h] [ebp-8Ch] BYREF
  const vostok::math::float3 *right_candidate; // [esp+16Ch] [ebp-8h]
  const vostok::math::float3 *head_forward; // [esp+170h] [ebp-4h]

  vostok::math::create_translation((vostok::math::float4x4 *)&v34[68], hit_point);
  survarium::weapon_user_dead_state::finalize(v3);
  head_forward = v4;
  vostok::math::operator^(v4, normal, (vostok::math::float3 *)&v34[56]);
  right_candidate = (const vostok::math::float3 *)&v34[56];
  if ( vostok::math::float3_pod::length(v5, (float *)&v34[56]) <= 0.001 )
  {
    survarium::weapon_user_dead_state::finalize(v6);
    *(_DWORD *)&v34[16] = v16;
    vostok::math::operator^(normal, v16, (vostok::math::float3 *)v34);
    forward_candidate = (const vostok::math::float3 *)v34;
    v26 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v34);
    vostok::math::normalize((const vostok::math::float3_pod *)v34, &v28.x);
    right = &v28;
    *(_DWORD *)&v34[12] = normal;
    v17 = vostok::math::operator^(&v28, normal, &v25);
    vostok::math::normalize(v17, v31);
    v29 = v31;
    survarium::weapon_user_dead_state::finalize(v18);
    *(float *)v19 = v31[0];
    *(float *)(v19 + 4) = v31[1];
    v20 = v32;
    *(_DWORD *)(v19 + 8) = v32;
    v21 = *(_DWORD **)&v34[12];
    survarium::weapon_user_dead_state::finalize(v20);
    *v22 = *v21;
    v23 = (survarium::game_camera *)v21[1];
    v22[1] = v23;
    v22[2] = v21[2];
    v14 = right;
    survarium::weapon_user_dead_state::finalize(v23);
  }
  else
  {
    vostok::math::normalize(right_candidate, (float *)&v34[40]);
    *(_DWORD *)&v34[32] = &v34[40];
    *(_DWORD *)&v34[52] = normal;
    v7 = vostok::math::operator^(normal, (const vostok::math::float3_pod *)&v34[40], &v27);
    vostok::math::normalize(v7, (float *)&v34[20]);
    *(_DWORD *)&v34[36] = &v34[20];
    v8 = *(_DWORD **)&v34[32];
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v34[20]);
    *v9 = *v8;
    v10 = (survarium::game_camera *)v8[1];
    v9[1] = v10;
    v9[2] = v8[2];
    v11 = *(_DWORD **)&v34[52];
    survarium::weapon_user_dead_state::finalize(v10);
    *v12 = *v11;
    v12[1] = v11[1];
    v13 = (survarium::game_camera *)v11[2];
    v12[2] = v13;
    v14 = *(vostok::math::float3_pod **)&v34[36];
    survarium::weapon_user_dead_state::finalize(v13);
  }
  *v15 = LODWORD(v14->x);
  v15[1] = LODWORD(v14->y);
  v15[2] = LODWORD(v14->z);
  qmemcpy((void *)result, &v34[68], sizeof(vostok::math::float4x4));
  return result;
}
