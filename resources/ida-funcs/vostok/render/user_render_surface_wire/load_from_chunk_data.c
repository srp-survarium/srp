void __userpurge vostok::render::user_render_surface_wire::load_from_chunk_data(
        vostok::render::user_render_surface_wire *this@<ecx>,
        vostok::render::material_effects_instance_cook_data *a2@<ebp>,
        vostok::render::hw_buffer_pool *a3@<edi>,
        const char *a4@<esi>,
        vostok::memory::chunk_reader *chunk)
{
  vostok::memory::reader *v5; // ecx
  char *v6; // eax
  vostok::fixed_string<256> *v7; // ecx
  vostok::memory::chunk_reader *v8; // ecx
  vostok::math::aabb *v9; // ecx
  float y; // esi
  int v11; // eax
  int v12; // edi
  unsigned int v13; // esi
  void *v14; // esp
  void *v15; // esp
  void *v16; // esp
  unsigned int v17; // edx
  vostok::render::hw_buffer_pool **v18; // eax
  float *v19; // ecx
  float v20; // esi
  float *v21; // edi
  unsigned int v22; // ecx
  float *p_delete_in_cook; // eax
  float *v24; // edx
  vostok::math::float3_pod *v25; // esi
  float v26; // xmm4_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm5_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  vostok::math::float3 *v36; // eax
  float v37; // xmm2_4
  float v38; // xmm3_4
  float *v39; // edi
  float v40; // xmm0_4
  float v41; // xmm0_4
  vostok::math::float3 *v42; // eax
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm3_4
  vostok::math::aabb *v46; // edi
  float v47; // xmm1_4
  float v48; // xmm2_4
  vostok::math::float3 *v49; // eax
  float v50; // xmm0_4
  float v51; // xmm1_4
  float v52; // xmm2_4
  vostok::math::aabb *m_object; // eax
  float *v54; // edi
  vostok::math::aabb *v55; // esi
  vostok::render::hw_buffer_pool **v56; // eax
  float v57; // xmm1_4
  float v58; // xmm3_4
  float v59; // xmm2_4
  vostok::math::aabb *v60; // edx
  float v61; // xmm5_4
  float v62; // xmm0_4
  float v63; // xmm1_4
  float v64; // xmm3_4
  float v65; // xmm2_4
  float v66; // xmm5_4
  float v67; // xmm1_4
  float v68; // xmm3_4
  float v69; // xmm2_4
  float z; // xmm6_4
  float v71; // xmm4_4
  float v72; // xmm5_4
  float v73; // xmm1_4
  float v74; // xmm4_4
  float v75; // xmm3_4
  float v76; // xmm1_4
  float v77; // xmm2_4
  float v78; // xmm3_4
  float v79; // xmm7_4
  float v80; // xmm1_4
  float v81; // xmm7_4
  float v82; // xmm3_4
  float v83; // xmm2_4
  float v84; // xmm7_4
  float v85; // xmm1_4
  float v86; // xmm4_4
  float v87; // xmm1_4
  float v88; // xmm7_4
  float v89; // xmm3_4
  float v90; // xmm2_4
  float v91; // xmm0_4
  float v92; // xmm0_4
  float v93; // xmm1_4
  float v94; // xmm2_4
  float v95; // xmm1_4
  float x; // xmm2_4
  unsigned int v97; // ecx
  unsigned int v98; // edx
  __int16 v99; // cx
  vostok::render::untyped_buffer *v100; // eax
  vostok::render::user_render_surface_wire *v101; // ecx
  vostok::render::material_effects_instance_cook_data *v102; // edi
  vostok::render::untyped_buffer *v103; // eax
  vostok::render::resource_manager *v104; // ecx
  vostok::render::res_declaration *declaration; // eax
  vostok::render::resource_manager *v106; // ecx
  vostok::render::res_geometry *geometry; // eax
  survarium::pure_game_effect_emitter_base *v108; // ecx
  vostok::render::material_effects_instance_cook_data *v109; // eax
  vostok::memory::doug_lea_allocator *v110; // esi
  char *v111; // eax
  vostok::memory::doug_lea_allocator *v112; // ecx
  char *v113; // esi
  bool ListenerStatus; // al
  vostok::fixed_string<260> *v115; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v116; // ecx
  vostok::variant<32> *v117; // ecx
  float v118; // edi
  vostok::render::resource_manager *v119; // esi
  bool v120; // zf
  const vostok::render::hw_buffer_pool_range *v121; // eax
  int v122; // eax
  float v123; // edi
  const vostok::render::hw_buffer_pool_range *v124; // eax
  int v125; // eax
  vostok::render::resource_manager *v126; // [esp-440h] [ebp-44Ch]
  vostok::render::enum_buffer_type v127; // [esp-438h] [ebp-444h]
  BOOL v128; // [esp-434h] [ebp-440h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v129; // [esp-430h] [ebp-43Ch] BYREF
  int v130; // [esp-42Ch] [ebp-438h]
  vostok::render::hw_buffer_pool *v131; // [esp-428h] [ebp-434h] BYREF
  const char *v132; // [esp-424h] [ebp-430h]
  vostok::buffer_string v133; // [esp-420h] [ebp-42Ch] BYREF
  vostok::buffer_string v134; // [esp-310h] [ebp-31Ch] BYREF
  vostok::math::float3 v135; // [esp-200h] [ebp-20Ch] BYREF
  vostok::math::float3 v136; // [esp-1F4h] [ebp-200h] BYREF
  vostok::variant<32> v137; // [esp-1E8h] [ebp-1F4h] BYREF
  vostok::math::float3 v138[2]; // [esp-1B8h] [ebp-1C4h] BYREF
  float v139[3]; // [esp-1A0h] [ebp-1ACh] BYREF
  float v140; // [esp-194h] [ebp-1A0h]
  float v141; // [esp-190h] [ebp-19Ch]
  float v142; // [esp-18Ch] [ebp-198h]
  vostok::math::float3_pod v143; // [esp-188h] [ebp-194h] BYREF
  float v144; // [esp-17Ch] [ebp-188h]
  float v145; // [esp-178h] [ebp-184h]
  float v146; // [esp-174h] [ebp-180h]
  vostok::math::float3 v147; // [esp-170h] [ebp-17Ch] BYREF
  float v148; // [esp-164h] [ebp-170h]
  float v149; // [esp-160h] [ebp-16Ch]
  float v150; // [esp-15Ch] [ebp-168h]
  vostok::math::float3 v151; // [esp-158h] [ebp-164h] BYREF
  vostok::math::float3_pod v152; // [esp-14Ch] [ebp-158h] BYREF
  float v153[3]; // [esp-140h] [ebp-14Ch] BYREF
  float v154; // [esp-134h] [ebp-140h]
  float v155; // [esp-130h] [ebp-13Ch]
  float v156; // [esp-12Ch] [ebp-138h]
  float v157; // [esp-128h] [ebp-134h]
  float v158; // [esp-124h] [ebp-130h]
  float v159; // [esp-120h] [ebp-12Ch]
  vostok::math::float3 v160; // [esp-11Ch] [ebp-128h] BYREF
  float v161; // [esp-110h] [ebp-11Ch]
  float v162; // [esp-10Ch] [ebp-118h]
  float v163; // [esp-108h] [ebp-114h]
  vostok::math::float3 v164; // [esp-104h] [ebp-110h] BYREF
  float v165; // [esp-F8h] [ebp-104h]
  float v166; // [esp-F4h] [ebp-100h]
  float v167; // [esp-F0h] [ebp-FCh]
  float v168; // [esp-ECh] [ebp-F8h]
  float v169; // [esp-E8h] [ebp-F4h]
  float v170; // [esp-E4h] [ebp-F0h]
  float v171; // [esp-E0h] [ebp-ECh]
  float v172; // [esp-DCh] [ebp-E8h]
  vostok::render::hw_buffer_pool **v173; // [esp-D8h] [ebp-E4h]
  vostok::math::aabb *v174; // [esp-D4h] [ebp-E0h]
  unsigned int v175; // [esp-D0h] [ebp-DCh]
  vostok::render::hw_buffer_pool **v176; // [esp-CCh] [ebp-D8h]
  unsigned int v177; // [esp-C8h] [ebp-D4h]
  float v178; // [esp-C4h] [ebp-D0h]
  vostok::render::hw_buffer_pool *v179; // [esp-C0h] [ebp-CCh]
  float v180; // [esp-BCh] [ebp-C8h]
  float v181; // [esp-B8h] [ebp-C4h]
  vostok::math::float3_pod v182; // [esp-B4h] [ebp-C0h] BYREF
  float v183; // [esp-A8h] [ebp-B4h]
  float v184; // [esp-A4h] [ebp-B0h]
  float v185; // [esp-A0h] [ebp-ACh]
  float v186; // [esp-9Ch] [ebp-A8h]
  vostok::render::hw_buffer_pool **v187; // [esp-98h] [ebp-A4h]
  unsigned int v188; // [esp-94h] [ebp-A0h]
  vostok::math::aabb *v189; // [esp-90h] [ebp-9Ch]
  float v190; // [esp-8Ch] [ebp-98h]
  int v191; // [esp-88h] [ebp-94h] BYREF
  __int16 v192; // [esp-84h] [ebp-90h]
  __int16 v193; // [esp-82h] [ebp-8Eh]
  _QWORD v194[3]; // [esp-80h] [ebp-8Ch] BYREF
  __int16 v195; // [esp-68h] [ebp-74h]
  __int16 v196; // [esp-66h] [ebp-72h]
  vostok::math::float3_pod v197; // [esp-5Ch] [ebp-68h] BYREF
  float v198; // [esp-50h] [ebp-5Ch] BYREF
  float v199; // [esp-4Ch] [ebp-58h]
  float v200; // [esp-48h] [ebp-54h]
  float v201; // [esp-44h] [ebp-50h]
  vostok::math::aabb *v202; // [esp-40h] [ebp-4Ch]
  unsigned int v203; // [esp-3Ch] [ebp-48h]
  unsigned int v204; // [esp-38h] [ebp-44h]
  vostok::render::hw_buffer_pool **v205; // [esp-34h] [ebp-40h]
  float v206; // [esp-30h] [ebp-3Ch]
  float v207; // [esp-2Ch] [ebp-38h]
  float v208; // [esp-28h] [ebp-34h]
  vostok::render::user_render_surface_wire *v209; // [esp-24h] [ebp-30h]
  vostok::render::material_effects_instance_cook_data *v210; // [esp-20h] [ebp-2Ch]
  float v211; // [esp-1Ch] [ebp-28h]
  float v212; // [esp-18h] [ebp-24h]
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v213; // [esp-14h] [ebp-20h] BYREF
  vostok::math::float3 v214; // [esp-10h] [ebp-1Ch] BYREF
  vostok::render::material_effects_instance_cook_data *v215[4]; // [esp-4h] [ebp-10h] BYREF
  vostok::render::material_effects_instance_cook_data *retaddr; // [esp+Ch] [ebp+0h]

  v215[1] = a2;
  v215[2] = retaddr;
  v132 = a4;
  v131 = a3;
  v130 = 2;
  v209 = this;
  this->m_vertex_input_type = wires_vertex_input_type;
  vostok::memory::chunk_reader::open_reader(
    (vostok::memory::chunk_reader *)this,
    chunk,
    (const unsigned __int8 **)&v214,
    (vostok::memory::chunk_reader::chunk_type *)v130,
    (unsigned int)v131);
  v6 = (char *)vostok::memory::reader::r_string(v5, &v214);
  vostok::fixed_string<256>::fixed_string<256>(v7, &v134, v6);
  v202 = *(vostok::math::aabb **)LODWORD(v214.y);
  v214 = *(vostok::math::float3 *)vostok::memory::chunk_reader::open_reader(
                                    v8,
                                    chunk,
                                    (const unsigned __int8 **)&v198,
                                    (vostok::memory::chunk_reader::chunk_type *)3,
                                    (unsigned int)v131);
  v213.m_object = (vostok::render::res_declaration *)&v209->m_aabbox;
  vostok::math::aabb::zero(v9, &v209->m_aabbox);
  y = v214.y;
  LODWORD(v214.y) += 4;
  v203 = *(_DWORD *)LODWORD(y);
  v11 = 12 * v203;
  v188 = v203 - 1;
  v12 = 3 * v203;
  v13 = 18 * (v203 - 1);
  v204 = v13;
  v209->m_render_geometry.vertex_count = 3 * v203;
  v14 = alloca(v11);
  v215[0] = (vostok::render::material_effects_instance_cook_data *)&v131;
  v177 = 56 * v12;
  v15 = alloca(56 * v12);
  v187 = &v131;
  v210 = (vostok::render::material_effects_instance_cook_data *)(2 * v13);
  v16 = alloca(2 * v13);
  v17 = v203;
  v18 = &v131;
  v176 = &v131;
  v173 = &v131;
  if ( v203 )
  {
    v19 = (float *)v215[0];
    do
    {
      v20 = v214.y;
      LODWORD(v214.y) += 12;
      v198 = *(float *)LODWORD(v20);
      LODWORD(v20) += 4;
      v199 = *(float *)LODWORD(v20);
      v200 = *(float *)(LODWORD(v20) + 4);
      *v19 = v198;
      v19[1] = v199;
      v21 = v19 + 2;
      v19 += 3;
      --v17;
      *v21 = v200;
    }
    while ( v17 );
    v13 = v204;
  }
  v22 = 0;
  v190 = 0.0;
  if ( v203 )
  {
    p_delete_in_cook = (float *)&v215[0][-1].delete_in_cook;
    memset(&v147, 0, sizeof(v147));
    memset(&v164, 0, sizeof(v164));
    memset(&v160, 0, sizeof(v160));
    memset(&v151, 0, sizeof(v151));
    v179 = 0;
    v183 = *(float *)&v202 * 0.5;
    v212 = *(float *)&v202 * 0.5;
    v181 = c_anim_center;
    v172 = FLOAT_0_1;
    v215[0] = (vostok::render::material_effects_instance_cook_data *)((char *)v215[0] - 4);
    v205 = v187 + 18;
    while ( 1 )
    {
      v24 = p_delete_in_cook + 1;
      v206 = p_delete_in_cook[1];
      v207 = p_delete_in_cook[2];
      v208 = p_delete_in_cook[3];
      v175 = v22 + 1;
      if ( v22 + 1 == v203 )
      {
        v139[0] = *v24 - *(p_delete_in_cook - 2);
        v139[1] = p_delete_in_cook[2] - *(p_delete_in_cook - 1);
        v139[2] = p_delete_in_cook[3] - *p_delete_in_cook;
        v25 = (vostok::math::float3_pod *)v139;
      }
      else
      {
        v153[0] = p_delete_in_cook[4] - *v24;
        v153[1] = p_delete_in_cook[5] - p_delete_in_cook[2];
        v153[2] = p_delete_in_cook[6] - p_delete_in_cook[3];
        v25 = (vostok::math::float3_pod *)v153;
      }
      v182 = *v25;
      v214 = *vostok::math::normalize_safe(&v182, &v147, &v136);
      v26 = v214.x - (float)(v214.y * 0.0);
      v27 = (float)(v214.y * 0.0) - v214.z;
      v28 = (float)(v214.z * 0.0) - (float)(v214.x * 0.0);
      v29 = s_bm_current_air_resistance / fsqrt((float)((float)(v26 * v26) + (float)(v28 * v28)) + (float)(v27 * v27));
      v30 = v29 * v27;
      v31 = v29 * v28;
      v186 = v29 * v26;
      v32 = (float)((float)(v29 * v28) * v214.z) - (float)((float)(v29 * v26) * v214.y);
      v33 = (float)(v214.x * (float)(v29 * v26)) - (float)((float)(v29 * v27) * v214.z);
      v184 = v30;
      v34 = (float)(v30 * v214.y) - (float)(v214.x * v31);
      v35 = s_bm_current_air_resistance / fsqrt((float)((float)(v32 * v32) + (float)(v34 * v34)) + (float)(v33 * v33));
      v197.z = v35 * v34;
      v185 = v31;
      v197.x = v35 * v32;
      v197.y = v35 * v33;
      v201 = v183;
      v36 = vostok::math::normalize_safe(&v197, &v164, &v135);
      v37 = v36->z * v201;
      v38 = v206 + (float)(v36->x * v201);
      v169 = v207 + (float)(v36->y * v201);
      v170 = v208 + v37;
      v39 = (float *)(v205 - 18);
      v168 = v38;
      v174 = (vostok::math::aabb *)(v205 - 18);
      v211 = v183;
      v40 = v184 - v197.x;
      *v39++ = v38;
      *v39 = v169;
      v143.x = v40;
      v143.y = v185 - v197.y;
      v41 = v186 - v197.z;
      v39[1] = v170;
      v143.z = v41;
      v42 = vostok::math::normalize_safe(&v143, &v160, &v138[1]);
      v43 = (float)(v42->y * v211) + v207;
      v44 = (float)(v42->z * v211) + v208;
      v45 = v186;
      v46 = (vostok::math::aabb *)(v205 - 4);
      v154 = (float)(v42->x * v211) + v206;
      v155 = v43;
      v47 = v184;
      v156 = v44;
      v48 = v185;
      v189 = v46;
      v46->min.x = v154;
      v46 = (vostok::math::aabb *)((char *)v46 + 4);
      v46->min.x = v155;
      v46->min.y = v156;
      v152.x = COERCE_FLOAT(LODWORD(v47) ^ _mask__NegFloat_) - v197.x;
      v152.y = COERCE_FLOAT(LODWORD(v48) ^ _mask__NegFloat_) - v197.y;
      v152.z = COERCE_FLOAT(LODWORD(v45) ^ _mask__NegFloat_) - v197.z;
      v49 = vostok::math::normalize_safe(&v152, &v151, (vostok::math::float3 *)&v194[2]);
      v50 = (float)(v49->x * v212) + v206;
      v51 = (float)(v49->y * v212) + v207;
      v52 = (float)(v49->z * v212) + v208;
      m_object = (vostok::math::aabb *)v213.m_object;
      v54 = (float *)(v205 + 10);
      v144 = v50;
      v145 = v51;
      v146 = v52;
      v202 = (vostok::math::aabb *)(v205 + 10);
      *((float *)v205 + 10) = v50;
      *++v54 = v145;
      v54[1] = v146;
      v55 = v174;
      vostok::math::aabb::modify(v174, m_object);
      vostok::math::aabb::modify(v189, (vostok::math::aabb *)v213.m_object);
      vostok::math::aabb::modify(v202, (vostok::math::aabb *)v213.m_object);
      v56 = v205;
      v57 = v55->min.x - v206;
      v58 = *((float *)v205 - 16) - v208;
      v59 = *((float *)v205 - 17) - v207;
      v60 = v189;
      v61 = fsqrt((float)((float)(v57 * v57) + (float)(v58 * v58)) + (float)(v59 * v59));
      v62 = s_bm_current_air_resistance;
      v140 = v57 * (float)(s_bm_current_air_resistance / v61);
      v141 = v59 * (float)(s_bm_current_air_resistance / v61);
      v142 = v58 * (float)(s_bm_current_air_resistance / v61);
      *((float *)v205 - 15) = v140;
      *((float *)v56 - 14) = v141;
      *((float *)v56 - 13) = v142;
      v63 = v60->min.x - v206;
      v64 = *((float *)v56 - 2) - v208;
      v65 = *((float *)v56 - 3) - v207;
      v66 = fsqrt((float)((float)(v63 * v63) + (float)(v64 * v64)) + (float)(v65 * v65));
      v148 = v63 * (float)(v62 / v66);
      v149 = v65 * (float)(v62 / v66);
      v150 = v64 * (float)(v62 / v66);
      *((float *)v56 - 1) = v148;
      *(float *)v56 = v149;
      *((float *)v56 + 1) = v150;
      v67 = v202->min.x - v206;
      v68 = *((float *)v56 + 12) - v208;
      v69 = *((float *)v56 + 11) - v207;
      z = v214.z;
      v71 = v62 / fsqrt((float)((float)(v67 * v67) + (float)(v68 * v68)) + (float)(v69 * v69));
      v72 = v214.y;
      v167 = v68 * v71;
      v165 = v67 * v71;
      v166 = v69 * v71;
      *((float *)v56 + 13) = v67 * v71;
      *((float *)v56 + 14) = v166;
      *((float *)v56 + 15) = v167;
      v73 = *((float *)v56 - 14);
      v74 = v73 * v214.x;
      v75 = *((float *)v56 - 13);
      v76 = (float)(v73 * z) - (float)(v75 * v72);
      v77 = (float)(v75 * v214.x) - (float)(*((float *)v56 - 15) * z);
      v78 = (float)(*((float *)v56 - 15) * v72) - v74;
      v79 = fsqrt((float)((float)(v76 * v76) + (float)(v78 * v78)) + (float)(v77 * v77));
      v161 = v76 * (float)(v62 / v79);
      v163 = v78 * (float)(v62 / v79);
      v162 = v77 * (float)(v62 / v79);
      *((float *)v56 - 12) = v161;
      *((float *)v56 - 11) = v162;
      *((float *)v56 - 10) = v163;
      v80 = (float)(*(float *)v56 * z) - (float)(*((float *)v56 + 1) * v72);
      v81 = *((float *)v56 - 1);
      v82 = (float)(v81 * v72) - (float)(*(float *)v56 * v214.x);
      v83 = (float)(*((float *)v56 + 1) * v214.x) - (float)(v81 * z);
      v84 = fsqrt((float)((float)(v80 * v80) + (float)(v82 * v82)) + (float)(v83 * v83));
      v159 = v82 * (float)(v62 / v84);
      v157 = v80 * (float)(v62 / v84);
      v158 = v83 * (float)(v62 / v84);
      *((float *)v56 + 2) = v157;
      *((float *)v56 + 3) = v158;
      *((float *)v56 + 4) = v159;
      v85 = *((float *)v56 + 14);
      v86 = v85 * v214.x;
      v87 = (float)(v85 * z) - (float)(*((float *)v56 + 15) * v72);
      v88 = *((float *)v56 + 13);
      v89 = (float)(v88 * v72) - v86;
      v90 = (float)(*((float *)v56 + 15) * v214.x) - (float)(v88 * z);
      v91 = v62 / fsqrt((float)((float)(v87 * v87) + (float)(v89 * v89)) + (float)(v90 * v90));
      v198 = v87 * v91;
      v199 = v90 * v91;
      v200 = v89 * v91;
      *((float *)v56 + 16) = v87 * v91;
      *((float *)v56 + 17) = v199;
      *((float *)v56 + 18) = v200;
      *((vostok::math::float3 *)v56 - 3) = v214;
      v92 = v190;
      *(vostok::math::float3 *)(v56 + 5) = v214;
      *(vostok::math::float3 *)(v56 + 19) = v214;
      v93 = v182.y;
      v94 = v182.z;
      v215[0] = (vostok::render::material_effects_instance_cook_data *)((char *)v215[0] + 12);
      v178 = v92;
      *((float *)v56 - 6) = v92;
      *(v56 - 5) = v179;
      v180 = v92;
      *((float *)v56 + 8) = v92;
      *((float *)v56 + 9) = v181;
      v171 = v92;
      *((float *)v56 + 22) = v92;
      v95 = (float)(v93 * v93) + (float)(v94 * v94);
      x = v182.x;
      *((float *)v56 + 23) = v172;
      v22 = v175;
      v190 = fsqrt(v95 + (float)(x * x)) + v92;
      v205 = v56 + 42;
      if ( v175 >= v203 )
        break;
      p_delete_in_cook = (float *)v215[0];
    }
    v18 = v176;
    v13 = v204;
  }
  v191 = 0x10000;
  v192 = 3;
  v193 = 1;
  v194[0] = 0x5000000030004LL;
  v194[1] = 0x5000300000002LL;
  v194[2] = 0x2000100040002LL;
  v195 = 5;
  v196 = 4;
  LOWORD(v97) = 0;
  v204 = 0;
  if ( v188 )
  {
    do
    {
      v98 = 0;
      v99 = 3 * v97;
      do
      {
        *(_WORD *)v18 = v99 + *((_WORD *)&v191 + v98);
        v18 = (vostok::render::hw_buffer_pool **)((char *)v18 + 2);
        ++v98;
      }
      while ( v98 < 0x12 );
      v97 = v204 + 1;
      v204 = v97;
    }
    while ( v97 < v188 );
  }
  vostok::render::resource_manager::create_buffer(
    v177,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)0x38,
    (vostok::render::enum_buffer_type)v187,
    0,
    1,
    0);
  v211 = 0.0;
  if ( *(float *)&v100 != 0.0 )
  {
    ++v100->m_reference_count;
    v211 = *(float *)&v100;
  }
  v101 = v209;
  v209->m_render_geometry.index_count = v13;
  LOBYTE(v130) = 0;
  LOBYTE(v129.m_object) = 0;
  v102 = v210;
  v128 = 1;
  v127 = (vostok::render::enum_buffer_type)v173;
  v126 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  v101->m_render_geometry.primitive_count = v13 / 3;
  vostok::render::resource_manager::create_buffer(
    (unsigned int)v102,
    v126,
    (void *)2,
    v127,
    v128,
    (bool)v129.m_object,
    v130);
  v212 = 0.0;
  if ( *(float *)&v103 != 0.0 )
  {
    ++v103->m_reference_count;
    v212 = *(float *)&v103;
  }
  declaration = vostok::render::resource_manager::create_declaration(
                  v104,
                  (const D3D11_INPUT_ELEMENT_DESC *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  layout_wire,
                  5u);
  v213.m_object = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    v213.m_object = declaration;
  }
  geometry = vostok::render::resource_manager::create_geometry(
               v106,
               (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
               v213.m_object,
               (vostok::render::untyped_buffer *)0x38,
               (vostok::render::untyped_buffer *)LODWORD(v211),
               (vostok::render::untyped_buffer *)LODWORD(v212));
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &v209->m_render_geometry.geom,
    geometry);
  v210 = (vostok::render::material_effects_instance_cook_data *)vostok::memory::new_helper<vostok::render::material_effects_instance_cook_data>::call<vostok::memory::doug_lea_allocator>(
                                                                  vostok::render::g_allocator,
                                                                  (const char *const)v131,
                                                                  v132,
                                                                  (const unsigned int)v133.m_begin);
  if ( v210 )
  {
    v130 = 0;
    v129.m_object = v108;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v129,
      0);
    vostok::render::material_effects_instance_cook_data::material_effects_instance_cook_data(
      v209->m_vertex_input_type,
      v210,
      v129,
      v130,
      (vostok::render::enum_cull_mode)v131);
    v215[0] = v109;
  }
  else
  {
    v215[0] = 0;
  }
  v137.m_helper = 0;
  v137.m_type_id = 0;
  vostok::variant<32>::set<vostok::render::material_effects_instance_cook_data *>(
    (vostok::variant<32> *)v108,
    &v137,
    v215);
  v110 = vostok::render::g_allocator;
  v111 = type_info::raw_name(&char `RTTI Type Descriptor');
  *(float *)&v113 = COERCE_FLOAT(
                      vostok::memory::doug_lea_allocator::malloc_impl(
                        v112,
                        (int)v110,
                        0x100u,
                        v111,
                        (const char *const)v131,
                        v132,
                        (const unsigned int)v133.m_begin));
  memset((int)v113, 0, 0x100u);
  strcpy_s(v113, 0x100u, v134.m_begin);
  v198 = *(float *)&v209;
  v200 = *(float *)&v113;
  HIDWORD(v194[0]) = 0;
  LODWORD(v194[0]) = vostok::render::user_render_surface::material_ready;
  v199 = *(float *)v215;
  v194[1] = __PAIR64__((unsigned int)v215[0], (unsigned int)v209);
  LODWORD(v194[2]) = v113;
  v130 = (int)v138;
  qmemcpy(v138, v194, sizeof(v138));
  ListenerStatus = Scaleform::Render::RenderEvent::GetListenerStatus(0);
  v115 = (vostok::fixed_string<260> *)v130;
  if ( ListenerStatus )
  {
    v191 = 0;
  }
  else
  {
    qmemcpy(v194, v138, sizeof(v194));
    v115 = 0;
    v191 = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::user_render_surface,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,char *>,boost::_bi::list4<boost::_bi::value<vostok::render::user_render_surface_wire *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>,boost::_bi::value<char *>>>>'::`2'::stored_vtable
         + 1;
  }
  vostok::fixed_string<260>::fixed_string<260>(v115, &v133, v134.m_begin);
  vostok::resources::query_resource(
    v133.m_begin,
    (vostok::variant<32> *)0xF,
    vostok::render::g_allocator,
    &v137,
    0,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v116, &v191);
  vostok::variant<32>::destroy_previous_variable_if_needed(v117, (int)&v137);
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(&v213);
  v118 = v212;
  v119 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  if ( v212 != 0.0 )
  {
    v120 = (*(_DWORD *)LODWORD(v212))-- == 1;
    if ( v120 )
    {
      v121 = (const vostok::render::hw_buffer_pool_range *)(LODWORD(v118) + 4);
      v120 = *(_DWORD *)(LODWORD(v118) + 4) == 0;
      v210 = (vostok::render::material_effects_instance_cook_data *)(LODWORD(v118) + 4);
      if ( v120 )
      {
        v122 = *(_DWORD *)(LODWORD(v118) + 20);
        if ( *(_DWORD *)(LODWORD(v118) + 28) == 1 )
          v119->m_total_index_buffers_size -= v122;
        else
          v119->m_total_vertex_buffers_size -= v122;
      }
      else
      {
        if ( *(_DWORD *)(LODWORD(v118) + 28) == 1 && v119->m_indices_pool )
        {
          vostok::render::hw_buffer_pool::deallocate(v121, v131);
          v121 = (const vostok::render::hw_buffer_pool_range *)v210;
        }
        if ( !*(_DWORD *)(LODWORD(v118) + 28) && v119->m_vertices_pool )
          vostok::render::hw_buffer_pool::deallocate(v121, v131);
      }
    }
  }
  v123 = v211;
  if ( v211 != 0.0 )
  {
    v120 = (*(_DWORD *)LODWORD(v211))-- == 1;
    if ( v120 )
    {
      v124 = (const vostok::render::hw_buffer_pool_range *)(LODWORD(v123) + 4);
      v120 = *(_DWORD *)(LODWORD(v123) + 4) == 0;
      v210 = (vostok::render::material_effects_instance_cook_data *)(LODWORD(v123) + 4);
      if ( v120 )
      {
        v125 = *(_DWORD *)(LODWORD(v123) + 20);
        if ( *(_DWORD *)(LODWORD(v123) + 28) == 1 )
          v119->m_total_index_buffers_size -= v125;
        else
          v119->m_total_vertex_buffers_size -= v125;
      }
      else
      {
        if ( *(_DWORD *)(LODWORD(v123) + 28) == 1 && v119->m_indices_pool )
        {
          vostok::render::hw_buffer_pool::deallocate(v124, v131);
          v124 = (const vostok::render::hw_buffer_pool_range *)v210;
        }
        if ( !*(_DWORD *)(LODWORD(v123) + 28) )
        {
          if ( v119->m_vertices_pool )
            vostok::render::hw_buffer_pool::deallocate(v124, v131);
        }
      }
    }
  }
}
