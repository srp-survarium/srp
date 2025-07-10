void __thiscall survarium::legs_ik_drawer::draw_cross(
        survarium::legs_ik_drawer *this,
        const vostok::math::float3 *p,
        float half_size,
        const vostok::math::color *c,
        bool use_depth)
{
  vostok::render::debug::renderer::draw_cross(
    &p->x,
    &c->m_value,
    half_size,
    this->m_renderer,
    &this->m_scene,
    use_depth);
}
