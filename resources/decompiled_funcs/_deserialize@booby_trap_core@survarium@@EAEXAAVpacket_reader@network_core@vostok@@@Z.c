void __thiscall survarium::booby_trap_core::deserialize(
        survarium::booby_trap_core *this,
        vostok::network_core::packet_reader *reader)
{
  vostok::network_core::packet_reader *v2; // ecx
  vostok::network_core::packet_reader *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  const vostok::math::float4x4 *v6; // eax
  const vostok::math::float4x4 *v7; // [esp-4h] [ebp-24Ch]
  vostok::math::float4x4 v9; // [esp+168h] [ebp-E0h] BYREF
  vostok::math::float4x4 result; // [esp+1A8h] [ebp-A0h] BYREF
  char v11; // [esp+1EAh] [ebp-5Eh]
  char v12; // [esp+1EBh] [ebp-5Dh]
  survarium::booby_trap_state state; // [esp+1ECh] [ebp-5Ch]
  vostok::math::float4x4 transform; // [esp+1F0h] [ebp-58h] BYREF
  vostok::math::float3 angles; // [esp+230h] [ebp-18h] BYREF
  vostok::math::float3 position; // [esp+23Ch] [ebp-Ch] BYREF

  state = vostok::network_core::packet_reader::r<unsigned char>(
            (vostok::network_core::packet_reader *)this,
            (int)reader);
  vostok::network_core::packet_reader::r<vostok::math::float3>(v2, &position, (int)reader);
  vostok::network_core::packet_reader::r<vostok::math::float3>(v3, &angles, (int)reader);
  v12 = 0;
  survarium::weapon_user_dead_state::finalize(v4);
  v11 = 0;
  survarium::weapon_user_dead_state::finalize(v5);
  v7 = vostok::math::create_translation(&result, &position);
  v6 = vostok::math::create_rotation(&v9, &angles);
  vostok::math::operator*(&transform, v6, v7);
  this->m_owner->insert_trap(this->m_owner, this, &transform);
  if ( state != booby_trap_state_armed )
    this->switch_to_state(this, state);
}
