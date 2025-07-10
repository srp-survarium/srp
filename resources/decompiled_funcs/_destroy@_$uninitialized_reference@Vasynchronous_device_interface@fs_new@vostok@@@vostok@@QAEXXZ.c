void __thiscall vostok::uninitialized_reference<vostok::fs_new::asynchronous_device_interface>::destroy(
        vostok::uninitialized_reference<vostok::fs_new::asynchronous_device_interface> *this,
        vostok::uninitialized_reference<vostok::fs_new::asynchronous_device_interface> *thisa)
{
  vostok::fs_new::asynchronous_device_interface *m_variable; // esi

  m_variable = thisa->m_variable;
  CloseHandle(*(HANDLE *)m_variable->m_wakeup_event.m_event.m_event);
  TlsFree(m_variable->m_high_priority_queries.m_backward_queue_tls_key);
  TlsFree(m_variable->m_high_priority_queries.m_backward_queue_allocator_tls_key);
  TlsFree(m_variable->m_queries.m_backward_queue_tls_key);
  TlsFree(m_variable->m_queries.m_backward_queue_allocator_tls_key);
  thisa->m_initialized = 0;
}
