void __userpurge vostok::render::renderer::recreate_stage(
        vostok::render::renderer *this@<ecx>,
        int a2@<eax>,
        unsigned int a3@<ebp>,
        unsigned int a4@<esi>,
        vostok::render::renderer *thisa)
{
  vostok::render::stage_gbuffer *v5; // esi
  vostok::render::stage *v6; // eax
  vostok::render::stage_decals_accumulate *v7; // esi
  int v8; // eax
  vostok::render::stage_accumulate_distortion *v9; // eax
  int v10; // eax
  vostok::render::stage_pre_rain *v11; // edi
  int v12; // eax
  _DWORD *v13; // eax
  vostok::render::stage_ambient_occlusion *v14; // esi
  int v15; // eax
  vostok::render::stage_ambient_lighting *v16; // eax
  int v17; // eax
  vostok::render::stage_shadow_direct *v18; // eax
  int v19; // eax
  vostok::render::stage_sun *v20; // eax
  int v21; // eax
  vostok::render::stage_lights *v22; // eax
  int v23; // eax
  vostok::render::stage_light_propagation_volumes *v24; // eax
  int v25; // eax
  vostok::render::stage_translucency *v26; // esi
  int v27; // eax
  vostok::render::stage_resolve_lighting *v28; // esi
  int v29; // eax
  vostok::render::stage_clouds *v30; // eax
  int v31; // eax
  vostok::render::stage_atmosphere *v32; // esi
  int v33; // eax
  vostok::render::stage_forward *v34; // esi
  int v35; // eax
  vostok::render::stage_atmosphere *v36; // esi
  int v37; // eax
  vostok::render::stage_apply_distortion *v38; // esi
  int v39; // eax
  vostok::render::stage_forward *v40; // esi
  int v41; // eax
  vostok::render::stage_rain *v42; // edi
  int v43; // eax
  vostok::render::stage_particles *v44; // esi
  int v45; // eax
  vostok::render::stage_lights *v46; // eax
  int v47; // eax
  vostok::render::stage_volume_fog *v48; // esi
  int v49; // eax
  vostok::render::stage_postprocess *v50; // eax
  int v51; // eax

  switch ( a2 )
  {
    case 0:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v5 = (vostok::render::stage_gbuffer *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              0x7Cu);
      if ( v5 )
      {
        vostok::render::stage_gbuffer::stage_gbuffer(v5, thisa, thisa->m_renderer_context);
        *thisa->m_stages.m_begin = v6;
      }
      else
      {
        *thisa->m_stages.m_begin = 0;
      }
      break;
    case 1:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 1,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v7 = (vostok::render::stage_decals_accumulate *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                        0x18u);
      if ( v7 )
      {
        vostok::render::stage_decals_accumulate::stage_decals_accumulate(v7, thisa, thisa->m_renderer_context);
        *((_DWORD *)thisa->m_stages.m_begin + 1) = v8;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 1) = 0;
      }
      break;
    case 2:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 2,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v9 = (vostok::render::stage_accumulate_distortion *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                            0x10u);
      if ( v9 )
      {
        vostok::render::stage_accumulate_distortion::stage_accumulate_distortion(v9, thisa, thisa->m_renderer_context);
        *((_DWORD *)thisa->m_stages.m_begin + 2) = v10;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 2) = 0;
      }
      break;
    case 3:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 3,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v11 = (vostok::render::stage_pre_rain *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                0x3Cu);
      if ( v11 )
      {
        vostok::render::stage_pre_rain::stage_pre_rain(v11, thisa, thisa->m_renderer_context, a3, a4);
        *((_DWORD *)thisa->m_stages.m_begin + 3) = v12;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 3) = 0;
      }
      break;
    case 4:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 4,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v13 = vostok::memory::doug_lea_allocator::malloc_impl(
              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
              0x10u);
      if ( v13 )
      {
        v13[1] = thisa->m_renderer_context;
        v13[2] = thisa;
        *((_BYTE *)v13 + 12) = 1;
        *((_BYTE *)v13 + 13) = 1;
        *v13 = &vostok::render::stage_pre_lighting::`vftable';
        *((_DWORD *)thisa->m_stages.m_begin + 4) = v13;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 4) = 0;
      }
      break;
    case 5:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 5,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v14 = (vostok::render::stage_ambient_occlusion *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                         0x40u);
      if ( v14 )
      {
        vostok::render::stage_ambient_occlusion::stage_ambient_occlusion(v14, thisa, thisa->m_renderer_context);
        *((_DWORD *)thisa->m_stages.m_begin + 5) = v15;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 5) = 0;
      }
      break;
    case 6:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 6,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v16 = (vostok::render::stage_ambient_lighting *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                        0xA4u);
      if ( v16 )
      {
        vostok::render::stage_ambient_lighting::stage_ambient_lighting(thisa, thisa->m_renderer_context, v16);
        *((_DWORD *)thisa->m_stages.m_begin + 6) = v17;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 6) = 0;
      }
      break;
    case 7:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 7,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v18 = (vostok::render::stage_shadow_direct *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                     (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                     0xABCu);
      if ( v18 )
      {
        vostok::render::stage_shadow_direct::stage_shadow_direct(thisa, thisa->m_renderer_context, v18);
        *((_DWORD *)thisa->m_stages.m_begin + 7) = v19;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 7) = 0;
      }
      break;
    case 8:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 8,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v20 = (vostok::render::stage_sun *)vostok::memory::doug_lea_allocator::malloc_impl(
                                           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                           0x78u);
      if ( v20 )
      {
        vostok::render::stage_sun::stage_sun(
          thisa,
          thisa->m_renderer_context,
          v20,
          &thisa->m_cloud_interp_textures,
          &thisa->m_simulation);
        *((_DWORD *)thisa->m_stages.m_begin + 8) = v21;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 8) = 0;
      }
      break;
    case 9:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 9,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v22 = (vostok::render::stage_lights *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              0x9E8u);
      if ( v22 )
      {
        vostok::render::stage_lights::stage_lights(thisa, thisa->m_renderer_context, v22, 0);
        *((_DWORD *)thisa->m_stages.m_begin + 9) = v23;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 9) = 0;
      }
      break;
    case 10:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 10,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v24 = (vostok::render::stage_light_propagation_volumes *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                                 (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                                 0x360u);
      if ( v24 )
      {
        vostok::render::stage_light_propagation_volumes::stage_light_propagation_volumes(
          thisa,
          thisa->m_renderer_context,
          v24);
        *((_DWORD *)thisa->m_stages.m_begin + 10) = v25;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 10) = 0;
      }
      break;
    case 11:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 11,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v26 = (vostok::render::stage_translucency *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                    (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                    0x30u);
      if ( v26 )
      {
        vostok::render::stage_translucency::stage_translucency(v26, thisa, thisa->m_renderer_context);
        *((_DWORD *)thisa->m_stages.m_begin + 11) = v27;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 11) = 0;
      }
      break;
    case 12:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 12,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v28 = (vostok::render::stage_resolve_lighting *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                        0x20u);
      if ( v28 )
      {
        vostok::render::stage_resolve_lighting::stage_resolve_lighting(v28, thisa, thisa->m_renderer_context);
        *((_DWORD *)thisa->m_stages.m_begin + 12) = v29;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 12) = 0;
      }
      break;
    case 13:
    case 14:
      return;
    case 15:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 15,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v30 = (vostok::render::stage_clouds *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              0x1B8u);
      if ( v30 )
      {
        vostok::render::stage_clouds::stage_clouds(
          thisa,
          thisa->m_renderer_context,
          v30,
          &thisa->m_cloud_interp_textures,
          &thisa->m_simulation);
        *((_DWORD *)thisa->m_stages.m_begin + 15) = v31;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 15) = 0;
      }
      break;
    case 16:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 16,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v32 = (vostok::render::stage_atmosphere *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                  (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                  0x6Cu);
      if ( v32 )
      {
        vostok::render::stage_atmosphere::stage_atmosphere(v32, thisa, thisa->m_renderer_context, 0);
        *((_DWORD *)thisa->m_stages.m_begin + 16) = v33;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 16) = 0;
      }
      break;
    case 17:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 17,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v34 = (vostok::render::stage_forward *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               0x8Cu);
      if ( v34 )
      {
        vostok::render::stage_forward::stage_forward(v34, thisa, thisa->m_renderer_context, forward_base);
        *((_DWORD *)thisa->m_stages.m_begin + 17) = v35;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 17) = 0;
      }
      break;
    case 18:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 18,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v36 = (vostok::render::stage_atmosphere *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                  (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                  0x6Cu);
      if ( v36 )
      {
        vostok::render::stage_atmosphere::stage_atmosphere(
          v36,
          thisa,
          thisa->m_renderer_context,
          (vostok::strings::shared::profile *)1);
        *((_DWORD *)thisa->m_stages.m_begin + 18) = v37;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 18) = 0;
      }
      break;
    case 19:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 19,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v38 = (vostok::render::stage_apply_distortion *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                        0x14u);
      if ( v38 )
      {
        vostok::render::stage_apply_distortion::stage_apply_distortion(v38, thisa, thisa->m_renderer_context);
        *((_DWORD *)thisa->m_stages.m_begin + 19) = v39;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 19) = 0;
      }
      break;
    case 20:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 20,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v40 = (vostok::render::stage_forward *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               0x8Cu);
      if ( v40 )
      {
        vostok::render::stage_forward::stage_forward(v40, thisa, thisa->m_renderer_context, forward_sky);
        *((_DWORD *)thisa->m_stages.m_begin + 20) = v41;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 20) = 0;
      }
      break;
    case 21:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 21,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v42 = (vostok::render::stage_rain *)vostok::memory::doug_lea_allocator::malloc_impl(
                                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                            0x38Cu);
      if ( v42 )
      {
        vostok::render::stage_rain::stage_rain(v42, thisa, thisa->m_renderer_context);
        *((_DWORD *)thisa->m_stages.m_begin + 21) = v43;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 21) = 0;
      }
      break;
    case 22:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 22,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v46 = (vostok::render::stage_lights *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              0x9E8u);
      if ( v46 )
      {
        vostok::render::stage_lights::stage_lights(
          thisa,
          thisa->m_renderer_context,
          v46,
          (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>)1);
        *((_DWORD *)thisa->m_stages.m_begin + 22) = v47;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 22) = 0;
      }
      break;
    case 23:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 23,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v44 = (vostok::render::stage_particles *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                 (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                 0x2Cu);
      if ( v44 )
      {
        vostok::render::stage_particles::stage_particles(v44, thisa, thisa->m_renderer_context);
        *((_DWORD *)thisa->m_stages.m_begin + 23) = v45;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 23) = 0;
      }
      break;
    case 24:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 24,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v48 = (vostok::render::stage_volume_fog *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                  (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                  0x60u);
      if ( v48 )
      {
        vostok::render::stage_volume_fog::stage_volume_fog(v48, thisa, thisa->m_renderer_context);
        *((_DWORD *)thisa->m_stages.m_begin + 24) = v49;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 24) = 0;
      }
      break;
    case 25:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        thisa->m_stages.m_begin + 25,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
      v50 = (vostok::render::stage_postprocess *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                   (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                   0x23Cu);
      if ( v50 )
      {
        vostok::render::stage_postprocess::stage_postprocess(thisa, thisa->m_renderer_context, v50);
        *((_DWORD *)thisa->m_stages.m_begin + 25) = v51;
      }
      else
      {
        *((_DWORD *)thisa->m_stages.m_begin + 25) = 0;
      }
      break;
  }
}
