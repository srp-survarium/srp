void __thiscall vostok::render::statistics::~statistics(vostok::render::statistics *this)
{
  vostok::render::visibility_statistics_group *v1; // ecx
  vostok::render::lpv_statistics_group *v2; // ecx
  vostok::render::cascaded_sun_shadow_statistics_group *v3; // ecx
  vostok::render::particles_statistics_group *v4; // ecx

  vostok::render::debug_statistics_group::~debug_statistics_group(
    (vostok::render::debug_statistics_group *)this,
    &m_statistics.debug_stat_group.first_statistics);
  m_statistics.general_stat_group.render_only_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.general_stat_group.cpu_fps.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.general_stat_group.fps.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.general_stat_group.num_setted_shader_constants.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.general_stat_group.cpu_render_frame_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.general_stat_group.render_frame_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.general_stat_group.render_frame_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.general_stat_group.render_frame_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_base::`vftable';
  vostok::render::visibility_statistics_group::~visibility_statistics_group(
    v1,
    &m_statistics.visibility_stat_group.first_statistics);
  m_statistics.lights_stat_group.shadow_map_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.lights_stat_group.shadow_map_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.lights_stat_group.shadow_map_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.lights_stat_group.forward_lighting_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.lights_stat_group.forward_lighting_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.lights_stat_group.forward_lighting_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.lights_stat_group.accumulate_lighting_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.lights_stat_group.accumulate_lighting_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.lights_stat_group.accumulate_lighting_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.deferred_decals_stat_group.num_decal_draw_calls.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.deferred_decals_stat_group.num_decals.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.deferred_decals_stat_group.execute_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  vostok::render::lpv_statistics_group::~lpv_statistics_group(v2, &m_statistics.lpv_stat_group.first_statistics);
  m_statistics.forward_decals_stat_group.num_decal_draw_calls.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.forward_decals_stat_group.num_decals.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.forward_decals_stat_group.execute_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.gbuffer_stat_group.material_pass_execute_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.gbuffer_stat_group.material_pass_execute_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.gbuffer_stat_group.material_pass_execute_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.gbuffer_stat_group.pre_pass_execute_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.gbuffer_stat_group.pre_pass_execute_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.gbuffer_stat_group.pre_pass_execute_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.grass_stat_group.num_visible_patches.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.grass_stat_group.num_rendered_patches.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.grass_stat_group.num_total_patches.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_base::`vftable';
  vostok::render::cascaded_sun_shadow_statistics_group::~cascaded_sun_shadow_statistics_group(
    v3,
    &m_statistics.cascaded_sun_shadow_stat_group.first_statistics);
  m_statistics.forward_stage_stat_group.execute_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.forward_stage_stat_group.execute_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.forward_stage_stat_group.execute_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.speedtree_stat_group.num_instances.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.speedtree_stat_group.culling_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.speedtree_stat_group.render_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.speedtree_stat_group.render_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.speedtree_stat_group.render_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.sky_stat_group.execute_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.sky_stat_group.execute_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.sky_stat_group.execute_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_base::`vftable';
  vostok::render::particles_statistics_group::~particles_statistics_group(
    v4,
    &m_statistics.particles_stat_group.first_statistics);
  m_statistics.distortion_pass_stat_group.apply_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.distortion_pass_stat_group.apply_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.distortion_pass_stat_group.apply_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.distortion_pass_stat_group.accumulate_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.distortion_pass_stat_group.accumulate_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.distortion_pass_stat_group.accumulate_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.ssao_stat_group.ssao_blurring_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.ssao_stat_group.ssao_blurring_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.ssao_stat_group.ssao_blurring_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.ssao_stat_group.ssao_accumulate_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.ssao_stat_group.ssao_accumulate_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.ssao_stat_group.ssao_accumulate_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.postprocess_stat_group.execute_time.gpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.postprocess_stat_group.execute_time.cpu_time.__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_base::`vftable';
  m_statistics.postprocess_stat_group.execute_time.__vftable = (vostok::render::statistics_cpu_gpu_vtbl *)&vostok::render::statistics_base::`vftable';
  vostok::quasi_singleton<vostok::render::statistics>::pinst = 0;
}
