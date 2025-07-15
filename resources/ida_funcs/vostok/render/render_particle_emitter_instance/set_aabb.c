void __thiscall vostok::render::render_particle_emitter_instance::set_aabb(
        vostok::render::render_particle_emitter_instance *this,
        const vostok::math::aabb *bbox)
{
  this->m_bbox = *bbox;
}
