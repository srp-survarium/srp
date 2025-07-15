int __thiscall vostok::logging::fs_new_file_impl::seek(
        vostok::logging::fs_new_file_impl *this,
        unsigned __int64 offset,
        vostok::logging::base_fs_file::seek_enum seek)
{
  vostok::fs_new::seek_file_enum v3; // edx

  v3 = seek_file_begin;
  if ( seek )
  {
    if ( seek == seek_current )
      v3 = seek_file_current;
    else
      v3 = seek_file_end;
  }
  return vostok::fs_new::device_file_system_proxy_base::seek(
           (vostok::fs_new::device_file_system_proxy_base *)this,
           &this->m_device->m_device.m_device_file_system,
           this->m_file,
           offset,
           v3);
}
