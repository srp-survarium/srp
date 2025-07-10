unsigned int __thiscall vostok::memory::doug_lea_allocator::total_size(vostok::memory::doug_lea_allocator *this)
{
  vostok::memory::thread_id_const_bool m_thread_id_const; // ebx
  unsigned int m_user_thread_id; // ebp
  unsigned int *p_m_user_thread_id; // edi
  DWORD CurrentThreadId; // eax
  const char *Value; // eax
  bool v7; // zf
  unsigned int result; // eax
  __int64 v9; // [esp+20h] [ebp-40h]
  mallinfo v10; // [esp+38h] [ebp-28h] BYREF

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
  v9 = *(_QWORD *)&internal_mallinfo(&v10, (malloc_state *)this->m_arena)->hblkhd;
  if ( *p_m_user_thread_id == m_user_thread_id )
  {
    result = HIDWORD(v9);
    this->m_thread_id_const = m_thread_id_const;
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)p_m_user_thread_id, m_user_thread_id);
    v7 = this->m_thread_id_const == thread_id_const_false;
    result = HIDWORD(v9);
    this->m_thread_id_const = m_thread_id_const;
    if ( !v7 )
      this->m_user_thread_id_called = 1;
  }
  return result;
}
