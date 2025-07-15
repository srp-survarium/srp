void __thiscall survarium::animation_analyzer::animation_analyzer(
        survarium::animation_analyzer *this,
        const survarium::leg_info *legs_info,
        unsigned int legs_count,
        const vostok::animation::skeleton *skeleton)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_legs_info = legs_info;
  this->m_legs_count = legs_count;
  this->m_skeleton = skeleton;
  this->m_ground_height = *(float *)&FLOAT_0_0;
}
