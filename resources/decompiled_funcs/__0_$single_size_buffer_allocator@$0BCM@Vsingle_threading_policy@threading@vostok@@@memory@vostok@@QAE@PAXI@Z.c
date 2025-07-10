void __thiscall vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>(
        vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *this,
        vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node *arena,
        unsigned int arena_size)
{
  _BYTE *v3; // eax
  survarium::game_world *v4; // ecx
  _BYTE *v5; // eax
  vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node *v7; // [esp+0h] [ebp-1Ch]
  vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node *i; // [esp+Ch] [ebp-10h]
  bool do_debug_break; // [esp+13h] [ebp-9h] BYREF
  vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node *end; // [esp+14h] [ebp-8h]
  vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node *begin; // [esp+18h] [ebp-4h]

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->m_allocated_count = 0;
  this->m_max_count = 0;
  this->m_max_count = arena_size / 0x12C;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x12C);
  if ( !*v3
    || LOBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.vostok::input::handler::__vftable)
    || (survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x12C), *v5) )
  {
    this->m_free_list_head.pointer = 0;
    begin = arena;
    end = &arena[this->m_max_count];
    for ( i = arena; i != end; ++i )
    {
      if ( &i[1] == end )
        v7 = 0;
      else
        v7 = i + 1;
      i->next = v7;
    }
    this->m_free_list_head.pointer = begin;
  }
  else
  {
    if ( `vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`8'::occurances_left == -1 )
      `vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`8'::occurances_left = vostok::ui::ui_dialog::input_priority(v4);
    if ( `vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`8'::occurances_left-- )
    {
      if ( !LOBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.vostok::input::handler::__vftable) )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "arena_size % element_size == 0",
          "C:\\survarium\\sources\\vostok/memory_single_size_buffer_allocator_inline.h",
          "vostok::memory::single_size_buffer_allocator<300,class vostok::threading::single_threading_policy>::single_siz"
          "e_buffer_allocator",
          0x16u,
          "address of arena isn't aligned or data size is improper");
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
  }
}
