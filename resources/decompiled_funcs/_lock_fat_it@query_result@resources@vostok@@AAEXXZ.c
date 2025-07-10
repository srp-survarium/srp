void __usercall vostok::resources::query_result::lock_fat_it(vostok::resources::query_result *this@<ecx>, int a2@<eax>)
{
  if ( *(_DWORD *)(a2 + 164) )
  {
    vostok::threading::interlocked_or((volatile int *)(a2 + 688), 0x10u);
    vostok::threading::interlocked_exchange_add(
      (int *)((char *)&dword_201B8 + (unsigned int)vostok::resources::g_resources_manager.m_variable),
      1u);
  }
}
