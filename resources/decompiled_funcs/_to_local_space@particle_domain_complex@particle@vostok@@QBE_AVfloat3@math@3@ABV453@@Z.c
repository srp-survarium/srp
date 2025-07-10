vostok::math::float3 *__thiscall vostok::particle::particle_domain_complex::to_local_space(
        vostok::particle::particle_domain_complex *this,
        vostok::math::float3 *result,
        const vostok::math::float3 *point)
{
  const vostok::math::float4x4 *transform; // eax
  vostok::math::float4x4 v6; // [esp+10h] [ebp-80h] BYREF
  vostok::math::float4x4 inv_transform; // [esp+50h] [ebp-40h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&inv_transform);
  transform = vostok::particle::particle_domain_complex::get_transform(this, &v6);
  vostok::math::float4x4::try_invert(&inv_transform, transform);
  vostok::math::float4x4::transform_position(point, result, &inv_transform);
  return result;
}
