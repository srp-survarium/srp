void __usercall vostok::apc::assign_thread_id(vostok::apc::threads_enum thread@<eax>, unsigned int thread_id@<edx>)
{
  g_threads.m_begin[thread].m_thread_id = thread_id;
}
