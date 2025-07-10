void __userpurge vostok::threading::reader_writer_lock::lock(
        vostok::threading::reader_writer_lock *this@<ecx>,
        unsigned int *a2@<eax>,
        vostok::threading::lock_type_enum lock_type)
{
  if ( lock_type == lock_type_read )
    vostok::threading::reader_writer_lock::lock_read_impl(this, a2);
  else
    vostok::threading::reader_writer_lock::lock_write_impl(this, (volatile signed __int64 *)a2);
}
