void __fastcall vostok::particle::particle_emitter_instance::set_transform(
        int a1,
        const vostok::math::float4x4 *transform,
        vostok::particle::particle_emitter_instance *this,
        const vostok::math::float4x4 *second_transform)
{
  const void *v4; // edx
  const void *v5; // edx
  vostok::particle::render_particle_emitter_instance *m_render_instance; // esi
  vostok::particle::render_particle_emitter_instance_vtbl *v7; // edi
  vostok::math::float4x4 *v8; // eax
  vostok::math::float4x4 v9; // [esp+10h] [ebp-40h] BYREF

  qmemcpy(&this->m_first_transform, transform, sizeof(this->m_first_transform));
  vostok::math::try_invert4x4(&this->m_first_transform, &v9);
  qmemcpy(&this->m_first_inverted_transform, v4, sizeof(this->m_first_inverted_transform));
  qmemcpy(&this->m_second_transform, second_transform, sizeof(this->m_second_transform));
  vostok::math::try_invert4x4(&this->m_second_transform, &v9);
  qmemcpy(&this->m_second_inverted_transform, v5, sizeof(this->m_second_inverted_transform));
  m_render_instance = this->m_render_instance;
  if ( m_render_instance )
  {
    v7 = m_render_instance->__vftable;
    v8 = vostok::particle::particle_emitter_instance::get_transform(0, this, &v9);
    v7->set_transform(m_render_instance, v8);
  }
}
