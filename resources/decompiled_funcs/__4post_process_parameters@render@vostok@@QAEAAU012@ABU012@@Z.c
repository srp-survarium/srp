vostok::render::post_process_parameters *__userpurge vostok::render::post_process_parameters::operator=@<eax>(
        const vostok::render::post_process_parameters *__that@<esi>,
        vostok::render::post_process_parameters *this)
{
  vostok::render::post_process_parameters *v2; // ebx
  vostok::render::res_texture *m_object; // eax
  vostok::render::res_texture *v4; // ecx
  const vostok::render::res_texture *v5; // ebp
  bool v6; // zf
  vostok::render::post_process_parameters *m_begin; // eax
  survarium::options_tab *v8; // edi
  stlp_std::priv::_Rb_tree_node_base *v9; // eax
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v10; // ecx
  vostok::render::res_texture *v11; // eax
  const vostok::render::res_texture *v12; // ebp
  unsigned int v13; // edx
  survarium::options_tab *v14; // edi
  stlp_std::priv::_Rb_tree_node_base *v15; // eax
  vostok::render::res_texture *v16; // ecx
  vostok::render::res_texture *v17; // eax
  const vostok::render::res_texture *v18; // ebp
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v19; // ecx
  survarium::options_tab *v20; // edi
  stlp_std::priv::_Rb_tree_node_base *v21; // eax
  vostok::render::res_texture *v22; // ecx
  vostok::render::res_texture *v23; // eax
  const vostok::render::res_texture *v24; // ebp
  char *v25; // eax
  survarium::options_tab *v26; // edi
  stlp_std::priv::_Rb_tree_node_base *v27; // eax
  stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > v29; // [esp-10h] [ebp-1Ch] BYREF
  char *v30; // [esp+8h] [ebp-4h] BYREF

  v2 = this;
  *(_QWORD *)&this->dof_height_lights.x = *(_QWORD *)&__that->dof_height_lights.x;
  v2->dof_height_lights.z = __that->dof_height_lights.z;
  v2->dof_focus_power = __that->dof_focus_power;
  v2->dof_focus_region = __that->dof_focus_region;
  v2->dof_focus_distance = __that->dof_focus_distance;
  v2->dof_far_blur_amount = __that->dof_far_blur_amount;
  v2->dof_near_blur_amount = __that->dof_near_blur_amount;
  v2->enable_dof = __that->enable_dof;
  v2->use_bokeh_dof = __that->use_bokeh_dof;
  v2->bokeh_dof_radius = __that->bokeh_dof_radius;
  v2->bokeh_dof_density = __that->bokeh_dof_density;
  v2->use_bokeh_image = __that->use_bokeh_image;
  v2->use_image_grain = __that->use_image_grain;
  v2->image_grain_scale = __that->image_grain_scale;
  v2->image_grain_update_frequency = __that->image_grain_update_frequency;
  v2->bloom_scale = __that->bloom_scale;
  v2->bloom_max_color = __that->bloom_max_color;
  v2->blur_kernel = __that->blur_kernel;
  v2->frame_dark_desaturation_limit = __that->frame_dark_desaturation_limit;
  v2->bloom_halo_color = __that->bloom_halo_color;
  v2->enable_bloom = __that->enable_bloom;
  v2->enable_ssao = __that->enable_ssao;
  v2->ssao_saturation = __that->ssao_saturation;
  v2->ssao_radius_scale = __that->ssao_radius_scale;
  v2->frame_desaturation = __that->frame_desaturation;
  v2->frame_height_lights = __that->frame_height_lights;
  v2->frame_mid_tones = __that->frame_mid_tones;
  v2->frame_shadows = __that->frame_shadows;
  v2->frame_fade_color = __that->frame_fade_color;
  v2->frame_fade_amount = __that->frame_fade_amount;
  v2->enable_scene = __that->enable_scene;
  v2->enable_advanced_bloom = __that->enable_advanced_bloom;
  v2->environment_sun_position = __that->environment_sun_position;
  v2->environment_far_fog_color = __that->environment_far_fog_color;
  v2->environment_ambient_color = __that->environment_ambient_color;
  v2->environment_sun_color = __that->environment_sun_color;
  v2->environment_far_fog_distance = __that->environment_far_fog_distance;
  v2->environment_near_fog_distance = __that->environment_near_fog_distance;
  v2->environment_shadow_transparency = __that->environment_shadow_transparency;
  v2->environment_fog_alpha = __that->environment_fog_alpha;
  v2->aberration_max_variance = __that->aberration_max_variance;
  v2->aberration_min_variance = __that->aberration_min_variance;
  v2->aberration_power = __that->aberration_power;
  v2->environment_skylight_lower_color = __that->environment_skylight_lower_color;
  v2->environment_skylight_upper_color = __that->environment_skylight_upper_color;
  v2->god_rays_color_0 = __that->god_rays_color_0;
  v2->god_rays_color_1 = __that->god_rays_color_1;
  v2->god_rays_color_blend_power = __that->god_rays_color_blend_power;
  v2->god_rays_intensity = __that->god_rays_intensity;
  v2->god_rays_attenuation_power = __that->god_rays_attenuation_power;
  v2->environment_rain_angle_x = __that->environment_rain_angle_x;
  v2->environment_rain_angle_y = __that->environment_rain_angle_y;
  v2->environment_rain_density = __that->environment_rain_density;
  v2->environment_rain_speed = __that->environment_rain_speed;
  v2->environment_use_rain = __that->environment_use_rain;
  v2->environment_skylight_parameters = __that->environment_skylight_parameters;
  v2->adaptation_speed = __that->adaptation_speed;
  v2->tonemap_bright_threshold = __that->tonemap_bright_threshold;
  v2->tonemap_median = __that->tonemap_median;
  v2->tonemap_darkness_threshold = __that->tonemap_darkness_threshold;
  v2->tonemap_middle_gray = __that->tonemap_middle_gray;
  v2->wind_direction = __that->wind_direction;
  v2->wind_strength = __that->wind_strength;
  v2->use_color_grading_lut = __that->use_color_grading_lut;
  *(_QWORD *)&v2->environment_skycolor[0].x = *(_QWORD *)&__that->environment_skycolor[0].x;
  *(_QWORD *)&v2->environment_skycolor[0].elements[2] = *(_QWORD *)&__that->environment_skycolor[0].elements[2];
  v2->environment_skycolor[1] = __that->environment_skycolor[1];
  v2->environment_skycolor[2] = __that->environment_skycolor[2];
  v2->environment_skycolor[3] = __that->environment_skycolor[3];
  v2->environment_skycolor[4] = __that->environment_skycolor[4];
  v2->environment_skycolor[5] = __that->environment_skycolor[5];
  v2->environment_suncolor = __that->environment_suncolor;
  v2->use_environment_skycolor = __that->use_environment_skycolor;
  m_object = __that->color_grading_texture.m_object;
  v4 = 0;
  if ( m_object )
  {
    v4 = __that->color_grading_texture.m_object;
    ++m_object->m_reference_count;
  }
  v5 = v2->color_grading_texture.m_object;
  v2->color_grading_texture.m_object = v4;
  if ( v5 )
  {
    v6 = v5->m_reference_count-- == 1;
    if ( v6 && v5->m_is_registered )
    {
      m_begin = (vostok::render::post_process_parameters *)v5->m_name.m_string.m_begin;
      *(_DWORD *)&v29._M_t._M_header._M_data._M_color = &this;
      v8 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
      this = m_begin;
      v9 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
             (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&this,
             (const char *const *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7]);
      if ( v9 != (stlp_std::priv::_Rb_tree_node_base *)v8 )
      {
        stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
          &v29,
          (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v9);
        vostok::render::resource_manager::release_impl(
          (vostok::render::resource_manager *)v29._M_t._M_header._M_data._M_parent,
          v5);
      }
    }
  }
  v10 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)__that->lens_flares_mask_texture.m_object;
  v11 = 0;
  if ( v10 )
  {
    v11 = __that->lens_flares_mask_texture.m_object;
    ++v10->_M_header._M_data._M_parent;
  }
  v12 = v2->lens_flares_mask_texture.m_object;
  v2->lens_flares_mask_texture.m_object = v11;
  if ( v12 )
  {
    v6 = v12->m_reference_count-- == 1;
    if ( v6 && v12->m_is_registered )
    {
      v13 = (unsigned int)v12->m_name.m_string.m_begin;
      *(_DWORD *)&v29._M_t._M_header._M_data._M_color = &v29._M_t._M_node_count;
      v14 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
      v29._M_t._M_node_count = v13;
      v15 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
              v10,
              (const char *const *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7]);
      if ( v15 != (stlp_std::priv::_Rb_tree_node_base *)v14 )
      {
        stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
          &v29,
          (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v15);
        vostok::render::resource_manager::release_impl(
          (vostok::render::resource_manager *)v29._M_t._M_header._M_data._M_parent,
          v12);
      }
    }
  }
  v16 = __that->sky_clouds_texture.m_object;
  v17 = 0;
  if ( v16 )
  {
    v17 = __that->sky_clouds_texture.m_object;
    ++v16->m_reference_count;
  }
  v18 = v2->sky_clouds_texture.m_object;
  v2->sky_clouds_texture.m_object = v17;
  if ( v18 )
  {
    v6 = v18->m_reference_count-- == 1;
    if ( v6 && v18->m_is_registered )
    {
      v19 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v18->m_name.m_string.m_begin;
      *(_DWORD *)&v29._M_t._M_header._M_data._M_color = &v29._M_t._M_key_compare;
      v20 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
      *(_DWORD *)&v29._M_t._M_key_compare.stlp_std::binary_function<char *,char *,bool> = v19;
      v21 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
              v19,
              (const char *const *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7]);
      if ( v21 != (stlp_std::priv::_Rb_tree_node_base *)v20 )
      {
        stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
          &v29,
          (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v21);
        vostok::render::resource_manager::release_impl(
          (vostok::render::resource_manager *)v29._M_t._M_header._M_data._M_parent,
          v18);
      }
    }
  }
  v22 = __that->sun_moon_texture.m_object;
  v23 = 0;
  if ( v22 )
  {
    v23 = __that->sun_moon_texture.m_object;
    ++v22->m_reference_count;
  }
  v24 = v2->sun_moon_texture.m_object;
  v2->sun_moon_texture.m_object = v23;
  if ( v24 )
  {
    v6 = v24->m_reference_count-- == 1;
    if ( v6 && v24->m_is_registered )
    {
      v25 = v24->m_name.m_string.m_begin;
      *(_DWORD *)&v29._M_t._M_header._M_data._M_color = &v30;
      v26 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
      v30 = v25;
      v27 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
              (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&v30,
              (const char *const *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7]);
      if ( v27 != (stlp_std::priv::_Rb_tree_node_base *)v26 )
      {
        stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
          &v29,
          (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v27);
        vostok::render::resource_manager::release_impl(
          (vostok::render::resource_manager *)v29._M_t._M_header._M_data._M_parent,
          v24);
      }
    }
  }
  v2->sun_moon_color = __that->sun_moon_color;
  v2->sun_moon_billboard_scale = __that->sun_moon_billboard_scale;
  v2->use_sun_moon_atmosphere_illumination = __that->use_sun_moon_atmosphere_illumination;
  v2->sky_clouds_u_tile = __that->sky_clouds_u_tile;
  v2->sky_clouds_color = __that->sky_clouds_color;
  v2->sky_clouds_fog_power = __that->sky_clouds_fog_power;
  v2->sky_clouds_fog_up_limit = __that->sky_clouds_fog_up_limit;
  v2->sky_clouds_rotation = __that->sky_clouds_rotation;
  v2->sky_clouds_blend_mode = __that->sky_clouds_blend_mode;
  v2->filmic_tonemap_shoulder_strength = __that->filmic_tonemap_shoulder_strength;
  v2->filmic_tonemap_linear_strength = __that->filmic_tonemap_linear_strength;
  v2->filmic_tonemap_linear_angle = __that->filmic_tonemap_linear_angle;
  v2->filmic_tonemap_toe_strength = __that->filmic_tonemap_toe_strength;
  v2->filmic_tonemap_toe_numerator = __that->filmic_tonemap_toe_numerator;
  v2->filmic_tonemap_toe_denominator = __that->filmic_tonemap_toe_denominator;
  v2->filmic_tonemap_liner_white = __that->filmic_tonemap_liner_white;
  v2->vignette_power = __that->vignette_power;
  v2->use_image_space_reflections = __that->use_image_space_reflections;
  v2->skylight_color = __that->skylight_color;
  v2->skylight_lower = __that->skylight_lower;
  v2->skylight_upper = __that->skylight_upper;
  v2->skylight_power = __that->skylight_power;
  v2->skylight_multiplier = __that->skylight_multiplier;
  v2->use_dynamic_lens_flares = __that->use_dynamic_lens_flares;
  v2->environment_probes_diffuse_instensity_multiplier = __that->environment_probes_diffuse_instensity_multiplier;
  v2->environment_probes_specular_instensity_multiplier = __that->environment_probes_specular_instensity_multiplier;
  v2->environment_rain_wet_intensity = __that->environment_rain_wet_intensity;
  v2->atmosphere_kresun_multiplier = __that->atmosphere_kresun_multiplier;
  v2->atmosphere_kmesun_multiplier = __that->atmosphere_kmesun_multiplier;
  v2->atmosphere_kr4pi_multiplier = __that->atmosphere_kr4pi_multiplier;
  v2->atmosphere_km4pi_multiplier = __that->atmosphere_km4pi_multiplier;
  v2->atmosphere_params_changed = __that->atmosphere_params_changed;
  v2->dof_blur_kernel = __that->dof_blur_kernel;
  v2->environment_rain_num_cones = __that->environment_rain_num_cones;
  v2->environment_rain_u_scale = __that->environment_rain_u_scale;
  v2->environment_rain_v_scale = __that->environment_rain_v_scale;
  v2->environment_rain_random_rotaion_speed = __that->environment_rain_random_rotaion_speed;
  v2->environment_rain_random_rotaion_radius = __that->environment_rain_random_rotaion_radius;
  v2->environment_rain_random_base_offset = __that->environment_rain_random_base_offset;
  v2->environment_rain_radius_scale = __that->environment_rain_radius_scale;
  v2->environment_rain_start_cone_index = __that->environment_rain_start_cone_index;
  v2->lens_flares_multiplier = __that->lens_flares_multiplier;
  v2->atmosphere_inscatter_distance = __that->atmosphere_inscatter_distance;
  v2->atmosphere_inscatter_power = __that->atmosphere_inscatter_power;
  v2->use_atmosphere_inscattering_on_geometry = __that->use_atmosphere_inscattering_on_geometry;
  v2->use_aberration = __that->use_aberration;
  return v2;
}
