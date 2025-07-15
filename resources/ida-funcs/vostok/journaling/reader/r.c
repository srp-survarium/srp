unsigned __int8 __thiscall vostok::journaling::reader::r<unsigned char>(vostok::journaling::reader *this)
{
  char v2; // [esp+7h] [ebp-1h] BYREF

  vostok::fs_new::device_file_system_proxy_base::read(
    (vostok::fs_new::device_file_system_proxy_base *)this,
    &this->m_device->m_device_file_system,
    this->m_file,
    &v2,
    1u);
  return v2;
}


unsigned int __thiscall vostok::journaling::reader::r<unsigned int>(vostok::journaling::reader *this)
{
  int v2; // [esp+4h] [ebp-4h] BYREF

  vostok::fs_new::device_file_system_proxy_base::read(
    (vostok::fs_new::device_file_system_proxy_base *)this,
    &this->m_device->m_device_file_system,
    this->m_file,
    &v2,
    4u);
  return v2;
}
