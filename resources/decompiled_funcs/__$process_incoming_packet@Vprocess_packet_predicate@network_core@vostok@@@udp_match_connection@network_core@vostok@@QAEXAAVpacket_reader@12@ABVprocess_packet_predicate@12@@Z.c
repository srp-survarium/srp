void __thiscall vostok::network_core::udp_match_connection::process_incoming_packet<vostok::network_core::process_packet_predicate>(
        vostok::network_core::udp_match_connection *this,
        vostok::network_core::packet_reader *reader,
        const vostok::network_core::process_packet_predicate *predicate)
{
  vostok::network_core::packet_reader *v3; // ecx
  vostok::network_core::packet_reader *v4; // ecx
  vostok::network_core::packet_reader *v5; // ecx
  vostok::network_core::packet_reader *v6; // ecx
  int v7; // ecx
  vostok::network_core::packet_reader *v8; // ecx
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v9; // ecx
  vostok::network_core::packet_reader *v10; // ecx
  int v11; // eax
  int v12; // [esp-Ch] [ebp-114h] BYREF
  _DWORD v13[2]; // [esp-8h] [ebp-110h] BYREF
  vostok::network_core::udp_match_connection *thisa; // [esp+0h] [ebp-108h]
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v15; // [esp+8h] [ebp-100h]
  int *v16; // [esp+A8h] [ebp-60h]
  _DWORD *v17; // [esp+ACh] [ebp-5Ch]
  vostok::network_core::packet_reader *v18; // [esp+B6h] [ebp-52h]
  unsigned __int16 v19; // [esp+BEh] [ebp-4Ah]
  _DWORD v20[4]; // [esp+C4h] [ebp-44h] BYREF
  vostok::network_core::packet_reader subpacket_reader; // [esp+D4h] [ebp-34h] BYREF
  unsigned __int8 subpacket_size; // [esp+DFh] [ebp-29h]
  unsigned int i; // [esp+E0h] [ebp-28h]
  unsigned __int16 local_acknowledgement_bits; // [esp+E4h] [ebp-24h]
  unsigned __int16 v25; // [esp+E8h] [ebp-20h] BYREF
  unsigned int message_bytes; // [esp+ECh] [ebp-1Ch]
  unsigned __int16 bits; // [esp+F0h] [ebp-18h]
  const vostok::network_core::sequence_number<unsigned short> *remote_sequence_id; // [esp+F4h] [ebp-14h]
  __int16 v29; // [esp+F8h] [ebp-10h] BYREF
  const vostok::network_core::sequence_number<unsigned short> *local_sequence_id; // [esp+FCh] [ebp-Ch]
  vostok::network_core::udp_match_packets_count_enum packet_type; // [esp+100h] [ebp-8h]
  unsigned int packet_bytes; // [esp+104h] [ebp-4h]

  thisa = this;
  vostok::network_core::udp_match_connection::dump(this, &stru_984D24.m_working_macro_list.m_buffer[1].m_store[292], 0);
  vostok::threading::interlocked_exchange_pointer(
    &thisa->m_last_receive_time_in_ms,
    thisa->m_last_send_attempt_time_in_ms);
  v3 = (vostok::network_core::packet_reader *)thisa;
  ++thisa->m_stats.received.packets.count;
  message_bytes = vostok::network_core::packet_reader::size_to_eof(v3, reader);
  packet_bytes = message_bytes + 46;
  thisa->m_stats.received.packets.bytes += message_bytes + 46;
  v4 = (vostok::network_core::packet_reader *)thisa;
  thisa->m_stats.received.messages.bytes += message_bytes;
  v19 = vostok::network_core::packet_reader::r<unsigned short>(v4, (int)reader);
  v25 = v19;
  remote_sequence_id = (const vostok::network_core::sequence_number<unsigned short> *)&v25;
  LOWORD(v18) = vostok::network_core::packet_reader::r<unsigned short>(v5, (int)reader);
  LOWORD(v6) = (_WORD)v18;
  v29 = (__int16)v18;
  local_sequence_id = (const vostok::network_core::sequence_number<unsigned short> *)&v29;
  bits = vostok::network_core::packet_reader::r<unsigned short>(v6, (int)reader);
  local_acknowledgement_bits = ((int)bits >> 1) | 0x8000;
  if ( thisa->m_remote_sequence_id.m_number == remote_sequence_id->m_number )
  {
    ++thisa->m_stats.received_duplicated.packets.count;
    thisa->m_stats.received_duplicated.packets.bytes += packet_bytes;
    thisa->m_stats.received_duplicated.messages.bytes += message_bytes;
    vostok::network_core::udp_match_connection::dump(
      thisa,
      &stru_984D24.m_working_macro_list.m_buffer[1].m_store[320],
      0);
  }
  else
  {
    if ( vostok::network_core::sequence_number<unsigned short>::operator<(
           &thisa->m_remote_sequence_id,
           remote_sequence_id) )
    {
      v7 = local_acknowledgement_bits;
      v13[1] = local_acknowledgement_bits;
      v13[0] = local_acknowledgement_bits;
      v17 = v13;
      LOWORD(v7) = (vostok::network_core::sequence_number<unsigned short>)local_sequence_id->m_number;
      v12 = v7;
      v16 = &v12;
      vostok::network_core::udp_match_connection::update_acknowledgements(
        thisa,
        (vostok::network_core::sequence_number<unsigned short>)remote_sequence_id->m_number,
        (vostok::network_core::sequence_number<unsigned short>)v7,
        local_acknowledgement_bits);
    }
    packet_type = (bits & 1) != 0;
    if ( (bits & 1) != 0 )
    {
      i = 0;
      while ( !vostok::network_core::packet_reader::eof(reader) )
      {
        v8 = (vostok::network_core::packet_reader *)thisa;
        ++thisa->m_stats.received.messages.count;
        subpacket_size = vostok::network_core::packet_reader::r<unsigned char>(v8, (int)reader);
        v9 = (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)(thisa->m_stats.received.data_bytes + subpacket_size);
        thisa->m_stats.received.data_bytes = (unsigned int)v9;
        v15 = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(v9, (int)reader);
        v20[0] = v15;
        v20[1] = subpacket_size;
        subpacket_reader.m_packet = (const vostok::network_core::base_packet *)v20;
        subpacket_reader.m_pointer = (const unsigned __int8 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                                v15,
                                                                (int)v20);
        vostok::network_core::packet_reader::advance(reader, subpacket_size);
        if ( !i && vostok::network_core::packet_reader::eof(reader) )
        {
          ++thisa->m_stats.received_low_level.packets.count;
          thisa->m_stats.received_low_level.packets.bytes += packet_bytes;
          ++thisa->m_stats.received_low_level.messages.count;
          v10 = (vostok::network_core::packet_reader *)thisa;
          thisa->m_stats.received_low_level.messages.bytes += message_bytes;
          v11 = vostok::network_core::packet_reader::size_to_eof(v10, &subpacket_reader);
          thisa->m_stats.received_low_level.data_bytes += v11;
          vostok::network_core::udp_match_connection::process_low_level_message(
            thisa,
            &subpacket_reader,
            thisa->m_last_send_attempt_time_in_ms);
        }
        else
        {
          vostok::network_core::udp_match_connection::call_predicate<vostok::network_core::process_packet_predicate>(
            thisa,
            predicate,
            &subpacket_reader);
        }
        ++i;
      }
      vostok::network_core::udp_match_connection::dump(
        thisa,
        &stru_984D24.m_working_macro_list.m_buffer[1].m_store[320],
        0);
    }
    else
    {
      ++thisa->m_stats.received.messages.count;
      thisa->m_stats.received.data_bytes += message_bytes;
      vostok::network_core::udp_match_connection::call_predicate<vostok::network_core::process_packet_predicate>(
        thisa,
        predicate,
        reader);
      vostok::network_core::udp_match_connection::dump(
        thisa,
        &stru_984D24.m_working_macro_list.m_buffer[1].m_store[320],
        0);
    }
  }
}
