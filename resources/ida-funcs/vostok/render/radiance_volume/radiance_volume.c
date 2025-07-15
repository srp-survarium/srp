void __thiscall vostok::render::radiance_volume::radiance_volume(
        vostok::render::radiance_volume *this,
        vostok::render::resource_manager *in_rsm_size,
        unsigned int in_num_cells,
        vostok::render::res_texture *in_num_propagate_iterations,
        float in_scale,
        float in_flux_amplifier,
        float in_flux_amplifiera)
{
  unsigned int v7; // ebp
  vostok::render::injection_geometry *v8; // ecx
  unsigned int v9; // esi
  vostok::render::sliced_cube_geometry *v10; // ecx
  float v11; // eax
  vostok::render::resource_manager *v12; // ecx
  vostok::render::render_target *volume_render_target; // eax
  vostok::render::resource_manager *v14; // ecx
  const char *v15; // eax
  vostok::render::resource_manager *v16; // edi
  vostok::render::render_target *v17; // eax
  vostok::render::resource_manager *v18; // ecx
  const char *v19; // eax
  vostok::render::render_target *v20; // eax
  vostok::render::resource_manager *v21; // ecx
  const char *v22; // eax
  vostok::render::render_target *v23; // eax
  vostok::render::resource_manager *v24; // ecx
  const char *v25; // eax
  vostok::render::render_target *v26; // eax
  vostok::render::resource_manager *v27; // ecx
  const char *v28; // eax
  vostok::render::render_target *v29; // eax
  vostok::render::resource_manager *v30; // ecx
  const char *v31; // eax
  int v32; // eax
  const vostok::render::res_texture *v33; // edi
  const vostok::render::res_texture *v34; // eax
  const vostok::render::res_texture *v35; // esi
  int v36; // eax
  const vostok::render::res_texture *v37; // edi
  const vostok::render::res_texture *v38; // eax
  const vostok::render::res_texture *v39; // esi
  int v40; // eax
  const vostok::render::res_texture *v41; // edi
  const vostok::render::res_texture *v42; // eax
  const vostok::render::res_texture *v43; // esi
  vostok::render::resource_manager *v44; // edi
  unsigned int v45; // esi
  vostok::render::render_target *v46; // eax
  vostok::render::resource_manager *v47; // ecx
  const char *v48; // eax
  vostok::render::render_target *v49; // eax
  vostok::render::resource_manager *v50; // ecx
  const char *v51; // eax
  vostok::render::render_target *v52; // eax
  vostok::render::resource_manager *v53; // ecx
  const char *v54; // eax
  int v55; // eax
  const vostok::render::res_texture *v56; // edi
  const vostok::render::res_texture *v57; // eax
  const vostok::render::res_texture *v58; // esi
  int v59; // eax
  const vostok::render::res_texture *v60; // edi
  const vostok::render::res_texture *v61; // eax
  const vostok::render::res_texture *v62; // esi
  int v63; // eax
  const vostok::render::res_texture *v64; // edi
  const vostok::render::res_texture *v65; // eax
  const vostok::render::res_texture *v66; // esi
  vostok::render::resource_manager *v67; // edi
  unsigned int v68; // esi
  vostok::render::render_target *v69; // eax
  vostok::render::resource_manager *v70; // ecx
  const char *v71; // eax
  vostok::render::render_target *v72; // eax
  vostok::render::resource_manager *v73; // ecx
  const char *v74; // eax
  vostok::render::render_target *v75; // eax
  vostok::render::resource_manager *v76; // ecx
  const char *v77; // eax
  vostok::render::res_texture *v78; // ecx
  const vostok::render::res_texture *v79; // edi
  const vostok::render::res_texture *v80; // eax
  const vostok::render::res_texture *v81; // esi
  vostok::render::res_texture *v82; // ecx
  const vostok::render::res_texture *v83; // edi
  const vostok::render::res_texture *v84; // eax
  const vostok::render::res_texture *v85; // esi
  vostok::render::res_texture *v86; // ecx
  const vostok::render::res_texture *v87; // edi
  const vostok::render::res_texture *v88; // eax
  const vostok::render::res_texture *v89; // esi
  vostok::render::res_texture *v90; // ecx
  const vostok::render::res_texture *v91; // esi
  const vostok::render::res_texture *v92; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v93; // ecx
  vostok::render::res_texture *v94; // ecx
  const vostok::render::res_texture *v95; // esi
  const vostok::render::res_texture *v96; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v97; // ecx
  vostok::render::res_texture *v98; // ecx
  const vostok::render::res_texture *v99; // esi
  const vostok::render::res_texture *v100; // esi
  vostok::render::render_target *v101; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v102; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v103; // ecx
  vostok::render::res_texture *v104; // ecx
  const vostok::render::res_texture *v105; // esi
  const vostok::render::res_texture *v106; // esi
  unsigned int v107; // edi
  vostok::render::render_target *v108; // eax
  vostok::render::render_target *v109; // eax
  vostok::render::resource_manager *v110; // ecx
  vostok::render::render_target *v111; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v112; // ecx
  vostok::render::res_texture *v113; // ecx
  const vostok::render::res_texture *v114; // esi
  const vostok::render::res_texture *v115; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v116; // ecx
  vostok::render::res_texture *v117; // ecx
  const vostok::render::res_texture *v118; // esi
  const vostok::render::res_texture *v119; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v120; // ecx
  vostok::render::res_texture *v121; // ecx
  const vostok::render::res_texture *v122; // esi
  const vostok::render::res_texture *v123; // esi
  survarium::game_action_id *M_start; // ecx
  unsigned int v125; // eax
  vostok::render::resource_manager *v126; // edx
  vostok::render::render_target *render_target; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v128; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v129; // ecx
  vostok::render::res_texture *v130; // ecx
  const vostok::render::res_texture *v131; // esi
  const vostok::render::res_texture *v132; // esi
  vostok::render::render_target *v133; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v134; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v135; // ecx
  vostok::render::res_texture *v136; // ecx
  const vostok::render::res_texture *v137; // esi
  const vostok::render::res_texture *v138; // esi
  vostok::render::render_target *v139; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v140; // ecx
  vostok::render::res_texture *v141; // ecx
  const vostok::render::res_texture *v142; // esi
  const vostok::render::res_texture *v143; // esi
  vostok::render::render_target *v144; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v145; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v146; // ecx
  vostok::render::res_texture *v147; // ecx
  const vostok::render::res_texture *v148; // esi
  const vostok::render::res_texture *v149; // esi
  vostok::render::render_target *v150; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v151; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v152; // ecx
  vostok::render::res_texture *v153; // ecx
  const vostok::render::res_texture *v154; // esi
  const vostok::render::res_texture *v155; // esi
  vostok::render::render_target *v156; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v157; // ecx
  vostok::render::res_texture *v158; // ecx
  const vostok::render::res_texture *v159; // esi
  const vostok::render::res_texture *v160; // esi
  vostok::render::render_target *v161; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v162; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v163; // ecx
  vostok::render::res_texture *v164; // ecx
  const vostok::render::res_texture *v165; // esi
  const vostok::render::res_texture *v166; // esi
  vostok::render::render_target *v167; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v168; // ecx
  vostok::render::res_texture *v169; // ecx
  const vostok::render::res_texture *v170; // esi
  vostok::render::render_target *v171; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v172; // ecx
  vostok::render::res_texture *v173; // ecx
  const vostok::render::res_texture *v174; // esi
  vostok::render::render_target *v175; // eax
  vostok::render::backend *v176; // ecx
  vostok::strings::shared::manager *v177; // ecx
  vostok::render::backend *v178; // ecx
  vostok::strings::shared::manager *v179; // ecx
  vostok::render::backend *v180; // ecx
  vostok::strings::shared::manager *v181; // ecx
  vostok::render::backend *v182; // ecx
  vostok::strings::shared::manager *v183; // ecx
  vostok::render::backend *v184; // ecx
  vostok::strings::shared::manager *v185; // ecx
  vostok::render::backend *v186; // ecx
  vostok::strings::shared::manager *v187; // ecx
  vostok::render::backend *v188; // ecx
  vostok::strings::shared::manager *v189; // ecx
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v190; // [esp-4h] [ebp-28h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v191; // [esp-4h] [ebp-28h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v192; // [esp-4h] [ebp-28h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v193; // [esp-4h] [ebp-28h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v194; // [esp-4h] [ebp-28h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v195; // [esp-4h] [ebp-28h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v196; // [esp-4h] [ebp-28h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v197; // [esp-4h] [ebp-28h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v198; // [esp-4h] [ebp-28h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v199; // [esp-4h] [ebp-28h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v200; // [esp-4h] [ebp-28h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v201; // [esp-4h] [ebp-28h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v202; // [esp-4h] [ebp-28h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v203; // [esp-4h] [ebp-28h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v204; // [esp-4h] [ebp-28h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v205; // [esp-4h] [ebp-28h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v206; // [esp-4h] [ebp-28h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v207; // [esp-4h] [ebp-28h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v208; // [esp-4h] [ebp-28h]
  vostok::render::enum_rt_usage v209; // [esp+0h] [ebp-24h]
  vostok::render::enum_rt_usage v210; // [esp+0h] [ebp-24h]
  vostok::render::enum_rt_usage v211; // [esp+0h] [ebp-24h]
  vostok::render::enum_rt_usage v212; // [esp+0h] [ebp-24h]
  vostok::render::enum_rt_usage v213; // [esp+0h] [ebp-24h]
  vostok::render::enum_rt_usage v214; // [esp+0h] [ebp-24h]
  vostok::render::enum_rt_usage v215; // [esp+0h] [ebp-24h]
  vostok::render::enum_rt_usage v216; // [esp+0h] [ebp-24h]
  vostok::render::enum_rt_usage v217; // [esp+0h] [ebp-24h]
  vostok::render::enum_rt_usage v218; // [esp+0h] [ebp-24h]
  vostok::render::enum_rt_usage v219; // [esp+0h] [ebp-24h]
  vostok::render::enum_rt_usage v220; // [esp+0h] [ebp-24h]
  vostok::render::enum_rt_usage v221; // [esp+0h] [ebp-24h]
  vostok::render::enum_rt_usage v222; // [esp+0h] [ebp-24h]
  vostok::render::enum_rt_usage v223; // [esp+0h] [ebp-24h]
  vostok::render::enum_rt_usage v224; // [esp+0h] [ebp-24h]
  unsigned int v225; // [esp+0h] [ebp-24h]
  unsigned int v226; // [esp+0h] [ebp-24h]
  unsigned int v227; // [esp+0h] [ebp-24h]
  unsigned int v228; // [esp+0h] [ebp-24h]
  unsigned int v229; // [esp+0h] [ebp-24h]
  unsigned int v230; // [esp+0h] [ebp-24h]
  unsigned int v231; // [esp+0h] [ebp-24h]
  unsigned int v232; // [esp+0h] [ebp-24h]
  unsigned int v233; // [esp+0h] [ebp-24h]
  unsigned int v234; // [esp+0h] [ebp-24h]
  D3D11_USAGE v235; // [esp+4h] [ebp-20h]
  D3D11_USAGE v236; // [esp+4h] [ebp-20h]
  D3D11_USAGE v237; // [esp+4h] [ebp-20h]
  D3D11_USAGE v238; // [esp+4h] [ebp-20h]
  D3D11_USAGE v239; // [esp+4h] [ebp-20h]
  D3D11_USAGE v240; // [esp+4h] [ebp-20h]
  D3D11_USAGE v241; // [esp+4h] [ebp-20h]
  D3D11_USAGE v242; // [esp+4h] [ebp-20h]
  D3D11_USAGE v243; // [esp+4h] [ebp-20h]
  D3D11_USAGE v244; // [esp+4h] [ebp-20h]
  D3D11_USAGE v245; // [esp+4h] [ebp-20h]
  D3D11_USAGE v246; // [esp+4h] [ebp-20h]
  D3D11_USAGE v247; // [esp+4h] [ebp-20h]
  D3D11_USAGE v248; // [esp+4h] [ebp-20h]
  D3D11_USAGE v249; // [esp+4h] [ebp-20h]
  D3D11_USAGE v250; // [esp+4h] [ebp-20h]
  unsigned int v251; // [esp+4h] [ebp-20h]
  unsigned int v252; // [esp+4h] [ebp-20h]
  unsigned int v253; // [esp+4h] [ebp-20h]
  unsigned int v254; // [esp+4h] [ebp-20h]
  unsigned int v255; // [esp+4h] [ebp-20h]
  unsigned int v256; // [esp+4h] [ebp-20h]
  unsigned int v257; // [esp+4h] [ebp-20h]
  unsigned int v258; // [esp+4h] [ebp-20h]
  unsigned int v259; // [esp+4h] [ebp-20h]
  unsigned int v260; // [esp+4h] [ebp-20h]

  v7 = (unsigned int)in_rsm_size;
  in_rsm_size->sh_created = 0;
  *(_DWORD *)(v7 + 4) = 0;
  *(_DWORD *)(v7 + 8) = 0;
  *(_DWORD *)(v7 + 12) = 0;
  *(_DWORD *)(v7 + 16) = 0;
  *(_DWORD *)(v7 + 20) = 0;
  *(_DWORD *)(v7 + 24) = 0;
  *(_DWORD *)(v7 + 28) = 0;
  *(_DWORD *)(v7 + 32) = 0;
  *(_DWORD *)(v7 + 36) = 0;
  *(_DWORD *)(v7 + 40) = 0;
  *(_DWORD *)(v7 + 44) = 0;
  *(_DWORD *)(v7 + 48) = 0;
  *(_DWORD *)(v7 + 52) = 0;
  *(_DWORD *)(v7 + 56) = 0;
  *(_DWORD *)(v7 + 60) = 0;
  *(_DWORD *)(v7 + 64) = 0;
  *(_DWORD *)(v7 + 68) = 0;
  vostok::render::box_geometry::box_geometry((vostok::render::box_geometry *)this);
  vostok::render::injection_geometry::injection_geometry((vostok::render::injection_geometry *)(v7 + 120), in_num_cells);
  *(_DWORD *)(v7 + 144) = 0;
  *(_DWORD *)(v7 + 148) = 0;
  *(_DWORD *)(v7 + 156) = 8;
  *(_DWORD *)(v7 + 160) = 0;
  *(_DWORD *)(v7 + 164) = 0;
  vostok::render::injection_geometry::prepare(v8, v7 + 144);
  v9 = (unsigned int)in_num_propagate_iterations;
  vostok::render::sliced_cube_geometry::sliced_cube_geometry(
    v10,
    (vostok::render::sliced_cube_geometry *)(v7 + 168),
    (unsigned int)in_num_propagate_iterations);
  *(float *)(v7 + 192) = in_flux_amplifier;
  v11 = in_scale;
  *(float *)(v7 + 196) = in_flux_amplifiera;
  *(_DWORD *)(v7 + 200) = v9;
  *(_QWORD *)(v7 + 204) = 0;
  *(_DWORD *)(v7 + 212) = 0;
  *(_QWORD *)(v7 + 216) = 0;
  *(_DWORD *)(v7 + 224) = 0;
  *(_DWORD *)(v7 + 228) = 0;
  *(_DWORD *)(v7 + 232) = 0;
  *(_DWORD *)(v7 + 236) = 0;
  *(float *)(v7 + 264) = v11;
  *(_DWORD *)(v7 + 268) = 0;
  *(_DWORD *)(v7 + 272) = 0;
  *(_DWORD *)(v7 + 276) = 0;
  *(_DWORD *)(v7 + 280) = 0;
  *(_DWORD *)(v7 + 284) = 0;
  *(_DWORD *)(v7 + 288) = 0;
  *(_DWORD *)(v7 + 292) = 0;
  *(_DWORD *)(v7 + 296) = 0;
  *(_DWORD *)(v7 + 300) = 0;
  *(_DWORD *)(v7 + 304) = 0;
  *(_DWORD *)(v7 + 308) = 0;
  *(_DWORD *)(v7 + 312) = 0;
  *(_DWORD *)(v7 + 316) = 0;
  *(_DWORD *)(v7 + 320) = 0;
  *(_DWORD *)(v7 + 324) = 0;
  *(_DWORD *)(v7 + 328) = 0;
  *(_DWORD *)(v7 + 332) = 0;
  *(_DWORD *)(v7 + 336) = 0;
  *(_DWORD *)(v7 + 340) = 0;
  *(_DWORD *)(v7 + 344) = 0;
  *(_DWORD *)(v7 + 348) = 0;
  *(_DWORD *)(v7 + 352) = 0;
  *(_DWORD *)(v7 + 356) = 0;
  *(_DWORD *)(v7 + 360) = 0;
  *(_DWORD *)(v7 + 364) = 0;
  *(_DWORD *)(v7 + 368) = 0;
  *(_DWORD *)(v7 + 372) = 0;
  *(_DWORD *)(v7 + 376) = 0;
  *(_DWORD *)(v7 + 380) = 0;
  v12 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  *(_DWORD *)(v7 + 384) = 0;
  *(_DWORD *)(v7 + 388) = 0;
  *(_DWORD *)(v7 + 392) = 0;
  *(_DWORD *)(v7 + 396) = 0;
  *(_DWORD *)(v7 + 400) = 0;
  *(_BYTE *)(v7 + 460) = 1;
  *(_DWORD *)(v7 + 464) = 0;
  *(_DWORD *)(v7 + 468) = 0;
  *(_DWORD *)(v7 + 472) = 0;
  in_rsm_size = (vostok::render::resource_manager *)(s_lpv1_value ? 28 : 10);
  volume_render_target = vostok::render::resource_manager::create_volume_render_target(
                           v12,
                           v12,
                           v9,
                           v9,
                           v9,
                           (DXGI_FORMAT)in_rsm_size,
                           v209,
                           v235);
  v14 = 0;
  if ( volume_render_target )
  {
    ++volume_render_target->m_reference_count;
    v14 = (vostok::render::resource_manager *)volume_render_target;
  }
  v15 = *(const char **)(v7 + 268);
  *(_DWORD *)(v7 + 268) = v14;
  if ( v15 )
  {
    if ( !--*(_DWORD *)v15 )
      vostok::render::resource_manager::release(
        v14,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v15);
  }
  v16 = in_rsm_size;
  v17 = vostok::render::resource_manager::create_volume_render_target(
          v14,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v9,
          v9,
          v9,
          (DXGI_FORMAT)in_rsm_size,
          v210,
          v236);
  v18 = 0;
  if ( v17 )
  {
    ++v17->m_reference_count;
    v18 = (vostok::render::resource_manager *)v17;
  }
  v19 = *(const char **)(v7 + 272);
  *(_DWORD *)(v7 + 272) = v18;
  if ( v19 )
  {
    if ( !--*(_DWORD *)v19 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v19);
  }
  v20 = vostok::render::resource_manager::create_volume_render_target(
          v18,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v9,
          v9,
          v9,
          (DXGI_FORMAT)v16,
          v211,
          v237);
  v21 = 0;
  if ( v20 )
  {
    ++v20->m_reference_count;
    v21 = (vostok::render::resource_manager *)v20;
  }
  v22 = *(const char **)(v7 + 276);
  *(_DWORD *)(v7 + 276) = v21;
  if ( v22 )
  {
    if ( !--*(_DWORD *)v22 )
      vostok::render::resource_manager::release(
        v21,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v22);
  }
  v23 = vostok::render::resource_manager::create_volume_render_target(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v9,
          v9,
          v9,
          (DXGI_FORMAT)v16,
          v212,
          v238);
  v24 = 0;
  if ( v23 )
  {
    ++v23->m_reference_count;
    v24 = (vostok::render::resource_manager *)v23;
  }
  v25 = *(const char **)(v7 + 364);
  *(_DWORD *)(v7 + 364) = v24;
  if ( v25 )
  {
    if ( !--*(_DWORD *)v25 )
      vostok::render::resource_manager::release(
        v24,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v25);
  }
  v26 = vostok::render::resource_manager::create_volume_render_target(
          v24,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v9,
          v9,
          v9,
          (DXGI_FORMAT)v16,
          v213,
          v239);
  v27 = 0;
  if ( v26 )
  {
    ++v26->m_reference_count;
    v27 = (vostok::render::resource_manager *)v26;
  }
  v28 = *(const char **)(v7 + 368);
  *(_DWORD *)(v7 + 368) = v27;
  if ( v28 )
  {
    if ( !--*(_DWORD *)v28 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v28);
  }
  v29 = vostok::render::resource_manager::create_volume_render_target(
          v27,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v9,
          v9,
          v9,
          (DXGI_FORMAT)v16,
          v214,
          v240);
  v30 = 0;
  if ( v29 )
  {
    ++v29->m_reference_count;
    v30 = (vostok::render::resource_manager *)v29;
  }
  v31 = *(const char **)(v7 + 372);
  *(_DWORD *)(v7 + 372) = v30;
  if ( v31 )
  {
    if ( !--*(_DWORD *)v31 )
      vostok::render::resource_manager::release(
        v30,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v31);
  }
  v32 = *(_DWORD *)(*(_DWORD *)(v7 + 364) + 24);
  v33 = 0;
  if ( v32 )
  {
    v33 = *(const vostok::render::res_texture **)(*(_DWORD *)(v7 + 364) + 24);
    ++*(_DWORD *)(v32 + 4);
  }
  v34 = 0;
  if ( v33 )
  {
    ++v33->m_reference_count;
    v34 = v33;
  }
  v35 = *(const vostok::render::res_texture **)(v7 + 376);
  *(_DWORD *)(v7 + 376) = v34;
  if ( v35 )
  {
    if ( !--v35->m_reference_count )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v30, v35);
  }
  if ( v33 )
  {
    if ( !--v33->m_reference_count )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v30, v33);
  }
  v36 = *(_DWORD *)(*(_DWORD *)(v7 + 368) + 24);
  v37 = 0;
  if ( v36 )
  {
    v37 = *(const vostok::render::res_texture **)(*(_DWORD *)(v7 + 368) + 24);
    ++*(_DWORD *)(v36 + 4);
  }
  v38 = 0;
  if ( v37 )
  {
    ++v37->m_reference_count;
    v38 = v37;
  }
  v39 = *(const vostok::render::res_texture **)(v7 + 380);
  *(_DWORD *)(v7 + 380) = v38;
  if ( v39 )
  {
    if ( !--v39->m_reference_count )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v30, v39);
  }
  if ( v37 )
  {
    if ( !--v37->m_reference_count )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v30, v37);
  }
  v40 = *(_DWORD *)(*(_DWORD *)(v7 + 372) + 24);
  v41 = 0;
  if ( v40 )
  {
    v41 = *(const vostok::render::res_texture **)(*(_DWORD *)(v7 + 372) + 24);
    ++*(_DWORD *)(v40 + 4);
  }
  v42 = 0;
  if ( v41 )
  {
    ++v41->m_reference_count;
    v42 = v41;
  }
  v43 = *(const vostok::render::res_texture **)(v7 + 384);
  *(_DWORD *)(v7 + 384) = v42;
  if ( v43 )
  {
    if ( !--v43->m_reference_count )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v30, v43);
  }
  if ( v41 )
  {
    if ( !--v41->m_reference_count )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v30, v41);
  }
  v44 = in_rsm_size;
  v45 = (unsigned int)in_num_propagate_iterations;
  v46 = vostok::render::resource_manager::create_volume_render_target(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (unsigned int)in_num_propagate_iterations,
          (unsigned int)in_num_propagate_iterations,
          (unsigned int)in_num_propagate_iterations,
          (DXGI_FORMAT)in_rsm_size,
          v215,
          v241);
  v47 = 0;
  if ( v46 )
  {
    ++v46->m_reference_count;
    v47 = (vostok::render::resource_manager *)v46;
  }
  v48 = *(const char **)(v7 + 292);
  *(_DWORD *)(v7 + 292) = v47;
  if ( v48 )
  {
    if ( !--*(_DWORD *)v48 )
      vostok::render::resource_manager::release(
        v47,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v48);
  }
  v49 = vostok::render::resource_manager::create_volume_render_target(
          v47,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v45,
          v45,
          v45,
          (DXGI_FORMAT)v44,
          v216,
          v242);
  v50 = 0;
  if ( v49 )
  {
    ++v49->m_reference_count;
    v50 = (vostok::render::resource_manager *)v49;
  }
  v51 = *(const char **)(v7 + 296);
  *(_DWORD *)(v7 + 296) = v50;
  if ( v51 )
  {
    if ( !--*(_DWORD *)v51 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v51);
  }
  v52 = vostok::render::resource_manager::create_volume_render_target(
          v50,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v45,
          v45,
          v45,
          (DXGI_FORMAT)v44,
          v217,
          v243);
  v53 = 0;
  if ( v52 )
  {
    ++v52->m_reference_count;
    v53 = (vostok::render::resource_manager *)v52;
  }
  v54 = *(const char **)(v7 + 300);
  *(_DWORD *)(v7 + 300) = v53;
  if ( v54 )
  {
    if ( !--*(_DWORD *)v54 )
      vostok::render::resource_manager::release(
        v53,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v54);
  }
  v55 = *(_DWORD *)(*(_DWORD *)(v7 + 292) + 24);
  v56 = 0;
  if ( v55 )
  {
    v56 = *(const vostok::render::res_texture **)(*(_DWORD *)(v7 + 292) + 24);
    ++*(_DWORD *)(v55 + 4);
  }
  v57 = 0;
  if ( v56 )
  {
    ++v56->m_reference_count;
    v57 = v56;
  }
  v58 = *(const vostok::render::res_texture **)(v7 + 304);
  *(_DWORD *)(v7 + 304) = v57;
  if ( v58 )
  {
    if ( !--v58->m_reference_count )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v53, v58);
  }
  if ( v56 )
  {
    if ( !--v56->m_reference_count )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v53, v56);
  }
  v59 = *(_DWORD *)(*(_DWORD *)(v7 + 296) + 24);
  v60 = 0;
  if ( v59 )
  {
    v60 = *(const vostok::render::res_texture **)(*(_DWORD *)(v7 + 296) + 24);
    ++*(_DWORD *)(v59 + 4);
  }
  v61 = 0;
  if ( v60 )
  {
    ++v60->m_reference_count;
    v61 = v60;
  }
  v62 = *(const vostok::render::res_texture **)(v7 + 308);
  *(_DWORD *)(v7 + 308) = v61;
  if ( v62 )
  {
    if ( !--v62->m_reference_count )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v53, v62);
  }
  if ( v60 )
  {
    if ( !--v60->m_reference_count )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v53, v60);
  }
  v63 = *(_DWORD *)(*(_DWORD *)(v7 + 300) + 24);
  v64 = 0;
  if ( v63 )
  {
    v64 = *(const vostok::render::res_texture **)(*(_DWORD *)(v7 + 300) + 24);
    ++*(_DWORD *)(v63 + 4);
  }
  v65 = 0;
  if ( v64 )
  {
    ++v64->m_reference_count;
    v65 = v64;
  }
  v66 = *(const vostok::render::res_texture **)(v7 + 312);
  *(_DWORD *)(v7 + 312) = v65;
  if ( v66 )
  {
    if ( !--v66->m_reference_count )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v53, v66);
  }
  if ( v64 )
  {
    if ( !--v64->m_reference_count )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v53, v64);
  }
  v67 = in_rsm_size;
  v68 = (unsigned int)in_num_propagate_iterations;
  v69 = vostok::render::resource_manager::create_volume_render_target(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (unsigned int)in_num_propagate_iterations,
          (unsigned int)in_num_propagate_iterations,
          (unsigned int)in_num_propagate_iterations,
          (DXGI_FORMAT)in_rsm_size,
          v218,
          v244);
  v70 = 0;
  if ( v69 )
  {
    ++v69->m_reference_count;
    v70 = (vostok::render::resource_manager *)v69;
  }
  v71 = *(const char **)(v7 + 316);
  *(_DWORD *)(v7 + 316) = v70;
  if ( v71 )
  {
    if ( !--*(_DWORD *)v71 )
      vostok::render::resource_manager::release(
        v70,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v71);
  }
  v72 = vostok::render::resource_manager::create_volume_render_target(
          v70,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v68,
          v68,
          v68,
          (DXGI_FORMAT)v67,
          v219,
          v245);
  v73 = 0;
  if ( v72 )
  {
    ++v72->m_reference_count;
    v73 = (vostok::render::resource_manager *)v72;
  }
  v74 = *(const char **)(v7 + 320);
  *(_DWORD *)(v7 + 320) = v73;
  if ( v74 )
  {
    if ( !--*(_DWORD *)v74 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v74);
  }
  v75 = vostok::render::resource_manager::create_volume_render_target(
          v73,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v68,
          v68,
          v68,
          (DXGI_FORMAT)v67,
          v220,
          v246);
  v76 = 0;
  if ( v75 )
  {
    ++v75->m_reference_count;
    v76 = (vostok::render::resource_manager *)v75;
  }
  v77 = *(const char **)(v7 + 324);
  *(_DWORD *)(v7 + 324) = v76;
  if ( v77 )
  {
    if ( !--*(_DWORD *)v77 )
      vostok::render::resource_manager::release(
        v76,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v77);
  }
  v190 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(v7 + 316) + 24);
  in_num_cells = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v76,
    (vostok::render::res_texture **)&in_num_cells,
    v190);
  v79 = (const vostok::render::res_texture *)in_num_cells;
  v80 = 0;
  if ( in_num_cells )
  {
    ++*(_DWORD *)(in_num_cells + 4);
    v80 = v79;
  }
  v81 = *(const vostok::render::res_texture **)(v7 + 328);
  *(_DWORD *)(v7 + 328) = v80;
  if ( v81 )
  {
    if ( !--v81->m_reference_count )
      vostok::render::res_texture::destroy_impl(v78, v81);
  }
  if ( v79 )
  {
    if ( !--v79->m_reference_count )
      vostok::render::res_texture::destroy_impl(v78, v79);
  }
  v191 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(v7 + 320) + 24);
  in_num_cells = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v78,
    (vostok::render::res_texture **)&in_num_cells,
    v191);
  v83 = (const vostok::render::res_texture *)in_num_cells;
  v84 = 0;
  if ( in_num_cells )
  {
    ++*(_DWORD *)(in_num_cells + 4);
    v84 = v83;
  }
  v85 = *(const vostok::render::res_texture **)(v7 + 332);
  *(_DWORD *)(v7 + 332) = v84;
  if ( v85 )
  {
    if ( !--v85->m_reference_count )
      vostok::render::res_texture::destroy_impl(v82, v85);
  }
  if ( v83 )
  {
    if ( !--v83->m_reference_count )
      vostok::render::res_texture::destroy_impl(v82, v83);
  }
  v192 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(v7 + 324) + 24);
  in_num_cells = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v82,
    (vostok::render::res_texture **)&in_num_cells,
    v192);
  v87 = (const vostok::render::res_texture *)in_num_cells;
  v88 = 0;
  if ( in_num_cells )
  {
    ++*(_DWORD *)(in_num_cells + 4);
    v88 = v87;
  }
  v89 = *(const vostok::render::res_texture **)(v7 + 336);
  *(_DWORD *)(v7 + 336) = v88;
  if ( v89 )
  {
    if ( !--v89->m_reference_count )
      vostok::render::res_texture::destroy_impl(v86, v89);
  }
  if ( v87 )
  {
    if ( !--v87->m_reference_count )
      vostok::render::res_texture::destroy_impl(v86, v87);
  }
  v193 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(v7 + 268) + 24);
  in_num_cells = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v86,
    (vostok::render::res_texture **)&in_num_cells,
    v193);
  in_flux_amplifier = 0.0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_num_cells,
    (vostok::render::res_texture **)&in_flux_amplifier,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_num_cells);
  v91 = *(const vostok::render::res_texture **)(v7 + 280);
  *(float *)(v7 + 280) = in_flux_amplifier;
  if ( v91 )
  {
    if ( !--v91->m_reference_count )
      vostok::render::res_texture::destroy_impl(v90, v91);
  }
  v92 = (const vostok::render::res_texture *)in_num_cells;
  if ( in_num_cells )
  {
    --*(_DWORD *)(in_num_cells + 4);
    if ( !v92->m_reference_count )
      vostok::render::res_texture::destroy_impl(v90, v92);
  }
  v194 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(v7 + 272) + 24);
  in_num_cells = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v90,
    (vostok::render::res_texture **)&in_num_cells,
    v194);
  in_flux_amplifier = 0.0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v93,
    (vostok::render::res_texture **)&in_flux_amplifier,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_num_cells);
  v95 = *(const vostok::render::res_texture **)(v7 + 284);
  *(float *)(v7 + 284) = in_flux_amplifier;
  if ( v95 )
  {
    if ( !--v95->m_reference_count )
      vostok::render::res_texture::destroy_impl(v94, v95);
  }
  v96 = (const vostok::render::res_texture *)in_num_cells;
  if ( in_num_cells )
  {
    --*(_DWORD *)(in_num_cells + 4);
    if ( !v96->m_reference_count )
      vostok::render::res_texture::destroy_impl(v94, v96);
  }
  v195 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(v7 + 276) + 24);
  in_num_cells = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v94,
    (vostok::render::res_texture **)&in_num_cells,
    v195);
  in_flux_amplifier = 0.0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v97,
    (vostok::render::res_texture **)&in_flux_amplifier,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_num_cells);
  v99 = *(const vostok::render::res_texture **)(v7 + 288);
  *(float *)(v7 + 288) = in_flux_amplifier;
  if ( v99 )
  {
    if ( !--v99->m_reference_count )
      vostok::render::res_texture::destroy_impl(v98, v99);
  }
  v100 = (const vostok::render::res_texture *)in_num_cells;
  if ( in_num_cells )
  {
    --*(_DWORD *)(in_num_cells + 4);
    if ( !v100->m_reference_count )
      vostok::render::res_texture::destroy_impl(v98, v100);
  }
  v101 = vostok::render::resource_manager::create_volume_render_target(
           in_rsm_size,
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           (unsigned int)in_num_propagate_iterations,
           (unsigned int)in_num_propagate_iterations,
           (unsigned int)in_num_propagate_iterations,
           (DXGI_FORMAT)in_rsm_size,
           v221,
           v247);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v101,
    (vostok::render::resource_manager **)(v7 + 388));
  v196 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(v7 + 388) + 24);
  in_num_cells = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v102,
    (vostok::render::res_texture **)&in_num_cells,
    v196);
  in_flux_amplifier = 0.0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v103,
    (vostok::render::res_texture **)&in_flux_amplifier,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_num_cells);
  v105 = *(const vostok::render::res_texture **)(v7 + 392);
  *(float *)(v7 + 392) = in_flux_amplifier;
  if ( v105 )
  {
    if ( !--v105->m_reference_count )
      vostok::render::res_texture::destroy_impl(v104, v105);
  }
  v106 = (const vostok::render::res_texture *)in_num_cells;
  if ( in_num_cells )
  {
    --*(_DWORD *)(in_num_cells + 4);
    if ( !v106->m_reference_count )
      vostok::render::res_texture::destroy_impl(v104, v106);
  }
  v107 = (unsigned int)in_num_propagate_iterations;
  v108 = vostok::render::resource_manager::create_volume_render_target(
           in_rsm_size,
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           (unsigned int)in_num_propagate_iterations,
           (unsigned int)in_num_propagate_iterations,
           (unsigned int)in_num_propagate_iterations,
           (DXGI_FORMAT)in_rsm_size,
           v222,
           v248);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v108,
    (vostok::render::resource_manager **)(v7 + 340));
  v109 = vostok::render::resource_manager::create_volume_render_target(
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           v107,
           v107,
           v107,
           (DXGI_FORMAT)in_rsm_size,
           v223,
           v249);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v109,
    (vostok::render::resource_manager **)(v7 + 344));
  v111 = vostok::render::resource_manager::create_volume_render_target(
           v110,
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           v107,
           v107,
           v107,
           (DXGI_FORMAT)in_rsm_size,
           v224,
           v250);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v111,
    (vostok::render::resource_manager **)(v7 + 348));
  v197 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(v7 + 340) + 24);
  in_rsm_size = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v112,
    (vostok::render::res_texture **)&in_rsm_size,
    v197);
  in_num_cells = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_rsm_size,
    (vostok::render::res_texture **)&in_num_cells,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_rsm_size);
  v114 = *(const vostok::render::res_texture **)(v7 + 352);
  *(_DWORD *)(v7 + 352) = in_num_cells;
  if ( v114 )
  {
    if ( !--v114->m_reference_count )
      vostok::render::res_texture::destroy_impl(v113, v114);
  }
  v115 = (const vostok::render::res_texture *)in_rsm_size;
  if ( in_rsm_size )
  {
    --in_rsm_size->sh_returned;
    if ( !v115->m_reference_count )
      vostok::render::res_texture::destroy_impl(v113, v115);
  }
  v198 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(v7 + 344) + 24);
  in_rsm_size = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v113,
    (vostok::render::res_texture **)&in_rsm_size,
    v198);
  in_num_cells = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v116,
    (vostok::render::res_texture **)&in_num_cells,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_rsm_size);
  v118 = *(const vostok::render::res_texture **)(v7 + 356);
  *(_DWORD *)(v7 + 356) = in_num_cells;
  if ( v118 )
  {
    if ( !--v118->m_reference_count )
      vostok::render::res_texture::destroy_impl(v117, v118);
  }
  v119 = (const vostok::render::res_texture *)in_rsm_size;
  if ( in_rsm_size )
  {
    --in_rsm_size->sh_returned;
    if ( !v119->m_reference_count )
      vostok::render::res_texture::destroy_impl(v117, v119);
  }
  v199 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(v7 + 348) + 24);
  in_rsm_size = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v117,
    (vostok::render::res_texture **)&in_rsm_size,
    v199);
  in_num_cells = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v120,
    (vostok::render::res_texture **)&in_num_cells,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_rsm_size);
  v122 = *(const vostok::render::res_texture **)(v7 + 360);
  *(_DWORD *)(v7 + 360) = in_num_cells;
  if ( v122 )
  {
    if ( !--v122->m_reference_count )
      vostok::render::res_texture::destroy_impl(v121, v122);
  }
  v123 = (const vostok::render::res_texture *)in_rsm_size;
  if ( in_rsm_size )
  {
    --in_rsm_size->sh_returned;
    if ( !v123->m_reference_count )
      vostok::render::res_texture::destroy_impl(v121, v123);
  }
  M_start = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
  v125 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 33);
  v126 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  *(_DWORD *)(v7 + 76) = v125;
  *(_DWORD *)(v7 + 72) = v125 >> 1;
  render_target = vostok::render::resource_manager::create_render_target(
                    (vostok::render::resource_manager *)M_start,
                    v126,
                    0,
                    *(vostok::render::res_texture **)(v7 + 76),
                    *(ID3D11Texture2D ***)(v7 + 76),
                    (const char *)0xA,
                    enum_rt_usage_render_target,
                    0,
                    0,
                    v225,
                    v251);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)render_target,
    (vostok::render::resource_manager **)v7);
  v200 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)v7 + 24);
  in_rsm_size = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v128,
    (vostok::render::res_texture **)&in_rsm_size,
    v200);
  in_num_cells = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v129,
    (vostok::render::res_texture **)&in_num_cells,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_rsm_size);
  v131 = *(const vostok::render::res_texture **)(v7 + 4);
  *(_DWORD *)(v7 + 4) = in_num_cells;
  if ( v131 )
  {
    if ( !--v131->m_reference_count )
      vostok::render::res_texture::destroy_impl(v130, v131);
  }
  v132 = (const vostok::render::res_texture *)in_rsm_size;
  if ( in_rsm_size )
  {
    --in_rsm_size->sh_returned;
    if ( !v132->m_reference_count )
      vostok::render::res_texture::destroy_impl(v130, v132);
  }
  v133 = vostok::render::resource_manager::create_render_target(
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           0,
           *(vostok::render::res_texture **)(v7 + 76),
           *(ID3D11Texture2D ***)(v7 + 76),
           (const char *)0xA,
           enum_rt_usage_render_target,
           0,
           0,
           v226,
           v252);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v133,
    (vostok::render::resource_manager **)(v7 + 8));
  v201 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(v7 + 8) + 24);
  in_rsm_size = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v134,
    (vostok::render::res_texture **)&in_rsm_size,
    v201);
  in_num_cells = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v135,
    (vostok::render::res_texture **)&in_num_cells,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_rsm_size);
  v137 = *(const vostok::render::res_texture **)(v7 + 12);
  *(_DWORD *)(v7 + 12) = in_num_cells;
  if ( v137 )
  {
    if ( !--v137->m_reference_count )
      vostok::render::res_texture::destroy_impl(v136, v137);
  }
  v138 = (const vostok::render::res_texture *)in_rsm_size;
  if ( in_rsm_size )
  {
    --in_rsm_size->sh_returned;
    if ( !v138->m_reference_count )
      vostok::render::res_texture::destroy_impl(v136, v138);
  }
  v139 = vostok::render::resource_manager::create_render_target(
           (vostok::render::resource_manager *)v136,
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           0,
           *(vostok::render::res_texture **)(v7 + 76),
           *(ID3D11Texture2D ***)(v7 + 76),
           (const char *)0xA,
           enum_rt_usage_render_target,
           0,
           0,
           v227,
           v253);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v139,
    (vostok::render::resource_manager **)(v7 + 16));
  v202 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(v7 + 16) + 24);
  in_rsm_size = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v140,
    (vostok::render::res_texture **)&in_rsm_size,
    v202);
  in_num_cells = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_rsm_size,
    (vostok::render::res_texture **)&in_num_cells,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_rsm_size);
  v142 = *(const vostok::render::res_texture **)(v7 + 20);
  *(_DWORD *)(v7 + 20) = in_num_cells;
  if ( v142 )
  {
    if ( !--v142->m_reference_count )
      vostok::render::res_texture::destroy_impl(v141, v142);
  }
  v143 = (const vostok::render::res_texture *)in_rsm_size;
  if ( in_rsm_size )
  {
    --in_rsm_size->sh_returned;
    if ( !v143->m_reference_count )
      vostok::render::res_texture::destroy_impl(v141, v143);
  }
  v144 = vostok::render::resource_manager::create_render_target(
           (vostok::render::resource_manager *)v141,
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           0,
           *(vostok::render::res_texture **)(v7 + 76),
           *(ID3D11Texture2D ***)(v7 + 76),
           (const char *)0xA,
           enum_rt_usage_render_target,
           0,
           0,
           v228,
           v254);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v144,
    (vostok::render::resource_manager **)(v7 + 24));
  v203 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(v7 + 24) + 24);
  in_rsm_size = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v145,
    (vostok::render::res_texture **)&in_rsm_size,
    v203);
  in_num_cells = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v146,
    (vostok::render::res_texture **)&in_num_cells,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_rsm_size);
  v148 = *(const vostok::render::res_texture **)(v7 + 28);
  *(_DWORD *)(v7 + 28) = in_num_cells;
  if ( v148 )
  {
    if ( !--v148->m_reference_count )
      vostok::render::res_texture::destroy_impl(v147, v148);
  }
  v149 = (const vostok::render::res_texture *)in_rsm_size;
  if ( in_rsm_size )
  {
    --in_rsm_size->sh_returned;
    if ( !v149->m_reference_count )
      vostok::render::res_texture::destroy_impl(v147, v149);
  }
  v150 = vostok::render::resource_manager::create_render_target(
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           0,
           *(vostok::render::res_texture **)(v7 + 76),
           *(ID3D11Texture2D ***)(v7 + 76),
           (const char *)0xA,
           enum_rt_usage_render_target,
           0,
           0,
           v229,
           v255);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v150,
    (vostok::render::resource_manager **)(v7 + 32));
  v204 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(v7 + 32) + 24);
  in_rsm_size = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v151,
    (vostok::render::res_texture **)&in_rsm_size,
    v204);
  in_num_cells = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v152,
    (vostok::render::res_texture **)&in_num_cells,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_rsm_size);
  v154 = *(const vostok::render::res_texture **)(v7 + 36);
  *(_DWORD *)(v7 + 36) = in_num_cells;
  if ( v154 )
  {
    if ( !--v154->m_reference_count )
      vostok::render::res_texture::destroy_impl(v153, v154);
  }
  v155 = (const vostok::render::res_texture *)in_rsm_size;
  if ( in_rsm_size )
  {
    --in_rsm_size->sh_returned;
    if ( !v155->m_reference_count )
      vostok::render::res_texture::destroy_impl(v153, v155);
  }
  v156 = vostok::render::resource_manager::create_render_target(
           (vostok::render::resource_manager *)v153,
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           0,
           *(vostok::render::res_texture **)(v7 + 76),
           *(ID3D11Texture2D ***)(v7 + 76),
           (const char *)0xA,
           enum_rt_usage_render_target,
           0,
           0,
           v230,
           v256);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v156,
    (vostok::render::resource_manager **)(v7 + 40));
  v205 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(v7 + 40) + 24);
  in_rsm_size = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v157,
    (vostok::render::res_texture **)&in_rsm_size,
    v205);
  in_num_cells = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_rsm_size,
    (vostok::render::res_texture **)&in_num_cells,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_rsm_size);
  v159 = *(const vostok::render::res_texture **)(v7 + 44);
  *(_DWORD *)(v7 + 44) = in_num_cells;
  if ( v159 )
  {
    if ( !--v159->m_reference_count )
      vostok::render::res_texture::destroy_impl(v158, v159);
  }
  v160 = (const vostok::render::res_texture *)in_rsm_size;
  if ( in_rsm_size )
  {
    --in_rsm_size->sh_returned;
    if ( !v160->m_reference_count )
      vostok::render::res_texture::destroy_impl(v158, v160);
  }
  v161 = vostok::render::resource_manager::create_render_target(
           (vostok::render::resource_manager *)v158,
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           0,
           *(vostok::render::res_texture **)(v7 + 72),
           *(ID3D11Texture2D ***)(v7 + 72),
           (const char *)0xA,
           enum_rt_usage_render_target,
           0,
           0,
           v231,
           v257);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v161,
    (vostok::render::resource_manager **)(v7 + 48));
  v206 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(v7 + 48) + 24);
  in_rsm_size = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v162,
    (vostok::render::res_texture **)&in_rsm_size,
    v206);
  in_num_cells = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v163,
    (vostok::render::res_texture **)&in_num_cells,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_rsm_size);
  v165 = *(const vostok::render::res_texture **)(v7 + 52);
  *(_DWORD *)(v7 + 52) = in_num_cells;
  if ( v165 )
  {
    if ( !--v165->m_reference_count )
      vostok::render::res_texture::destroy_impl(v164, v165);
  }
  v166 = (const vostok::render::res_texture *)in_rsm_size;
  if ( in_rsm_size )
  {
    --in_rsm_size->sh_returned;
    if ( !v166->m_reference_count )
      vostok::render::res_texture::destroy_impl(v164, v166);
  }
  v167 = vostok::render::resource_manager::create_render_target(
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           0,
           *(vostok::render::res_texture **)(v7 + 72),
           *(ID3D11Texture2D ***)(v7 + 72),
           (const char *)0xA,
           enum_rt_usage_render_target,
           0,
           0,
           v232,
           v258);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v167,
    (vostok::render::resource_manager **)(v7 + 56));
  v207 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(v7 + 56) + 24);
  in_rsm_size = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v168,
    (vostok::render::res_texture **)&in_rsm_size,
    v207);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_rsm_size,
    (vostok::render::res_texture **)(v7 + 60));
  v170 = (const vostok::render::res_texture *)in_rsm_size;
  if ( in_rsm_size )
  {
    --in_rsm_size->sh_returned;
    if ( !v170->m_reference_count )
      vostok::render::res_texture::destroy_impl(v169, v170);
  }
  v171 = vostok::render::resource_manager::create_render_target(
           (vostok::render::resource_manager *)v169,
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           0,
           *(vostok::render::res_texture **)(v7 + 72),
           *(ID3D11Texture2D ***)(v7 + 72),
           (const char *)0xA,
           enum_rt_usage_render_target,
           0,
           0,
           v233,
           v259);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v171,
    (vostok::render::resource_manager **)(v7 + 64));
  v208 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(v7 + 64) + 24);
  in_rsm_size = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v172,
    (vostok::render::res_texture **)&in_rsm_size,
    v208);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_rsm_size,
    (vostok::render::res_texture **)(v7 + 68));
  v174 = (const vostok::render::res_texture *)in_rsm_size;
  if ( in_rsm_size )
  {
    --in_rsm_size->sh_returned;
    if ( !v174->m_reference_count )
      vostok::render::res_texture::destroy_impl(v173, v174);
  }
  v175 = vostok::render::resource_manager::create_render_target(
           (vostok::render::resource_manager *)v173,
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           0,
           in_num_propagate_iterations,
           (ID3D11Texture2D **)in_num_propagate_iterations,
           (const char *)0x35,
           enum_rt_usage_depth_stencil,
           0,
           0,
           v234,
           v260);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v175,
    (vostok::render::resource_manager **)(v7 + 396));
  vostok::shared_string::shared_string((vostok::shared_string *)&in_num_propagate_iterations, "rsm_size");
  *(_DWORD *)(v7 + 404) = vostok::render::backend::register_constant_host(
                            (vostok::render::backend *)&in_num_propagate_iterations,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&in_num_propagate_iterations,
                            rc_int);
  if ( in_num_propagate_iterations
    && !_InterlockedExchangeAdd((volatile signed __int32 *)in_num_propagate_iterations, 0xFFFFFFFF) )
  {
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  vostok::shared_string::shared_string((vostok::shared_string *)&in_num_propagate_iterations, "grid_size");
  *(_DWORD *)(v7 + 408) = vostok::render::backend::register_constant_host(
                            v176,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&in_num_propagate_iterations,
                            rc_float);
  if ( in_num_propagate_iterations )
  {
    v177 = (vostok::strings::shared::manager *)in_num_propagate_iterations;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)in_num_propagate_iterations, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(v177, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  vostok::shared_string::shared_string((vostok::shared_string *)&in_num_propagate_iterations, "grid_origin");
  *(_DWORD *)(v7 + 412) = vostok::render::backend::register_constant_host(
                            (vostok::render::backend *)&in_num_propagate_iterations,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&in_num_propagate_iterations,
                            rc_float);
  if ( in_num_propagate_iterations
    && !_InterlockedExchangeAdd((volatile signed __int32 *)in_num_propagate_iterations, 0xFFFFFFFF) )
  {
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  vostok::shared_string::shared_string(
    (vostok::shared_string *)&in_num_propagate_iterations,
    "grid_origin_and_inv_grid_scale");
  *(_DWORD *)(v7 + 416) = vostok::render::backend::register_constant_host(
                            v178,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&in_num_propagate_iterations,
                            rc_float);
  if ( in_num_propagate_iterations )
  {
    v179 = (vostok::strings::shared::manager *)in_num_propagate_iterations;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)in_num_propagate_iterations, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(v179, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  vostok::shared_string::shared_string((vostok::shared_string *)&in_num_propagate_iterations, "grid_cell_size");
  *(_DWORD *)(v7 + 420) = vostok::render::backend::register_constant_host(
                            (vostok::render::backend *)&in_num_propagate_iterations,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&in_num_propagate_iterations,
                            rc_float);
  if ( in_num_propagate_iterations
    && !_InterlockedExchangeAdd((volatile signed __int32 *)in_num_propagate_iterations, 0xFFFFFFFF) )
  {
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  vostok::shared_string::shared_string((vostok::shared_string *)&in_num_propagate_iterations, "num_grid_cells");
  *(_DWORD *)(v7 + 424) = vostok::render::backend::register_constant_host(
                            v180,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&in_num_propagate_iterations,
                            rc_float);
  if ( in_num_propagate_iterations )
  {
    v181 = (vostok::strings::shared::manager *)in_num_propagate_iterations;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)in_num_propagate_iterations, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(v181, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  vostok::shared_string::shared_string((vostok::shared_string *)&in_num_propagate_iterations, "light_direction");
  *(_DWORD *)(v7 + 428) = vostok::render::backend::register_constant_host(
                            (vostok::render::backend *)&in_num_propagate_iterations,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&in_num_propagate_iterations,
                            rc_float);
  if ( in_num_propagate_iterations
    && !_InterlockedExchangeAdd((volatile signed __int32 *)in_num_propagate_iterations, 0xFFFFFFFF) )
  {
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  vostok::shared_string::shared_string((vostok::shared_string *)&in_num_propagate_iterations, "light_position");
  *(_DWORD *)(v7 + 432) = vostok::render::backend::register_constant_host(
                            v182,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&in_num_propagate_iterations,
                            rc_float);
  if ( in_num_propagate_iterations )
  {
    v183 = (vostok::strings::shared::manager *)in_num_propagate_iterations;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)in_num_propagate_iterations, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(v183, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  vostok::shared_string::shared_string(
    (vostok::shared_string *)&in_num_propagate_iterations,
    "propagate_iteration_index");
  *(_DWORD *)(v7 + 436) = vostok::render::backend::register_constant_host(
                            (vostok::render::backend *)&in_num_propagate_iterations,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&in_num_propagate_iterations,
                            rc_int);
  if ( in_num_propagate_iterations
    && !_InterlockedExchangeAdd((volatile signed __int32 *)in_num_propagate_iterations, 0xFFFFFFFF) )
  {
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  vostok::shared_string::shared_string((vostok::shared_string *)&in_num_propagate_iterations, "inject_flux_weight");
  *(_DWORD *)(v7 + 440) = vostok::render::backend::register_constant_host(
                            v184,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&in_num_propagate_iterations,
                            rc_float);
  if ( in_num_propagate_iterations )
  {
    v185 = (vostok::strings::shared::manager *)in_num_propagate_iterations;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)in_num_propagate_iterations, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(v185, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  vostok::shared_string::shared_string((vostok::shared_string *)&in_num_propagate_iterations, "flux_amplifier");
  *(_DWORD *)(v7 + 444) = vostok::render::backend::register_constant_host(
                            (vostok::render::backend *)&in_num_propagate_iterations,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&in_num_propagate_iterations,
                            rc_float);
  if ( in_num_propagate_iterations
    && !_InterlockedExchangeAdd((volatile signed __int32 *)in_num_propagate_iterations, 0xFFFFFFFF) )
  {
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  vostok::shared_string::shared_string((vostok::shared_string *)&in_num_propagate_iterations, "s_eye_ray_corner");
  *(_DWORD *)(v7 + 448) = vostok::render::backend::register_constant_host(
                            v186,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&in_num_propagate_iterations,
                            rc_float);
  if ( in_num_propagate_iterations )
  {
    v187 = (vostok::strings::shared::manager *)in_num_propagate_iterations;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)in_num_propagate_iterations, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(v187, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  vostok::shared_string::shared_string((vostok::shared_string *)&in_num_propagate_iterations, "cascade_index");
  *(_DWORD *)(v7 + 452) = vostok::render::backend::register_constant_host(
                            (vostok::render::backend *)&in_num_propagate_iterations,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&in_num_propagate_iterations,
                            rc_int);
  if ( in_num_propagate_iterations
    && !_InterlockedExchangeAdd((volatile signed __int32 *)in_num_propagate_iterations, 0xFFFFFFFF) )
  {
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  vostok::shared_string::shared_string((vostok::shared_string *)&in_num_propagate_iterations, "occlusion_amplifier");
  *(_DWORD *)(v7 + 456) = vostok::render::backend::register_constant_host(
                            v188,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            (const vostok::shared_string *)&in_num_propagate_iterations,
                            rc_float);
  if ( in_num_propagate_iterations )
  {
    v189 = (vostok::strings::shared::manager *)in_num_propagate_iterations;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)in_num_propagate_iterations, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(v189, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  vostok::render::effect_manager::create_effect<vostok::render::effect_light_propagation_volumes>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)(v7 + 400));
}
