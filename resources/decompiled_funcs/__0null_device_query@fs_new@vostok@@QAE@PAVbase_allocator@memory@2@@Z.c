void __thiscall vostok::fs_new::null_device_query::null_device_query(
        vostok::fs_new::null_device_query *this,
        vostok::memory::base_allocator *allocator)
{
  this->m_next_forward = 0;
  this->m_next_backward = 0;
  this->m_backward_queue = 0;
  this->m_allocator = allocator;
  this->m_in_backward_queue = 0;
  this->__vftable = (vostok::fs_new::null_device_query_vtbl *)&vostok::fs_new::asynchronous_device_query::`vftable';
  this->m_device_query_result = 1;
  this->m_event_to_fire_after_execute = 0;
  this->__vftable = (vostok::fs_new::null_device_query_vtbl *)&vostok::fs_new::null_device_query::`vftable';
}
