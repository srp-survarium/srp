bool __thiscall vostok::ai::search_restrictor::planner_backward::impl::limit_reached<vostok::ai::planning::search_base::priority_queue_impl_type>(
        vostok::ai::search_restrictor::planner_backward::impl *this,
        const vostok::ai::planning::search_base::priority_queue_impl_type *queue,
        survarium::game_camera *iteration_count)
{
  unsigned int v5; // [esp+14h] [ebp-Ch] BYREF
  unsigned int visited_vertex_count; // [esp+18h] [ebp-8h]
  const unsigned int *current_range; // [esp+1Ch] [ebp-4h]

  if ( (unsigned int)iteration_count >= this->m_max_iteration_count )
    return 1;
  survarium::weapon_user_dead_state::finalize(iteration_count);
  v5 = (*queue->m_heap_head)->m_h + **(_DWORD **)queue->m_heap_head;
  current_range = &v5;
  if ( v5 >= this->m_max_range )
    return 1;
  visited_vertex_count = queue->m_manager->m_allocator->m_vertex_current - queue->m_manager->m_allocator->m_vertices;
  return visited_vertex_count >= this->m_max_visited_vertex_count;
}
