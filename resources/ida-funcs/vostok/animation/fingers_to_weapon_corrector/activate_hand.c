void __userpurge vostok::animation::fingers_to_weapon_corrector::activate_hand(
        vostok::animation::fingers_to_weapon_corrector::hands_enum hand@<eax>,
        bool is_active@<dl>,
        vostok::animation::fingers_to_weapon_corrector *this,
        vostok::animation::fingers_to_weapon_corrector::fingers_locator_set_id_enum __formal,
        unsigned int locator_set_id,
        unsigned int current_time_in_ms)
{
  vostok::animation::fingers_to_weapon_corrector::hand *v6; // eax
  vostok::animation::fingers_to_weapon_corrector::fingers_locator_set_id_enum *p_locator_set_id; // ecx

  v6 = &this->m_hands[hand];
  if ( v6->is_active != is_active || v6->locator_set_id != __formal )
  {
    p_locator_set_id = &v6->locator_set_id;
    v6->previous_locator_set_id = v6->locator_set_id;
    if ( is_active )
      *p_locator_set_id = __formal;
    else
      *p_locator_set_id = fingers_locator_set_id_count;
    v6->is_active = is_active;
    v6->start_transition_time_in_ms = locator_set_id;
  }
}
