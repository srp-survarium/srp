void __thiscall vostok::sound::sound_scene::set_listener_properties(
        vostok::sound::sound_scene *this,
        const vostok::math::float3 *position,
        const vostok::math::float3 *orient_front,
        const vostok::math::float3 *orient_top)
{
  signed __int64 v5; // [esp+24h] [ebp-98h]
  vostok::sound::atomic_half3 *p_m_list_orient_top; // [esp+2Ch] [ebp-90h]
  volatile signed __int64 v7; // [esp+30h] [ebp-8Ch]
  vostok::sound::atomic_half3 v8; // [esp+38h] [ebp-84h] BYREF
  signed __int64 v9; // [esp+48h] [ebp-74h]
  vostok::sound::atomic_half3 *p_m_list_orient_front; // [esp+50h] [ebp-6Ch]
  signed __int64 v11; // [esp+54h] [ebp-68h]
  vostok::sound::atomic_half3 v12; // [esp+68h] [ebp-54h] BYREF
  signed __int64 v13; // [esp+78h] [ebp-44h]
  vostok::sound::atomic_half3 *p_m_list_position; // [esp+80h] [ebp-3Ch]
  signed __int64 m_atomic; // [esp+84h] [ebp-38h]
  vostok::sound::atomic_half3 v16; // [esp+98h] [ebp-24h] BYREF
  vostok::math::half3 v17; // [esp+A8h] [ebp-14h] BYREF
  vostok::math::half3 v18; // [esp+AEh] [ebp-Eh] BYREF
  vostok::math::half3 v19; // [esp+B4h] [ebp-8h] BYREF
  char v20; // [esp+BBh] [ebp-1h]

  v20 = 0;
  this->m_is_listener_position_set = 1;
  vostok::math::half3::half3(&v19, position);
  vostok::sound::atomic_half3::atomic_half3(&v16);
  v16.m_data.m_val = v19.vostok::math::half3_pod;
  v13 = __PAIR64__(HIDWORD(v16.m_data.m_atomic), *(unsigned int *)&v19.x.data);
  p_m_list_position = &this->m_list_position;
  do
    m_atomic = p_m_list_position->m_data.m_atomic;
  while ( _InterlockedCompareExchange64((volatile signed __int64 *)p_m_list_position, v13, m_atomic) != m_atomic );
  vostok::math::half3::half3(&v18, orient_front);
  vostok::sound::atomic_half3::atomic_half3(&v12);
  v12.m_data.m_val = v18.vostok::math::half3_pod;
  v9 = __PAIR64__(HIDWORD(v12.m_data.m_atomic), *(unsigned int *)&v18.x.data);
  p_m_list_orient_front = &this->m_list_orient_front;
  do
    v11 = p_m_list_orient_front->m_data.m_atomic;
  while ( _InterlockedCompareExchange64((volatile signed __int64 *)p_m_list_orient_front, v9, v11) != v11 );
  vostok::math::half3::half3(&v17, orient_top);
  vostok::sound::atomic_half3::atomic_half3(&v8);
  v8.m_data.m_val = v17.vostok::math::half3_pod;
  v5 = __PAIR64__(HIDWORD(v8.m_data.m_atomic), *(unsigned int *)&v17.x.data);
  p_m_list_orient_top = &this->m_list_orient_top;
  do
    v7 = p_m_list_orient_top->m_data.m_atomic;
  while ( _InterlockedCompareExchange64(
            (volatile signed __int64 *)p_m_list_orient_top,
            v5,
            p_m_list_orient_top->m_data.m_atomic) != v7 );
}
