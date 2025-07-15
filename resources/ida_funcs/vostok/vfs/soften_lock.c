vostok::vfs::lock_type_enum __cdecl vostok::vfs::soften_lock(vostok::vfs::lock_type_enum lock)
{
  if ( lock == lock_type_read )
    return 3;
  if ( lock == lock_type_write )
    return 4;
  return lock;
}
