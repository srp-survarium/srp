void __thiscall vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::game::renderer::draw_scene_params>::defer_execution(
        vostok::render::functor_command *this)
{
  boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
    (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)this,
    &this->m_on_defer_execution.vtable,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)this);
}
