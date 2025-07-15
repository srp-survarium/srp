vostok::render::environment_properties *__thiscall vostok::render::environment_properties::operator=(
        vostok::render::environment_properties *this,
        const vostok::render::environment_properties *__that,
        int a3)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *color_grading_textures; // eax
  float *color_grading_weights; // eax
  int v6; // ecx
  vostok::render::environment_properties *result; // eax
  int v8; // [esp+Ch] [ebp-8h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v9; // [esp+10h] [ebp-4h]
  int v10; // [esp+1Ch] [ebp+8h]

  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)a3,
    &__that->sun_moon_texture);
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(a3 + 4),
    &__that->sky_clouds_texture);
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(a3 + 8),
    &__that->stratosphere_texture);
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(a3 + 12),
    &__that->sky_shadows_texture);
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(a3 + 16),
    &__that->lens_flares_mask_texture);
  color_grading_textures = __that->color_grading_textures;
  v10 = a3 - (_DWORD)__that;
  v9 = __that->color_grading_textures;
  v8 = 4;
  while ( 1 )
  {
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)((char *)color_grading_textures + v10),
      color_grading_textures);
    ++v9;
    if ( !--v8 )
      break;
    color_grading_textures = v9;
  }
  color_grading_weights = __that->color_grading_weights;
  v6 = 4;
  do
  {
    *color_grading_weights = *(float *)((char *)color_grading_weights + v10);
    ++color_grading_weights;
    --v6;
  }
  while ( v6 );
  __that->num_color_grading_textures = *(_DWORD *)(a3 + 52);
  __that->use_sun = *(_BYTE *)(a3 + 56);
  __that->sun_position_azimut = *(float *)(a3 + 60);
  __that->sun_angle = *(float *)(a3 + 64);
  __that->sun_intensity = *(float *)(a3 + 68);
  __that->sun_color.x = *(float *)(a3 + 72);
  __that->sun_color.y = *(float *)(a3 + 76);
  __that->sun_color.z = *(float *)(a3 + 80);
  __that->sun_color.w = *(float *)(a3 + 84);
  __that->sun_shadow_rain = *(_BYTE *)(a3 + 88);
  __that->use_sun_shadows = *(_BYTE *)(a3 + 89);
  __that->sun_shadow_filter_radius = *(float *)(a3 + 92);
  __that->sun_shadow_penumbra = *(float *)(a3 + 96);
  __that->use_sun_moon_texture = *(_BYTE *)(a3 + 100);
  __that->sun_moon_billboard_scale = *(float *)(a3 + 104);
  __that->god_rays_color_1.x = *(float *)(a3 + 108);
  __that->god_rays_color_1.y = *(float *)(a3 + 112);
  __that->god_rays_color_1.z = *(float *)(a3 + 116);
  __that->god_rays_color_1.w = *(float *)(a3 + 120);
  __that->god_rays_color_2.x = *(float *)(a3 + 124);
  __that->god_rays_color_2.y = *(float *)(a3 + 128);
  __that->god_rays_color_2.z = *(float *)(a3 + 132);
  __that->god_rays_color_2.w = *(float *)(a3 + 136);
  __that->god_rays_color_blend_power = *(float *)(a3 + 140);
  __that->god_rays_intensity = *(float *)(a3 + 144);
  __that->god_rays_attenuation = *(float *)(a3 + 148);
  __that->use_radial_blur = *(_BYTE *)(a3 + 152);
  __that->use_channel_blur = *(_BYTE *)(a3 + 153);
  __that->channel_blur_amount = *(float *)(a3 + 156);
  __that->channel_blur_power = *(float *)(a3 + 160);
  __that->radial_blur_intensity = *(float *)(a3 + 164);
  __that->radial_blur_amount = *(float *)(a3 + 168);
  __that->radial_blur_power = *(float *)(a3 + 172);
  __that->atmosphere_rayleighSun_multiplier = *(float *)(a3 + 176);
  __that->atmosphere_mieSun_multiplier = *(float *)(a3 + 180);
  __that->atmosphere_rayleighPi_multiplier = *(float *)(a3 + 184);
  __that->atmosphere_miePi_multiplier = *(float *)(a3 + 188);
  __that->atmosphere_use_sun_illumination = *(_BYTE *)(a3 + 192);
  __that->use_sky_clouds = *(_BYTE *)(a3 + 193);
  __that->sky_clouds_rotation = *(float *)(a3 + 196);
  __that->sky_clouds_rotation_speed = *(float *)(a3 + 200);
  __that->use_stratosphere = *(_BYTE *)(a3 + 204);
  __that->stratosphere_rotation = *(float *)(a3 + 208);
  __that->stratosphere_rotation_speed = *(float *)(a3 + 212);
  __that->sky_clouds_blend_mode = *(_DWORD *)(a3 + 216);
  __that->sky_clouds_color.x = *(float *)(a3 + 220);
  __that->sky_clouds_color.y = *(float *)(a3 + 224);
  __that->sky_clouds_color.z = *(float *)(a3 + 228);
  __that->sky_clouds_color.w = *(float *)(a3 + 232);
  __that->sky_clouds_color_multiplier = *(float *)(a3 + 236);
  __that->sky_clouds_fog_color.x = *(float *)(a3 + 240);
  __that->sky_clouds_fog_color.y = *(float *)(a3 + 244);
  __that->sky_clouds_fog_color.z = *(float *)(a3 + 248);
  __that->sky_clouds_fog_color.w = *(float *)(a3 + 252);
  __that->sky_clouds_fog_power = *(float *)(a3 + 256);
  __that->sky_clouds_fog_up_limit = *(float *)(a3 + 260);
  __that->use_sky_shadows = *(_BYTE *)(a3 + 264);
  __that->sky_shadows_moving_x = *(float *)(a3 + 268);
  __that->sky_shadows_moving_y = *(float *)(a3 + 272);
  __that->sky_shadows_tiling = *(float *)(a3 + 276);
  __that->use_sky_clouds_lighting = *(_BYTE *)(a3 + 280);
  __that->rayleigh_fog_color.x = *(float *)(a3 + 284);
  __that->rayleigh_fog_color.y = *(float *)(a3 + 288);
  __that->rayleigh_fog_color.z = *(float *)(a3 + 292);
  __that->rayleigh_fog_color.w = *(float *)(a3 + 296);
  __that->rayleigh_fog_far_distance = *(float *)(a3 + 300);
  __that->rayleigh_fog_near_distance = *(float *)(a3 + 304);
  __that->rayleigh_fog_density = *(float *)(a3 + 308);
  __that->mie_fog_color.x = *(float *)(a3 + 312);
  __that->mie_fog_color.y = *(float *)(a3 + 316);
  __that->mie_fog_color.z = *(float *)(a3 + 320);
  __that->mie_fog_color.w = *(float *)(a3 + 324);
  __that->mie_fog_far_distance = *(float *)(a3 + 328);
  __that->mie_fog_near_distance = *(float *)(a3 + 332);
  __that->mie_fog_density = *(float *)(a3 + 336);
  __that->mie_fog_bias = *(float *)(a3 + 340);
  __that->mie_fog_falloff = *(float *)(a3 + 344);
  __that->mie_fog_height_falloff = *(float *)(a3 + 348);
  __that->use_ambient_occlusion = *(_BYTE *)(a3 + 352);
  __that->ao_saturation = *(float *)(a3 + 356);
  __that->ao_radius = *(float *)(a3 + 360);
  __that->environment_probes_diffuse_intensity_multiplier = *(float *)(a3 + 364);
  __that->environment_probes_specular_intensity_multiplier = *(float *)(a3 + 368);
  __that->use_height_based_ambient = *(_BYTE *)(a3 + 372);
  __that->height_based_ambient_low_color.x = *(float *)(a3 + 376);
  __that->height_based_ambient_low_color.y = *(float *)(a3 + 380);
  __that->height_based_ambient_low_color.z = *(float *)(a3 + 384);
  __that->height_based_ambient_low_color.w = *(float *)(a3 + 388);
  __that->height_based_ambient_high_color.x = *(float *)(a3 + 392);
  __that->height_based_ambient_high_color.y = *(float *)(a3 + 396);
  __that->height_based_ambient_high_color.z = *(float *)(a3 + 400);
  __that->height_based_ambient_high_color.w = *(float *)(a3 + 404);
  __that->height_based_ambient_low_limit = *(float *)(a3 + 408);
  __that->height_based_ambient_high_limit = *(float *)(a3 + 412);
  __that->height_based_ambient_power = *(float *)(a3 + 416);
  __that->use_rain = *(_BYTE *)(a3 + 420);
  __that->rain_surface_intensity = *(float *)(a3 + 424);
  __that->rain_angle_x = *(float *)(a3 + 428);
  __that->rain_angle_y = *(float *)(a3 + 432);
  __that->rain_speed = *(float *)(a3 + 436);
  __that->rain_density = *(float *)(a3 + 440);
  __that->rain_num_cones = *(_DWORD *)(a3 + 444);
  __that->rain_u_scale = *(float *)(a3 + 448);
  __that->rain_v_scale = *(float *)(a3 + 452);
  __that->rain_random_rotation_speed = *(float *)(a3 + 456);
  __that->rain_random_rotation_radius = *(float *)(a3 + 460);
  __that->rain_random_base_offset = *(float *)(a3 + 464);
  __that->rain_radius_scale = *(float *)(a3 + 468);
  __that->rain_start_cone_index = *(_DWORD *)(a3 + 472);
  __that->wind_direction.x = *(float *)(a3 + 476);
  __that->wind_direction.y = *(float *)(a3 + 480);
  __that->wind_direction.z = *(float *)(a3 + 484);
  __that->wind_strength = *(float *)(a3 + 488);
  __that->eye_adaptation_speed = *(float *)(a3 + 492);
  __that->use_color_grading_texture = *(_BYTE *)(a3 + 496);
  __that->blueshift = *(float *)(a3 + 500);
  __that->vignette_effect_power = *(float *)(a3 + 504);
  __that->use_dynamic_lens_flare = *(_BYTE *)(a3 + 508);
  __that->lens_flares_multiplier = *(float *)(a3 + 512);
  __that->use_image_grain = *(_BYTE *)(a3 + 516);
  __that->image_grain_intensity = *(float *)(a3 + 520);
  __that->image_grain_update_frequency = *(_DWORD *)(a3 + 524);
  __that->use_aberration = *(_BYTE *)(a3 + 528);
  __that->aberration_amount = *(float *)(a3 + 532);
  __that->aberration_red = *(float *)(a3 + 536);
  __that->aberration_blue = *(float *)(a3 + 540);
  __that->use_sharpen = *(_BYTE *)(a3 + 544);
  __that->sharpen_amount = *(float *)(a3 + 548);
  __that->bloom_intensity = *(float *)(a3 + 552);
  __that->bloom_ratio = *(float *)(a3 + 556);
  __that->blur_kernel = *(_DWORD *)(a3 + 560);
  __that->bloom_color.x = *(float *)(a3 + 564);
  __that->bloom_color.y = *(float *)(a3 + 568);
  __that->bloom_color.z = *(float *)(a3 + 572);
  __that->bloom_color.w = *(float *)(a3 + 576);
  __that->use_bokeh_dof = *(_BYTE *)(a3 + 580);
  __that->bokeh_radius = *(float *)(a3 + 584);
  __that->bokeh_density = *(float *)(a3 + 588);
  __that->use_bokeh_template_image = *(_BYTE *)(a3 + 592);
  __that->dof_focus_region = *(float *)(a3 + 596);
  __that->dof_focus_distance = *(float *)(a3 + 600);
  __that->dof_blur_kernel = *(_DWORD *)(a3 + 604);
  __that->dof_near_blurness_amount = *(float *)(a3 + 608);
  result = (vostok::render::environment_properties *)__that;
  __that->dof_far_blurness_amount = *(float *)(a3 + 612);
  return result;
}
