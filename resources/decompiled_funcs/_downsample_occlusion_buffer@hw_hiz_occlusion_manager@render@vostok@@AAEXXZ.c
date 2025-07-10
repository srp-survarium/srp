void __thiscall vostok::render::hw_hiz_occlusion_manager::downsample_occlusion_buffer(
        vostok::render::hw_hiz_occlusion_manager *this,
        vostok::render::hw_hiz_occlusion_manager *thisa)
{
  vostok::render::hw_hiz_occlusion_manager *v2; // edi
  unsigned int v3; // ebp
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v4; // esi
  int y; // eax
  vostok::render::render_target *m_object; // eax
  vostok::render::backend *m_rt; // ecx
  const char *m_conflicted_key_name; // eax
  vostok::render::res_texture *v9; // eax
  vostok::render::res_texture *v10; // ebp
  _DWORD *v11; // eax
  unsigned int v12; // ecx
  const char *v13; // esi
  unsigned int Width; // ecx
  double v15; // st7
  const char *v16; // edx
  vostok::render::shader_constant_host *m_prev_texture_size_parameter; // eax
  int v18; // ecx
  unsigned __int16 m_buffer_index; // cx
  int v20; // ebp
  unsigned int m_class_id; // esi
  int m_slot_index; // eax
  float *v23; // edi
  int v24; // ecx
  _BYTE *v25; // esi
  _BYTE *v26; // eax
  char v27; // bl
  char v28; // dl
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > **v29; // esi
  vostok::render::render_target *v30; // eax
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v31; // ecx
  vostok::render::res_texture *v32; // eax
  void **v33; // edi
  const char *m_begin; // edx
  survarium::options_tab *v35; // ebp
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v36; // eax
  stlp_std::priv::_Rb_tree_node_base *v37; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::grass_render_model *v39; // ebp
  char *v40; // esi
  char *v41; // eax
  malloc_state *v42; // esi
  unsigned int v43; // ebx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v44; // esi
  _DWORD *v45; // eax
  const char *v46; // edi
  char v47; // al
  vostok::render::render_target *v48; // eax
  const char *v49; // esi
  int v50; // eax
  bool v51; // zf
  survarium::options_tab *v52; // edi
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v53; // eax
  stlp_std::priv::_Rb_tree_node_base *v54; // eax
  malloc_state *v55; // esi
  vostok::render::grass_render_model *v56; // edi
  char *v57; // esi
  char *v58; // eax
  malloc_state *v59; // esi
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v60; // [esp+Ch] [ebp-94h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v61; // [esp+10h] [ebp-90h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v62; // [esp+14h] [ebp-8Ch]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v63; // [esp+18h] [ebp-88h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v64; // [esp+1Ch] [ebp-84h]
  D3D11_VIEWPORT *v65; // [esp+20h] [ebp-80h]
  float v66; // [esp+24h] [ebp-7Ch]
  float pos_y; // [esp+28h] [ebp-78h]
  float size_x; // [esp+2Ch] [ebp-74h]
  float size_y; // [esp+30h] [ebp-70h]
  float v70; // [esp+34h] [ebp-6Ch]
  float v71; // [esp+38h] [ebp-68h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> read_texture; // [esp+4Ch] [ebp-54h]
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > **v73; // [esp+50h] [ebp-50h]
  unsigned int mip_level_index; // [esp+54h] [ebp-4Ch] BYREF
  const char *v75; // [esp+58h] [ebp-48h] BYREF
  unsigned int Height; // [esp+5Ch] [ebp-44h]
  float v77[4]; // [esp+60h] [ebp-40h] BYREF
  D3D11_VIEWPORT view_port; // [esp+70h] [ebp-30h] BYREF
  D3D11_VIEWPORT prev_view_port; // [esp+88h] [ebp-18h] BYREF

  v2 = thisa;
  v3 = 1;
  if ( thisa->m_num_mips > 1 )
  {
    v4 = &thisa->m_rt_depth_mips[1];
    do
    {
      y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
      mip_level_index = 1;
      (*(void (__stdcall **)(int, unsigned int *, D3D11_VIEWPORT *))(*(_DWORD *)y + 380))(
        y,
        &mip_level_index,
        &prev_view_port);
      m_object = v4->m_object;
      view_port.Width = (float)v4->m_object->m_width;
      view_port.Height = (float)m_object->m_height;
      view_port.MinDepth = 0.0;
      LODWORD(view_port.MaxDepth) = clear_value;
      view_port.TopLeftX = 0.0;
      view_port.TopLeftY = 0.0;
      (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                        + 176))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        1,
        &view_port);
      if ( v4->m_object )
        m_rt = (vostok::render::backend *)v4->m_object->m_rt;
      else
        m_rt = 0;
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *((vostok::render::backend **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
           + 535) != m_rt )
      {
        *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
        *((_BYTE *)m_conflicted_key_name + 163) = 1;
      }
      if ( *((_DWORD *)m_conflicted_key_name + 536) )
      {
        *((_DWORD *)m_conflicted_key_name + 536) = 0;
        *((_BYTE *)m_conflicted_key_name + 164) = 1;
      }
      if ( *((_DWORD *)m_conflicted_key_name + 537) )
      {
        *((_DWORD *)m_conflicted_key_name + 537) = 0;
        *((_BYTE *)m_conflicted_key_name + 165) = 1;
      }
      if ( *((_DWORD *)m_conflicted_key_name + 538) )
      {
        *((_DWORD *)m_conflicted_key_name + 538) = 0;
        *((_BYTE *)m_conflicted_key_name + 166) = 1;
      }
      vostok::render::backend::clear_render_targets(
        m_rt,
        (int)m_conflicted_key_name,
        *(float *)&clear_value,
        1.0,
        1.0,
        1.0,
        v71);
      (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                        + 176))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        1,
        &prev_view_port);
      ++v3;
      ++v4;
    }
    while ( v3 < v2->m_num_mips );
  }
  v9 = v2->m_t_depth_mips.m_object;
  v10 = 0;
  read_texture.m_object = 0;
  if ( v9 )
  {
    ++v9->m_reference_count;
    read_texture.m_object = v9;
    v10 = v9;
  }
  mip_level_index = 1;
  if ( v2->m_num_mips > 1 )
  {
    v77[2] = 0.0;
    v77[3] = 0.0;
    v73 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > **)&v2->m_t_depth_mips_work[1];
    do
    {
      v11 = &v2->m_hiz_occlusion_effect.m_object->__vftable;
      v12 = (v11[71] - v11[70]) >> 2;
      if ( v12 > 4 )
      {
        v11[69] = 4;
        vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v12, (int)v11);
      }
      v13 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)v13 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                (vostok::render::textures_handler<0> *)v12,
                                (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                              + 1488,
                                (vostok::render::res_texture *)&stru_967C04,
                                v10);
      Width = v10->m_desc.Width;
      Height = v10->m_desc.Height;
      v15 = (double)Height;
      Height = Width;
      v16 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v77[0] = (float)Width;
      m_prev_texture_size_parameter = v2->m_prev_texture_size_parameter;
      v18 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 573);
      v77[1] = v15;
      if ( m_prev_texture_size_parameter->m_update_markers[1] == v18 )
      {
        m_buffer_index = m_prev_texture_size_parameter->m_shader_slots[1].m_buffer_index;
        if ( m_buffer_index != 0xFFFF )
        {
          v20 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                        + 371)
                                      + 16)
                          + 4 * m_buffer_index);
          m_class_id = (unsigned __int8)m_prev_texture_size_parameter->m_shader_slots[1].m_class_id;
          m_slot_index = m_prev_texture_size_parameter->m_shader_slots[1].m_slot_index;
          v23 = v77;
          if ( m_class_id > *(_DWORD *)(v20 + 92) - m_slot_index )
            m_class_id = *(_DWORD *)(v20 + 92) - m_slot_index;
          v24 = *(_DWORD *)(v20 + 88);
          v25 = (_BYTE *)(v24 + m_slot_index + m_class_id);
          v26 = (_BYTE *)(v24 + m_slot_index);
          v27 = 0;
          if ( v26 != v25 )
          {
            do
            {
              v28 = *(_BYTE *)v23 ^ *v26;
              *v26++ = *(_BYTE *)v23;
              v27 |= v28;
              v23 = (float *)((char *)v23 + 1);
            }
            while ( v26 != v25 );
            v16 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          }
          *(_BYTE *)(v20 + 100) |= v27 != 0;
          v10 = read_texture.m_object;
        }
      }
      ++*((_DWORD *)v16 + 23);
      v70 = 1.0;
      v29 = v73;
      size_y = 1.0;
      size_x = 0.0;
      pos_y = 0.0;
      v66 = 0.0;
      v65 = 0;
      v64.m_object = 0;
      v63.m_object = 0;
      v62.m_object = 0;
      v61.m_object = 0;
      v30 = (vostok::render::render_target *)*(v73 - 16);
      v60.m_object = 0;
      if ( v30 )
      {
        v60.m_object = v30;
        ++v30->m_reference_count;
      }
      vostok::render::system_renderer::fill_surface(
        (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
        (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        pos_y,
        size_x,
        size_y,
        v70);
      v31 = *v29;
      v32 = 0;
      if ( *v29 )
      {
        v32 = (vostok::render::res_texture *)*v29;
        ++v31->_M_header._M_data._M_parent;
      }
      v33 = (void **)&v10->__vftable;
      read_texture.m_object = v32;
      if ( v10 )
      {
        if ( !--v10->m_reference_count && v10->m_is_registered )
        {
          m_begin = v10->m_name.m_string.m_begin;
          v35 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
          v75 = m_begin;
          v36 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(v31, (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7], &v75);
          if ( v36 != (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v35 )
          {
            v37 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
                    &v36->_M_header._M_data,
                    (stlp_std::priv::_Rb_tree_node_base **)&v35->m_options_count,
                    (stlp_std::priv::_Rb_tree_node_base **)&v35->m_type,
                    (stlp_std::priv::_Rb_tree_node_base **)&v35->m_game);
            if ( v37 )
            {
              m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (char *)&v37->_M_color);
            }
            --v35->m_movie;
            v39 = vostok::render::g_allocator.m_object;
            v40 = __RTCastToVoid(v33);
            (*(void (__thiscall **)(void **, _DWORD))*v33)(v33, 0);
            if ( v40 )
            {
              v41 = v40;
              v42 = (malloc_state *)HIDWORD(v39->m_reconstruction_info_actuality_tick);
              BYTE2(v39->m_children_resources.m_lock) = 0;
              vostok_mspace_free(v42, v41);
            }
          }
        }
      }
      this = thisa;
      ++v73;
      v10 = read_texture.m_object;
      ++mip_level_index;
      v43 = 1;
      v2 = thisa;
    }
    while ( mip_level_index < thisa->m_num_mips );
    if ( thisa->m_num_mips > 1 )
    {
      v44 = &thisa->m_rt_depth_mips[1];
      while ( 1 )
      {
        v45 = &v2->m_hiz_occlusion_effect.m_object->__vftable;
        if ( (unsigned int)((v45[71] - v45[70]) >> 2) > 5 )
        {
          v45[69] = 5;
          vostok::render::res_effect::apply_pass((vostok::render::res_effect *)this, (int)v45);
        }
        v70 = *(float *)&v44[-16].m_object;
        v46 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        v47 = vostok::render::textures_handler<0>::set_overwrite(
                (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                      + 1488),
                (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 1488,
                (vostok::render::res_texture *)&stru_967C04,
                (vostok::render::res_texture *)LODWORD(v70));
        v70 = 1.0;
        size_y = 1.0;
        *((_BYTE *)v46 + 159) = v47;
        size_x = 0.0;
        pos_y = 0.0;
        v66 = 0.0;
        v65 = 0;
        v64.m_object = 0;
        v63.m_object = 0;
        v62.m_object = 0;
        v61.m_object = 0;
        v48 = v44->m_object;
        v60.m_object = 0;
        if ( v48 )
        {
          v60.m_object = v48;
          ++v48->m_reference_count;
        }
        vostok::render::system_renderer::fill_surface(
          (vostok::render::system_renderer *)&v60,
          (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          pos_y,
          size_x,
          size_y,
          v70);
        this = thisa;
        ++v43;
        ++v44;
        if ( v43 >= thisa->m_num_mips )
          break;
        v2 = thisa;
      }
    }
  }
  v49 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  vostok::render::backend::reset_render_targets(
    (vostok::render::backend *)this,
    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  v50 = *((_DWORD *)v49 + 547);
  v51 = *((_DWORD *)v49 + 539) == v50;
  *((_DWORD *)v49 + 539) = v50;
  *((_BYTE *)v49 + 167) |= !v51;
  if ( v10 )
  {
    v51 = v10->m_reference_count-- == 1;
    if ( v51 && v10->m_is_registered )
    {
      v52 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
      thisa = (vostok::render::hw_hiz_occlusion_manager *)v10->m_name.m_string.m_begin;
      v53 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>((stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&thisa, (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7], (const char **)&thisa);
      if ( v53 != (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v52 )
      {
        v54 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
                &v53->_M_header._M_data,
                (stlp_std::priv::_Rb_tree_node_base **)&v52->m_options_count,
                (stlp_std::priv::_Rb_tree_node_base **)&v52->m_type,
                (stlp_std::priv::_Rb_tree_node_base **)&v52->m_game);
        if ( v54 )
        {
          v55 = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
          vostok_mspace_free(v55, (char *)&v54->_M_color);
        }
        --v52->m_movie;
        v56 = vostok::render::g_allocator.m_object;
        v57 = __RTCastToVoid((void **)&v10->__vftable);
        ((void (__thiscall *)(vostok::render::res_texture *, _DWORD))v10->~vostok::render::res_texture)(v10, 0);
        if ( v57 )
        {
          v58 = v57;
          v59 = (malloc_state *)HIDWORD(v56->m_reconstruction_info_actuality_tick);
          BYTE2(v56->m_children_resources.m_lock) = 0;
          vostok_mspace_free(v59, v58);
        }
      }
    }
  }
}
