void __fastcall vostok::memory::doug_lea_allocator::user_thread_id(
        vostok::memory::doug_lea_allocator *this,
        __int32 user_thread_id)
{
  if ( this->m_user_thread_id != user_thread_id )
  {
    _InterlockedExchange((volatile __int32 *)&this->m_user_thread_id, user_thread_id);
    if ( this->m_thread_id_const )
      this->m_user_thread_id_called = 1;
  }
}
