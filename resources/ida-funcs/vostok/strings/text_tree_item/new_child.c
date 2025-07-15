vostok::strings::text_tree_item *__thiscall vostok::strings::text_tree_item::new_child(
        vostok::strings::text_tree_item *this,
        const char *s,
        char *is_page_breaker)
{
  int v3; // edi
  vostok::threading::mutex *v4; // ecx
  vostok::strings::text_tree_item *v5; // esi
  vostok::strings::text_tree_item *v6; // eax
  vostok::strings::text_tree_item *v7; // edi
  bool v9; // [esp+0h] [ebp-Ch]

  v3 = *((_DWORD *)s + 27);
  type_info::raw_name(&vostok::strings::text_tree_item `RTTI Type Descriptor');
  v5 = *(vostok::strings::text_tree_item **)(v3 + 20);
  *(_DWORD *)(v3 + 20) = v5 + 1;
  if ( v5 )
  {
    vostok::strings::text_tree_item::text_tree_item(
      v5,
      *((vostok::memory::stack_allocator **)s + 27),
      &v4->m_mutex,
      is_page_breaker,
      v9);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  vostok::intrusive_list<vostok::strings::text_tree_column_item,vostok::strings::text_tree_column_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<vostok::strings::text_tree_item_base,vostok::strings::text_tree_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)(s + 8),
    v7,
    v4);
  return v7;
}


vostok::strings::text_tree_item *__thiscall vostok::strings::text_tree_item::new_child<unsigned int>(
        vostok::strings::text_tree_item *this,
        char *name,
        char *value,
        int a4)
{
  vostok::strings::text_tree_item *v4; // esi
  vostok::debug::detail::string_helper *str_impl; // eax
  vostok::strings::text_tree_item *v7; // [esp-4h] [ebp-Ch]

  v4 = vostok::strings::text_tree_item::new_child(this, name, value);
  str_impl = vostok::strings::make_str_impl("%u", a4);
  vostok::strings::text_tree_item::add_column_impl(v7, (const char *)v4, str_impl->m_buffer);
  return v4;
}
