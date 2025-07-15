void __usercall vostok::tasks::thread_pool::on_task_thread_started(vostok::tasks::thread_pool *this@<esi>)
{
  void *v2; // [esp+0h] [ebp-8h]

  TlsSetValue(this->m_thread_tls_key, v2);
  if ( _InterlockedIncrement(&this->m_num_task_threads_started) == this->m_task_thread_tls.m_end
                                                                 - this->m_task_thread_tls.m_begin )
    SetEvent(*(HANDLE *)this->m_all_task_threads_started.m_event);
}
