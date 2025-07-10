void __thiscall vostok::fs_new::synchronize_device_query::synchronize_device_query(
        vostok::fs_new::synchronize_device_query *this,
        vostok::fs_new::asynchronous_device_interface *device,
        unsigned int synchronous_thread_id,
        vostok::memory::base_allocator *allocator)
{
  this->m_next_forward = 0;
  this->m_next_backward = 0;
  this->m_backward_queue = 0;
  this->m_allocator = allocator;
  this->m_in_backward_queue = 0;
  this->__vftable = (vostok::fs_new::synchronize_device_query_vtbl *)&vostok::fs_new::asynchronous_device_query::`vftable';
  this->m_device_query_result = 1;
  this->m_event_to_fire_after_execute = 0;
  this->__vftable = (vostok::fs_new::synchronize_device_query_vtbl *)&vostok::fs_new::synchronize_device_query::`vftable';
  this->m_device = device;
  vostok::threading::event::event(&this->m_synchronization_started_event, 0);
  vostok::threading::event::event(&this->m_synchronization_ended_event, 0);
  this->m_synchronous_thread_id = synchronous_thread_id;
}
