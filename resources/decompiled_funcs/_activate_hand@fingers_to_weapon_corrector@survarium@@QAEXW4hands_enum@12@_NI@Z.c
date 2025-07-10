void __userpurge survarium::fingers_to_weapon_corrector::activate_hand(
        const survarium::fingers_to_weapon_corrector::hands_enum hand@<eax>,
        char is_active@<cl>,
        survarium::fingers_to_weapon_corrector *this,
        unsigned int current_time_in_ms)
{
  survarium::fingers_to_weapon_corrector::hand *v4; // eax

  v4 = &this->m_hands[hand];
  if ( v4->is_active != is_active )
  {
    v4->is_active = is_active;
    v4->start_transition_time_in_ms = current_time_in_ms;
  }
}
