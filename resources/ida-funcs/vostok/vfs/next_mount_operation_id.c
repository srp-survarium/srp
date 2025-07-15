signed __int32 __cdecl vostok::vfs::next_mount_operation_id()
{
  return _InterlockedIncrement(&vostok::vfs::s_mount_operation_id);
}
