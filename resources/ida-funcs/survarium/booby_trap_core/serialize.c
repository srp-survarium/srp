void __thiscall survarium::booby_trap_core::serialize(
        survarium::booby_trap_core *this,
        vostok::network_core::udp_match_packet *packet)
{
  survarium::game_camera *v2; // ecx
  vostok::math::float3 *v3; // eax
  vostok::math::float4x4 *v4; // ecx
  vostok::math::float3 *angles; // eax
  vostok::math::float3 *v6; // [esp+0h] [ebp-34h]
  vostok::math::axis_rotation_order v7; // [esp+4h] [ebp-30h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_owner->serialize_game_world_object_header(this->m_owner, this, packet);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, this->m_trap_state);
  survarium::weapon_user_dead_state::finalize(v2);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, v3);
  angles = vostok::math::float4x4::get_angles(v4, v6, v7);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, angles);
}
