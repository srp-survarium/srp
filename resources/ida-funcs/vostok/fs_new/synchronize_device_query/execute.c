void __thiscall vostok::fs_new::synchronize_device_query::execute(vostok::fs_new::synchronize_device_query *this)
{
  vostok::threading::event *v2; // ecx

  this->m_device->m_synchronous_thread_id = this->m_synchronous_thread_id;
  SetEvent(*(HANDLE *)this->m_synchronization_started_event.m_event.m_event);
  vostok::threading::event::wait(v2, (HANDLE *)&this->m_synchronization_ended_event, 0xFFFFFFFF);
}
