void __thiscall vostok::fs_new::windows_hdd_file_system::~windows_hdd_file_system(
        vostok::fs_new::windows_hdd_file_system *this)
{
  void *m_archive_handle; // eax

  m_archive_handle = this->m_archive_handle;
  this->__vftable = (vostok::fs_new::windows_hdd_file_system_vtbl *)&vostok::fs_new::windows_hdd_file_system::`vftable';
  if ( m_archive_handle != (void *)-1 )
  {
    CloseHandle(m_archive_handle);
    this->m_archive_handle = (void *)-1;
  }
}
