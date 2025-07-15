void __thiscall survarium::legs_ik_drawer::draw_line_capsule(
        survarium::legs_ik_drawer *this,
        const vostok::math::float4x4 *matrix,
        const vostok::math::float3 *size,
        const vostok::math::color *color,
        bool use_depth)
{
  vostok::render::debug::renderer::draw_line_capsule(size, this->m_renderer, &this->m_scene, matrix, color, use_depth);
}
