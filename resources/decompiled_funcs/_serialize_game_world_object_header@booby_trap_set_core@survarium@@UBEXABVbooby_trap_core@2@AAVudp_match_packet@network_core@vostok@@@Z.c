void __thiscall survarium::booby_trap_set_core::serialize_game_world_object_header(
        survarium::booby_trap_set_core *this,
        survarium::booby_trap_core *trap,
        vostok::network_core::udp_match_packet *packet)
{
  unsigned __int8 v3; // al

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = survarium::booby_trap_set_core::trap_index(this, trap);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, v3);
}
