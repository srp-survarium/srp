void __usercall vostok::memory::managed_allocator::deallocate(
        vostok::memory::managed_allocator *this@<ecx>,
        unsigned int a2@<ebx>)
{
  unsigned int v2; // eax
  vostok::memory::managed_allocator_vtbl *v3; // ecx
  _DWORD *v4; // eax
  bool do_debug_break; // [esp+5h] [ebp-20Dh] BYREF
  _BYTE v6[524]; // [esp+6h] [ebp-20Ch] BYREF

  if ( debug_macro_helper_ignore_always_16 || !LOBYTE(this->m_arena_size) )
  {
    vostok::memory::managed_allocator_base::deallocate(
      (vostok::memory::managed_allocator_base *)this,
      (int)&vostok::memory::g_resources_managed_allocator.vostok::memory::managed_allocator_base);
  }
  else
  {
    v2 = occurances_left_16;
    if ( occurances_left_16 == -1 )
      v2 = 10;
    occurances_left_16 = v2 - 1;
    if ( v2 )
    {
      v3 = this->__vftable;
      do_debug_break = 0;
      v4 = (_DWORD *)(*((int (__thiscall **)(vostok::memory::managed_allocator_vtbl *, _BYTE *))v3->~vostok::memory::managed_allocator
                      + 2))(
                       v3,
                       v6);
      vostok::debug::on_error(
        a2,
        &do_debug_break,
        process_error_false,
        &debug_macro_helper_ignore_always_16,
        assert_untyped,
        "assertion_failed",
        "node->is_allocated()",
        ".\\managed_allocator.cpp",
        "vostok::memory::managed_allocator::deallocate",
        0x76u,
        "resources:allocator",
        "bah! already deallocated node: %s",
        *v4);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
  }
}
