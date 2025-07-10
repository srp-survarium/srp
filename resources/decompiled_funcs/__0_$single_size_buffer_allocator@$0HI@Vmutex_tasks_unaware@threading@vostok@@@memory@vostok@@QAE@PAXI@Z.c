void __userpurge vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>(
        vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware> *this@<esi>,
        unsigned int arena_size@<ecx>,
        vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::node *arena)
{
  vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::node *v3; // ebp
  unsigned int v4; // eax
  unsigned int m_max_count; // ecx
  vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::node *v6; // edi
  vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::node *i; // ecx

  v3 = arena;
  this->m_allocated_count = 0;
  this->m_max_count = arena_size / 0x78;
  if ( `vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>'::`5'::debug_macro_helper_ignore_always
    || !(arena_size % 0x78) )
  {
    m_max_count = this->m_max_count;
    this->m_free_list_head.pointer = 0;
    v6 = &v3[m_max_count];
    this->m_free_list_head.whole = 0;
    this->m_free_list_head.counter = 0;
    for ( i = v3; i != v6; ++i )
      i->next = v6 != &i[1] ? &i[1] : 0;
    this->m_free_list_head.pointer = v3;
  }
  else
  {
    v4 = `vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>'::`8'::occurances_left;
    if ( `vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>'::`8'::occurances_left == -1 )
      v4 = 10;
    `vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>'::`8'::occurances_left = v4 - 1;
    if ( v4 )
    {
      LOBYTE(arena) = 0;
      vostok::debug::on_error(
        (bool *)&arena,
        process_error_false,
        &`vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>'::`5'::debug_macro_helper_ignore_always,
        assert_untyped,
        "assertion_failed",
        "arena_size % element_size == 0",
        "C:\\survarium\\sources\\vostok/memory_single_size_buffer_allocator_inline.h",
        &stru_95DC74.m_buffer[416],
        0x16u,
        "address of arena isn't aligned or data size is improper");
      if ( vostok::debug::is_debugger_present() || (_BYTE)arena )
        __debugbreak();
    }
  }
}
