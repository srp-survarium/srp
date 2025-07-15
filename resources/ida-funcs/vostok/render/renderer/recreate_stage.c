void __userpurge vostok::render::renderer::recreate_stage(
        vostok::render::renderer *this@<ecx>,
        int a2@<eax>,
        vostok::render::renderer *thisa)
{
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  char *v6; // eax
  vostok::render::stage *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // esi
  char *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // ecx
  char *v11; // eax
  int v12; // eax
  vostok::memory::doug_lea_allocator *v13; // esi
  char *v14; // eax
  vostok::memory::doug_lea_allocator *v15; // ecx
  char *v16; // eax
  int v17; // eax
  vostok::memory::doug_lea_allocator *v18; // esi
  char *v19; // eax
  vostok::memory::doug_lea_allocator *v20; // ecx
  char *v21; // eax
  _DWORD *v22; // eax
  vostok::memory::doug_lea_allocator *v23; // esi
  char *v24; // eax
  vostok::memory::doug_lea_allocator *v25; // ecx
  char *v26; // eax
  int v27; // eax
  vostok::memory::doug_lea_allocator *v28; // esi
  char *v29; // eax
  vostok::memory::doug_lea_allocator *v30; // ecx
  char *v31; // eax
  int v32; // eax
  vostok::memory::doug_lea_allocator *v33; // esi
  char *v34; // eax
  vostok::memory::doug_lea_allocator *v35; // ecx
  char *v36; // eax
  int v37; // eax
  vostok::render::stage_lights *v38; // eax
  int v39; // eax
  vostok::memory::doug_lea_allocator *v40; // esi
  char *v41; // eax
  vostok::memory::doug_lea_allocator *v42; // ecx
  char *v43; // eax
  int v44; // eax
  vostok::memory::doug_lea_allocator *v45; // esi
  char *v46; // eax
  vostok::memory::doug_lea_allocator *v47; // ecx
  char *v48; // eax
  int v49; // eax
  vostok::memory::doug_lea_allocator *v50; // esi
  char *v51; // eax
  vostok::memory::doug_lea_allocator *v52; // ecx
  char *v53; // eax
  int v54; // eax
  vostok::render::stage_forward *v55; // eax
  int v56; // eax
  vostok::memory::doug_lea_allocator *v57; // esi
  char *v58; // eax
  vostok::memory::doug_lea_allocator *v59; // ecx
  char *v60; // eax
  int v61; // eax
  vostok::memory::doug_lea_allocator *v62; // esi
  char *v63; // eax
  vostok::memory::doug_lea_allocator *v64; // ecx
  char *v65; // eax
  int v66; // eax
  vostok::render::stage_forward *v67; // eax
  int v68; // eax
  vostok::memory::doug_lea_allocator *v69; // esi
  char *v70; // eax
  vostok::memory::doug_lea_allocator *v71; // ecx
  char *v72; // eax
  int v73; // eax
  vostok::memory::doug_lea_allocator *v74; // esi
  char *v75; // eax
  vostok::memory::doug_lea_allocator *v76; // ecx
  char *v77; // eax
  int v78; // eax
  vostok::memory::doug_lea_allocator *v79; // esi
  char *v80; // eax
  vostok::memory::doug_lea_allocator *v81; // ecx
  char *v82; // eax
  int v83; // eax
  vostok::render::stage_lights *v84; // eax
  int v85; // eax
  vostok::memory::doug_lea_allocator *v86; // esi
  char *v87; // eax
  vostok::memory::doug_lea_allocator *v88; // ecx
  char *v89; // eax
  int v90; // eax
  vostok::memory::doug_lea_allocator *v91; // esi
  char *v92; // eax
  vostok::memory::doug_lea_allocator *v93; // ecx
  char *v94; // eax
  int v95; // eax
  vostok::memory::doug_lea_allocator *v96; // esi
  char *v97; // eax
  vostok::memory::doug_lea_allocator *v98; // ecx
  char *v99; // eax
  int v100; // eax
  vostok::memory::doug_lea_allocator *v101; // esi
  char *v102; // eax
  vostok::memory::doug_lea_allocator *v103; // ecx
  char *v104; // eax
  int v105; // eax
  vostok::render::surface_effect_parameters v106; // [esp-4h] [ebp-14h]
  vostok::render::surface_effect_parameters v107; // [esp-4h] [ebp-14h]
  const char *v108; // [esp+0h] [ebp-10h]
  const char *v109; // [esp+0h] [ebp-10h]
  const char *v110; // [esp+0h] [ebp-10h]
  const char *v111; // [esp+0h] [ebp-10h]
  const char *v112; // [esp+0h] [ebp-10h]
  const char *v113; // [esp+0h] [ebp-10h]
  const char *v114; // [esp+0h] [ebp-10h]
  const char *v115; // [esp+0h] [ebp-10h]
  const char *v116; // [esp+0h] [ebp-10h]
  const char *v117; // [esp+0h] [ebp-10h]
  const char *v118; // [esp+0h] [ebp-10h]
  const char *v119; // [esp+0h] [ebp-10h]
  const char *v120; // [esp+0h] [ebp-10h]
  const char *v121; // [esp+0h] [ebp-10h]
  const char *v122; // [esp+0h] [ebp-10h]
  const char *v123; // [esp+0h] [ebp-10h]
  const char *v124; // [esp+0h] [ebp-10h]
  const char *v125; // [esp+0h] [ebp-10h]
  const char *v126; // [esp+0h] [ebp-10h]
  const char *v127; // [esp+0h] [ebp-10h]
  const char *v128; // [esp+0h] [ebp-10h]
  const char *v129; // [esp+0h] [ebp-10h]
  const char *v130; // [esp+4h] [ebp-Ch]
  const char *v131; // [esp+4h] [ebp-Ch]
  const char *v132; // [esp+4h] [ebp-Ch]
  const char *v133; // [esp+4h] [ebp-Ch]
  const char *v134; // [esp+4h] [ebp-Ch]
  const char *v135; // [esp+4h] [ebp-Ch]
  const char *v136; // [esp+4h] [ebp-Ch]
  const char *v137; // [esp+4h] [ebp-Ch]
  const char *v138; // [esp+4h] [ebp-Ch]
  const char *v139; // [esp+4h] [ebp-Ch]
  const char *v140; // [esp+4h] [ebp-Ch]
  const char *v141; // [esp+4h] [ebp-Ch]
  const char *v142; // [esp+4h] [ebp-Ch]
  const char *v143; // [esp+4h] [ebp-Ch]
  const char *v144; // [esp+4h] [ebp-Ch]
  const char *v145; // [esp+4h] [ebp-Ch]
  const char *v146; // [esp+4h] [ebp-Ch]
  const char *v147; // [esp+4h] [ebp-Ch]
  const char *v148; // [esp+4h] [ebp-Ch]
  const char *v149; // [esp+4h] [ebp-Ch]
  const char *v150; // [esp+4h] [ebp-Ch]
  const char *v151; // [esp+4h] [ebp-Ch]
  unsigned int v152; // [esp+8h] [ebp-8h]
  unsigned int v153; // [esp+8h] [ebp-8h]
  unsigned int v154; // [esp+8h] [ebp-8h]
  unsigned int v155; // [esp+8h] [ebp-8h]
  unsigned int v156; // [esp+8h] [ebp-8h]
  unsigned int v157; // [esp+8h] [ebp-8h]
  unsigned int v158; // [esp+8h] [ebp-8h]
  unsigned int v159; // [esp+8h] [ebp-8h]
  unsigned int v160; // [esp+8h] [ebp-8h]
  unsigned int v161; // [esp+8h] [ebp-8h]
  unsigned int v162; // [esp+8h] [ebp-8h]
  unsigned int v163; // [esp+8h] [ebp-8h]
  unsigned int v164; // [esp+8h] [ebp-8h]
  unsigned int v165; // [esp+8h] [ebp-8h]
  unsigned int v166; // [esp+8h] [ebp-8h]
  unsigned int v167; // [esp+8h] [ebp-8h]
  unsigned int v168; // [esp+8h] [ebp-8h]
  unsigned int v169; // [esp+8h] [ebp-8h]
  unsigned int v170; // [esp+8h] [ebp-8h]
  unsigned int v171; // [esp+8h] [ebp-8h]
  unsigned int v172; // [esp+8h] [ebp-8h]
  unsigned int v173; // [esp+8h] [ebp-8h]

  switch ( a2 )
  {
    case 0:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin,
        v108,
        v130,
        v152);
      v3 = vostok::render::g_allocator;
      v4 = type_info::raw_name(&vostok::render::stage_shadow_direct `RTTI Type Descriptor');
      v6 = vostok::memory::doug_lea_allocator::malloc_impl(v5, (int)v3, (unsigned int)&loc_40C88, v4, v109, v131, v153);
      if ( v6 )
        vostok::render::stage_shadow_direct::stage_shadow_direct(
          thisa->m_renderer_context,
          (vostok::render::stage_shadow_direct *)v6,
          thisa);
      else
        v7 = 0;
      *thisa->m_stages.m_begin = v7;
      break;
    case 1:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 1,
        v108,
        v130,
        v152);
      v8 = vostok::render::g_allocator;
      v9 = type_info::raw_name(&vostok::render::stage_gbuffer `RTTI Type Descriptor');
      v11 = vostok::memory::doug_lea_allocator::malloc_impl(v10, (int)v8, 0x6Cu, v9, v110, v132, v154);
      if ( v11 )
        vostok::render::stage_gbuffer::stage_gbuffer(
          thisa->m_renderer_context,
          (vostok::render::stage_gbuffer *)v11,
          thisa);
      else
        v12 = 0;
      *((_DWORD *)thisa->m_stages.m_begin + 1) = v12;
      break;
    case 2:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 2,
        v108,
        v130,
        v152);
      v13 = vostok::render::g_allocator;
      v14 = type_info::raw_name(&vostok::render::stage_decals_accumulate `RTTI Type Descriptor');
      v16 = vostok::memory::doug_lea_allocator::malloc_impl(v15, (int)v13, 0x18u, v14, v111, v133, v155);
      if ( v16 )
        vostok::render::stage_decals_accumulate::stage_decals_accumulate(
          (vostok::render::stage_decals_accumulate *)v16,
          thisa->m_renderer_context,
          thisa);
      else
        v17 = 0;
      *((_DWORD *)thisa->m_stages.m_begin + 2) = v17;
      break;
    case 3:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 3,
        v108,
        v130,
        v152);
      v18 = vostok::render::g_allocator;
      v19 = type_info::raw_name(&vostok::render::stage_accumulate_distortion `RTTI Type Descriptor');
      v21 = vostok::memory::doug_lea_allocator::malloc_impl(v20, (int)v18, 0x10u, v19, v112, v134, v156);
      if ( v21 )
      {
        vostok::render::stage::stage((vostok::render::stage *)v21, thisa->m_renderer_context, thisa);
        *v22 = &vostok::render::stage_accumulate_distortion::`vftable';
      }
      else
      {
        v22 = 0;
      }
      *((_DWORD *)thisa->m_stages.m_begin + 3) = v22;
      break;
    case 4:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 4,
        v108,
        v130,
        v152);
      v23 = vostok::render::g_allocator;
      v24 = type_info::raw_name(&vostok::render::stage_pre_rain `RTTI Type Descriptor');
      v26 = vostok::memory::doug_lea_allocator::malloc_impl(v25, (int)v23, 0x3Cu, v24, v113, v135, v157);
      if ( v26 )
        vostok::render::stage_pre_rain::stage_pre_rain(
          thisa->m_renderer_context,
          (vostok::render::stage_pre_rain *)v26,
          thisa);
      else
        v27 = 0;
      *((_DWORD *)thisa->m_stages.m_begin + 4) = v27;
      break;
    case 5:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 5,
        v108,
        v130,
        v152);
      v28 = vostok::render::g_allocator;
      v29 = type_info::raw_name(&vostok::render::stage_ambient_occlusion `RTTI Type Descriptor');
      v31 = vostok::memory::doug_lea_allocator::malloc_impl(v30, (int)v28, 0x40u, v29, v114, v136, v158);
      if ( v31 )
        vostok::render::stage_ambient_occlusion::stage_ambient_occlusion(
          (vostok::render::stage_ambient_occlusion *)v31,
          thisa->m_renderer_context,
          thisa);
      else
        v32 = 0;
      *((_DWORD *)thisa->m_stages.m_begin + 5) = v32;
      break;
    case 6:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 6,
        v108,
        v130,
        v152);
      v33 = vostok::render::g_allocator;
      v34 = type_info::raw_name(&vostok::render::stage_ambient_lighting `RTTI Type Descriptor');
      v36 = vostok::memory::doug_lea_allocator::malloc_impl(v35, (int)v33, 0x104u, v34, v115, v137, v159);
      if ( v36 )
        vostok::render::stage_ambient_lighting::stage_ambient_lighting(
          thisa->m_renderer_context,
          (vostok::render::stage_ambient_lighting *)v36,
          thisa);
      else
        v37 = 0;
      *((_DWORD *)thisa->m_stages.m_begin + 6) = v37;
      break;
    case 7:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 7,
        v108,
        v130,
        v152);
      v38 = (vostok::render::stage_lights *)vostok::memory::new_helper<vostok::render::stage_lights>::call<vostok::memory::doug_lea_allocator>(
                                              vostok::render::g_allocator,
                                              v116,
                                              v138,
                                              v160);
      if ( v38 )
        vostok::render::stage_lights::stage_lights(thisa->m_renderer_context, v38, thisa, 0);
      else
        v39 = 0;
      *((_DWORD *)thisa->m_stages.m_begin + 7) = v39;
      break;
    case 8:
    case 11:
      return;
    case 9:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 9,
        v108,
        v130,
        v152);
      v40 = vostok::render::g_allocator;
      v41 = type_info::raw_name(&vostok::render::stage_shadow_mask `RTTI Type Descriptor');
      v43 = vostok::memory::doug_lea_allocator::malloc_impl(v42, (int)v40, 0x70u, v41, v117, v139, v161);
      if ( v43 )
        vostok::render::stage_shadow_mask::stage_shadow_mask(
          thisa->m_renderer_context,
          (vostok::render::stage_shadow_mask *)v43,
          thisa);
      else
        v44 = 0;
      *((_DWORD *)thisa->m_stages.m_begin + 9) = v44;
      break;
    case 10:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 10,
        v108,
        v130,
        v152);
      v45 = vostok::render::g_allocator;
      v46 = type_info::raw_name(&vostok::render::stage_composition `RTTI Type Descriptor');
      v48 = vostok::memory::doug_lea_allocator::malloc_impl(v47, (int)v45, 0x4Cu, v46, v118, v140, v162);
      if ( v48 )
        vostok::render::stage_composition::stage_composition(
          thisa->m_renderer_context,
          (vostok::render::stage_composition *)v48,
          thisa);
      else
        v49 = 0;
      *((_DWORD *)thisa->m_stages.m_begin + 10) = v49;
      break;
    case 12:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 12,
        v108,
        v130,
        v152);
      v50 = vostok::render::g_allocator;
      v51 = type_info::raw_name(&vostok::render::stage_atmosphere `RTTI Type Descriptor');
      v53 = vostok::memory::doug_lea_allocator::malloc_impl(v52, (int)v50, 0x7Cu, v51, v119, v141, v163);
      if ( v53 )
        vostok::render::stage_atmosphere::stage_atmosphere(
          thisa->m_renderer_context,
          (vostok::render::stage_atmosphere *)v53,
          thisa,
          atmosphere_on_sky);
      else
        v54 = 0;
      *((_DWORD *)thisa->m_stages.m_begin + 12) = v54;
      break;
    case 13:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 13,
        v108,
        v130,
        v152);
      v57 = vostok::render::g_allocator;
      v58 = type_info::raw_name(&vostok::render::stage_atmosphere `RTTI Type Descriptor');
      v60 = vostok::memory::doug_lea_allocator::malloc_impl(v59, (int)v57, 0x7Cu, v58, v120, v142, v164);
      if ( v60 )
        vostok::render::stage_atmosphere::stage_atmosphere(
          thisa->m_renderer_context,
          (vostok::render::stage_atmosphere *)v60,
          thisa,
          atmosphere_on_geometry);
      else
        v61 = 0;
      *((_DWORD *)thisa->m_stages.m_begin + 13) = v61;
      break;
    case 14:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 14,
        v108,
        v130,
        v152);
      v67 = (vostok::render::stage_forward *)vostok::memory::new_helper<vostok::render::stage_forward>::call<vostok::memory::doug_lea_allocator>(
                                               vostok::render::g_allocator,
                                               (const char *const)v107.cull_mode,
                                               (const char *const)v107.draw_to_gbuffer,
                                               v107.blend_mode);
      if ( v67 )
      {
        v107.vertex_input_type = 1;
        vostok::render::stage_forward::stage_forward(
          thisa->m_renderer_context,
          v67,
          (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)thisa,
          v107);
      }
      else
      {
        v68 = 0;
      }
      *((_DWORD *)thisa->m_stages.m_begin + 14) = v68;
      break;
    case 15:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 15,
        v108,
        v130,
        v152);
      v96 = vostok::render::g_allocator;
      v97 = type_info::raw_name(&vostok::render::stage_screen_space_reflections `RTTI Type Descriptor');
      v99 = vostok::memory::doug_lea_allocator::malloc_impl(v98, (int)v96, 0x38u, v97, v128, v150, v172);
      if ( v99 )
        vostok::render::stage_screen_space_reflections::stage_screen_space_reflections(
          (vostok::render::stage_screen_space_reflections *)v99,
          thisa->m_renderer_context,
          thisa);
      else
        v100 = 0;
      *((_DWORD *)thisa->m_stages.m_begin + 15) = v100;
      break;
    case 16:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 16,
        v108,
        v130,
        v152);
      v55 = (vostok::render::stage_forward *)vostok::memory::new_helper<vostok::render::stage_forward>::call<vostok::memory::doug_lea_allocator>(
                                               vostok::render::g_allocator,
                                               (const char *const)v106.cull_mode,
                                               (const char *const)v106.draw_to_gbuffer,
                                               v106.blend_mode);
      if ( v55 )
      {
        v106.vertex_input_type = 0;
        vostok::render::stage_forward::stage_forward(
          thisa->m_renderer_context,
          v55,
          (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)thisa,
          v106);
      }
      else
      {
        v56 = 0;
      }
      *((_DWORD *)thisa->m_stages.m_begin + 16) = v56;
      break;
    case 17:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 17,
        v108,
        v130,
        v152);
      v84 = (vostok::render::stage_lights *)vostok::memory::new_helper<vostok::render::stage_lights>::call<vostok::memory::doug_lea_allocator>(
                                              vostok::render::g_allocator,
                                              v125,
                                              v147,
                                              v169);
      if ( v84 )
        vostok::render::stage_lights::stage_lights(thisa->m_renderer_context, v84, thisa, 1);
      else
        v85 = 0;
      *((_DWORD *)thisa->m_stages.m_begin + 17) = v85;
      break;
    case 18:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 18,
        v108,
        v130,
        v152);
      v69 = vostok::render::g_allocator;
      v70 = type_info::raw_name(&vostok::render::stage_rain `RTTI Type Descriptor');
      v72 = vostok::memory::doug_lea_allocator::malloc_impl(v71, (int)v69, 0x38Cu, v70, v122, v144, v166);
      if ( v72 )
        vostok::render::stage_rain::stage_rain(thisa->m_renderer_context, (vostok::render::stage_rain *)v72, thisa);
      else
        v73 = 0;
      *((_DWORD *)thisa->m_stages.m_begin + 18) = v73;
      break;
    case 19:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 19,
        v108,
        v130,
        v152);
      v79 = vostok::render::g_allocator;
      v80 = type_info::raw_name(&vostok::render::stage_particles `RTTI Type Descriptor');
      v82 = vostok::memory::doug_lea_allocator::malloc_impl(v81, (int)v79, 0x34u, v80, v124, v146, v168);
      if ( v82 )
        vostok::render::stage_particles::stage_particles(
          (vostok::render::stage_particles *)v82,
          thisa->m_renderer_context,
          thisa,
          0);
      else
        v83 = 0;
      *((_DWORD *)thisa->m_stages.m_begin + 19) = v83;
      break;
    case 20:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 20,
        v108,
        v130,
        v152);
      v62 = vostok::render::g_allocator;
      v63 = type_info::raw_name(&vostok::render::stage_apply_distortion `RTTI Type Descriptor');
      v65 = vostok::memory::doug_lea_allocator::malloc_impl(v64, (int)v62, 0x18u, v63, v121, v143, v165);
      if ( v65 )
        vostok::render::stage_apply_distortion::stage_apply_distortion(
          (vostok::render::stage_apply_distortion *)v65,
          thisa->m_renderer_context,
          thisa);
      else
        v66 = 0;
      *((_DWORD *)thisa->m_stages.m_begin + 20) = v66;
      break;
    case 21:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 21,
        v108,
        v130,
        v152);
      v74 = vostok::render::g_allocator;
      v75 = type_info::raw_name(&vostok::render::stage_particles `RTTI Type Descriptor');
      v77 = vostok::memory::doug_lea_allocator::malloc_impl(v76, (int)v74, 0x34u, v75, v123, v145, v167);
      if ( v77 )
        vostok::render::stage_particles::stage_particles(
          (vostok::render::stage_particles *)v77,
          thisa->m_renderer_context,
          thisa,
          (vostok::render::effect_manager *)1);
      else
        v78 = 0;
      *((_DWORD *)thisa->m_stages.m_begin + 21) = v78;
      break;
    case 22:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 22,
        v108,
        v130,
        v152);
      v91 = vostok::render::g_allocator;
      v92 = type_info::raw_name(&vostok::render::stage_volume_fog `RTTI Type Descriptor');
      v94 = vostok::memory::doug_lea_allocator::malloc_impl(v93, (int)v91, 0x5Cu, v92, v127, v149, v171);
      if ( v94 )
        vostok::render::stage_volume_fog::stage_volume_fog(
          (vostok::render::stage_volume_fog *)v94,
          thisa->m_renderer_context,
          thisa);
      else
        v95 = 0;
      *((_DWORD *)thisa->m_stages.m_begin + 22) = v95;
      break;
    case 23:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 23,
        v108,
        v130,
        v152);
      v86 = vostok::render::g_allocator;
      v87 = type_info::raw_name(&vostok::render::stage_foreground `RTTI Type Descriptor');
      v89 = vostok::memory::doug_lea_allocator::malloc_impl(v88, (int)v86, 0x10u, v87, v126, v148, v170);
      if ( v89 )
      {
        vostok::render::stage::stage((vostok::render::stage *)v89, thisa->m_renderer_context, thisa);
        *(_DWORD *)v90 = &vostok::render::stage_foreground::`vftable';
        *(_BYTE *)(v90 + 12) = 1;
      }
      else
      {
        v90 = 0;
      }
      *((_DWORD *)thisa->m_stages.m_begin + 23) = v90;
      break;
    case 24:
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        (vostok::ai::fsm_state **)thisa->m_stages.m_begin + 24,
        v108,
        v130,
        v152);
      v101 = vostok::render::g_allocator;
      v102 = type_info::raw_name(&vostok::render::stage_postprocess `RTTI Type Descriptor');
      v104 = vostok::memory::doug_lea_allocator::malloc_impl(
               v103,
               (int)v101,
               (unsigned int)&loc_2639C + 4,
               v102,
               v129,
               v151,
               v173);
      if ( v104 )
        vostok::render::stage_postprocess::stage_postprocess(
          thisa->m_renderer_context,
          (vostok::render::stage_postprocess *)v104,
          thisa);
      else
        v105 = 0;
      *((_DWORD *)thisa->m_stages.m_begin + 24) = v105;
      break;
  }
}
