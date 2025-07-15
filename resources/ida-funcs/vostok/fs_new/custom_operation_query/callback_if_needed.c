void __thiscall vostok::fs_new::custom_operation_query::callback_if_needed(
        vostok::fs_new::custom_operation_query *this)
{
  if ( (this->m_args.callback.vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)this->m_result,
      &this->m_args.callback.vtable,
      (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)this->m_result);
}
