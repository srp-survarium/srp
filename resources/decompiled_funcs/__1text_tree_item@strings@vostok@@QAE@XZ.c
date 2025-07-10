void __thiscall vostok::strings::text_tree_item::~text_tree_item(vostok::strings::text_tree_item *this)
{
  vostok::strings::text_tree_item::clear(this);
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->m_column_items.vostok::threading::mutex);
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->m_sub_items.vostok::threading::mutex);
}
