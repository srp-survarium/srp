void __thiscall vostok::particle::particle_emitter_instance::set_transform(
        vostok::particle::particle_emitter_instance *this,
        const vostok::math::float4x4 *transform)
{
  vostok::math::float4x4 *v2; // eax
  vostok::math::float4x4 *p_m_transform; // [esp+8h] [ebp-8Ch]
  char v5; // [esp+50h] [ebp-44h] BYREF
  vostok::math::float4x4 *v6; // [esp+90h] [ebp-4h]

  qmemcpy((void *)&this->m_transform, transform, sizeof(this->m_transform));
  if ( this->m_render_instance )
  {
    if ( this->m_world_space )
    {
      v2 = (vostok::math::float4x4 *)survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v5);
      p_m_transform = vostok::math::float4x4::identity(v2);
    }
    else
    {
      p_m_transform = &this->m_transform;
    }
    v6 = p_m_transform;
    this->m_render_instance->set_transform(this->m_render_instance, p_m_transform);
  }
}
