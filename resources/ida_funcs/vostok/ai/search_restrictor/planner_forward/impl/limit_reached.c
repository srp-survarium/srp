bool __thiscall vostok::ai::search_restrictor::planner_forward::impl::limit_reached<vostok::ai::planning::search_base::priority_queue_impl_type>(
        vostok::ai::search_restrictor::planner_forward::impl *this,
        const vostok::ai::planning::search_base::priority_queue_impl_type *queue,
        survarium::game_camera *iteration_count)
{
  if ( (unsigned int)iteration_count >= this->m_max_iteration_count )
    return 1;
  survarium::weapon_user_dead_state::finalize(iteration_count);
  return (*queue->m_heap_head)->m_h + **(_DWORD **)queue->m_heap_head >= this->m_max_range
      || queue->m_manager->m_allocator->m_vertex_current - queue->m_manager->m_allocator->m_vertices >= this->m_max_visited_vertex_count;
}
