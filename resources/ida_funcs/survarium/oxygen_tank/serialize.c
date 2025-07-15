void __thiscall survarium::oxygen_tank::serialize(
        survarium::weapon_ammunition *this,
        vostok::network_core::udp_match_packet *packet,
        unsigned int client_offset)
{
  survarium::inventory_item::serialize(this, packet, client_offset);
}
