void __thiscall vostok::sound::sound_receiver::set_position(
        vostok::sound::sound_receiver *this,
        const vostok::math::float3 *position)
{
  vostok::sound::atomic_half3 *m_position; // [esp+14h] [ebp-54h]
  signed __int64 v4; // [esp+18h] [ebp-50h]
  volatile signed __int64 m_atomic; // [esp+24h] [ebp-44h]
  vostok::sound::atomic_half3 v6; // [esp+44h] [ebp-24h] BYREF
  vostok::math::half3 v7; // [esp+60h] [ebp-8h] BYREF
  char v8; // [esp+67h] [ebp-1h]

  v8 = 0;
  vostok::math::half3::half3(&v7, position);
  m_position = this->m_position;
  vostok::sound::atomic_half3::atomic_half3(&v6);
  v6.m_data.m_val = v7.vostok::math::half3_pod;
  v4 = __PAIR64__(HIDWORD(v6.m_data.m_atomic), *(unsigned int *)&v7.x.data);
  do
    m_atomic = m_position->m_data.m_atomic;
  while ( _InterlockedCompareExchange64((volatile signed __int64 *)m_position, v4, m_position->m_data.m_atomic) != m_atomic );
}
