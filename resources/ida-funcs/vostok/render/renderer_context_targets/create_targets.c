void __userpurge vostok::render::renderer_context_targets::create_targets(
        vostok::render::renderer_context_targets *this@<ecx>,
        vostok::render::enum_render_target_index a2@<edi>,
        vostok::math::uint2 size,
        unsigned int force_resize)
{
  int v4; // ebx
  unsigned int y; // edx
  unsigned int v6; // esi
  unsigned int *v7; // ecx
  unsigned int *v8; // ecx
  unsigned int v9; // esi
  vostok::render::renderer_context_targets *v10; // ecx
  vostok::render::renderer_context_targets *v11; // ecx
  vostok::render::renderer_context_targets *v12; // ecx
  vostok::render::renderer_context_targets *v13; // ecx
  vostok::render::renderer_context_targets *v14; // ecx
  vostok::render::renderer_context_targets *v15; // ecx
  vostok::render::renderer_context_targets *v16; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v17; // ecx
  bool has_passed_filters; // al
  int z_low; // ebx
  vostok::render::backend *v20; // ecx
  int v21; // ebx
  vostok::render::backend *v22; // ecx
  const vostok::render::render_target *v23; // eax
  int v24; // ebx
  vostok::render::backend *v25; // ecx
  int v26; // esi
  vostok::render::backend *v27; // ecx
  int v28; // [esp+8h] [ebp-6Ch]
  vostok::math::uint2 v29; // [esp+Ch] [ebp-68h]
  vostok::math::uint2 v30; // [esp+Ch] [ebp-68h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v31; // [esp+Ch] [ebp-68h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v32; // [esp+18h] [ebp-5Ch] BYREF
  unsigned int v33; // [esp+3Ch] [ebp-38h]
  vostok::render::renderer_context_targets *v34; // [esp+40h] [ebp-34h]
  unsigned int v35; // [esp+44h] [ebp-30h]
  vostok::render::renderer_context_targets *v36; // [esp+48h] [ebp-2Ch]
  unsigned int v37; // [esp+4Ch] [ebp-28h]
  vostok::render::renderer_context_targets *v38; // [esp+50h] [ebp-24h]
  unsigned int v39; // [esp+54h] [ebp-20h]
  vostok::render::renderer_context_targets *v40; // [esp+58h] [ebp-1Ch]
  unsigned int v41; // [esp+5Ch] [ebp-18h] BYREF
  vostok::render::renderer_context_targets *v42; // [esp+60h] [ebp-14h]
  int v43; // [esp+64h] [ebp-10h]
  unsigned int v44; // [esp+68h] [ebp-Ch] BYREF
  vostok::render::renderer_context_targets *v45; // [esp+6Ch] [ebp-8h]
  int v46; // [esp+7Ch] [ebp+8h]

  v43 = 0;
  if ( LOBYTE(size.x) || *(_QWORD *)(a2 + 11680) != __PAIR64__(force_resize, size.y) )
  {
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Flush(vostok::quasi_singleton<vostok::render::device>::pinst->m_context);
    v4 = a2 + 152;
    v46 = 73;
    do
    {
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        0,
        (vostok::render::res_texture *)(v4 + 4));
      vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v4,
        0);
      v4 += 160;
      --v46;
    }
    while ( v46 );
    y = size.y;
    *(_DWORD *)(a2 + 11680) = 1 - ((1 - size.y) & ((1 - (unsigned __int64)size.y) >> 32));
    *(_DWORD *)(a2 + 11688) = vostok::render::renderer_context_targets::s_new_id++;
    *(_DWORD *)(a2 + 11684) = force_resize > 1 ? 1 - force_resize - 1 : -1;
    v33 = y >> 2 > 1 ? 1 - (y >> 2) - 1 : -1;
    v34 = (vostok::render::renderer_context_targets *)(1
                                                     - ((1 - (force_resize >> 2))
                                                      & ((1 - (unsigned __int64)(force_resize >> 2)) >> 32)));
    v6 = y >> 1 > 1 ? 1 - (y >> 1) - 1 : -1;
    v42 = (vostok::render::renderer_context_targets *)(1
                                                     - ((1 - (force_resize >> 1))
                                                      & ((1 - (unsigned __int64)(force_resize >> 1)) >> 32)));
    v41 = v6;
    v44 = 1 - ((1 - (y >> 2)) & ((1 - (unsigned __int64)(y >> 2)) >> 32));
    v45 = v34;
    v35 = 1 - ((1 - (size.y >> 3)) & ((1 - (unsigned __int64)(size.y >> 3)) >> 32));
    v36 = (vostok::render::renderer_context_targets *)(1
                                                     - ((1 - (force_resize >> 3))
                                                      & ((1 - (unsigned __int64)(force_resize >> 3)) >> 32)));
    v39 = 1 - ((1 - (size.y >> 4)) & ((1 - (unsigned __int64)(size.y >> 4)) >> 32));
    *(_DWORD *)(a2 + 11692) = 0;
    v40 = (vostok::render::renderer_context_targets *)(force_resize >> 4 > 1 ? 1 - (force_resize >> 4) - 1 : -1);
    v37 = size.y >> 1 > 1 ? 1 - (size.y >> 1) - 1 : -1;
    v38 = (vostok::render::renderer_context_targets *)(1
                                                     - ((1 - (force_resize >> 1))
                                                      & ((1 - (unsigned __int64)(force_resize >> 1)) >> 32)));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_generic_0,
      (const vostok::math::uint2)0x10000001ALL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_generic_1,
      (const vostok::math::uint2)0x10000001ALL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_present,
      (const vostok::math::uint2)0x10000001CLL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_previous_present,
      (const vostok::math::uint2)0x10000001CLL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_accumulator_diffuse,
      (const vostok::math::uint2)0x10000001ALL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_accumulator_specular,
      (const vostok::math::uint2)0x10000001ALL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_sun_translucensy_help_data,
      (const vostok::math::uint2)0x100000022LL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_normal,
      (const vostok::math::uint2)0x100000022LL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_albedo,
      (const vostok::math::uint2)0x10000001CLL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_surface_parameters,
      (const vostok::math::uint2)0x10000001CLL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_decals_normal_result,
      (const vostok::math::uint2)0x100000022LL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_decals_smoothness_result,
      (const vostok::math::uint2)0x10000001CLL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_normal_copy,
      (const vostok::math::uint2)0x100000022LL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_decals_normal,
      (const vostok::math::uint2)0x10000000ALL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_distortion,
      (const vostok::math::uint2)0x100000022LL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_decals_diffuse,
      (const vostok::math::uint2)0x10000001CLL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_parameters_copy,
      (const vostok::math::uint2)0x10000001CLL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_object_motion_vectors,
      (const vostok::math::uint2)0x10000000ALL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_ssao_accumulator_full_x,
      (const vostok::math::uint2)0x100000031LL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_sun_shadow_and_scattering,
      (const vostok::math::uint2)0x100000031LL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_decals_smoothness,
      (const vostok::math::uint2)0x10000001CLL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_ssao_prev_accumulator_full_x,
      (const vostok::math::uint2)0x100000031LL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_apply_indirect_lighting_ds,
      (const vostok::math::uint2)53LL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_position,
      (const vostok::math::uint2)0x100000036LL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_ssao_accumulator_z,
      (const vostok::math::uint2)0x100000036LL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_ssao_prev_accumulator_z,
      (const vostok::math::uint2)0x100000036LL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_distortion_mask,
      (const vostok::math::uint2)0x10000003DLL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_probe_indices,
      (const vostok::math::uint2)0x10000003DLL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)force_resize,
      a2,
      rt_accumulator_ambient_lights,
      (const vostok::math::uint2)0x10000001CLL,
      size.y,
      (DXGI_FORMAT)force_resize);
    vostok::render::renderer_context_targets::new_rt(
      v42,
      a2,
      rt_local_reflection_result,
      (const vostok::math::uint2)0x10000000ALL,
      v6,
      (DXGI_FORMAT)v42);
    vostok::render::renderer_context_targets::new_rt(
      v42,
      a2,
      rt_bright_pixels_2x,
      (const vostok::math::uint2)0x10000000ALL,
      v6,
      (DXGI_FORMAT)v42);
    vostok::render::renderer_context_targets::new_rt(
      v42,
      a2,
      rt_generic_downsampled_2x,
      (const vostok::math::uint2)0x10000001ALL,
      v6,
      (DXGI_FORMAT)v42);
    vostok::render::renderer_context_targets::new_rt(
      v42,
      a2,
      rt_present_downsampled,
      (const vostok::math::uint2)0x10000001CLL,
      v6,
      (DXGI_FORMAT)v42);
    vostok::render::renderer_context_targets::new_rt(
      v42,
      a2,
      rt_motion_blur_result,
      (const vostok::math::uint2)0x10000001CLL,
      v6,
      (DXGI_FORMAT)v42);
    vostok::render::renderer_context_targets::new_rt(
      v42,
      a2,
      rt_radial_motion_blur_result,
      (const vostok::math::uint2)0x10000001CLL,
      v6,
      (DXGI_FORMAT)v42);
    vostok::render::renderer_context_targets::new_rt(
      v42,
      a2,
      rt_lpv_accumulation,
      (const vostok::math::uint2)0x10000001ALL,
      v6,
      (DXGI_FORMAT)v42);
    vostok::render::renderer_context_targets::new_rt(
      v42,
      a2,
      rt_indirect_lighting_specular,
      (const vostok::math::uint2)0x10000001ALL,
      v6,
      (DXGI_FORMAT)v42);
    vostok::render::renderer_context_targets::new_rt(
      v42,
      a2,
      rt_ssao_accumulator,
      (const vostok::math::uint2)0x100000022LL,
      v6,
      (DXGI_FORMAT)v42);
    vostok::render::renderer_context_targets::new_rt(
      v42,
      a2,
      rt_frame_depth_downsampled,
      (const vostok::math::uint2)0x100000036LL,
      v6,
      (DXGI_FORMAT)v42);
    vostok::render::renderer_context_targets::new_rt(
      v42,
      a2,
      rt_ssao_temporal_mask,
      (const vostok::math::uint2)0x100000031LL,
      v6,
      (DXGI_FORMAT)v42);
    v7 = &v44;
    if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_post_process_quality >= 2 )
      v7 = &v41;
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)v7[1],
      a2,
      rt_light_scattering_mask,
      (const vostok::math::uint2)0x10000003DLL,
      *v7,
      (DXGI_FORMAT)v7[1]);
    v8 = &v44;
    if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_post_process_quality >= 2 )
      v8 = &v41;
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)v8[1],
      a2,
      rt_light_scattering_result,
      (const vostok::math::uint2)0x10000001ALL,
      *v8,
      (DXGI_FORMAT)v8[1]);
    vostok::render::renderer_context_targets::new_rt(
      v42,
      a2,
      rt_rain_result,
      (const vostok::math::uint2)0x10000001CLL,
      v6,
      (DXGI_FORMAT)v42);
    v9 = v44;
    vostok::render::renderer_context_targets::new_rt(
      v45,
      a2,
      rt_generic_downsampled_4x,
      (const vostok::math::uint2)0x10000001ALL,
      v44,
      (DXGI_FORMAT)v45);
    vostok::render::renderer_context_targets::new_rt(
      v38,
      a2,
      rt_particle_lighting,
      (const vostok::math::uint2)0x10000000ALL,
      v37,
      (DXGI_FORMAT)v38);
    vostok::render::renderer_context_targets::new_rt(
      v38,
      a2,
      rt_particle_lighting_depth,
      (const vostok::math::uint2)0x100000036LL,
      v37,
      (DXGI_FORMAT)v38);
    vostok::render::renderer_context_targets::new_rt(
      v45,
      a2,
      rt_frame_lum_scene_downsampled,
      (const vostok::math::uint2)0x10000000ALL,
      v9,
      (DXGI_FORMAT)v45);
    vostok::render::renderer_context_targets::new_rt(
      v45,
      a2,
      rt_bloom_combine,
      (const vostok::math::uint2)0x10000001CLL,
      v9,
      (DXGI_FORMAT)v45);
    vostok::render::renderer_context_targets::new_rt(
      v40,
      a2,
      rt_final_frame_downsampled,
      (const vostok::math::uint2)0x10000000ALL,
      v39,
      (DXGI_FORMAT)v40);
    vostok::render::renderer_context_targets::new_rt(
      v40,
      a2,
      rt_final_frame_downsampled_temp,
      (const vostok::math::uint2)0x10000000ALL,
      v39,
      (DXGI_FORMAT)v40);
    vostok::render::renderer_context_targets::new_rt(
      v45,
      a2,
      rt_bloom_4x,
      (const vostok::math::uint2)0x10000000ALL,
      v44,
      (DXGI_FORMAT)v45);
    vostok::render::renderer_context_targets::new_rt(
      v36,
      a2,
      rt_bloom_8x,
      (const vostok::math::uint2)0x10000000ALL,
      v35,
      (DXGI_FORMAT)v36);
    vostok::render::renderer_context_targets::new_rt(
      v40,
      a2,
      rt_bloom_16x,
      (const vostok::math::uint2)0x10000000ALL,
      v39,
      (DXGI_FORMAT)v40);
    vostok::render::renderer_context_targets::new_rt(
      v45,
      a2,
      rt_bloom_temp_4x,
      (const vostok::math::uint2)0x10000000ALL,
      v44,
      (DXGI_FORMAT)v45);
    vostok::render::renderer_context_targets::new_rt(
      v36,
      a2,
      rt_bloom_temp_8x,
      (const vostok::math::uint2)0x10000000ALL,
      v35,
      (DXGI_FORMAT)v36);
    vostok::render::renderer_context_targets::new_rt(
      v40,
      a2,
      rt_bloom_temp_16x,
      (const vostok::math::uint2)0x10000000ALL,
      v39,
      (DXGI_FORMAT)v40);
    vostok::render::renderer_context_targets::new_rt(
      v34,
      a2,
      rt_lens_flares,
      (const vostok::math::uint2)0x10000000ALL,
      v33,
      (DXGI_FORMAT)v34);
    vostok::render::renderer_context_targets::new_rt(
      v10,
      a2,
      rt_frame_luminance0,
      (const vostok::math::uint2)0x100000002LL,
      1u,
      DXGI_FORMAT_R32G32B32A32_TYPELESS);
    vostok::render::renderer_context_targets::new_rt(
      v11,
      a2,
      rt_frame_luminance1,
      (const vostok::math::uint2)0x100000002LL,
      2u,
      DXGI_FORMAT_R32G32B32A32_FLOAT);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)4,
      a2,
      rt_frame_luminance2,
      (const vostok::math::uint2)0x100000002LL,
      4u,
      DXGI_FORMAT_R32G32B32A32_SINT);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)8,
      a2,
      rt_frame_luminance3,
      (const vostok::math::uint2)0x100000002LL,
      8u,
      DXGI_FORMAT_R32G32B32_SINT);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x10,
      a2,
      rt_frame_luminance4,
      (const vostok::math::uint2)0x100000002LL,
      0x10u,
      DXGI_FORMAT_R32G32_FLOAT);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x20,
      a2,
      rt_frame_luminance5,
      (const vostok::math::uint2)0x100000002LL,
      0x20u,
      DXGI_FORMAT_R8G8B8A8_SINT);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x40,
      a2,
      rt_frame_luminance6,
      (const vostok::math::uint2)0x100000002LL,
      0x40u,
      DXGI_FORMAT_R8_SINT);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x80,
      a2,
      rt_frame_luminance7,
      (const vostok::math::uint2)0x100000002LL,
      0x80u,
      (DXGI_FORMAT)128);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x100,
      a2,
      rt_frame_luminance8,
      (const vostok::math::uint2)0x100000002LL,
      0x100u,
      (DXGI_FORMAT)256);
    vostok::render::renderer_context_targets::new_rt(
      v12,
      a2,
      rt_frame_luminance_current,
      (const vostok::math::uint2)0x100000002LL,
      1u,
      DXGI_FORMAT_R32G32B32A32_TYPELESS);
    vostok::render::renderer_context_targets::new_rt(
      v13,
      a2,
      rt_frame_luminance_previous,
      (const vostok::math::uint2)0x100000002LL,
      1u,
      DXGI_FORMAT_R32G32B32A32_TYPELESS);
    vostok::render::renderer_context_targets::new_rt(
      v14,
      a2,
      rt_frame_luminance_histogram,
      (const vostok::math::uint2)0x100000002LL,
      0x10u,
      DXGI_FORMAT_R32G32B32A32_TYPELESS);
    v29.x = 1;
    vostok::render::renderer_context_targets::new_lt((vostok::render::renderer_context_targets *)0x47, a2, 0x10u, v29);
    v30.x = 1;
    vostok::render::renderer_context_targets::new_lt((vostok::render::renderer_context_targets *)0x48, a2, 0x10u, v30);
    vostok::render::renderer_context_targets::new_rt(
      v15,
      a2,
      rt_mie_scattering,
      (const vostok::math::uint2)0x10000000ALL,
      0x100u,
      (DXGI_FORMAT)128);
    vostok::render::renderer_context_targets::new_rt(
      v16,
      a2,
      rt_rayleigh_scattering,
      (const vostok::math::uint2)0x10000000ALL,
      0x100u,
      (DXGI_FORMAT)128);
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"render_pc_dx11",
                                 (const char *)4),
          v17 = v31,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v17,
        &v32);
      v28 = *(_DWORD *)(a2 + 11692) >> 20;
      v43 = 1;
      vostok::logging::append(
        &v32,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\renderer_context_targets.cpp",
        0x151u,
        "void __thiscall vostok::render::renderer_context_targets::create_targets(class vostok::math::uint2,bool)",
        "render_pc_dx11",
        info,
        "render targets memory usage: %d",
        v28);
    }
    if ( (v43 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v17,
        (int *)&v32);
    z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      *(const vostok::render::render_target **)(a2 + 8952),
      0,
      0,
      0);
    vostok::render::backend::clear_render_targets(v20, z_low, SLODWORD(FLOAT_0_25), 0.25, 0.25, 0.25);
    v21 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      *(const vostok::render::render_target **)(a2 + 9112),
      0,
      0,
      0);
    vostok::render::backend::clear_render_targets(v22, v21, SLODWORD(FLOAT_0_25), 0.25, 0.25, 0.25);
    v23 = *(const vostok::render::render_target **)(a2 + 3992);
    if ( v23 )
    {
      v24 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
      vostok::render::backend::set_render_targets(
        (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        v23,
        0,
        0,
        0);
      vostok::render::backend::clear_render_targets(v25, v24, SLODWORD(s_bm_current_air_resistance), 0.0, 0.0, 0.0);
      v26 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
      vostok::render::backend::set_render_targets(
        (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        *(const vostok::render::render_target **)(a2 + 4312),
        0,
        0,
        0);
      vostok::render::backend::clear_render_targets(v27, v26, 0, 0.0, 0.0, 0.0);
    }
  }
}
