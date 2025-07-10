void __thiscall vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type>::add_to_opened_list(
        vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type> *this,
        vostok::ai::planning::search_base::vertex_type *vertex)
{
  vostok::ai::planning::search_base::vertex_type **__last; // [esp+0h] [ebp-18h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vertex->m_opened = 1;
  if ( *this->m_heap_head && (*this->m_heap_head)->m_h + **(_DWORD **)this->m_heap_head >= vertex->m_h + vertex->m_g )
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
  stlp_std::push_heap<vostok::ai::planning::search_base::vertex_type * *,vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type>::predicate>(
    this->m_heap_head,
    __last,
    0);
}
