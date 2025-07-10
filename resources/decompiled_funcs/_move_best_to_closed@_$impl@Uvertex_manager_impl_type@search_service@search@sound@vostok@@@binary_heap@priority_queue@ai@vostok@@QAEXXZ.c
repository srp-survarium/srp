void __thiscall vostok::ai::priority_queue::binary_heap::impl<vostok::sound::search::search_service::vertex_manager_impl_type>::move_best_to_closed(
        vostok::ai::priority_queue::binary_heap::impl<vostok::sound::search::search_service::vertex_manager_impl_type> *this)
{
  vostok::sound::search::search_service::vertex_type **__last; // [esp+0h] [ebp-14h]

  (*this->m_heap_head)->m_opened = 0;
  __last = this->m_heap_tail;
  this->m_heap_tail = __last - 1;
  stlp_std::pop_heap<vostok::sound::search::search_service::vertex_type * *,vostok::ai::priority_queue::binary_heap::impl<vostok::sound::search::search_service::vertex_manager_impl_type>::predicate>(
    this->m_heap_head,
    __last,
    0);
}
