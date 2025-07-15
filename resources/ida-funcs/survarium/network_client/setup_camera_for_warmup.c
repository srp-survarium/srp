void __usercall survarium::network_client::setup_camera_for_warmup(survarium::network_client *this@<ecx>, int a2@<esi>)
{
  float *v2; // eax
  unsigned int v3; // xmm3_4
  unsigned int v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm2_4
  int v7; // ecx
  void (__thiscall *v8)(int, vostok::physics::closest_ray_result *, vostok::math::float3 *, vostok::math::float3 *, _DWORD, int, int); // edx
  float length; // [esp+14h] [ebp-60h]
  vostok::math::float3 direction; // [esp+18h] [ebp-5Ch] BYREF
  vostok::math::float3 position; // [esp+24h] [ebp-50h] BYREF
  vostok::math::float3 v12; // [esp+30h] [ebp-44h] BYREF
  vostok::math::float3 target; // [esp+3Ch] [ebp-38h] BYREF
  vostok::physics::closest_ray_result ray_result; // [esp+48h] [ebp-2Ch] BYREF

  v2 = *(float **)(a2 + 15544);
  *(float *)&v3 = (float)((float)((float)(v2[8676] * s_warmup_camera_position.z)
                                + (float)(v2[8672] * s_warmup_camera_position.y))
                        + (float)(s_warmup_camera_position.x * v2[8668]))
                + v2[8680];
  *(float *)&v4 = (float)((float)((float)(v2[8677] * s_warmup_camera_position.z)
                                + (float)(v2[8673] * s_warmup_camera_position.y))
                        + (float)(v2[8669] * s_warmup_camera_position.x))
                + v2[8681];
  v5 = (float)((float)((float)(v2[8678] * s_warmup_camera_position.z) + (float)(v2[8674] * s_warmup_camera_position.y))
             + (float)(v2[8670] * s_warmup_camera_position.x))
     + v2[8682];
  target.x = (float)((float)((float)(v2[8676] * s_warmup_camera_target.z) + (float)(v2[8672] * s_warmup_camera_target.y))
                   + (float)(s_warmup_camera_target.x * v2[8668]))
           + v2[8680];
  target.y = (float)((float)((float)(v2[8677] * s_warmup_camera_target.z) + (float)(v2[8673] * s_warmup_camera_target.y))
                   + (float)(v2[8669] * s_warmup_camera_target.x))
           + v2[8681];
  v6 = (float)((float)((float)(v2[8678] * s_warmup_camera_target.z) + (float)(v2[8674] * s_warmup_camera_target.y))
             + (float)(v2[8670] * s_warmup_camera_target.x))
     + v2[8682];
  *(_QWORD *)&position.x = __PAIR64__(v4, v3);
  target.z = v6;
  direction.z = v6 - v5;
  direction.y = target.y - *(float *)&v4;
  position.z = v5;
  direction.x = target.x - *(float *)&v3;
  length = sqrtf(
             (float)((float)(direction.z * direction.z)
                   + (float)((float)(target.y - *(float *)&v4) * (float)(target.y - *(float *)&v4)))
           + (float)(direction.x * direction.x));
  v7 = *(_DWORD *)(*(_DWORD *)(a2 + 24) + 328);
  direction.x = (float)(*(float *)&clear_value / length) * (float)(target.x - *(float *)&v3);
  v12.x = -direction.x;
  direction.z = (float)(v6 - v5) * (float)(*(float *)&clear_value / length);
  v12.y = -(float)((float)(target.y - *(float *)&v4) * (float)(*(float *)&clear_value / length));
  v12.z = -direction.z;
  v8 = *(void (__thiscall **)(int, vostok::physics::closest_ray_result *, vostok::math::float3 *, vostok::math::float3 *, _DWORD, int, int))(*(_DWORD *)v7 + 60);
  direction.y = (float)(target.y - *(float *)&v4) * (float)(*(float *)&clear_value / length);
  v8(v7, &ray_result, &target, &v12, LODWORD(length), 16, 8);
  if ( ray_result.object )
  {
    v12.x = (float)(direction.x * 0.0099999998) + ray_result.hit_point_world.x;
    v12.y = ray_result.hit_point_world.y + (float)(direction.y * 0.0099999998);
    v12.z = ray_result.hit_point_world.z + (float)(direction.z * 0.0099999998);
    position = v12;
  }
  survarium::game_camera::set_position_direction(
    *(survarium::game_camera **)(*(_DWORD *)(a2 + 24) + 716),
    &position,
    &direction);
}
