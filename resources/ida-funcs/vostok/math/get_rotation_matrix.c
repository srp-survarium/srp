vostok::math::float4x4 *__cdecl vostok::math::get_rotation_matrix(
        vostok::math::float4x4 *result,
        const vostok::math::float3 *original_dir,
        const vostok::math::float3 *target_dir)
{
  survarium::game_camera *v3; // ecx
  vostok::math::float4x4 *v5; // eax
  survarium::game_options v6; // [esp+6Ch] [ebp-B4h] BYREF
  const vostok::math::float3 *rot_axis; // [esp+F4h] [ebp-2Ch]
  vostok::math::float3 v8; // [esp+F8h] [ebp-28h] BYREF
  float angle; // [esp+104h] [ebp-1Ch] BYREF
  float cos_angle; // [esp+108h] [ebp-18h] BYREF
  vostok::math::float3_pod v11; // [esp+10Ch] [ebp-14h] BYREF
  float sin_angle; // [esp+118h] [ebp-8h] BYREF
  const vostok::math::float3 *cp; // [esp+11Ch] [ebp-4h]

  vostok::math::operator^(target_dir, original_dir, (vostok::math::float3 *)&v11);
  cp = (const vostok::math::float3 *)&v11;
  sin_angle = vostok::math::float3_pod::length(&v11, &v11.x);
  cos_angle = vostok::math::operator|(original_dir, target_dir);
  vostok::math::clamp<float>(&sin_angle, -1.0, 1.0);
  vostok::math::clamp<float>(&cos_angle, -1.0, 1.0);
  angle = vostok::math::atan2(sin_angle, cos_angle);
  if ( vostok::math::is_zero<float>(&angle, &epsilon_5_87) )
  {
    v5 = (vostok::math::float4x4 *)survarium::weapon_core::cast_weapon_core(&v6);
    qmemcpy((void *)result, vostok::math::float4x4::identity(v5), sizeof(vostok::math::float4x4));
  }
  else
  {
    vostok::math::normalize(cp, &v8.x);
    rot_axis = &v8;
    vostok::math::create_rotation(&v8, -angle);
    HIBYTE(v6.m_conflicted_action_to_bind) = 0;
    survarium::weapon_user_dead_state::finalize(v3);
    qmemcpy((void *)result, &v6.m_conflicted_action_ids, sizeof(vostok::math::float4x4));
  }
  return result;
}
