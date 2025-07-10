void __thiscall vostok::strings::text_tree_item::clear(vostok::strings::text_tree_item *this)
{
  vostok::intrusive_list<vostok::strings::text_tree_item_base,vostok::strings::text_tree_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *p_m_sub_items; // esi
  vostok::threading::mutex *v3; // ebx
  vostok::intrusive_list<vostok::strings::text_tree_column_item,vostok::strings::text_tree_column_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v4; // ecx
  vostok::threading::mutex *v5; // ebx
  vostok::strings::text_tree_item::text_tree_item_deleter deleter; // [esp+10h] [ebp-8h] BYREF
  vostok::strings::text_tree_item::text_tree_item_deleter *p_deleter; // [esp+14h] [ebp-4h]

  deleter.m_allocator = this->m_allocator;
  p_m_sub_items = &this->m_sub_items;
  p_deleter = &deleter;
  vostok::intrusive_list<vostok::strings::text_tree_item_base,vostok::strings::text_tree_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::strings::text_tree_item_base,vostok::strings::text_tree_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::strings::text_tree_item::text_tree_item_deleter>>(
    (vostok::intrusive_list<vostok::strings::text_tree_item_base,vostok::strings::text_tree_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&deleter,
    (int)&this->m_sub_items);
  if ( this == (vostok::strings::text_tree_item *)-8 )
    v3 = 0;
  else
    v3 = &this->m_sub_items.vostok::threading::mutex;
  vostok::threading::mutex::lock(v3);
  this->m_sub_items.m_first = 0;
  this->m_sub_items.m_last = 0;
  p_m_sub_items->m_size = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)v3);
  p_deleter = &deleter;
  vostok::intrusive_list<vostok::strings::text_tree_column_item,vostok::strings::text_tree_column_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::strings::text_tree_column_item,vostok::strings::text_tree_column_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::strings::text_tree_item::text_tree_item_deleter>>(
    v4,
    (int)&this->m_column_items);
  if ( this == (vostok::strings::text_tree_item *)-56 )
    v5 = 0;
  else
    v5 = &this->m_column_items.vostok::threading::mutex;
  vostok::threading::mutex::lock(v5);
  this->m_column_items.m_first = 0;
  this->m_column_items.m_last = 0;
  this->m_column_items.m_size = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)v5);
  if ( this->m_column_value )
    this->m_column_value = 0;
}
