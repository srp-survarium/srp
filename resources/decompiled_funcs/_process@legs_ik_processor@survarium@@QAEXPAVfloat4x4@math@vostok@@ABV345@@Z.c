void __thiscall survarium::legs_ik_processor::process(
        survarium::legs_ik_processor *this,
        vostok::math::float4x4 *matrices,
        const vostok::math::float4x4 *transform)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  _BYTE *v5; // eax
  const vostok::math::float4x4 *v6; // eax
  const vostok::math::float4x4 *v7; // eax
  const vostok::math::float4x4 *v8; // eax
  const vostok::math::float4x4 *v9; // eax
  const vostok::math::float4x4 *v10; // eax
  const vostok::math::float4x4 *v11; // eax
  bool v12; // [esp+10h] [ebp-3B4h]
  bool v13; // [esp+14h] [ebp-3B0h]
  vostok::math::float4x4 v15; // [esp+58h] [ebp-36Ch] BYREF
  vostok::math::float4x4 v16; // [esp+98h] [ebp-32Ch] BYREF
  vostok::math::float4x4 v17; // [esp+D8h] [ebp-2ECh] BYREF
  vostok::math::float4x4 v18; // [esp+118h] [ebp-2ACh] BYREF
  vostok::math::float4x4 v19; // [esp+158h] [ebp-26Ch] BYREF
  vostok::math::float4x4 v20; // [esp+198h] [ebp-22Ch] BYREF
  vostok::math::float4x4 v21; // [esp+1D8h] [ebp-1ECh] BYREF
  vostok::math::float4x4 v22; // [esp+218h] [ebp-1ACh] BYREF
  char v23; // [esp+25Bh] [ebp-169h]
  vostok::math::float4x4 inverted_transform; // [esp+25Ch] [ebp-168h] BYREF
  float right_delta_len; // [esp+2A0h] [ebp-124h] BYREF
  vostok::math::float4x4 result; // [esp+2A4h] [ebp-120h] BYREF
  float left_delta_len; // [esp+2E8h] [ebp-DCh] BYREF
  vostok::math::float4x4 hip_obj_matrix; // [esp+2ECh] [ebp-D8h] BYREF
  const vostok::math::float4x4 *right_foot_fixed_transform; // [esp+330h] [ebp-94h]
  vostok::math::float4x4 v30; // [esp+334h] [ebp-90h] BYREF
  const vostok::math::float4x4 *hip_world_matrix; // [esp+378h] [ebp-4Ch]
  bool success; // [esp+37Fh] [ebp-45h]
  const vostok::math::float4x4 *left_foot_fixed_transform; // [esp+380h] [ebp-44h]
  vostok::math::float4x4 v34; // [esp+384h] [ebp-40h] BYREF

  survarium::get_bone_matrix_in_object_space(&hip_obj_matrix, this->m_hip_bone, this->m_skeleton, matrices);
  vostok::math::operator*(&result, &hip_obj_matrix, transform);
  hip_world_matrix = &result;
  left_delta_len = *(float *)&FLOAT_0_0;
  survarium::legs_ik_processor::get_foot_fixed_transform(
    this,
    &v34,
    (survarium::game_camera *)&this->m_left_leg_params,
    &result,
    matrices,
    &left_delta_len);
  left_foot_fixed_transform = &v34;
  right_delta_len = *(float *)&FLOAT_0_0;
  survarium::legs_ik_processor::get_foot_fixed_transform(
    this,
    &v30,
    (survarium::game_camera *)&this->m_right_leg_params,
    hip_world_matrix,
    matrices,
    &right_delta_len);
  right_foot_fixed_transform = &v30;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&inverted_transform);
  success = vostok::math::float4x4::try_invert(&inverted_transform, transform);
  v23 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  if ( *v5 )
    survarium::weapon_user_dead_state::finalize(v4);
  if ( s_ik_adjust_hip_position_value && (left_delta_len < 0.0 || right_delta_len < 0.0) )
  {
    v13 = this->m_left_leg_params.m_heel_on_ground || this->m_left_leg_params.m_toe_on_ground;
    if ( v13 && left_delta_len < 0.0 && right_delta_len > 0.0 )
    {
      matrices->c.y = matrices->c.y + left_delta_len;
      qmemcpy(
        (void *)&hip_obj_matrix,
        survarium::get_bone_matrix_in_object_space(&v20, this->m_hip_bone, this->m_skeleton, matrices),
        sizeof(hip_obj_matrix));
      v8 = vostok::math::operator*(&v19, left_foot_fixed_transform, &inverted_transform);
      survarium::legs_ik_processor::process_leg(
        this,
        (vostok::animation::skeleton *)&this->m_left_leg_params,
        v8,
        &hip_obj_matrix,
        matrices,
        transform);
      v9 = vostok::math::operator*(&v18, right_foot_fixed_transform, &inverted_transform);
      survarium::legs_ik_processor::process_leg(
        this,
        (vostok::animation::skeleton *)&this->m_right_leg_params,
        v9,
        &hip_obj_matrix,
        matrices,
        transform);
    }
    else
    {
      v12 = this->m_right_leg_params.m_heel_on_ground || this->m_right_leg_params.m_toe_on_ground;
      if ( v12 && left_delta_len > 0.0 && right_delta_len < 0.0 )
      {
        matrices->c.y = matrices->c.y + right_delta_len;
        qmemcpy(
          (void *)&hip_obj_matrix,
          survarium::get_bone_matrix_in_object_space(&v17, this->m_hip_bone, this->m_skeleton, matrices),
          sizeof(hip_obj_matrix));
        v10 = vostok::math::operator*(&v16, left_foot_fixed_transform, &inverted_transform);
        survarium::legs_ik_processor::process_leg(
          this,
          (vostok::animation::skeleton *)&this->m_left_leg_params,
          v10,
          &hip_obj_matrix,
          matrices,
          transform);
        v11 = vostok::math::operator*(&v15, right_foot_fixed_transform, &inverted_transform);
        survarium::legs_ik_processor::process_leg(
          this,
          (vostok::animation::skeleton *)&this->m_right_leg_params,
          v11,
          &hip_obj_matrix,
          matrices,
          transform);
      }
    }
  }
  else
  {
    v6 = vostok::math::operator*(&v22, left_foot_fixed_transform, &inverted_transform);
    survarium::legs_ik_processor::process_leg(
      this,
      (vostok::animation::skeleton *)&this->m_left_leg_params,
      v6,
      &hip_obj_matrix,
      matrices,
      transform);
    v7 = vostok::math::operator*(&v21, right_foot_fixed_transform, &inverted_transform);
    survarium::legs_ik_processor::process_leg(
      this,
      (vostok::animation::skeleton *)&this->m_right_leg_params,
      v7,
      &hip_obj_matrix,
      matrices,
      transform);
  }
}
