vostok::animation::callback_return_type_enum __thiscall survarium::weapon::on_hand_correction_event(
        survarium::weapon *this,
        vostok::animation::animation_callback_params *params,
        survarium::fingers_to_weapon_corrector::hands_enum hand)
{
  unsigned int callback_time_in_ms; // esi
  bool v4; // dl

  callback_time_in_ms = params->callback_time_in_ms;
  v4 = params->domain_data == 9;
  if ( this->m_fingers_corrector.m_hands[hand].is_active != v4 )
  {
    this->m_fingers_corrector.m_hands[hand].is_active = v4;
    this->m_fingers_corrector.m_hands[hand].start_transition_time_in_ms = callback_time_in_ms;
  }
  return 0;
}
