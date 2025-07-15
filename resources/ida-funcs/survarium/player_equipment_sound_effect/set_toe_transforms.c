void __fastcall survarium::player_equipment_sound_effect::set_toe_transforms(
        const vostok::math::float4x4 *right_toe_transform,
        const vostok::math::float4x4 *left_toe_transform,
        survarium::player_equipment_sound_effect *this)
{
  *(_QWORD *)&this->m_left_toe_position.x = *(_QWORD *)&left_toe_transform->lines[3].x;
  this->m_left_toe_position.z = left_toe_transform->c.z;
  *(_QWORD *)&this->m_left_toe_rotation.x = *(_QWORD *)&left_toe_transform->lines[2].x;
  this->m_left_toe_rotation.z = left_toe_transform->k.z;
  *(_QWORD *)&this->m_right_toe_position.x = *(_QWORD *)&right_toe_transform->lines[3].x;
  this->m_right_toe_position.z = right_toe_transform->c.z;
  *(_QWORD *)&this->m_right_toe_rotation.x = *(_QWORD *)&right_toe_transform->lines[2].x;
  this->m_right_toe_rotation.z = right_toe_transform->k.z;
  this->m_toe_transforms_are_actual = 1;
}
