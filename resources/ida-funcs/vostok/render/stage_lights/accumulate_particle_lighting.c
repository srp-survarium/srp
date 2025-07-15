void __thiscall vostok::render::stage_lights::accumulate_particle_lighting(
        vostok::render::stage_lights *this,
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> lq,
        char a3)
{
  vostok::render::render_target *m_object; // ebx
  unsigned int m_checksum; // eax
  unsigned int m_length; // esi
  float x; // ecx
  vostok::render::environment_probe **v7; // edi
  int v8; // eax
  int v9; // edx
  vostok::render::render_target *v10; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *rt; // eax
  float z; // edi
  vostok::render::render_target *v13; // eax
  vostok::render::renderer_context *v14; // ecx
  vostok::render::render_target *v15; // eax
  vostok::render::backend *v16; // ecx
  vostok::render::render_target *v17; // eax
  unsigned int m_end; // ecx
  vostok::render::ambient_light **m_begin; // eax
  bool i; // zf
  long double v21; // rdi
  vostok::strings::shared::profile *v22; // ecx
  int *v23; // edi
  float v24; // xmm0_4
  unsigned int v25; // xmm1_4
  unsigned int v26; // xmm2_4
  void *v27; // esp
  vostok::math::float3 *sun_direction; // eax
  float y; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm4_4
  vostok::render::environment_properties *v33; // ecx
  vostok::math::float3 *v34; // eax
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm4_4
  int v39; // xmm2_4
  unsigned int v40; // ecx
  int v41; // ecx
  float v42; // xmm5_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  float v45; // xmm4_4
  float v46; // xmm6_4
  float v47; // xmm2_4
  float v48; // xmm0_4
  float v49; // xmm3_4
  float v50; // xmm0_4
  float v51; // xmm6_4
  float v52; // xmm1_4
  float v53; // xmm0_4
  float v54; // xmm3_4
  float v55; // xmm0_4
  vostok::math::float4x4 *v56; // eax
  vostok::math::cuboid *v57; // ecx
  double v58; // xmm0_8
  double v59; // xmm0_8
  float v60; // xmm0_4
  float *p_m_reference_count; // eax
  const vostok::math::float3 **v62; // ecx
  float v63; // xmm2_4
  float v64; // xmm3_4
  float v65; // xmm4_4
  float v66; // xmm7_4
  float v67; // xmm6_4
  float v68; // xmm7_4
  float v69; // xmm3_4
  float v70; // xmm2_4
  float v71; // xmm4_4
  float v72; // xmm6_4
  float v73; // xmm7_4
  const vostok::math::float3 *v74; // xmm2_4
  const vostok::math::float3 *v75; // eax
  const vostok::math::float3 *v76; // xmm1_4
  const vostok::math::float3 *v77; // xmm1_4
  unsigned int v78; // eax
  unsigned int *v79; // eax
  vostok::render::shader_buffer *v80; // ecx
  vostok::render::untyped_buffer **v81; // edx
  ID3D11ShaderResourceView **v82; // edi
  float v83; // xmm2_4
  vostok::render::render_particle_emitter_instance *v84; // ecx
  unsigned int v85; // eax
  float v86; // xmm0_4
  const vostok::math::float3 *v87; // eax
  float v88; // xmm1_4
  float v89; // xmm0_4
  vostok::render::material_effects *material_effects; // eax
  float v91; // esi
  const vostok::render::shader_constant_host **p_m_order; // edi
  const vostok::math::float4x4 *view2shadow; // eax
  vostok::math::float4x4 *v94; // eax
  const vostok::render::shader_constant_host *v95; // eax
  vostok::render::resource_manager *v96; // ecx
  vostok::render::buffers_handler<0> *v97; // ecx
  vostok::render::res_texture *v98; // edi
  float v99; // esi
  vostok::render::textures_handler<0> *v100; // ecx
  vostok::render::resource_manager *v101; // ecx
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v102; // edi
  float v103; // esi
  unsigned int v104; // xmm0_4
  unsigned int v105; // xmm0_4
  const vostok::render::shader_constant_host *m_rt; // eax
  double v107; // st7
  int v108; // eax
  const vostok::render::shader_constant_host *m_zrt; // eax
  float v110; // xmm0_4
  vostok::math::float4x4 *v111; // eax
  vostok::math::float4x4 *v112; // esi
  vostok::math::float3 *scale; // eax
  float v114; // esi
  const vostok::render::shader_constant_host *v115; // eax
  const vostok::render::shader_constant_host *v116; // eax
  vostok::math::float4x4 *v117; // eax
  vostok::render::textures_handler<0> **default_texture; // eax
  float v119; // esi
  vostok::render::resource_manager *v120; // ecx
  const vostok::render::shader_constant_host *v121; // eax
  const vostok::render::shader_constant_host *v122; // eax
  const vostok::render::shader_constant_host *v123; // eax
  const vostok::render::shader_constant_host *v124; // eax
  vostok::math::float4x4 *v125; // ecx
  vostok::math::float4x4 *v126; // eax
  const vostok::render::shader_constant_host *m_memory_usage; // eax
  const vostok::math::float4x4 *v128; // eax
  vostok::math::float4x4 *v129; // eax
  const vostok::render::shader_constant_host **v130; // edi
  const vostok::math::float4x4 *v131; // eax
  vostok::math::float4x4 *v132; // eax
  vostok::render::backend *v133; // ecx
  vostok::render::backend *v134; // ecx
  vostok::render::buffers_handler<0> *v135; // ecx
  vostok::render::resource_manager *v136; // ecx
  vostok::render::res_texture *v137; // edi
  vostok::render::backend *v138; // ecx
  vostok::render::resource_manager *v139; // ecx
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v140; // edi
  float v141; // esi
  float v142; // xmm0_4
  vostok::render::backend *v143; // ecx
  double v144; // st7
  int v145; // eax
  float v146; // xmm0_4
  vostok::math::float4x4 *v147; // eax
  vostok::math::float4x4 *v148; // esi
  vostok::math::float3 *v149; // eax
  float v150; // esi
  float v151; // xmm0_4
  vostok::render::backend *v152; // ecx
  vostok::math::float3 *v153; // eax
  float v154; // xmm0_4
  vostok::render::backend *v155; // ecx
  vostok::math::float4x4 *v156; // eax
  vostok::render::backend *v157; // ecx
  vostok::render::backend *v158; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v159; // eax
  vostok::render::backend *v160; // ecx
  vostok::render::resource_manager *v161; // ecx
  vostok::render::backend *v162; // ecx
  vostok::render::backend *v163; // ecx
  vostok::render::backend *v164; // ecx
  vostok::math::float4x4 *v165; // ecx
  vostok::math::float4x4 *v166; // eax
  vostok::render::backend *v167; // ecx
  vostok::render::backend *v168; // ecx
  vostok::strings::shared::profile *v169; // eax
  int x_low; // edi
  float *v171; // eax
  float v172; // xmm0_4
  float v173; // xmm1_4
  const vostok::render::shader_constant_host *m_surface; // eax
  vostok::render::particle_shader_constants *v175; // ecx
  vostok::math::float3 *v176; // esi
  vostok::render::render_particle_emitter_instance *v177; // ecx
  float v178; // eax
  int v179; // esi
  vostok::math::float3 v180; // [esp-24h] [ebp-1610h]
  vostok::math::float3 v181; // [esp-Ch] [ebp-15F8h]
  vostok::render::renderer *v182; // [esp+0h] [ebp-15ECh]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v183; // [esp+4h] [ebp-15E8h] BYREF
  vostok::math::float3 v184; // [esp+8h] [ebp-15E4h] BYREF
  vostok::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024> __first; // [esp+1Ch] [ebp-15D0h] BYREF
  vostok::math::frustum v186; // [esp+102Ch] [ebp-5C0h] BYREF
  vostok::math::float4x4 v187; // [esp+10A4h] [ebp-548h] BYREF
  vostok::math::float4x4 v188; // [esp+10E4h] [ebp-508h] BYREF
  vostok::math::float4x4 v189; // [esp+1124h] [ebp-4C8h] BYREF
  vostok::math::float4x4 v190; // [esp+1164h] [ebp-488h] BYREF
  vostok::math::float4x4 v191; // [esp+11A4h] [ebp-448h] BYREF
  vostok::math::float4x4 v192; // [esp+11E4h] [ebp-408h] BYREF
  vostok::math::float4x4 v193; // [esp+1224h] [ebp-3C8h] BYREF
  vostok::math::float3 v194; // [esp+1264h] [ebp-388h] BYREF
  vostok::math::float3 v195; // [esp+1270h] [ebp-37Ch] BYREF
  float v196[3]; // [esp+127Ch] [ebp-370h] BYREF
  D3D11_VIEWPORT v197; // [esp+1288h] [ebp-364h] BYREF
  float v198[3]; // [esp+12A0h] [ebp-34Ch] BYREF
  vostok::math::float3 v199; // [esp+12ACh] [ebp-340h] BYREF
  vostok::math::float3 v200; // [esp+12B8h] [ebp-334h] BYREF
  vostok::math::float4x4 v201; // [esp+12C4h] [ebp-328h] BYREF
  D3D11_VIEWPORT v202; // [esp+1308h] [ebp-2E4h] BYREF
  float v203[6]; // [esp+1320h] [ebp-2CCh] BYREF
  vostok::math::float3 v204; // [esp+1338h] [ebp-2B4h] BYREF
  float v205; // [esp+1344h] [ebp-2A8h]
  vostok::math::float3 v206; // [esp+1348h] [ebp-2A4h] BYREF
  int v207; // [esp+1354h] [ebp-298h]
  unsigned int v208; // [esp+1358h] [ebp-294h]
  unsigned int v209; // [esp+135Ch] [ebp-290h]
  vostok::render::untyped_buffer *v210; // [esp+1360h] [ebp-28Ch]
  ID3D11ShaderResourceView *v211; // [esp+1364h] [ebp-288h]
  vostok::math::float3 v212; // [esp+1368h] [ebp-284h] BYREF
  int v213; // [esp+1374h] [ebp-278h]
  unsigned int v214[4]; // [esp+1378h] [ebp-274h] BYREF
  vostok::math::float3 v215; // [esp+1388h] [ebp-264h] BYREF
  int v216; // [esp+1394h] [ebp-258h]
  ID3D11ShaderResourceView *m_buffer_shader_resource_view; // [esp+1398h] [ebp-254h]
  unsigned int v218; // [esp+139Ch] [ebp-250h]
  unsigned int v219; // [esp+13A0h] [ebp-24Ch]
  vostok::render::untyped_buffer *v220; // [esp+13A4h] [ebp-248h]
  vostok::math::float3 v221; // [esp+13A8h] [ebp-244h] BYREF
  int v222; // [esp+13B4h] [ebp-238h]
  vostok::math::float3 v223; // [esp+13B8h] [ebp-234h] BYREF
  int v224; // [esp+13C4h] [ebp-228h]
  vostok::math::float3 v225; // [esp+13C8h] [ebp-224h] BYREF
  int v226; // [esp+13D4h] [ebp-218h]
  unsigned int v227[4]; // [esp+13D8h] [ebp-214h] BYREF
  vostok::math::float3 v228; // [esp+13E8h] [ebp-204h] BYREF
  int v229; // [esp+13F4h] [ebp-1F8h]
  unsigned int v230; // [esp+13F8h] [ebp-1F4h]
  unsigned int v231; // [esp+13FCh] [ebp-1F0h]
  vostok::render::untyped_buffer *v232; // [esp+1400h] [ebp-1ECh]
  ID3D11ShaderResourceView *v233; // [esp+1404h] [ebp-1E8h]
  vostok::math::float3 v234; // [esp+1408h] [ebp-1E4h] BYREF
  vostok::render::res_texture *v235; // [esp+1414h] [ebp-1D8h]
  vostok::render::untyped_buffer *v236; // [esp+1418h] [ebp-1D4h]
  ID3D11ShaderResourceView *v237; // [esp+141Ch] [ebp-1D0h]
  unsigned int v238; // [esp+1420h] [ebp-1CCh]
  ID3D11ShaderResourceView *v239; // [esp+1424h] [ebp-1C8h]
  unsigned int v240[4]; // [esp+1428h] [ebp-1C4h] BYREF
  unsigned int m_size; // [esp+1438h] [ebp-1B4h]
  unsigned int m_reference_count; // [esp+143Ch] [ebp-1B0h]
  vostok::render::untyped_buffer *v243; // [esp+1440h] [ebp-1ACh]
  unsigned int v244; // [esp+1444h] [ebp-1A8h]
  unsigned int v245[4]; // [esp+1448h] [ebp-1A4h] BYREF
  unsigned int v246[4]; // [esp+1458h] [ebp-194h] BYREF
  vostok::math::float3 v247; // [esp+1468h] [ebp-184h] BYREF
  vostok::render::res_texture *v248; // [esp+1474h] [ebp-178h]
  unsigned int v249[4]; // [esp+1478h] [ebp-174h] BYREF
  float v250; // [esp+1488h] [ebp-164h]
  __int64 v251; // [esp+148Ch] [ebp-160h]
  __int64 v252; // [esp+1494h] [ebp-158h]
  float v253; // [esp+149Ch] [ebp-150h]
  unsigned int v254[3]; // [esp+14A0h] [ebp-14Ch] BYREF
  vostok::math::float3 v255; // [esp+14ACh] [ebp-140h] BYREF
  vostok::math::float3 position; // [esp+14B8h] [ebp-134h] BYREF
  __int64 v257; // [esp+14C4h] [ebp-128h]
  float v258; // [esp+14CCh] [ebp-120h]
  vostok::math::float3 v259; // [esp+14D0h] [ebp-11Ch] BYREF
  vostok::math::float3 v260; // [esp+14DCh] [ebp-110h] BYREF
  float v261; // [esp+14E8h] [ebp-104h]
  float v262; // [esp+14ECh] [ebp-100h]
  float v263; // [esp+14F0h] [ebp-FCh]
  float v264; // [esp+14F4h] [ebp-F8h]
  __int64 v265; // [esp+14F8h] [ebp-F4h]
  vostok::math::float3 v266; // [esp+1500h] [ebp-ECh] BYREF
  vostok::math::float3 v267; // [esp+150Ch] [ebp-E0h] BYREF
  _OWORD v268[5]; // [esp+1518h] [ebp-D4h] BYREF
  float v269; // [esp+1568h] [ebp-84h] BYREF
  vostok::render::res_texture *v270; // [esp+156Ch] [ebp-80h]
  unsigned int *v271; // [esp+1570h] [ebp-7Ch]
  unsigned int v272; // [esp+1574h] [ebp-78h] BYREF
  unsigned int v273; // [esp+1578h] [ebp-74h]
  vostok::math::float3 v274; // [esp+157Ch] [ebp-70h] BYREF
  char *name; // [esp+1588h] [ebp-64h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v276; // [esp+158Ch] [ebp-60h] BYREF
  vostok::render::res_texture *v277; // [esp+1590h] [ebp-5Ch]
  unsigned int arg; // [esp+1594h] [ebp-58h] BYREF
  unsigned int v279; // [esp+1598h] [ebp-54h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v280; // [esp+159Ch] [ebp-50h] BYREF
  int *v281; // [esp+15A0h] [ebp-4Ch]
  int v282; // [esp+15A4h] [ebp-48h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> result; // [esp+15A8h] [ebp-44h] BYREF
  float v284; // [esp+15ACh] [ebp-40h]
  float v285; // [esp+15B0h] [ebp-3Ch]
  float v286; // [esp+15B4h] [ebp-38h]
  vostok::render::ambient_light **m_width; // [esp+15B8h] [ebp-34h]
  unsigned int num_max_lights_per_particle; // [esp+15BCh] [ebp-30h]
  float v289; // [esp+15C0h] [ebp-2Ch]
  int v290; // [esp+15C4h] [ebp-28h]
  float v291; // [esp+15C8h] [ebp-24h]
  vostok::render::ambient_light **end; // [esp+15CCh] [ebp-20h] BYREF
  vostok::math::float3 *v293; // [esp+15D0h] [ebp-1Ch]
  unsigned int *v294; // [esp+15D4h] [ebp-18h]
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v295; // [esp+15D8h] [ebp-14h]
  unsigned int v296; // [esp+15DCh] [ebp-10h] BYREF
  const vostok::math::float3 **v297; // [esp+15E0h] [ebp-Ch]
  unsigned int v298; // [esp+15E4h] [ebp-8h]
  unsigned int translation; // [esp+15E8h] [ebp-4h] BYREF

  m_object = lq.m_object;
  if ( *(int *)((char *)&dword_8B9664 + lq.m_object->m_name.m_pointer.m_object[1016].m_length) )
  {
    num_max_lights_per_particle = vostok::render::options::get_num_max_lights_per_particle(
                                    (vostok::render::options *)this,
                                    (int)vostok::quasi_singleton<vostok::render::options>::pinst);
    m_checksum = m_object->m_name.m_pointer.m_object[1016].m_checksum;
    v290 = m_checksum + 280;
    vostok::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024>::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024>(
      &__first,
      (const vostok::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024> *)(m_checksum + 56568));
    LOBYTE(lq.m_object) = 0;
    end = (vostok::render::ambient_light **)__first.m_end;
    lq.m_object = (vostok::render::render_target *)stlp_std::remove_if<vostok::particle::render_particle_emitter_instance * *,remove_unlit_particles_predicate>(
                                                     __first.m_begin,
                                                     __first.m_end,
                                                     0);
    vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::erase(
      (vostok::buffer_vector<vostok::render::ambient_light *> *)&__first,
      (vostok::render::ambient_light ***)&lq,
      &end);
    if ( (((char *)__first.m_end - (char *)__first.m_begin) & 0xFFFFFFFC) != 0 )
    {
      m_length = m_object->m_name.m_pointer.m_object[1016].m_length;
      x = *(float *)&aAvbtcollisionw[m_length + 4];
      v271 = *(unsigned int **)((char *)&dword_8B9660 + m_length);
      LOBYTE(lq.m_object) = 0;
      v7 = *(vostok::render::environment_probe ***)(m_length + 9135448);
      v279 = m_length;
      end = (vostok::render::ambient_light **)LODWORD(x);
      if ( (vostok::render::environment_probe **)LODWORD(x) != v7 )
      {
        v8 = ((int)v7 - LODWORD(x)) >> 2;
        v9 = 0;
        while ( v8 != 1 )
        {
          ++v9;
          v8 >>= 1;
        }
        _____introsort_loop_PAPAUenvironment_probe_render_vostok__PAU123_HUsort_probes_by_size_predicate__5__accumulate_particle_lighting_stage_lights_23_AAEX_N_Z__priv_stlp_std__YAXPAPAUenvironment_probe_render_vostok__00HUsort_probes_by_size_predicate__5__accumulate_particle_lighting_stage_lights_34_AAEX_N_Z__Z(
          (const vostok::render::environment_probe *)m_length,
          (vostok::render::environment_probe **)LODWORD(x),
          v7,
          0,
          2 * v9,
          (vostok::render::environment_probe **)lq.m_object);
        _____final_insertion_sort_PAPAUenvironment_probe_render_vostok__Usort_probes_by_size_predicate__5__accumulate_particle_lighting_stage_lights_23_AAEX_N_Z__priv_stlp_std__YAXPAPAUenvironment_probe_render_vostok__0Usort_probes_by_size_predicate__5__accumulate_particle_lighting_stage_lights_34_AAEX_N_Z__Z(
          (vostok::render::environment_probe **)end,
          v7,
          (vostok::render::environment_probe *)lq.m_object);
        x = v184.x;
      }
      v281 = *(int **)(m_length + 9135448);
      if ( s_light0 )
      {
        v184.x = x;
        vostok::render::renderer_context::get_t(
          (vostok::render::renderer_context *)m_object->m_name.m_pointer.m_object,
          rt_position,
          (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v184);
        v183.m_object = v10;
        v182 = (vostok::render::renderer *)v10;
        vostok::render::renderer_context::get_rt(
          (vostok::render::renderer_context *)m_object->m_name.m_pointer.m_object,
          rt_particle_lighting_depth,
          &v183);
        vostok::render::renderer::downsample(v182, m_object->m_memory_usage_type, v183.m_object, LODWORD(v184.x));
      }
      rt = vostok::render::renderer_context::get_rt(
             (vostok::render::renderer_context *)m_object->m_name.m_pointer.m_object,
             rt_particle_lighting,
             &lq);
      z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      vostok::render::backend::set_render_targets(
        (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        rt->m_object,
        0,
        0,
        0);
      v13 = lq.m_object;
      if ( lq.m_object )
      {
        --lq.m_object->m_reference_count;
        if ( !v13->m_reference_count )
        {
          vostok::render::resource_manager::release(
            lq.m_object,
            vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
          z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        }
      }
      *(_BYTE *)(LODWORD(z) + 117) |= *(_DWORD *)(LODWORD(z) + 7384) != 0;
      *(_DWORD *)(LODWORD(z) + 7384) = 0;
      LODWORD(v184.x) = &lq;
      qmemcpy((void *)&v197, (const void *)(LODWORD(z) + 120), sizeof(v197));
      v14 = (vostok::render::renderer_context *)m_object->m_name.m_pointer.m_object;
      v202.TopLeftX = 0.0;
      v202.TopLeftY = 0.0;
      m_width = (vostok::render::ambient_light **)vostok::render::renderer_context::get_rt(
                                                    v14,
                                                    rt_particle_lighting,
                                                    &lq)->m_object->m_width;
      v15 = lq.m_object;
      v202.Width = (float)(unsigned int)m_width;
      if ( lq.m_object )
      {
        --lq.m_object->m_reference_count;
        if ( !v15->m_reference_count )
          vostok::render::resource_manager::release(
            lq.m_object,
            vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      }
      m_width = (vostok::render::ambient_light **)vostok::render::renderer_context::get_rt(
                                                    (vostok::render::renderer_context *)m_object->m_name.m_pointer.m_object,
                                                    rt_particle_lighting,
                                                    &lq)->m_object->m_height;
      v17 = lq.m_object;
      v202.Height = (float)(unsigned int)m_width;
      if ( lq.m_object )
      {
        --lq.m_object->m_reference_count;
        if ( !v17->m_reference_count )
          vostok::render::resource_manager::release(
            lq.m_object,
            vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      }
      v202.MinDepth = 0.0;
      v202.MaxDepth = s_bm_current_air_resistance;
      vostok::render::backend::set_viewports(
        v16,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        &v202,
        (const D3D11_VIEWPORT *)LODWORD(v184.y));
      m_end = (unsigned int)__first.m_end;
      m_begin = (vostok::render::ambient_light **)__first.m_begin;
      m_width = (vostok::render::ambient_light **)__first.m_end;
      for ( i = __first.m_begin == __first.m_end; ; i = end + 1 == m_width )
      {
        end = m_begin;
        if ( i )
        {
LABEL_110:
          vostok::render::backend::set_viewports(
            (vostok::render::backend *)m_end,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            &v197,
            (const D3D11_VIEWPORT *)LODWORD(v184.y));
          v178 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
          v179 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7440);
          i = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) == v179;
          *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) = v179;
          *(_BYTE *)(LODWORD(v178) + 117) |= !i;
          return;
        }
        HIDWORD(v21) = *m_begin;
        v22 = m_object->m_name.m_pointer.m_object;
        lq.m_object = (vostok::render::render_target *)HIDWORD(v21);
        vostok::render::render_particle_emitter_instance::sort_particles(
          (vostok::render::render_particle_emitter_instance *)&v22[1320].m_checksum,
          (const vostok::math::float3 *)HIDWORD(v21),
          0);
        v273 = **(_DWORD **)(HIDWORD(v21) + 340);
        if ( v273 )
        {
          v23 = *(int **)&aAvbtcollisionw[v279 + 4];
          translation = (unsigned int)v23;
          if ( v23 == v281 )
            goto LABEL_27;
          v24 = (float)(*(float *)(HIDWORD(v21) + 160) + *(float *)(HIDWORD(v21) + 172)) * 0.5;
          *(float *)&v25 = (float)(*(float *)(HIDWORD(v21) + 176) + *(float *)(HIDWORD(v21) + 164)) * 0.5;
          *(float *)&v26 = (float)(*(float *)(HIDWORD(v21) + 180) + *(float *)(HIDWORD(v21) + 168)) * 0.5;
          position.x = v24;
          *(_QWORD *)&position.elements[1] = __PAIR64__(v26, v25);
          while ( 1 )
          {
            HIDWORD(v21) = *v23;
            vostok::render::environment_probe::calc_attenuation(
              (vostok::render::environment_probe *)m_end,
              *v23,
              &position);
            if ( s_bm_current_air_resistance > v24 )
              break;
            if ( ++v23 == v281 )
              goto LABEL_27;
          }
          v295 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)HIDWORD(v21);
          if ( !HIDWORD(v21) )
          {
LABEL_27:
            m_end = *(_DWORD *)(v279 + 9135448) - translation;
            if ( (m_end & 0xFFFFFFFC) == 0 )
              goto LABEL_110;
            v295 = *(const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(*(_DWORD *)(v279 + 9135448) - 4);
          }
          v27 = alloca(80 * num_max_lights_per_particle);
          v296 = 0;
          i = *(_BYTE *)(v290 + 56) == 0;
          v293 = (vostok::math::float3 *)&v184.elements[1];
          if ( !i )
          {
            LODWORD(v21) = m_object->m_name.m_pointer.m_object;
            sun_direction = vostok::render::environment_properties::get_sun_direction(
                              (vostok::render::environment_properties *)m_end,
                              v290,
                              v198);
            y = sun_direction->y;
            v30 = sun_direction->z;
            v31 = sun_direction->x;
            v32 = *(float *)(LODWORD(v21) + 19528);
            v250 = (float)((float)(*(float *)(LODWORD(v21) + 19524) * y)
                         + (float)(*(float *)(LODWORD(v21) + 19540) * v30))
                 + (float)(*(float *)(LODWORD(v21) + 19508) * sun_direction->x);
            *(float *)&v251 = (float)((float)(*(float *)(LODWORD(v21) + 19512) * v31) + (float)(v32 * y))
                            + (float)(*(float *)(LODWORD(v21) + 19544) * v30);
            *((float *)&v251 + 1) = (float)((float)(*(float *)(LODWORD(v21) + 19516) * v31)
                                          + (float)(*(float *)(LODWORD(v21) + 19532) * y))
                                  + (float)(*(float *)(LODWORD(v21) + 19548) * v30);
            v34 = vostok::render::environment_properties::get_sun_direction(v33, v290, v196);
            v35 = v34->x * -1000.0;
            v36 = v34->y * -1000.0;
            v37 = v34->z * -1000.0;
            v38 = *(float *)(LODWORD(v21) + 19544);
            *(float *)&v252 = (float)((float)((float)(*(float *)(LODWORD(v21) + 19540) * v37)
                                            + (float)(*(float *)(LODWORD(v21) + 19524) * v36))
                                    + (float)(v35 * *(float *)(LODWORD(v21) + 19508)))
                            + *(float *)(LODWORD(v21) + 19556);
            *((float *)&v252 + 1) = (float)((float)((float)(*(float *)(LODWORD(v21) + 19512) * v35) + (float)(v38 * v37))
                                          + (float)(*(float *)(LODWORD(v21) + 19528) * v36))
                                  + *(float *)(LODWORD(v21) + 19560);
            v253 = (float)((float)((float)(*(float *)(LODWORD(v21) + 19516) * v35)
                                 + (float)(*(float *)(LODWORD(v21) + 19548) * v37))
                         + (float)(*(float *)(LODWORD(v21) + 19532) * v36))
                 + *(float *)(LODWORD(v21) + 19564);
            *(_QWORD *)&v268[0] = v252;
            *((_QWORD *)&v268[0] + 1) = __PAIR64__(LODWORD(v250), LODWORD(v253));
            *(_QWORD *)&v268[1] = v251;
            v39 = *(_DWORD *)(v290 + 68);
            *(vostok::math::float3 *)((char *)&v268[1] + 8) = *(vostok::math::float3 *)(v290 + 72);
            *(_QWORD *)((char *)&v268[2] + 4) = __PAIR64__(LODWORD(s_bm_current_air_resistance), LODWORD(FLOAT_1000_0));
            HIDWORD(v268[3]) = v39;
            HIDWORD(v268[2]) = 0;
            memset(&v268[3], 0, 12);
            LODWORD(v268[4]) = 0;
            *(_QWORD *)((char *)&v268[4] + 4) = __PAIR64__(LODWORD(s_bm_current_air_resistance), LODWORD(FLOAT_4_0));
            *((float *)&v268[4] + 3) = s_bm_current_air_resistance;
            qmemcpy(v293, v268, 0x50u);
            HIDWORD(v21) = &v269;
            v296 = 1;
          }
          v40 = *v271;
          translation = v271[1];
          v298 = v40;
          if ( v296 < num_max_lights_per_particle && v40 != translation )
          {
            v294 = (unsigned int *)((char *)v293 + 80 * v296);
            while ( 1 )
            {
              v41 = *(_DWORD *)(*(_DWORD *)v298 + 860) & 0xF;
              v297 = *(const vostok::math::float3 ***)v298;
              if ( v41 != 4
                && (v41
                 || *(float *)&lq.m_object[2].m_texture.m_object >= *((float *)v297 + 218)
                 && *(float *)&lq.m_object[2].m_width >= *((float *)v297 + 219)
                 && *(float *)&lq.m_object[2].m_height >= *((float *)v297 + 220)
                 && *((float *)v297 + 221) >= *(float *)&lq.m_object[2].m_surface_3d
                 && *((float *)v297 + 222) >= *(float *)&lq.m_object[2].m_rt
                 && *((float *)v297 + 223) >= *(float *)&lq.m_object[2].m_zrt) )
              {
                v42 = s_bm_current_air_resistance;
                v289 = 0.0;
                v282 = 0;
                v43 = 0.0;
                if ( v41 != 1 )
                  goto LABEL_49;
                LODWORD(v21) = v297;
                v44 = *((float *)v297 + 136);
                if ( v44 <= *((float *)v297 + 143) )
                  v44 = *((float *)v297 + 143);
                v269 = *((float *)v297 + 152);
                vostok::math::create_perspective_projection(
                  v21,
                  v44,
                  (vostok::math *)&v191,
                  COERCE_STRUCT_VOSTOK_MATH_FLOAT4X4_(1.0),
                  v269 * 0.001,
                  v269);
                v45 = *(float *)(LODWORD(v21) + 552);
                v46 = *(float *)(LODWORD(v21) + 556);
                v47 = (float)(*(float *)(LODWORD(v21) + 584) * v45) - (float)(*(float *)(LODWORD(v21) + 580) * v46);
                v48 = *(float *)(LODWORD(v21) + 576);
                v49 = v48 * v45;
                v50 = v48 * v46;
                v51 = *(float *)(LODWORD(v21) + 548);
                v52 = (float)(v51 * *(float *)(LODWORD(v21) + 580)) - v49;
                v53 = v50 - (float)(v51 * *(float *)(LODWORD(v21) + 584));
                v54 = s_bm_current_air_resistance
                    / fsqrt((float)((float)(v52 * v52) + (float)(v53 * v53)) + (float)(v47 * v47));
                v260.y = v53 * v54;
                v255.x = *(float *)(LODWORD(v21) + 532) + *(float *)(LODWORD(v21) + 548);
                v255.y = *(float *)(LODWORD(v21) + 552) + *(float *)(LODWORD(v21) + 536);
                v55 = *(float *)(LODWORD(v21) + 556) + *(float *)(LODWORD(v21) + 540);
                v260.x = v54 * v47;
                v260.z = v52 * v54;
                v255.z = v55;
                vostok::math::create_camera_at((const vostok::math::float3 *)(LODWORD(v21) + 532), &v255, &v201, &v260);
                v56 = vostok::math::mul4x4(&v191, &v201, (vostok::math::float4x4 *)&v268[1]);
                HIDWORD(v21) = &v186;
                vostok::math::frustum::frustum(&v186, v56);
                if ( vostok::math::cuboid::test_inexact(
                       v57,
                       (int)&v186,
                       (vostok::math::aabb_plane *)&lq.m_object[2].m_surface_3d) != 2 )
                  break;
              }
LABEL_50:
              v298 += 8;
              if ( v298 == translation )
                goto LABEL_51;
            }
            v58 = (float)(*(float *)(LODWORD(v21) + 572) * 0.5);
            __libm_sse2_cos(*(long double *)&v184.elements[1]);
            *(float *)&v58 = v58;
            v289 = *(float *)&v58;
            v59 = (float)(*(float *)(LODWORD(v21) + 544) * 0.5);
            __libm_sse2_cos(*(long double *)&v184.elements[1]);
            *(float *)&v59 = v59;
            v282 = LODWORD(v59);
            v60 = *(float *)&v59 - v289;
            if ( v60 <= 0.000099999997 )
              v60 = FLOAT_0_000099999997;
            v42 = *(float *)(LODWORD(v21) + 588);
            v43 = s_bm_current_air_resistance / v60;
LABEL_49:
            p_m_reference_count = (float *)&m_object->m_name.m_pointer.m_object->m_reference_count;
            v62 = v297;
            v63 = *((float *)v297 + 139);
            v64 = *((float *)v297 + 138);
            v65 = *((float *)v297 + 137);
            v66 = p_m_reference_count[4882];
            v264 = (float)((float)(p_m_reference_count[4881] * v64) + (float)(p_m_reference_count[4885] * v63))
                 + (float)(p_m_reference_count[4877] * v65);
            v67 = (float)((float)(p_m_reference_count[4878] * v65) + (float)(v66 * v64))
                + (float)(p_m_reference_count[4886] * v63);
            v68 = p_m_reference_count[4885];
            *(float *)&v265 = v67;
            *((float *)&v265 + 1) = (float)((float)(p_m_reference_count[4879] * v65)
                                          + (float)(p_m_reference_count[4883] * v64))
                                  + (float)(p_m_reference_count[4887] * v63);
            v69 = *((float *)v297 + 134);
            v70 = *((float *)v297 + 135);
            v71 = *((float *)v297 + 133);
            v72 = (float)((float)((float)(p_m_reference_count[4881] * v69) + (float)(v68 * v70))
                        + (float)(v71 * p_m_reference_count[4877]))
                + p_m_reference_count[4889];
            v73 = p_m_reference_count[4882];
            *(float *)&v257 = v72;
            *((float *)&v257 + 1) = (float)((float)((float)(p_m_reference_count[4878] * v71) + (float)(v73 * v69))
                                          + (float)(p_m_reference_count[4886] * v70))
                                  + p_m_reference_count[4890];
            v258 = (float)((float)((float)(p_m_reference_count[4879] * v71) + (float)(p_m_reference_count[4883] * v69))
                         + (float)(p_m_reference_count[4887] * v70))
                 + p_m_reference_count[4891];
            *(_QWORD *)&v268[0] = v257;
            *((_QWORD *)&v268[0] + 1) = __PAIR64__(LODWORD(v264), LODWORD(v258));
            *(_QWORD *)&v268[1] = v265;
            *((_QWORD *)&v268[1] + 1) = *(_QWORD *)(v297 + 129);
            v74 = v297[152];
            v75 = v297[215];
            LODWORD(v268[2]) = v297[131];
            DWORD1(v268[2]) = v74;
            DWORD2(v268[2]) = v297[151];
            *((float *)&v268[2] + 3) = v289;
            *(_QWORD *)((char *)&v268[3] + 4) = __PAIR64__(LODWORD(v42), LODWORD(v43));
            v76 = v297[132];
            v297 = (const vostok::math::float3 **)((unsigned __int8)v75 & 0xF);
            LODWORD(v268[3]) = v282;
            HIDWORD(v268[3]) = v76;
            LODWORD(v268[4]) = 0;
            v77 = v62[207];
            *((float *)&v268[4] + 1) = (float)(int)v297;
            ++v296;
            v21 = COERCE_DOUBLE(__PAIR64__(&v269, (unsigned int)v294));
            v78 = v296;
            v294 += 20;
            DWORD2(v268[4]) = v77;
            HIDWORD(v268[4]) = v62[208];
            qmemcpy((void *)LODWORD(v21), v268, 0x50u);
            if ( v78 >= num_max_lights_per_particle )
              goto LABEL_51;
            goto LABEL_50;
          }
LABEL_51:
          if ( s_light1 )
          {
            v79 = (unsigned int *)vostok::render::shader_buffer::lock_write_discard((vostok::render::shader_buffer *)m_object->m_rt);
            if ( v296 )
            {
              v81 = (vostok::render::untyped_buffer **)(v79 + 8);
              v80 = (vostok::render::shader_buffer *)&v293[1].elements[2];
              translation = v296;
              do
              {
                m_size = v80[-2].m_size;
                m_reference_count = v80[-1].m_reference_count;
                v243 = v80[-1].m_buffer.m_object;
                v244 = v80[1].m_reference_count;
                *v79 = m_size;
                v79[1] = m_reference_count;
                v79[2] = (unsigned int)v243;
                v79[3] = v244;
                m_buffer_shader_resource_view = v80[-1].m_buffer_shader_resource_view;
                v218 = v80[-1].m_size;
                v219 = v80->m_reference_count;
                v220 = v80[1].m_buffer.m_object;
                *(v81 - 4) = (vostok::render::untyped_buffer *)m_buffer_shader_resource_view;
                *(v81 - 3) = (vostok::render::untyped_buffer *)v218;
                *(v81 - 2) = (vostok::render::untyped_buffer *)v219;
                *(v81 - 1) = v220;
                v236 = v80->m_buffer.m_object;
                v237 = v80->m_buffer_shader_resource_view;
                v238 = v80->m_size;
                v239 = v80[1].m_buffer_shader_resource_view;
                *v81 = v236;
                v81[1] = (vostok::render::untyped_buffer *)v237;
                v81[2] = (vostok::render::untyped_buffer *)v238;
                v81[3] = (vostok::render::untyped_buffer *)v239;
                v208 = v80[1].m_size;
                v209 = v80[2].m_reference_count;
                v210 = v80[2].m_buffer.m_object;
                v211 = v80[2].m_buffer_shader_resource_view;
                v81[4] = (vostok::render::untyped_buffer *)v208;
                v81[5] = (vostok::render::untyped_buffer *)v209;
                v81[6] = v210;
                v81[7] = (vostok::render::untyped_buffer *)v211;
                v230 = v80[2].m_size;
                v231 = v80[3].m_reference_count;
                v232 = v80[3].m_buffer.m_object;
                v233 = v80[3].m_buffer_shader_resource_view;
                v81[8] = (vostok::render::untyped_buffer *)v230;
                v81[9] = (vostok::render::untyped_buffer *)v231;
                v81[10] = v232;
                v82 = (ID3D11ShaderResourceView **)(v81 + 11);
                v79 += 20;
                v81 += 20;
                v80 += 5;
                i = translation-- == 1;
                *v82 = v233;
              }
              while ( !i );
            }
            vostok::render::shader_buffer::unlock_write_discard(v80, (int)m_object->m_rt);
          }
          v83 = s_bm_current_air_resistance;
          v84 = *(vostok::render::render_particle_emitter_instance **)(m_object->m_name.m_pointer.m_object[1016].m_checksum
                                                                     + 64784);
          v85 = *(_DWORD *)(m_object->m_name.m_pointer.m_object[1016].m_checksum + 64788);
          v291 = s_bm_current_air_resistance;
          v284 = 0.0;
          v285 = 0.0;
          v286 = 0.0;
          v297 = (const vostok::math::float3 **)v84;
          translation = v85;
          if ( v84 != (vostok::render::render_particle_emitter_instance *)v85 )
          {
            v270 = lq.m_object[2].m_texture.m_object;
            do
            {
              qmemcpy(v203, &(*v297)[9].elements[2], sizeof(v203));
              v84 = 0;
              if ( *(float *)&v270 >= v203[0]
                && *(float *)&lq.m_object[2].m_width >= v203[1]
                && *(float *)&lq.m_object[2].m_height >= v203[2]
                && v203[3] >= *(float *)&lq.m_object[2].m_surface_3d
                && v203[4] >= *(float *)&lq.m_object[2].m_rt )
              {
                v86 = v203[5];
                if ( v203[5] >= *(float *)&lq.m_object[2].m_zrt )
                {
                  vostok::render::ambient_light::calc_attenuation(0, *v297, (float *)&lq.m_object[3].m_surface_3d);
                  if ( v291 > v86 )
                  {
                    v87 = *v297;
                    v88 = (*v297)[6].z;
                    v291 = v86;
                    v89 = v87[7].z;
                    v261 = v88 * v89;
                    v262 = v87[7].x * v89;
                    v263 = v87[7].y * v89;
                    v284 = v88 * v89;
                    v285 = v262;
                    v286 = v263;
                  }
                }
              }
              ++v297;
            }
            while ( v297 != (const vostok::math::float3 **)translation );
            v83 = s_bm_current_air_resistance;
          }
          v267.x = (float)((float)(v83 - v284) * v291) + v284;
          v267.y = (float)((float)(v83 - v285) * v291) + v285;
          v267.z = (float)((float)(v83 - v286) * v291) + v286;
          material_effects = vostok::render::render_particle_emitter_instance::get_material_effects(
                               v84,
                               (int)lq.m_object);
          vostok::render::res_effect::apply(
            (vostok::render::res_effect *)v296,
            (int)material_effects->m_effects[17].m_object);
          v298 = 0;
          v91 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
          p_m_order = (const vostok::render::shader_constant_host **)&m_object[31].m_order;
          if ( a3 )
          {
            do
            {
              view2shadow = vostok::render::renderer_context::get_view2shadow(
                              (vostok::render::renderer_context *)m_object->m_name.m_pointer.m_object,
                              v298);
              v94 = vostok::math::transpose(view2shadow, (vostok::math::float4x4 *)&v268[1]);
              vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
                (vostok::render::backend *)LODWORD(v91),
                *p_m_order,
                (const unsigned int *)v94);
              ++v298;
              ++p_m_order;
            }
            while ( v298 < 4 );
            LODWORD(v184.x) = &arg;
            v95 = (const vostok::render::shader_constant_host *)*(&m_object[33].m_memory_usage + 1);
            arg = 0;
            vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
              (vostok::render::backend *)LODWORD(v91),
              v95,
              &arg);
            if ( s_light2 )
            {
              vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
                (vostok::render::backend *)LODWORD(v91),
                (const vostok::render::shader_constant_host *)m_object[33].m_order,
                &v296);
              *(_BYTE *)(LODWORD(v91) + 101) = vostok::render::buffers_handler<0>::set_overwrite(
                                                 v97,
                                                 LODWORD(v91) + 1376,
                                                 (vostok::render::shader_buffer *)m_object->m_rt,
                                                 (vostok::render::shader_buffer *)LODWORD(v184.y));
            }
            if ( v295 )
            {
              vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
                (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&name,
                v295 + 149);
              v98 = (vostok::render::res_texture *)name;
              v99 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
              *(_BYTE *)(LODWORD(v99) + 99) = vostok::render::textures_handler<0>::set_overwrite(
                                                v100,
                                                LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                              + 492,
                                                (vostok::render::res_texture *)name,
                                                (vostok::render::res_texture *)LODWORD(v184.y));
              if ( v98 )
              {
                i = v98->m_reference_count-- == 1;
                if ( i )
                  vostok::render::resource_manager::release(
                    v101,
                    (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                    v98);
              }
              v102 = v295;
              v103 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
              translation = m_object->m_name.m_pointer.m_object[1016].m_checksum + 280;
              v214[0] = (unsigned int)v295[127].m_object;
              v214[1] = (unsigned int)v295[128].m_object;
              v104 = (unsigned int)v295[129].m_object;
              v293 = (vostok::math::float3 *)&v295[127];
              v214[2] = v104;
              v105 = (unsigned int)v295[130].m_object;
              LODWORD(v184.x) = v214;
              m_rt = (const vostok::render::shader_constant_host *)m_object[31].m_rt;
              v214[3] = v105;
              vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
                (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                m_rt,
                v214);
              v107 = (double)(int)v102[145].m_object;
              *(float *)v227 = *(float *)(translation + 364) * *(float *)&v102[132].m_object;
              v108 = (int)v102[145].m_object;
              *(float *)&v227[1] = *(float *)(translation + 368) * *(float *)&v102[133].m_object;
              if ( v108 < 0 )
                v107 = v107 + 4294967300.0;
              *(float *)&v227[2] = v107;
              LODWORD(v184.x) = v227;
              m_zrt = (const vostok::render::shader_constant_host *)m_object[31].m_zrt;
              v227[3] = 0;
              vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
                (vostok::render::backend *)LODWORD(v103),
                m_zrt,
                v227);
              v110 = *(float *)&v102[130].m_object;
              i = v102[137].m_object == 0;
              LODWORD(v274.elements[2]) = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v102[131].m_object;
              v294 = (unsigned int *)&v102[137];
              if ( i )
              {
                v259.x = v110;
                v259.y = v110;
                v259.z = v110;
                translation = (unsigned int)vostok::math::create_translation(v293, (vostok::math::float4x4 *)&v268[1]);
                v111 = vostok::math::create_scale(&v259, &v191);
                vostok::math::mul4x3((const vostok::math::float4x4 *)translation, v111, &v201);
                v112 = &v201;
              }
              else
              {
                v112 = (vostok::math::float4x4 *)&v102[71];
              }
              qmemcpy(&v190, v112, sizeof(v190));
              qmemcpy(&v189, &v295[87], sizeof(v189));
              qmemcpy(&v192, &v295[71], sizeof(v192));
              vostok::math::float4x4::try_invert(&v192, &v192);
              scale = vostok::math::float4x4::get_scale(&v190, &v200);
              v114 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
              v204 = *scale;
              LODWORD(v184.x) = &v204;
              v115 = (const vostok::render::shader_constant_host *)m_object[31].m_texture.m_object;
              v205 = v274.z;
              vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
                (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                v115,
                (const unsigned int *)&v204);
              v223 = *vostok::math::float4x4::get_scale(&v189, &v199);
              LODWORD(v184.x) = &v223;
              v116 = (const vostok::render::shader_constant_host *)m_object[31].m_width;
              v224 = 0;
              vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
                (vostok::render::backend *)LODWORD(v114),
                v116,
                (const unsigned int *)&v223);
              v117 = vostok::math::transpose(&v192, (vostok::math::float4x4 *)&v268[1]);
              vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
                (vostok::render::backend *)LODWORD(v114),
                (const vostok::render::shader_constant_host *)m_object[31].m_height,
                (const unsigned int *)v117);
              vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
                (vostok::render::backend *)LODWORD(v114),
                (const vostok::render::shader_constant_host *)m_object[31].m_format,
                v294);
            }
            else
            {
              default_texture = (vostok::render::textures_handler<0> **)vostok::render::resource_manager::get_default_texture(
                                                                          v96,
                                                                          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                                                          &result);
              v119 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
              *(_BYTE *)(LODWORD(v119) + 99) = vostok::render::textures_handler<0>::set_overwrite(
                                                 *default_texture,
                                                 LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                               + 492,
                                                 (vostok::render::res_texture *)*default_texture,
                                                 (vostok::render::res_texture *)LODWORD(v184.y));
              if ( result.m_object )
              {
                i = result.m_object->m_reference_count-- == 1;
                if ( i )
                  vostok::render::resource_manager::release(
                    v120,
                    (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                    result.m_object);
              }
              v114 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
              LODWORD(v184.x) = v249;
              v121 = (const vostok::render::shader_constant_host *)m_object[31].m_rt;
              memset(v249, 0, sizeof(v249));
              vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
                (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                v121,
                v249);
              LODWORD(v184.x) = v246;
              v122 = (const vostok::render::shader_constant_host *)m_object[31].m_zrt;
              memset(v246, 0, sizeof(v246));
              vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
                (vostok::render::backend *)LODWORD(v114),
                v122,
                v246);
              LODWORD(v184.x) = v245;
              v123 = (const vostok::render::shader_constant_host *)m_object[31].m_texture.m_object;
              memset(v245, 0, sizeof(v245));
              vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
                (vostok::render::backend *)LODWORD(v114),
                v123,
                v245);
              LODWORD(v184.x) = v240;
              v124 = (const vostok::render::shader_constant_host *)m_object[31].m_width;
              memset(v240, 0, sizeof(v240));
              vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
                (vostok::render::backend *)LODWORD(v114),
                v124,
                v240);
              v126 = vostok::math::float4x4::identity(v125, (vostok::math::float4x4 *)&v268[1]);
              vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
                (vostok::render::backend *)LODWORD(v114),
                (const vostok::render::shader_constant_host *)m_object[31].m_height,
                (const unsigned int *)v126);
              translation = 0;
              vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
                (vostok::render::backend *)LODWORD(v114),
                (const vostok::render::shader_constant_host *)m_object[31].m_format,
                &translation);
            }
            vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
              (vostok::render::backend *)LODWORD(v114),
              (const vostok::render::shader_constant_host *)m_object[31].m_usage,
              (const unsigned int *)&v267);
            LODWORD(v184.x) = &v272;
            m_memory_usage = (const vostok::render::shader_constant_host *)m_object[31].m_memory_usage;
            v272 = LODWORD(retry_to_increase_quality_period_sec);
            vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
              (vostok::render::backend *)LODWORD(v114),
              m_memory_usage,
              &v272);
          }
          else
          {
            do
            {
              v128 = vostok::render::renderer_context::get_view2shadow(
                       (vostok::render::renderer_context *)m_object->m_name.m_pointer.m_object,
                       v298);
              v129 = vostok::math::transpose(v128, (vostok::math::float4x4 *)&v268[1]);
              vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
                (vostok::render::backend *)LODWORD(v91),
                *p_m_order,
                (const unsigned int *)v129);
              ++v298;
              ++p_m_order;
            }
            while ( v298 < 4 );
            v298 = 0;
            v130 = (const vostok::render::shader_constant_host **)&m_object[31].m_order;
            do
            {
              v131 = vostok::render::renderer_context::get_view2shadow(
                       (vostok::render::renderer_context *)m_object->m_name.m_pointer.m_object,
                       v298);
              v132 = vostok::math::transpose(v131, &v201);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v133,
                (vostok::render::constants_handler<1> *)LODWORD(v91),
                *v130,
                (const vostok::math::float3 *)v132);
              ++v298;
              ++v130;
            }
            while ( v298 < 4 );
            LODWORD(v184.x) = &v274;
            v183.m_object = (vostok::render::render_target *)*(&m_object[33].m_memory_usage + 1);
            v274.x = 0.0;
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v134,
              (vostok::render::constants_handler<1> *)LODWORD(v91),
              (const vostok::render::shader_constant_host *)v183.m_object,
              &v274);
            vostok::render::backend::set_ps_constant<unsigned int>(
              (vostok::render::backend *)LODWORD(v91),
              (const vostok::render::shader_constant_host *)m_object[33].m_order,
              (const int *)&v296);
            if ( vostok::render::buffers_handler<0>::set_overwrite(
                   v135,
                   LODWORD(v91) + 4624,
                   (vostok::render::shader_buffer *)m_object->m_rt,
                   (vostok::render::shader_buffer *)LODWORD(v184.y)) )
            {
              *(_BYTE *)(LODWORD(v91) + 111) = 1;
            }
            if ( v295 )
            {
              vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
                &v276,
                v295 + 149);
              v137 = v276.m_object;
              vostok::render::backend::set_ps_texture(
                v138,
                SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                "t_probe_cubemap_diffuse",
                v276.m_object);
              if ( v137 )
              {
                i = v137->m_reference_count-- == 1;
                if ( i )
                  vostok::render::resource_manager::release(
                    v139,
                    (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                    v137);
              }
              v140 = v295;
              v141 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
              translation = m_object->m_name.m_pointer.m_object[1016].m_checksum + 280;
              *(_QWORD *)&v234.x = *(_QWORD *)&v295[127].m_object;
              v142 = *(float *)&v295[129].m_object;
              v293 = (vostok::math::float3 *)&v295[127];
              LODWORD(v184.x) = &v234;
              v183.m_object = (vostok::render::render_target *)m_object[31].m_rt;
              v234.z = v142;
              v235 = v295[130].m_object;
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                (vostok::render::backend *)v139,
                (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                (const vostok::render::shader_constant_host *)v183.m_object,
                &v234);
              v144 = (double)(int)v140[145].m_object;
              v228.x = *(float *)(translation + 364) * *(float *)&v140[132].m_object;
              v145 = (int)v140[145].m_object;
              v228.y = *(float *)(translation + 368) * *(float *)&v140[133].m_object;
              if ( v145 < 0 )
                v144 = v144 + 4294967300.0;
              v228.z = v144;
              LODWORD(v184.x) = &v228;
              v183.m_object = (vostok::render::render_target *)m_object[31].m_zrt;
              v229 = 0;
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v143,
                (vostok::render::constants_handler<1> *)LODWORD(v141),
                (const vostok::render::shader_constant_host *)v183.m_object,
                &v228);
              v146 = *(float *)&v140[130].m_object;
              i = v140[137].m_object == 0;
              v277 = v140[131].m_object;
              v294 = (unsigned int *)&v140[137];
              if ( i )
              {
                v266.x = v146;
                v266.y = v146;
                v266.z = v146;
                translation = (unsigned int)vostok::math::create_translation(v293, (vostok::math::float4x4 *)&v268[1]);
                v147 = vostok::math::create_scale(&v266, &v191);
                vostok::math::mul4x3((const vostok::math::float4x4 *)translation, v147, &v201);
                v148 = &v201;
              }
              else
              {
                v148 = (vostok::math::float4x4 *)&v140[71];
              }
              qmemcpy(&v188, v148, sizeof(v188));
              qmemcpy(&v187, &v295[87], sizeof(v187));
              qmemcpy(&v193, &v295[71], sizeof(v193));
              vostok::math::float4x4::try_invert(&v193, &v193);
              v149 = vostok::math::float4x4::get_scale(&v188, &v195);
              v150 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
              *(_QWORD *)&v247.x = *(_QWORD *)&v149->x;
              v151 = v149->z;
              LODWORD(v184.x) = &v247;
              v183.m_object = (vostok::render::render_target *)m_object[31].m_texture.m_object;
              v247.z = v151;
              v248 = v277;
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v152,
                (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                (const vostok::render::shader_constant_host *)v183.m_object,
                &v247);
              v153 = vostok::math::float4x4::get_scale(&v187, &v194);
              *(_QWORD *)&v225.x = *(_QWORD *)&v153->x;
              v154 = v153->z;
              LODWORD(v184.x) = &v225;
              v183.m_object = (vostok::render::render_target *)m_object[31].m_width;
              v225.z = v154;
              v226 = 0;
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v155,
                (vostok::render::constants_handler<1> *)LODWORD(v150),
                (const vostok::render::shader_constant_host *)v183.m_object,
                &v225);
              v156 = vostok::math::transpose(&v193, (vostok::math::float4x4 *)&v268[1]);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v157,
                (vostok::render::constants_handler<1> *)LODWORD(v150),
                (const vostok::render::shader_constant_host *)m_object[31].m_height,
                (const vostok::math::float3 *)v156);
              vostok::render::backend::set_ps_constant<unsigned int>(
                (vostok::render::backend *)LODWORD(v150),
                (const vostok::render::shader_constant_host *)m_object[31].m_format,
                (const int *)v294);
            }
            else
            {
              v159 = vostok::render::resource_manager::get_default_texture(
                       v136,
                       (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                       &v280);
              vostok::render::backend::set_ps_texture(
                v160,
                SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                "t_probe_cubemap_diffuse",
                v159->m_object);
              if ( v280.m_object )
              {
                i = v280.m_object->m_reference_count-- == 1;
                if ( i )
                  vostok::render::resource_manager::release(
                    v161,
                    (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                    v280.m_object);
              }
              v150 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
              LODWORD(v184.x) = &v221;
              v183.m_object = (vostok::render::render_target *)m_object[31].m_rt;
              memset(&v221, 0, sizeof(v221));
              v222 = 0;
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                (vostok::render::backend *)v161,
                (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                (const vostok::render::shader_constant_host *)v183.m_object,
                &v221);
              LODWORD(v184.x) = &v215;
              v183.m_object = (vostok::render::render_target *)m_object[31].m_zrt;
              memset(&v215, 0, sizeof(v215));
              v216 = 0;
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v162,
                (vostok::render::constants_handler<1> *)LODWORD(v150),
                (const vostok::render::shader_constant_host *)v183.m_object,
                &v215);
              LODWORD(v184.x) = &v212;
              v183.m_object = (vostok::render::render_target *)m_object[31].m_texture.m_object;
              memset(&v212, 0, sizeof(v212));
              v213 = 0;
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v163,
                (vostok::render::constants_handler<1> *)LODWORD(v150),
                (const vostok::render::shader_constant_host *)v183.m_object,
                &v212);
              LODWORD(v184.x) = &v206;
              v183.m_object = (vostok::render::render_target *)m_object[31].m_width;
              memset(&v206, 0, sizeof(v206));
              v207 = 0;
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v164,
                (vostok::render::constants_handler<1> *)LODWORD(v150),
                (const vostok::render::shader_constant_host *)v183.m_object,
                &v206);
              v166 = vostok::math::float4x4::identity(v165, (vostok::math::float4x4 *)&v268[1]);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v167,
                (vostok::render::constants_handler<1> *)LODWORD(v150),
                (const vostok::render::shader_constant_host *)m_object[31].m_height,
                (const vostok::math::float3 *)v166);
              translation = 0;
              vostok::render::backend::set_ps_constant<unsigned int>(
                (vostok::render::backend *)LODWORD(v150),
                (const vostok::render::shader_constant_host *)m_object[31].m_format,
                (const int *)&translation);
            }
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v158,
              (vostok::render::constants_handler<1> *)LODWORD(v150),
              (const vostok::render::shader_constant_host *)m_object[31].m_usage,
              &v267);
            LODWORD(v184.x) = &v274.y;
            v183.m_object = (vostok::render::render_target *)m_object[31].m_memory_usage;
            v274.y = retry_to_increase_quality_period_sec;
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v168,
              (vostok::render::constants_handler<1> *)LODWORD(v150),
              (const vostok::render::shader_constant_host *)v183.m_object,
              (vostok::math::float3 *)&v274.elements[1]);
          }
          LODWORD(v184.x) = lq.m_object[5].m_surface;
          v169 = m_object->m_name.m_pointer.m_object;
          v183.m_object = (vostok::render::render_target *)lq.m_object[5].m_memory_usage_type;
          *(_QWORD *)&v181.elements[1] = *(_QWORD *)&v169[1320].m_checksum;
          LODWORD(v181.x) = v169[1016].next_in_hashset;
          *(_QWORD *)&v180.elements[1] = *(_QWORD *)&v169[1015].m_reference_count;
          x_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.x);
          v180.x = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.x;
          vostok::render::particle_shader_constants::set(
            (vostok::render::particle_shader_constants *)lq.m_object,
            v180,
            *(const vostok::math::float3 *)&v169[1015].m_length,
            v181,
            (vostok::particle::enum_particle_locked_axis)v169[1321].next_in_hashset,
            (vostok::particle::enum_particle_screen_alignment)v183.m_object,
            SLODWORD(v184.x));
          v171 = (float *)m_object->m_name.m_pointer.m_object[1016].m_checksum;
          v172 = v171[87];
          v171 += 70;
          *(float *)v254 = v172 * v171[18];
          *(float *)&v254[1] = v171[19] * v172;
          v173 = v171[20];
          LODWORD(v184.x) = v254;
          m_surface = (const vostok::render::shader_constant_host *)m_object[32].m_surface;
          *(float *)&v254[2] = v173 * v172;
          vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
            (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            m_surface,
            v254);
          v184.x = *(float *)&m_object->m_name.m_pointer.m_object[732].next_in_hashset;
          vostok::render::particle_shader_constants::set_time(v175, *(float *)&x_low, v184);
          v176 = (vostok::math::float3 *)lq.m_object;
          vostok::render::renderer_context::set_w(
            (const vostok::math::float4x4 *)&lq.m_object[2].m_format,
            (vostok::render::renderer_context *)m_object->m_name.m_pointer.m_object);
          vostok::render::render_particle_emitter_instance::render(
            v177,
            (int)m_object,
            x_low,
            (int)v176,
            v176,
            (const unsigned int)m_object->m_name.m_pointer.m_object,
            v273);
        }
        m_begin = end + 1;
      }
    }
  }
}
