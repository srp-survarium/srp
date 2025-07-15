void __thiscall vostok::memory::managed_allocator::deallocate(vostok::memory::managed_allocator *this)
{
  unsigned int v1; // eax
  vostok::memory::managed_allocator_vtbl *v2; // ecx
  void (__thiscall *v3)(struct vostok::memory::managed_allocator *); // eax
  const char **v4; // eax
  bool v5[527]; // [esp+8h] [ebp-210h] BYREF
  bool do_debug_break; // [esp+217h] [ebp-1h] BYREF

  if ( debug_macro_helper_ignore_always_23 || !LOBYTE(this->m_arena_size) )
  {
    vostok::memory::managed_allocator_base::deallocate(
      (vostok::memory::managed_allocator_base *)this,
      (int)&vostok::memory::g_resources_managed_allocator.vostok::memory::managed_allocator_base);
  }
  else
  {
    v1 = occurances_left_16;
    if ( occurances_left_16 == -1 )
      v1 = 10;
    occurances_left_16 = v1 - 1;
    if ( v1 )
    {
      v2 = this->__vftable;
      v3 = v2->~vostok::memory::managed_allocator;
      do_debug_break = 0;
      v4 = (const char **)(*((int (__thiscall **)(vostok::memory::managed_allocator_vtbl *, bool *))v3 + 2))(v2, v5);
      vostok::debug::on_error(
        &do_debug_break,
        process_error_false,
        0,
        "assertion_failed",
        "node->is_allocated()",
        ".\\managed_allocator.cpp",
        "vostok::memory::managed_allocator::deallocate",
        (const char *)0x76,
        "resources:allocator",
        "bah! already deallocated node: %s",
        *v4);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
  }
}
