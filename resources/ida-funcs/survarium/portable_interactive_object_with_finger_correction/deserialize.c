void __thiscall survarium::portable_interactive_object_with_finger_correction::deserialize(
        survarium::portable_interactive_object_with_finger_correction *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader,
        unsigned int time_offset)
{
  survarium::portable_interactive_object::deserialize(this, reader, client_reader, time_offset);
  if ( client_reader )
  {
    vostok::animation::fingers_to_weapon_corrector::deserialize(&this->m_fingers_corrector, client_reader, time_offset);
  }
  else
  {
    this->m_fingers_corrector.m_hands[0].start_transition_time_in_ms = 0;
    this->m_fingers_corrector.m_hands[1].start_transition_time_in_ms = 0;
  }
}
