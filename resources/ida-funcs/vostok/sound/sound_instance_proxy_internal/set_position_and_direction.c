void __thiscall vostok::sound::sound_instance_proxy_internal::set_position_and_direction(
        vostok::sound::sound_instance_proxy_internal *this,
        const vostok::math::float3 *position,
        const vostok::math::float3 *direction)
{
  vostok::sound::atomic_half3 *v4; // ecx
  vostok::math::half *v5; // ecx
  vostok::sound::atomic_half3 *v6; // ecx
  vostok::math::half3 v7; // [esp+12h] [ebp-6h] BYREF

  vostok::math::half3::half3(&v7, position, (vostok::math::half *)this);
  vostok::sound::atomic_half3::set(v4, (vostok::math::half3 *)&this->m_position, (int)&v7);
  vostok::math::half3::half3(&v7, direction, v5);
  vostok::sound::atomic_half3::set(v6, (vostok::math::half3 *)&this->m_direction, (int)&v7);
}
