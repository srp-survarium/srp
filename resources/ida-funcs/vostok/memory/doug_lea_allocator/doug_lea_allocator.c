void __userpurge vostok::memory::doug_lea_allocator::doug_lea_allocator(
        vostok::memory::doug_lea_allocator *this@<esi>,
        vostok::memory::thread_id_const_bool thread_id_const@<eax>,
        bool crash_after_out_of_memory,
        bool return_null_after_out_of_memory,
        bool use_guards)
{
  this->m_arena_start = 0;
  this->m_arena_end = 0;
  this->m_arena_id = 0;
  this->m_use_memory_monitor = 0;
  this->__vftable = (vostok::memory::doug_lea_allocator_vtbl *)&vostok::memory::doug_lea_allocator::`vftable';
  this->m_arena = 0;
  this->m_user_thread_logging_name = "invalid thread id";
  this->m_thread_id_const = thread_id_const;
  this->m_user_thread_id_called = 0;
  this->m_user_thread_id = GetCurrentThreadId();
  this->m_crash_after_out_of_memory = crash_after_out_of_memory;
  this->m_return_null_after_out_of_memory = return_null_after_out_of_memory;
  this->m_out_of_memory = 0;
  this->m_use_guards = use_guards;
}
