void __thiscall vostok::sound::sound_instance_proxy_internal::set_position_and_direction(
        vostok::sound::sound_instance_proxy_internal *this,
        const vostok::math::float3 *position,
        const vostok::math::float3 *direction)
{
  signed __int64 v4; // [esp+1Ch] [ebp-78h]
  vostok::sound::atomic_half3 *p_m_direction; // [esp+24h] [ebp-70h]
  volatile signed __int64 v6; // [esp+28h] [ebp-6Ch]
  vostok::sound::atomic_half3 v7; // [esp+3Ch] [ebp-58h] BYREF
  signed __int64 v8; // [esp+58h] [ebp-3Ch]
  vostok::sound::atomic_half3 *p_m_position; // [esp+60h] [ebp-34h]
  signed __int64 m_atomic; // [esp+64h] [ebp-30h]
  vostok::sound::atomic_half3 v11; // [esp+78h] [ebp-1Ch] BYREF
  vostok::math::half3 v12; // [esp+86h] [ebp-Eh] BYREF
  vostok::math::half3 v13; // [esp+8Ch] [ebp-8h] BYREF
  char v14; // [esp+93h] [ebp-1h]

  v14 = 0;
  vostok::sound::sound_instance_proxy_internal::set_quality_for_resource(this, position);
  vostok::math::half3::half3(&v13, position);
  vostok::sound::atomic_half3::atomic_half3(&v11);
  v11.m_data.m_val = v13.vostok::math::half3_pod;
  v8 = __PAIR64__(HIDWORD(v11.m_data.m_atomic), *(unsigned int *)&v13.x.data);
  p_m_position = &this->m_position;
  do
    m_atomic = p_m_position->m_data.m_atomic;
  while ( _InterlockedCompareExchange64((volatile signed __int64 *)p_m_position, v8, m_atomic) != m_atomic );
  vostok::math::half3::half3(&v12, direction);
  vostok::sound::atomic_half3::atomic_half3(&v7);
  v7.m_data.m_val = v12.vostok::math::half3_pod;
  v4 = __PAIR64__(HIDWORD(v7.m_data.m_atomic), *(unsigned int *)&v12.x.data);
  p_m_direction = &this->m_direction;
  do
    v6 = p_m_direction->m_data.m_atomic;
  while ( _InterlockedCompareExchange64((volatile signed __int64 *)p_m_direction, v4, p_m_direction->m_data.m_atomic) != v6 );
}
