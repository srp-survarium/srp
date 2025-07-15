void __userpurge vostok::fs_new::asynchronous_device_query::asynchronous_device_query(
        vostok::fs_new::asynchronous_device_query *this@<eax>,
        vostok::memory::base_allocator *allocator@<edx>,
        vostok::threading::event *event_to_fire_after_execute)
{
  this->m_next_forward = 0;
  this->m_next_backward = 0;
  this->m_backward_queue = 0;
  this->m_in_backward_queue = 0;
  this->m_allocator = allocator;
  this->__vftable = (vostok::fs_new::asynchronous_device_query_vtbl *)&vostok::fs_new::asynchronous_device_query::`vftable';
  this->m_device_query_result = 1;
  this->m_event_to_fire_after_execute = event_to_fire_after_execute;
}
