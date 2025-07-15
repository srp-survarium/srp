void __thiscall vostok::resources::query_resources_and_wait_callback_proxy_pred::callback(
        vostok::resources::query_resources_and_wait_callback_proxy_pred *this,
        vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *result)
{
  boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
    (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)this,
    &this->callback_.vtable,
    result);
  this->receieved_callback_ = 1;
}
