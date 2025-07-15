void __userpurge vostok::strings::text_tree::text_tree(
        vostok::strings::text_tree *this@<ecx>,
        int a2@<eax>,
        void *buffer,
        char *buffer_size,
        const char *root_name)
{
  int v6; // edi
  vostok::memory::stack_allocator *v7; // ecx
  bool v8; // [esp+0h] [ebp-Ch]

  v6 = a2 + 120;
  vostok::strings::text_tree_item::text_tree_item(
    (vostok::strings::text_tree_item *)a2,
    (vostok::memory::stack_allocator *)(a2 + 120),
    (vostok::threading::mutex_tasks_unaware *)this,
    0,
    v8);
  vostok::memory::stack_allocator::stack_allocator(v7, v6);
  (*(void (__thiscall **)(int, void *, HINSTANCE__ *, _DWORD, const char *))(*(_DWORD *)v6 + 4))(
    v6,
    buffer,
    &_sbh_sizeHeaderList,
    0,
    "text_tree");
  if ( *(_DWORD *)(a2 + 104) )
    *(_DWORD *)(a2 + 104) = 0;
  if ( buffer_size )
    *(_DWORD *)(a2 + 104) = vostok::strings::duplicate<vostok::memory::stack_allocator>(
                              *(vostok::memory::stack_allocator **)(a2 + 108),
                              buffer_size);
}
