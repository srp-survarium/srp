void __userpurge vostok::render::system_renderer::draw_lines(
        const vostok::render::vertex_colored *const vertices_end@<eax>,
        vostok::render::system_renderer *a2@<ecx>,
        vostok::render::system_renderer *this,
        vostok::render::vertex_colored *vertices_begin,
        unsigned __int8 *indices_begin,
        const unsigned __int16 *indices_end,
        bool covering_effect)
{
  const unsigned __int16 *v7; // ebp
  unsigned int v9; // ebx
  unsigned __int8 *v10; // eax
  unsigned int v11; // ebp
  unsigned __int8 *v12; // eax
  unsigned int v13; // ecx
  vostok::render::res_effect *m_object; // eax
  vostok::render::res_effect *v15; // ebx
  unsigned int v16; // [esp-8h] [ebp-18h]
  unsigned int v17; // [esp+0h] [ebp-10h]

  v7 = indices_end;
  if ( vostok::render::system_renderer::is_effects_ready(a2, this) )
  {
    v16 = vertices_end - vertices_begin;
    v9 = 16 * v16;
    v10 = (unsigned __int8 *)vostok::render::vertex_buffer::lock(
                               &this->m_vertex_stream,
                               v16,
                               0x10u,
                               (unsigned int *)&indices_end);
    memcpy(v10, (unsigned __int8 *)vertices_begin, v9);
    this->m_vertex_stream.m_position += this->m_vertex_stream.m_lock_count * this->m_vertex_stream.m_lock_stride;
    (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                       + 60))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      this->m_vertex_stream.m_buffer.m_object->m_hardware_buffer,
      0);
    v11 = ((char *)v7 - (char *)indices_begin) >> 1;
    v12 = (unsigned __int8 *)vostok::render::index_buffer::lock(
                               &this->m_index_stream,
                               v11,
                               (unsigned int *)&vertices_begin);
    memcpy(v12, indices_begin, 2 * v11);
    this->m_index_stream.m_position += this->m_index_stream.m_lock_size;
    (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                       + 60))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      this->m_index_stream.m_buffer.m_object->m_hardware_buffer,
      0);
    vostok::render::res_geometry::apply(this->m_colored_geom.m_object);
    if ( covering_effect )
    {
      m_object = this->m_sh_vcolor.m_object;
      v13 = m_object->m_techniques._M_impl._M_finish - m_object->m_techniques._M_impl._M_start;
      if ( v13 > 3 )
      {
        m_object->m_cur_technique = 3;
LABEL_7:
        vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v13, v17);
      }
    }
    else
    {
      v15 = this->m_sh_vcolor.m_object;
      if ( v15->m_techniques._M_impl._M_finish - v15->m_techniques._M_impl._M_start )
      {
        v15->m_cur_technique = 0;
        goto LABEL_7;
      }
    }
    vostok::render::backend::render_indexed(
      (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
      v11,
      D3D_PRIMITIVE_TOPOLOGY_LINELIST,
      (unsigned int)vertices_begin,
      (unsigned int)indices_end);
  }
}
