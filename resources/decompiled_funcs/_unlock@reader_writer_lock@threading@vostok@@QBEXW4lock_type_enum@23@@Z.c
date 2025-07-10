void __userpurge vostok::threading::reader_writer_lock::unlock(
        vostok::threading::reader_writer_lock *this@<ecx>,
        vostok::threading::reader_writer_lock::counters_type *a2@<eax>,
        vostok::threading::lock_type_enum lock_type)
{
  if ( lock_type == lock_type_read )
    vostok::threading::reader_writer_lock::unlock_read(this, a2);
  else
    vostok::threading::reader_writer_lock::unlock_write(this, (volatile signed __int64 *)a2);
}
