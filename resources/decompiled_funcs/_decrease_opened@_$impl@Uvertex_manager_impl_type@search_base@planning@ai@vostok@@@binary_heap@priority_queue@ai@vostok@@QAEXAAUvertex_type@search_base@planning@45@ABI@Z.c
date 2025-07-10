void __thiscall vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type>::decrease_opened(
        vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type> *this,
        vostok::ai::planning::search_base::vertex_type *vertex,
        const unsigned int *value)
{
  vostok::ai::planning::search_base::vertex_type **i; // [esp+8h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  for ( i = this->m_heap_head; *i != vertex; ++i )
    ;
  stlp_std::push_heap<vostok::ai::planning::search_base::vertex_type * *,vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type>::predicate>(
    this->m_heap_head,
    i + 1,
    0);
}
