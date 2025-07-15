void __userpurge vostok::console_commands::console_command::on_changed(
        vostok::console_commands::console_command *this@<ecx>,
        int a2@<eax>,
        const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *args)
{
  int v3; // ecx

  v3 = -(*(_DWORD *)(a2 + 32) != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v3) != 0 )
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)v3,
      args);
}
