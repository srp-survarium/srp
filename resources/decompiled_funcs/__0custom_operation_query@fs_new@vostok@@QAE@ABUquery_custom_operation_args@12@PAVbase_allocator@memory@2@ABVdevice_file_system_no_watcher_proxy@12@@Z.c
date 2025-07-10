void __thiscall vostok::fs_new::custom_operation_query::custom_operation_query(
        vostok::fs_new::custom_operation_query *this,
        const vostok::fs_new::query_custom_operation_args *args,
        vostok::memory::base_allocator *allocator,
        const vostok::fs_new::device_file_system_no_watcher_proxy *device)
{
  vostok::threading::event *event_to_fire_after_execute; // [esp+8h] [ebp-8h]

  event_to_fire_after_execute = args->event_to_fire_after_execute;
  this->m_next_forward = 0;
  this->m_next_backward = 0;
  this->m_backward_queue = 0;
  this->m_allocator = allocator;
  this->m_in_backward_queue = 0;
  this->__vftable = (vostok::fs_new::custom_operation_query_vtbl *)&vostok::fs_new::asynchronous_device_query::`vftable';
  this->m_device_query_result = 1;
  this->m_event_to_fire_after_execute = event_to_fire_after_execute;
  this->__vftable = (vostok::fs_new::custom_operation_query_vtbl *)&vostok::fs_new::custom_operation_query::`vftable';
  vostok::fs_new::query_custom_operation_args::query_custom_operation_args(&this->m_args, args);
  this->m_device = (vostok::fs_new::device_file_system_no_watcher_proxy)device->m_device_file_system;
  this->m_result = 0;
}
