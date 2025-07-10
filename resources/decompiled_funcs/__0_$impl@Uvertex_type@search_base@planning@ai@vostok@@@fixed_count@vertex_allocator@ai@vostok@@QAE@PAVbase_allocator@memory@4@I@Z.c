void __thiscall vostok::ai::vertex_allocator::fixed_count::impl<vostok::ai::planning::search_base::vertex_type>::impl<vostok::ai::planning::search_base::vertex_type>(
        vostok::ai::vertex_allocator::fixed_count::impl<vostok::ai::planning::search_base::vertex_type> *this,
        vostok::memory::base_allocator *memory_allocator,
        unsigned int max_vertex_count)
{
  survarium::game_camera *v3; // ecx
  vostok::memory::base_allocator *v4; // eax
  _DWORD *v6; // [esp+18h] [ebp-Ch]
  vostok::ai::planning::search_base::vertex_type *iter; // [esp+20h] [ebp-4h]

  this->m_allocator = memory_allocator;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)memory_allocator);
  survarium::weapon_user_dead_state::finalize(v3);
  this->m_vertices = (vostok::ai::planning::search_base::vertex_type *)vostok::memory::malloc_helper<vostok::memory::base_allocator>(
                                                                         v4,
                                                                         40 * max_vertex_count);
  this->m_vertices_end = &this->m_vertices[max_vertex_count];
  for ( iter = this->m_vertices; iter != this->m_vertices_end; ++iter )
  {
    v6 = operator new(0x28u, iter);
    if ( v6 )
    {
      v6[4] = 0;
      v6[5] = 0;
      v6[6] = 0;
      v6[7] = 0;
    }
  }
}
