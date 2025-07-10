void __usercall vostok::console_commands::save_storage::save_storage(
        vostok::console_commands::save_storage *this@<ecx>,
        _DWORD *a2@<eax>)
{
  *a2 = 0;
  a2[1] = 0;
  a2[2] = &vostok::memory::g_mt_allocator;
  a2[3] = 0;
  a2[4] = &vostok::memory::g_mt_allocator;
}
