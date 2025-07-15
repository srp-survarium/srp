void __userpurge vostok::logging::filter_tree::filter_tree(
        vostok::logging::filter_tree *this@<ecx>,
        int a2@<edi>,
        vostok::logging::base_allocator *allocator)
{
  int v3; // eax
  vostok::logging::node *v4; // ecx
  int v5; // eax

  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  v3 = allocator->allocate(allocator, 72);
  if ( v3 )
    vostok::logging::node::node(v4, v3, (char *)uri, trace);
  else
    v5 = 0;
  *(_DWORD *)(a2 + 8) = v5;
  *(_DWORD *)(a2 + 12) = allocator;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    (vostok::threading::mutex_tasks_unaware *)v4,
    (_RTL_CRITICAL_SECTION *)(a2 + 32));
}
