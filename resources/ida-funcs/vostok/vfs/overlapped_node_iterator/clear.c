void __thiscall vostok::vfs::overlapped_node_iterator::clear(vostok::vfs::overlapped_node_iterator *this)
{
  vostok::threading::lock_type_enum v1; // eax
  vostok::threading::reader_writer_lock *v2; // ecx

  if ( this->hashset_lock )
  {
    v1 = vostok::vfs::to_threading_lock_type(this->lock_type);
    vostok::threading::reader_writer_lock::unlock(v2, &this->hashset_lock->m_readers_writers_counter, v1);
  }
  this->hashset_lock = 0;
  this->lock_type = lock_type_uninitialized;
  this->node = 0;
}
