void __thiscall vostok::fs_new::open_file_device_query::execute(vostok::fs_new::open_file_device_query *this)
{
  vostok::fs_new::device_file_system_no_watcher_proxy::open(
    &this->m_device,
    &this->m_result_file,
    &this->m_physical_path,
    &this->m_open_file_params);
}
