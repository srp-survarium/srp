void __userpurge vostok::render::stage_shadow_direct::stage_shadow_direct(
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>,
        vostok::render::stage_shadow_direct *this)
{
  vostok::render::stage_shadow_direct *v3; // ebp
  vostok::render::effect_manager *m_conflicted_action_to_bind; // ecx
  vostok::strings::shared::manager *v5; // ecx
  vostok::render::stage_shadow_direct *v6; // eax
  vostok::render::backend *v7; // ecx
  volatile signed __int32 *v8; // esi
  vostok::strings::shared::manager *v9; // ecx
  vostok::render::stage_shadow_direct *v10; // eax
  vostok::render::backend *v11; // ecx
  volatile signed __int32 *v12; // esi
  vostok::strings::shared::manager *v13; // ecx
  vostok::render::stage_shadow_direct *v14; // eax
  vostok::render::backend *v15; // ecx
  volatile signed __int32 *v16; // esi
  vostok::strings::shared::manager *v17; // ecx
  vostok::render::stage_shadow_direct *v18; // eax
  vostok::render::backend *v19; // ecx
  volatile signed __int32 *v20; // esi
  vostok::strings::shared::manager *v21; // ecx
  vostok::render::stage_shadow_direct *v22; // eax
  vostok::render::backend *v23; // ecx
  volatile signed __int32 *v24; // esi
  vostok::strings::shared::manager *v25; // ecx
  vostok::render::stage_shadow_direct *v26; // eax
  vostok::render::backend *v27; // ecx
  volatile signed __int32 *v28; // esi
  survarium::game_action_id *M_start; // eax
  vostok::render::render_target *render_target; // eax
  vostok::render::resource_manager *v31; // ecx
  const char *m_object; // eax
  bool v33; // zf
  stlp_std::priv::_Rb_tree_node_base *texture; // eax
  vostok::render::res_texture *v35; // ecx
  vostok::render::res_texture *v36; // esi
  survarium::options_tab *v37; // edi
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v38; // eax
  vostok::math::float4x4 *m_previous_view_matrix; // ebx
  vostok::math::float4x4 *v40; // eax
  __int64 v41; // xmm0_8
  vostok::math::float4x4 *v42; // esi
  vostok::render::stage_shadow_direct *v43; // eax
  unsigned int v44; // ecx
  vostok::math::float4x4 *v45; // eax
  vostok::math::float4x4 *v46; // edi
  const vostok::math::float4x4 *v47; // edx
  stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > v48; // [esp-4h] [ebp-64h] BYREF
  __int64 v49; // [esp+14h] [ebp-4Ch]
  unsigned int first_array_slice_index; // [esp+1Ch] [ebp-44h]
  vostok::math::float4x4 v51; // [esp+20h] [ebp-40h] BYREF

  v3 = this;
  this->m_context = context;
  v3->m_renderer = in_renderer;
  m_conflicted_action_to_bind = (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind;
  v3->m_enabled = 1;
  v3->m_prev_enabled = 1;
  v3->__vftable = (vostok::render::stage_shadow_direct_vtbl *)&vostok::render::stage_shadow_direct::`vftable';
  v3->m_effect_shadow_direct.m_object = 0;
  v3->m_rt_shadow_map.m_object = 0;
  v3->m_t_shadow_map.m_object = 0;
  v3->m_invalid_shadow = 0;
  v3->m_cascade_texture_index[0] = 0;
  v3->m_cascade_texture_index[1] = 0;
  v3->m_cascade_texture_index[2] = 0;
  v3->m_cascade_texture_index[3] = 0;
  vostok::render::effect_manager::create_effect<vostok::render::effect_shadow_map>(
    m_conflicted_action_to_bind,
    &v3->m_effect_shadow_direct);
  *(_DWORD *)&v48._M_t._M_header._M_data._M_color = "light_direction";
  v6 = (vostok::render::stage_shadow_direct *)vostok::strings::shared::manager::string(
                                                v5,
                                                (const char *)s_manager.m_variable);
  v8 = 0;
  this = 0;
  if ( v6 )
  {
    v8 = (volatile signed __int32 *)v6;
    this = v6;
    v7 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v6, 1u);
  }
  v3->m_c_light_direction = vostok::render::backend::register_constant_host(
                              v7,
                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                              (const vostok::shared_string *)&this,
                              rc_float);
  if ( v8 )
  {
    v9 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v8, 0xFFFFFFFF);
    if ( !v9 )
    {
      *(_DWORD *)&v48._M_t._M_header._M_data._M_color = v8;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  *(_DWORD *)&v48._M_t._M_header._M_data._M_color = "light_position";
  v10 = (vostok::render::stage_shadow_direct *)vostok::strings::shared::manager::string(
                                                 v9,
                                                 (const char *)s_manager.m_variable);
  v12 = 0;
  this = 0;
  if ( v10 )
  {
    v12 = (volatile signed __int32 *)v10;
    this = v10;
    v11 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v10, 1u);
  }
  v3->m_c_light_position = vostok::render::backend::register_constant_host(
                             v11,
                             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                             (const vostok::shared_string *)&this,
                             rc_float);
  if ( v12 )
  {
    v13 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v12, 0xFFFFFFFF);
    if ( !v13 )
    {
      *(_DWORD *)&v48._M_t._M_header._M_data._M_color = v12;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  *(_DWORD *)&v48._M_t._M_header._M_data._M_color = "light_attenuation";
  v14 = (vostok::render::stage_shadow_direct *)vostok::strings::shared::manager::string(
                                                 v13,
                                                 (const char *)s_manager.m_variable);
  v16 = 0;
  this = 0;
  if ( v14 )
  {
    v16 = (volatile signed __int32 *)v14;
    this = v14;
    v15 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v14, 1u);
  }
  v3->m_c_light_attenuation_power = vostok::render::backend::register_constant_host(
                                      v15,
                                      (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                      (const vostok::shared_string *)&this,
                                      rc_float);
  if ( v16 )
  {
    v17 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v16, 0xFFFFFFFF);
    if ( !v17 )
    {
      *(_DWORD *)&v48._M_t._M_header._M_data._M_color = v16;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  *(_DWORD *)&v48._M_t._M_header._M_data._M_color = "start_corner";
  v18 = (vostok::render::stage_shadow_direct *)vostok::strings::shared::manager::string(
                                                 v17,
                                                 (const char *)s_manager.m_variable);
  v20 = 0;
  this = 0;
  if ( v18 )
  {
    v20 = (volatile signed __int32 *)v18;
    this = v18;
    v19 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v18, 1u);
  }
  v3->m_c_start_corner = vostok::render::backend::register_constant_host(
                           v19,
                           (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                           (const vostok::shared_string *)&this,
                           rc_float);
  if ( v20 )
  {
    v21 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v20, 0xFFFFFFFF);
    if ( !v21 )
    {
      *(_DWORD *)&v48._M_t._M_header._M_data._M_color = v20;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  *(_DWORD *)&v48._M_t._M_header._M_data._M_color = "wind_info_parameters";
  v22 = (vostok::render::stage_shadow_direct *)vostok::strings::shared::manager::string(
                                                 v21,
                                                 (const char *)s_manager.m_variable);
  v24 = 0;
  this = 0;
  if ( v22 )
  {
    v24 = (volatile signed __int32 *)v22;
    this = v22;
    v23 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v22, 1u);
  }
  v3->m_wind_info_parameters = vostok::render::backend::register_constant_host(
                                 v23,
                                 (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                 (const vostok::shared_string *)&this,
                                 rc_float);
  if ( v24 )
  {
    v25 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v24, 0xFFFFFFFF);
    if ( !v25 )
    {
      *(_DWORD *)&v48._M_t._M_header._M_data._M_color = v24;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  *(_DWORD *)&v48._M_t._M_header._M_data._M_color = "shadow_cascade_index";
  v26 = (vostok::render::stage_shadow_direct *)vostok::strings::shared::manager::string(
                                                 v25,
                                                 (const char *)s_manager.m_variable);
  v28 = 0;
  this = 0;
  if ( v26 )
  {
    v28 = (volatile signed __int32 *)v26;
    this = v26;
    v27 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v26, 1u);
  }
  v3->m_shadow_cascade_index = vostok::render::backend::register_constant_host(
                                 v27,
                                 (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                 (const vostok::shared_string *)&this,
                                 rc_int);
  if ( v28 && !_InterlockedExchangeAdd(v28, 0xFFFFFFFF) )
  {
    *(_DWORD *)&v48._M_t._M_header._M_data._M_color = v28;
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  M_start = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
  v3->m_enabled = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                  + 247);
  v3->m_cascade_shadow_map_size = M_start[43];
  *(_QWORD *)&v3->m_previous_adjastment[0].x = 0;
  *(_DWORD *)&v48._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&v3->m_previous_adjastment[1].x = 0;
  v3->m_previous_adjastment[0].z = 0.0;
  v3->m_previous_adjastment[1].z = 0.0;
  first_array_slice_index = 0;
  *(_QWORD *)&v3->m_previous_adjastment[2].x = 0;
  v49 = 0;
  *(_QWORD *)&v3->m_previous_adjastment[3].x = 0;
  v3->m_previous_adjastment[3].z = 0.0;
  v3->m_previous_adjastment[2].z = 0.0;
  render_target = vostok::render::resource_manager::create_render_target(
                    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                    "$user$cascaded_shadow_map",
                    (vostok::render::res_texture *)(2 * v3->m_cascade_shadow_map_size),
                    (ID3D11Texture2D **)(2 * v3->m_cascade_shadow_map_size),
                    (const char *)0x35,
                    enum_rt_usage_depth_stencil,
                    0,
                    *(unsigned int *)&v48._M_t._M_header._M_data._M_color,
                    (unsigned int)v48._M_t._M_header._M_data._M_parent,
                    (unsigned int)v48._M_t._M_header._M_data._M_left);
  v31 = 0;
  if ( render_target )
  {
    ++render_target->m_reference_count;
    v31 = (vostok::render::resource_manager *)render_target;
  }
  m_object = (const char *)v3->m_rt_shadow_map.m_object;
  v3->m_rt_shadow_map.m_object = (vostok::render::render_target *)v31;
  if ( m_object )
  {
    v33 = (*(_DWORD *)m_object)-- == 1;
    if ( v33 )
      vostok::render::resource_manager::release(
        v31,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_object);
  }
  texture = vostok::render::resource_manager::create_texture(
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              "$user$cascaded_shadow_map",
              0,
              0,
              0,
              1,
              1,
              0xFFFFFFFF);
  v35 = 0;
  if ( texture )
  {
    ++texture->_M_parent;
    v35 = (vostok::render::res_texture *)texture;
  }
  v36 = v3->m_t_shadow_map.m_object;
  v3->m_t_shadow_map.m_object = v35;
  if ( v36 )
  {
    v33 = v36->m_reference_count-- == 1;
    if ( v33 && v36->m_is_registered )
    {
      v37 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
      this = (vostok::render::stage_shadow_direct *)v36->m_name.m_string.m_begin;
      v38 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
              (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&this,
              (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7],
              (const char **)&this);
      if ( v38 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v37 )
      {
        stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
          &v48,
          (int)v37,
          (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v38);
        vostok::render::resource_manager::release_impl(
          v36,
          (vostok::render::resource_manager *)v48._M_t._M_header._M_data._M_parent);
      }
    }
  }
  v49 = 0;
  first_array_slice_index = 0;
  this = (vostok::render::stage_shadow_direct *)v3->m_previous_position;
  m_previous_view_matrix = v3->m_previous_view_matrix;
  *(_DWORD *)&v48._M_t._M_key_compare.stlp_std::binary_function<char *,char *,bool> = 4;
  do
  {
    qmemcpy((void *)&m_previous_view_matrix[12], vostok::math::float4x4::identity(&v51), sizeof(vostok::math::float4x4));
    qmemcpy((void *)m_previous_view_matrix, vostok::math::float4x4::identity(&v51), sizeof(vostok::math::float4x4));
    qmemcpy((void *)&m_previous_view_matrix[4], vostok::math::float4x4::identity(&v51), sizeof(vostok::math::float4x4));
    v40 = vostok::math::float4x4::identity(&v51);
    v41 = v49;
    v42 = v40;
    v43 = this;
    qmemcpy((void *)&m_previous_view_matrix[8], v42, sizeof(vostok::math::float4x4));
    v44 = first_array_slice_index;
    *(_QWORD *)&v43->__vftable = v41;
    v43->m_renderer = (vostok::render::renderer *)v44;
    v45 = vostok::math::float4x4::identity(&v51);
    this = (vostok::render::stage_shadow_direct *)((char *)this + 12);
    v46 = m_previous_view_matrix + 16;
    ++m_previous_view_matrix;
    v33 = (*(_DWORD *)&v48._M_t._M_key_compare.stlp_std::binary_function<char *,char *,bool>)-- == 1;
    qmemcpy((void *)v46, v45, sizeof(vostok::math::float4x4));
  }
  while ( !v33 );
  v47 = clear_value;
  *(_QWORD *)&v3->m_previous_direction.x = 0;
  LODWORD(v3->m_previous_direction.z) = v47;
}
