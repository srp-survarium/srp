void __thiscall vostok::render::stage_lights::~stage_lights(vostok::render::stage_lights *this)
{
  void *m_reconstruction_info_actuality_tick_high; // esi
  char *v3; // eax
  vostok::render::resource_manager *v4; // ecx
  vostok::render::shader_constant_host **p_m_probe_parameters0; // eax
  _DWORD *v6; // eax
  bool v7; // zf
  _DWORD *v8; // esi
  void **M_start; // eax
  void **M_finish; // edx
  void ***p_M_finish; // edi
  vostok::render::resource_manager *v12; // ebx
  int v13; // eax
  vostok::render::grass_render_model *m_object; // edi
  void *v15; // eax
  void *v16; // esi
  vostok::render::res_declaration *v17; // eax
  vostok::render::res_declaration *v18; // eax
  vostok::render::untyped_buffer *v19; // eax
  vostok::render::res_geometry *v20; // eax
  vostok::render::untyped_buffer *v21; // eax
  vostok::render::stage_lights::light_geometry *v22; // ecx
  vostok::render::stage_lights::light_geometry *v23; // ecx
  vostok::render::res_texture *v24; // ecx
  vostok::render::res_effect *v25; // eax
  vostok::render::res_effect *v26; // eax
  vostok::render::res_effect *v27; // eax
  vostok::render::res_effect *v28; // eax
  vostok::render::res_effect *v29; // eax
  vostok::render::res_effect *v30; // eax
  vostok::render::res_effect *v31; // eax
  vostok::render::res_effect *v32; // eax
  vostok::render::res_effect *v33; // eax
  vostok::render::res_effect *v34; // eax
  vostok::render::res_effect *v35; // eax
  vostok::render::res_effect *v36; // eax
  vostok::render::res_effect *v37; // eax
  vostok::render::res_effect *v38; // eax
  vostok::render::res_effect *v39; // eax
  vostok::render::res_effect *v40; // eax
  vostok::render::res_texture *v41; // eax
  vostok::render::res_texture *v42; // eax
  const char **p_m_cubemap_texture; // esi
  int i; // edi
  _DWORD *v45; // eax
  const char **m_cubemap_face_depth_stencil; // esi
  int j; // edi
  _DWORD *v48; // eax
  vostok::render::res_geometry *v49; // eax
  vostok::render::untyped_buffer *v50; // eax
  vostok::render::res_texture *v51; // eax
  vostok::render::res_texture *v52; // eax
  const char **p_m_lookup_vcm_texture; // esi
  int k; // edi
  _DWORD *v55; // eax
  vostok::render::resource_manager **m_lookup_vcm_depth_stencil; // esi
  int m; // edi
  _DWORD *v58; // eax
  vostok::render::render_target *v59; // eax
  vostok::render::render_target *v60; // eax
  int v61; // eax
  int v62; // ebx
  survarium::options_tab *v63; // edi
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v64; // eax
  stlp_std::priv::_Rb_tree_node_base *v65; // eax
  void *v66; // esi
  vostok::render::grass_render_model *v67; // edi
  _BYTE *v68; // esi
  void *v69; // eax
  void *v70; // esi
  vostok::render::resource_manager **m_shadow_depth_stencil_texture; // esi
  int ii; // edi
  _DWORD *v73; // eax
  vostok::render::res_texture *v74; // eax
  vostok::render::render_target *v75; // eax
  vostok::render::render_target *v76; // eax
  vostok::render::res_texture *v77; // eax
  vostok::render::render_target *v78; // eax
  vostok::render::res_texture *v79; // eax
  vostok::render::render_target *v80; // eax
  vostok::render::res_texture *v81; // eax
  vostok::render::render_target *v82; // eax
  vostok::render::res_texture *v83; // eax
  vostok::render::render_target *v84; // eax
  vostok::render::res_texture *v85; // eax
  vostok::render::render_target *v86; // eax
  vostok::render::res_texture *v87; // eax
  vostok::render::render_target *v88; // eax
  vostok::render::res_texture *v89; // eax
  vostok::render::render_target *v90; // eax
  vostok::render::res_texture *v91; // eax
  vostok::render::render_target *v92; // eax
  vostok::render::res_texture *v93; // eax
  vostok::render::render_target *v94; // eax
  vostok::render::res_texture *v95; // eax
  vostok::render::render_target *v96; // eax
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v97; // [esp+14h] [ebp-Ch]
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *p_m_vcm_render_target; // [esp+14h] [ebp-Ch]
  int v99; // [esp+18h] [ebp-8h]
  int n; // [esp+18h] [ebp-8h]
  const char *v101; // [esp+1Ch] [ebp-4h] BYREF

  this->__vftable = (vostok::render::stage_lights_vtbl *)&stru_9649F4.m_name.m_string.m_buffer[124];
  m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  v3 = (char *)&this->m_light_instances[-1].lines[3].elements[2];
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v3);
  v4 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  p_m_probe_parameters0 = &this->m_probe_parameters0;
  v99 = 3;
  while ( 1 )
  {
    v97 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)(p_m_probe_parameters0 - 1);
    v6 = *(p_m_probe_parameters0 - 1);
    if ( v6 )
    {
      v7 = (*v6)-- == 1;
      if ( v7 )
      {
        v8 = *(_DWORD **)&v97->_M_header._M_data._M_color;
        M_start = v4->m_buffers._M_impl._M_start;
        M_finish = v4->m_buffers._M_impl._M_finish;
        p_M_finish = &v4->m_buffers._M_impl._M_finish;
        v12 = v4;
        if ( M_start != M_finish )
        {
          while ( *M_start != v8 )
          {
            if ( ++M_start == M_finish )
              goto LABEL_14;
          }
          if ( M_start + 1 != M_finish )
            stlp_std::priv::__copy_ptrs<void * *,void * *>(M_start + 1, *p_M_finish, M_start);
          --*p_M_finish;
          v12->m_num_bytes_of_buffers_video_memory -= v8[2];
          v13 = v8[1];
          m_object = vostok::render::g_allocator.m_object;
          if ( v13 )
          {
            (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v13 + 8))(v8[1]);
            v8[1] = 0;
          }
          v15 = v8;
          v16 = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
          BYTE2(m_object->m_children_resources.m_lock) = 0;
          vostok_mspace_free(v16, v15);
          v4 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
        }
      }
    }
LABEL_14:
    if ( --v99 < 0 )
      break;
    p_m_probe_parameters0 = (vostok::render::shader_constant_host **)v97;
  }
  v17 = this->m_instance_declaration_small.m_object;
  if ( v17 )
  {
    v7 = v17->m_reference_count-- == 1;
    if ( v7 )
    {
      vostok::render::resource_manager::release(v4, this->m_instance_declaration_small.m_object);
      v4 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
    }
  }
  v18 = this->m_instance_declaration.m_object;
  if ( v18 )
  {
    v7 = v18->m_reference_count-- == 1;
    if ( v7 )
    {
      vostok::render::resource_manager::release(v4, this->m_instance_declaration.m_object);
      v4 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
    }
  }
  v19 = this->m_instance_vb_small.m_object;
  if ( v19 )
  {
    v7 = v19->m_reference_count-- == 1;
    if ( v7 )
    {
      vostok::render::resource_manager::release((vostok::render::res_state *)this->m_instance_vb_small.m_object, v4);
      v4 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
    }
  }
  v20 = this->m_screen_vertex_geometry.m_object;
  if ( v20 )
  {
    v7 = v20->m_reference_count-- == 1;
    if ( v7 )
    {
      vostok::render::resource_manager::release(v4, this->m_screen_vertex_geometry.m_object);
      v4 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
    }
  }
  v21 = this->m_screen_vertex_ib.m_object;
  if ( v21 )
  {
    v7 = v21->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release((vostok::render::res_state *)this->m_screen_vertex_ib.m_object, v4);
  }
  vostok::render::stage_lights::light_geometry::~light_geometry(
    (vostok::render::stage_lights::light_geometry *)v4,
    (int)&this->m_obb_geometry);
  vostok::render::stage_lights::light_geometry::~light_geometry(v22, (int)&this->m_pyramid_geometry);
  vostok::render::stage_lights::light_geometry::~light_geometry(v23, (int)&this->m_sphere_geometry);
  v25 = this->m_shadow_effect.m_object;
  if ( v25 )
  {
    v24 = (vostok::render::res_texture *)_InterlockedExchangeAdd(&v25->m_reference_count, 0xFFFFFFFF);
    if ( !v24 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_shadow_effect.m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_shadow_effect.m_object);
  }
  v26 = this->m_sh_fix_irradiance_texture.m_object;
  if ( v26 && !_InterlockedExchangeAdd(&v26->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_sh_fix_irradiance_texture.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_sh_fix_irradiance_texture.m_object);
  v27 = this->m_sh_downsample_skin_irradiance_texture.m_object;
  if ( v27 )
  {
    v24 = (vostok::render::res_texture *)_InterlockedExchangeAdd(&v27->m_reference_count, 0xFFFFFFFF);
    if ( !v24 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_sh_downsample_skin_irradiance_texture.m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_sh_downsample_skin_irradiance_texture.m_object);
  }
  v28 = this->m_shadowed_plane_spot_light_accumulator.m_object;
  if ( v28 && !_InterlockedExchangeAdd(&v28->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_shadowed_plane_spot_light_accumulator.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_shadowed_plane_spot_light_accumulator.m_object);
  v29 = this->m_plane_spot_light_accumulator.m_object;
  if ( v29 )
  {
    v24 = (vostok::render::res_texture *)_InterlockedExchangeAdd(&v29->m_reference_count, 0xFFFFFFFF);
    if ( !v24 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_plane_spot_light_accumulator.m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_plane_spot_light_accumulator.m_object);
  }
  v30 = this->m_shadowed_sphere_light_accumulator.m_object;
  if ( v30 && !_InterlockedExchangeAdd(&v30->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_shadowed_sphere_light_accumulator.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_shadowed_sphere_light_accumulator.m_object);
  v31 = this->m_sphere_light_accumulator.m_object;
  if ( v31 )
  {
    v24 = (vostok::render::res_texture *)_InterlockedExchangeAdd(&v31->m_reference_count, 0xFFFFFFFF);
    if ( !v24 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_sphere_light_accumulator.m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_sphere_light_accumulator.m_object);
  }
  v32 = this->m_shadowed_obb_light_accumulator.m_object;
  if ( v32 && !_InterlockedExchangeAdd(&v32->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_shadowed_obb_light_accumulator.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_shadowed_obb_light_accumulator.m_object);
  v33 = this->m_obb_light_accumulator.m_object;
  if ( v33 )
  {
    v24 = (vostok::render::res_texture *)_InterlockedExchangeAdd(&v33->m_reference_count, 0xFFFFFFFF);
    if ( !v24 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_obb_light_accumulator.m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_obb_light_accumulator.m_object);
  }
  v34 = this->m_capsule_light_accumulator.m_object;
  if ( v34 && !_InterlockedExchangeAdd(&v34->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_capsule_light_accumulator.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_capsule_light_accumulator.m_object);
  v35 = this->m_shadowed_spot_light_accumulator.m_object;
  if ( v35 )
  {
    v24 = (vostok::render::res_texture *)_InterlockedExchangeAdd(&v35->m_reference_count, 0xFFFFFFFF);
    if ( !v24 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_shadowed_spot_light_accumulator.m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_shadowed_spot_light_accumulator.m_object);
  }
  v36 = this->m_spot_light_accumulator.m_object;
  if ( v36 && !_InterlockedExchangeAdd(&v36->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_spot_light_accumulator.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_spot_light_accumulator.m_object);
  v37 = this->m_shadowed_point_light_accumulator.m_object;
  if ( v37 )
  {
    v24 = (vostok::render::res_texture *)_InterlockedExchangeAdd(&v37->m_reference_count, 0xFFFFFFFF);
    if ( !v24 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_shadowed_point_light_accumulator.m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_shadowed_point_light_accumulator.m_object);
  }
  v38 = this->m_point_light_accumulator.m_object;
  if ( v38 && !_InterlockedExchangeAdd(&v38->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_point_light_accumulator.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_point_light_accumulator.m_object);
  v39 = this->m_point_light_shadower.m_object;
  if ( v39 )
  {
    v24 = (vostok::render::res_texture *)_InterlockedExchangeAdd(&v39->m_reference_count, 0xFFFFFFFF);
    if ( !v24 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_point_light_shadower.m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_point_light_shadower.m_object);
  }
  v40 = this->m_effect_accum_mask.m_object;
  if ( v40 && !_InterlockedExchangeAdd(&v40->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_effect_accum_mask.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_effect_accum_mask.m_object);
  v41 = this->m_depth_stencil_cubemap_texture.m_object;
  if ( v41 )
  {
    v7 = v41->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::res_texture::destroy_impl(v24, this->m_depth_stencil_cubemap_texture.m_object);
  }
  v42 = this->m_cubemap_texture.m_object;
  if ( v42 )
  {
    v7 = v42->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::res_texture::destroy_impl(v24, this->m_cubemap_texture.m_object);
  }
  p_m_cubemap_texture = (const char **)&this->m_cubemap_texture;
  for ( i = 5; i >= 0; --i )
  {
    v45 = *--p_m_cubemap_texture;
    if ( v45 )
    {
      v7 = (*v45)-- == 1;
      if ( v7 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          *p_m_cubemap_texture);
    }
  }
  m_cubemap_face_depth_stencil = (const char **)this->m_cubemap_face_depth_stencil;
  for ( j = 5; j >= 0; --j )
  {
    v48 = *--m_cubemap_face_depth_stencil;
    if ( v48 )
    {
      v7 = (*v48)-- == 1;
      if ( v7 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)v24,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          *m_cubemap_face_depth_stencil);
    }
  }
  v49 = this->m_lookup_vcm_geometry.m_object;
  if ( v49 )
  {
    v7 = v49->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        this->m_lookup_vcm_geometry.m_object);
  }
  v50 = this->m_lookup_vcm_ib.m_object;
  if ( v50 )
  {
    v7 = v50->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)this->m_lookup_vcm_ib.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v51 = this->m_lookup_vcm_depth_stencil_texture.m_object;
  if ( v51 )
  {
    v7 = v51->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::res_texture::destroy_impl(v24, this->m_lookup_vcm_depth_stencil_texture.m_object);
  }
  v52 = this->m_lookup_vcm_texture.m_object;
  if ( v52 )
  {
    v7 = v52->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::res_texture::destroy_impl(v24, this->m_lookup_vcm_texture.m_object);
  }
  p_m_lookup_vcm_texture = (const char **)&this->m_lookup_vcm_texture;
  for ( k = 5; k >= 0; --k )
  {
    v55 = *--p_m_lookup_vcm_texture;
    if ( v55 )
    {
      v7 = (*v55)-- == 1;
      if ( v7 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)v24,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          *p_m_lookup_vcm_texture);
    }
  }
  m_lookup_vcm_depth_stencil = (vostok::render::resource_manager **)this->m_lookup_vcm_depth_stencil;
  for ( m = 5; m >= 0; --m )
  {
    v58 = *--m_lookup_vcm_depth_stencil;
    if ( v58 )
    {
      v7 = (*v58)-- == 1;
      if ( v7 )
        vostok::render::resource_manager::release(
          *m_lookup_vcm_depth_stencil,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)*m_lookup_vcm_depth_stencil);
    }
  }
  v59 = this->m_vcm_depth_stencil.m_object;
  if ( v59 )
  {
    v7 = v59->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)this->m_vcm_depth_stencil.m_object);
  }
  v60 = this->m_vcm_render_target.m_object;
  if ( v60 )
  {
    v7 = v60->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)v24,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)this->m_vcm_render_target.m_object);
  }
  p_m_vcm_render_target = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&this->m_vcm_render_target;
  for ( n = 2; n >= 0; --n )
  {
    p_m_vcm_render_target = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)((char *)p_m_vcm_render_target - 4);
    v61 = *(_DWORD *)&p_m_vcm_render_target->_M_header._M_data._M_color;
    if ( *(_DWORD *)&p_m_vcm_render_target->_M_header._M_data._M_color )
    {
      v7 = (*(_DWORD *)(v61 + 4))-- == 1;
      if ( v7 )
      {
        v24 = (vostok::render::res_texture *)p_m_vcm_render_target;
        v62 = *(_DWORD *)&p_m_vcm_render_target->_M_header._M_data._M_color;
        if ( *(_BYTE *)(*(_DWORD *)&p_m_vcm_render_target->_M_header._M_data._M_color + 439) )
        {
          v63 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
          v101 = *(const char **)(v62 + 144);
          v64 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(p_m_vcm_render_target, (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7], &v101);
          if ( v64 != (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v63 )
          {
            v65 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
                    &v64->_M_header._M_data,
                    (stlp_std::priv::_Rb_tree_node_base **)&v63->m_options_count,
                    (stlp_std::priv::_Rb_tree_node_base **)&v63->m_type,
                    (stlp_std::priv::_Rb_tree_node_base **)&v63->m_game);
            if ( v65 )
            {
              v66 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(v66, v65);
            }
            --v63->m_movie;
            v67 = vostok::render::g_allocator.m_object;
            v68 = __RTCastToVoid((void **)v62);
            (**(void (__thiscall ***)(int, _DWORD))v62)(v62, 0);
            if ( v68 )
            {
              v69 = v68;
              v70 = (void *)HIDWORD(v67->m_reconstruction_info_actuality_tick);
              BYTE2(v67->m_children_resources.m_lock) = 0;
              vostok_mspace_free(v70, v69);
            }
          }
        }
      }
    }
  }
  m_shadow_depth_stencil_texture = (vostok::render::resource_manager **)this->m_shadow_depth_stencil_texture;
  for ( ii = 2; ii >= 0; --ii )
  {
    v73 = *--m_shadow_depth_stencil_texture;
    if ( v73 )
    {
      v7 = (*v73)-- == 1;
      if ( v7 )
        vostok::render::resource_manager::release(
          *m_shadow_depth_stencil_texture,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)*m_shadow_depth_stencil_texture);
    }
  }
  v74 = this->m_skin_scattering_texture.m_object;
  if ( v74 )
  {
    v7 = v74->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::res_texture::destroy_impl(v24, this->m_skin_scattering_texture.m_object);
  }
  v75 = this->m_skin_scattering_depth_stencil.m_object;
  if ( v75 )
  {
    v7 = v75->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)this->m_skin_scattering_depth_stencil.m_object);
  }
  v76 = this->m_skin_scattering_render_target.m_object;
  if ( v76 )
  {
    v7 = v76->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)v24,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)this->m_skin_scattering_render_target.m_object);
  }
  v77 = this->m_t_skin_scattering_blurred_4.m_object;
  if ( v77 )
  {
    v7 = v77->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::res_texture::destroy_impl(v24, this->m_t_skin_scattering_blurred_4.m_object);
  }
  v78 = this->m_rt_skin_scattering_blurred_4.m_object;
  if ( v78 )
  {
    v7 = v78->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)this->m_rt_skin_scattering_blurred_4.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)this->m_rt_skin_scattering_blurred_4.m_object);
  }
  v79 = this->m_t_skin_scattering_blurred_3.m_object;
  if ( v79 )
  {
    v7 = v79->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::res_texture::destroy_impl(v24, this->m_t_skin_scattering_blurred_3.m_object);
  }
  v80 = this->m_rt_skin_scattering_blurred_3.m_object;
  if ( v80 )
  {
    v7 = v80->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)this->m_rt_skin_scattering_blurred_3.m_object);
  }
  v81 = this->m_t_skin_scattering_blurred_2.m_object;
  if ( v81 )
  {
    v7 = v81->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::res_texture::destroy_impl(v24, this->m_t_skin_scattering_blurred_2.m_object);
  }
  v82 = this->m_rt_skin_scattering_blurred_2.m_object;
  if ( v82 )
  {
    v7 = v82->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)v24,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)this->m_rt_skin_scattering_blurred_2.m_object);
  }
  v83 = this->m_t_skin_scattering_blurred_1.m_object;
  if ( v83 )
  {
    v7 = v83->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::res_texture::destroy_impl(v24, this->m_t_skin_scattering_blurred_1.m_object);
  }
  v84 = this->m_rt_skin_scattering_blurred_1.m_object;
  if ( v84 )
  {
    v7 = v84->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)this->m_rt_skin_scattering_blurred_1.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)this->m_rt_skin_scattering_blurred_1.m_object);
  }
  v85 = this->m_t_skin_scattering_blurred_0.m_object;
  if ( v85 )
  {
    v7 = v85->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::res_texture::destroy_impl(v24, this->m_t_skin_scattering_blurred_0.m_object);
  }
  v86 = this->m_rt_skin_scattering_blurred_0.m_object;
  if ( v86 )
  {
    v7 = v86->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)this->m_rt_skin_scattering_blurred_0.m_object);
  }
  v87 = this->m_t_skin_scattering_small.m_object;
  if ( v87 )
  {
    v7 = v87->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::res_texture::destroy_impl(v24, this->m_t_skin_scattering_small.m_object);
  }
  v88 = this->m_rt_skin_scattering_small.m_object;
  if ( v88 )
  {
    v7 = v88->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)v24,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)this->m_rt_skin_scattering_small.m_object);
  }
  v89 = this->m_t_skin_scattering_stretch.m_object;
  if ( v89 )
  {
    v7 = v89->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::res_texture::destroy_impl(v24, this->m_t_skin_scattering_stretch.m_object);
  }
  v90 = this->m_rt_skin_scattering_stretch.m_object;
  if ( v90 )
  {
    v7 = v90->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)this->m_rt_skin_scattering_stretch.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)this->m_rt_skin_scattering_stretch.m_object);
  }
  v91 = this->m_t_skin_scattering.m_object;
  if ( v91 )
  {
    v7 = v91->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::res_texture::destroy_impl(v24, this->m_t_skin_scattering.m_object);
  }
  v92 = this->m_rt_skin_scattering.m_object;
  if ( v92 )
  {
    v7 = v92->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)this->m_rt_skin_scattering.m_object);
  }
  v93 = this->m_t_skin_scattering_temp.m_object;
  if ( v93 )
  {
    v7 = v93->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::res_texture::destroy_impl(v24, this->m_t_skin_scattering_temp.m_object);
  }
  v94 = this->m_rt_skin_scattering_temp.m_object;
  if ( v94 )
  {
    v7 = v94->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)v24,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)this->m_rt_skin_scattering_temp.m_object);
  }
  v95 = this->m_t_skin_scattering_position.m_object;
  if ( v95 )
  {
    v7 = v95->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::res_texture::destroy_impl(v24, this->m_t_skin_scattering_position.m_object);
  }
  v96 = this->m_rt_skin_scattering_position.m_object;
  if ( v96 )
  {
    v7 = v96->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)this->m_rt_skin_scattering_position.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)this->m_rt_skin_scattering_position.m_object);
  }
  this->__vftable = (vostok::render::stage_lights_vtbl *)&vostok::render::stage::`vftable';
}
