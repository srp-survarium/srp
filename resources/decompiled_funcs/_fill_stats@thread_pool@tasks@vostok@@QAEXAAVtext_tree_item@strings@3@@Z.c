void __userpurge vostok::tasks::thread_pool::fill_stats(
        vostok::tasks::thread_pool *this@<ecx>,
        vostok::tasks::thread_pool *a2@<eax>,
        vostok::strings::text_tree_item *stats)
{
  void *v5; // esp
  int v6; // edx
  unsigned int v7; // eax
  vostok::memory::stack_allocator *m_allocator; // eax
  vostok::strings::text_tree_item *m_arena_current_position; // esi
  vostok::strings::text_tree_item *v10; // eax
  vostok::memory::stack_allocator *v11; // eax
  vostok::strings::text_tree_item *v12; // esi
  vostok::strings::text_tree_item *v13; // ecx
  vostok::strings::text_tree_item *v14; // eax
  const char *i; // ebx
  vostok::fixed_string<512> *v16; // eax
  bool *v17[4]; // [esp+0h] [ebp-224h] BYREF
  _BYTE v18[524]; // [esp+10h] [ebp-214h] BYREF
  vostok::tasks::thread_tls::type_enum __formal; // [esp+21Ch] [ebp-8h]
  unsigned int threads_count; // [esp+220h] [ebp-4h]
  vostok::strings::text_tree_item *statsa; // [esp+22Ch] [ebp+8h]
  vostok::strings::text_tree_item *statsb; // [esp+22Ch] [ebp+8h]

  v5 = alloca(4 * (a2->m_core_thread_count.m_end - a2->m_core_thread_count.m_begin));
  v6 = a2->m_core_thread_count.m_end - a2->m_core_thread_count.m_begin;
  v7 = 0;
  __formal = (vostok::tasks::thread_tls::type_enum)v17;
  if ( v6 )
  {
    do
      v17[v7++] = 0;
    while ( v7 < a2->m_core_thread_count.m_end - a2->m_core_thread_count.m_begin );
  }
  m_allocator = stats->m_allocator;
  m_arena_current_position = (vostok::strings::text_tree_item *)m_allocator->m_arena_current_position;
  m_allocator->m_arena_current_position = &m_arena_current_position[1];
  if ( m_arena_current_position )
  {
    vostok::strings::text_tree_item::text_tree_item(m_arena_current_position + 1, stats->m_allocator, "threads", 0);
    statsa = v10;
  }
  else
  {
    statsa = 0;
  }
  threads_count = (unsigned int)&stats->m_sub_items;
  vostok::intrusive_list<vostok::strings::text_tree_column_item,vostok::strings::text_tree_column_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<vostok::strings::text_tree_item_base,vostok::strings::text_tree_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)statsa,
    (int)&stats->m_sub_items,
    statsa,
    v17[0]);
  vostok::tasks::thread_pool::fill_stats(
    a2,
    &a2->m_user_thread_tls,
    statsa,
    (unsigned int *)__formal,
    (unsigned int *)v17[0]);
  v11 = stats->m_allocator;
  v12 = (vostok::strings::text_tree_item *)v11->m_arena_current_position;
  v13 = v12 + 1;
  v11->m_arena_current_position = &v12[1];
  if ( v12 )
  {
    vostok::strings::text_tree_item::text_tree_item(v13, stats->m_allocator, "CORES", 0);
    statsb = v14;
  }
  else
  {
    statsb = 0;
  }
  vostok::intrusive_list<vostok::strings::text_tree_column_item,vostok::strings::text_tree_column_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<vostok::strings::text_tree_item_base,vostok::strings::text_tree_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)v13,
    threads_count,
    statsb,
    v17[0]);
  for ( i = 0; (unsigned int)i < a2->m_core_thread_count.m_end - a2->m_core_thread_count.m_begin; ++i )
  {
    threads_count = a2->m_core_thread_count.m_begin[(_DWORD)i];
    v16 = vostok::fixed_string<512>::createf((int)v18, (vostok::fixed_string<512> *)&stru_95DC74, i);
    vostok::strings::text_tree_item::new_childf(
      statsb,
      v16->m_begin,
      "(%d user + %d task)",
      threads_count - *(_DWORD *)(__formal + 4 * (_DWORD)i),
      *(_DWORD *)(__formal + 4 * (_DWORD)i));
  }
}
