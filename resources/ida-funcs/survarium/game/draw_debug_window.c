// bad sp value at call has been detected, the output may be wrong!
void __usercall survarium::game::draw_debug_window(survarium::game *this@<ecx>, int a2@<eax>)
{
  void *v3; // esp
  vostok::strings::text_tree_item *v4; // ecx
  vostok::strings::text_tree *v5; // ecx
  const char *v6; // [esp-10000h] [ebp-10098h] BYREF
  vostok::strings::text_tree_item v7; // [esp+8h] [ebp-90h] BYREF

  v3 = alloca((int)&_sbh_sizeHeaderList);
  vostok::strings::text_tree::text_tree((vostok::strings::text_tree *)this, (int)&v7, &v6, "resources stats", v6);
  if ( *(_DWORD *)(a2 + 15164) == 1 )
    vostok::resources::resources_manager::fill_stats(&v7, v4);
  else
    vostok::tasks::thread_pool::fill_stats((vostok::tasks::thread_pool *)v4, s_thread_pool.m_variable, &v7);
  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 15168) + 72))(*(_DWORD *)(a2 + 15168));
  vostok::strings::text_tree::~text_tree(v5, &v7);
}
