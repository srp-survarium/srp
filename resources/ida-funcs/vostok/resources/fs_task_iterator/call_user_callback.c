void __thiscall vostok::resources::fs_task_iterator::call_user_callback(vostok::resources::fs_task_iterator *this)
{
  boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
    (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)this,
    &this->m_callback.vtable,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)&this->m_iterator);
}
