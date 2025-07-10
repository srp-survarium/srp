void __thiscall vostok::threading::simple_lock::mutex_raii::clear(vostok::threading::simple_lock::mutex_raii *this)
{
  const vostok::threading::simple_lock *lock; // eax

  if ( this->locked )
  {
    lock = this->lock;
    if ( this->lock->m_lock-- == 1 )
      _InterlockedExchange(&lock->m_thread_id, 0);
    this->locked = 0;
  }
}
