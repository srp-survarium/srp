int vostok::animation::_dynamic_initializer_for__zero___11()
{
  struct vostok::math::float3 *v0; // eax
  vostok::math::float3_pod *v1; // ecx
  struct vostok::math::float3 *v2; // eax
  vostok::math::float3_pod *v3; // ecx
  struct vostok::math::float3 *v4; // eax
  vostok::math::float3_pod *v5; // ecx
  struct vostok::math::float3 *v6; // eax
  int result; // eax
  float v8; // [esp+8h] [ebp-24h] BYREF
  char v9; // [esp+14h] [ebp-18h] BYREF
  char v10; // [esp+20h] [ebp-Ch] BYREF

  v0 = (struct vostok::math::float3 *)survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v10);
  zero_11.translation = vostok::math::float3_pod::set(v1, v0, 0.0, 0.0, 0.0, v8)->vostok::math::float3_pod;
  v2 = (struct vostok::math::float3 *)survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v9);
  *(struct vostok::math::float3 *)&zero_11.channels[3] = *vostok::math::float3_pod::set(v3, v2, 0.0, 0.0, 0.0, v8);
  v4 = (struct vostok::math::float3 *)survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v8);
  v6 = vostok::math::float3_pod::set(v5, v4, *(float *)&clear_value, 1.0, 1.0, v8);
  *(_QWORD *)&zero_11.channels[6] = *(_QWORD *)&v6->x;
  result = LODWORD(v6->z);
  LODWORD(zero_11.scale.z) = result;
  return result;
}
