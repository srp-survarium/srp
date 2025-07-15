void __thiscall vostok::fs_new::synchronize_device_query::~synchronize_device_query(
        vostok::fs_new::synchronize_device_query *this)
{
  void *v2; // [esp-4h] [ebp-Ch]

  v2 = *(void **)this->m_synchronization_ended_event.m_event.m_event;
  this->__vftable = (vostok::fs_new::synchronize_device_query_vtbl *)&vostok::fs_new::synchronize_device_query::`vftable';
  CloseHandle(v2);
  CloseHandle(*(HANDLE *)this->m_synchronization_started_event.m_event.m_event);
  this->__vftable = (vostok::fs_new::synchronize_device_query_vtbl *)&vostok::fs_new::asynchronous_device_query::`vftable';
}
