void __thiscall vostok::strings::text_tree_item::add_column_impl(
        vostok::strings::text_tree_item *this,
        const char *s,
        char *string)
{
  int v3; // esi
  vostok::strings::text_tree_item *v4; // eax
  vostok::strings::text_tree_item *v5; // edi
  vostok::threading::mutex *v6; // [esp-4h] [ebp-10h]

  v3 = *((_DWORD *)s + 27);
  type_info::raw_name(&vostok::strings::text_tree_column_item `RTTI Type Descriptor');
  v4 = *(vostok::strings::text_tree_item **)(v3 + 20);
  v5 = 0;
  *(_DWORD *)(v3 + 20) = &v4->m_sub_items;
  if ( v4 )
  {
    v4->m_next_brother = 0;
    *((_DWORD *)&v4->vostok::strings::text_tree_item_base + 1) = 0;
    v5 = v4;
  }
  *((_DWORD *)&v5->vostok::strings::text_tree_item_base + 1) = vostok::strings::duplicate<vostok::memory::stack_allocator>(
                                                                 *((vostok::memory::stack_allocator **)s + 27),
                                                                 string);
  vostok::intrusive_list<vostok::strings::text_tree_column_item,vostok::strings::text_tree_column_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<vostok::strings::text_tree_item_base,vostok::strings::text_tree_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)(s + 56),
    v5,
    v6);
}
