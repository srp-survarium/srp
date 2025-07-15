BOOL __userpurge vostok::replay_match_reader::read_bytes@<eax>(
        vostok::replay_match_reader *this@<ecx>,
        int a2@<eax>,
        void *const buffer,
        const unsigned int buffer_size)
{
  int v4; // edx

  return vostok::fs_new::device_file_system_proxy_base::read(
           &this->m_device,
           (_DWORD *)a2,
           *(void ***)(a2 + 4),
           buffer,
           buffer_size) == buffer_size
      && !v4;
}
