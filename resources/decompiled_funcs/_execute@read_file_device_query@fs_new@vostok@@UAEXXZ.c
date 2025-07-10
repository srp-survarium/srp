void __thiscall vostok::fs_new::read_file_device_query::execute(vostok::fs_new::read_file_device_query *this)
{
  int v1; // edx
  bool v2; // [esp+0h] [ebp-14h]

  v2 = vostok::fs_new::device_file_system_proxy_base::read(
         &this->m_device,
         this->m_args.file,
         this->m_args.data,
         this->m_args.size) == LODWORD(this->m_args.size)
    && v1 == HIDWORD(this->m_args.size);
  this->m_result = v2;
}
