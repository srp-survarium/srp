void __userpurge survarium::weapon_core_base_state::deserialize(
        survarium::weapon_core_base_state *this@<ecx>,
        float a2@<xmm0>,
        vostok::network_core::packet_reader *reader)
{
  vostok::network_core::packet_reader *m_serialize_animation_state; // ecx

  m_serialize_animation_state = (vostok::network_core::packet_reader *)this->m_serialize_animation_state;
  if ( m_serialize_animation_state )
  {
    this->m_animation_playback_state.interval_id = vostok::network_core::packet_reader::r<unsigned int>(
                                                     m_serialize_animation_state,
                                                     (int)reader);
    vostok::network_core::packet_reader::r<float>(reader);
    this->m_animation_playback_state.interval_time = a2;
  }
}
