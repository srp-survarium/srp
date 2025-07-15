vostok::render::environment_properties *__cdecl vostok::math::lerp<vostok::render::environment_properties>(
        vostok::render::environment_properties *result,
        const vostok::render::environment_properties *left,
        const vostok::render::environment_properties *right,
        const vostok::math::float3 *t)
{
  vostok::render::environment_properties *v4; // ecx
  unsigned int num_color_grading_textures; // eax
  float *color_grading_weights; // ecx
  float v8; // xmm1_4
  float v9; // xmm2_4
  float x; // xmm5_4
  float z; // xmm4_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float w; // xmm7_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm7_4
  float v21; // xmm4_4
  float v22; // xmm1_4
  float v23; // xmm5_4
  float v24; // xmm5_4
  float v25; // xmm4_4
  float v26; // xmm1_4
  float v27; // xmm3_4
  float v28; // xmm7_4
  float v29; // xmm3_4
  float v30; // xmm4_4
  float v31; // xmm7_4
  float v32; // xmm3_4
  float v33; // xmm4_4
  float v34; // xmm1_4
  float v35; // xmm5_4
  float v36; // xmm5_4
  float v37; // xmm4_4
  float v38; // xmm1_4
  float v39; // xmm3_4
  float v40; // xmm7_4
  float v41; // xmm3_4
  float v42; // xmm4_4
  float v43; // xmm5_4
  float v44; // xmm1_4
  float y; // xmm6_4
  float v46; // xmm2_4
  float v47; // xmm7_4
  float v48; // xmm4_4
  float v49; // xmm3_4
  float v50; // xmm7_4
  float v51; // xmm4_4
  float v52; // xmm7_4
  float v53; // xmm3_4
  float v54; // xmm5_4
  float v55; // xmm4_4
  float v56; // xmm5_4
  float v57; // xmm4_4
  float v58; // xmm1_4
  float v59; // xmm3_4
  float v60; // xmm7_4
  float v61; // xmm3_4
  float v62; // xmm4_4
  float v63; // xmm1_4
  float v64; // xmm3_4
  float v65; // xmm2_4
  float v66; // xmm6_4
  float v68; // [esp+4h] [ebp-34h]
  float v69; // [esp+4h] [ebp-34h]
  float v70; // [esp+4h] [ebp-34h]
  float v71; // [esp+4h] [ebp-34h]
  vostok::math::float4 v72; // [esp+18h] [ebp-20h] BYREF
  float v73[3]; // [esp+28h] [ebp-10h] BYREF
  unsigned int v74; // [esp+34h] [ebp-4h]
  float v75; // [esp+44h] [ebp+Ch]
  float v76; // [esp+44h] [ebp+Ch]

  vostok::render::environment_properties::environment_properties(v4, (int)result, 0);
  num_color_grading_textures = left->num_color_grading_textures;
  v74 = 0;
  result->num_color_grading_textures = num_color_grading_textures;
  if ( num_color_grading_textures )
  {
    color_grading_weights = left->color_grading_weights;
    do
    {
      v8 = *color_grading_weights;
      v9 = *(float *)((char *)color_grading_weights + (char *)right - (char *)left);
      ++v74;
      *(float *)((char *)color_grading_weights++ + (char *)result - (char *)left) = (float)((float)(v9 - v8)
                                                                                          * *(float *)&t)
                                                                                  + v8;
    }
    while ( v74 < result->num_color_grading_textures );
  }
  result->sun_position_azimut = (float)((float)(right->sun_position_azimut - left->sun_position_azimut) * *(float *)&t)
                              + left->sun_position_azimut;
  result->sun_angle = (float)((float)(right->sun_angle - left->sun_angle) * *(float *)&t) + left->sun_angle;
  result->sun_intensity = (float)((float)(right->sun_intensity - left->sun_intensity) * *(float *)&t)
                        + left->sun_intensity;
  x = left->sun_color.x;
  z = left->sun_color.z;
  v12 = right->sun_color.x;
  v13 = right->sun_color.z;
  w = left->sun_color.w;
  v72.y = (float)((float)(right->sun_color.y - left->sun_color.y) * *(float *)&t) + left->sun_color.y;
  v15 = v13 - z;
  v16 = right->sun_color.w;
  v72.z = (float)(v15 * *(float *)&t) + left->sun_color.z;
  v72.w = (float)((float)(v16 - w) * *(float *)&t) + w;
  result->sun_color.x = (float)((float)(v12 - x) * *(float *)&t) + x;
  *(_QWORD *)&result->sun_color.elements[1] = *(_QWORD *)&v72.elements[1];
  result->sun_color.w = v72.w;
  result->sun_shadow_rain = left->sun_shadow_rain;
  result->sun_shadow_filter_radius = (float)((float)(right->sun_shadow_filter_radius - left->sun_shadow_filter_radius)
                                           * *(float *)&t)
                                   + left->sun_shadow_filter_radius;
  result->sun_shadow_penumbra = (float)((float)(right->sun_shadow_penumbra - left->sun_shadow_penumbra) * *(float *)&t)
                              + left->sun_shadow_penumbra;
  result->use_sun_moon_texture = left->use_sun_moon_texture;
  result->sun_moon_billboard_scale = (float)((float)(right->sun_moon_billboard_scale - left->sun_moon_billboard_scale)
                                           * *(float *)&t)
                                   + left->sun_moon_billboard_scale;
  v17 = left->god_rays_color_1.x;
  v18 = right->god_rays_color_1.x - v17;
  v19 = right->god_rays_color_1.z - left->god_rays_color_1.z;
  v20 = left->god_rays_color_1.w;
  v21 = right->god_rays_color_1.w;
  v72.y = (float)((float)(right->god_rays_color_1.y - left->god_rays_color_1.y) * *(float *)&t)
        + left->god_rays_color_1.y;
  v22 = (float)(v18 * *(float *)&t) + v17;
  v23 = left->god_rays_color_1.z;
  v72.w = (float)((float)(v21 - v20) * *(float *)&t) + v20;
  v72.z = (float)(v19 * *(float *)&t) + v23;
  result->god_rays_color_1.x = v22;
  *(_QWORD *)&result->god_rays_color_1.elements[1] = *(_QWORD *)&v72.elements[1];
  result->god_rays_color_1.w = v72.w;
  v24 = left->god_rays_color_2.x;
  v25 = left->god_rays_color_2.z;
  v26 = right->god_rays_color_2.x;
  v27 = right->god_rays_color_2.z;
  v28 = left->god_rays_color_2.w;
  v72.y = (float)((float)(right->god_rays_color_2.y - left->god_rays_color_2.y) * *(float *)&t)
        + left->god_rays_color_2.y;
  v29 = v27 - v25;
  v30 = right->god_rays_color_2.w;
  v72.z = (float)(v29 * *(float *)&t) + left->god_rays_color_2.z;
  v72.w = (float)((float)(v30 - v28) * *(float *)&t) + v28;
  result->god_rays_color_2.x = (float)((float)(v26 - v24) * *(float *)&t) + v24;
  *(_QWORD *)&result->god_rays_color_2.elements[1] = *(_QWORD *)&v72.elements[1];
  result->god_rays_color_2.w = v72.w;
  result->god_rays_color_blend_power = (float)((float)(right->god_rays_color_blend_power
                                                     - left->god_rays_color_blend_power)
                                             * *(float *)&t)
                                     + left->god_rays_color_blend_power;
  result->god_rays_intensity = (float)((float)(right->god_rays_intensity - left->god_rays_intensity) * *(float *)&t)
                             + left->god_rays_intensity;
  result->god_rays_attenuation = (float)((float)(right->god_rays_attenuation - left->god_rays_attenuation) * *(float *)&t)
                               + left->god_rays_attenuation;
  result->atmosphere_rayleighSun_multiplier = (float)((float)(right->atmosphere_rayleighSun_multiplier
                                                            - left->atmosphere_rayleighSun_multiplier)
                                                    * *(float *)&t)
                                            + left->atmosphere_rayleighSun_multiplier;
  result->atmosphere_mieSun_multiplier = (float)((float)(right->atmosphere_mieSun_multiplier
                                                       - left->atmosphere_mieSun_multiplier)
                                               * *(float *)&t)
                                       + left->atmosphere_mieSun_multiplier;
  result->atmosphere_rayleighPi_multiplier = (float)((float)(right->atmosphere_rayleighPi_multiplier
                                                           - left->atmosphere_rayleighPi_multiplier)
                                                   * *(float *)&t)
                                           + left->atmosphere_rayleighPi_multiplier;
  result->atmosphere_miePi_multiplier = (float)((float)(right->atmosphere_miePi_multiplier
                                                      - left->atmosphere_miePi_multiplier)
                                              * *(float *)&t)
                                      + left->atmosphere_miePi_multiplier;
  result->atmosphere_use_sun_illumination = left->atmosphere_use_sun_illumination;
  result->use_sky_clouds = left->use_sky_clouds;
  result->sky_clouds_rotation = (float)((float)(right->sky_clouds_rotation - left->sky_clouds_rotation) * *(float *)&t)
                              + left->sky_clouds_rotation;
  result->sky_clouds_rotation_speed = (float)((float)(right->sky_clouds_rotation_speed - left->sky_clouds_rotation_speed)
                                            * *(float *)&t)
                                    + left->sky_clouds_rotation_speed;
  result->use_stratosphere = left->use_stratosphere;
  result->stratosphere_rotation = (float)((float)(right->stratosphere_rotation - left->stratosphere_rotation)
                                        * *(float *)&t)
                                + left->stratosphere_rotation;
  result->stratosphere_rotation_speed = (float)((float)(right->stratosphere_rotation_speed
                                                      - left->stratosphere_rotation_speed)
                                              * *(float *)&t)
                                      + left->stratosphere_rotation_speed;
  v31 = left->sky_clouds_color.w;
  v32 = right->sky_clouds_color.z - left->sky_clouds_color.z;
  v33 = right->sky_clouds_color.w;
  v34 = (float)((float)(right->sky_clouds_color.x - left->sky_clouds_color.x) * *(float *)&t) + left->sky_clouds_color.x;
  v35 = left->sky_clouds_color.z;
  v72.y = (float)((float)(right->sky_clouds_color.y - left->sky_clouds_color.y) * *(float *)&t)
        + left->sky_clouds_color.y;
  v72.z = (float)(v32 * *(float *)&t) + v35;
  v72.w = (float)((float)(v33 - v31) * *(float *)&t) + v31;
  result->sky_clouds_color.x = v34;
  *(_QWORD *)&result->sky_clouds_color.elements[1] = *(_QWORD *)&v72.elements[1];
  result->sky_clouds_color.w = v72.w;
  result->sky_clouds_color_multiplier = (float)((float)(right->sky_clouds_color_multiplier
                                                      - left->sky_clouds_color_multiplier)
                                              * *(float *)&t)
                                      + left->sky_clouds_color_multiplier;
  v36 = left->sky_clouds_fog_color.x;
  v37 = left->sky_clouds_fog_color.z;
  v38 = right->sky_clouds_fog_color.x;
  v39 = right->sky_clouds_fog_color.z;
  v40 = left->sky_clouds_fog_color.w;
  v72.y = (float)((float)(right->sky_clouds_fog_color.y - left->sky_clouds_fog_color.y) * *(float *)&t)
        + left->sky_clouds_fog_color.y;
  v41 = v39 - v37;
  v42 = right->sky_clouds_fog_color.w;
  v72.z = (float)(v41 * *(float *)&t) + left->sky_clouds_fog_color.z;
  v72.w = (float)((float)(v42 - v40) * *(float *)&t) + v40;
  result->sky_clouds_fog_color.x = (float)((float)(v38 - v36) * *(float *)&t) + v36;
  *(_QWORD *)&result->sky_clouds_fog_color.elements[1] = *(_QWORD *)&v72.elements[1];
  result->sky_clouds_fog_color.w = v72.w;
  result->sky_clouds_fog_power = (float)((float)(right->sky_clouds_fog_power - left->sky_clouds_fog_power) * *(float *)&t)
                               + left->sky_clouds_fog_power;
  result->sky_clouds_fog_up_limit = (float)((float)(right->sky_clouds_fog_up_limit - left->sky_clouds_fog_up_limit)
                                          * *(float *)&t)
                                  + left->sky_clouds_fog_up_limit;
  result->use_sky_shadows = left->use_sky_shadows;
  result->sky_shadows_moving_x = (float)((float)(right->sky_shadows_moving_x - left->sky_shadows_moving_x) * *(float *)&t)
                               + left->sky_shadows_moving_x;
  result->sky_shadows_moving_y = (float)((float)(right->sky_shadows_moving_y - left->sky_shadows_moving_y) * *(float *)&t)
                               + left->sky_shadows_moving_y;
  result->sky_shadows_tiling = (float)((float)(right->sky_shadows_tiling - left->sky_shadows_tiling) * *(float *)&t)
                             + left->sky_shadows_tiling;
  result->use_sky_clouds_lighting = left->use_sky_clouds_lighting;
  v43 = left->rayleigh_fog_color.x;
  v44 = right->rayleigh_fog_color.x;
  y = left->rayleigh_fog_color.y;
  v46 = right->rayleigh_fog_color.y;
  v47 = left->rayleigh_fog_color.w;
  v48 = right->rayleigh_fog_color.w - v47;
  v72.z = left->rayleigh_fog_color.z
        + (float)((float)(right->rayleigh_fog_color.z - left->rayleigh_fog_color.z) * *(float *)&t);
  v72.y = y + (float)((float)(v46 - y) * *(float *)&t);
  v72.w = v47 + (float)(v48 * *(float *)&t);
  result->rayleigh_fog_color.x = v43 + (float)((float)(v44 - v43) * *(float *)&t);
  *(_QWORD *)&result->rayleigh_fog_color.elements[1] = *(_QWORD *)&v72.elements[1];
  result->rayleigh_fog_color.w = v72.w;
  result->rayleigh_fog_far_distance = (float)((float)(right->rayleigh_fog_far_distance - left->rayleigh_fog_far_distance)
                                            * *(float *)&t)
                                    + left->rayleigh_fog_far_distance;
  result->rayleigh_fog_near_distance = (float)((float)(right->rayleigh_fog_near_distance
                                                     - left->rayleigh_fog_near_distance)
                                             * *(float *)&t)
                                     + left->rayleigh_fog_near_distance;
  result->rayleigh_fog_density = (float)((float)(right->rayleigh_fog_density - left->rayleigh_fog_density) * *(float *)&t)
                               + left->rayleigh_fog_density;
  v49 = right->mie_fog_color.z;
  v50 = left->mie_fog_color.w;
  v75 = left->mie_fog_color.z;
  v51 = right->mie_fog_color.w - v50;
  v72.x = left->mie_fog_color.x + (float)((float)(right->mie_fog_color.x - left->mie_fog_color.x) * *(float *)&t);
  v72.y = left->mie_fog_color.y + (float)((float)(right->mie_fog_color.y - left->mie_fog_color.y) * *(float *)&t);
  v72.z = v75 + (float)((float)(v49 - v75) * *(float *)&t);
  v72.w = v50 + (float)(v51 * *(float *)&t);
  result->mie_fog_color = v72;
  result->mie_fog_far_distance = (float)((float)(right->mie_fog_far_distance - left->mie_fog_far_distance) * *(float *)&t)
                               + left->mie_fog_far_distance;
  result->mie_fog_near_distance = (float)((float)(right->mie_fog_near_distance - left->mie_fog_near_distance)
                                        * *(float *)&t)
                                + left->mie_fog_near_distance;
  result->mie_fog_density = (float)((float)(right->mie_fog_density - left->mie_fog_density) * *(float *)&t)
                          + left->mie_fog_density;
  result->mie_fog_bias = (float)((float)(right->mie_fog_bias - left->mie_fog_bias) * *(float *)&t) + left->mie_fog_bias;
  result->mie_fog_falloff = (float)((float)(right->mie_fog_falloff - left->mie_fog_falloff) * *(float *)&t)
                          + left->mie_fog_falloff;
  result->use_ambient_occlusion = left->use_ambient_occlusion;
  result->ao_saturation = (float)((float)(right->ao_saturation - left->ao_saturation) * *(float *)&t)
                        + left->ao_saturation;
  result->ao_radius = (float)((float)(right->ao_radius - left->ao_radius) * *(float *)&t) + left->ao_radius;
  result->environment_probes_diffuse_intensity_multiplier = (float)((float)(right->environment_probes_diffuse_intensity_multiplier
                                                                          - left->environment_probes_diffuse_intensity_multiplier)
                                                                  * *(float *)&t)
                                                          + left->environment_probes_diffuse_intensity_multiplier;
  result->environment_probes_specular_intensity_multiplier = (float)((float)(right->environment_probes_specular_intensity_multiplier
                                                                           - left->environment_probes_specular_intensity_multiplier)
                                                                   * *(float *)&t)
                                                           + left->environment_probes_specular_intensity_multiplier;
  result->use_height_based_ambient = left->use_height_based_ambient;
  v52 = left->height_based_ambient_low_color.w;
  v53 = right->height_based_ambient_low_color.z - left->height_based_ambient_low_color.z;
  v54 = left->height_based_ambient_low_color.z;
  v55 = right->height_based_ambient_low_color.w - v52;
  v72.x = (float)((float)(right->height_based_ambient_low_color.x - left->height_based_ambient_low_color.x)
                * *(float *)&t)
        + left->height_based_ambient_low_color.x;
  v72.y = (float)((float)(right->height_based_ambient_low_color.y - left->height_based_ambient_low_color.y)
                * *(float *)&t)
        + left->height_based_ambient_low_color.y;
  v72.z = (float)(v53 * *(float *)&t) + v54;
  v72.w = (float)(v55 * *(float *)&t) + v52;
  result->height_based_ambient_low_color = v72;
  v56 = left->height_based_ambient_high_color.x;
  v57 = left->height_based_ambient_high_color.z;
  v58 = right->height_based_ambient_high_color.x - v56;
  v59 = right->height_based_ambient_high_color.z;
  v60 = left->height_based_ambient_high_color.w;
  v72.y = (float)((float)(right->height_based_ambient_high_color.y - left->height_based_ambient_high_color.y)
                * *(float *)&t)
        + left->height_based_ambient_high_color.y;
  v61 = v59 - v57;
  v62 = right->height_based_ambient_high_color.w;
  v72.z = (float)(v61 * *(float *)&t) + left->height_based_ambient_high_color.z;
  v72.w = (float)((float)(v62 - v60) * *(float *)&t) + v60;
  result->height_based_ambient_high_color.x = (float)(v58 * *(float *)&t) + v56;
  *(_QWORD *)&result->height_based_ambient_high_color.elements[1] = *(_QWORD *)&v72.elements[1];
  result->height_based_ambient_high_color.w = v72.w;
  result->height_based_ambient_low_limit = (float)((float)(right->height_based_ambient_low_limit
                                                         - left->height_based_ambient_low_limit)
                                                 * *(float *)&t)
                                         + left->height_based_ambient_low_limit;
  result->height_based_ambient_high_limit = (float)((float)(right->height_based_ambient_high_limit
                                                          - left->height_based_ambient_high_limit)
                                                  * *(float *)&t)
                                          + left->height_based_ambient_high_limit;
  result->height_based_ambient_power = (float)((float)(right->height_based_ambient_power
                                                     - left->height_based_ambient_power)
                                             * *(float *)&t)
                                     + left->height_based_ambient_power;
  result->use_rain = left->use_rain;
  result->rain_surface_intensity = (float)((float)(right->rain_surface_intensity - left->rain_surface_intensity)
                                         * *(float *)&t)
                                 + left->rain_surface_intensity;
  result->rain_angle_x = (float)((float)(right->rain_angle_x - left->rain_angle_x) * *(float *)&t) + left->rain_angle_x;
  result->rain_angle_y = (float)((float)(right->rain_angle_y - left->rain_angle_y) * *(float *)&t) + left->rain_angle_y;
  result->rain_speed = (float)((float)(right->rain_speed - left->rain_speed) * *(float *)&t) + left->rain_speed;
  result->rain_density = (float)((float)(right->rain_density - left->rain_density) * *(float *)&t) + left->rain_density;
  v68 = (double)left->rain_num_cones
      + ((double)right->rain_num_cones - (double)left->rain_num_cones) * *(float *)&t
      + 0.5;
  result->rain_num_cones = vostok::math::floor(v68);
  result->rain_u_scale = (float)((float)(right->rain_u_scale - left->rain_u_scale) * *(float *)&t) + left->rain_u_scale;
  result->rain_v_scale = (float)((float)(right->rain_v_scale - left->rain_v_scale) * *(float *)&t) + left->rain_v_scale;
  result->rain_random_rotation_speed = (float)((float)(right->rain_random_rotation_speed
                                                     - left->rain_random_rotation_speed)
                                             * *(float *)&t)
                                     + left->rain_random_rotation_speed;
  result->rain_random_rotation_radius = (float)((float)(right->rain_random_rotation_radius
                                                      - left->rain_random_rotation_radius)
                                              * *(float *)&t)
                                      + left->rain_random_rotation_radius;
  result->rain_random_base_offset = (float)((float)(right->rain_random_base_offset - left->rain_random_base_offset)
                                          * *(float *)&t)
                                  + left->rain_random_base_offset;
  v63 = s_bm_current_air_resistance;
  result->rain_radius_scale = (float)((float)(right->rain_radius_scale - left->rain_radius_scale) * *(float *)&t)
                            + left->rain_radius_scale;
  result->rain_start_cone_index = left->rain_start_cone_index;
  v73[0] = 0.0;
  v73[1] = v63;
  v73[2] = 0.0;
  result->wind_direction = *vostok::math::slerp(
                              &left->wind_direction,
                              &right->wind_direction,
                              (vostok::math::float3 *)&v72.elements[1],
                              t,
                              v73);
  result->wind_strength = (float)((float)(right->wind_strength - left->wind_strength) * *(float *)&t)
                        + left->wind_strength;
  result->eye_adaptation_speed = (float)((float)(right->eye_adaptation_speed - left->eye_adaptation_speed) * *(float *)&t)
                               + left->eye_adaptation_speed;
  result->use_color_grading_texture = left->use_color_grading_texture;
  result->blueshift = (float)((float)(right->blueshift - left->blueshift) * *(float *)&t) + left->blueshift;
  result->vignette_effect_power = (float)((float)(right->vignette_effect_power - left->vignette_effect_power)
                                        * *(float *)&t)
                                + left->vignette_effect_power;
  result->use_dynamic_lens_flare = left->use_dynamic_lens_flare;
  result->lens_flares_multiplier = (float)((float)(right->lens_flares_multiplier - left->lens_flares_multiplier)
                                         * *(float *)&t)
                                 + left->lens_flares_multiplier;
  result->use_image_grain = left->use_image_grain;
  result->image_grain_intensity = (float)((float)(right->image_grain_intensity - left->image_grain_intensity)
                                        * *(float *)&t)
                                + left->image_grain_intensity;
  v69 = (double)left->image_grain_update_frequency
      + ((double)right->image_grain_update_frequency - (double)left->image_grain_update_frequency) * *(float *)&t
      + 0.5;
  result->image_grain_update_frequency = vostok::math::floor(v69);
  result->use_aberration = left->use_aberration;
  result->aberration_amount = (float)((float)(right->aberration_amount - left->aberration_amount) * *(float *)&t)
                            + left->aberration_amount;
  result->aberration_red = (float)((float)(right->aberration_red - left->aberration_red) * *(float *)&t)
                         + left->aberration_red;
  result->aberration_blue = (float)((float)(right->aberration_blue - left->aberration_blue) * *(float *)&t)
                          + left->aberration_blue;
  result->use_sharpen = left->use_sharpen;
  result->sharpen_amount = (float)((float)(right->sharpen_amount - left->sharpen_amount) * *(float *)&t)
                         + left->sharpen_amount;
  result->bloom_intensity = (float)((float)(right->bloom_intensity - left->bloom_intensity) * *(float *)&t)
                          + left->bloom_intensity;
  result->bloom_ratio = (float)((float)(right->bloom_ratio - left->bloom_ratio) * *(float *)&t) + left->bloom_ratio;
  v70 = (double)left->blur_kernel + ((double)right->blur_kernel - (double)left->blur_kernel) * *(float *)&t + 0.5;
  result->blur_kernel = vostok::math::floor(v70);
  v64 = right->bloom_color.w;
  v65 = right->bloom_color.z;
  v66 = left->bloom_color.z;
  v76 = left->bloom_color.w;
  v72.x = left->bloom_color.x + (float)((float)(right->bloom_color.x - left->bloom_color.x) * *(float *)&t);
  v72.y = left->bloom_color.y + (float)((float)(right->bloom_color.y - left->bloom_color.y) * *(float *)&t);
  v72.w = v76 + (float)((float)(v64 - v76) * *(float *)&t);
  v72.z = v66 + (float)((float)(v65 - v66) * *(float *)&t);
  result->bloom_color = v72;
  result->use_bokeh_dof = left->use_bokeh_dof;
  result->bokeh_radius = (float)((float)(right->bokeh_radius - left->bokeh_radius) * *(float *)&t) + left->bokeh_radius;
  result->bokeh_density = (float)((float)(right->bokeh_density - left->bokeh_density) * *(float *)&t)
                        + left->bokeh_density;
  result->use_bokeh_dof = left->use_bokeh_template_image;
  result->dof_focus_region = (float)((float)(right->dof_focus_region - left->dof_focus_region) * *(float *)&t)
                           + left->dof_focus_region;
  result->dof_focus_distance = (float)((float)(right->dof_focus_distance - left->dof_focus_distance) * *(float *)&t)
                             + left->dof_focus_distance;
  v71 = (double)left->dof_blur_kernel
      + ((double)right->dof_blur_kernel - (double)left->dof_blur_kernel) * *(float *)&t
      + 0.5;
  result->dof_blur_kernel = vostok::math::floor(v71);
  result->dof_near_blurness_amount = (float)((float)(right->dof_near_blurness_amount - left->dof_near_blurness_amount)
                                           * *(float *)&t)
                                   + left->dof_near_blurness_amount;
  result->dof_far_blurness_amount = (float)((float)(right->dof_far_blurness_amount - left->dof_far_blurness_amount)
                                          * *(float *)&t)
                                  + left->dof_far_blurness_amount;
  result->use_radial_blur = left->use_radial_blur;
  result->use_channel_blur = left->use_channel_blur;
  result->channel_blur_amount = (float)((float)(right->channel_blur_amount - left->channel_blur_amount) * *(float *)&t)
                              + left->channel_blur_amount;
  result->channel_blur_power = (float)((float)(right->channel_blur_power - left->channel_blur_power) * *(float *)&t)
                             + left->channel_blur_power;
  result->radial_blur_intensity = (float)((float)(right->radial_blur_intensity - left->radial_blur_intensity)
                                        * *(float *)&t)
                                + left->radial_blur_intensity;
  result->radial_blur_amount = (float)((float)(right->radial_blur_amount - left->radial_blur_amount) * *(float *)&t)
                             + left->radial_blur_amount;
  result->radial_blur_power = (float)((float)(right->radial_blur_power - left->radial_blur_power) * *(float *)&t)
                            + left->radial_blur_power;
  return result;
}
