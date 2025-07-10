void __thiscall survarium::inventory_item::serialize(
        survarium::inventory_item *this,
        vostok::network_core::udp_match_packet *packet,
        unsigned int client_offset)
{
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, this->m_amount);
}
