vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *__thiscall vostok::journaling::match_client::new_packet(
        vostok::journaling::match_client *this,
        vostok::match::client::messages_enum message_type)
{
  vostok::network_core::udp_match_packet **p_m_fake_packet; // esi
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *p_m_fake_packet_allocator; // edi
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *result; // eax

  p_m_fake_packet = &this->m_fake_packet;
  p_m_fake_packet_allocator = &this->m_fake_packet_allocator;
  vostok::network_core::delete_udp_match_packet(
    &this->m_fake_packet_allocator,
    (vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node **)&this->m_fake_packet);
  result = vostok::network_core::new_udp_match_packet(p_m_fake_packet_allocator);
  *p_m_fake_packet = (vostok::network_core::udp_match_packet *)result;
  return result;
}
