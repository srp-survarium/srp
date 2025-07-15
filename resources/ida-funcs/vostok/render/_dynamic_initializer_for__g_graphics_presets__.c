vostok::render::enum_uro_texture_quality_values vostok::render::_dynamic_initializer_for__g_graphics_presets__()
{
  bool is_address_space_or_ram_under_2_gb; // al
  bool v1; // al
  vostok::render::enum_uro_texture_quality_values result; // eax

  is_address_space_or_ram_under_2_gb = vostok::platform::is_address_space_or_ram_under_2_gb();
  vostok::render::g_graphics_presets[2].geometry_quality_option = uro_geometry_quality_high;
  vostok::render::g_graphics_presets[2].shadow_quality_option = uro_shadow_quality_medium;
  vostok::render::g_graphics_presets[2].texture_quality_option = !is_address_space_or_ram_under_2_gb;
  vostok::render::g_graphics_presets[2].lighting_quality_option = uro_lighting_quality_medium;
  vostok::render::g_graphics_presets[2].shading_quality_option = uro_shading_quality_medium;
  vostok::render::g_graphics_presets[2].decorations_quality_option = uro_decorations_quality_medium;
  vostok::render::g_graphics_presets[2].post_process_quality_option = uro_post_process_quality_medium;
  vostok::render::g_graphics_presets[2].ambient_occlusion_quality_option = uro_ambient_occlusion_quality_ssao;
  vostok::render::g_graphics_presets[2].particles_quality_option = uro_particles_quality_medium;
  vostok::render::g_graphics_presets[2].motion_blur_quality_option = uro_motion_blur_quality_medium;
  vostok::render::g_graphics_presets[3].texture_quality_option = vostok::platform::is_address_space_or_ram_under_2_gb()
                                                               ? uro_texture_quality_low
                                                               : uro_texture_quality_high;
  vostok::render::g_graphics_presets[3].geometry_quality_option = uro_geometry_quality_high;
  vostok::render::g_graphics_presets[3].shadow_quality_option = uro_shadow_quality_high;
  vostok::render::g_graphics_presets[3].lighting_quality_option = uro_lighting_quality_high;
  vostok::render::g_graphics_presets[3].shading_quality_option = uro_shading_quality_high;
  vostok::render::g_graphics_presets[3].decorations_quality_option = uro_decorations_quality_high;
  vostok::render::g_graphics_presets[3].post_process_quality_option = uro_post_process_quality_high;
  vostok::render::g_graphics_presets[3].ambient_occlusion_quality_option = uro_ambient_occlusion_quality_hdao;
  vostok::render::g_graphics_presets[3].particles_quality_option = uro_particles_quality_high;
  vostok::render::g_graphics_presets[3].motion_blur_quality_option = uro_motion_blur_quality_high;
  v1 = vostok::platform::is_address_space_or_ram_under_2_gb();
  vostok::render::g_graphics_presets[4].geometry_quality_option = uro_geometry_quality_high;
  result = v1 ? uro_texture_quality_low : uro_texture_quality_high;
  vostok::render::g_graphics_presets[4].decorations_quality_option = uro_decorations_quality_high;
  vostok::render::g_graphics_presets[4].ambient_occlusion_quality_option = uro_ambient_occlusion_quality_hdao;
  vostok::render::g_graphics_presets[4].particles_quality_option = uro_particles_quality_high;
  vostok::render::g_graphics_presets[4].shadow_quality_option = uro_shadow_quality_ultra;
  vostok::render::g_graphics_presets[4].lighting_quality_option = uro_lighting_quality_ultra;
  vostok::render::g_graphics_presets[4].shading_quality_option = uro_shading_quality_ultra;
  vostok::render::g_graphics_presets[4].post_process_quality_option = uro_post_process_quality_high;
  vostok::render::g_graphics_presets[4].motion_blur_quality_option = uro_motion_blur_quality_high;
  vostok::render::g_graphics_presets[4].texture_quality_option = result;
  return result;
}
