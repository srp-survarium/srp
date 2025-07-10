unsigned int __thiscall survarium::weapon_cook::cooked_object_size(
        survarium::weapon_cook *this,
        survarium::weapon_core *object_to_cook)
{
  return 4
       * (*(_DWORD *)&object_to_cook[3].m_legs_ik_processor.m_left_leg_params.m_heel_on_ground
        + object_to_cook[3].m_legs_ik_processor.m_right_leg_params.foot_bone_index
        + object_to_cook[3].m_legs_ik_processor.m_right_leg_params.toe_bone_index)
       + 4080;
}
