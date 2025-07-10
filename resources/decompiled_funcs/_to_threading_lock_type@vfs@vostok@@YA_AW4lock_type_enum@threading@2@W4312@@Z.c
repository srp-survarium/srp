int __cdecl vostok::vfs::to_threading_lock_type(vostok::vfs::lock_type_enum lock_type)
{
  if ( lock_type == lock_type_read )
    return 1;
  else
    return 2;
}
