void __usercall vostok::apc::wait(
        const vostok::apc::threads_enum thread_id@<eax>,
        vostok::command_line::key *a2@<ecx>,
        boost::function<void __cdecl(void)> *process_callback)
{
  vostok::apc::callback *v3; // edi
  boost::function0<bool> *v4; // ecx

  v3 = &g_threads.m_begin[thread_id];
  while ( v3->m_pending )
  {
    vostok::resources::dispatch_callbacks(a2);
    if ( (process_callback->vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
      boost::function0<void>::operator()(v4, process_callback);
    vostok::threading::yield(1u, (vostok::tasks *)v4);
  }
}
