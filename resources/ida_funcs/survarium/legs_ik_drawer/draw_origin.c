void __thiscall survarium::legs_ik_drawer::draw_origin(
        survarium::legs_ik_drawer *this,
        const vostok::math::float4x4 *matrix,
        float half_size,
        bool use_depth)
{
  vostok::render::debug::renderer::draw_origin(
    &matrix->i.x,
    (int)this->m_renderer,
    half_size,
    &this->m_scene,
    use_depth);
}
