unsigned int __thiscall vostok::memory::doug_lea_allocator::total_size(vostok::memory::doug_lea_allocator *this)
{
  vostok::memory::thread_id_const_bool m_thread_id_const; // eax
  mallinfo v4; // [esp+Ch] [ebp-58h] BYREF
  _DWORD v5[10]; // [esp+34h] [ebp-30h] BYREF
  vostok::memory::thread_id_const_bool v6; // [esp+5Ch] [ebp-8h]
  unsigned int m_user_thread_id; // [esp+60h] [ebp-4h]

  m_thread_id_const = this->m_thread_id_const;
  this->m_thread_id_const = thread_id_const_false;
  v6 = m_thread_id_const;
  m_user_thread_id = this->m_user_thread_id;
  vostok::memory::doug_lea_allocator::user_current_thread_id(this, (int)this);
  qmemcpy(v5, vostok_mspace_mallinfo((malloc_state *)this->m_arena, &v4), sizeof(v5));
  if ( this->m_user_thread_id != m_user_thread_id )
  {
    _InterlockedExchange((volatile __int32 *)&this->m_user_thread_id, m_user_thread_id);
    if ( this->m_thread_id_const )
      this->m_user_thread_id_called = 1;
  }
  this->m_thread_id_const = v6;
  return v5[5];
}
