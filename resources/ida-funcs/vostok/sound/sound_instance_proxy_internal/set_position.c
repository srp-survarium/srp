void __thiscall vostok::sound::sound_instance_proxy_internal::set_position(
        vostok::sound::sound_instance_proxy_internal *this,
        const vostok::math::float3 *position)
{
  signed __int64 v3; // [esp+14h] [ebp-50h]
  vostok::sound::atomic_half3 *p_m_position; // [esp+1Ch] [ebp-48h]
  volatile signed __int64 m_atomic; // [esp+20h] [ebp-44h]
  vostok::sound::atomic_half3 v6; // [esp+40h] [ebp-24h] BYREF
  vostok::math::half3 v7; // [esp+5Ch] [ebp-8h] BYREF
  char v8; // [esp+63h] [ebp-1h]

  v8 = 0;
  vostok::sound::sound_instance_proxy_internal::set_quality_for_resource(this, position);
  vostok::math::half3::half3(&v7, position);
  vostok::sound::atomic_half3::atomic_half3(&v6);
  v6.m_data.m_val = v7.vostok::math::half3_pod;
  v3 = __PAIR64__(HIDWORD(v6.m_data.m_atomic), *(unsigned int *)&v7.x.data);
  p_m_position = &this->m_position;
  do
    m_atomic = p_m_position->m_data.m_atomic;
  while ( _InterlockedCompareExchange64((volatile signed __int64 *)p_m_position, v3, p_m_position->m_data.m_atomic) != m_atomic );
}
