void __userpurge survarium::player_state::deserialize(
        survarium::player_state *this@<ecx>,
        float a2@<xmm0>,
        vostok::network_core::packet_reader *packet)
{
  const vostok::math::float3 *v3; // esi
  vostok::math::float3 *v4; // eax
  _QWORD v6[8]; // [esp+B4h] [ebp-54h] BYREF
  float yaw; // [esp+F4h] [ebp-14h]
  vostok::math::float3 v8; // [esp+F8h] [ebp-10h] BYREF
  const vostok::math::float3 *position; // [esp+104h] [ebp-4h]

  vostok::network_core::packet_reader::r<vostok::math::float3>(
    (vostok::network_core::packet_reader *)this,
    &v8,
    (int)packet);
  position = &v8;
  vostok::network_core::packet_reader::r<float>(packet);
  yaw = a2;
  vostok::network_core::packet_reader::r<float>(packet);
  this->look_pitch = a2;
  qmemcpy(this, vostok::math::create_rotation_y(v6, (vostok::math::float4x4 *)LODWORD(yaw)), 0x40u);
  v3 = position;
  survarium::weapon_user_dead_state::finalize(0);
  *v4 = *v3;
}
