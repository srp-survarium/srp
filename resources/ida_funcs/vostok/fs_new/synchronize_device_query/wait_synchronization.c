void __thiscall vostok::fs_new::synchronize_device_query::wait_synchronization(
        vostok::fs_new::synchronize_device_query *this)
{
  vostok::threading::event::wait(
    &this->m_synchronization_started_event,
    (unsigned int)&this->m_synchronization_started_event);
}
