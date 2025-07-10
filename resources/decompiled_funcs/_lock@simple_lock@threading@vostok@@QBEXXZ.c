void __thiscall vostok::threading::simple_lock::lock(
        vostok::threading::simple_lock *this,
        vostok::threading::simple_lock *thisa)
{
  if ( thisa->m_thread_id == GetCurrentThreadId() )
  {
    ++thisa->m_lock;
  }
  else
  {
    while ( _InterlockedCompareExchange(&thisa->m_thread_id, GetCurrentThreadId(), 0) )
      ;
    thisa->m_lock = 1;
  }
}
