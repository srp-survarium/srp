void __thiscall survarium::hand_to_weapon_ik_processor::activate_hand(
        survarium::hand_to_weapon_ik_processor *this,
        survarium::hand_to_weapon_ik_processor::hands_enum hand,
        bool active,
        unsigned int current_time_in_ms)
{
  if ( this->m_hands[hand].is_active != active )
  {
    this->m_hands[hand].is_active = active;
    this->m_hands[hand].start_transition_time_in_ms = survarium::hand_to_weapon_ik_processor::get_hand_new_start_transition_time(
                                                        &this->m_hands[hand],
                                                        current_time_in_ms);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(20 * hand));
  }
}
