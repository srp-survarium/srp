void __thiscall vostok::fs_new::close_file_device_query::execute(vostok::fs_new::close_file_device_query *this)
{
  vostok::fs_new::device_file_system_no_watcher_proxy::close(&this->m_device, this->m_file);
}
