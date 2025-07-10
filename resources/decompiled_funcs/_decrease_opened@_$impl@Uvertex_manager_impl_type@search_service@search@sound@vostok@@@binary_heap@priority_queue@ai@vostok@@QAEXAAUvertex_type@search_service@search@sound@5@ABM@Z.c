void __thiscall vostok::ai::priority_queue::binary_heap::impl<vostok::sound::search::search_service::vertex_manager_impl_type>::decrease_opened(
        vostok::ai::priority_queue::binary_heap::impl<vostok::sound::search::search_service::vertex_manager_impl_type> *this,
        vostok::sound::search::search_service::vertex_type *vertex,
        const float *value)
{
  vostok::sound::search::search_service::vertex_type **i; // [esp+8h] [ebp-4h]

  for ( i = this->m_heap_head; *i != vertex; ++i )
    ;
  stlp_std::push_heap<vostok::sound::search::search_service::vertex_type * *,vostok::ai::priority_queue::binary_heap::impl<vostok::sound::search::search_service::vertex_manager_impl_type>::predicate>(
    this->m_heap_head,
    i + 1,
    0);
}
