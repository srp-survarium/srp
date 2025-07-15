void __usercall vostok::render::statistics::statistics(
        vostok::render::statistics *this@<ecx>,
        vostok::render::statistics *a2@<esi>)
{
  vostok::render::statistics_group *v2; // ecx
  vostok::render::statistics_group *v3; // ecx
  vostok::render::particles_statistics_group *v4; // ecx
  vostok::render::statistics_group *v5; // ecx
  vostok::render::statistics_group *v6; // ecx
  vostok::render::cascaded_sun_shadow_statistics_group *v7; // ecx
  vostok::render::statistics_group *v8; // ecx
  _DWORD *v9; // eax
  vostok::render::statistics_group *v10; // ecx
  vostok::render::statistics_group *v11; // ecx
  _DWORD *v12; // eax
  vostok::render::lpv_statistics_group *v13; // ecx
  vostok::render::statistics_group *v14; // ecx
  _DWORD *v15; // eax
  vostok::render::statistics_group *v16; // ecx
  vostok::render::visibility_statistics_group *v17; // ecx
  vostok::render::frame_statistics_group *v18; // ecx
  vostok::render::debug_statistics_group *v19; // ecx
  const char *v20; // [esp+0h] [ebp-Ch]
  const char *v21; // [esp+0h] [ebp-Ch]
  const char *v22; // [esp+0h] [ebp-Ch]
  const char *v23; // [esp+0h] [ebp-Ch]
  const char *v24; // [esp+0h] [ebp-Ch]
  const vostok::math::color *v25; // [esp+0h] [ebp-Ch]
  const char *v26; // [esp+0h] [ebp-Ch]
  const char *v27; // [esp+0h] [ebp-Ch]
  const vostok::math::color *v28; // [esp+0h] [ebp-Ch]
  const char *v29; // [esp+0h] [ebp-Ch]
  const char *v30; // [esp+0h] [ebp-Ch]
  const vostok::math::color *v31; // [esp+0h] [ebp-Ch]
  const char *v32; // [esp+0h] [ebp-Ch]
  const char *v33; // [esp+0h] [ebp-Ch]
  const char *v34; // [esp+0h] [ebp-Ch]
  const vostok::math::color *v35; // [esp+0h] [ebp-Ch]
  const vostok::math::color *v36; // [esp+0h] [ebp-Ch]
  const vostok::math::color *v37; // [esp+0h] [ebp-Ch]
  int p_num_visible_patches; // [esp+8h] [ebp-4h] BYREF

  a2->first_group = 0;
  p_num_visible_patches = -1;
  vostok::quasi_singleton<vostok::render::statistics>::pinst = a2;
  vostok::render::statistics_group::statistics_group(
    (vostok::render::statistics_group *)this,
    &a2->postprocess_stat_group,
    "post-process statistics",
    (const vostok::math::color *)&p_num_visible_patches);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)&a2->postprocess_stat_group,
    (int)&a2->postprocess_stat_group.execute_time,
    (vostok::render::statistics_group *)"execute time",
    v20);
  p_num_visible_patches = -1;
  vostok::render::statistics_group::statistics_group(
    v2,
    &a2->ssao_stat_group,
    "ssao statistics",
    (const vostok::math::color *)&p_num_visible_patches);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)&a2->ssao_stat_group,
    (int)&a2->ssao_stat_group.ssao_accumulate_time,
    (vostok::render::statistics_group *)"ssao accumulate time",
    v21);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)&a2->ssao_stat_group,
    (int)&a2->ssao_stat_group.ssao_blurring_time,
    (vostok::render::statistics_group *)"ssao blurring time",
    v22);
  p_num_visible_patches = -1;
  vostok::render::statistics_group::statistics_group(
    v3,
    &a2->distortion_pass_stat_group,
    "distortion pass statistics",
    (const vostok::math::color *)&p_num_visible_patches);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)&a2->distortion_pass_stat_group,
    (int)&a2->distortion_pass_stat_group.accumulate_time,
    (vostok::render::statistics_group *)"accumulate time",
    v23);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)&a2->distortion_pass_stat_group,
    (int)&a2->distortion_pass_stat_group.apply_time,
    (vostok::render::statistics_group *)"apply time",
    v24);
  p_num_visible_patches = -1;
  vostok::render::particles_statistics_group::particles_statistics_group(
    v4,
    (int)&a2->particles_stat_group,
    (const vostok::math::color *)&p_num_visible_patches,
    v25);
  p_num_visible_patches = -1;
  vostok::render::statistics_group::statistics_group(
    v5,
    &a2->sky_stat_group,
    "sky statistics",
    (const vostok::math::color *)&p_num_visible_patches);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)&a2->sky_stat_group,
    (int)&a2->sky_stat_group.execute_time,
    (vostok::render::statistics_group *)"execute time",
    v26);
  p_num_visible_patches = -1;
  vostok::render::statistics_group::statistics_group(
    v6,
    &a2->forward_stage_stat_group,
    "forward stage statistics",
    (const vostok::math::color *)&p_num_visible_patches);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)&a2->forward_stage_stat_group,
    (int)&a2->forward_stage_stat_group.execute_time,
    (vostok::render::statistics_group *)"execute time",
    v27);
  p_num_visible_patches = -8996;
  vostok::render::cascaded_sun_shadow_statistics_group::cascaded_sun_shadow_statistics_group(
    v7,
    (int)&a2->cascaded_sun_shadow_stat_group,
    (const vostok::math::color *)&p_num_visible_patches,
    v28);
  p_num_visible_patches = -3604536;
  vostok::render::statistics_group::statistics_group(
    v8,
    &a2->grass_stat_group,
    "grass statistics",
    (const vostok::math::color *)&p_num_visible_patches);
  vostok::render::statistics_value<int>::statistics_value<int>(
    &a2->grass_stat_group.num_total_patches,
    &a2->grass_stat_group,
    "total patches");
  a2->grass_stat_group.num_total_patches.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    &a2->grass_stat_group.num_rendered_patches,
    &a2->grass_stat_group,
    "rendered patches");
  a2->grass_stat_group.num_rendered_patches.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
  p_num_visible_patches = (int)&a2->grass_stat_group.num_visible_patches;
  vostok::render::statistics_value<int>::statistics_value<int>(
    &a2->grass_stat_group.num_visible_patches,
    &a2->grass_stat_group,
    "visible patches");
  v9 = (_DWORD *)p_num_visible_patches;
  p_num_visible_patches = -1;
  *v9 = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_group::statistics_group(
    v10,
    &a2->gbuffer_stat_group,
    "g-buffer statistics",
    (const vostok::math::color *)&p_num_visible_patches);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)&a2->gbuffer_stat_group,
    (int)&a2->gbuffer_stat_group.pre_pass_execute_time,
    (vostok::render::statistics_group *)"pre pass execute time",
    v29);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)&a2->gbuffer_stat_group,
    (int)&a2->gbuffer_stat_group.material_pass_execute_time,
    (vostok::render::statistics_group *)"material pass execute time",
    v30);
  p_num_visible_patches = -1;
  vostok::render::statistics_group::statistics_group(
    v11,
    &a2->forward_decals_stat_group,
    "forward decals statistics",
    (const vostok::math::color *)&p_num_visible_patches);
  vostok::render::statistics_float::statistics_float(
    &a2->forward_decals_stat_group.execute_time,
    &a2->forward_decals_stat_group,
    "execute time",
    6u);
  vostok::render::statistics_value<int>::statistics_value<int>(
    &a2->forward_decals_stat_group.num_decals,
    &a2->forward_decals_stat_group,
    "decals");
  a2->forward_decals_stat_group.num_decals.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
  p_num_visible_patches = (int)&a2->forward_decals_stat_group.num_decal_draw_calls;
  vostok::render::statistics_value<int>::statistics_value<int>(
    &a2->forward_decals_stat_group.num_decal_draw_calls,
    &a2->forward_decals_stat_group,
    "decal draw calls");
  v12 = (_DWORD *)p_num_visible_patches;
  p_num_visible_patches = -1;
  *v12 = &vostok::render::statistics_int::`vftable';
  vostok::render::lpv_statistics_group::lpv_statistics_group(
    v13,
    (int)&a2->lpv_stat_group,
    (const vostok::math::color *)&p_num_visible_patches,
    v31);
  p_num_visible_patches = -1;
  vostok::render::statistics_group::statistics_group(
    v14,
    &a2->deferred_decals_stat_group,
    "deferred decals statistics",
    (const vostok::math::color *)&p_num_visible_patches);
  vostok::render::statistics_float::statistics_float(
    &a2->deferred_decals_stat_group.execute_time,
    &a2->deferred_decals_stat_group,
    "execute time",
    6u);
  vostok::render::statistics_value<int>::statistics_value<int>(
    &a2->deferred_decals_stat_group.num_decals,
    &a2->deferred_decals_stat_group,
    "decals");
  a2->deferred_decals_stat_group.num_decals.__vftable = (vostok::render::statistics_int_vtbl *)&vostok::render::statistics_int::`vftable';
  p_num_visible_patches = (int)&a2->deferred_decals_stat_group.num_decal_draw_calls;
  vostok::render::statistics_value<int>::statistics_value<int>(
    &a2->deferred_decals_stat_group.num_decal_draw_calls,
    &a2->deferred_decals_stat_group,
    "decal draw calls");
  v15 = (_DWORD *)p_num_visible_patches;
  p_num_visible_patches = -1;
  *v15 = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_group::statistics_group(
    v16,
    &a2->lights_stat_group,
    "lights statistics",
    (const vostok::math::color *)&p_num_visible_patches);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)&a2->lights_stat_group,
    (int)&a2->lights_stat_group.accumulate_lighting_time,
    (vostok::render::statistics_group *)"accumulate lighting time",
    v32);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)&a2->lights_stat_group,
    (int)&a2->lights_stat_group.forward_lighting_time,
    (vostok::render::statistics_group *)"forward lighting time",
    v33);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)&a2->lights_stat_group,
    (int)&a2->lights_stat_group.shadow_map_time,
    (vostok::render::statistics_group *)"shadow map time",
    v34);
  p_num_visible_patches = -4915201;
  vostok::render::visibility_statistics_group::visibility_statistics_group(
    v17,
    (int)&a2->visibility_stat_group,
    (const vostok::math::color *)&p_num_visible_patches,
    v35);
  p_num_visible_patches = -6881386;
  vostok::render::frame_statistics_group::frame_statistics_group(
    v18,
    (int)&a2->frame_stat_group,
    (const vostok::math::color *)&p_num_visible_patches,
    v36);
  p_num_visible_patches = -4934476;
  vostok::render::debug_statistics_group::debug_statistics_group(
    v19,
    (int)&a2->debug_stat_group,
    (const vostok::math::color *)&p_num_visible_patches,
    v37);
  a2->m_max_string_width = 0;
}
