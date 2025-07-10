void __userpurge vostok::render::system_renderer::draw_screen_lines(
        vostok::render::system_renderer *this@<ecx>,
        vostok::render::system_renderer *points,
        const vostok::math::float3 *count,
        unsigned int color,
        const vostok::math::color *width,
        bool pattern,
        bool use_depth,
        bool is_screen_space_coord)
{
  vostok::math::float4x4 *v8; // eax
  char v9; // cl
  unsigned int v10; // edx
  unsigned __int16 *v11; // ebx
  float v12; // xmm0_4
  vostok::render::vertex_colored_sl *v13; // ecx
  __int64 v15; // xmm1_8
  float z; // edx
  vostok::render::vertex_colored_sl *v17; // esi
  float v18; // xmm0_4
  double v19; // st7
  float v20; // eax
  _WORD *v21; // ebx
  vostok::render::res_effect *v22; // ecx
  float v23; // eax
  const char *v24; // eax
  float v25; // ecx
  const char *m_conflicted_key_name; // edi
  int v27; // edx
  unsigned int v28; // ebx
  bool v29; // al
  unsigned int v30; // [esp+0h] [ebp-118h]
  float shift; // [esp+Ch] [ebp-10Ch]
  unsigned int screen_width; // [esp+14h] [ebp-104h]
  unsigned int vertex_count; // [esp+18h] [ebp-100h]
  unsigned int screen_height; // [esp+1Ch] [ebp-FCh]
  unsigned int u32_color; // [esp+20h] [ebp-F8h]
  unsigned int i; // [esp+24h] [ebp-F4h]
  unsigned int voffset; // [esp+30h] [ebp-E8h] BYREF
  unsigned int ioffset; // [esp+34h] [ebp-E4h] BYREF
  vostok::render::vertex_colored_sl *vbuffer; // [esp+38h] [ebp-E0h]
  vostok::math::float3 current_point; // [esp+3Ch] [ebp-DCh] BYREF
  vostok::math::float2 screen_start; // [esp+48h] [ebp-D0h] BYREF
  vostok::math::float2 screen_end; // [esp+50h] [ebp-C8h] BYREF
  vostok::math::float4x4 wvpMatrix; // [esp+58h] [ebp-C0h] BYREF
  vostok::math::float4x4 result; // [esp+98h] [ebp-80h] BYREF
  vostok::math::float4x4 v45; // [esp+D8h] [ebp-40h] BYREF

  if ( vostok::render::system_renderer::is_effects_ready(this, points) )
  {
    if ( pattern )
      v8 = vostok::math::float4x4::identity(&v45);
    else
      v8 = vostok::math::mul4x4(&points->m_renderer_context->m_v, &points->m_renderer_context->m_p);
    qmemcpy((void *)&wvpMatrix, v8, sizeof(wvpMatrix));
    v9 = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 105);
    if ( v9 )
      v10 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 27);
    else
      v10 = *(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                        + 540)
                      + 144);
    screen_width = v10;
    if ( v9 )
      screen_height = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                      + 28);
    else
      screen_height = *(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                  + 540)
                                + 148);
    u32_color = width->m_value;
    vertex_count = 2 * color - 2;
    v11 = vostok::render::index_buffer::lock(&points->m_index_stream, vertex_count, &ioffset);
    v12 = 0.0;
    v13 = (vostok::render::vertex_colored_sl *)vostok::render::vertex_buffer::lock(
                                                 &points->m_vertex_stream,
                                                 vertex_count,
                                                 0x24u,
                                                 &voffset);
    shift = 0.0;
    i = 1;
    if ( color > 1 )
    {
      while ( 1 )
      {
        v15 = *(_QWORD *)&count[1].x;
        z = count[1].z;
        v17 = v13 + 1;
        vbuffer = v13 + 2;
        *(_QWORD *)&current_point.x = v15;
        *(_QWORD *)&v13->position.x = *(_QWORD *)&count->x;
        v13->position.z = count->z;
        current_point.z = z;
        v13->color = u32_color;
        *(_QWORD *)&v13->begin_line_position.x = *(_QWORD *)&count->x;
        v13->begin_line_position.z = count->z;
        v13[1].shift = v12;
        v13->shift = v12;
        v13[1].pattern = -1;
        v13->pattern = -1;
        vostok::render::clip_2_screen(&wvpMatrix, count, &screen_start, screen_width, screen_height);
        vostok::render::clip_2_screen(&wvpMatrix, &current_point, &screen_end, screen_width, screen_height);
        LODWORD(v18) = COERCE_UNSIGNED_INT(screen_end.y - screen_start.y) & _mask__AbsFloat_;
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(screen_end.x - screen_start.x) & _mask__AbsFloat_) > v18 )
          LODWORD(v18) = COERCE_UNSIGNED_INT(screen_end.x - screen_start.x) & _mask__AbsFloat_;
        v19 = (double)(unsigned __int8)(int)(float)((float)((float)(v18 * 0.125) - (float)(int)(float)(v18 * 0.125))
                                                  * 8.0)
            + shift;
        shift = v19;
        v12 = shift;
        if ( (unsigned int)(__int64)v19 >= 8 )
        {
          v12 = shift - 8.0;
          shift = shift - 8.0;
        }
        v20 = current_point.z;
        *(_QWORD *)&v17->position.x = *(_QWORD *)&current_point.x;
        v17->position.z = v20;
        v17->color = u32_color;
        *(_QWORD *)&v17->begin_line_position.x = *(_QWORD *)&count->x;
        v17->begin_line_position.z = count->z;
        *v11 = 2 * i - 2;
        v21 = v11 + 1;
        *v21 = 2 * i - 1;
        v11 = v21 + 1;
        ++count;
        if ( ++i >= color )
          break;
        v13 = vbuffer;
      }
    }
    points->m_vertex_stream.m_position += points->m_vertex_stream.m_lock_count * points->m_vertex_stream.m_lock_stride;
    (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                       + 60))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      points->m_vertex_stream.m_buffer.m_object->m_hardware_buffer,
      0);
    points->m_index_stream.m_position += points->m_index_stream.m_lock_size;
    (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                       + 60))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      points->m_index_stream.m_buffer.m_object->m_hardware_buffer,
      0);
    vostok::render::res_geometry::apply(points->m_colored_geom_sl.m_object);
    v23 = *(float *)&points->m_sh_sl.m_object;
    if ( (unsigned int)((*(_DWORD *)(LODWORD(v23) + 284) - *(_DWORD *)(LODWORD(v23) + 280)) >> 2) > 1 )
    {
      *(_DWORD *)(LODWORD(v23) + 276) = 1;
      vostok::render::res_effect::apply_pass(v22, v30);
    }
    v24 = (const char *)vostok::math::transpose(&result, &wvpMatrix);
    v25 = *(float *)&points->m_WVP_sl;
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *(_DWORD *)(LODWORD(v25) + 36) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                           + 572) )
    {
      v27 = *(unsigned __int16 *)(LODWORD(v25) + 12);
      if ( v27 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          *(unsigned __int16 *)(LODWORD(v25) + 14),
          (unsigned __int8)*(_WORD *)(LODWORD(v25) + 8),
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                   + 51)
                                                                 + 16)
                                                     + 4 * v27),
          v24);
    }
    ++*((_DWORD *)m_conflicted_key_name + 23);
    v28 = 2 * color - 2;
    v29 = *((_DWORD *)m_conflicted_key_name + 529) != 2;
    *((_BYTE *)m_conflicted_key_name + 162) = v29;
    if ( v29 )
      *((_DWORD *)m_conflicted_key_name + 529) = 2;
    vostok::render::backend::flush((vostok::render::backend *)2, (int)m_conflicted_key_name);
    if ( m_conflicted_key_name[104] )
    {
      ++*((_DWORD *)m_conflicted_key_name + 25);
      v28 = vertex_count
          + (3 * s_max_triagles_per_dip_value < vertex_count ? 3 * s_max_triagles_per_dip_value - vertex_count : 0);
    }
    if ( !m_conflicted_key_name[37] )
      (*(void (__stdcall **)(int, unsigned int, unsigned int, unsigned int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                           + 48))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        v28,
        ioffset,
        voffset);
    *((_DWORD *)m_conflicted_key_name + 21) += v28 >> 1;
  }
}
