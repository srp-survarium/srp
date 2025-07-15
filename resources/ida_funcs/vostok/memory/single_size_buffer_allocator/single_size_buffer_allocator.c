void __thiscall vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>(
        vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy> *this,
        vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::node *arena,
        unsigned int arena_size)
{
  vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::node *v4; // [esp+0h] [ebp-1Ch]
  vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::node *i; // [esp+Ch] [ebp-10h]
  bool do_debug_break; // [esp+13h] [ebp-9h] BYREF
  vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::node *end; // [esp+14h] [ebp-8h]
  vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::node *begin; // [esp+18h] [ebp-4h]

  this->m_allocated_count = 0;
  this->m_max_count = 0;
  this->m_max_count = arena_size >> 3;
  if ( `vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always
    || !(arena_size % 8) )
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
    if ( `vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>'::`8'::occurances_left == -1 )
      `vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>'::`8'::occurances_left = 10;
    if ( `vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>'::`8'::occurances_left-- )
    {
      if ( !`vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "arena_size % element_size == 0",
          "C:\\survarium\\sources\\vostok/memory_single_size_buffer_allocator_inline.h",
          "vostok::memory::single_size_buffer_allocator<8,class vostok::threading::single_threading_policy>::single_size_"
          "buffer_allocator",
          0x16u,
          "address of arena isn't aligned or data size is improper");
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
  }
}


void __thiscall vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>(
        vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *this,
        vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *arena,
        unsigned int arena_size)
{
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *v4; // [esp+0h] [ebp-1Ch]
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *i; // [esp+Ch] [ebp-10h]
  bool do_debug_break; // [esp+13h] [ebp-9h] BYREF
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *end; // [esp+14h] [ebp-8h]
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *begin; // [esp+18h] [ebp-4h]

  this->m_allocated_count = 0;
  this->m_max_count = 0;
  this->m_max_count = arena_size >> 4;
  if ( `vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always
    || !(arena_size % 0x10) )
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
    if ( `vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>'::`8'::occurances_left == -1 )
      `vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>'::`8'::occurances_left = 10;
    if ( `vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>'::`8'::occurances_left-- )
    {
      if ( !`vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "arena_size % element_size == 0",
          "C:\\survarium\\sources\\vostok/memory_single_size_buffer_allocator_inline.h",
          "vostok::memory::single_size_buffer_allocator<16,class vostok::threading::single_threading_policy>::single_size"
          "_buffer_allocator",
          0x16u,
          "address of arena isn't aligned or data size is improper");
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
  }
}


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


void __thiscall vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>(
        vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy> *this,
        vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::node *arena,
        unsigned int arena_size)
{
  vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::node *v4; // [esp+0h] [ebp-1Ch]
  vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::node *i; // [esp+Ch] [ebp-10h]
  bool do_debug_break; // [esp+13h] [ebp-9h] BYREF
  vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::node *end; // [esp+14h] [ebp-8h]
  vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::node *begin; // [esp+18h] [ebp-4h]

  this->m_allocated_count = 0;
  this->m_max_count = 0;
  this->m_max_count = arena_size / 0x1C;
  if ( `vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always
    || !(arena_size % 0x1C) )
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
    if ( `vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>'::`8'::occurances_left == -1 )
      `vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>'::`8'::occurances_left = 10;
    if ( `vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>'::`8'::occurances_left-- )
    {
      if ( !`vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "arena_size % element_size == 0",
          "C:\\survarium\\sources\\vostok/memory_single_size_buffer_allocator_inline.h",
          "vostok::memory::single_size_buffer_allocator<28,class vostok::threading::single_threading_policy>::single_size"
          "_buffer_allocator",
          0x16u,
          "address of arena isn't aligned or data size is improper");
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
  }
}


void __thiscall vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>(
        vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy> *this,
        vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::node *arena,
        unsigned int arena_size)
{
  vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::node *v4; // [esp+0h] [ebp-20h]
  vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::node *i; // [esp+10h] [ebp-10h]
  bool do_debug_break; // [esp+17h] [ebp-9h] BYREF
  vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::node *end; // [esp+18h] [ebp-8h]
  vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::node *begin; // [esp+1Ch] [ebp-4h]

  this->m_allocated_count = 0;
  this->m_max_count = 0;
  this->m_max_count = arena_size / 0x218;
  if ( `vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>'::`5'::debug_macro_helper_ignore_always
    || !(arena_size % 0x218) )
  {
    this->m_free_list_head.pointer = 0;
    this->m_free_list_head.whole = 0;
    this->m_free_list_head.counter = 0;
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
    if ( `vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>'::`8'::occurances_left == -1 )
      `vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>'::`8'::occurances_left = 10;
    if ( `vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>'::`8'::occurances_left-- )
    {
      if ( !`vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "arena_size % element_size == 0",
          "C:\\survarium\\sources\\vostok/memory_single_size_buffer_allocator_inline.h",
          "vostok::memory::single_size_buffer_allocator<536,class vostok::threading::multi_threading_policy>::single_size"
          "_buffer_allocator",
          0x16u,
          "address of arena isn't aligned or data size is improper");
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
  }
}


void __thiscall vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>(
        vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy> *this,
        vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node *arena,
        unsigned int arena_size)
{
  _BYTE *v3; // eax
  survarium::game_world *v4; // ecx
  _BYTE *v5; // eax
  vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node *v7; // [esp+0h] [ebp-1Ch]
  vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node *i; // [esp+Ch] [ebp-10h]
  bool do_debug_break; // [esp+13h] [ebp-9h] BYREF
  vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node *end; // [esp+14h] [ebp-8h]
  vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node *begin; // [esp+18h] [ebp-4h]

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->m_allocated_count = 0;
  this->m_max_count = 0;
  this->m_max_count = arena_size / 0x2C;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x2C);
  if ( !*v3
    || BYTE1(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[2])
    || (survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x2C), *v5) )
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
    if ( `vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>'::`8'::occurances_left == -1 )
      `vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>'::`8'::occurances_left = vostok::ui::ui_dialog::input_priority(v4);
    if ( `vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>'::`8'::occurances_left-- )
    {
      if ( !BYTE1(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[2]) )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[2]
        + 1,
          assert_untyped,
          "assertion_failed",
          "arena_size % element_size == 0",
          "C:\\survarium\\sources\\vostok/memory_single_size_buffer_allocator_inline.h",
          &stru_97F6C0.m_buffer[12],
          0x16u,
          "address of arena isn't aligned or data size is improper");
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
  }
}


void __thiscall vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>(
        vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy> *this,
        vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>::node *arena,
        unsigned int arena_size)
{
  vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>::node *v4; // [esp+0h] [ebp-1Ch]
  vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>::node *i; // [esp+Ch] [ebp-10h]
  bool do_debug_break; // [esp+13h] [ebp-9h] BYREF
  vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>::node *end; // [esp+14h] [ebp-8h]
  vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>::node *begin; // [esp+18h] [ebp-4h]

  this->m_allocated_count = 0;
  this->m_max_count = 0;
  this->m_max_count = arena_size / 0x6C;
  if ( `vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always
    || !(arena_size % 0x6C) )
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
    if ( `vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>'::`8'::occurances_left == -1 )
      `vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>'::`8'::occurances_left = 10;
    if ( `vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>'::`8'::occurances_left-- )
    {
      if ( !`vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "arena_size % element_size == 0",
          "C:\\survarium\\sources\\vostok/memory_single_size_buffer_allocator_inline.h",
          "vostok::memory::single_size_buffer_allocator<108,class vostok::threading::single_threading_policy>::single_siz"
          "e_buffer_allocator",
          0x16u,
          "address of arena isn't aligned or data size is improper");
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
  }
}


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


void __thiscall vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::single_size_buffer_allocator<128,vostok::threading::simple_lock>(
        vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock> *this,
        vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::node *arena,
        unsigned int arena_size)
{
  _BYTE *v3; // eax
  survarium::game_world *v4; // ecx
  _BYTE *v5; // eax
  vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::node *v7; // [esp+0h] [ebp-20h]
  vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::node *i; // [esp+10h] [ebp-10h]
  bool do_debug_break; // [esp+17h] [ebp-9h] BYREF
  vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::node *end; // [esp+18h] [ebp-8h]
  vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::node *begin; // [esp+1Ch] [ebp-4h]

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->m_allocated_count = 0;
  this->m_max_count = 0;
  this->m_max_count = arena_size >> 7;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( !*v3
    || `vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::single_size_buffer_allocator<128,vostok::threading::simple_lock>'::`5'::debug_macro_helper_ignore_always
    || (survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x80), *v5) )
  {
    this->m_free_list_head.pointer = 0;
    this->m_free_list_head.pointer = 0;
    this->m_free_list_head.counter = 0;
    this->m_free_list_head.counter = 0;
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
    if ( `vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::single_size_buffer_allocator<128,vostok::threading::simple_lock>'::`8'::occurances_left == -1 )
      `vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::single_size_buffer_allocator<128,vostok::threading::simple_lock>'::`8'::occurances_left = vostok::ui::ui_dialog::input_priority(v4);
    if ( `vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::single_size_buffer_allocator<128,vostok::threading::simple_lock>'::`8'::occurances_left-- )
    {
      if ( !`vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::single_size_buffer_allocator<128,vostok::threading::simple_lock>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::single_size_buffer_allocator<128,vostok::threading::simple_lock>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "arena_size % element_size == 0",
          "C:\\survarium\\sources\\vostok/memory_single_size_buffer_allocator_inline.h",
          "vostok::memory::single_size_buffer_allocator<128,class vostok::threading::simple_lock>::single_size_buffer_allocator",
          0x16u,
          "address of arena isn't aligned or data size is improper");
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
  }
}


void __thiscall vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>(
        vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy> *this,
        vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>::node *arena,
        unsigned int arena_size)
{
  vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>::node *v4; // [esp+0h] [ebp-1Ch]
  vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>::node *i; // [esp+Ch] [ebp-10h]
  bool do_debug_break; // [esp+13h] [ebp-9h] BYREF
  vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>::node *end; // [esp+14h] [ebp-8h]
  vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>::node *begin; // [esp+18h] [ebp-4h]

  this->m_allocated_count = 0;
  this->m_max_count = 0;
  this->m_max_count = arena_size / 0x88;
  if ( `vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always
    || !(arena_size % 0x88) )
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
    if ( `vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>'::`8'::occurances_left == -1 )
      `vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>'::`8'::occurances_left = 10;
    if ( `vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>'::`8'::occurances_left-- )
    {
      if ( !`vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "arena_size % element_size == 0",
          "C:\\survarium\\sources\\vostok/memory_single_size_buffer_allocator_inline.h",
          "vostok::memory::single_size_buffer_allocator<136,class vostok::threading::single_threading_policy>::single_siz"
          "e_buffer_allocator",
          0x16u,
          "address of arena isn't aligned or data size is improper");
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
  }
}


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


void __userpurge vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::single_size_buffer_allocator<12,vostok::threading::mutex>(
        vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex> *this@<esi>,
        unsigned int arena_size@<ecx>,
        vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node *arena)
{
  vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node *v3; // ebp
  unsigned int v4; // eax
  unsigned int m_max_count; // eax
  vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node *v6; // edi
  vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node *i; // ecx

  v3 = arena;
  this->m_allocated_count = 0;
  this->m_max_count = arena_size / 0xC;
  if ( `vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::single_size_buffer_allocator<12,vostok::threading::mutex>'::`5'::debug_macro_helper_ignore_always
    || !(arena_size % 0xC) )
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
    v4 = `vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::single_size_buffer_allocator<12,vostok::threading::mutex>'::`8'::occurances_left;
    if ( `vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::single_size_buffer_allocator<12,vostok::threading::mutex>'::`8'::occurances_left == -1 )
      v4 = 10;
    `vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::single_size_buffer_allocator<12,vostok::threading::mutex>'::`8'::occurances_left = v4 - 1;
    if ( v4 )
    {
      LOBYTE(arena) = 0;
      vostok::debug::on_error(
        (bool *)&arena,
        process_error_false,
        &`vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::single_size_buffer_allocator<12,vostok::threading::mutex>'::`5'::debug_macro_helper_ignore_always,
        assert_untyped,
        "assertion_failed",
        "arena_size % element_size == 0",
        "C:\\survarium\\sources\\vostok/memory_single_size_buffer_allocator_inline.h",
        "vostok::memory::single_size_buffer_allocator<12,class vostok::threading::mutex>::single_size_buffer_allocator",
        0x16u,
        "address of arena isn't aligned or data size is improper");
      if ( vostok::debug::is_debugger_present() || (_BYTE)arena )
        __debugbreak();
    }
  }
}


void __thiscall vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::single_size_buffer_allocator<208,vostok::threading::mutex>(
        vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex> *this,
        vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::node *arena,
        unsigned int arena_size)
{
  _BYTE *v3; // eax
  survarium::game_world *v4; // ecx
  _BYTE *v5; // eax
  vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::node *v7; // [esp+0h] [ebp-20h]
  vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::node *i; // [esp+10h] [ebp-10h]
  bool do_debug_break; // [esp+17h] [ebp-9h] BYREF
  vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::node *end; // [esp+18h] [ebp-8h]
  vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::node *begin; // [esp+1Ch] [ebp-4h]

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->m_allocated_count = 0;
  this->m_max_count = 0;
  this->m_max_count = arena_size / 0xD0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0xD0);
  if ( !*v3
    || `vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::single_size_buffer_allocator<208,vostok::threading::mutex>'::`5'::debug_macro_helper_ignore_always
    || (survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0xD0), *v5) )
  {
    this->m_free_list_head.pointer = 0;
    this->m_free_list_head.pointer = 0;
    this->m_free_list_head.counter = 0;
    this->m_free_list_head.counter = 0;
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
    if ( `vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::single_size_buffer_allocator<208,vostok::threading::mutex>'::`8'::occurances_left == -1 )
      `vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::single_size_buffer_allocator<208,vostok::threading::mutex>'::`8'::occurances_left = vostok::ui::ui_dialog::input_priority(v4);
    if ( `vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::single_size_buffer_allocator<208,vostok::threading::mutex>'::`8'::occurances_left-- )
    {
      if ( !`vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::single_size_buffer_allocator<208,vostok::threading::mutex>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::single_size_buffer_allocator<208,vostok::threading::mutex>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "arena_size % element_size == 0",
          "C:\\survarium\\sources\\vostok/memory_single_size_buffer_allocator_inline.h",
          "vostok::memory::single_size_buffer_allocator<208,class vostok::threading::mutex>::single_size_buffer_allocator",
          0x16u,
          "address of arena isn't aligned or data size is improper");
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
  }
}
