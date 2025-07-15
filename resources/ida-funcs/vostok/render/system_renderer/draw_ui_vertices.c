void __thiscall vostok::render::system_renderer::draw_ui_vertices(
        vostok::render::system_renderer *this,
        vostok::render::vertex_formats::TL *vertices,
        unsigned __int8 *count,
        unsigned int *prim_type,
        int point_type,
        int a6)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  bool v7; // al
  unsigned __int8 *v8; // eax
  vostok::render::vertex_buffer *v9; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // ecx
  bool has_passed_filters; // al
  int v12; // ecx
  int y_low; // eax
  vostok::render::backend *v14; // ecx
  vostok::render::backend *v15; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v16; // [esp-4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v17; // [esp-4h] [ebp-3Ch]
  char v18; // [esp+10h] [ebp-28h]
  unsigned int v_offset; // [esp+14h] [ebp-24h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v20; // [esp+18h] [ebp-20h] BYREF

  v18 = 0;
  if ( vostok::render::system_renderer::is_effects_ready(this, vertices) )
  {
    v8 = (unsigned __int8 *)vostok::render::vertex_buffer::lock(
                              (vostok::render::vertex_buffer *)&vertices[4].p.elements[1],
                              &v_offset,
                              *prim_type,
                              0x1Cu);
    memcpy(v8, count, 28 * *prim_type);
    vostok::render::vertex_buffer::unlock(v9, (int *)&vertices[4].p.y);
    if ( s_test_ui )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"render_pc_dx11",
                                   (const char *)2),
            v10 = v17,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v20);
        v18 = 2;
        vostok::logging::append(
          &v20,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\system_renderer.cpp",
          0x2DEu,
          "void __thiscall vostok::render::system_renderer::draw_ui_vertices(const struct vostok::render::vertex_formats:"
          ":TL *,const unsigned int &,int,int)",
          "render_pc_dx11",
          error,
          "test ui: point type: %d, prim_type: %d, count: %d, offset: %d",
          a6,
          point_type,
          *prim_type,
          v_offset);
      }
      if ( (v18 & 2) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
          (int *)&v20);
    }
    vostok::render::res_geometry::apply((vostok::render::res_geometry *)v10, LODWORD(vertices[10].uv.x));
    y_low = LODWORD(vertices[7].uv.y);
    if ( point_type )
    {
      *(_DWORD *)(y_low + 22048) = 3;
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v12, y_low);
      vostok::render::backend::render(
        (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        D3D_PRIMITIVE_TOPOLOGY_LINESTRIP,
        v15,
        *prim_type,
        v_offset);
    }
    else
    {
      if ( a6 )
      {
        v12 = 1;
        if ( a6 == 1 )
          *(_DWORD *)(y_low + 22048) = 1;
        else
          *(_DWORD *)(y_low + 22048) = 2;
      }
      else
      {
        *(_DWORD *)(y_low + 22048) = 0;
      }
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v12, y_low);
      vostok::render::backend::render_indexed(
        (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        (3 * *prim_type) >> 1,
        v14,
        D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
        0,
        v_offset);
    }
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (v7 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"render_pc_dx11", (const char *)2),
          v6 = v16,
          v7) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v6,
        &v20);
      v18 = 1;
      vostok::logging::append(
        &v20,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\system_renderer.cpp",
        0x2CEu,
        "void __thiscall vostok::render::system_renderer::draw_ui_vertices(const struct vostok::render::vertex_formats::T"
        "L *,const unsigned int &,int,int)",
        "render_pc_dx11",
        error,
        "draw_ui_vertices: effects not ready");
    }
    if ( (v18 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v6,
        (int *)&v20);
  }
}
