void __thiscall survarium::weapon_core_reload_state_base::deserialize(
        survarium::weapon_core_reload_state_base *this,
        vostok::network_core::packet_reader *reader)
{
  this->m_animation_has_been_ended = vostok::network_core::packet_reader::r<unsigned char>(
                                       (vostok::network_core::packet_reader *)this,
                                       (int)reader);
}
