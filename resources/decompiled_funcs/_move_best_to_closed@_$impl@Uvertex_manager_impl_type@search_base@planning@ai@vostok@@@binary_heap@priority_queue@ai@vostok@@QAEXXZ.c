void __thiscall vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type>::move_best_to_closed(
        vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type> *this)
{
  vostok::ai::planning::search_base::vertex_type **__last; // [esp+0h] [ebp-14h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  (*this->m_heap_head)->m_opened = 0;
  __last = this->m_heap_tail;
  this->m_heap_tail = __last - 1;
  stlp_std::pop_heap<vostok::ai::planning::search_base::vertex_type * *,vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type>::predicate>(
    this->m_heap_head,
    __last,
    0);
}
