void __userpurge vostok::render::backend::render_indexed(
        vostok::render::backend *this@<ecx>,
        unsigned int index_count@<eax>,
        D3D_PRIMITIVE_TOPOLOGY type,
        unsigned int start_index,
        unsigned int base_vertex)
{
  bool v7; // al

  v7 = type != this->m_primitive_topology;
  this->m_dirty_objects.primitive_topology = v7;
  if ( v7 )
    this->m_primitive_topology = type;
  vostok::render::backend::flush(this, (int)this);
  if ( this->draw_calls_counting )
  {
    ++this->num_draw_calls;
    index_count += 3 * s_max_triagles_per_dip_value < index_count ? 3 * s_max_triagles_per_dip_value - index_count : 0;
  }
  if ( !this->disable_DrawIndexed )
    (*(void (__stdcall **)(int, unsigned int, unsigned int, unsigned int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                         + 48))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      index_count,
      start_index,
      base_vertex);
  switch ( type )
  {
    case D3D_PRIMITIVE_TOPOLOGY_POINTLIST:
      this->num_total_rendered_points += index_count;
      break;
    case D3D_PRIMITIVE_TOPOLOGY_LINELIST:
      this->num_total_rendered_triangles += index_count >> 1;
      break;
    case D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST:
      this->num_total_rendered_triangles += index_count / 3;
      break;
  }
}
