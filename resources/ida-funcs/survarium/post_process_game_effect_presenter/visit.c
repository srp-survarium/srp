void __thiscall survarium::post_process_game_effect_presenter::visit(
        survarium::post_process_game_effect_presenter *this,
        const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *effect,
        const survarium::game_effect_state *state)
{
  float current_time; // xmm0_4
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v4; // edi
  int v6; // ecx
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v7; // edi
  float v8; // xmm0_4
  float w; // xmm3_4
  float y; // xmm1_4
  float z; // xmm2_4
  float current_weight; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm4_4
  bool use_sun_moon_texture; // al
  float v17; // xmm5_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float x; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm3_4
  float god_rays_color_blend_power; // xmm0_4
  float v27; // xmm5_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  float sky_clouds_color_multiplier; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm5_4
  float v36; // xmm0_4
  float sky_clouds_fog_power; // xmm0_4
  float v38; // xmm4_4
  float v39; // xmm3_4
  float rayleigh_fog_far_distance; // xmm0_4
  float v41; // xmm3_4
  float v42; // xmm4_4
  float mie_fog_far_distance; // xmm0_4
  float v44; // xmm4_4
  float v45; // xmm3_4
  float v46; // xmm4_4
  float v47; // xmm3_4
  float height_based_ambient_low_limit; // xmm0_4
  double rain_num_cones; // st7
  float v50; // xmm4_4
  float v51; // xmm0_4
  float v52; // xmm1_4
  float wind_strength; // xmm4_4
  float v54; // xmm3_4
  float v55; // xmm6_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  double image_grain_update_frequency; // st7
  double blur_kernel; // st7
  float v60; // xmm5_4
  float v61; // xmm2_4
  float v62; // xmm3_4
  float v63; // xmm0_4
  double dof_blur_kernel; // st7
  float v65; // [esp+0h] [ebp-294h]
  float v66; // [esp+0h] [ebp-294h]
  float v67; // [esp+0h] [ebp-294h]
  float v68; // [esp+0h] [ebp-294h]
  vostok::render::environment_properties *v69; // [esp+0h] [ebp-294h]
  float *i; // [esp+14h] [ebp-280h]
  float *color_grading_weights; // [esp+14h] [ebp-280h]
  survarium::pure_game_effect_emitter_base_vtbl *v72; // [esp+18h] [ebp-27Ch]
  unsigned int v73; // [esp+18h] [ebp-27Ch]
  unsigned int num_color_grading_textures; // [esp+1Ch] [ebp-278h]
  vostok::math::float3_pod result_in_case_of_zero; // [esp+20h] [ebp-274h] BYREF
  vostok::render::environment_properties v76; // [esp+2Ch] [ebp-268h] BYREF

  current_time = state->current_time;
  v4 = effect;
  v6 = 0;
  v72 = effect[13].m_object->__vftable;
  for ( i = (float *)&v72[38].increase_quality_to_target; ; i += 155 )
  {
    if ( *(i - 155) == current_time )
    {
      vostok::render::environment_properties::environment_properties(
        (vostok::render::environment_properties *)((char *)v72 + 620 * v6),
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v76,
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)v72
      + 155 * v6);
      goto LABEL_7;
    }
    if ( *i > current_time )
      break;
    ++v6;
  }
  vostok::math::lerp<vostok::render::environment_properties>(
    &v76,
    (const vostok::render::environment_properties *)((char *)v72 + 620 * v6),
    (const vostok::render::environment_properties *)(&v72[19].unlink_child_resource + 155 * v6),
    COERCE_CONST_VOSTOK_MATH_FLOAT3_(
      (float)(current_time - *((float *)&v72[19].link_child_resource + 155 * v6))
    / (float)(*((float *)&v72[38].increase_quality_to_target + 155 * v6)
            - *((float *)&v72[19].link_child_resource + 155 * v6))));
LABEL_7:
  if ( effect[7].m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      effect + 7,
      &this->m_result.sun_moon_texture);
    v4 = effect;
  }
  if ( v4[8].m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      v4 + 8,
      &this->m_result.sky_clouds_texture);
    v4 = effect;
  }
  if ( v4[9].m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      v4 + 9,
      &this->m_result.stratosphere_texture);
    v4 = effect;
  }
  if ( v4[10].m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      v4 + 10,
      &this->m_result.sky_shadows_texture);
    v4 = effect;
  }
  if ( v4[11].m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      v4 + 11,
      &this->m_result.lens_flares_mask_texture);
    v4 = effect;
  }
  v73 = 0;
  if ( v76.num_color_grading_textures )
  {
    v7 = v4 + 12;
    color_grading_weights = v76.color_grading_weights;
    do
    {
      num_color_grading_textures = this->m_result.num_color_grading_textures;
      this->m_result.num_color_grading_textures = num_color_grading_textures + 1;
      vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
        v7,
        &this->m_result.color_grading_textures[num_color_grading_textures]);
      ++v73;
      v8 = *color_grading_weights++ * state->current_weight;
      this->m_result.color_grading_weights[num_color_grading_textures] = v8;
    }
    while ( v73 < v76.num_color_grading_textures );
  }
  w = v76.sun_color.w;
  y = v76.sun_color.y;
  z = v76.sun_color.z;
  this->m_result.sun_position_azimut = (float)(v76.sun_position_azimut * state->current_weight)
                                     + this->m_result.sun_position_azimut;
  this->m_result.sun_angle = (float)(v76.sun_angle * state->current_weight) + this->m_result.sun_angle;
  this->m_result.sun_intensity = (float)(v76.sun_intensity * state->current_weight) + this->m_result.sun_intensity;
  current_weight = state->current_weight;
  v13 = (float)(y * current_weight) + this->m_result.sun_color.y;
  v14 = (float)(z * current_weight) + this->m_result.sun_color.z;
  v15 = (float)(w * current_weight) + this->m_result.sun_color.w;
  this->m_result.sun_color.x = (float)(v76.sun_color.x * current_weight) + this->m_result.sun_color.x;
  this->m_result.sun_color.y = v13;
  this->m_result.sun_color.z = v14;
  this->m_result.sun_color.w = v15;
  this->m_sun_color_weight = (float)(w * state->current_weight) + this->m_sun_color_weight;
  if ( v76.sun_shadow_rain )
    this->m_result.sun_shadow_rain = v76.sun_shadow_rain;
  use_sun_moon_texture = v76.use_sun_moon_texture;
  this->m_result.sun_shadow_filter_radius = (float)(v76.sun_shadow_filter_radius * state->current_weight)
                                          + this->m_result.sun_shadow_filter_radius;
  this->m_result.sun_shadow_penumbra = (float)(v76.sun_shadow_penumbra * state->current_weight)
                                     + this->m_result.sun_shadow_penumbra;
  if ( use_sun_moon_texture )
    this->m_result.use_sun_moon_texture = use_sun_moon_texture;
  this->m_result.sun_moon_billboard_scale = (float)(v76.sun_moon_billboard_scale * state->current_weight)
                                          + this->m_result.sun_moon_billboard_scale;
  v17 = state->current_weight;
  v18 = v76.god_rays_color_1.w;
  v19 = v76.god_rays_color_1.y;
  v20 = v76.god_rays_color_1.z;
  this->m_result.god_rays_color_1.x = (float)(v76.god_rays_color_1.x * v17) + this->m_result.god_rays_color_1.x;
  x = v76.god_rays_color_2.x;
  this->m_result.god_rays_color_1.y = (float)(v19 * v17) + this->m_result.god_rays_color_1.y;
  v22 = v76.god_rays_color_2.y;
  this->m_result.god_rays_color_1.z = (float)(v20 * v17) + this->m_result.god_rays_color_1.z;
  v23 = v76.god_rays_color_2.z;
  this->m_result.god_rays_color_1.w = (float)(v18 * v17) + this->m_result.god_rays_color_1.w;
  this->m_god_rays_color_1_weight = (float)(v18 * state->current_weight) + this->m_god_rays_color_1_weight;
  v24 = state->current_weight;
  v25 = v76.god_rays_color_2.w;
  this->m_result.god_rays_color_2.x = (float)(x * v24) + this->m_result.god_rays_color_2.x;
  god_rays_color_blend_power = v76.god_rays_color_blend_power;
  this->m_result.god_rays_color_2.y = (float)(v22 * v24) + this->m_result.god_rays_color_2.y;
  this->m_result.god_rays_color_2.z = (float)(v23 * v24) + this->m_result.god_rays_color_2.z;
  this->m_result.god_rays_color_2.w = (float)(v25 * v24) + this->m_result.god_rays_color_2.w;
  this->m_god_rays_color_2_weight = (float)(v25 * state->current_weight) + this->m_god_rays_color_2_weight;
  this->m_result.god_rays_color_blend_power = (float)(god_rays_color_blend_power * state->current_weight)
                                            + this->m_result.god_rays_color_blend_power;
  this->m_result.god_rays_intensity = (float)(v76.god_rays_intensity * state->current_weight)
                                    + this->m_result.god_rays_intensity;
  this->m_result.god_rays_attenuation = (float)(v76.god_rays_attenuation * state->current_weight)
                                      + this->m_result.god_rays_attenuation;
  this->m_result.atmosphere_rayleighSun_multiplier = (float)(v76.atmosphere_rayleighSun_multiplier
                                                           * state->current_weight)
                                                   + this->m_result.atmosphere_rayleighSun_multiplier;
  this->m_result.atmosphere_mieSun_multiplier = (float)(v76.atmosphere_mieSun_multiplier * state->current_weight)
                                              + this->m_result.atmosphere_mieSun_multiplier;
  this->m_result.atmosphere_rayleighPi_multiplier = (float)(v76.atmosphere_rayleighPi_multiplier * state->current_weight)
                                                  + this->m_result.atmosphere_rayleighPi_multiplier;
  this->m_result.atmosphere_miePi_multiplier = (float)(v76.atmosphere_miePi_multiplier * state->current_weight)
                                             + this->m_result.atmosphere_miePi_multiplier;
  if ( v76.atmosphere_use_sun_illumination )
    this->m_result.atmosphere_use_sun_illumination = v76.atmosphere_use_sun_illumination;
  if ( v76.use_sky_clouds )
    this->m_result.use_sky_clouds = v76.use_sky_clouds;
  this->m_result.sky_clouds_rotation = (float)(v76.sky_clouds_rotation * state->current_weight)
                                     + this->m_result.sky_clouds_rotation;
  this->m_result.sky_clouds_rotation_speed = (float)(v76.sky_clouds_rotation_speed * state->current_weight)
                                           + this->m_result.sky_clouds_rotation_speed;
  if ( v76.use_stratosphere )
    this->m_result.use_stratosphere = v76.use_stratosphere;
  this->m_result.stratosphere_rotation = (float)(v76.stratosphere_rotation * state->current_weight)
                                       + this->m_result.stratosphere_rotation;
  this->m_result.stratosphere_rotation_speed = (float)(v76.stratosphere_rotation_speed * state->current_weight)
                                             + this->m_result.stratosphere_rotation_speed;
  if ( v76.sky_clouds_blend_mode )
    this->m_result.sky_clouds_blend_mode = v76.sky_clouds_blend_mode;
  v27 = state->current_weight;
  v28 = v76.sky_clouds_color.y;
  v29 = v76.sky_clouds_color.z;
  v30 = v76.sky_clouds_color.w;
  this->m_result.sky_clouds_color.x = (float)(v76.sky_clouds_color.x * v27) + this->m_result.sky_clouds_color.x;
  sky_clouds_color_multiplier = v76.sky_clouds_color_multiplier;
  this->m_result.sky_clouds_color.y = (float)(v28 * v27) + this->m_result.sky_clouds_color.y;
  v32 = v76.sky_clouds_fog_color.y;
  this->m_result.sky_clouds_color.z = (float)(v29 * v27) + this->m_result.sky_clouds_color.z;
  v33 = v76.sky_clouds_fog_color.z;
  this->m_result.sky_clouds_color.w = (float)(v30 * v27) + this->m_result.sky_clouds_color.w;
  this->m_sky_clouds_color_weight = (float)(v30 * state->current_weight) + this->m_sky_clouds_color_weight;
  v34 = v76.sky_clouds_fog_color.w;
  this->m_result.sky_clouds_color_multiplier = (float)(sky_clouds_color_multiplier * state->current_weight)
                                             + this->m_result.sky_clouds_color_multiplier;
  v35 = state->current_weight;
  v36 = v76.sky_clouds_fog_color.x;
  this->m_result.sky_clouds_fog_color.y = (float)(v32 * v35) + this->m_result.sky_clouds_fog_color.y;
  this->m_result.sky_clouds_fog_color.x = (float)(v36 * v35) + this->m_result.sky_clouds_fog_color.x;
  sky_clouds_fog_power = v76.sky_clouds_fog_power;
  this->m_result.sky_clouds_fog_color.z = (float)(v33 * v35) + this->m_result.sky_clouds_fog_color.z;
  this->m_result.sky_clouds_fog_color.w = (float)(v34 * v35) + this->m_result.sky_clouds_fog_color.w;
  this->m_sky_clouds_fog_color_weight = (float)(v34 * state->current_weight) + this->m_sky_clouds_fog_color_weight;
  this->m_result.sky_clouds_fog_power = (float)(sky_clouds_fog_power * state->current_weight)
                                      + this->m_result.sky_clouds_fog_power;
  this->m_result.sky_clouds_fog_up_limit = (float)(v76.sky_clouds_fog_up_limit * state->current_weight)
                                         + this->m_result.sky_clouds_fog_up_limit;
  if ( v76.use_sky_shadows )
    this->m_result.use_sky_shadows = v76.use_sky_shadows;
  this->m_result.sky_shadows_moving_x = (float)(v76.sky_shadows_moving_x * state->current_weight)
                                      + this->m_result.sky_shadows_moving_x;
  this->m_result.sky_shadows_moving_y = (float)(v76.sky_shadows_moving_y * state->current_weight)
                                      + this->m_result.sky_shadows_moving_y;
  this->m_result.sky_shadows_tiling = (float)(v76.sky_shadows_tiling * state->current_weight)
                                    + this->m_result.sky_shadows_tiling;
  if ( v76.use_sky_clouds_lighting )
    this->m_result.use_sky_clouds_lighting = v76.use_sky_clouds_lighting;
  v38 = state->current_weight;
  v39 = v76.rayleigh_fog_color.w;
  this->m_result.rayleigh_fog_color.y = (float)(v38 * v76.rayleigh_fog_color.y) + this->m_result.rayleigh_fog_color.y;
  this->m_result.rayleigh_fog_color.z = (float)(v38 * v76.rayleigh_fog_color.z) + this->m_result.rayleigh_fog_color.z;
  this->m_result.rayleigh_fog_color.x = (float)(v38 * v76.rayleigh_fog_color.x) + this->m_result.rayleigh_fog_color.x;
  rayleigh_fog_far_distance = v76.rayleigh_fog_far_distance;
  this->m_result.rayleigh_fog_color.w = (float)(v38 * v39) + this->m_result.rayleigh_fog_color.w;
  this->m_rayleigh_fog_color_weight = (float)(v39 * state->current_weight) + this->m_rayleigh_fog_color_weight;
  v41 = v76.mie_fog_color.w;
  this->m_result.rayleigh_fog_far_distance = (float)(rayleigh_fog_far_distance * state->current_weight)
                                           + this->m_result.rayleigh_fog_far_distance;
  this->m_result.rayleigh_fog_near_distance = (float)(v76.rayleigh_fog_near_distance * state->current_weight)
                                            + this->m_result.rayleigh_fog_near_distance;
  this->m_result.rayleigh_fog_density = (float)(v76.rayleigh_fog_density * state->current_weight)
                                      + this->m_result.rayleigh_fog_density;
  v42 = state->current_weight;
  this->m_result.mie_fog_color.y = (float)(v42 * v76.mie_fog_color.y) + this->m_result.mie_fog_color.y;
  this->m_result.mie_fog_color.z = (float)(v42 * v76.mie_fog_color.z) + this->m_result.mie_fog_color.z;
  this->m_result.mie_fog_color.x = (float)(v42 * v76.mie_fog_color.x) + this->m_result.mie_fog_color.x;
  mie_fog_far_distance = v76.mie_fog_far_distance;
  this->m_result.mie_fog_color.w = (float)(v42 * v41) + this->m_result.mie_fog_color.w;
  this->m_mie_fog_color_weight = (float)(v41 * state->current_weight) + this->m_mie_fog_color_weight;
  this->m_result.mie_fog_far_distance = (float)(mie_fog_far_distance * state->current_weight)
                                      + this->m_result.mie_fog_far_distance;
  this->m_result.mie_fog_near_distance = (float)(v76.mie_fog_near_distance * state->current_weight)
                                       + this->m_result.mie_fog_near_distance;
  this->m_result.mie_fog_density = (float)(v76.mie_fog_density * state->current_weight) + this->m_result.mie_fog_density;
  this->m_result.mie_fog_bias = (float)(v76.mie_fog_bias * state->current_weight) + this->m_result.mie_fog_bias;
  this->m_result.mie_fog_falloff = (float)(v76.mie_fog_falloff * state->current_weight) + this->m_result.mie_fog_falloff;
  if ( v76.use_ambient_occlusion )
    this->m_result.use_ambient_occlusion = v76.use_ambient_occlusion;
  this->m_result.ao_saturation = (float)(v76.ao_saturation * state->current_weight) + this->m_result.ao_saturation;
  this->m_result.ao_radius = (float)(v76.ao_radius * state->current_weight) + this->m_result.ao_radius;
  this->m_result.environment_probes_diffuse_intensity_multiplier = (float)(v76.environment_probes_diffuse_intensity_multiplier
                                                                         * state->current_weight)
                                                                 + this->m_result.environment_probes_diffuse_intensity_multiplier;
  this->m_result.environment_probes_specular_intensity_multiplier = (float)(v76.environment_probes_specular_intensity_multiplier
                                                                          * state->current_weight)
                                                                  + this->m_result.environment_probes_specular_intensity_multiplier;
  if ( v76.use_height_based_ambient )
    this->m_result.use_height_based_ambient = v76.use_height_based_ambient;
  v44 = state->current_weight;
  v45 = v76.height_based_ambient_low_color.w;
  this->m_result.height_based_ambient_low_color.y = (float)(v44 * v76.height_based_ambient_low_color.y)
                                                  + this->m_result.height_based_ambient_low_color.y;
  this->m_result.height_based_ambient_low_color.z = (float)(v44 * v76.height_based_ambient_low_color.z)
                                                  + this->m_result.height_based_ambient_low_color.z;
  this->m_result.height_based_ambient_low_color.x = (float)(v44 * v76.height_based_ambient_low_color.x)
                                                  + this->m_result.height_based_ambient_low_color.x;
  this->m_result.height_based_ambient_low_color.w = (float)(v44 * v45) + this->m_result.height_based_ambient_low_color.w;
  this->m_height_based_ambient_low_color_weight = (float)(v45 * state->current_weight)
                                                + this->m_height_based_ambient_low_color_weight;
  v46 = state->current_weight;
  v47 = v76.height_based_ambient_high_color.w;
  this->m_result.height_based_ambient_high_color.y = (float)(v46 * v76.height_based_ambient_high_color.y)
                                                   + this->m_result.height_based_ambient_high_color.y;
  this->m_result.height_based_ambient_high_color.z = (float)(v46 * v76.height_based_ambient_high_color.z)
                                                   + this->m_result.height_based_ambient_high_color.z;
  this->m_result.height_based_ambient_high_color.x = (float)(v46 * v76.height_based_ambient_high_color.x)
                                                   + this->m_result.height_based_ambient_high_color.x;
  height_based_ambient_low_limit = v76.height_based_ambient_low_limit;
  this->m_result.height_based_ambient_high_color.w = (float)(v46 * v47)
                                                   + this->m_result.height_based_ambient_high_color.w;
  this->m_height_based_ambient_high_color_weight = (float)(v47 * state->current_weight)
                                                 + this->m_height_based_ambient_high_color_weight;
  this->m_result.height_based_ambient_low_limit = (float)(height_based_ambient_low_limit * state->current_weight)
                                                + this->m_result.height_based_ambient_low_limit;
  this->m_result.height_based_ambient_high_limit = (float)(v76.height_based_ambient_high_limit * state->current_weight)
                                                 + this->m_result.height_based_ambient_high_limit;
  this->m_result.height_based_ambient_power = (float)(v76.height_based_ambient_power * state->current_weight)
                                            + this->m_result.height_based_ambient_power;
  if ( v76.use_rain )
    this->m_result.use_rain = v76.use_rain;
  rain_num_cones = (double)v76.rain_num_cones;
  this->m_result.rain_surface_intensity = (float)(v76.rain_surface_intensity * state->current_weight)
                                        + this->m_result.rain_surface_intensity;
  this->m_result.rain_angle_x = (float)(v76.rain_angle_x * state->current_weight) + this->m_result.rain_angle_x;
  this->m_result.rain_angle_y = (float)(v76.rain_angle_y * state->current_weight) + this->m_result.rain_angle_y;
  this->m_result.rain_speed = (float)(v76.rain_speed * state->current_weight) + this->m_result.rain_speed;
  this->m_result.rain_density = (float)(v76.rain_density * state->current_weight) + this->m_result.rain_density;
  v65 = rain_num_cones * state->current_weight + 0.5;
  this->m_result.rain_num_cones += vostok::math::floor(v65);
  this->m_result.rain_u_scale = (float)(v76.rain_u_scale * state->current_weight) + this->m_result.rain_u_scale;
  this->m_result.rain_v_scale = (float)(v76.rain_v_scale * state->current_weight) + this->m_result.rain_v_scale;
  this->m_result.rain_random_rotation_speed = (float)(v76.rain_random_rotation_speed * state->current_weight)
                                            + this->m_result.rain_random_rotation_speed;
  this->m_result.rain_random_rotation_radius = (float)(v76.rain_random_rotation_radius * state->current_weight)
                                             + this->m_result.rain_random_rotation_radius;
  this->m_result.rain_random_base_offset = (float)(v76.rain_random_base_offset * state->current_weight)
                                         + this->m_result.rain_random_base_offset;
  this->m_result.rain_radius_scale = (float)(v76.rain_radius_scale * state->current_weight)
                                   + this->m_result.rain_radius_scale;
  if ( v76.rain_start_cone_index )
    this->m_result.rain_start_cone_index = v76.rain_start_cone_index;
  v50 = state->current_weight;
  v51 = (float)(v76.wind_direction.y * v76.wind_strength) * v50;
  v52 = (float)(v76.wind_direction.z * v76.wind_strength) * v50;
  wind_strength = this->m_result.wind_strength;
  v54 = state->current_weight * (float)(v76.wind_strength * v76.wind_direction.x);
  v55 = v52;
  v56 = this->m_result.wind_direction.z;
  v57 = wind_strength * this->m_result.wind_direction.x;
  result_in_case_of_zero.y = (float)(this->m_result.wind_direction.y * wind_strength) + v51;
  result_in_case_of_zero.z = (float)(v56 * wind_strength) + v55;
  this->m_result.wind_direction.x = v57 + v54;
  *(_QWORD *)&this->m_result.wind_direction.elements[1] = *(_QWORD *)&result_in_case_of_zero.elements[1];
  *(_QWORD *)&result_in_case_of_zero.x = 0;
  result_in_case_of_zero.z = s_bm_current_air_resistance;
  this->m_result.wind_strength = vostok::math::float3_pod::normalize_safe_r(
                                   &result_in_case_of_zero,
                                   &this->m_result.wind_direction.x,
                                   &result_in_case_of_zero);
  this->m_result.eye_adaptation_speed = (float)(v76.eye_adaptation_speed * state->current_weight)
                                      + this->m_result.eye_adaptation_speed;
  if ( v76.use_color_grading_texture )
    this->m_result.use_color_grading_texture = v76.use_color_grading_texture;
  this->m_result.blueshift = (float)(v76.blueshift * state->current_weight) + this->m_result.blueshift;
  this->m_result.vignette_effect_power = (float)(v76.vignette_effect_power * state->current_weight)
                                       + this->m_result.vignette_effect_power;
  if ( v76.use_dynamic_lens_flare )
    this->m_result.use_dynamic_lens_flare = v76.use_dynamic_lens_flare;
  this->m_result.lens_flares_multiplier = (float)(v76.lens_flares_multiplier * state->current_weight)
                                        + this->m_result.lens_flares_multiplier;
  if ( v76.use_image_grain )
    this->m_result.use_image_grain = v76.use_image_grain;
  image_grain_update_frequency = (double)v76.image_grain_update_frequency;
  this->m_result.image_grain_intensity = (float)(v76.image_grain_intensity * state->current_weight)
                                       + this->m_result.image_grain_intensity;
  v66 = image_grain_update_frequency * state->current_weight + 0.5;
  this->m_result.image_grain_update_frequency += vostok::math::floor(v66);
  if ( v76.use_aberration )
    this->m_result.use_aberration = v76.use_aberration;
  this->m_result.aberration_amount = (float)(v76.aberration_amount * state->current_weight)
                                   + this->m_result.aberration_amount;
  this->m_result.aberration_red = (float)(v76.aberration_red * state->current_weight) + this->m_result.aberration_red;
  this->m_result.aberration_blue = (float)(v76.aberration_blue * state->current_weight) + this->m_result.aberration_blue;
  if ( v76.use_sharpen )
    this->m_result.use_sharpen = v76.use_sharpen;
  blur_kernel = (double)v76.blur_kernel;
  this->m_result.sharpen_amount = (float)(v76.sharpen_amount * state->current_weight) + this->m_result.sharpen_amount;
  this->m_result.bloom_intensity = (float)(v76.bloom_intensity * state->current_weight) + this->m_result.bloom_intensity;
  this->m_result.bloom_ratio = (float)(v76.bloom_ratio * state->current_weight) + this->m_result.bloom_ratio;
  v67 = blur_kernel * state->current_weight + 0.5;
  this->m_result.blur_kernel += vostok::math::floor(v67);
  v60 = state->current_weight;
  v61 = v76.bloom_color.z;
  v62 = v76.bloom_color.w;
  v63 = v76.bloom_color.x;
  this->m_result.bloom_color.y = (float)(v76.bloom_color.y * v60) + this->m_result.bloom_color.y;
  this->m_result.bloom_color.z = (float)(v61 * v60) + this->m_result.bloom_color.z;
  this->m_result.bloom_color.w = (float)(v62 * v60) + this->m_result.bloom_color.w;
  this->m_result.bloom_color.x = (float)(v63 * v60) + this->m_result.bloom_color.x;
  this->m_bloom_color_weight = (float)(v62 * state->current_weight) + this->m_bloom_color_weight;
  if ( v76.use_bokeh_dof )
    this->m_result.use_bokeh_dof = v76.use_bokeh_dof;
  this->m_result.bokeh_radius = (float)(v76.bokeh_radius * state->current_weight) + this->m_result.bokeh_radius;
  this->m_result.bokeh_density = (float)(v76.bokeh_density * state->current_weight) + this->m_result.bokeh_density;
  if ( v76.use_bokeh_template_image )
    this->m_result.use_bokeh_template_image = v76.use_bokeh_template_image;
  dof_blur_kernel = (double)v76.dof_blur_kernel;
  this->m_result.dof_focus_region = (float)(v76.dof_focus_region * state->current_weight)
                                  + this->m_result.dof_focus_region;
  this->m_result.dof_focus_distance = (float)(v76.dof_focus_distance * state->current_weight)
                                    + this->m_result.dof_focus_distance;
  v68 = dof_blur_kernel * state->current_weight + 0.5;
  this->m_result.dof_blur_kernel += vostok::math::floor(v68);
  this->m_result.dof_near_blurness_amount = (float)(v76.dof_near_blurness_amount * state->current_weight)
                                          + this->m_result.dof_near_blurness_amount;
  this->m_result.dof_far_blurness_amount = (float)(v76.dof_far_blurness_amount * state->current_weight)
                                         + this->m_result.dof_far_blurness_amount;
  if ( v76.use_radial_blur )
    this->m_result.use_radial_blur = v76.use_radial_blur;
  if ( v76.use_channel_blur )
    this->m_result.use_channel_blur = v76.use_channel_blur;
  this->m_result.channel_blur_amount = (float)(v76.channel_blur_amount * state->current_weight)
                                     + this->m_result.channel_blur_amount;
  this->m_result.channel_blur_power = (float)(v76.channel_blur_power * state->current_weight)
                                    + this->m_result.channel_blur_power;
  this->m_result.radial_blur_intensity = (float)(v76.radial_blur_intensity * state->current_weight)
                                       + this->m_result.radial_blur_intensity;
  this->m_result.radial_blur_amount = (float)(v76.radial_blur_amount * state->current_weight)
                                    + this->m_result.radial_blur_amount;
  this->m_result.radial_blur_power = (float)(v76.radial_blur_power * state->current_weight)
                                   + this->m_result.radial_blur_power;
  vostok::render::environment_properties::~environment_properties(
    v69,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v76);
}
