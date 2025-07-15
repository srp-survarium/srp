void __usercall vostok::render::shader_macros::register_available_macros(
        vostok::render::shader_macros *this@<ecx>,
        vostok::buffer_vector<void const *> *a2@<eax>)
{
  const char **m_end; // edi
  const char **m_begin; // esi
  int v5; // eax
  int i; // ecx
  const char **__comp; // [esp+8h] [ebp-4h]

  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_global_use_branching);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_global_allow_steepparallax);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_global_master_gold);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_global_num_max_light_instances);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_global_cascaded_shadow_map_size);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_global_use_god_rays);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_global_shadowmap_size);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_global_spot_shadowmap_size);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_post_process_quality);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_lighting_quality);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(a2, (const void **)&str_shading_quality);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(a2, (const void **)&str_cfg_use_diffuse);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_anisotropic_direction);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(a2, (const void **)&str_cfg_use_normal);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_detail_normal);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_alpha_test);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_parallax);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_trancluency_texture);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_specular_color_texture);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_fresnel_texture);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_roughness_texture);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_emissive);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_diffuse_power_texture);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(a2, (const void **)&str_cfg_use_detail);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_alphablended_diffuse);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_alphablended_normal);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_vertex_blended_diffuse);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_vertex_blended_mask);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_vertex_blended_normal);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_vertex_blended_specular);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_detail_bump);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(a2, (const void **)&str_cfg_use_subuv);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_reflection);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_ttransparency);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_grass_fresnel_effect);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(a2, (const void **)&str_cfg_light_type);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_vertex_input_type);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_post_process_blur_kernel);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(a2, (const void **)&str_cfg_lod_index);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_specular_lighting);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(a2, (const void **)&str_cfg_wind_motion);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_bound_normals);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_up_directional_normals);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_diffuse_as_specular);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_num_used_terrain_layers);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_used_terrain_height_mask);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_variation_mask);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_shadowed_light);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_bokeh_dof);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_bokeh_image);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_lighting_model);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_decal_material);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(a2, (const void **)&str_cfg_decal_type);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_is_anisotropic_material);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_ao_texture);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_local_reflections);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_indirect_specular);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_image_grain);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_env_probe_clip_by_normal);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_env_probe_with_shadows);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_env_probe_geometry_type);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_diffuse_masked_color);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_diffuse_masked_color_by_hue);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_uv_scrolling);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_normal_waves);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_fuzziness);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_terrain_blend_mode);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_soft_edges);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_thickness_map);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_subsurface_scattering_mask_map);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(a2, (const void **)&str_cfg_use_olta);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_organic_scattering_amount_mask);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_organic_scattering_depth_texture);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_organic_back_illumination_texture);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_organic_subdermal_texture);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_use_sequence);
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    a2,
    (const void **)&str_cfg_reflection_mask);
  m_end = (const char **)a2->m_end;
  m_begin = (const char **)a2->m_begin;
  LOBYTE(__comp) = 0;
  if ( m_begin != m_end )
  {
    v5 = m_end - m_begin;
    for ( i = 0; v5 != 1; ++i )
      v5 >>= 1;
    stlp_std::priv::__introsort_loop<char const * *,char const *,int,vostok::render::shader_macros_dort_predicate>(
      (vostok::render::shader_macros_dort_predicate)m_end,
      m_begin,
      m_end,
      0,
      2 * i,
      __comp);
    stlp_std::priv::__final_insertion_sort<char const * *,vostok::render::shader_macros_dort_predicate>(
      m_begin,
      m_end,
      0);
  }
}
