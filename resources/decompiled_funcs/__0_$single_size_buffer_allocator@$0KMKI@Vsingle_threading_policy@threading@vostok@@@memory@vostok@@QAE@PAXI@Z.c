void __thiscall vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>(
        vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy> *this,
        vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::node *arena,
        unsigned int arena_size)
{
  vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::node *v4; // [esp+0h] [ebp-1Ch]
  vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::node *i; // [esp+Ch] [ebp-10h]
  bool do_debug_break; // [esp+13h] [ebp-9h] BYREF
  vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::node *end; // [esp+14h] [ebp-8h]
  vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::node *begin; // [esp+18h] [ebp-4h]

  this->m_allocated_count = 0;
  this->m_max_count = 0;
  this->m_max_count = arena_size / 0xACA8;
  if ( `vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always
    || !(arena_size % 0xACA8) )
  {
    this->m_free_list_head.pointer = 0;
    begin = arena;
    end = &arena[this->m_max_count];
    for ( i = arena; i != end; ++i )
    {
      if ( &i[1] == end )
        v4 = 0;
      else
        v4 = i + 1;
      i->next = v4;
    }
    this->m_free_list_head.pointer = begin;
  }
  else
  {
    if ( `vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>'::`8'::occurances_left == -1 )
      `vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>'::`8'::occurances_left = 10;
    if ( `vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>'::`8'::occurances_left-- )
    {
      if ( !`vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "arena_size % element_size == 0",
          "C:\\survarium\\sources\\vostok/memory_single_size_buffer_allocator_inline.h",
          "vostok::memory::single_size_buffer_allocator<44200,class vostok::threading::single_threading_policy>::single_s"
          "ize_buffer_allocator",
          0x16u,
          "address of arena isn't aligned or data size is improper");
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
  }
}
