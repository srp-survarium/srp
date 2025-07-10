unsigned int __thiscall vostok::memory::doug_lea_allocator::allocated_size(vostok::memory::doug_lea_allocator *this)
{
  vostok::memory::thread_id_const_bool m_thread_id_const; // ebx
  unsigned int m_user_thread_id; // ebp
  unsigned int *p_m_user_thread_id; // edi
  DWORD CurrentThreadId; // eax
  const char *Value; // eax
  unsigned int uordblks; // eax
  mallinfo v9; // [esp+38h] [ebp-28h] BYREF

  m_thread_id_const = this->m_thread_id_const;
  m_user_thread_id = this->m_user_thread_id;
  p_m_user_thread_id = &this->m_user_thread_id;
  this->m_thread_id_const = thread_id_const_false;
  CurrentThreadId = GetCurrentThreadId();
  if ( *p_m_user_thread_id != CurrentThreadId )
  {
    _InterlockedExchange((volatile __int32 *)p_m_user_thread_id, CurrentThreadId);
    if ( this->m_thread_id_const )
      this->m_user_thread_id_called = 1;
  }
  Value = (const char *)TlsGetValue(s_thread_logging_name_tls_key);
  if ( !Value )
    Value = "undefined";
  this->m_user_thread_logging_name = Value;
  uordblks = internal_mallinfo(&v9, (malloc_state *)this->m_arena)->uordblks;
  *p_m_user_thread_id = m_user_thread_id;
  this->m_thread_id_const = m_thread_id_const;
  return uordblks - 480;
}
