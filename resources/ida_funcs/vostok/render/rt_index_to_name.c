const char *__usercall vostok::render::rt_index_to_name@<eax>(vostok::render::enum_render_target_index index@<eax>)
{
  const char *result; // eax

  switch ( index )
  {
    case rt_gbuffer_position_downsampled:
      result = "$user$gbuffer_position_downsampled";
      break;
    case rt_final_frame_downsampled_temp:
      result = "$user$final_frame_downsampledtemp";
      break;
    case rt_final_frame_downsampled:
      result = "$user$final_frame_downsampled";
      break;
    case rt_indirect_lighting_specular:
      result = "$user$indirect_lighting_specular";
      break;
    case rt_light_scattering_mask:
      result = "$user$light_scattering_mask";
      break;
    case rt_light_scattering_result:
      result = "$user$light_scattering_result";
      break;
    case rt_local_reflection_result:
      result = "$user$local_reflection_result";
      break;
    case rt_local_reflection_result_params:
      result = "$user$local_reflection_result_params";
      break;
    case rt_sun_translucensy_help_data:
      result = "$user$sun_translucensy_help_data";
      break;
    case rt_position:
      result = "$user$position";
      break;
    case rt_normal:
      result = "$user$normal";
      break;
    case rt_normal_copy:
      result = "$user$normal_copy";
      break;
    case rt_albedo:
      result = "$user$albedo";
      break;
    case rt_one_layer_transparency_alpha:
      result = "$user$one_layer_transparency_alpha";
      break;
    case rt_distortion:
      result = "$user$distortion";
      break;
    case rt_distortion_mask:
      result = "$user$distortion_mask";
      break;
    case rt_object_motion_vectors:
      result = "$user$object_motion_vectors";
      break;
    case rt_ssao_accumulator:
      result = "$user$ssao_accumulator";
      break;
    case rt_ssao_accumulator_full_x:
      result = "$user$ssao_accumulator_full_x";
      break;
    case rt_ssao_temporal_mask:
      result = "$user$ssao_temporal_mask";
      break;
    case rt_ssao_prev_accumulator_full_x:
      result = "$user$ssao_prev_accumulator_full_x";
      break;
    case rt_ssao_accumulator_z:
      result = "$user$ssao_accumulator_z";
      break;
    case rt_ssao_prev_accumulator_z:
      result = "$user$ssao_prev_accumulator_z";
      break;
    case rt_decals_diffuse:
      result = "$user$decals_diffuse";
      break;
    case rt_decals_normal:
      result = "$user$decals_normal";
      break;
    case rt_decals_smoothness:
      result = "$user$decals_smoothness";
      break;
    case rt_accumulator_diffuse:
      result = "$user$accum_diffuse";
      break;
    case rt_decals_blend_result:
      result = "$user$decals_blend_result";
      break;
    case rt_accumulator_specular:
      result = "$user$accum_specular";
      break;
    case rt_lpv_accumulation:
      result = "$user$lpv_accumulation";
      break;
    case rt_blur_0:
      result = "$user$blur0";
      break;
    case rt_blur_1:
      result = "$user$blur1";
      break;
    case rt_blur_2:
      result = "$user$blur2";
      break;
    case rt_blur_3:
      result = "$user$blur3";
      break;
    case rt_blur_4:
      result = "$user$blur4";
      break;
    case rt_blur_4_0:
      result = "$user$blur40";
      break;
    case rt_blur_5:
      result = "$user$blur5";
      break;
    case rt_blur_5_0:
      result = "$user$blur50";
      break;
    case rt_blur_6:
      result = "$user$blur6";
      break;
    case rt_blur_6_0:
      result = "$user$blur60";
      break;
    case rt_blur_7:
      result = "$user$blur7";
      break;
    case rt_blur_7_0:
      result = "$user$blur70";
      break;
    case rt_blur_8:
      result = "$user$blur8";
      break;
    case rt_blur_8_0:
      result = "$user$blur80";
      break;
    case rt_lens_flares:
      result = "$user$lens_flares";
      break;
    case rt_present:
      result = "$user$present";
      break;
    case rt_previous_present:
      result = "$user$previous_present";
      break;
    case rt_generic_0:
      result = "$user$generic0";
      break;
    case rt_generic_1:
      result = "$user$generic1";
      break;
    case rt_particle_result:
      result = "$user$particle_result";
      break;
    case rt_particle_lighting:
      result = "$user$particle_lighting";
      break;
    case rt_rain_result:
      result = "$user$rain_result";
      break;
    case rt_frame_luminance_previous:
      result = "$user$frame_luminance_previous";
      break;
    case rt_frame_luminance_current:
      result = "$user$frame_luminance";
      break;
    case rt_frame_luminance_histogram:
      result = "$user$frame_luminance_histogram";
      break;
    case rt_apply_indirect_lighting_ds:
      result = "$user$apply_indirect_lighting_ds_%d";
      break;
    case rt_frame_luminance0:
      result = "$user$frame_luminance0";
      break;
    case rt_frame_luminance1:
      result = "$user$frame_luminance1";
      break;
    case rt_frame_luminance2:
      result = "$user$frame_luminance2";
      break;
    case rt_frame_luminance3:
      result = "$user$frame_luminance3";
      break;
    case rt_frame_luminance4:
      result = "$user$frame_luminance4";
      break;
    case rt_frame_luminance5:
      result = "$user$frame_luminance5";
      break;
    case rt_frame_luminance6:
      result = "$user$frame_luminance6";
      break;
    case rt_frame_luminance7:
      result = "$user$frame_luminance7";
      break;
    case rt_frame_luminance8:
      result = "$user$frame_luminance8";
      break;
    case rt_mie_scattering:
      result = "$user$mie_scattering";
      break;
    case rt_rayleigh_scattering:
      result = "$user$rayleigh_scattering";
      break;
    case rt_frame_lum_scene_downsampled:
      result = "$user$frame_luminance_scene_color_downsampled";
      break;
    case rt_result_frame_luminance_histogram:
      result = "$user$result_frame_luminance_histogram";
      break;
    case rt_frame_luminance_lockable:
      result = "$user$frame_luminance_lockable";
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
