void __thiscall vostok::fs_new::asynchronous_device_interface::tick(
        vostok::fs_new::asynchronous_device_interface *this,
        bool call_from_dedicated_thread)
{
  vostok::fs_new::asynchronous_device_interface::process_queries(this);
  if ( call_from_dedicated_thread )
    vostok::threading::event::wait(&this->m_wakeup_event, (unsigned int)&this->m_wakeup_event);
}
