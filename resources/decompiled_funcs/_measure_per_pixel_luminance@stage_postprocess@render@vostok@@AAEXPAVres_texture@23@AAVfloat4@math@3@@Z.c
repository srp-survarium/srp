void __thiscall vostok::render::stage_postprocess::measure_per_pixel_luminance(
        vostok::render::stage_postprocess *this,
        vostok::render::stage_postprocess *scene_texture,
        vostok::render::res_texture *out_avrg_min_max)
{
  vostok::render::stage_postprocess *v3; // edi
  _DWORD *v4; // eax
  int v5; // ecx
  const char *m_conflicted_key_name; // esi
  const vostok::render::renderer_context_targets *m_targets; // eax
  vostok::render::render_target *m_object; // eax
  unsigned int v9; // ecx
  int v10; // ebx
  _DWORD *v11; // eax
  vostok::render::textures_handler<0> *v12; // ecx
  int v13; // ebx
  ID3D11ShaderResourceView *v14; // eax
  vostok::render::res_texture *v15; // esi
  char v16; // al
  bool v17; // zf
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v18; // eax
  vostok::render::render_target **p_m_object; // ebx
  vostok::render::render_target *v20; // eax
  _DWORD *v21; // eax
  unsigned int v22; // ecx
  vostok::render::renderer_context *m_context; // edx
  vostok::render::res_texture *v24; // eax
  vostok::render::res_texture *v25; // esi
  const char *v26; // ebx
  vostok::render::res_texture *v27; // ecx
  const vostok::render::renderer_context_targets *v28; // eax
  vostok::render::render_target *v29; // eax
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v30; // [esp-4h] [ebp-1Ch] BYREF
  vostok::render::resource_manager *v31; // [esp+0h] [ebp-18h]
  int lum_rt_index; // [esp+Ch] [ebp-Ch]
  const char *m_begin; // [esp+10h] [ebp-8h] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > > __pos; // [esp+14h] [ebp-4h]

  v3 = scene_texture;
  v4 = &scene_texture->m_sh_gather_luminance.m_object->__vftable;
  v5 = (v4[71] - v4[70]) >> 2;
  if ( v5 )
  {
    v4[69] = 0;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v5, (unsigned int)v31);
  }
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)m_conflicted_key_name + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                              (vostok::render::textures_handler<0> *)v5,
                                              (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                            + 1488,
                                              (vostok::render::res_texture *)&stru_9656C8,
                                              out_avrg_min_max);
  m_targets = scene_texture->m_context->m_targets;
  v30.m_object = 0;
  m_object = m_targets->m_family[64].target.m_object;
  if ( m_object )
  {
    v30.m_object = m_object;
    ++m_object->m_reference_count;
  }
  vostok::render::stage_postprocess::fill_surface2((vostok::render::stage_postprocess *)&v30, scene_texture, v30);
  v10 = 63;
  for ( lum_rt_index = 63; ; v10 = lum_rt_index )
  {
    v11 = &v3->m_sh_gather_luminance.m_object->__vftable;
    if ( v10 == 56 )
    {
      v9 = (v11[71] - v11[70]) >> 2;
      if ( v9 <= 2 )
        goto LABEL_13;
      v11[69] = 2;
    }
    else
    {
      if ( (unsigned int)((v11[71] - v11[70]) >> 2) <= 1 )
        goto LABEL_13;
      v11[69] = 1;
    }
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v9, (unsigned int)v31);
LABEL_13:
    v12 = (vostok::render::textures_handler<0> *)v3->m_context->m_targets;
    v13 = 160 * v10;
    v14 = v12->m_tmp_buffer[v13 / 4u + 76];
    v15 = 0;
    if ( v14 )
    {
      v15 = (vostok::render::res_texture *)v12->m_tmp_buffer[v13 / 4u + 76];
      ++v14[1].lpVtbl;
    }
    m_begin = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v16 = vostok::render::textures_handler<0>::set_overwrite(
            v12,
            (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 1488,
            (vostok::render::res_texture *)&stru_9656C8.m_rescale_min,
            v15);
    *((_BYTE *)m_begin + 159) = v16;
    if ( v15 )
    {
      v17 = v15->m_reference_count-- == 1;
      if ( v17 && v15->m_is_registered )
      {
        m_begin = v15->m_name.m_string.m_begin;
        __pos._M_node = (stlp_std::priv::_Rb_tree_node_base *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7];
        v18 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&m_begin,
                (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7],
                &m_begin);
        if ( v18 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)__pos._M_node )
        {
          stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
            (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)__pos._M_node,
            (int)__pos._M_node,
            (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v18);
          vostok::render::resource_manager::release_impl(v15, v31);
          v3 = scene_texture;
        }
      }
    }
    p_m_object = &v3->m_context->m_targets->m_family[v13 / 0xA0u].target.m_object;
    v30.m_object = 0;
    v20 = *p_m_object;
    if ( *p_m_object )
    {
      v30.m_object = *p_m_object;
      ++v20->m_reference_count;
    }
    vostok::render::stage_postprocess::fill_surface2((vostok::render::stage_postprocess *)&v30, v3, v30);
    if ( --lum_rt_index < 56 )
      break;
  }
  __pos._M_node = (stlp_std::priv::_Rb_tree_node_base *)v3->m_context->m_scene_view.m_object[2].m_parent_resources.m_lock;
  __pos._M_node = (stlp_std::priv::_Rb_tree_node_base *)((unsigned int)__pos._M_node & 0x7FFFFFFF);
  if ( *(float *)&__pos._M_node < 0.050000001 )
  {
    v21 = &v3->m_sh_eye_adaptation.m_object->__vftable;
    v22 = (v21[71] - v21[70]) >> 2;
    if ( v22 > 1 )
    {
      v21[69] = 1;
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v22, (unsigned int)v31);
    }
    m_context = v3->m_context;
    v24 = m_context->m_targets->m_family[56].texture.m_object;
    v25 = 0;
    if ( v24 )
    {
      v25 = m_context->m_targets->m_family[56].texture.m_object;
      ++v24->m_reference_count;
    }
    v26 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *((_BYTE *)v26 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                              (vostok::render::textures_handler<0> *)v22,
                              (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                            + 1488,
                              (vostok::render::res_texture *)&stru_9656C8.m_rescale_max,
                              v25);
    if ( v25 )
    {
      v17 = v25->m_reference_count-- == 1;
      if ( v17 )
        vostok::render::res_texture::destroy_impl(v27, v25);
    }
    v28 = v3->m_context->m_targets;
    v30.m_object = 0;
    v29 = v28->m_family[53].target.m_object;
    if ( v29 )
    {
      v30.m_object = v29;
      ++v29->m_reference_count;
    }
    vostok::render::stage_postprocess::fill_surface2((vostok::render::stage_postprocess *)&v30, v3, v30);
  }
}
