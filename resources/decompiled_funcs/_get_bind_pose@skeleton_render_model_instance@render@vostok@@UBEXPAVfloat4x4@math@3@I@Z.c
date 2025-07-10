void __thiscall vostok::render::skeleton_render_model_instance::get_bind_pose(
        vostok::render::skeleton_render_model_instance *this,
        vostok::math::float4x4 *matrices,
        unsigned int count)
{
  vostok::render::skeleton_render_model::get_bind_pose(count, this->m_original.m_object, matrices);
}
