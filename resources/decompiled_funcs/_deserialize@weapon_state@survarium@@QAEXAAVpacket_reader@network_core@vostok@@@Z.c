void __thiscall survarium::weapon_state::deserialize(
        survarium::weapon_state *this,
        vostok::network_core::packet_reader *packet)
{
  vostok::network_core::packet_reader *v2; // ecx

  this->slot_id = vostok::network_core::packet_reader::r<unsigned char>(
                    (vostok::network_core::packet_reader *)this,
                    (int)packet);
  this->ammo_slot_id = vostok::network_core::packet_reader::r<unsigned char>(
                         (vostok::network_core::packet_reader *)this,
                         (int)packet);
  this->state = vostok::network_core::packet_reader::r<unsigned char>(v2, (int)packet);
}
