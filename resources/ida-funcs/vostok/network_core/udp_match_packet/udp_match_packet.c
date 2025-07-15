void __thiscall vostok::network_core::udp_match_packet::udp_match_packet(vostok::network_core::udp_match_packet *this)
{
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::packet<vostok::network_core::udp_match_packet>(
    this,
    (vostok::mutable_buffer *)this);
  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_Impl_vector<void *,survarium::std_allocator<void *>>(
    (survarium::vector<vostok::resources::request> *)1,
    &this->set_member_hook.parent_);
  this->next = 0;
  this->last_send_time_in_ms = -1;
  this->sequence_id.m_number = -1;
  this->order_id.m_number = -1;
  this->send_count = 0;
  *((_BYTE *)this + 42) |= 0x3Fu;
  *((_BYTE *)this + 42) &= ~0x40u;
  *((_BYTE *)this + 42) &= ~0x80u;
  this->vostok::network_core::packet<vostok::network_core::udp_match_packet>::vostok::network_core::base_packet::m_buffer = &this->m_buffer.elems[6];
  this->m_buffer.elems[0] = 0;
}
