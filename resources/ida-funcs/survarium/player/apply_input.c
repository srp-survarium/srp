void __userpurge survarium::player::apply_input(
        survarium::player *this@<ecx>,
        float *a2@<eax>,
        vostok::math::float3 *a3@<edi>,
        float a4@<xmm0>,
        struct survarium::client_player_state *player_state,
        const struct vostok::math::float2 *a6,
        const struct vostok::math::float2 *a7,
        float a8)
{
  vostok::math::float2 rotation_to_apply; // [esp+0h] [ebp-8h] BYREF

  rotation_to_apply.x = (float)((float)((float)(*a2 * a4) * 0.5)
                              + *(float *)&this->survarium::base_player::survarium::inventory_holder::__vftable)
                      * a4;
  rotation_to_apply.y = (float)((float)((float)(a2[1] * a4) * 0.5) + *(float *)&this->m_scheduler) * a4;
  survarium::player::apply_input((survarium::player *)player_state, a3, player_state, &rotation_to_apply);
}


void __userpurge survarium::player::apply_input(
        survarium::player *this@<ecx>,
        vostok::math::float3 *a2@<edi>,
        survarium::client_player_state *player_state,
        const vostok::math::float2 *rotation_to_apply)
{
  float x; // xmm1_4
  vostok::math::float4x4 *v5; // ecx
  const vostok::math::float3 *angles_xyz; // eax
  const vostok::math::float4x4 *v7; // eax
  const vostok::math::float4x4 *v8; // eax
  float v9; // xmm0_4
  vostok::math::float3 angles; // [esp+4h] [ebp-110h] BYREF
  vostok::math::float4x4 right; // [esp+10h] [ebp-104h] BYREF
  vostok::math::float4x4 left; // [esp+50h] [ebp-C4h] BYREF
  vostok::math::float4x4 result; // [esp+90h] [ebp-84h] BYREF
  vostok::math::float4x4 v14; // [esp+D0h] [ebp-44h] BYREF

  x = rotation_to_apply->x;
  angles.x = 0.0;
  *(_QWORD *)&angles.elements[1] = LODWORD(x);
  vostok::math::create_rotation(&angles, &right);
  angles_xyz = vostok::math::float4x4::get_angles_xyz(v5, a2);
  v7 = vostok::math::create_rotation(&result, angles_xyz);
  vostok::math::mul4x3(&left, v7, &right);
  v8 = vostok::math::create_translation(&v14, (const vostok::math::float3 *)&player_state->transform.lines[3]);
  vostok::math::mul4x3(&right, &left, v8);
  qmemcpy((void *)&player_state->transform, &right, sizeof(player_state->transform));
  v9 = rotation_to_apply->y + player_state->look_pitch;
  if ( v9 > -1.0 )
  {
    if ( *(float *)&clear_value < v9 )
      v9 = *(float *)&clear_value;
    player_state->look_pitch = v9;
  }
  else
  {
    player_state->look_pitch = -1.0;
  }
}
