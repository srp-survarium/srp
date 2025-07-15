void __thiscall vostok::console_commands::cc_delegate::execute(
        vostok::console_commands::cc_delegate *this,
        vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *args)
{
  vostok::console_commands::console_command *v3; // ecx

  boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
    (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)this,
    &this->m_functor.vtable,
    args);
  vostok::console_commands::console_command::on_changed(v3, (int)this, args);
}
