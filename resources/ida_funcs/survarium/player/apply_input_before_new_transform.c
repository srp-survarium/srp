void __thiscall survarium::player::apply_input_before_new_transform(
        survarium::player *this,
        survarium::player *player_state,
        survarium::client_player_state *previous_input,
        float *time_delta,
        float time_deltaa)
{
  const survarium::player_input *p_animated_object; // esi
  float v6; // xmm2_4
  float v7; // xmm0_4
  survarium::client_player_state *v8; // esi
  vostok::animation::mixing::n_ary_tree *v9; // ecx
  survarium::player *v10; // ecx
  vostok::animation::mixing::n_ary_tree *v11; // ecx
  float z; // edx
  float angle; // [esp+10h] [ebp-FCh] BYREF
  vostok::math::float3 axe; // [esp+14h] [ebp-F8h] BYREF
  float v15; // [esp+20h] [ebp-ECh]
  vostok::math::quaternion previous_rotation; // [esp+24h] [ebp-E8h] BYREF
  vostok::animation::mixing::n_ary_tree *p_m_mixing_tree; // [esp+34h] [ebp-D8h]
  vostok::math::quaternion v18; // [esp+38h] [ebp-D4h]
  vostok::math::float4x4 new_transform; // [esp+48h] [ebp-C4h] BYREF
  vostok::math::float4x4 animated_object; // [esp+88h] [ebp-84h] BYREF
  vostok::math::float4x4 result; // [esp+C8h] [ebp-44h] BYREF

  if ( previous_input->animation_player.m_mixing_tree.m_animations_count )
  {
    vostok::animation::mixing::n_ary_tree::get_object_transform(
      (vostok::animation::mixing::n_ary_tree *)&animated_object,
      (vostok::math::float4x4 *)&previous_input->animation_player.m_mixing_tree,
      &animated_object);
    p_animated_object = (const survarium::player_input *)&animated_object;
  }
  else
  {
    p_animated_object = (const survarium::player_input *)&previous_input->transform;
  }
  qmemcpy((void *)&new_transform, p_animated_object, sizeof(new_transform));
  vostok::math::quaternion::quaternion(&previous_rotation, &previous_input->transform);
  vostok::math::quaternion::quaternion((vostok::math::quaternion *)&axe, &new_transform);
  v6 = -previous_rotation.x;
  v18 = previous_rotation;
  v7 = -previous_rotation.y;
  previous_rotation.w = (float)((float)((float)(previous_rotation.w * v15) - (float)(axe.x * (float)-previous_rotation.x))
                              - (float)(axe.y * (float)-previous_rotation.y))
                      - (float)(axe.z * (float)-previous_rotation.z);
  previous_rotation.x = (float)((float)((float)(axe.z * (float)-previous_rotation.y) + (float)(v18.w * axe.x))
                              + (float)(v15 * (float)-previous_rotation.x))
                      - (float)(axe.y * (float)-previous_rotation.z);
  previous_rotation.y = (float)((float)((float)(v18.w * axe.y) - (float)(axe.z * v6))
                              + (float)(v15 * (float)-previous_rotation.y))
                      + (float)((float)-previous_rotation.z * axe.x);
  previous_rotation.z = (float)((float)((float)(v18.w * axe.z) + (float)(axe.y * v6)) - (float)(v7 * axe.x))
                      + (float)(v15 * (float)-previous_rotation.z);
  vostok::math::quaternion::get_axis_and_angle(&previous_rotation, &axe, &angle);
  v8 = (survarium::client_player_state *)player_state;
  p_m_mixing_tree = &previous_input->animation_player.m_mixing_tree;
  vostok::animation::mixing::n_ary_tree::set_object_transform(v9, player_state, &previous_input->transform);
  if ( player_state->is_local )
  {
    axe.x = (float)((float)((float)(*(float *)((char *)&dword_10ED8 + (_DWORD)player_state) * time_deltaa) * 0.5)
                  + *time_delta)
          * time_deltaa;
    axe.y = (float)((float)((float)(*(float *)((char *)&dword_10EDC + (_DWORD)player_state) * time_deltaa) * 0.5)
                  + time_delta[1])
          * time_deltaa;
    survarium::player::apply_input(v10, previous_input, (const vostok::math::float2 *)&axe);
  }
  v11 = (vostok::animation::mixing::n_ary_tree *)(LODWORD(angle) & 0x7FFFFFFF);
  LODWORD(angle) &= ~0x80000000;
  if ( angle >= 0.0000001 )
  {
    memset(&axe, 0, sizeof(axe));
    vostok::math::create_matrix(&previous_rotation, &axe);
    vostok::math::mul4x3(&result, &animated_object, &previous_input->transform);
    qmemcpy((void *)&previous_input->transform, &result, sizeof(previous_input->transform));
    v11 = 0;
    v8 = (survarium::client_player_state *)player_state;
  }
  z = new_transform.c.z;
  *(_QWORD *)&previous_input->transform.lines[3].x = *(_QWORD *)&new_transform.lines[3].x;
  previous_input->transform.c.z = z;
  vostok::animation::mixing::n_ary_tree::set_object_transform(v11, v8, &previous_input->transform);
}
