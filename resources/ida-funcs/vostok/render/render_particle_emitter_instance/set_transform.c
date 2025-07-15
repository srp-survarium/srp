void __thiscall vostok::render::render_particle_emitter_instance::set_transform(
        vostok::render::render_particle_emitter_instance *this,
        const vostok::math::float4x4 *transform)
{
  qmemcpy(&this->m_transform, transform, sizeof(this->m_transform));
}
