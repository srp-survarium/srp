void __thiscall survarium::hand_to_weapon_ik_processor::process(
        survarium::hand_to_weapon_ik_processor *this,
        unsigned int current_time_in_ms,
        const vostok::math::float4x4 *weapon_matrices,
        vostok::math::float4x4 *user_matrices)
{
  const vostok::animation::skeleton_bone *bone; // eax
  vostok::animation::skeleton *m_skeleton; // [esp-4h] [ebp-1A4h]
  float hand_coefficient; // [esp+0h] [ebp-1A0h]
  vostok::math::float4x4 v8; // [esp+80h] [ebp-120h] BYREF
  const vostok::math::float4x4 *hand_transform; // [esp+C4h] [ebp-DCh]
  vostok::math::float4x4 coeff; // [esp+C8h] [ebp-D8h] BYREF
  const vostok::math::float4x4 *locator_transform; // [esp+10Ch] [ebp-94h]
  vostok::math::float4x4 v12; // [esp+110h] [ebp-90h] BYREF
  const survarium::hand_to_weapon_ik_processor::hand *h; // [esp+150h] [ebp-50h]
  const vostok::animation::skeleton_bone *weapon_bone; // [esp+154h] [ebp-4Ch]
  vostok::math::float4x4 result; // [esp+158h] [ebp-48h] BYREF
  const vostok::math::float4x4 *weapon_transform; // [esp+19Ch] [ebp-4h]

  weapon_bone = vostok::animation::skeleton::get_bone(
                  (vostok::animation::skeleton *)this->m_skeleton,
                  this->m_weapon_bone_index);
  survarium::get_bone_matrix_in_object_space(&result, weapon_bone, this->m_skeleton, user_matrices);
  weapon_transform = &result;
  for ( h = (const survarium::hand_to_weapon_ik_processor::hand *)this;
        h != (const survarium::hand_to_weapon_ik_processor::hand *)&this->m_interpolator;
        ++h )
  {
    if ( survarium::hand_to_weapon_ik_processor::hand_need_correction(h, current_time_in_ms) )
    {
      vostok::math::operator*(&v12, &weapon_matrices[h->locator_matrix_index], weapon_transform);
      locator_transform = &v12;
      if ( survarium::hand_to_weapon_ik_processor::hand_need_interpolation(h, current_time_in_ms) )
      {
        m_skeleton = (vostok::animation::skeleton *)this->m_skeleton;
        bone = vostok::animation::skeleton::get_bone(m_skeleton, h->hand_bone_index);
        survarium::get_bone_matrix_in_object_space(&v8, bone, m_skeleton, user_matrices);
        hand_transform = &v8;
        hand_coefficient = survarium::hand_to_weapon_ik_processor::get_hand_coefficient(this, h, current_time_in_ms);
        survarium::mix_transformations(locator_transform, hand_transform, (int)&coeff, hand_coefficient);
        survarium::hand_to_weapon_ik_processor::process_hand(this, (survarium::game_camera *)h, &coeff, user_matrices);
      }
      else
      {
        survarium::hand_to_weapon_ik_processor::process_hand(
          this,
          (survarium::game_camera *)h,
          locator_transform,
          user_matrices);
      }
    }
  }
}
