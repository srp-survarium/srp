void __thiscall survarium::player_input_handler::update_inverted_view(
        survarium::player_input_handler *this,
        survarium::player_input_handler *player_head_transform,
        const vostok::math::float4x4 *player_head_transforma)
{
  vostok::math::float4x4 *p_new_inverted_view; // esi
  double m_yaw; // st7
  vostok::math::float4x4 *rotation_y; // eax
  const vostok::math::float4x4 *rotation; // eax
  float v7; // xmm1_4
  vostok::math::float4x4 *result; // [esp+0h] [ebp-E8h]
  float resulta; // [esp+0h] [ebp-E8h]
  __int64 v10; // [esp+18h] [ebp-D0h]
  float v11; // [esp+20h] [ebp-C8h]
  vostok::math::float4x4 new_inverted_view; // [esp+24h] [ebp-C4h] BYREF
  vostok::math::float4x4 v13; // [esp+64h] [ebp-84h] BYREF
  _QWORD v14[8]; // [esp+A4h] [ebp-44h] BYREF

  p_new_inverted_view = player_head_transforma;
  if ( player_head_transform->m_input_mode )
  {
    m_yaw = player_head_transform->m_yaw;
    qmemcpy((void *)&new_inverted_view, player_head_transforma, sizeof(new_inverted_view));
    *(float *)&result = m_yaw;
    memset(&new_inverted_view.lines[3], 0, 12);
    rotation_y = vostok::math::create_rotation_y(v14, result);
    vostok::math::mul4x3(&v13, &new_inverted_view, rotation_y);
    resulta = player_head_transform->m_pitch;
    qmemcpy((void *)&new_inverted_view, &v13, sizeof(new_inverted_view));
    rotation = vostok::math::create_rotation((const vostok::math::float3 *)&new_inverted_view, resulta);
    vostok::math::mul4x3(&v13, &new_inverted_view, rotation);
    *(float *)&v10 = player_head_transforma->c.x
                   + (float)(player_head_transform->m_distance_to_focus_point
                           * (float)(COERCE_FLOAT(LODWORD(v13.k.x) ^ 0x80000000) + (float)(v13.i.x * 0.2)));
    v7 = player_head_transforma->c.y
       + (float)(player_head_transform->m_distance_to_focus_point
               * (float)(COERCE_FLOAT(LODWORD(v13.k.y) ^ 0x80000000) + (float)(v13.i.y * 0.2)));
    v11 = player_head_transforma->c.z
        + (float)(player_head_transform->m_distance_to_focus_point * (float)((float)(v13.i.z * 0.2) - v13.k.z));
    qmemcpy((void *)&new_inverted_view, &v13, sizeof(new_inverted_view));
    *((float *)&v10 + 1) = v7;
    *(_QWORD *)&new_inverted_view.lines[3].x = v10;
    new_inverted_view.c.z = v11;
    p_new_inverted_view = &new_inverted_view;
  }
  qmemcpy(
    (void *)&player_head_transform->m_inverted_view_matrix,
    p_new_inverted_view,
    sizeof(player_head_transform->m_inverted_view_matrix));
  player_head_transform->m_input_mode_changed = 0;
}
