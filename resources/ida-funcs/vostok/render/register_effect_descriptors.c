void vostok::render::register_effect_descriptors()
{
  vostok::memory::doug_lea_allocator *v0; // esi
  char *v1; // eax
  vostok::memory::doug_lea_allocator *v2; // ecx
  char *v3; // eax
  vostok::render::effect_manager *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  char *v8; // eax
  vostok::render::effect_manager *v9; // ecx
  vostok::memory::doug_lea_allocator *v10; // esi
  char *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // ecx
  char *v13; // eax
  vostok::render::effect_manager *v14; // ecx
  vostok::memory::doug_lea_allocator *v15; // esi
  char *v16; // eax
  vostok::memory::doug_lea_allocator *v17; // ecx
  char *v18; // eax
  vostok::render::effect_manager *v19; // ecx
  vostok::memory::doug_lea_allocator *v20; // esi
  char *v21; // eax
  vostok::memory::doug_lea_allocator *v22; // ecx
  char *v23; // eax
  vostok::render::effect_manager *v24; // ecx
  vostok::memory::doug_lea_allocator *v25; // esi
  char *v26; // eax
  vostok::memory::doug_lea_allocator *v27; // ecx
  char *v28; // eax
  vostok::render::effect_manager *v29; // ecx
  vostok::memory::doug_lea_allocator *v30; // esi
  char *v31; // eax
  vostok::memory::doug_lea_allocator *v32; // ecx
  char *v33; // eax
  vostok::render::effect_manager *v34; // ecx
  vostok::memory::doug_lea_allocator *v35; // esi
  char *v36; // eax
  vostok::memory::doug_lea_allocator *v37; // ecx
  char *v38; // eax
  vostok::render::effect_manager *v39; // ecx
  vostok::memory::doug_lea_allocator *v40; // esi
  char *v41; // eax
  vostok::memory::doug_lea_allocator *v42; // ecx
  char *v43; // eax
  vostok::render::effect_manager *v44; // ecx
  vostok::memory::doug_lea_allocator *v45; // esi
  char *v46; // eax
  vostok::memory::doug_lea_allocator *v47; // ecx
  char *v48; // eax
  vostok::render::effect_manager *v49; // ecx
  vostok::memory::doug_lea_allocator *v50; // esi
  char *v51; // eax
  vostok::memory::doug_lea_allocator *v52; // ecx
  char *v53; // eax
  vostok::render::effect_manager *v54; // ecx
  vostok::memory::doug_lea_allocator *v55; // esi
  char *v56; // eax
  vostok::memory::doug_lea_allocator *v57; // ecx
  char *v58; // eax
  vostok::render::effect_manager *v59; // ecx
  vostok::memory::doug_lea_allocator *v60; // esi
  char *v61; // eax
  vostok::memory::doug_lea_allocator *v62; // ecx
  char *v63; // eax
  vostok::render::effect_manager *v64; // ecx
  vostok::memory::doug_lea_allocator *v65; // esi
  char *v66; // eax
  vostok::memory::doug_lea_allocator *v67; // ecx
  char *v68; // eax
  vostok::render::effect_manager *v69; // ecx
  vostok::memory::doug_lea_allocator *v70; // esi
  char *v71; // eax
  vostok::memory::doug_lea_allocator *v72; // ecx
  char *v73; // eax
  vostok::render::effect_manager *v74; // ecx
  vostok::memory::doug_lea_allocator *v75; // esi
  char *v76; // eax
  vostok::memory::doug_lea_allocator *v77; // ecx
  char *v78; // eax
  vostok::render::effect_manager *v79; // ecx
  vostok::memory::doug_lea_allocator *v80; // esi
  char *v81; // eax
  vostok::memory::doug_lea_allocator *v82; // ecx
  char *v83; // eax
  vostok::render::effect_manager *v84; // ecx
  vostok::memory::doug_lea_allocator *v85; // esi
  char *v86; // eax
  vostok::memory::doug_lea_allocator *v87; // ecx
  char *v88; // eax
  vostok::render::effect_manager *v89; // ecx
  vostok::memory::doug_lea_allocator *v90; // esi
  char *v91; // eax
  vostok::memory::doug_lea_allocator *v92; // ecx
  char *v93; // eax
  vostok::render::effect_manager *v94; // ecx
  vostok::memory::doug_lea_allocator *v95; // esi
  char *v96; // eax
  vostok::memory::doug_lea_allocator *v97; // ecx
  char *v98; // eax
  vostok::render::effect_manager *v99; // ecx
  vostok::memory::doug_lea_allocator *v100; // esi
  char *v101; // eax
  vostok::memory::doug_lea_allocator *v102; // ecx
  char *v103; // eax
  vostok::render::effect_manager *v104; // ecx
  vostok::memory::doug_lea_allocator *v105; // esi
  char *v106; // eax
  vostok::memory::doug_lea_allocator *v107; // ecx
  char *v108; // eax
  vostok::render::effect_manager *v109; // ecx
  vostok::memory::doug_lea_allocator *v110; // esi
  char *v111; // eax
  vostok::memory::doug_lea_allocator *v112; // ecx
  char *v113; // eax
  vostok::render::effect_manager *v114; // ecx
  vostok::memory::doug_lea_allocator *v115; // esi
  char *v116; // eax
  vostok::memory::doug_lea_allocator *v117; // ecx
  char *v118; // eax
  vostok::render::effect_manager *v119; // ecx
  vostok::memory::doug_lea_allocator *v120; // esi
  char *v121; // eax
  vostok::memory::doug_lea_allocator *v122; // ecx
  char *v123; // eax
  vostok::render::effect_manager *v124; // ecx
  vostok::memory::doug_lea_allocator *v125; // esi
  char *v126; // eax
  vostok::memory::doug_lea_allocator *v127; // ecx
  char *v128; // eax
  vostok::render::effect_manager *v129; // ecx
  vostok::memory::doug_lea_allocator *v130; // esi
  char *v131; // eax
  vostok::memory::doug_lea_allocator *v132; // ecx
  char *v133; // eax
  vostok::render::effect_manager *v134; // ecx
  vostok::memory::doug_lea_allocator *v135; // esi
  char *v136; // eax
  vostok::memory::doug_lea_allocator *v137; // ecx
  char *v138; // eax
  vostok::render::effect_manager *v139; // ecx
  vostok::memory::doug_lea_allocator *v140; // esi
  char *v141; // eax
  vostok::memory::doug_lea_allocator *v142; // ecx
  char *v143; // eax
  vostok::render::effect_manager *v144; // ecx
  vostok::memory::doug_lea_allocator *v145; // esi
  char *v146; // eax
  vostok::memory::doug_lea_allocator *v147; // ecx
  char *v148; // eax
  vostok::render::effect_manager *v149; // ecx
  vostok::memory::doug_lea_allocator *v150; // esi
  char *v151; // eax
  vostok::memory::doug_lea_allocator *v152; // ecx
  char *v153; // eax
  vostok::render::effect_manager *v154; // ecx
  const char *v155; // [esp+0h] [ebp-14h]
  const char *v156; // [esp+0h] [ebp-14h]
  const char *v157; // [esp+0h] [ebp-14h]
  const char *v158; // [esp+0h] [ebp-14h]
  const char *v159; // [esp+0h] [ebp-14h]
  const char *v160; // [esp+0h] [ebp-14h]
  const char *v161; // [esp+0h] [ebp-14h]
  const char *v162; // [esp+0h] [ebp-14h]
  const char *v163; // [esp+0h] [ebp-14h]
  const char *v164; // [esp+0h] [ebp-14h]
  const char *v165; // [esp+0h] [ebp-14h]
  const char *v166; // [esp+0h] [ebp-14h]
  const char *v167; // [esp+0h] [ebp-14h]
  const char *v168; // [esp+0h] [ebp-14h]
  const char *v169; // [esp+0h] [ebp-14h]
  const char *v170; // [esp+0h] [ebp-14h]
  const char *v171; // [esp+0h] [ebp-14h]
  const char *v172; // [esp+0h] [ebp-14h]
  const char *v173; // [esp+0h] [ebp-14h]
  const char *v174; // [esp+0h] [ebp-14h]
  const char *v175; // [esp+0h] [ebp-14h]
  const char *v176; // [esp+0h] [ebp-14h]
  const char *v177; // [esp+0h] [ebp-14h]
  const char *v178; // [esp+0h] [ebp-14h]
  const char *v179; // [esp+0h] [ebp-14h]
  const char *v180; // [esp+0h] [ebp-14h]
  const char *v181; // [esp+0h] [ebp-14h]
  const char *v182; // [esp+0h] [ebp-14h]
  const char *v183; // [esp+0h] [ebp-14h]
  const char *v184; // [esp+0h] [ebp-14h]
  const char *v185; // [esp+0h] [ebp-14h]
  const char *v186; // [esp+4h] [ebp-10h]
  const char *v187; // [esp+4h] [ebp-10h]
  const char *v188; // [esp+4h] [ebp-10h]
  const char *v189; // [esp+4h] [ebp-10h]
  const char *v190; // [esp+4h] [ebp-10h]
  const char *v191; // [esp+4h] [ebp-10h]
  const char *v192; // [esp+4h] [ebp-10h]
  const char *v193; // [esp+4h] [ebp-10h]
  const char *v194; // [esp+4h] [ebp-10h]
  const char *v195; // [esp+4h] [ebp-10h]
  const char *v196; // [esp+4h] [ebp-10h]
  const char *v197; // [esp+4h] [ebp-10h]
  const char *v198; // [esp+4h] [ebp-10h]
  const char *v199; // [esp+4h] [ebp-10h]
  const char *v200; // [esp+4h] [ebp-10h]
  const char *v201; // [esp+4h] [ebp-10h]
  const char *v202; // [esp+4h] [ebp-10h]
  const char *v203; // [esp+4h] [ebp-10h]
  const char *v204; // [esp+4h] [ebp-10h]
  const char *v205; // [esp+4h] [ebp-10h]
  const char *v206; // [esp+4h] [ebp-10h]
  const char *v207; // [esp+4h] [ebp-10h]
  const char *v208; // [esp+4h] [ebp-10h]
  const char *v209; // [esp+4h] [ebp-10h]
  const char *v210; // [esp+4h] [ebp-10h]
  const char *v211; // [esp+4h] [ebp-10h]
  const char *v212; // [esp+4h] [ebp-10h]
  const char *v213; // [esp+4h] [ebp-10h]
  const char *v214; // [esp+4h] [ebp-10h]
  const char *v215; // [esp+4h] [ebp-10h]
  const char *v216; // [esp+4h] [ebp-10h]
  unsigned int v217; // [esp+8h] [ebp-Ch]
  unsigned int v218; // [esp+8h] [ebp-Ch]
  unsigned int v219; // [esp+8h] [ebp-Ch]
  unsigned int v220; // [esp+8h] [ebp-Ch]
  unsigned int v221; // [esp+8h] [ebp-Ch]
  unsigned int v222; // [esp+8h] [ebp-Ch]
  unsigned int v223; // [esp+8h] [ebp-Ch]
  unsigned int v224; // [esp+8h] [ebp-Ch]
  unsigned int v225; // [esp+8h] [ebp-Ch]
  unsigned int v226; // [esp+8h] [ebp-Ch]
  unsigned int v227; // [esp+8h] [ebp-Ch]
  unsigned int v228; // [esp+8h] [ebp-Ch]
  unsigned int v229; // [esp+8h] [ebp-Ch]
  unsigned int v230; // [esp+8h] [ebp-Ch]
  unsigned int v231; // [esp+8h] [ebp-Ch]
  unsigned int v232; // [esp+8h] [ebp-Ch]
  unsigned int v233; // [esp+8h] [ebp-Ch]
  unsigned int v234; // [esp+8h] [ebp-Ch]
  unsigned int v235; // [esp+8h] [ebp-Ch]
  unsigned int v236; // [esp+8h] [ebp-Ch]
  unsigned int v237; // [esp+8h] [ebp-Ch]
  unsigned int v238; // [esp+8h] [ebp-Ch]
  unsigned int v239; // [esp+8h] [ebp-Ch]
  unsigned int v240; // [esp+8h] [ebp-Ch]
  unsigned int v241; // [esp+8h] [ebp-Ch]
  unsigned int v242; // [esp+8h] [ebp-Ch]
  unsigned int v243; // [esp+8h] [ebp-Ch]
  unsigned int v244; // [esp+8h] [ebp-Ch]
  unsigned int v245; // [esp+8h] [ebp-Ch]
  unsigned int v246; // [esp+8h] [ebp-Ch]
  unsigned int v247; // [esp+8h] [ebp-Ch]

  v0 = vostok::render::g_allocator;
  v1 = type_info::raw_name(&vostok::render::effect_fstage_fire_fresnel_materials `RTTI Type Descriptor');
  v3 = vostok::memory::doug_lea_allocator::malloc_impl(v2, (int)v0, 4u, v1, v155, v186, v217);
  if ( v3 )
    *(_DWORD *)v3 = &vostok::render::effect_fstage_fire_fresnel_materials::`vftable';
  else
    v3 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v4,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&dectriptor,
    (int)v3);
  v5 = vostok::render::g_allocator;
  v6 = type_info::raw_name(&vostok::render::effect_fstage_default_materials `RTTI Type Descriptor');
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(v7, (int)v5, 4u, v6, v156, v187, v218);
  if ( v8 )
    *(_DWORD *)v8 = &vostok::render::effect_fstage_default_materials::`vftable';
  else
    v8 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v9,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_8123EC,
    (int)v8);
  v10 = vostok::render::g_allocator;
  v11 = type_info::raw_name(&vostok::render::effect_fstage_sphere_projection_materials `RTTI Type Descriptor');
  v13 = vostok::memory::doug_lea_allocator::malloc_impl(v12, (int)v10, 4u, v11, v157, v188, v219);
  if ( v13 )
    *(_DWORD *)v13 = &vostok::render::effect_fstage_sphere_projection_materials::`vftable';
  else
    v13 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v14,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_8123FC,
    (int)v13);
  v15 = vostok::render::g_allocator;
  v16 = type_info::raw_name(&vostok::render::effect_fstage_sky_materials `RTTI Type Descriptor');
  v18 = vostok::memory::doug_lea_allocator::malloc_impl(v17, (int)v15, 4u, v16, v158, v189, v220);
  if ( v18 )
    *(_DWORD *)v18 = &vostok::render::effect_fstage_sky_materials::`vftable';
  else
    v18 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v19,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_80B4E8,
    (int)v18);
  v20 = vostok::render::g_allocator;
  v21 = type_info::raw_name(&vostok::render::effect_fstage_default_materials `RTTI Type Descriptor');
  v23 = vostok::memory::doug_lea_allocator::malloc_impl(v22, (int)v20, 4u, v21, v159, v190, v221);
  if ( v23 )
    *(_DWORD *)v23 = &vostok::render::effect_fstage_default_materials::`vftable';
  else
    v23 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v24,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_812418,
    (int)v23);
  v25 = vostok::render::g_allocator;
  v26 = type_info::raw_name(&vostok::render::effect_fstage_blend_subuv_materials `RTTI Type Descriptor');
  v28 = vostok::memory::doug_lea_allocator::malloc_impl(v27, (int)v25, 4u, v26, v160, v191, v222);
  if ( v28 )
    *(_DWORD *)v28 = &vostok::render::effect_fstage_blend_subuv_materials::`vftable';
  else
    v28 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v29,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_812430,
    (int)v28);
  v30 = vostok::render::g_allocator;
  v31 = type_info::raw_name(&vostok::render::effect_fstage_soft_materials `RTTI Type Descriptor');
  v33 = vostok::memory::doug_lea_allocator::malloc_impl(v32, (int)v30, 4u, v31, v161, v192, v223);
  if ( v33 )
    *(_DWORD *)v33 = &vostok::render::effect_fstage_soft_materials::`vftable';
  else
    v33 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v34,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_812448,
    (int)v33);
  v35 = vostok::render::g_allocator;
  v36 = type_info::raw_name(&vostok::render::effect_lighting_stage_default_materials `RTTI Type Descriptor');
  v38 = vostok::memory::doug_lea_allocator::malloc_impl(v37, (int)v35, 4u, v36, v162, v193, v224);
  if ( v38 )
    *(_DWORD *)v38 = &vostok::render::effect_lighting_stage_default_materials::`vftable';
  else
    v38 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v39,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_812458,
    (int)v38);
  v40 = vostok::render::g_allocator;
  v41 = type_info::raw_name(&vostok::render::effect_offscreen_particle_lighting_materials `RTTI Type Descriptor');
  v43 = vostok::memory::doug_lea_allocator::malloc_impl(v42, (int)v40, 4u, v41, v163, v194, v225);
  if ( v43 )
    *(_DWORD *)v43 = &vostok::render::effect_offscreen_particle_lighting_materials::`vftable';
  else
    v43 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v44,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_81246C,
    (int)v43);
  v45 = vostok::render::g_allocator;
  v46 = type_info::raw_name(&vostok::render::effect_lighting_stage_organic_base_materials `RTTI Type Descriptor');
  v48 = vostok::memory::doug_lea_allocator::malloc_impl(v47, (int)v45, 4u, v46, v164, v195, v226);
  if ( v48 )
    *(_DWORD *)v48 = &vostok::render::effect_lighting_stage_organic_base_materials::`vftable';
  else
    v48 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v49,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_812480,
    (int)v48);
  v50 = vostok::render::g_allocator;
  v51 = type_info::raw_name(&vostok::render::effect_lighting_stage_skin_base_materials `RTTI Type Descriptor');
  v53 = vostok::memory::doug_lea_allocator::malloc_impl(v52, (int)v50, 4u, v51, v165, v196, v227);
  if ( v53 )
    *(_DWORD *)v53 = &vostok::render::effect_lighting_stage_skin_base_materials::`vftable';
  else
    v53 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v54,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_812498,
    (int)v53);
  v55 = vostok::render::g_allocator;
  v56 = type_info::raw_name(&vostok::render::effect_fstage_volume_sphere_base_materials `RTTI Type Descriptor');
  v58 = vostok::memory::doug_lea_allocator::malloc_impl(v57, (int)v55, 4u, v56, v166, v197, v228);
  if ( v58 )
    *(_DWORD *)v58 = &vostok::render::effect_fstage_volume_sphere_base_materials::`vftable';
  else
    v58 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v59,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_8124AC,
    (int)v58);
  v60 = vostok::render::g_allocator;
  v61 = type_info::raw_name(&vostok::render::effect_fstage_volume_cone_base_materials `RTTI Type Descriptor');
  v63 = vostok::memory::doug_lea_allocator::malloc_impl(v62, (int)v60, 4u, v61, v167, v198, v229);
  if ( v63 )
    *(_DWORD *)v63 = &vostok::render::effect_fstage_volume_cone_base_materials::`vftable';
  else
    v63 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v64,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_8124C8,
    (int)v63);
  v65 = vostok::render::g_allocator;
  v66 = type_info::raw_name(&vostok::render::effect_fstage_smoke_custom_lighted_materials `RTTI Type Descriptor');
  v68 = vostok::memory::doug_lea_allocator::malloc_impl(v67, (int)v65, 4u, v66, v168, v199, v230);
  if ( v68 )
    *(_DWORD *)v68 = &vostok::render::effect_fstage_smoke_custom_lighted_materials::`vftable';
  else
    v68 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v69,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_8124E4,
    (int)v68);
  v70 = vostok::render::g_allocator;
  v71 = type_info::raw_name(&vostok::render::effect_distortion_stage_panner_materials `RTTI Type Descriptor');
  v73 = vostok::memory::doug_lea_allocator::malloc_impl(v72, (int)v70, 4u, v71, v169, v200, v231);
  if ( v73 )
    *(_DWORD *)v73 = &vostok::render::effect_distortion_stage_panner_materials::`vftable';
  else
    v73 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v74,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_812504,
    (int)v73);
  v75 = vostok::render::g_allocator;
  v76 = type_info::raw_name(&vostok::render::effect_distortion_stage_default_materials `RTTI Type Descriptor');
  v78 = vostok::memory::doug_lea_allocator::malloc_impl(v77, (int)v75, 4u, v76, v170, v201, v232);
  if ( v78 )
    *(_DWORD *)v78 = &vostok::render::effect_distortion_stage_default_materials::`vftable';
  else
    v78 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v79,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_812518,
    (int)v78);
  v80 = vostok::render::g_allocator;
  v81 = type_info::raw_name(&vostok::render::effect_gstage_default_materials `RTTI Type Descriptor');
  v83 = vostok::memory::doug_lea_allocator::malloc_impl(v82, (int)v80, 4u, v81, v171, v202, v233);
  if ( v83 )
    *(_DWORD *)v83 = &vostok::render::effect_gstage_default_materials::`vftable';
  else
    v83 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v84,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_81252C,
    (int)v83);
  v85 = vostok::render::g_allocator;
  v86 = type_info::raw_name(&vostok::render::effect_gstage_terrain_materials `RTTI Type Descriptor');
  v88 = vostok::memory::doug_lea_allocator::malloc_impl(v87, (int)v85, 4u, v86, v172, v203, v234);
  if ( v88 )
    *(_DWORD *)v88 = &vostok::render::effect_gstage_terrain_materials::`vftable';
  else
    v88 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v89,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_81253C,
    (int)v88);
  v90 = vostok::render::g_allocator;
  v91 = type_info::raw_name(&vostok::render::effect_gstage_default_materials `RTTI Type Descriptor');
  v93 = vostok::memory::doug_lea_allocator::malloc_impl(v92, (int)v90, 4u, v91, v173, v204, v235);
  if ( v93 )
    *(_DWORD *)v93 = &vostok::render::effect_gstage_default_materials::`vftable';
  else
    v93 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v94,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_81254C,
    (int)v93);
  v95 = vostok::render::g_allocator;
  v96 = type_info::raw_name(&vostok::render::effect_gstage_burning_wood_materials `RTTI Type Descriptor');
  v98 = vostok::memory::doug_lea_allocator::malloc_impl(v97, (int)v95, 4u, v96, v174, v205, v236);
  if ( v98 )
    *(_DWORD *)v98 = &vostok::render::effect_gstage_burning_wood_materials::`vftable';
  else
    v98 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v99,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_812564,
    (int)v98);
  v100 = vostok::render::g_allocator;
  v101 = type_info::raw_name(&vostok::render::effect_post_process_blend_texture_materials `RTTI Type Descriptor');
  v103 = vostok::memory::doug_lea_allocator::malloc_impl(v102, (int)v100, 4u, v101, v175, v206, v237);
  if ( v103 )
    *(_DWORD *)v103 = &vostok::render::effect_post_process_blend_texture_materials::`vftable';
  else
    v103 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v104,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_81257C,
    (int)v103);
  v105 = vostok::render::g_allocator;
  v106 = type_info::raw_name(&vostok::render::effect_post_process_distortion_materials `RTTI Type Descriptor');
  v108 = vostok::memory::doug_lea_allocator::malloc_impl(v107, (int)v105, 4u, v106, v176, v207, v238);
  if ( v108 )
    *(_DWORD *)v108 = &vostok::render::effect_post_process_distortion_materials::`vftable';
  else
    v108 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v109,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_812598,
    (int)v108);
  v110 = vostok::render::g_allocator;
  v111 = type_info::raw_name(&vostok::render::effect_post_process_terrain_debug_materials `RTTI Type Descriptor');
  v113 = vostok::memory::doug_lea_allocator::malloc_impl(v112, (int)v110, 4u, v111, v177, v208, v239);
  if ( v113 )
    *(_DWORD *)v113 = &vostok::render::effect_post_process_terrain_debug_materials::`vftable';
  else
    v113 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v114,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_8125B0,
    (int)v113);
  v115 = vostok::render::g_allocator;
  v116 = type_info::raw_name(&vostok::render::effect_debug_editor_wireframe `RTTI Type Descriptor');
  v118 = vostok::memory::doug_lea_allocator::malloc_impl(v117, (int)v115, 4u, v116, v178, v209, v240);
  if ( v118 )
    *(_DWORD *)v118 = &vostok::render::effect_debug_editor_wireframe::`vftable';
  else
    v118 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v119,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_8125D4,
    (int)v118);
  v120 = vostok::render::g_allocator;
  v121 = type_info::raw_name(&vostok::render::depth_accumulate_material_effect `RTTI Type Descriptor');
  v123 = vostok::memory::doug_lea_allocator::malloc_impl(v122, (int)v120, 4u, v121, v179, v210, v241);
  if ( v123 )
    *(_DWORD *)v123 = &vostok::render::depth_accumulate_material_effect::`vftable';
  else
    v123 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v124,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_80B56C,
    (int)v123);
  v125 = vostok::render::g_allocator;
  v126 = type_info::raw_name(&vostok::render::decal_default_material_effect `RTTI Type Descriptor');
  v128 = vostok::memory::doug_lea_allocator::malloc_impl(v127, (int)v125, 8u, v126, v180, v211, v242);
  if ( v128 )
  {
    *(_DWORD *)v128 = &vostok::render::decal_default_material_effect::`vftable';
    v128[4] = 0;
  }
  else
  {
    v128 = 0;
  }
  vostok::render::effect_manager::register_effect_desctiptor(
    v129,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_8125EC,
    (int)v128);
  v130 = vostok::render::g_allocator;
  v131 = type_info::raw_name(&vostok::render::decal_default_material_effect `RTTI Type Descriptor');
  v133 = vostok::memory::doug_lea_allocator::malloc_impl(v132, (int)v130, 8u, v131, v181, v212, v243);
  if ( v133 )
  {
    *(_DWORD *)v133 = &vostok::render::decal_default_material_effect::`vftable';
    v133[4] = 1;
  }
  else
  {
    v133 = 0;
  }
  vostok::render::effect_manager::register_effect_desctiptor(
    v134,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_8125FC,
    (int)v133);
  v135 = vostok::render::g_allocator;
  v136 = type_info::raw_name(&vostok::render::effect_sky_sphere_default_materials `RTTI Type Descriptor');
  v138 = vostok::memory::doug_lea_allocator::malloc_impl(v137, (int)v135, 4u, v136, v182, v213, v244);
  if ( v138 )
    *(_DWORD *)v138 = &vostok::render::effect_sky_sphere_default_materials::`vftable';
  else
    v138 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v139,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_81260C,
    (int)v138);
  v140 = vostok::render::g_allocator;
  v141 = type_info::raw_name(&vostok::render::effect_fstage_simpe_water_materials `RTTI Type Descriptor');
  v143 = vostok::memory::doug_lea_allocator::malloc_impl(v142, (int)v140, 4u, v141, v183, v214, v245);
  if ( v143 )
    *(_DWORD *)v143 = &vostok::render::effect_fstage_simpe_water_materials::`vftable';
  else
    v143 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v144,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_80B4F4,
    (int)v143);
  v145 = vostok::render::g_allocator;
  v146 = type_info::raw_name(&vostok::render::effect_fstage_fake_translucency_materials `RTTI Type Descriptor');
  v148 = vostok::memory::doug_lea_allocator::malloc_impl(v147, (int)v145, 4u, v146, v184, v215, v246);
  if ( v148 )
    *(_DWORD *)v148 = &vostok::render::effect_fstage_fake_translucency_materials::`vftable';
  else
    v148 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v149,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_812620,
    (int)v148);
  v150 = vostok::render::g_allocator;
  v151 = type_info::raw_name(&vostok::render::effect_fstage_default_view_angle_dependent_materials `RTTI Type Descriptor');
  v153 = vostok::memory::doug_lea_allocator::malloc_impl(v152, (int)v150, 4u, v151, v185, v216, v247);
  if ( v153 )
    *(_DWORD *)v153 = &vostok::render::effect_fstage_default_view_angle_dependent_materials::`vftable';
  else
    v153 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    v154,
    (const char *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->force_sync,
    (vostok::render::effect_descriptor *)&stru_80B510,
    (int)v153);
}
