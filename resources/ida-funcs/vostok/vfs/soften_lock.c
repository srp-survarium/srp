vostok::vfs::lock_type_enum __usercall vostok::vfs::soften_lock@<eax>(vostok::vfs::lock_type_enum lock@<eax>)
{
  if ( lock == lock_type_read )
    return 3;
  if ( lock == lock_type_write )
    return 4;
  return lock;
}
