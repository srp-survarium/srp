void __userpurge vostok::network_core::udp_network_flow_emulator::add_packet(
        unsigned int time_in_ms@<eax>,
        vostok::network_core::udp_network_flow_emulator *this,
        unsigned __int8 *buffer,
        unsigned int buffer_size,
        const boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *endpoint,
        unsigned int unacknowledged_packets_count,
        vostok::network_core::socket_handler *const socket_handler)
{
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *matched; // eax
  unsigned int m_min_ping_time_in_ms; // esi
  vostok::network_core::udp_match_packet *v11; // ecx
  unsigned int m_max_ping_time_in_ms; // eax
  unsigned int v13; // edx
  unsigned __int8 *m_buffer; // edi
  stlp_std::pair<vostok::network_core::udp_match_packet *,stlp_std::pair<boost::asio::ip::basic_endpoint<boost::asio::ip::udp>,vostok::network_core::socket_handler *> > *M_finish; // ecx
  const stlp_std::__false_type *v16; // [esp+0h] [ebp-34h]
  unsigned int v17; // [esp+4h] [ebp-30h]
  bool v18; // [esp+8h] [ebp-2Ch]
  stlp_std::pair<vostok::network_core::udp_match_packet *,stlp_std::pair<boost::asio::ip::basic_endpoint<boost::asio::ip::udp>,vostok::network_core::socket_handler *> > __val; // [esp+10h] [ebp-24h] BYREF
  vostok::network_core::udp_match_packet *v20; // [esp+3Ch] [ebp+8h]

  matched = vostok::network_core::new_udp_match_packet(this->m_packets_allocator);
  m_min_ping_time_in_ms = this->m_min_ping_time_in_ms;
  v11 = (vostok::network_core::udp_match_packet *)matched;
  m_max_ping_time_in_ms = this->m_max_ping_time_in_ms;
  v13 = 134775813 * this->m_ping_random.m_seed + 1;
  this->m_ping_random.m_seed = v13;
  v11->last_send_time_in_ms = time_in_ms
                            + m_min_ping_time_in_ms
                            + ((v13 * (unsigned __int64)(m_max_ping_time_in_ms - m_min_ping_time_in_ms)) >> 32);
  v20 = v11;
  if ( unacknowledged_packets_count
     + this->m_delayed_packets._M_impl._M_finish
     - this->m_delayed_packets._M_impl._M_start >= ((1364 * this->m_packets_allocator->m_max_count) >> 2) - 1 )
    v11->last_send_time_in_ms = time_in_ms;
  m_buffer = v11->m_buffer.m_buffer;
  *(_DWORD *)m_buffer = *(_DWORD *)buffer;
  m_buffer += 4;
  *(_DWORD *)m_buffer = *((_DWORD *)buffer + 1);
  *((_DWORD *)m_buffer + 1) = *((_DWORD *)buffer + 2);
  vostok::network_core::buffer_writer::w(
    &v11->m_writer,
    &v11->m_writer.serialization_operations_descriptors.m_size,
    buffer + 12,
    buffer_size - 12);
  __val.first = v20;
  qmemcpy(&__val.second, endpoint, 0x1Cu);
  M_finish = this->m_delayed_packets._M_impl._M_finish;
  __val.second.second = 0;
  if ( M_finish == this->m_delayed_packets._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<stlp_std::pair<vostok::network_core::udp_match_packet *,stlp_std::pair<boost::asio::ip::basic_endpoint<boost::asio::ip::udp>,vostok::network_core::socket_handler *>>,vostok::vectora_allocator<stlp_std::pair<vostok::network_core::udp_match_packet *,stlp_std::pair<boost::asio::ip::basic_endpoint<boost::asio::ip::udp>,vostok::network_core::socket_handler *>>>>::_M_insert_overflow_aux(
      (stlp_std::priv::_Impl_vector<stlp_std::pair<vostok::network_core::udp_match_packet *,stlp_std::pair<boost::asio::ip::basic_endpoint<boost::asio::ip::udp>,vostok::network_core::socket_handler *> >,vostok::vectora_allocator<stlp_std::pair<vostok::network_core::udp_match_packet *,stlp_std::pair<boost::asio::ip::basic_endpoint<boost::asio::ip::udp>,vostok::network_core::socket_handler *> > > > *)M_finish,
      &this->m_delayed_packets._M_impl._M_start,
      M_finish,
      &__val,
      v16,
      v17,
      v18);
  }
  else
  {
    stlp_std::_Copy_Construct<stlp_std::pair<vostok::network_core::udp_match_packet *,stlp_std::pair<boost::asio::ip::basic_endpoint<boost::asio::ip::udp>,vostok::network_core::socket_handler *>>>(
      M_finish,
      &__val);
    ++this->m_delayed_packets._M_impl._M_finish;
  }
}
