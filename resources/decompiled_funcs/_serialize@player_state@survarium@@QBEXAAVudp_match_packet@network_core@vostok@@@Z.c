void __thiscall survarium::player_state::serialize(
        survarium::player_state *this,
        vostok::network_core::udp_match_packet *packet)
{
  vostok::math::float3 *v2; // eax
  vostok::math::float4x4 *v3; // ecx
  vostok::math::float3 *angles; // eax
  _BYTE v6[12]; // [esp+28h] [ebp-Ch] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, v2);
  angles = vostok::math::float4x4::get_angles(v3, (int)v6, &this->transform.i.x);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, angles->y);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, this->look_pitch);
}
