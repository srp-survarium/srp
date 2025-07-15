vostok::fs_new::windows_hdd_file_system *__thiscall vostok::fs_new::windows_hdd_file_system::`vector deleting destructor'(
        vostok::fs_new::windows_hdd_file_system *this,
        char a2)
{
  vostok::fs_new::windows_hdd_file_system::~windows_hdd_file_system(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
