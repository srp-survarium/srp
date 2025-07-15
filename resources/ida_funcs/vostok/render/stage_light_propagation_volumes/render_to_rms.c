// local variable allocation has failed, the output may be wrong!
void __thiscall vostok::render::stage_light_propagation_volumes::render_to_rms(
        vostok::render::stage_light_propagation_volumes *this,
        vostok::render::stage_light_propagation_volumes *light_color,
        const vostok::math::float3 *light_intensity,
        vostok::render::render_surface_instance **view_matrix,
        vostok::render::renderer_context *projection_matrix,
        vostok::render::vector<vostok::math::float4x4> transforms,
        const unsigned int cascade_index,
        unsigned int cascade_indexa)
{
  vostok::math::float4x4 *v8; // eax
  bool v9; // zf
  int y; // eax
  double m_rsm_source_size; // st7
  float v12; // eax
  void *v13; // edi
  vostok::render::renderer_context *v14; // ecx
  vostok::render::renderer_context *v15; // ecx
  float v16; // eax
  void *v17; // edi
  float v18; // ecx
  const char *m_conflicted_key_name; // ebx
  const vostok::render::render_target *v20; // esi
  const vostok::render::render_target *v21; // edx
  vostok::render::backend *v22; // ecx
  vostok::render::render_target *m_object; // eax
  ID3D11DepthStencilView *m_zrt; // ecx
  const char *v25; // eax
  int v26; // ecx
  int v27; // ecx
  vostok::math::float4x4 *M_finish; // esi
  vostok::math::float4x4 *M_data; // edi
  float v30; // eax
  unsigned int v31; // ecx
  float v32; // edx
  int v33; // esi
  int *v34; // ecx
  int v35; // edx
  int v36; // ecx
  int v37; // ecx
  int v38; // ecx
  int v39; // ecx
  vostok::render::scene *m_scene; // ebx
  int p_m_lpv_geometry; // ebx
  __int64 v42; // xmm0_8
  float z; // edx
  float x; // ecx
  void (__cdecl *v45)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v46)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  const char *v47; // esi
  int v48; // eax
  survarium::game *m_game; // edx
  float v50; // esi
  float v51; // ebp
  vostok::render::renderer_context *v52; // ecx
  vostok::render::grass_render_model *v53; // ecx
  float v54; // eax
  vostok::render::stage_light_propagation_volumes *t; // eax
  vostok::render::render_surface_instance **v56; // edx
  vostok::render::render_surface_instance *v57; // ebx
  vostok::render::render_surface *m_render_surface; // edi
  vostok::render::material_effects_instance *v59; // eax
  vostok::render::material_effects *p_m_material_effects; // eax
  _DWORD *v61; // eax
  const char *v62; // esi
  float v63; // eax
  int v64; // ecx
  __int16 v65; // dx
  unsigned int primitive_count; // eax
  const char *v67; // edi
  unsigned int v68; // ebx
  const char *v69; // esi
  vostok::render::statistics *v70; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::stage_light_propagation_volumes,vostok::math::float3 const &,float,vostok::render::geometry_batch const &>,boost::_bi::list4<boost::_bi::value<vostok::render::stage_light_propagation_volumes *>,boost::_bi::value<vostok::math::float3>,boost::_bi::value<float>,boost::arg<1> > > v72; // [esp+8h] [ebp-E8h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::base_network_client,char const *>,boost::_bi::list2<boost::_bi::value<survarium::base_network_client *>,boost::arg<1> > > g; // [esp+1Ch] [ebp-D4h]
  float v74; // [esp+28h] [ebp-C8h]
  vostok::render::render_surface_instance **it_d; // [esp+3Ch] [ebp-B4h] BYREF
  boost::_bi::storage2<boost::_bi::value<vostok::render::stage_light_propagation_volumes *>,boost::_bi::value<vostok::math::float3> > visible_render_models; // [esp+40h] [ebp-B0h] OVERLAPPED BYREF
  vostok::render::render_surface_instance *const *end_d; // [esp+58h] [ebp-98h]
  vostok::render::shader_constant_buffer *v78; // [esp+5Ch] [ebp-94h]
  D3D11_VIEWPORT tmp_viewport; // [esp+60h] [ebp-90h] BYREF
  boost::function<void __cdecl(vostok::render::geometry_batch const &)> post_render_predicate; // [esp+78h] [ebp-78h] BYREF
  boost::function<void __cdecl(vostok::render::geometry_batch const &)> pre_render_predicate; // [esp+98h] [ebp-58h] BYREF
  void (__thiscall *v82)(vostok::render::stage_light_propagation_volumes *, const vostok::math::float3 *, float, const vostok::render::geometry_batch *); // [esp+B8h] [ebp-38h]
  int v83; // [esp+BCh] [ebp-34h]
  __int64 v84; // [esp+D0h] [ebp-20h]
  D3D11_VIEWPORT orig_viewport; // [esp+D8h] [ebp-18h] BYREF

  if ( s_draw_to_rsm_value )
  {
    y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
    it_d = (vostok::render::render_surface_instance **)1;
    (*(void (__stdcall **)(int, vostok::render::render_surface_instance ***, D3D11_VIEWPORT *))(*(_DWORD *)y + 380))(
      y,
      &it_d,
      &orig_viewport);
    m_rsm_source_size = (double)light_color->m_rsm_source_size;
    tmp_viewport.TopLeftX = 0.0;
    tmp_viewport.TopLeftY = 0.0;
    tmp_viewport.Width = m_rsm_source_size;
    tmp_viewport.MinDepth = 0.0;
    tmp_viewport.Height = m_rsm_source_size;
    LODWORD(tmp_viewport.MaxDepth) = clear_value;
    (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                      + 176))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      1,
      &tmp_viewport);
    v12 = *(float *)&light_color->m_context;
    v13 = *(void **)(LODWORD(v12) + 13432);
    if ( v13 )
      qmemcpy(v13, (const void *)(LODWORD(v12) + 15620), 0x40u);
    v14 = projection_matrix;
    *(_DWORD *)(LODWORD(v12) + 13432) += 64;
    vostok::render::renderer_context::set_v(v14, (const vostok::math::float4x4 *)LODWORD(v12));
    v16 = *(float *)&light_color->m_context;
    v17 = *(void **)(LODWORD(v16) + 14464);
    if ( v17 )
    {
      qmemcpy(v17, (const void *)(LODWORD(v16) + 15940), 0x40u);
      v15 = 0;
    }
    *(_DWORD *)(LODWORD(v16) + 14464) += 64;
    vostok::render::renderer_context::set_p(v15, (const vostok::math::float4x4 *)LODWORD(v16));
    v18 = *(float *)&light_color->m_radiance_volume;
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v20 = *(const vostok::render::render_target **)(476 * cascade_indexa + LODWORD(v18) + 16);
    v21 = *(const vostok::render::render_target **)(476 * cascade_indexa + LODWORD(v18) + 8);
    it_d = (vostok::render::render_surface_instance **)(476 * cascade_indexa);
    vostok::render::backend::set_render_targets(
      *(ID3D11RenderTargetView **)(LODWORD(v18) + 476 * cascade_indexa),
      v21,
      v20,
      0,
      (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
    vostok::render::backend::clear_render_targets(v22, (int)m_conflicted_key_name, 0.0, 0.0, 0.0, 0.0, v74);
    m_object = light_color->m_rms_depth_stencil_source[cascade_indexa].m_object;
    if ( m_object )
      m_zrt = m_object->m_zrt;
    else
      m_zrt = 0;
    v25 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v9 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) == (_DWORD)m_zrt;
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) = m_zrt;
    *((_BYTE *)v25 + 167) |= !v9;
    if ( s_debug_enabled_ds_clearing_value && m_zrt )
    {
      (*(void (__stdcall **)(int, ID3D11DepthStencilView *, int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                                + 212))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        m_zrt,
        3,
        1.0,
        0);
      v25 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
    v26 = *(int *)((char *)it_d + (unsigned int)light_color->m_radiance_volume + 16);
    if ( v26 )
      v27 = *(_DWORD *)(v26 + 16);
    else
      v27 = 0;
    if ( *((_DWORD *)v25 + 535) != v27 )
    {
      *((_DWORD *)v25 + 535) = v27;
      *((_BYTE *)v25 + 163) = 1;
    }
    if ( *((_DWORD *)v25 + 536) )
    {
      *((_DWORD *)v25 + 536) = 0;
      *((_BYTE *)v25 + 164) = 1;
    }
    if ( *((_DWORD *)v25 + 537) )
    {
      *((_DWORD *)v25 + 537) = 0;
      *((_BYTE *)v25 + 165) = 1;
    }
    if ( *((_DWORD *)v25 + 538) )
    {
      *((_DWORD *)v25 + 538) = 0;
      *((_BYTE *)v25 + 166) = 1;
    }
    M_finish = transforms._M_impl._M_finish;
    M_data = transforms._M_impl._M_end_of_storage._M_data;
    if ( transforms._M_impl._M_finish != transforms._M_impl._M_end_of_storage._M_data )
    {
      do
      {
        vostok::render::renderer_context::set_w(light_color->m_context, M_finish);
        v30 = *(float *)&light_color->m_fill_rsm_effect[0].m_object;
        v31 = (*(_DWORD *)(LODWORD(v30) + 284) - *(_DWORD *)(LODWORD(v30) + 280)) >> 2;
        if ( v31 > 1 )
        {
          *(_DWORD *)(LODWORD(v30) + 276) = 1;
          vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v31, *((unsigned int *)&g.l_ + 1));
        }
        vostok::render::box_geometry::draw((vostok::render::box_geometry *)v31);
        ++M_finish;
      }
      while ( M_finish != M_data );
      v25 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
    v32 = *(float *)&light_color->m_radiance_volume;
    v33 = *(int *)((char *)it_d + LODWORD(v32) + 16);
    v34 = (int *)((char *)it_d + LODWORD(v32));
    v35 = *(int *)((char *)it_d + LODWORD(v32) + 8);
    v36 = *v34;
    if ( v36 )
      v37 = *(_DWORD *)(v36 + 16);
    else
      v37 = 0;
    if ( *((_DWORD *)v25 + 535) != v37 )
    {
      *((_DWORD *)v25 + 535) = v37;
      *((_BYTE *)v25 + 163) = 1;
    }
    if ( v35 )
      v38 = *(_DWORD *)(v35 + 16);
    else
      v38 = 0;
    if ( *((_DWORD *)v25 + 536) != v38 )
    {
      *((_DWORD *)v25 + 536) = v38;
      *((_BYTE *)v25 + 164) = 1;
    }
    if ( v33 )
      v39 = *(_DWORD *)(v33 + 16);
    else
      v39 = 0;
    if ( *((_DWORD *)v25 + 537) != v39 )
    {
      *((_DWORD *)v25 + 537) = v39;
      *((_BYTE *)v25 + 165) = 1;
    }
    if ( *((_DWORD *)v25 + 538) )
    {
      *((_DWORD *)v25 + 538) = 0;
      *((_BYTE *)v25 + 166) = 1;
    }
    if ( s_use_batched_lpv_geometry )
    {
      m_scene = light_color->m_context->m_scene;
      visible_render_models.a1_.t_ = (vostok::render::stage_light_propagation_volumes *)vostok::render::stage_light_propagation_volumes::post_lpv_batch_render;
      visible_render_models.a2_.t_.x = 0.0;
      LODWORD(g.f_.f_) = 0;
      LODWORD(visible_render_models.a2_.t_.y) = light_color;
      p_m_lpv_geometry = (int)&m_scene->m_lpv_geometry;
      post_render_predicate.vtable = 0;
      *(void (__thiscall *__ptr64 *)(survarium::base_network_client *, const char *))((char *)&g.f_.f_ + 4) = *(void (__thiscall *__ptr64 *)(survarium::base_network_client *, const char *))&visible_render_models.a2_.t_.elements[1];
      if ( boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::player_cook,vostok::resources::queries_result &,survarium::player_creation_params *>,boost::_bi::list3<boost::_bi::value<survarium::player_cook *>,boost::arg<1>,boost::_bi::value<survarium::player_creation_params *>>>>(
             &post_render_predicate.functor,
             (boost::detail::function::basic_vtable1<void,char const *> *)vostok::render::stage_light_propagation_volumes::post_lpv_batch_render,
             g) )
      {
        post_render_predicate.vtable = (boost::detail::function::vtable_base *)((char *)&stru_964DF4.m_desc_3d.BindFlags
                                                                              + 1);
      }
      else
      {
        post_render_predicate.vtable = 0;
      }
      it_d = view_matrix;
      v42 = *(_QWORD *)&light_intensity->x;
      z = light_intensity->z;
      v82 = vostok::render::stage_light_propagation_volumes::pre_lpv_batch_render;
      *(_QWORD *)&visible_render_models.a2_.t_.x = v42;
      visible_render_models.a2_.t_.z = z;
      v83 = 0;
      v72.f_.f_ = (void (__thiscall *__ptr64)(vostok::render::stage_light_propagation_volumes *, const vostok::math::float3 *, float, const vostok::render::geometry_batch *))(unsigned int)vostok::render::stage_light_propagation_volumes::pre_lpv_batch_render;
      visible_render_models.a1_.t_ = light_color;
      v72.l_.boost::_bi::storage2<boost::_bi::value<vostok::render::stage_light_propagation_volumes *>,boost::_bi::value<vostok::math::float3> > = visible_render_models;
      LODWORD(v84) = view_matrix;
      pre_render_predicate.vtable = 0;
      *(_QWORD *)&v72.l_.a3_.t_ = v84;
      boost::function1<void,vostok::render::geometry_batch const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::stage_light_propagation_volumes,vostok::math::float3 const &,float,vostok::render::geometry_batch const &>,boost::_bi::list4<boost::_bi::value<vostok::render::stage_light_propagation_volumes *>,boost::_bi::value<vostok::math::float3>,boost::_bi::value<float>,boost::arg<1>>>>(
        0,
        (int)&pre_render_predicate,
        (boost::detail::function::function_obj_tag)&post_render_predicate.functor,
        v72);
      vostok::render::batched_geometry<vostok::render::lpv_vertex>::for_each_batch_render(
        (vostok::render::batched_geometry<vostok::render::lpv_vertex> *)&pre_render_predicate,
        p_m_lpv_geometry,
        light_color->m_context,
        &pre_render_predicate,
        &post_render_predicate);
      if ( pre_render_predicate.vtable )
      {
        if ( ((int)pre_render_predicate.vtable & 1) == 0 )
        {
          v45 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)pre_render_predicate.vtable & 0xFFFFFFFE);
          if ( v45 )
            v45(&pre_render_predicate.functor, &pre_render_predicate.functor, 2);
        }
        pre_render_predicate.vtable = 0;
      }
      if ( post_render_predicate.vtable )
      {
        if ( ((int)post_render_predicate.vtable & 1) == 0 )
        {
          v46 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)post_render_predicate.vtable & 0xFFFFFFFE);
          if ( v46 )
            v46(&post_render_predicate.functor, &post_render_predicate.functor, 2);
        }
        post_render_predicate.vtable = 0;
      }
    }
    else
    {
      v54 = *(float *)&light_color->m_context;
      *(_QWORD *)&visible_render_models.a1_.t_ = 0;
      visible_render_models.a2_.t_.y = 0.0;
      vostok::render::scene::select_models(
        *(vostok::render::scene **)(LODWORD(v54) + 12388),
        (const vostok::math::float4x4 *)(LODWORD(v54) + 16260),
        (vostok::render::vector<vostok::render::render_surface_instance *> *)&visible_render_models,
        (const vostok::math::float3 *)(LODWORD(v54) + 16900),
        1u,
        0);
      x = visible_render_models.a2_.t_.x;
      t = visible_render_models.a1_.t_;
      __SET_PAIR__((unsigned int)end_d, (unsigned int)v56, *(_QWORD *)&visible_render_models.a1_.t_);
      it_d = (vostok::render::render_surface_instance **)visible_render_models.a1_.t_;
      if ( visible_render_models.a1_.t_ != (vostok::render::stage_light_propagation_volumes *)LODWORD(visible_render_models.a2_.t_.x) )
      {
        do
        {
          v57 = *v56;
          m_render_surface = (*v56)->m_render_surface;
          v59 = m_render_surface->m_materail_effects_instance.m_object;
          if ( !v59 || s_use_one_material_value )
          {
            x = *(float *)&m_render_surface->m_vertex_input_type;
            p_m_material_effects = s_nomaterial_material_effects[LODWORD(x)];
          }
          else
          {
            p_m_material_effects = &v59->m_material_effects;
          }
          if ( m_render_surface->m_vertex_input_type == static_mesh_vertex_input_type )
          {
            v61 = &p_m_material_effects->m_effects[0].m_object->__vftable;
            if ( v61 )
            {
              if ( m_render_surface->m_render_geometry.lpv_pass_geom.m_object )
              {
                if ( (unsigned int)((v61[71] - v61[70]) >> 2) > 4 )
                {
                  v61[69] = 4;
                  vostok::render::res_effect::apply_pass(
                    (vostok::render::res_effect *)LODWORD(x),
                    *((unsigned int *)&g.l_ + 1));
                }
                v62 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
                vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                  light_color->m_c_light_color,
                  (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                + 123,
                  light_intensity);
                ++*((_DWORD *)v62 + 23);
                v63 = *(float *)&light_color->m_c_light_intensity;
                if ( *(_DWORD *)(LODWORD(v63) + 40) == *((_DWORD *)v62 + 573) )
                {
                  v64 = *(unsigned __int16 *)(LODWORD(v63) + 20);
                  if ( v64 != 0xFFFF )
                  {
                    v65 = *(_WORD *)(LODWORD(v63) + 16);
                    v78 = *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v62 + 371) + 16) + 4 * v64);
                    vostok::render::shader_constant_buffer::set_memory(
                      *(unsigned __int16 *)(LODWORD(v63) + 22),
                      (unsigned __int8)v65,
                      v78,
                      (const char *)&view_matrix);
                  }
                }
                ++*((_DWORD *)v62 + 23);
                vostok::render::renderer_context::set_w(light_color->m_context, v57->m_transform);
                v57->m_parent->set_constants(v57->m_parent);
                vostok::render::res_geometry::apply(m_render_surface->m_render_geometry.lpv_pass_geom.m_object);
                primitive_count = m_render_surface->m_render_geometry.primitive_count;
                v67 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
                v68 = 3 * primitive_count;
                LOBYTE(primitive_count) = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                          + 529) != 4;
                v69 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
                *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = primitive_count;
                if ( (_BYTE)primitive_count )
                  *((_DWORD *)v67 + 529) = 4;
                vostok::render::backend::flush((vostok::render::backend *)4, (int)v67);
                if ( v69[104] )
                {
                  ++*((_DWORD *)v69 + 25);
                  LODWORD(x) = 3 * s_max_triagles_per_dip_value < v68 ? 3 * s_max_triagles_per_dip_value - v68 : 0;
                  v68 += LODWORD(x);
                }
                if ( !v69[37] )
                  (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                           + 48))(
                    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
                    v68,
                    0,
                    0);
                v70 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
                *((_DWORD *)v69 + 21) += v68 / 3;
                ++v70->debug_stat_group.num_dips_in_lpv.value;
                v56 = it_d;
              }
            }
          }
          it_d = ++v56;
        }
        while ( v56 != end_d );
        t = visible_render_models.a1_.t_;
      }
      if ( t )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, t);
      }
    }
    v47 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    vostok::render::backend::reset_render_targets(
      (vostok::render::backend *)LODWORD(x),
      (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
    v48 = *((_DWORD *)v47 + 547);
    m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
    *((_BYTE *)v47 + 167) |= *((_DWORD *)v47 + 539) != v48;
    *((_DWORD *)v47 + 539) = v48;
    (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.y + 176))(
      m_game->m_game_world.m_mouse_pos.y,
      1,
      &orig_viewport);
    v50 = *(float *)&light_color->m_context;
    vostok::render::renderer_context::set_v(
      (vostok::render::renderer_context *)(*(_DWORD *)(LODWORD(v50) + 13432) - 64),
      (const vostok::math::float4x4 *)LODWORD(v50));
    *(_DWORD *)(LODWORD(v50) + 13432) -= 64;
    v51 = *(float *)&light_color->m_context;
    vostok::render::renderer_context::set_p(v52, (const vostok::math::float4x4 *)LODWORD(v51));
    *(_DWORD *)(LODWORD(v51) + 14464) -= 64;
    v8 = transforms._M_impl._M_finish;
    v9 = transforms._M_impl._M_finish == 0;
  }
  else
  {
    v8 = transforms._M_impl._M_finish;
    v9 = transforms._M_impl._M_finish == 0;
  }
  if ( !v9 )
  {
    v53 = vostok::render::g_allocator.m_object;
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free((void *)HIDWORD(v53->m_reconstruction_info_actuality_tick), (void *)v8);
  }
}
