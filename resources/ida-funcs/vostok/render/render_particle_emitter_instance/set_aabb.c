void __thiscall vostok::render::render_particle_emitter_instance::set_aabb(
        vostok::render::render_particle_emitter_instance *this,
        const vostok::math::aabb *bbox)
{
  qmemcpy(&this->m_bbox, bbox, sizeof(this->m_bbox));
}
