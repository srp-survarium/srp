void __cdecl survarium::deserialize_affect(
        vostok::network_core::packet_reader *reader,
        stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *affect)
{
  vostok::network_core::packet_reader *v2; // ecx
  survarium::game_camera *v3; // ecx

  affect->first = vostok::network_core::packet_reader::r<unsigned char>(v2, (int)reader);
  affect->second = vostok::network_core::packet_reader::r<unsigned int>(
                     (vostok::network_core::packet_reader *)affect,
                     (int)reader);
  survarium::weapon_user_dead_state::finalize(v3);
}
