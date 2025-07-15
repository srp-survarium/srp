void __thiscall vostok::network::send_order::execute(vostok::network::send_order *this)
{
  boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
    (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)this,
    &this->m_sender.vtable,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)this->m_packet);
}
