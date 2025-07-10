double __thiscall survarium::hand_to_weapon_ik_processor::get_hand_coefficient(
        survarium::hand_to_weapon_ik_processor *this,
        const survarium::hand_to_weapon_ik_processor::hand *h,
        unsigned int current_time_in_ms)
{
  float hand_transition_time; // [esp+1Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  hand_transition_time = (double)(current_time_in_ms - h->start_transition_time_in_ms) / 1000.0;
  if ( h->is_active )
    return (float)(1.0
                 - ((double (__thiscall *)(vostok::animation::linear_interpolator *, _DWORD))this->m_interpolator.interpolated_value)(
                     &this->m_interpolator,
                     LODWORD(hand_transition_time)));
  else
    return (float)((double (__thiscall *)(vostok::animation::linear_interpolator *, _DWORD))this->m_interpolator.interpolated_value)(
                    &this->m_interpolator,
                    LODWORD(hand_transition_time));
}
