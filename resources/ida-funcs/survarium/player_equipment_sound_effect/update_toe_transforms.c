void __userpurge survarium::player_equipment_sound_effect::update_toe_transforms(
        survarium::player_equipment_sound_effect *this@<esi>,
        const vostok::math::float4x4 *character_transform@<ecx>,
        const vostok::math::float4x4 *const user_matrices,
        const unsigned int user_matrices_count)
{
  const vostok::math::float4x4 *v4; // ecx
  vostok::math::float4x4 left_toe_transform; // [esp+0h] [ebp-84h] BYREF
  vostok::math::float4x4 right_toe_transform; // [esp+40h] [ebp-44h] BYREF

  vostok::math::mul4x3(character_transform, &user_matrices[this->m_left_toe_bone_index], &left_toe_transform);
  vostok::math::mul4x3(v4, &user_matrices[this->m_right_toe_bone_index], &right_toe_transform);
  survarium::player_equipment_sound_effect::set_toe_transforms(&right_toe_transform, &left_toe_transform, this);
}
