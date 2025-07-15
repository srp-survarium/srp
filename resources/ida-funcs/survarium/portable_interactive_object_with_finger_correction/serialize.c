void __thiscall survarium::portable_interactive_object_with_finger_correction::serialize(
        survarium::portable_interactive_object_with_finger_correction *this,
        vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *client_writer,
        vostok::network_core::buffer_writer *time_offset)
{
  vostok::animation::fingers_to_weapon_corrector *v5; // ecx

  survarium::portable_interactive_object::serialize(this, writer, client_writer, time_offset);
  if ( client_writer )
    vostok::animation::fingers_to_weapon_corrector::serialize(
      v5,
      (const vostok::network_core::buffer_writer *)&this->m_fingers_corrector,
      client_writer,
      time_offset);
}
