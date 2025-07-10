void __thiscall survarium::hand_to_weapon_ik_processor::hand_to_weapon_ik_processor(
        survarium::hand_to_weapon_ik_processor *this)
{
  vostok::animation::linear_interpolator *v1; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  `vector constructor iterator'(
    (char *)this,
    0x14u,
    2,
    (void *(__thiscall *)(void *))survarium::hand_to_weapon_ik_processor::hand::hand);
  vostok::animation::linear_interpolator::linear_interpolator(
    v1,
    &this->m_interpolator.__vftable,
    SLODWORD(s_aim_transition_time));
  this->m_current_transition_time = *(float *)&FLOAT_0_0;
  this->m_active = 1;
}
