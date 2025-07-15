void __thiscall vostok::render::renderer::sync_pools(vostok::render::renderer *this)
{
  int ***p_m_vertices_pool; // esi
  vostok::render::hw_buffer_pool *m_vertices_pool; // ecx
  vostok::render::hw_buffer_pool *v3; // ecx
  int ***p_m_indices_pool; // esi
  vostok::render::hw_buffer_pool *m_indices_pool; // ecx
  vostok::render::hw_buffer_pool *v6; // ecx

  p_m_vertices_pool = (int ***)&vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_vertices_pool;
  m_vertices_pool = vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_vertices_pool;
  if ( m_vertices_pool && vostok::render::hw_buffer_pool::changed(m_vertices_pool) )
    vostok::render::hw_buffer_pool::sync(v3, *p_m_vertices_pool);
  p_m_indices_pool = (int ***)&vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_indices_pool;
  m_indices_pool = vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_indices_pool;
  if ( m_indices_pool )
  {
    if ( vostok::render::hw_buffer_pool::changed(m_indices_pool) )
      vostok::render::hw_buffer_pool::sync(v6, *p_m_indices_pool);
  }
}
