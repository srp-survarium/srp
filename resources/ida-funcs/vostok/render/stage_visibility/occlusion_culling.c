void __usercall vostok::render::stage_visibility::occlusion_culling(
        vostok::render::stage_visibility *this@<ecx>,
        int a2@<eax>)
{
  vostok::render::stage_visibility *v3; // ecx
  vostok::render::stage_visibility *v4; // ecx
  vostok::render::stage_visibility *v5; // ecx
  vostok::render::stage_visibility *v6; // ecx
  vostok::render::stage_visibility *v7; // ecx
  vostok::render::stage_visibility *v8; // ecx
  vostok::render::stage_visibility *v9; // ecx
  vostok::render::stage_visibility *v10; // ecx
  vostok::render::hw_hiz_occlusion_manager *v11; // ecx
  const vostok::math::float4 *v12; // [esp-8h] [ebp-18h]
  unsigned int v13; // [esp-4h] [ebp-14h]
  unsigned int out_counter; // [esp+8h] [ebp-8h] BYREF
  unsigned int in_num_bounds_and_results; // [esp+Ch] [ebp-4h] BYREF

  out_counter = *(_DWORD *)(a2 + 24);
  if ( *(_BYTE *)(*(_DWORD *)(a2 + 20) + 228) )
    memset(*(_DWORD *)(a2 + 28), 255, (unsigned int)&_sbh_sizeHeaderList);
  in_num_bounds_and_results = 0;
  vostok::render::stage_visibility::get_results_and_prepare_bounds_models(
    this,
    (vostok::math::float4 **)a2,
    &out_counter,
    (int *)&in_num_bounds_and_results);
  vostok::render::stage_visibility::get_results_and_prepare_bounds_lights(
    v3,
    (vostok::math::float4 **)a2,
    &out_counter,
    (int *)&in_num_bounds_and_results);
  vostok::render::stage_visibility::get_results_and_prepare_bounds_grass(
    v4,
    (vostok::math::float4 **)a2,
    &out_counter,
    (vostok::math::float4x4 *)&in_num_bounds_and_results);
  vostok::render::stage_visibility::get_results_and_prepare_bounds_decals(
    v5,
    (vostok::math::float4 **)a2,
    &out_counter,
    (int *)&in_num_bounds_and_results);
  vostok::render::stage_visibility::get_results_and_prepare_bounds_env_probes(
    v6,
    (vostok::math::float4 **)a2,
    &out_counter,
    (int *)&in_num_bounds_and_results);
  vostok::render::stage_visibility::get_results_and_prepare_bounds_ambient_volumes(
    v7,
    (vostok::math::float4 **)a2,
    &out_counter,
    (int *)&in_num_bounds_and_results);
  vostok::render::stage_visibility::get_results_and_prepare_bounds_ambient_lights(
    v8,
    (vostok::math::float4 **)a2,
    &out_counter,
    (int *)&in_num_bounds_and_results);
  vostok::render::stage_visibility::get_results_and_prepare_bounds_particles(
    v9,
    (vostok::math::float4 **)a2,
    &out_counter,
    (vostok::math::float4x4 *)&in_num_bounds_and_results);
  vostok::render::stage_visibility::get_results_and_prepare_bounds_portals(
    v10,
    (_DWORD *)a2,
    (vostok::math::float4 **)&out_counter,
    &in_num_bounds_and_results);
  v13 = in_num_bounds_and_results;
  v12 = *(const vostok::math::float4 **)(a2 + 24);
  *(_DWORD *)(a2 + 32) = in_num_bounds_and_results;
  vostok::render::hw_hiz_occlusion_manager::process_culling(
    v11,
    *(_DWORD *)(a2 + 20),
    *(vostok::math::float4 **)(a2 + 4),
    v12,
    v13);
}
