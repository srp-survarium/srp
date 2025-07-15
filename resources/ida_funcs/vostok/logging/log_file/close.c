void __thiscall vostok::logging::log_file::close(vostok::logging::log_file *this)
{
  __int32 v2; // [esp+4h] [ebp-Ch] BYREF
  __int32 v3; // [esp+8h] [ebp-8h]
  void **file; // [esp+Ch] [ebp-4h]

  if ( this->m_file )
  {
    file = this->m_file;
    v3 = vostok::threading::interlocked_exchange_pointer((volatile int *)&this->m_file, 0);
    _InterlockedExchange(&v2, v3);
    vostok::fs_new::device_file_system_proxy_base::flush(&this->m_device.m_device, file);
    vostok::fs_new::device_file_system_no_watcher_proxy::close(&this->m_device.m_device, file);
  }
}
