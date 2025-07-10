void __thiscall vostok::render::update_skeleton_command::execute(vostok::render::update_skeleton_command *this)
{
  vostok::render::skeleton_render_model_instance::update_render_matrices(
    this->m_matrices_count,
    (vostok::render::skeleton_render_model_instance *)this->m_model_instance.m_object,
    this->m_matrices);
}
