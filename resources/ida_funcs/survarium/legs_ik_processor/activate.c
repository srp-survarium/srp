void __thiscall survarium::legs_ik_processor::activate(
        survarium::legs_ik_processor *this,
        vostok::animation::skeleton *skeleton)
{
  unsigned int bone_index; // eax
  survarium::legs_ik_processor *thisb; // [esp+0h] [ebp-Ch]

  survarium::ik_processor::activate(this, skeleton);
  survarium::legs_ik_processor::leg_params::activate(
    &this->m_left_leg_params,
    skeleton,
    (vostok::animation::skeleton *)"LeftFoot");
  survarium::legs_ik_processor::leg_params::activate(
    &this->m_right_leg_params,
    skeleton,
    (vostok::animation::skeleton *)"RightFoot");
  bone_index = vostok::animation::skeleton::get_bone_index(
                 (vostok::animation::skeleton *)&stru_977EF0.m_last_fail_of_increasing_quality,
                 (const char *)this);
  thisb->m_hip_bone = vostok::animation::skeleton::get_bone(skeleton, bone_index);
}
