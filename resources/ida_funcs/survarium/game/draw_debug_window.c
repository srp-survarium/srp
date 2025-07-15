// bad sp value at call has been detected, the output may be wrong!
void __usercall survarium::game::draw_debug_window(survarium::game *this@<ecx>, int a2@<esi>)
{
  void *v2; // esp
  int v3; // [esp-10000h] [ebp-10090h] BYREF
  vostok::strings::text_tree v4; // [esp+0h] [ebp-90h] BYREF

  v2 = alloca((int)&_sbh_sizeHeaderList);
  vostok::strings::text_tree::text_tree(&v4, &v3, (const unsigned int)&_sbh_sizeHeaderList, "resources stats");
  if ( *(_DWORD *)(a2 + 2160) == 1 )
    vostok::resources::resources_manager::fill_stats(vostok::resources::g_resources_manager.m_variable, &v4.m_root);
  else
    vostok::tasks::thread_pool::fill_stats((vostok::tasks::thread_pool *)&v4, &v4.m_root);
  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 2164) + 72))(*(_DWORD *)(a2 + 2164));
  v4.m_allocator.finalize_impl(&v4.m_allocator);
  memset(&v4.m_allocator.m_arena_start, 0, 12);
  v4.m_allocator.__vftable = (vostok::memory::stack_allocator_vtbl *)&vostok::memory::base_allocator::`vftable';
  vostok::strings::text_tree_item::~text_tree_item(&v4.m_root);
}
