void __userpurge vostok::sound::sound_scene::set_listener_properties(
        const vostok::math::float3 *position@<eax>,
        vostok::math::half *a2@<ecx>,
        vostok::sound::sound_scene *this,
        const vostok::math::float3 *orient_front,
        const vostok::math::float3 *orient_top)
{
  vostok::sound::atomic_half3 *v5; // ecx
  vostok::math::half *v6; // ecx
  vostok::sound::atomic_half3 *v7; // ecx
  vostok::math::half *v8; // ecx
  vostok::sound::atomic_half3 *v9; // ecx
  vostok::math::half3 v10; // [esp+12h] [ebp-6h] BYREF

  this->m_is_listener_position_set = 1;
  vostok::math::half3::half3(&v10, position, a2);
  vostok::sound::atomic_half3::set(v5, (vostok::math::half3 *)&this->m_listener_position, (int)&v10);
  vostok::math::half3::half3(&v10, orient_front, v6);
  vostok::sound::atomic_half3::set(v7, (vostok::math::half3 *)&this->m_listener_orient_front, (int)&v10);
  vostok::math::half3::half3(&v10, orient_top, v8);
  vostok::sound::atomic_half3::set(v9, (vostok::math::half3 *)&this->m_listener_orient_top, (int)&v10);
}
