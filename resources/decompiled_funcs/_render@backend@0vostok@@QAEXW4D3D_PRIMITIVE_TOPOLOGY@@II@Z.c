void __userpurge vostok::render::backend::render(
        vostok::render::backend *this@<eax>,
        D3D_PRIMITIVE_TOPOLOGY type@<esi>,
        vostok::render::backend *a3@<ecx>,
        unsigned int vertex_count,
        unsigned int base_vertex)
{
  bool v6; // al

  v6 = type != this->m_primitive_topology;
  this->m_dirty_objects.primitive_topology = v6;
  if ( v6 )
    this->m_primitive_topology = type;
  vostok::render::backend::flush(a3, (int)this);
  if ( this->draw_calls_counting )
    ++this->num_draw_calls;
  (*(void (__stdcall **)(int, unsigned int, unsigned int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                         + 52))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    vertex_count,
    base_vertex);
  switch ( type )
  {
    case D3D_PRIMITIVE_TOPOLOGY_POINTLIST:
      this->num_total_rendered_points += vertex_count;
      break;
    case D3D_PRIMITIVE_TOPOLOGY_LINELIST:
      this->num_total_rendered_triangles += vertex_count >> 1;
      break;
    case D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST:
      this->num_total_rendered_triangles += vertex_count / 3;
      break;
  }
}
