void __thiscall vostok::render::update_skeleton_command::execute(vostok::render::update_skeleton_command *this)
{
  vostok::render::skeleton_render_model_instance::update_render_matrices(
    (int)this,
    this->m_matrices,
    (vostok::render::skeleton_render_model_instance *)this->m_model_instance.m_object,
    this->m_shadow_matrices,
    (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)this->m_matrices_count);
}
