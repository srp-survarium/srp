void __userpurge vostok::fs_new::asynchronous_device_interface::tick(
        vostok::fs_new::asynchronous_device_interface *this@<ecx>,
        vostok::fs_new::asynchronous_device_interface *a2@<esi>,
        bool call_from_dedicated_thread)
{
  vostok::threading::event *v3; // ecx

  vostok::fs_new::asynchronous_device_interface::process_queries(
    a2,
    (vostok::fs_new::asynchronous_device_interface *)&a2->m_high_priority_queries);
  vostok::fs_new::asynchronous_device_interface::process_queries(a2, a2);
  if ( call_from_dedicated_thread )
    vostok::threading::event::wait(v3, (HANDLE *)&a2->m_wakeup_event, 0xAu);
}
