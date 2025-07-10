void __userpurge vostok::render::stage_clouds::stage_clouds(
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>,
        vostok::render::stage_clouds *this,
        vostok::render::cloud_interp_textures *in_interp_textures,
        vostok::render::cloud_simulation *in_simulation)
{
  vostok::render::sphere_geometry *v5; // ecx
  vostok::render::environment_temp *v6; // ecx
  survarium::game_action_id *M_start; // eax
  double m_clouds_size_x; // st7
  const vostok::math::float4x4 *v9; // eax
  survarium::game_action_id *v10; // edx
  signed int v11; // eax
  signed int m_clouds_size_y; // ecx
  double v13; // st7
  signed int m_clouds_size_z; // edx
  double v15; // st7
  float m_clouds_scale_multiplier; // xmm0_4
  float v17; // eax
  unsigned int v18; // edi
  const char *v19; // eax
  vostok::render::res_texture *texture3d; // eax
  vostok::render::res_texture *v21; // ecx
  vostok::render::res_texture *m_object; // esi
  bool v23; // zf
  vostok::strings::shared::profile *v24; // eax
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v25; // ecx
  vostok::render::res_texture *v26; // eax
  vostok::render::res_texture *v27; // esi
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v28; // eax
  vostok::render::stage_clouds *v29; // ecx
  vostok::render::res_texture *v30; // eax
  vostok::render::res_texture *v31; // esi
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v32; // eax
  vostok::render::scene *m_scene; // eax
  vostok::render::stage_clouds *v34; // ecx
  vostok::render::res_texture *v35; // edx
  vostok::render::cloud_interp_textures *m_interp_textures; // ecx
  vostok::render::res_texture *v37; // eax
  const vostok::render::res_texture *v38; // esi
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v39; // eax
  vostok::render::res_texture *v40; // edx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_cloud_density_1; // eax
  vostok::render::res_texture *v42; // ecx
  const vostok::render::res_texture *v43; // esi
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v44; // eax
  vostok::strings::shared::manager *v45; // ecx
  vostok::strings::shared::profile *v46; // eax
  vostok::render::backend *v47; // ecx
  volatile signed __int32 *p_m_reference_count; // esi
  vostok::strings::shared::manager *v49; // ecx
  vostok::strings::shared::profile *v50; // eax
  vostok::render::backend *v51; // ecx
  volatile signed __int32 *v52; // esi
  vostok::strings::shared::manager *v53; // ecx
  vostok::strings::shared::profile *v54; // eax
  vostok::render::backend *v55; // ecx
  volatile signed __int32 *v56; // esi
  vostok::strings::shared::manager *v57; // ecx
  vostok::strings::shared::profile *v58; // eax
  vostok::render::backend *v59; // ecx
  volatile signed __int32 *v60; // esi
  vostok::strings::shared::manager *v61; // ecx
  vostok::strings::shared::profile *v62; // eax
  vostok::render::backend *v63; // ecx
  volatile signed __int32 *v64; // esi
  vostok::strings::shared::manager *v65; // ecx
  vostok::strings::shared::profile *v66; // eax
  vostok::render::backend *v67; // ecx
  volatile signed __int32 *v68; // esi
  vostok::strings::shared::manager *v69; // ecx
  vostok::strings::shared::profile *v70; // eax
  vostok::render::backend *v71; // ecx
  volatile signed __int32 *v72; // esi
  vostok::strings::shared::manager *v73; // ecx
  vostok::strings::shared::profile *v74; // eax
  vostok::render::backend *v75; // ecx
  volatile signed __int32 *v76; // esi
  vostok::strings::shared::manager *v77; // ecx
  vostok::strings::shared::profile *v78; // eax
  vostok::render::backend *v79; // ecx
  volatile signed __int32 *v80; // esi
  vostok::strings::shared::manager *v81; // ecx
  vostok::strings::shared::profile *v82; // eax
  vostok::render::backend *v83; // ecx
  void *(__thiscall *v84)(void *); // esi
  char v85; // cl
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v87; // ecx
  vostok::render::res_state *v88; // edi
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v90; // ecx
  vostok::render::res_geometry *v91; // eax
  void *(__thiscall *p_m_desc_cache_surface)(void *); // [esp-4h] [ebp-ACh] BYREF
  vostok::render::resource_manager *v93; // [esp+0h] [ebp-A8h]
  __int64 v94; // [esp+10h] [ebp-98h]
  float v95; // [esp+18h] [ebp-90h]
  vostok::shared_string v96; // [esp+1Ch] [ebp-8Ch] BYREF
  vostok::shared_string name; // [esp+20h] [ebp-88h] BYREF
  unsigned int i; // [esp+24h] [ebp-84h] BYREF
  vostok::shared_string v99; // [esp+28h] [ebp-80h] BYREF
  vostok::shared_string v100; // [esp+2Ch] [ebp-7Ch] BYREF
  vostok::shared_string v101; // [esp+30h] [ebp-78h] BYREF
  vostok::shared_string v102; // [esp+34h] [ebp-74h] BYREF
  vostok::shared_string v103; // [esp+38h] [ebp-70h] BYREF
  vostok::shared_string v104; // [esp+3Ch] [ebp-6Ch] BYREF
  vostok::shared_string v105; // [esp+40h] [ebp-68h] BYREF
  unsigned __int16 indices[6]; // [esp+44h] [ebp-64h] BYREF
  _BYTE v107[28]; // [esp+50h] [ebp-58h] BYREF
  float v108; // [esp+6Ch] [ebp-3Ch]
  D3D11_INPUT_ELEMENT_DESC screen_vertex_layout[2]; // [esp+70h] [ebp-38h] BYREF

  p_m_desc_cache_surface = (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>;
  this->m_context = context;
  this->m_renderer = in_renderer;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->__vftable = (vostok::render::stage_clouds_vtbl *)&stru_965008.m_rescale_min.elements[3];
  `vector constructor iterator'((char *)this->m_3d_clouds_density_texture, 4u, 2, p_m_desc_cache_surface);
  this->m_3d_clouds_density_texture_left.m_object = 0;
  this->m_3d_clouds_density_texture_right.m_object = 0;
  p_m_desc_cache_surface = (void *(__thiscall *)(void *))25;
  this->m_clouds_effect.m_object = 0;
  this->m_read_cloud_base_effect.m_object = 0;
  this->m_god_rays_effect.m_object = 0;
  this->m_ss_god_rays_effect.m_object = 0;
  vostok::render::sphere_geometry::sphere_geometry(
    v5,
    &this->m_evaluate_geometry,
    COERCE_FLOAT(25),
    (unsigned int)p_m_desc_cache_surface);
  vostok::render::environment_temp::environment_temp(v6, &this->m_environment.keys);
  M_start = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
  this->m_screen_vertex_ib.m_object = 0;
  this->m_screen_vertex_geometry.m_object = 0;
  this->m_clouds_size_x = M_start[27];
  this->m_clouds_size_y = M_start[28];
  this->m_clouds_size_z = M_start[27];
  this->m_tasks_type = vostok::tasks::create_new_task_type(&stru_964DF4.m_name.m_string.m_buffer[172], 0);
  this->m_parent_task.m_next_task_in_allocator = 0;
  this->m_parent_task.m_next_task_in_full_queue = 0;
  this->m_parent_task.m_children.m_size = 0;
  this->m_parent_task.m_children.m_first = 0;
  this->m_parent_task.m_children.m_last = 0;
  this->m_parent_task.m_child_counter = 0;
  this->m_parent_task.m_event_wait_for_children = 0;
  this->m_parent_task.m_function.vtable = 0;
  this->m_parent_task.m_ordinal = 0;
  this->m_parent_task.m_type = 0;
  this->m_parent_task.m_parent = 0;
  this->m_parent_task.m_state = 1;
  this->m_parent_task.m_reference_counter = 4;
  *(_QWORD *)&this->m_prev_right_vector.x = 0;
  v94 = 0;
  this->m_simulation = in_simulation;
  v95 = 0.0;
  this->m_first_tick = 1;
  this->m_interp_textures = in_interp_textures;
  this->m_x_rotation = 0.0;
  this->m_y_rotation = 0.0;
  this->m_prev_right_vector.z = 0.0;
  *(_QWORD *)&this->m_prev_up_vector.x = 0;
  m_clouds_size_x = (double)(int)this->m_clouds_size_x;
  *(_QWORD *)&this->m_wind_offset.x = 0;
  v9 = clear_value;
  *(_QWORD *)&this->m_wind_direction.x = (unsigned int)clear_value;
  this->m_prev_up_vector.z = 0.0;
  v94 = 0;
  v95 = 0.0;
  this->m_fixed_time = 0.0;
  this->m_wind_offset.z = 0.0;
  v10 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
  *(_QWORD *)&this->m_previous_view_position.x = 0;
  this->m_camera_offset = 0.0;
  LODWORD(this->m_wind_direction.z) = v9;
  v11 = this->m_clouds_size_x;
  this->m_clouds_scale_multiplier = 3000.0;
  this->m_need_generate = 0;
  this->m_previous_view_position.z = 0.0;
  this->m_clouds_scale_multiplier = *((float *)v10 + 13) * 3000.0;
  if ( v11 < 0 )
    m_clouds_size_x = m_clouds_size_x + 4294967300.0;
  m_clouds_size_y = this->m_clouds_size_y;
  *(float *)&v94 = m_clouds_size_x;
  v13 = (double)(int)this->m_clouds_size_y;
  if ( m_clouds_size_y < 0 )
    v13 = v13 + 4294967300.0;
  m_clouds_size_z = this->m_clouds_size_z;
  *((float *)&v94 + 1) = v13;
  v15 = (double)(int)this->m_clouds_size_z;
  if ( m_clouds_size_z < 0 )
    v15 = v15 + 4294967300.0;
  m_clouds_scale_multiplier = this->m_clouds_scale_multiplier;
  v95 = v15;
  *(float *)&v107[20] = m_clouds_scale_multiplier * *(float *)&v94;
  v108 = m_clouds_scale_multiplier * v95;
  v17 = m_clouds_scale_multiplier * v95;
  *(float *)&v107[24] = m_clouds_scale_multiplier * *((float *)&v94 + 1);
  v18 = 0;
  *(_QWORD *)&this->m_clouds_scale.x = *(_QWORD *)&v107[20];
  this->m_clouds_scale.z = v17;
  i = 0;
  do
  {
    v19 = &stru_964DF4.m_name.m_string.m_buffer[196];
    if ( v18 )
      v19 = &stru_964DF4.m_name.m_string.m_buffer[220];
    texture3d = vostok::render::resource_manager::create_texture3d(
                  0,
                  DXGI_FORMAT_R8G8B8A8_UNORM,
                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                  v19,
                  this->m_clouds_size_x,
                  this->m_clouds_size_y,
                  this->m_clouds_size_z,
                  D3D11_USAGE_DYNAMIC,
                  (unsigned int)v93);
    v21 = 0;
    if ( texture3d )
    {
      ++texture3d->m_reference_count;
      v21 = texture3d;
    }
    m_object = this->m_3d_clouds_density_texture[v18].m_object;
    this->m_3d_clouds_density_texture[v18].m_object = v21;
    if ( m_object )
    {
      v23 = m_object->m_reference_count-- == 1;
      if ( v23 && m_object->m_is_registered )
      {
        *(_DWORD *)v107 = m_object->m_name.m_string.m_begin;
        name.m_pointer.m_object = (vostok::strings::shared::profile *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7];
        v24 = (vostok::strings::shared::profile *)stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                                                    (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v107,
                                                    (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7],
                                                    (const char **)v107);
        if ( v24 != name.m_pointer.m_object )
        {
          stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
            (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&p_m_desc_cache_surface,
            (int)name.m_pointer.m_object,
            (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v24);
          vostok::render::resource_manager::release_impl(m_object, v93);
          v18 = i;
        }
      }
    }
    i = ++v18;
  }
  while ( v18 < 2 );
  v25 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)this->m_3d_clouds_density_texture[0].m_object;
  v26 = 0;
  if ( v25 )
  {
    v26 = this->m_3d_clouds_density_texture[0].m_object;
    ++v25->_M_header._M_data._M_parent;
  }
  v27 = this->m_3d_clouds_density_texture_left.m_object;
  this->m_3d_clouds_density_texture_left.m_object = v26;
  if ( v27 )
  {
    v23 = v27->m_reference_count-- == 1;
    if ( v23 && v27->m_is_registered )
    {
      v18 = (unsigned int)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7];
      *(_DWORD *)&v107[4] = v27->m_name.m_string.m_begin;
      v28 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
              v25,
              (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7],
              (const char **)&v107[4]);
      if ( v28 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v18 )
      {
        stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
          (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&p_m_desc_cache_surface,
          v18,
          (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v28);
        vostok::render::resource_manager::release_impl(v27, v93);
      }
    }
  }
  v29 = (vostok::render::stage_clouds *)this->m_3d_clouds_density_texture[1].m_object;
  v30 = 0;
  if ( v29 )
  {
    v30 = this->m_3d_clouds_density_texture[1].m_object;
    ++v29->m_context;
  }
  v31 = this->m_3d_clouds_density_texture_right.m_object;
  this->m_3d_clouds_density_texture_right.m_object = v30;
  if ( v31 )
  {
    v23 = v31->m_reference_count-- == 1;
    if ( v23 && v31->m_is_registered )
    {
      v18 = (unsigned int)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7];
      *(_DWORD *)&v107[8] = v31->m_name.m_string.m_begin;
      v32 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
              *(stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > **)&v107[8],
              (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7],
              (const char **)&v107[8]);
      if ( v32 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v18 )
      {
        stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
          (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&p_m_desc_cache_surface,
          v18,
          (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v32);
        vostok::render::resource_manager::release_impl(v31, v93);
      }
    }
  }
  m_scene = this->m_context->m_scene;
  if ( m_scene && m_scene->m_clouds )
  {
    LOBYTE(v18) = (_BYTE)this;
    vostok::render::stage_clouds::fill_cloud_texture(v29, this, 0);
    vostok::render::stage_clouds::fill_cloud_texture(v34, this, 1u);
  }
  v35 = this->m_3d_clouds_density_texture_left.m_object;
  m_interp_textures = this->m_interp_textures;
  v37 = 0;
  if ( v35 )
  {
    v37 = this->m_3d_clouds_density_texture_left.m_object;
    ++v35->m_reference_count;
  }
  v38 = m_interp_textures->cloud_density_0.m_object;
  m_interp_textures->cloud_density_0.m_object = v37;
  if ( v38 )
  {
    v23 = v38->m_reference_count-- == 1;
    if ( v23 && v38->m_is_registered )
    {
      v18 = (unsigned int)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7];
      *(_DWORD *)&v107[16] = v38->m_name.m_string.m_begin;
      v39 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
              *(stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > **)&v107[16],
              (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7],
              (const char **)&v107[16]);
      if ( v39 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v18 )
      {
        stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
          (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&p_m_desc_cache_surface,
          v18,
          (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v39);
        vostok::render::resource_manager::release_impl(v38, v93);
      }
    }
  }
  v40 = this->m_3d_clouds_density_texture_right.m_object;
  p_cloud_density_1 = &this->m_interp_textures->cloud_density_1;
  v42 = 0;
  if ( v40 )
  {
    v42 = this->m_3d_clouds_density_texture_right.m_object;
    ++v40->m_reference_count;
  }
  v43 = p_cloud_density_1->m_object;
  p_cloud_density_1->m_object = v42;
  if ( v43 )
  {
    v23 = v43->m_reference_count-- == 1;
    if ( v23 && v43->m_is_registered )
    {
      v18 = (unsigned int)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7];
      *(_DWORD *)&v107[12] = v43->m_name.m_string.m_begin;
      v44 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
              (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&v107[12],
              (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7],
              (const char **)&v107[12]);
      if ( v44 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v18 )
      {
        stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
          (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&p_m_desc_cache_surface,
          v18,
          (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v44);
        vostok::render::resource_manager::release_impl(v43, v93);
      }
    }
  }
  vostok::render::effect_manager::create_effect<vostok::render::effect_clouds>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_clouds_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_read_cloud_base>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_read_cloud_base_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_clouds_god_rays>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_god_rays_effect);
  p_m_desc_cache_surface = (void *(__thiscall *)(void *))&stru_964DF4.m_name.m_string.m_buffer[244];
  v46 = vostok::strings::shared::manager::string(v45, (const char *)s_manager.m_variable);
  p_m_reference_count = 0;
  i = 0;
  if ( v46 )
  {
    p_m_reference_count = &v46->m_reference_count;
    i = (unsigned int)v46;
    v47 = (vostok::render::backend *)_InterlockedExchangeAdd(&v46->m_reference_count, 1u);
  }
  this->m_c_sphere_to_sky_matrix = vostok::render::backend::register_constant_host(
                                     v47,
                                     (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                     (const vostok::shared_string *)&i,
                                     rc_float);
  if ( p_m_reference_count )
  {
    v49 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(p_m_reference_count, 0xFFFFFFFF);
    if ( !v49 )
    {
      p_m_desc_cache_surface = (void *(__thiscall *)(void *))p_m_reference_count;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  p_m_desc_cache_surface = (void *(__thiscall *)(void *))&stru_964DF4.m_desc_cache_surface;
  v50 = vostok::strings::shared::manager::string(v49, (const char *)s_manager.m_variable);
  v52 = 0;
  name.m_pointer.m_object = 0;
  if ( v50 )
  {
    v52 = &v50->m_reference_count;
    name.m_pointer.m_object = v50;
    v51 = (vostok::render::backend *)_InterlockedExchangeAdd(&v50->m_reference_count, 1u);
  }
  this->m_c_clouds_grid_size = vostok::render::backend::register_constant_host(
                                 v51,
                                 (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                 &name,
                                 rc_float);
  if ( v52 )
  {
    v53 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v52, 0xFFFFFFFF);
    if ( !v53 )
    {
      p_m_desc_cache_surface = (void *(__thiscall *)(void *))v52;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  p_m_desc_cache_surface = (void *(__thiscall *)(void *))"cloud_movement";
  v54 = vostok::strings::shared::manager::string(v53, (const char *)s_manager.m_variable);
  v56 = 0;
  v104.m_pointer.m_object = 0;
  if ( v54 )
  {
    v56 = &v54->m_reference_count;
    v104.m_pointer.m_object = v54;
    v55 = (vostok::render::backend *)_InterlockedExchangeAdd(&v54->m_reference_count, 1u);
  }
  this->m_c_cloud_movement = vostok::render::backend::register_constant_host(
                               v55,
                               (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                               &v104,
                               rc_float);
  if ( v56 )
  {
    v57 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v56, 0xFFFFFFFF);
    if ( !v57 )
    {
      p_m_desc_cache_surface = (void *(__thiscall *)(void *))v56;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  p_m_desc_cache_surface = (void *(__thiscall *)(void *))"interp_alpha";
  v58 = vostok::strings::shared::manager::string(v57, (const char *)s_manager.m_variable);
  v60 = 0;
  v105.m_pointer.m_object = 0;
  if ( v58 )
  {
    v60 = &v58->m_reference_count;
    v105.m_pointer.m_object = v58;
    v59 = (vostok::render::backend *)_InterlockedExchangeAdd(&v58->m_reference_count, 1u);
  }
  this->m_c_interp_alpha = vostok::render::backend::register_constant_host(
                             v59,
                             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                             &v105,
                             rc_float);
  if ( v60 )
  {
    v61 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v60, 0xFFFFFFFF);
    if ( !v61 )
    {
      p_m_desc_cache_surface = (void *(__thiscall *)(void *))v60;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  p_m_desc_cache_surface = (void *(__thiscall *)(void *))"clouds_offset";
  v62 = vostok::strings::shared::manager::string(v61, (const char *)s_manager.m_variable);
  v64 = 0;
  v102.m_pointer.m_object = 0;
  if ( v62 )
  {
    v64 = &v62->m_reference_count;
    v102.m_pointer.m_object = v62;
    v63 = (vostok::render::backend *)_InterlockedExchangeAdd(&v62->m_reference_count, 1u);
  }
  this->m_c_clouds_offset = vostok::render::backend::register_constant_host(
                              v63,
                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                              &v102,
                              rc_float);
  if ( v64 )
  {
    v65 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v64, 0xFFFFFFFF);
    if ( !v65 )
    {
      p_m_desc_cache_surface = (void *(__thiscall *)(void *))v64;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  p_m_desc_cache_surface = (void *(__thiscall *)(void *))&stru_962594.m_render_outputs._M_impl._M_end_of_storage;
  v66 = vostok::strings::shared::manager::string(v65, (const char *)s_manager.m_variable);
  v68 = 0;
  v101.m_pointer.m_object = 0;
  if ( v66 )
  {
    v68 = &v66->m_reference_count;
    v101.m_pointer.m_object = v66;
    v67 = (vostok::render::backend *)_InterlockedExchangeAdd(&v66->m_reference_count, 1u);
  }
  this->m_c_layer_height = vostok::render::backend::register_constant_host(
                             v67,
                             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                             &v101,
                             rc_float);
  if ( v68 )
  {
    v69 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v68, 0xFFFFFFFF);
    if ( !v69 )
    {
      p_m_desc_cache_surface = (void *(__thiscall *)(void *))v68;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  p_m_desc_cache_surface = (void *(__thiscall *)(void *))&stru_962594.m_sampler_lists._M_t._M_key_compare;
  v70 = vostok::strings::shared::manager::string(v69, (const char *)s_manager.m_variable);
  v72 = 0;
  v99.m_pointer.m_object = 0;
  if ( v70 )
  {
    v72 = &v70->m_reference_count;
    v99.m_pointer.m_object = v70;
    v71 = (vostok::render::backend *)_InterlockedExchangeAdd(&v70->m_reference_count, 1u);
  }
  this->m_c_cloud_base = vostok::render::backend::register_constant_host(
                           v71,
                           (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                           &v99,
                           rc_float);
  if ( v72 )
  {
    v73 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v72, 0xFFFFFFFF);
    if ( !v73 )
    {
      p_m_desc_cache_surface = (void *(__thiscall *)(void *))v72;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  p_m_desc_cache_surface = (void *(__thiscall *)(void *))"light_multiplier_parameters";
  v74 = vostok::strings::shared::manager::string(v73, (const char *)s_manager.m_variable);
  v76 = 0;
  v103.m_pointer.m_object = 0;
  if ( v74 )
  {
    v76 = &v74->m_reference_count;
    v103.m_pointer.m_object = v74;
    v75 = (vostok::render::backend *)_InterlockedExchangeAdd(&v74->m_reference_count, 1u);
  }
  this->m_c_light_multiplier_parameters = vostok::render::backend::register_constant_host(
                                            v75,
                                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                            &v103,
                                            rc_float);
  if ( v76 )
  {
    v77 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v76, 0xFFFFFFFF);
    if ( !v77 )
    {
      p_m_desc_cache_surface = (void *(__thiscall *)(void *))v76;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  p_m_desc_cache_surface = (void *(__thiscall *)(void *))"inverted_view_projection_matrix";
  v78 = vostok::strings::shared::manager::string(v77, (const char *)s_manager.m_variable);
  v80 = 0;
  v100.m_pointer.m_object = 0;
  if ( v78 )
  {
    v80 = &v78->m_reference_count;
    v100.m_pointer.m_object = v78;
    v79 = (vostok::render::backend *)_InterlockedExchangeAdd(&v78->m_reference_count, 1u);
  }
  this->m_c_inverted_view_projection_matrix = vostok::render::backend::register_constant_host(
                                                v79,
                                                (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                &v100,
                                                rc_float);
  if ( v80 )
  {
    v81 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v80, 0xFFFFFFFF);
    if ( !v81 )
    {
      p_m_desc_cache_surface = (void *(__thiscall *)(void *))v80;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  p_m_desc_cache_surface = (void *(__thiscall *)(void *))"to_sun_direction_parameter";
  v82 = vostok::strings::shared::manager::string(v81, (const char *)s_manager.m_variable);
  v84 = 0;
  v96.m_pointer.m_object = 0;
  if ( v82 )
  {
    v84 = (void *(__thiscall *)(void *))v82;
    v96.m_pointer.m_object = v82;
    v83 = (vostok::render::backend *)_InterlockedExchangeAdd(&v82->m_reference_count, 1u);
  }
  this->m_to_sun_direction_parameter = vostok::render::backend::register_constant_host(
                                         v83,
                                         (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                         &v96,
                                         rc_float);
  if ( v84 && !_InterlockedExchangeAdd((volatile signed __int32 *)v84, 0xFFFFFFFF) )
  {
    p_m_desc_cache_surface = v84;
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v85 = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 257);
  screen_vertex_layout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
  screen_vertex_layout[1].AlignedByteOffset = 16;
  this->m_enabled = v85;
  indices[1] = 1;
  indices[0] = 0;
  indices[2] = 2;
  indices[3] = 3;
  indices[4] = 2;
  screen_vertex_layout[0].SemanticName = "POSITION";
  screen_vertex_layout[0].SemanticIndex = 0;
  screen_vertex_layout[0].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
  screen_vertex_layout[0].InputSlot = 0;
  screen_vertex_layout[0].AlignedByteOffset = 0;
  screen_vertex_layout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  screen_vertex_layout[0].InstanceDataStepRate = 0;
  screen_vertex_layout[1].SemanticName = "TEXCOORD";
  screen_vertex_layout[1].SemanticIndex = 0;
  screen_vertex_layout[1].InputSlot = 0;
  screen_vertex_layout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  screen_vertex_layout[1].InstanceDataStepRate = 0;
  indices[5] = 1;
  buffer = vostok::render::resource_manager::create_buffer(
             0xCu,
             v18,
             (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
             indices,
             enum_buffer_type_index,
             0,
             0);
  v87 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v87 = buffer;
  }
  v88 = (vostok::render::res_state *)this->m_screen_vertex_ib.m_object;
  this->m_screen_vertex_ib.m_object = v87;
  if ( v88 )
  {
    v23 = v88->m_reference_count-- == 1;
    if ( v23 )
      vostok::render::resource_manager::release(
        v88,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  geometry = vostok::render::resource_manager::create_geometry(
               (stlp_std::forward_iterator_tag *)screen_vertex_layout,
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               2u,
               0x18u,
               *((vostok::render::untyped_buffer **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
               + 10),
               this->m_screen_vertex_ib.m_object);
  v90 = 0;
  if ( geometry )
  {
    ++geometry->m_reference_count;
    v90 = geometry;
  }
  v91 = this->m_screen_vertex_geometry.m_object;
  this->m_screen_vertex_geometry.m_object = v90;
  if ( v91 )
  {
    v23 = v91->m_reference_count-- == 1;
    if ( v23 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v91);
  }
}
