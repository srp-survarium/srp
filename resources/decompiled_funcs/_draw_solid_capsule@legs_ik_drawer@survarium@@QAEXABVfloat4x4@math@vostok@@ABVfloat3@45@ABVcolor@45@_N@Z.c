void __thiscall survarium::legs_ik_drawer::draw_solid_capsule(
        survarium::legs_ik_drawer *this,
        const vostok::math::float4x4 *matrix,
        const vostok::math::float3 *size,
        const vostok::math::color *color,
        bool use_depth)
{
  vostok::render::debug::renderer::draw_solid_capsule(
    (vostok::render::debug::renderer *)&this->m_scene,
    this->m_renderer,
    &this->m_scene,
    matrix,
    size,
    color,
    use_depth);
}
