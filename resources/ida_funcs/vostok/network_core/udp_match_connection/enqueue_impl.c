void __thiscall vostok::network_core::udp_match_connection::enqueue_impl(
        vostok::network_core::udp_match_connection *this,
        vostok::network_core::udp_match_packet *packet)
{
  vostok::network_core::sequence_number<unsigned short> *sent_order_id; // [esp+18h] [ebp-8h]

  if ( *((char *)packet + 42) < 0 )
  {
    sent_order_id = &this->m_channels.elems[*((_BYTE *)packet + 42) & 0x3F].sent_order_id;
    packet->order_id = (vostok::network_core::sequence_number<unsigned short>)sent_order_id->m_number;
    *(vostok::network_core::sequence_number<unsigned short> *)(packet->vostok::network_core::packet<vostok::network_core::udp_match_packet>::vostok::network_core::base_packet::m_buffer
                                                             + 1) = (vostok::network_core::sequence_number<unsigned short>)sent_order_id->m_number++;
  }
  if ( (*((_BYTE *)packet + 42) & 0x40) != 0 )
    ++this->m_stats.unacknowledged_packets;
  vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&this->m_packets_to_send,
    (survarium::game_camera *)packet,
    0);
}
