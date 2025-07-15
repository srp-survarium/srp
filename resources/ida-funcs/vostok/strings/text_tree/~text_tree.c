void __usercall vostok::strings::text_tree::~text_tree(vostok::strings::text_tree *this@<ecx>, _DWORD *a2@<edi>)
{
  vostok::strings::text_tree_item *v2; // ecx

  (*(void (__thiscall **)(_DWORD *))(a2[30] + 36))(a2 + 30);
  a2[31] = 0;
  a2[32] = 0;
  a2[33] = 0;
  a2[30] = &vostok::memory::base_allocator::`vftable';
  vostok::strings::text_tree_item::~text_tree_item(v2, (int)a2);
}
