void __userpurge vostok::intrusive_list<vostok::strings::text_tree_column_item,vostok::strings::text_tree_column_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::strings::text_tree_item_base,vostok::strings::text_tree_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        int a2@<esi>,
        vostok::strings::text_tree_item *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // edi

  object->m_next_brother = 0;
  if ( a2 )
    v4 = (vostok::threading::mutex *)(a2 + 8);
  else
    v4 = 0;
  vostok::threading::mutex::lock(v4);
  ++*(_DWORD *)a2;
  if ( *(_DWORD *)(a2 + 36) )
    **(_DWORD **)(a2 + 40) = object;
  else
    *(_DWORD *)(a2 + 36) = object;
  *(_DWORD *)(a2 + 40) = object;
  LeaveCriticalSection((LPCRITICAL_SECTION)v4);
}
