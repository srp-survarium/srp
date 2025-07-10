void __thiscall vostok::ai::priority_queue::binary_heap::impl<vostok::sound::search::search_service::vertex_manager_impl_type>::add_to_opened_list(
        vostok::ai::priority_queue::binary_heap::impl<vostok::sound::search::search_service::vertex_manager_impl_type> *this,
        vostok::sound::search::search_service::vertex_type *vertex)
{
  vostok::sound::search::search_service::vertex_type **__last; // [esp+0h] [ebp-18h]

  vertex->m_opened = 1;
  if ( *this->m_heap_head
    && (float)(vertex->m_g + vertex->m_h) <= (float)(**(float **)this->m_heap_head + (*this->m_heap_head)->m_h) )
  {
    *this->m_heap_tail = *this->m_heap_head;
    *this->m_heap_head = vertex;
  }
  else
  {
    *this->m_heap_tail = vertex;
  }
  __last = this->m_heap_tail;
  this->m_heap_tail = __last + 1;
  stlp_std::push_heap<vostok::sound::search::search_service::vertex_type * *,vostok::ai::priority_queue::binary_heap::impl<vostok::sound::search::search_service::vertex_manager_impl_type>::predicate>(
    this->m_heap_head,
    __last,
    0);
}
