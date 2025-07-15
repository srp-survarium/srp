void __thiscall vostok::fs_new::synchronize_device_query::execute(vostok::fs_new::synchronize_device_query *this)
{
  vostok::threading::event *v1; // ecx

  vostok::fs_new::asynchronous_device_interface::set_synchronous_thread_id(
    this->m_device,
    this->m_synchronous_thread_id);
  vostok::threading::event::set(v1, (HANDLE *)&this->m_synchronization_started_event, 1);
  vostok::threading::event::wait(
    &this->m_synchronization_ended_event,
    (unsigned int)&this->m_synchronization_ended_event);
}
