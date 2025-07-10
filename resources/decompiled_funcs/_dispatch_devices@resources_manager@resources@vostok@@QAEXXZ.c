void __thiscall vostok::resources::resources_manager::dispatch_devices(vostok::resources::resources_manager *this)
{
  vostok::fs_new::asynchronous_device_interface::dispatch_callbacks(*(vostok::fs_new::asynchronous_device_interface **)((char *)&loc_205F8 + (_DWORD)this));
  vostok::fs_new::asynchronous_device_interface::dispatch_callbacks(*(vostok::fs_new::asynchronous_device_interface **)((char *)&this->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_205FB + 1));
}
