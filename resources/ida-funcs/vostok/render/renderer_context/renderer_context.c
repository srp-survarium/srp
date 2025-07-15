void __userpurge vostok::render::renderer_context::renderer_context(
        vostok::render::renderer_context *this@<ecx>,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        char a16)
{
  vostok::render::render_target_instance *v16; // edi
  _DWORD *v17; // ecx
  int v18; // eax
  float v19; // xmm1_4
  float v20; // xmm1_4
  vostok::math::float4x4 *v21; // edi
  vostok::math::float4x4 *v22; // esi
  _DWORD *v23; // eax
  vostok::render::res_texture *v24; // edi
  int v25; // ecx
  vostok::fixed_vector<vostok::render::ray,8>::allign_helper *m_buffer; // eax
  float v27; // xmm1_4
  int v28; // ecx
  vostok::fixed_vector<vostok::render::ray,8>::allign_helper *v29; // eax
  vostok::buffer_vector<vostok::render::sun_cascade> *v30; // ecx
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v31; // eax
  vostok::render::resource_manager *v32; // ecx
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v34; // eax
  vostok::render::resource_manager *v35; // ecx
  vostok::render::res_geometry *v36; // eax
  vostok::render::renderer_context *v37; // ecx
  vostok::render::resource_manager *v38; // esi
  vostok::shared_string *v39; // ecx
  const vostok::render::shader_constant_binding *v40; // eax
  vostok::render::resource_manager *v41; // esi
  vostok::shared_string *v42; // ecx
  const vostok::render::shader_constant_binding *v43; // eax
  vostok::render::resource_manager *v44; // esi
  vostok::shared_string *v45; // ecx
  const vostok::render::shader_constant_binding *v46; // eax
  vostok::render::resource_manager *v47; // esi
  vostok::shared_string *v48; // ecx
  const vostok::render::shader_constant_binding *v49; // eax
  vostok::render::resource_manager *v50; // esi
  vostok::shared_string *v51; // ecx
  const vostok::render::shader_constant_binding *v52; // eax
  vostok::render::resource_manager *v53; // esi
  vostok::shared_string *v54; // ecx
  const vostok::render::shader_constant_binding *v55; // eax
  vostok::render::resource_manager *v56; // esi
  vostok::shared_string *v57; // ecx
  const vostok::render::shader_constant_binding *v58; // eax
  vostok::render::resource_manager *v59; // esi
  vostok::shared_string *v60; // ecx
  const vostok::render::shader_constant_binding *v61; // eax
  vostok::render::resource_manager *v62; // esi
  vostok::shared_string *v63; // ecx
  const vostok::render::shader_constant_binding *v64; // eax
  vostok::render::resource_manager *v65; // esi
  vostok::shared_string *v66; // ecx
  const vostok::render::shader_constant_binding *v67; // eax
  vostok::render::resource_manager *v68; // esi
  vostok::shared_string *v69; // ecx
  const vostok::render::shader_constant_binding *v70; // eax
  vostok::render::resource_manager *v71; // esi
  vostok::shared_string *v72; // ecx
  const vostok::render::shader_constant_binding *v73; // eax
  vostok::render::resource_manager *v74; // esi
  vostok::shared_string *v75; // ecx
  const vostok::render::shader_constant_binding *v76; // eax
  vostok::render::resource_manager *v77; // esi
  vostok::shared_string *v78; // ecx
  const vostok::render::shader_constant_binding *v79; // eax
  vostok::render::resource_manager *v80; // esi
  vostok::shared_string *v81; // ecx
  const vostok::render::shader_constant_binding *v82; // eax
  vostok::render::resource_manager *v83; // esi
  vostok::shared_string *v84; // ecx
  const vostok::render::shader_constant_binding *v85; // eax
  vostok::render::resource_manager *v86; // esi
  vostok::shared_string *v87; // ecx
  const vostok::render::shader_constant_binding *v88; // eax
  vostok::render::resource_manager *v89; // esi
  vostok::shared_string *v90; // ecx
  const vostok::render::shader_constant_binding *v91; // eax
  vostok::render::resource_manager *v92; // esi
  vostok::shared_string *v93; // ecx
  const vostok::render::shader_constant_binding *v94; // eax
  vostok::render::resource_manager *v95; // esi
  vostok::shared_string *v96; // ecx
  const vostok::render::shader_constant_binding *v97; // eax
  vostok::render::resource_manager *v98; // esi
  vostok::shared_string *v99; // ecx
  const vostok::render::shader_constant_binding *v100; // eax
  vostok::shared_string *v101; // ecx
  const char *v102; // esi
  const char *v103; // edi
  int v104; // ecx
  bool v105; // cf
  bool v106; // zf
  int v107; // edx
  vostok::render::res_texture *texture; // eax
  const char *v109; // edi
  const char *v110; // esi
  int v111; // ecx
  bool v112; // cf
  bool v113; // zf
  int v114; // edx
  vostok::render::res_texture *v115; // eax
  int v116; // ecx
  char *v117; // eax
  int v118; // ecx
  vostok::fixed_vector<vostok::render::ray,8> *p_rays; // eax
  vostok::render::enum_render_target_index index; // [esp+10h] [ebp-938h]
  vostok::render::enum_render_target_index indexa; // [esp+10h] [ebp-938h]
  vostok::render::enum_render_target_index indexb; // [esp+10h] [ebp-938h]
  int i; // [esp+14h] [ebp-934h]
  int v124; // [esp+14h] [ebp-934h]
  vostok::math::float4x4 *v125; // [esp+14h] [ebp-934h]
  vostok::render::res_texture *v126; // [esp+14h] [ebp-934h]
  int name; // [esp+18h] [ebp-930h]
  int namea; // [esp+18h] [ebp-930h]
  char *nameb; // [esp+18h] [ebp-930h]
  vostok::render::shader_constant_binding binding; // [esp+1Ch] [ebp-92Ch] BYREF
  vostok::render::resource_manager *v131; // [esp+30h] [ebp-918h]
  vostok::render::shader_constant_binding v132; // [esp+34h] [ebp-914h] BYREF
  vostok::math::float4x4 v133; // [esp+48h] [ebp-900h] BYREF
  vostok::render::sun_cascade value; // [esp+88h] [ebp-8C0h] BYREF
  float v135; // [esp+2ACh] [ebp-69Ch]
  float v136; // [esp+2B0h] [ebp-698h]
  float v137; // [esp+3C4h] [ebp-584h]
  float v138; // [esp+3C8h] [ebp-580h]
  float v139; // [esp+4DCh] [ebp-46Ch]
  float v140; // [esp+4E0h] [ebp-468h]
  vostok::render::sun_cascade v141; // [esp+4E8h] [ebp-460h] BYREF
  float v142; // [esp+70Ch] [ebp-23Ch]
  float v143; // [esp+710h] [ebp-238h]
  float v144; // [esp+824h] [ebp-124h]
  float v145; // [esp+828h] [ebp-120h]

  *(_DWORD *)a2 = 0;
  v16 = (vostok::render::render_target_instance *)(a2 + 4);
  for ( i = 72; i >= 0; --i )
    vostok::render::render_target_instance::render_target_instance(v16++);
  *(_DWORD *)(a2 + 11692) = 0;
  *(_DWORD *)(a2 + 11696) = 0;
  *(_DWORD *)(a2 + 11700) = 0;
  *(_DWORD *)(a2 + 11704) = 0;
  v17 = (_DWORD *)(a2 + 11720);
  *(_DWORD *)(a2 + 11708) = 0;
  *(_DWORD *)(a2 + 11712) = 0;
  v124 = 1;
  v18 = a2 + 11732;
  do
  {
    *v17 = v18;
    *(_DWORD *)(v18 - 8) = v18;
    *(_DWORD *)(v18 - 4) = v18 + 2240;
    v17 += 563;
    v18 += 2252;
    --v124;
  }
  while ( v124 >= 0 );
  v19 = s_bm_current_air_resistance;
  *(_DWORD *)(a2 + 16240) = 0;
  *(float *)(a2 + 16244) = v19;
  *(_DWORD *)(a2 + 16248) = 0;
  *(float *)(a2 + 16252) = v19;
  *(_DWORD *)(a2 + 16256) = 0;
  *(_DWORD *)(a2 + 16260) = 0;
  *(_DWORD *)(a2 + 16264) = 0;
  *(_DWORD *)(a2 + 16268) = 0;
  *(_DWORD *)(a2 + 16272) = a2 + 16284;
  *(_DWORD *)(a2 + 16276) = a2 + 16284;
  *(_DWORD *)(a2 + 16280) = a2 + 17308;
  *(_DWORD *)(a2 + 17308) = a2 + 17320;
  *(_DWORD *)(a2 + 17312) = a2 + 17320;
  *(_DWORD *)(a2 + 17316) = a2 + 18344;
  *(_DWORD *)(a2 + 18344) = a2 + 18356;
  *(_DWORD *)(a2 + 18348) = a2 + 18356;
  *(_DWORD *)(a2 + 18352) = a2 + 19380;
  qmemcpy((void *)(a2 + 19380), vostok::math::float4x4::identity((vostok::math::float4x4 *)(a2 + 19380), &v133), 0x40u);
  qmemcpy((void *)(a2 + 19444), vostok::math::float4x4::identity(0, &v133), 0x40u);
  qmemcpy((void *)(a2 + 19508), vostok::math::float4x4::identity(0, &v133), 0x40u);
  qmemcpy((void *)(a2 + 19572), vostok::math::float4x4::identity(0, &v133), 0x40u);
  qmemcpy((void *)(a2 + 19636), vostok::math::float4x4::identity(0, &v133), 0x40u);
  qmemcpy((void *)(a2 + 19700), vostok::math::float4x4::identity(0, &v133), 0x40u);
  qmemcpy((void *)(a2 + 19828), vostok::math::float4x4::identity(0, &v133), 0x40u);
  qmemcpy((void *)(a2 + 19892), vostok::math::float4x4::identity(0, &v133), 0x40u);
  qmemcpy((void *)(a2 + 19956), vostok::math::float4x4::identity(0, &v133), 0x40u);
  qmemcpy((void *)(a2 + 20020), vostok::math::float4x4::identity(0, &v133), 0x40u);
  qmemcpy((void *)(a2 + 20084), vostok::math::float4x4::identity(0, &v133), 0x40u);
  qmemcpy((void *)(a2 + 20148), vostok::math::float4x4::identity(0, &v133), 0x40u);
  qmemcpy((void *)(a2 + 20212), vostok::math::float4x4::identity(0, &v133), 0x40u);
  qmemcpy((void *)(a2 + 20276), vostok::math::float4x4::identity(0, &v133), 0x40u);
  qmemcpy((void *)(a2 + 20340), vostok::math::float4x4::identity(0, &v133), 0x40u);
  qmemcpy((void *)(a2 + 20404), vostok::math::float4x4::identity(0, &v133), 0x40u);
  qmemcpy((void *)(a2 + 20468), vostok::math::float4x4::identity(0, &v133), 0x40u);
  qmemcpy((void *)(a2 + 20532), vostok::math::float4x4::identity(0, &v133), 0x40u);
  qmemcpy((void *)(a2 + 20596), vostok::math::float4x4::identity(0, &v133), 0x40u);
  *(_DWORD *)(a2 + 21084) = 0;
  *(_DWORD *)(a2 + 21088) = 0;
  *(_DWORD *)(a2 + 21092) = 0;
  *(_DWORD *)(a2 + 21096) = 0;
  *(float *)(a2 + 21100) = FLOAT_10_0;
  v20 = s_bm_current_air_resistance;
  *(_DWORD *)(a2 + 21108) = 0;
  *(_DWORD *)(a2 + 21112) = 0;
  *(float *)(a2 + 21104) = v20;
  *(_DWORD *)(a2 + 21132) = 0;
  *(_DWORD *)(a2 + 21136) = 0;
  *(_DWORD *)(a2 + 21140) = 0;
  *(float *)(a2 + 21144) = v20;
  *(_DWORD *)(a2 + 21148) = 0;
  *(_DWORD *)(a2 + 21152) = 0;
  *(float *)(a2 + 21156) = v20;
  *(float *)(a2 + 21160) = FLOAT_0_1;
  *(_DWORD *)(a2 + 21164) = 0;
  *(_DWORD *)(a2 + 21168) = 0;
  *(_DWORD *)(a2 + 21172) = 0;
  *(_DWORD *)(a2 + 21176) = 0;
  *(_DWORD *)(a2 + 21180) = 0;
  *(_DWORD *)(a2 + 21184) = 0;
  *(_DWORD *)(a2 + 21188) = 0;
  *(_DWORD *)(a2 + 21192) = 0;
  index = a2 + 20660;
  v125 = (vostok::math::float4x4 *)(a2 + 20676);
  name = 4;
  do
  {
    v21 = v125++;
    v22 = vostok::math::float4x4::identity(0, &v133);
    v23 = (_DWORD *)index;
    index += 4;
    qmemcpy(v21, v22, sizeof(vostok::math::float4x4));
    *v23 = 0;
    --name;
  }
  while ( name );
  v24 = (vostok::render::res_texture *)(a2 + 160);
  namea = 73;
  do
  {
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v24[-1].m_desc_valid,
      0);
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      0,
      v24);
    v24 = (vostok::render::res_texture *)((char *)v24 + 160);
    --namea;
  }
  while ( namea );
  *(_DWORD *)(a2 + 11684) = 0;
  *(_DWORD *)(a2 + 11688) = 0;
  memset(a2 + 20932, 0, 0x30u);
  vostok::render::register_effect_descriptors();
  v25 = 3;
  m_buffer = value.rays.m_buffer;
  do
  {
    *(_DWORD *)&m_buffer[-1].m_store[12] = m_buffer;
    *(_DWORD *)&m_buffer[-1].m_store[16] = m_buffer;
    *(_DWORD *)&m_buffer[-1].m_store[20] = m_buffer + 8;
    m_buffer[8].m_store[8] = 0;
    m_buffer = (vostok::fixed_vector<vostok::render::ray,8>::allign_helper *)((char *)m_buffer + 280);
    --v25;
  }
  while ( v25 >= 0 );
  value.size = FLOAT_10_0;
  v135 = default_fps_4;
  v27 = z_bias;
  v137 = FLOAT_75_0;
  value.bias = FLOAT_0_000099999997;
  v136 = z_bias;
  v138 = epsilon_3_4;
  v139 = FLOAT_240_0;
  v140 = FLOAT_0_003;
  v28 = 3;
  v29 = v141.rays.m_buffer;
  do
  {
    *(_DWORD *)&v29[-1].m_store[12] = v29;
    *(_DWORD *)&v29[-1].m_store[16] = v29;
    *(_DWORD *)&v29[-1].m_store[20] = v29 + 8;
    v29[8].m_store[8] = 0;
    v29 = (vostok::fixed_vector<vostok::render::ray,8>::allign_helper *)((char *)v29 + 280);
    --v28;
  }
  while ( v28 >= 0 );
  indexa = rt_frame_depth_downsampled;
  v141.bias = FLOAT_0_000099999997;
  v141.size = FLOAT_15_0;
  v142 = FLOAT_45_0;
  v143 = v27;
  v144 = FLOAT_240_0;
  v145 = epsilon_3_4;
  do
  {
    vostok::buffer_vector<vostok::render::sun_cascade>::push_back(
      (vostok::buffer_vector<vostok::render::sun_cascade> *)v28,
      a2 + 11720,
      (vostok::render::sun_cascade *)((char *)&value + indexa));
    vostok::buffer_vector<vostok::render::sun_cascade>::push_back(
      v30,
      a2 + 13972,
      (vostok::render::sun_cascade *)((char *)&v141 + indexa));
    indexa += 280;
  }
  while ( (unsigned int)indexa < (rt_frame_luminance5|rt_decals_normal_result|0x400) );
  memset(a2 + 20932, 0, 0x30u);
  *(float *)&binding.m_source.m_pointer = s_bm_current_air_resistance;
  *(float *)&binding.m_source.m_size = s_bm_current_air_resistance;
  *(float *)&binding.m_name.m_pointer.m_object = s_bm_current_air_resistance;
  *(float *)&binding.m_type = s_bm_current_air_resistance;
  *(float *)(a2 + 21068) = s_bm_current_air_resistance;
  *(_DWORD *)(a2 + 21072) = binding.m_source.m_size;
  *(_DWORD *)(a2 + 21076) = binding.m_name.m_pointer.m_object;
  *(_DWORD *)(a2 + 21080) = binding.m_type;
  vostok::render::create_quad_ib();
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v31,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 11708),
    (vostok::render::hw_buffer_pool *)&binding.m_class_id);
  geometry = vostok::render::resource_manager::create_geometry(
               v32,
               (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
               F_TL,
               3u,
               (vostok::render::untyped_buffer *)0x1C,
               *(vostok::render::untyped_buffer **)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
               *(_DWORD *)(a2 + 11708));
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 11696),
    geometry);
  v34 = vostok::render::resource_manager::create_geometry(
          *(vostok::render::resource_manager **)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          F_TL2uv,
          4u,
          (vostok::render::untyped_buffer *)0x24,
          *(vostok::render::untyped_buffer **)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          *(_DWORD *)(a2 + 11708));
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 11700),
    v34);
  v36 = vostok::render::resource_manager::create_geometry(
          v35,
          (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          F_Tquad,
          3u,
          (vostok::render::untyped_buffer *)0x24,
          *(vostok::render::untyped_buffer **)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          *(_DWORD *)(a2 + 11708));
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 11704),
    v36);
  vostok::render::renderer_context::reset_matrices(v37, a2);
  v38 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &binding,
    (vostok::math::float4x4 *)(a2 + 19444),
    v39,
    "m_W");
  *(_DWORD *)(a2 + 21164) = vostok::render::resource_manager::register_constant_binding(v38, v40);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&binding.m_name.m_pointer);
  v41 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &v132,
    (vostok::math::float4x4 *)(a2 + 19572),
    v42,
    "m_V");
  *(_DWORD *)(a2 + 21172) = vostok::render::resource_manager::register_constant_binding(v41, v43);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&v132.m_name.m_pointer);
  v44 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &binding,
    (vostok::math::float4x4 *)(a2 + 19892),
    v45,
    "m_P");
  *(_DWORD *)(a2 + 21176) = vostok::render::resource_manager::register_constant_binding(v44, v46);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&binding.m_name.m_pointer);
  v47 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &v132,
    (vostok::math::float4x4 *)(a2 + 19700),
    v48,
    "m_V2W");
  *(_DWORD *)(a2 + 21192) = vostok::render::resource_manager::register_constant_binding(v47, v49);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&v132.m_name.m_pointer);
  v50 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &binding,
    (vostok::math::float4x4 *)(a2 + 19764),
    v51,
    "m_WV_inverted");
  *(_DWORD *)(a2 + 21196) = vostok::render::resource_manager::register_constant_binding(v50, v52);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&binding.m_name.m_pointer);
  v53 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &v132,
    (vostok::math::float4x4 *)(a2 + 20084),
    v54,
    "m_WV");
  *(_DWORD *)(a2 + 21180) = vostok::render::resource_manager::register_constant_binding(v53, v55);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&v132.m_name.m_pointer);
  v56 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &binding,
    (vostok::math::float4x4 *)(a2 + 20212),
    v57,
    "m_VP");
  *(_DWORD *)(a2 + 21184) = vostok::render::resource_manager::register_constant_binding(v56, v58);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&binding.m_name.m_pointer);
  v59 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &v132,
    (vostok::math::float4x4 *)(a2 + 20340),
    v60,
    "m_WVP");
  *(_DWORD *)(a2 + 21188) = vostok::render::resource_manager::register_constant_binding(v59, v61);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&v132.m_name.m_pointer);
  v62 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &binding,
    (vostok::math::float4 *)(a2 + 16224),
    v63,
    "near_far_invn_invf");
  *(_DWORD *)(a2 + 21200) = vostok::render::resource_manager::register_constant_binding(v62, v64);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&binding.m_name.m_pointer);
  v65 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &v132,
    (vostok::math::float3 *)(a2 + 20980),
    v66,
    "to_sun_direction");
  *(_DWORD *)(a2 + 21208) = vostok::render::resource_manager::register_constant_binding(v65, v67);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&v132.m_name.m_pointer);
  v68 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &binding,
    (vostok::math::float3 *)(a2 + 20992),
    v69,
    "sun_color");
  *(_DWORD *)(a2 + 21212) = vostok::render::resource_manager::register_constant_binding(v68, v70);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&binding.m_name.m_pointer);
  v71 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &v132,
    (vostok::math::float4 *)(a2 + 21004),
    v72,
    "atmosphere_parameters0");
  *(_DWORD *)(a2 + 21204) = vostok::render::resource_manager::register_constant_binding(v71, v73);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&v132.m_name.m_pointer);
  v74 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &binding,
    (vostok::math::float4 *)(a2 + 21020),
    v75,
    "atmosphere_parameters1");
  *(_DWORD *)(a2 + 21216) = vostok::render::resource_manager::register_constant_binding(v74, v76);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&binding.m_name.m_pointer);
  v77 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &v132,
    (vostok::math::float4 *)(a2 + 21036),
    v78,
    "atmosphere_parameters2");
  *(_DWORD *)(a2 + 21220) = vostok::render::resource_manager::register_constant_binding(v77, v79);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&v132.m_name.m_pointer);
  v80 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &binding,
    (vostok::math::float4 *)(a2 + 21052),
    v81,
    "atmosphere_parameters3");
  *(_DWORD *)(a2 + 21224) = vostok::render::resource_manager::register_constant_binding(v80, v82);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&binding.m_name.m_pointer);
  v83 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &v132,
    (vostok::math::float4 *)(a2 + 21068),
    v84,
    "screen_res");
  *(_DWORD *)(a2 + 21228) = vostok::render::resource_manager::register_constant_binding(v83, v85);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&v132.m_name.m_pointer);
  v86 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &binding,
    (vostok::math::float4 *)(a2 + 21132),
    v87,
    "eye_position");
  *(_DWORD *)(a2 + 21232) = vostok::render::resource_manager::register_constant_binding(v86, v88);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&binding.m_name.m_pointer);
  v89 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &v132,
    (vostok::math::float4 *)(a2 + 21148),
    v90,
    "eye_direction");
  *(_DWORD *)(a2 + 21240) = vostok::render::resource_manager::register_constant_binding(v89, v91);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&v132.m_name.m_pointer);
  v92 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &binding,
    (vostok::math::float4 *)(a2 + 21084),
    v93,
    "solid_color_specular");
  *(_DWORD *)(a2 + 21244) = vostok::render::resource_manager::register_constant_binding(v92, v94);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&binding.m_name.m_pointer);
  v95 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &v132,
    (vostok::math::float4 *)(a2 + 21100),
    v96,
    "solid_material_params");
  *(_DWORD *)(a2 + 21248) = vostok::render::resource_manager::register_constant_binding(v95, v97);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&v132.m_name.m_pointer);
  v98 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &binding,
    (vostok::math::float4 *)(a2 + 21116),
    v99,
    "solid_emission_color");
  *(_DWORD *)(a2 + 21252) = vostok::render::resource_manager::register_constant_binding(v98, v100);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&binding.m_name.m_pointer);
  binding.m_source.m_pointer = (void *const)(a2 + 11716);
  binding.m_source.m_size = 4;
  vostok::shared_string::shared_string(v101, &binding.m_name.m_pointer, "scene_time");
  binding.m_type = rc_float;
  binding.m_class_id = rc_1x1;
  *(_DWORD *)(a2 + 21256) = vostok::render::resource_manager::register_constant_binding(
                              vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                              &binding);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&binding.m_name.m_pointer);
  indexb = rt_frame_depth_downsampled;
  v126 = (vostok::render::res_texture *)(a2 + 160);
  do
  {
    v102 = vostok::render::rt_index_to_name(indexb);
    nameb = (char *)v102;
    if ( v102 )
    {
      v103 = "null";
      v104 = 5;
      v107 = 0;
      v105 = 0;
      v106 = 1;
      do
      {
        if ( !v104 )
          break;
        v105 = *v102 < (unsigned int)*v103;
        v106 = *v102++ == *v103++;
        --v104;
      }
      while ( v106 );
      v131 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
      if ( !v106 )
        v107 = -v105 - (v105 - 1);
      if ( v107 )
      {
        texture = (vostok::render::res_texture *)vostok::render::resource_manager::find_texture(
                                                   (vostok::render::resource_manager *)v104,
                                                   (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                                   nameb);
        if ( !texture )
          texture = vostok::render::resource_manager::load_texture(v131, nameb, 0, 0, 0, 1, 1, 0xFFFFFFFF, 1, 0);
      }
      else
      {
        texture = 0;
      }
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        texture,
        v126);
    }
    ++indexb;
    v126 = (vostok::render::res_texture *)((char *)v126 + 160);
  }
  while ( (unsigned int)indexb < rt_num_render_targets );
  v109 = "null";
  v110 = "$user$null";
  v111 = 11;
  v114 = 0;
  v112 = 0;
  v113 = 1;
  do
  {
    if ( !v111 )
      break;
    v112 = *v110 < (unsigned int)*v109;
    v113 = *v110++ == *v109++;
    --v111;
  }
  while ( v113 );
  v131 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  if ( !v113 )
    v114 = -v112 - (v112 - 1);
  if ( v114 )
  {
    v115 = (vostok::render::res_texture *)vostok::render::resource_manager::find_texture(
                                            (vostok::render::resource_manager *)v111,
                                            (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                                            "$user$null");
    if ( !v115 )
      v115 = vostok::render::resource_manager::load_texture(v131, "$user$null", 0, 0, 0, 1, 1, 0xFFFFFFFF, 1, 0);
  }
  else
  {
    v115 = 0;
  }
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v115,
    (vostok::render::res_texture *)(a2 + 11692));
  v116 = 3;
  v117 = &a16;
  do
  {
    v117 -= 280;
    --v116;
    *((_DWORD *)v117 + 1) = *(_DWORD *)v117;
  }
  while ( v116 >= 0 );
  v118 = 3;
  p_rays = &v141.rays;
  do
  {
    p_rays = (vostok::fixed_vector<vostok::render::ray,8> *)((char *)p_rays - 280);
    --v118;
    p_rays->m_end = p_rays->m_begin;
  }
  while ( v118 >= 0 );
}
