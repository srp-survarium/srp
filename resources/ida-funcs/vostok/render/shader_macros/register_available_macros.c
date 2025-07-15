void __usercall vostok::render::shader_macros::register_available_macros(
        vostok::render::shader_macros *this@<ecx>,
        const char ***a2@<eax>)
{
  vostok::buffer_vector<char const *> *v3; // ecx
  vostok::buffer_vector<char const *> *v4; // ecx
  vostok::buffer_vector<char const *> *v5; // ecx
  vostok::buffer_vector<char const *> *v6; // ecx
  vostok::buffer_vector<char const *> *v7; // ecx
  vostok::buffer_vector<char const *> *v8; // ecx
  vostok::buffer_vector<char const *> *v9; // ecx
  vostok::buffer_vector<char const *> *v10; // ecx
  vostok::buffer_vector<char const *> *v11; // ecx
  vostok::buffer_vector<char const *> *v12; // ecx
  vostok::buffer_vector<char const *> *v13; // ecx
  vostok::buffer_vector<char const *> *v14; // ecx
  vostok::buffer_vector<char const *> *v15; // ecx
  vostok::buffer_vector<char const *> *v16; // ecx
  vostok::buffer_vector<char const *> *v17; // ecx
  vostok::buffer_vector<char const *> *v18; // ecx
  vostok::buffer_vector<char const *> *v19; // ecx
  vostok::buffer_vector<char const *> *v20; // ecx
  vostok::buffer_vector<char const *> *v21; // ecx
  vostok::buffer_vector<char const *> *v22; // ecx
  vostok::buffer_vector<char const *> *v23; // ecx
  vostok::buffer_vector<char const *> *v24; // ecx
  vostok::buffer_vector<char const *> *v25; // ecx
  vostok::buffer_vector<char const *> *v26; // ecx
  vostok::buffer_vector<char const *> *v27; // ecx
  vostok::buffer_vector<char const *> *v28; // ecx
  vostok::buffer_vector<char const *> *v29; // ecx
  vostok::buffer_vector<char const *> *v30; // ecx
  vostok::buffer_vector<char const *> *v31; // ecx
  vostok::buffer_vector<char const *> *v32; // ecx
  vostok::buffer_vector<char const *> *v33; // ecx
  vostok::buffer_vector<char const *> *v34; // ecx
  vostok::buffer_vector<char const *> *v35; // ecx
  vostok::buffer_vector<char const *> *v36; // ecx
  vostok::buffer_vector<char const *> *v37; // ecx
  vostok::buffer_vector<char const *> *v38; // ecx
  vostok::buffer_vector<char const *> *v39; // ecx
  vostok::buffer_vector<char const *> *v40; // ecx
  vostok::buffer_vector<char const *> *v41; // ecx
  vostok::buffer_vector<char const *> *v42; // ecx
  vostok::buffer_vector<char const *> *v43; // ecx
  vostok::buffer_vector<char const *> *v44; // ecx
  vostok::buffer_vector<char const *> *v45; // ecx
  vostok::buffer_vector<char const *> *v46; // ecx
  vostok::buffer_vector<char const *> *v47; // ecx
  vostok::buffer_vector<char const *> *v48; // ecx
  vostok::buffer_vector<char const *> *v49; // ecx
  vostok::buffer_vector<char const *> *v50; // ecx
  vostok::buffer_vector<char const *> *v51; // ecx
  vostok::buffer_vector<char const *> *v52; // ecx
  vostok::buffer_vector<char const *> *v53; // ecx
  vostok::buffer_vector<char const *> *v54; // ecx
  vostok::buffer_vector<char const *> *v55; // ecx
  vostok::buffer_vector<char const *> *v56; // ecx
  vostok::buffer_vector<char const *> *v57; // ecx
  vostok::buffer_vector<char const *> *v58; // ecx
  vostok::buffer_vector<char const *> *v59; // ecx
  vostok::buffer_vector<char const *> *v60; // ecx
  vostok::buffer_vector<char const *> *v61; // ecx
  vostok::buffer_vector<char const *> *v62; // ecx
  vostok::buffer_vector<char const *> *v63; // ecx
  vostok::buffer_vector<char const *> *v64; // ecx
  vostok::buffer_vector<char const *> *v65; // ecx
  vostok::render::shader_macros_dort_predicate *v66; // edi
  const char **v67; // esi
  int v68; // eax
  int v69; // ecx
  const char **__comp; // [esp+Ch] [ebp-4h]

  vostok::buffer_vector<char const *>::push_back(
    &this->m_available_macros,
    (int)a2,
    (const char **)&str_cfg_use_diffuse);
  vostok::buffer_vector<char const *>::push_back(v3, (int)a2, (const char **)&str_cfg_use_anisotropic_direction);
  vostok::buffer_vector<char const *>::push_back(v4, (int)a2, (const char **)&str_cfg_use_normal);
  vostok::buffer_vector<char const *>::push_back(v5, (int)a2, (const char **)&str_cfg_use_detail_normal);
  vostok::buffer_vector<char const *>::push_back(v6, (int)a2, (const char **)&str_cfg_use_alpha_test);
  vostok::buffer_vector<char const *>::push_back(v7, (int)a2, (const char **)&str_cfg_use_vertex_alpha_test);
  vostok::buffer_vector<char const *>::push_back(v8, (int)a2, (const char **)&str_cfg_use_parallax);
  vostok::buffer_vector<char const *>::push_back(v9, (int)a2, (const char **)&str_cfg_use_trancluency_texture);
  vostok::buffer_vector<char const *>::push_back(v10, (int)a2, (const char **)&str_cfg_use_specular_color_texture);
  vostok::buffer_vector<char const *>::push_back(v11, (int)a2, (const char **)&str_cfg_use_fresnel_texture);
  vostok::buffer_vector<char const *>::push_back(v12, (int)a2, (const char **)&str_cfg_use_roughness_texture);
  vostok::buffer_vector<char const *>::push_back(v13, (int)a2, (const char **)&str_cfg_use_emissive);
  vostok::buffer_vector<char const *>::push_back(v14, (int)a2, (const char **)&str_cfg_use_diffuse_power_texture);
  vostok::buffer_vector<char const *>::push_back(v15, (int)a2, (const char **)&str_cfg_use_detail);
  vostok::buffer_vector<char const *>::push_back(v16, (int)a2, (const char **)&str_cfg_use_alphablended_diffuse);
  vostok::buffer_vector<char const *>::push_back(v17, (int)a2, (const char **)&str_cfg_use_alphablended_normal);
  vostok::buffer_vector<char const *>::push_back(v18, (int)a2, (const char **)&str_cfg_use_vertex_blended_diffuse);
  vostok::buffer_vector<char const *>::push_back(v19, (int)a2, (const char **)&str_cfg_use_vertex_blended_mask);
  vostok::buffer_vector<char const *>::push_back(v20, (int)a2, (const char **)&str_cfg_use_vertex_blended_normal);
  vostok::buffer_vector<char const *>::push_back(v21, (int)a2, (const char **)&str_cfg_use_vertex_blended_specular);
  vostok::buffer_vector<char const *>::push_back(v22, (int)a2, (const char **)&str_cfg_use_detail_bump);
  vostok::buffer_vector<char const *>::push_back(v23, (int)a2, (const char **)&str_cfg_use_subuv);
  vostok::buffer_vector<char const *>::push_back(v24, (int)a2, (const char **)&str_cfg_use_reflection);
  vostok::buffer_vector<char const *>::push_back(v25, (int)a2, (const char **)&str_cfg_use_ttransparency);
  vostok::buffer_vector<char const *>::push_back(v26, (int)a2, (const char **)&str_cfg_use_grass_fresnel_effect);
  vostok::buffer_vector<char const *>::push_back(v27, (int)a2, (const char **)&str_cfg_light_type);
  vostok::buffer_vector<char const *>::push_back(v28, (int)a2, (const char **)&str_cfg_vertex_input_type);
  vostok::buffer_vector<char const *>::push_back(v29, (int)a2, (const char **)&str_cfg_post_process_blur_kernel);
  vostok::buffer_vector<char const *>::push_back(v30, (int)a2, (const char **)&str_cfg_lod_index);
  vostok::buffer_vector<char const *>::push_back(v31, (int)a2, (const char **)&str_cfg_use_specular_lighting);
  vostok::buffer_vector<char const *>::push_back(v32, (int)a2, (const char **)&str_cfg_use_instancing);
  vostok::buffer_vector<char const *>::push_back(v33, (int)a2, (const char **)&str_cfg_wind_motion);
  vostok::buffer_vector<char const *>::push_back(v34, (int)a2, (const char **)&str_cfg_num_used_terrain_layers);
  vostok::buffer_vector<char const *>::push_back(v35, (int)a2, (const char **)&str_cfg_used_terrain_height_mask);
  vostok::buffer_vector<char const *>::push_back(v36, (int)a2, (const char **)&str_cfg_use_variation_mask);
  vostok::buffer_vector<char const *>::push_back(v37, (int)a2, (const char **)&str_cfg_use_shadowed_light);
  vostok::buffer_vector<char const *>::push_back(v38, (int)a2, (const char **)&str_cfg_use_bokeh_dof);
  vostok::buffer_vector<char const *>::push_back(v39, (int)a2, (const char **)&str_cfg_use_bokeh_image);
  vostok::buffer_vector<char const *>::push_back(v40, (int)a2, (const char **)&str_cfg_lighting_model);
  vostok::buffer_vector<char const *>::push_back(v41, (int)a2, (const char **)&str_cfg_decal_material);
  vostok::buffer_vector<char const *>::push_back(v42, (int)a2, (const char **)&str_cfg_decal_type);
  vostok::buffer_vector<char const *>::push_back(v43, (int)a2, (const char **)&str_cfg_is_anisotropic_material);
  vostok::buffer_vector<char const *>::push_back(v44, (int)a2, (const char **)&str_cfg_use_ao_texture);
  vostok::buffer_vector<char const *>::push_back(v45, (int)a2, (const char **)&str_cfg_local_reflections);
  vostok::buffer_vector<char const *>::push_back(v46, (int)a2, (const char **)&str_cfg_use_indirect_specular);
  vostok::buffer_vector<char const *>::push_back(v47, (int)a2, (const char **)&str_cfg_use_image_grain);
  vostok::buffer_vector<char const *>::push_back(v48, (int)a2, (const char **)&str_cfg_env_probe_geometry_type);
  vostok::buffer_vector<char const *>::push_back(v49, (int)a2, (const char **)&str_cfg_use_diffuse_masked_color);
  vostok::buffer_vector<char const *>::push_back(v50, (int)a2, (const char **)&str_cfg_use_diffuse_masked_color_by_hue);
  vostok::buffer_vector<char const *>::push_back(v51, (int)a2, (const char **)&str_cfg_use_uv_scrolling);
  vostok::buffer_vector<char const *>::push_back(v52, (int)a2, (const char **)&str_cfg_use_normal_waves);
  vostok::buffer_vector<char const *>::push_back(v53, (int)a2, (const char **)&str_cfg_use_fuzziness);
  vostok::buffer_vector<char const *>::push_back(v54, (int)a2, (const char **)&str_cfg_terrain_blend_mode);
  vostok::buffer_vector<char const *>::push_back(v55, (int)a2, (const char **)&str_cfg_use_soft_edges);
  vostok::buffer_vector<char const *>::push_back(v56, (int)a2, (const char **)&str_cfg_use_thickness_map);
  vostok::buffer_vector<char const *>::push_back(
    v57,
    (int)a2,
    (const char **)&str_cfg_use_subsurface_scattering_mask_map);
  vostok::buffer_vector<char const *>::push_back(v58, (int)a2, (const char **)&str_cfg_use_displacement);
  vostok::buffer_vector<char const *>::push_back(v59, (int)a2, (const char **)&str_cfg_use_olta);
  vostok::buffer_vector<char const *>::push_back(
    v60,
    (int)a2,
    (const char **)&str_cfg_use_organic_scattering_amount_mask);
  vostok::buffer_vector<char const *>::push_back(
    v61,
    (int)a2,
    (const char **)&str_cfg_use_organic_scattering_depth_texture);
  vostok::buffer_vector<char const *>::push_back(
    v62,
    (int)a2,
    (const char **)&str_cfg_use_organic_back_illumination_texture);
  vostok::buffer_vector<char const *>::push_back(v63, (int)a2, (const char **)&str_cfg_use_organic_subdermal_texture);
  vostok::buffer_vector<char const *>::push_back(v64, (int)a2, (const char **)&str_cfg_use_sequence);
  vostok::buffer_vector<char const *>::push_back(v65, (int)a2, (const char **)&str_cfg_reflection_mask);
  LOBYTE(__comp) = 0;
  v66 = (vostok::render::shader_macros_dort_predicate *)a2[1];
  v67 = *a2;
  if ( v67 != (const char **)v66 )
  {
    v68 = (v66 - (vostok::render::shader_macros_dort_predicate *)v67) >> 2;
    v69 = 0;
    while ( v68 != 1 )
    {
      ++v69;
      v68 >>= 1;
    }
    stlp_std::priv::__introsort_loop<char const * *,char const *,int,vostok::render::shader_macros_dort_predicate>(
      v66,
      v67,
      (const char **)v66,
      0,
      2 * v69,
      __comp);
    stlp_std::priv::__final_insertion_sort<char const * *,vostok::render::shader_macros_dort_predicate>(
      v67,
      (const char **)v66,
      0);
  }
}
