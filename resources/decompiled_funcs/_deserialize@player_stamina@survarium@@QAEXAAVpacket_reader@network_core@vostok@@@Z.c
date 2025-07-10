void __userpurge survarium::player_stamina::deserialize(
        survarium::player_stamina *this@<ecx>,
        float a2@<xmm0>,
        vostok::network_core::packet_reader *packet)
{
  vostok::network_core::packet_reader *v3; // ecx
  vostok::network_core::packet_reader *v4; // ecx

  vostok::network_core::packet_reader::r<float>(packet);
  this->m_value = a2;
  this->m_last_spending_time_in_ms = vostok::network_core::packet_reader::r<unsigned int>(v3, (int)packet);
  this->m_last_tick_time_in_ms = vostok::network_core::packet_reader::r<unsigned int>(
                                   (vostok::network_core::packet_reader *)this,
                                   (int)packet);
  this->m_lower_threshold_was_reached = vostok::network_core::packet_reader::r<unsigned char>(v4, (int)packet);
}
