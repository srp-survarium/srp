bool __usercall vostok::apc::is_same_thread@<al>(const vostok::apc::threads_enum thread_id@<eax>)
{
  vostok::apc::callback *v1; // esi

  v1 = &g_threads.m_begin[thread_id];
  return v1->m_thread_id == GetCurrentThreadId();
}
