void __thiscall vostok::sound::sound_instance_proxy_internal::set_position(
        vostok::sound::sound_instance_proxy_internal *this,
        const vostok::math::float3 *position)
{
  vostok::sound::atomic_half3 *v3; // ecx
  vostok::math::half3 v4; // [esp+6h] [ebp-6h] BYREF

  if ( this->m_type == point )
  {
    vostok::math::half3::half3(&v4, position, (vostok::math::half *)this);
    vostok::sound::atomic_half3::set(v3, (vostok::math::half3 *)&this->m_position, (int)&v4);
  }
}
