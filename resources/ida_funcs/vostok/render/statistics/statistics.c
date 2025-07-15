void __thiscall vostok::render::statistics::statistics(vostok::render::statistics *this)
{
  vostok::render::ssao_statistics_group *v1; // ecx
  vostok::render::distortion_pass_statistics_group *v2; // ecx
  vostok::render::particles_statistics_group *v3; // ecx
  vostok::render::sky_statistics_group *v4; // ecx
  vostok::render::speedtree_statistics_group *v5; // ecx
  vostok::render::forward_stage_statistics_group *v6; // ecx
  vostok::render::cascaded_sun_shadow_statistics_group *v7; // ecx
  vostok::render::grass_statistics_group *v8; // ecx
  vostok::render::gbuffer_statistics_group *v9; // ecx
  vostok::render::forward_decals_statistics_group *v10; // ecx
  vostok::render::lpv_statistics_group *v11; // ecx
  vostok::render::deferred_decals_statistics_group *v12; // ecx
  vostok::render::lights_statistics_group *v13; // ecx
  vostok::render::visibility_statistics_group *v14; // ecx
  vostok::render::general_statistics_group *v15; // ecx
  vostok::render::debug_statistics_group *v16; // ecx

  vostok::quasi_singleton<vostok::render::statistics>::pinst = &m_statistics;
  m_statistics.first_group = 0;
  vostok::render::postprocess_statistics_group::postprocess_statistics_group(
    (vostok::render::postprocess_statistics_group *)this,
    &m_statistics.postprocess_stat_group);
  vostok::render::ssao_statistics_group::ssao_statistics_group(v1, &m_statistics.ssao_stat_group);
  vostok::render::distortion_pass_statistics_group::distortion_pass_statistics_group(
    v2,
    &m_statistics.distortion_pass_stat_group);
  vostok::render::particles_statistics_group::particles_statistics_group(v3, &m_statistics.particles_stat_group);
  vostok::render::sky_statistics_group::sky_statistics_group(v4, &m_statistics.sky_stat_group);
  vostok::render::speedtree_statistics_group::speedtree_statistics_group(v5, &m_statistics.speedtree_stat_group);
  vostok::render::forward_stage_statistics_group::forward_stage_statistics_group(
    v6,
    &m_statistics.forward_stage_stat_group);
  vostok::render::cascaded_sun_shadow_statistics_group::cascaded_sun_shadow_statistics_group(
    v7,
    &m_statistics.cascaded_sun_shadow_stat_group);
  vostok::render::grass_statistics_group::grass_statistics_group(v8, (int)&m_statistics.grass_stat_group);
  vostok::render::gbuffer_statistics_group::gbuffer_statistics_group(v9, &m_statistics.gbuffer_stat_group);
  vostok::render::forward_decals_statistics_group::forward_decals_statistics_group(
    v10,
    (int)&m_statistics.forward_decals_stat_group);
  vostok::render::lpv_statistics_group::lpv_statistics_group(v11, &m_statistics.lpv_stat_group);
  vostok::render::deferred_decals_statistics_group::deferred_decals_statistics_group(
    v12,
    (int)&m_statistics.deferred_decals_stat_group);
  vostok::render::lights_statistics_group::lights_statistics_group(v13, &m_statistics.lights_stat_group);
  vostok::render::visibility_statistics_group::visibility_statistics_group(
    v14,
    (int)&m_statistics.visibility_stat_group);
  vostok::render::general_statistics_group::general_statistics_group(v15, &m_statistics.general_stat_group);
  vostok::render::debug_statistics_group::debug_statistics_group(v16, (int)&m_statistics.debug_stat_group);
  m_statistics.m_max_string_width = 0;
}
