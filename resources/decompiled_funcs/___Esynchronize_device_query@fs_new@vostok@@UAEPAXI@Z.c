vostok::fs_new::synchronize_device_query *__thiscall vostok::fs_new::synchronize_device_query::`vector deleting destructor'(
        vostok::fs_new::synchronize_device_query *this,
        char a2)
{
  vostok::threading::event *v2; // ecx

  this->__vftable = (vostok::fs_new::synchronize_device_query_vtbl *)&vostok::fs_new::synchronize_device_query::`vftable';
  vostok::threading::event::~event((vostok::threading::event *)this, (HANDLE *)&this->m_synchronization_ended_event);
  vostok::threading::event::~event(v2, (HANDLE *)&this->m_synchronization_started_event);
  this->__vftable = (vostok::fs_new::synchronize_device_query_vtbl *)&vostok::fs_new::asynchronous_device_query::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
