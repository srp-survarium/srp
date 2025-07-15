void __userpurge vostok::render::user_render_surface_wire::load_from_chunk_data(
        vostok::render::user_render_surface_wire *this@<ecx>,
        vostok::render::material_effects_instance_cook_data *a2@<ebp>,
        vostok::memory::chunk_reader::chunk_type *a3@<edi>,
        vostok::memory::chunk_reader::chunk_type *a4@<esi>,
        vostok::memory::chunk_reader *chunk)
{
  vostok::render::user_render_surface_wire *v5; // edi
  unsigned int v6; // eax
  const unsigned __int8 *m_pointer; // ecx
  const unsigned __int8 *v8; // eax
  const unsigned __int8 *i; // edx
  int *v10; // eax
  bool v11; // zf
  const unsigned __int8 *v12; // eax
  vostok::memory::chunk_reader::chunk_type **v13; // esi
  void *v14; // esp
  void *v15; // esp
  void *v16; // esp
  vostok::memory::chunk_reader::chunk_type **v17; // ecx
  vostok::memory::chunk_reader::chunk_type **v18; // eax
  __int64 v19; // xmm0_8
  float v20; // edx
  unsigned int v21; // eax
  vostok::memory::chunk_reader::chunk_type **v22; // ecx
  float v23; // edx
  __int64 v24; // xmm0_8
  vostok::math::float3 *v25; // eax
  __int64 v26; // xmm0_8
  float z; // eax
  float v28; // xmm4_4
  vostok::math::float3 *v29; // eax
  float y; // xmm1_4
  float v31; // xmm2_4
  vostok::memory::chunk_reader::chunk_type **v32; // eax
  float v33; // edx
  vostok::math::float3 *v34; // eax
  float v35; // xmm1_4
  float v36; // xmm2_4
  vostok::memory::chunk_reader::chunk_type **v37; // eax
  float v38; // xmm1_4
  float v39; // ecx
  float v40; // xmm2_4
  vostok::math::float3 *v41; // eax
  float v42; // xmm4_4
  float v43; // xmm5_4
  vostok::memory::chunk_reader::chunk_type **v44; // esi
  float v45; // xmm1_4
  float v46; // xmm2_4
  float v47; // xmm3_4
  float v48; // eax
  vostok::render::user_render_surface_wire *v49; // eax
  float v50; // ecx
  float v51; // edx
  float v52; // ecx
  float v53; // edx
  float v54; // ecx
  float v55; // edx
  float v56; // xmm2_4
  float v57; // xmm1_4
  float v58; // eax
  float v59; // xmm2_4
  float v60; // xmm1_4
  float v61; // ecx
  float v62; // xmm1_4
  float v63; // xmm2_4
  float v64; // xmm6_4
  float v65; // xmm2_4
  float v66; // xmm7_4
  float v67; // edx
  float v68; // xmm3_4
  float v69; // xmm4_4
  float v70; // xmm5_4
  float v71; // xmm6_4
  float v72; // xmm2_4
  float v73; // xmm1_4
  float v74; // xmm4_4
  float v75; // xmm5_4
  float v76; // xmm7_4
  float v77; // xmm3_4
  float v78; // xmm2_4
  float v79; // xmm4_4
  float v80; // xmm1_4
  float v81; // xmm5_4
  float v82; // xmm6_4
  float v83; // xmm7_4
  float v84; // eax
  vostok::memory::chunk_reader::chunk_type *v85; // ecx
  float v86; // xmm1_4
  __int64 v87; // xmm0_8
  float v88; // edx
  float v89; // xmm1_4
  float v90; // eax
  const char *path; // ecx
  float v92; // xmm2_4
  vostok::resources::class_id_enum id; // edx
  long double v94; // st7
  vostok::render::user_render_surface_wire *v95; // edx
  unsigned int v96; // eax
  __int16 v97; // dx
  vostok::render::untyped_buffer *v98; // eax
  unsigned int v99; // ecx
  survarium::options_tab *v100; // eax
  const vostok::variant<32> *v101; // eax
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v103; // esi
  vostok::render::res_declaration *declaration; // eax
  vostok::render::res_declaration *v105; // ecx
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v107; // ecx
  vostok::render::res_geometry *m_object; // eax
  vostok::render::enum_vertex_input_type *v109; // eax
  char *v110; // esi
  void (__cdecl *v111)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::render::res_declaration *v112; // eax
  vostok::render::res_state *v113; // edi
  vostok::render::res_state *v114; // edi
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::user_render_surface,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,char *>,boost::_bi::list4<boost::_bi::value<vostok::render::user_render_surface_wire *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>,boost::_bi::value<char *> > > v115; // [esp-14h] [ebp-3ECh]
  vostok::memory::chunk_reader::chunk_type *v116[2]; // [esp+4h] [ebp-3D4h] BYREF
  const char *v117; // [esp+Ch] [ebp-3CCh]
  int *v118; // [esp+10h] [ebp-3C8h]
  int *v119; // [esp+14h] [ebp-3C4h]
  _BYTE v120[256]; // [esp+18h] [ebp-3C0h] BYREF
  int v121; // [esp+118h] [ebp-2C0h] BYREF
  vostok::math::float3 v122; // [esp+120h] [ebp-2B8h] BYREF
  vostok::math::float3 v123; // [esp+12Ch] [ebp-2ACh] BYREF
  vostok::math::float3 v124; // [esp+138h] [ebp-2A0h] BYREF
  _DWORD v125[2]; // [esp+144h] [ebp-294h] BYREF
  vostok::memory::chunk_reader::chunk_type **v126; // [esp+14Ch] [ebp-28Ch] BYREF
  _DWORD *v127; // [esp+16Ch] [ebp-26Ch]
  int v128; // [esp+170h] [ebp-268h]
  __int64 v129; // [esp+174h] [ebp-264h]
  vostok::math::float3 v130; // [esp+180h] [ebp-258h] BYREF
  vostok::math::float3 v131; // [esp+190h] [ebp-248h] BYREF
  vostok::math::float3 v132; // [esp+19Ch] [ebp-23Ch] BYREF
  vostok::math::float3_pod v133; // [esp+1A8h] [ebp-230h] BYREF
  vostok::math::float3 v134; // [esp+1B4h] [ebp-224h] BYREF
  vostok::math::float3 v135; // [esp+1C0h] [ebp-218h] BYREF
  __int64 v136; // [esp+1CCh] [ebp-20Ch]
  float v137; // [esp+1D4h] [ebp-204h]
  __int64 v138; // [esp+1D8h] [ebp-200h]
  float v139; // [esp+1E0h] [ebp-1F8h]
  __int64 v140; // [esp+1E4h] [ebp-1F4h]
  float v141; // [esp+1ECh] [ebp-1ECh]
  __int64 v142; // [esp+1F0h] [ebp-1E8h]
  float v143; // [esp+1F8h] [ebp-1E0h]
  __int64 v144; // [esp+1FCh] [ebp-1DCh]
  float v145; // [esp+204h] [ebp-1D4h]
  __int64 v146; // [esp+208h] [ebp-1D0h]
  float v147; // [esp+210h] [ebp-1C8h]
  __int64 v148; // [esp+214h] [ebp-1C4h]
  float v149; // [esp+21Ch] [ebp-1BCh]
  __int64 v150; // [esp+220h] [ebp-1B8h]
  float v151; // [esp+228h] [ebp-1B0h]
  __int64 v152; // [esp+22Ch] [ebp-1ACh]
  float v153; // [esp+234h] [ebp-1A4h]
  __int64 v154; // [esp+238h] [ebp-1A0h]
  float v155; // [esp+240h] [ebp-198h]
  __int64 v156; // [esp+244h] [ebp-194h]
  float v157; // [esp+24Ch] [ebp-18Ch]
  float v158; // [esp+250h] [ebp-188h]
  vostok::memory::chunk_reader::chunk_type *v159; // [esp+254h] [ebp-184h]
  float v160; // [esp+258h] [ebp-180h]
  float v161; // [esp+25Ch] [ebp-17Ch]
  float v162; // [esp+260h] [ebp-178h]
  float v163; // [esp+264h] [ebp-174h]
  unsigned int v164; // [esp+268h] [ebp-170h]
  float v165; // [esp+26Ch] [ebp-16Ch]
  float v166; // [esp+270h] [ebp-168h]
  float v167; // [esp+274h] [ebp-164h]
  float v168; // [esp+278h] [ebp-160h]
  float v169; // [esp+27Ch] [ebp-15Ch]
  float v170; // [esp+280h] [ebp-158h]
  float v171; // [esp+284h] [ebp-154h]
  float v172; // [esp+288h] [ebp-150h]
  float v173; // [esp+28Ch] [ebp-14Ch]
  float v174; // [esp+290h] [ebp-148h]
  float v175; // [esp+294h] [ebp-144h]
  float v176; // [esp+298h] [ebp-140h]
  float v177; // [esp+29Ch] [ebp-13Ch]
  float v178; // [esp+2A0h] [ebp-138h]
  float v179; // [esp+2A4h] [ebp-134h]
  float v180; // [esp+2A8h] [ebp-130h]
  vostok::memory::chunk_reader::chunk_type **v181; // [esp+2ACh] [ebp-12Ch]
  float v182; // [esp+2B0h] [ebp-128h]
  float v183; // [esp+2B4h] [ebp-124h]
  float v184; // [esp+2B8h] [ebp-120h]
  unsigned int v185; // [esp+2BCh] [ebp-11Ch]
  float v186; // [esp+2C0h] [ebp-118h]
  float v187; // [esp+2C4h] [ebp-114h]
  float v188; // [esp+2C8h] [ebp-110h]
  vostok::render::user_render_surface_wire *v189; // [esp+2CCh] [ebp-10Ch]
  __int64 v190; // [esp+2D0h] [ebp-108h]
  vostok::memory::chunk_reader::chunk_type *v191; // [esp+2D8h] [ebp-100h]
  __int64 v192; // [esp+2DCh] [ebp-FCh]
  vostok::memory::chunk_reader::chunk_type *v193; // [esp+2E4h] [ebp-F4h]
  __int64 v194; // [esp+2E8h] [ebp-F0h]
  vostok::memory::chunk_reader::chunk_type *v195; // [esp+2F0h] [ebp-E8h]
  __int64 v196; // [esp+2F4h] [ebp-E4h]
  vostok::memory::chunk_reader::chunk_type *v197; // [esp+2FCh] [ebp-DCh]
  __int64 v198; // [esp+300h] [ebp-D8h]
  vostok::memory::chunk_reader::chunk_type *v199; // [esp+308h] [ebp-D0h]
  __int64 v200; // [esp+30Ch] [ebp-CCh]
  vostok::memory::chunk_reader::chunk_type *v201; // [esp+314h] [ebp-C4h]
  vostok::math::float3_pod v202; // [esp+318h] [ebp-C0h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> v203; // [esp+324h] [ebp-B4h] BYREF
  __int16 v204; // [esp+344h] [ebp-94h]
  __int16 v205; // [esp+346h] [ebp-92h]
  vostok::math::float3_pod v206; // [esp+350h] [ebp-88h] BYREF
  vostok::memory::chunk_reader::chunk_type **v207; // [esp+35Ch] [ebp-7Ch]
  unsigned int v208; // [esp+360h] [ebp-78h]
  float v209; // [esp+364h] [ebp-74h]
  float v210; // [esp+368h] [ebp-70h]
  float v211; // [esp+36Ch] [ebp-6Ch]
  vostok::math::float3_pod v212; // [esp+370h] [ebp-68h] BYREF
  vostok::resources::request v213; // [esp+37Ch] [ebp-5Ch] BYREF
  float v214; // [esp+384h] [ebp-54h]
  __int64 v215; // [esp+388h] [ebp-50h]
  float v216; // [esp+390h] [ebp-48h]
  __int64 v217; // [esp+394h] [ebp-44h]
  float v218; // [esp+39Ch] [ebp-3Ch]
  vostok::memory::chunk_reader::chunk_type **v219; // [esp+3A0h] [ebp-38h]
  vostok::render::user_render_surface_wire *v220; // [esp+3A4h] [ebp-34h]
  unsigned int v221; // [esp+3A8h] [ebp-30h]
  const vostok::variant<32> *v222; // [esp+3ACh] [ebp-2Ch] BYREF
  __int64 v223; // [esp+3B0h] [ebp-28h]
  float v224; // [esp+3B8h] [ebp-20h]
  float v225; // [esp+3BCh] [ebp-1Ch]
  vostok::memory::chunk_reader::chunk_type **v226; // [esp+3C0h] [ebp-18h]
  vostok::memory::chunk_reader::chunk_type **v227; // [esp+3C4h] [ebp-14h]
  float v228; // [esp+3C8h] [ebp-10h]
  vostok::render::material_effects_instance_cook_data *cook_data; // [esp+3CCh] [ebp-Ch]
  void *v230; // [esp+3D0h] [ebp-8h]
  void *retaddr; // [esp+3D8h] [ebp+0h]

  cook_data = a2;
  v230 = retaddr;
  v116[1] = a4;
  v116[0] = a3;
  v5 = this;
  *((_DWORD *)&v115.l_ + 3) = &v222;
  v220 = this;
  this->m_vertex_input_type = wires_vertex_input_type;
  v6 = vostok::memory::chunk_reader::chunk_size(
         (vostok::memory::chunk_reader *)2,
         *((const unsigned int *)&v115.l_ + 3),
         v116[0]);
  m_pointer = chunk->m_reader.m_pointer;
  v8 = &m_pointer[v6];
  for ( i = m_pointer; i != v8; ++i )
  {
    if ( !*i )
      break;
  }
  v117 = v120;
  v118 = (int *)v120;
  v119 = &v121;
  v120[0] = 0;
  v227 = (vostok::memory::chunk_reader::chunk_type **)m_pointer;
  if ( m_pointer )
  {
    v10 = v118;
    if ( *m_pointer )
    {
      do
      {
        if ( v10 >= v119 )
          break;
        *(_BYTE *)v10 = *(_BYTE *)v227;
        v10 = (int *)((char *)v118 + 1);
        v118 = (int *)((char *)v118 + 1);
        v11 = *((_BYTE *)v227 + 1) == 0;
        v227 = (vostok::memory::chunk_reader::chunk_type **)((char *)v227 + 1);
      }
      while ( !v11 );
    }
    *(_BYTE *)v10 = 0;
  }
  v214 = *(float *)(i + 1);
  vostok::memory::chunk_reader::chunk_size((vostok::memory::chunk_reader *)3, (const unsigned int)&v222, v116[0]);
  v12 = chunk->m_reader.m_pointer;
  v216 = 0.0;
  v12 += 4;
  v215 = 0;
  *(_QWORD *)&v5->m_aabbox.max.x = 0;
  *(_QWORD *)&v5->m_aabbox.min.x = 0;
  v5->m_aabbox.max.z = 0.0;
  v5->m_aabbox.min.z = 0.0;
  v13 = (vostok::memory::chunk_reader::chunk_type **)*((_DWORD *)v12 - 1);
  HIDWORD(v215) = v12;
  v208 = (unsigned int)v13 - 1;
  v221 = 18 * ((_DWORD)v13 - 1);
  v207 = v13;
  v5->m_render_geometry.vertex_count = 3 * (_DWORD)v13;
  v14 = alloca(12 * (_DWORD)v13);
  v227 = v116;
  v185 = 168 * (_DWORD)v13;
  v15 = alloca(168 * (_DWORD)v13);
  v219 = v116;
  v222 = (const vostok::variant<32> *)(2 * v221);
  v16 = alloca(2 * v221);
  v17 = v116;
  v189 = (vostok::render::user_render_surface_wire *)v116;
  v181 = v116;
  if ( v13 )
  {
    v18 = v227;
    v226 = v13;
    do
    {
      v19 = *(_QWORD *)HIDWORD(v215);
      v20 = *(float *)(HIDWORD(v215) + 8);
      HIDWORD(v215) += 12;
      *(_QWORD *)v18 = v19;
      *((float *)v18 + 2) = v20;
      v18 += 3;
      v11 = v226 == (vostok::memory::chunk_reader::chunk_type **)1;
      v226 = (vostok::memory::chunk_reader::chunk_type **)((char *)v226 - 1);
      v206.z = v20;
    }
    while ( !v11 );
  }
  v21 = 0;
  v225 = 0.0;
  if ( v13 )
  {
    v22 = v227 - 1;
    memset(&v131, 0, sizeof(v131));
    memset(&v134, 0, sizeof(v134));
    memset(&v135, 0, sizeof(v135));
    memset(&v132, 0, sizeof(v132));
    v159 = 0;
    v214 = v214 * 0.5;
    v177 = v214;
    v167 = FLOAT_0_5;
    *(float *)&v213.id = FLOAT_0_1;
    v226 = v227 - 1;
    v227 = v219 + 18;
    while ( 1 )
    {
      v23 = *((float *)v22 + 3);
      v217 = *(_QWORD *)(v22 + 1);
      v218 = v23;
      v164 = v21 + 1;
      if ( (vostok::memory::chunk_reader::chunk_type **)(v21 + 1) == v13 )
      {
        *(float *)&v136 = *((float *)v22 + 1) - *((float *)v22 - 2);
        *((float *)&v136 + 1) = *((float *)v22 + 2) - *((float *)v22 - 1);
        v137 = *((float *)v22 + 3) - *(float *)v22;
        v24 = v136;
        v202.z = v137;
      }
      else
      {
        *(float *)&v156 = *((float *)v22 + 4) - *((float *)v22 + 1);
        *((float *)&v156 + 1) = *((float *)v22 + 5) - *((float *)v22 + 2);
        v157 = *((float *)v22 + 6) - *((float *)v22 + 3);
        v24 = v156;
        v202.z = v157;
      }
      *(_QWORD *)&v202.x = v24;
      v25 = vostok::math::normalize_safe(&v202, &v123, &v131);
      v26 = *(_QWORD *)&v25->x;
      z = v25->z;
      v223 = v26;
      v224 = z;
      v160 = (float)(*((float *)&v26 + 1) * 0.0) - z;
      v161 = (float)(z * 0.0) - (float)(*(float *)&v26 * 0.0);
      v162 = *(float *)&v26 - (float)(*((float *)&v26 + 1) * 0.0);
      v228 = sqrtf((float)((float)(v160 * v160) + (float)(v162 * v162)) + (float)(v161 * v161));
      *(float *)&v26 = (float)(*(float *)&clear_value / v228) * v162;
      v28 = (float)(*(float *)&clear_value / v228) * v161;
      v209 = (float)(*(float *)&clear_value / v228) * v160;
      v171 = (float)(v28 * v224) - (float)(*(float *)&v26 * *((float *)&v223 + 1));
      v211 = *(float *)&v26;
      v210 = v28;
      v172 = (float)(*(float *)&v26 * *(float *)&v223) - (float)(v224 * v209);
      v173 = (float)(*((float *)&v223 + 1) * v209) - (float)(v28 * *(float *)&v223);
      v228 = sqrtf((float)((float)(v171 * v171) + (float)(v173 * v173)) + (float)(v172 * v172));
      v212.x = (float)(*(float *)&clear_value / v228) * v171;
      v212.z = (float)(*(float *)&clear_value / v228) * v173;
      v212.y = (float)(*(float *)&clear_value / v228) * v172;
      v165 = v214;
      v29 = vostok::math::normalize_safe(&v212, &v124, &v134);
      *(float *)&v26 = v29->x;
      y = v29->y;
      v31 = v29->z;
      v32 = v227;
      *((float *)&v138 + 1) = *((float *)&v217 + 1) + (float)(y * v165);
      v139 = v218 + (float)(v31 * v165);
      v33 = v139;
      *(float *)&v138 = *(float *)&v217 + (float)(*(float *)&v26 * v165);
      *((_QWORD *)v227 - 9) = v138;
      v163 = v214;
      v133.x = v209 - v212.x;
      *(float *)&v26 = v210 - v212.y;
      *((float *)v32 - 16) = v33;
      LODWORD(v133.y) = v26;
      v133.z = v211 - v212.z;
      v34 = vostok::math::normalize_safe(&v133, &v122, &v135);
      *(float *)&v26 = v34->x;
      v35 = v34->y;
      v36 = v34->z;
      v37 = v227;
      *(float *)&v140 = (float)(*(float *)&v26 * v163) + *(float *)&v217;
      *((float *)&v140 + 1) = (float)(v35 * v163) + *((float *)&v217 + 1);
      v38 = v210;
      v141 = (float)(v36 * v163) + v218;
      v39 = v141;
      v40 = v211;
      *((_QWORD *)v227 - 2) = v140;
      *(float *)&v26 = v209;
      *((float *)v37 - 2) = v39;
      v206.x = (float)-*(float *)&v26 - v212.x;
      v206.y = (float)-v38 - v212.y;
      v206.z = (float)-v40 - v212.z;
      v41 = vostok::math::normalize_safe(&v206, &v130, &v132);
      v42 = *((float *)&v217 + 1);
      v43 = v218;
      v44 = v227;
      v45 = v41->y * v177;
      v46 = v41->z * v177;
      v47 = *(float *)&v217;
      *(float *)&v150 = (float)(v177 * v41->x) + *(float *)&v217;
      *((float *)&v150 + 1) = v45 + *((float *)&v217 + 1);
      v151 = v46 + v218;
      v48 = v46 + v218;
      *((_QWORD *)v227 + 5) = v150;
      *((float *)v44 + 12) = v48;
      v49 = v220;
      LODWORD(v192) = *((float *)v44 - 18) <= v220->m_aabbox.min.x
                    ? *(v44 - 18)
                    : (vostok::memory::chunk_reader::chunk_type *)LODWORD(v220->m_aabbox.min.x);
      HIDWORD(v192) = *((float *)v44 - 17) <= v220->m_aabbox.min.y
                    ? *(v44 - 17)
                    : (vostok::memory::chunk_reader::chunk_type *)LODWORD(v220->m_aabbox.min.y);
      v193 = *((float *)v44 - 16) <= v220->m_aabbox.min.z
           ? *(v44 - 16)
           : (vostok::memory::chunk_reader::chunk_type *)LODWORD(v220->m_aabbox.min.z);
      v50 = *(float *)&v193;
      *(_QWORD *)&v220->m_aabbox.min.x = v192;
      v49->m_aabbox.min.z = v50;
      LODWORD(v198) = v49->m_aabbox.max.x <= *((float *)v44 - 18)
                    ? *(v44 - 18)
                    : (vostok::memory::chunk_reader::chunk_type *)LODWORD(v49->m_aabbox.max.x);
      HIDWORD(v198) = v49->m_aabbox.max.y <= *((float *)v44 - 17)
                    ? *(v44 - 17)
                    : (vostok::memory::chunk_reader::chunk_type *)LODWORD(v49->m_aabbox.max.y);
      v199 = v49->m_aabbox.max.z <= *((float *)v44 - 16)
           ? *(v44 - 16)
           : (vostok::memory::chunk_reader::chunk_type *)LODWORD(v49->m_aabbox.max.z);
      v51 = *(float *)&v199;
      *(_QWORD *)&v49->m_aabbox.max.x = v198;
      v49->m_aabbox.max.z = v51;
      LODWORD(v194) = *((float *)v44 - 4) <= v49->m_aabbox.min.x
                    ? *(v44 - 4)
                    : (vostok::memory::chunk_reader::chunk_type *)LODWORD(v49->m_aabbox.min.x);
      HIDWORD(v194) = *((float *)v44 - 3) <= v49->m_aabbox.min.y
                    ? *(v44 - 3)
                    : (vostok::memory::chunk_reader::chunk_type *)LODWORD(v49->m_aabbox.min.y);
      v195 = *((float *)v44 - 2) <= v49->m_aabbox.min.z
           ? *(v44 - 2)
           : (vostok::memory::chunk_reader::chunk_type *)LODWORD(v49->m_aabbox.min.z);
      v52 = *(float *)&v195;
      *(_QWORD *)&v49->m_aabbox.min.x = v194;
      v49->m_aabbox.min.z = v52;
      LODWORD(v190) = v49->m_aabbox.max.x <= *((float *)v44 - 4)
                    ? *(v44 - 4)
                    : (vostok::memory::chunk_reader::chunk_type *)LODWORD(v49->m_aabbox.max.x);
      HIDWORD(v190) = v49->m_aabbox.max.y <= *((float *)v44 - 3)
                    ? *(v44 - 3)
                    : (vostok::memory::chunk_reader::chunk_type *)LODWORD(v49->m_aabbox.max.y);
      v191 = v49->m_aabbox.max.z <= *((float *)v44 - 2)
           ? *(v44 - 2)
           : (vostok::memory::chunk_reader::chunk_type *)LODWORD(v49->m_aabbox.max.z);
      v53 = *(float *)&v191;
      *(_QWORD *)&v49->m_aabbox.max.x = v190;
      v49->m_aabbox.max.z = v53;
      LODWORD(v196) = *((float *)v44 + 10) <= v49->m_aabbox.min.x
                    ? v44[10]
                    : (vostok::memory::chunk_reader::chunk_type *)LODWORD(v49->m_aabbox.min.x);
      HIDWORD(v196) = *((float *)v44 + 11) <= v49->m_aabbox.min.y
                    ? v44[11]
                    : (vostok::memory::chunk_reader::chunk_type *)LODWORD(v49->m_aabbox.min.y);
      v197 = *((float *)v44 + 12) <= v49->m_aabbox.min.z
           ? v44[12]
           : (vostok::memory::chunk_reader::chunk_type *)LODWORD(v49->m_aabbox.min.z);
      v54 = *(float *)&v197;
      *(_QWORD *)&v49->m_aabbox.min.x = v196;
      v49->m_aabbox.min.z = v54;
      LODWORD(v200) = v49->m_aabbox.max.x <= *((float *)v44 + 10)
                    ? v44[10]
                    : (vostok::memory::chunk_reader::chunk_type *)LODWORD(v49->m_aabbox.max.x);
      HIDWORD(v200) = v49->m_aabbox.max.y <= *((float *)v44 + 11)
                    ? v44[11]
                    : (vostok::memory::chunk_reader::chunk_type *)LODWORD(v49->m_aabbox.max.y);
      v201 = v49->m_aabbox.max.z <= *((float *)v44 + 12)
           ? v44[12]
           : (vostok::memory::chunk_reader::chunk_type *)LODWORD(v49->m_aabbox.max.z);
      v55 = *(float *)&v201;
      *(_QWORD *)&v49->m_aabbox.max.x = v200;
      v49->m_aabbox.max.z = v55;
      v56 = *((float *)v44 - 16);
      v57 = *((float *)v44 - 17);
      v186 = *((float *)v44 - 18) - v47;
      v187 = v57 - v42;
      v188 = v56 - v43;
      v228 = sqrtf((float)((float)(v186 * v186) + (float)(v188 * v188)) + (float)(v187 * v187));
      *(float *)&v142 = (float)(*(float *)&clear_value / v228) * v186;
      v143 = (float)(*(float *)&clear_value / v228) * v188;
      v58 = v143;
      *((float *)&v142 + 1) = (float)(*(float *)&clear_value / v228) * v187;
      *(_QWORD *)(v44 - 15) = v142;
      *((float *)v44 - 13) = v58;
      v59 = *((float *)v44 - 2) - v218;
      v60 = *((float *)v44 - 3) - *((float *)&v217 + 1);
      v182 = *((float *)v44 - 4) - *(float *)&v217;
      v183 = v60;
      v184 = v59;
      v228 = sqrtf((float)((float)(v182 * v182) + (float)(v59 * v59)) + (float)(v60 * v60));
      *(float *)&v146 = v182 * (float)(*(float *)&clear_value / v228);
      *((float *)&v146 + 1) = v183 * (float)(*(float *)&clear_value / v228);
      v147 = v184 * (float)(*(float *)&clear_value / v228);
      v61 = v147;
      *(_QWORD *)(v44 - 1) = v146;
      *((float *)v44 + 1) = v61;
      v62 = *((float *)v44 + 11) - *((float *)&v217 + 1);
      v63 = *((float *)v44 + 12);
      v178 = *((float *)v44 + 10) - *(float *)&v217;
      v179 = v62;
      v180 = v63 - v218;
      v228 = sqrtf((float)((float)(v180 * v180) + (float)(v62 * v62)) + (float)(v178 * v178));
      v64 = v224;
      v65 = *((float *)&v223 + 1);
      v66 = *(float *)&v223;
      *(float *)&v154 = v178 * (float)(*(float *)&clear_value / v228);
      *((float *)&v154 + 1) = v179 * (float)(*(float *)&clear_value / v228);
      v155 = v180 * (float)(*(float *)&clear_value / v228);
      v67 = v155;
      *(_QWORD *)(v44 + 13) = v154;
      *((float *)v44 + 15) = v67;
      v68 = *((float *)v44 - 14);
      v69 = *((float *)v44 - 13);
      v70 = *((float *)v44 - 15);
      v176 = (float)(v65 * v70) - (float)(v66 * v68);
      v175 = (float)(v66 * v69) - (float)(v64 * v70);
      v174 = (float)(v64 * v68) - (float)(v65 * v69);
      v228 = sqrtf((float)((float)(v176 * v176) + (float)(v175 * v175)) + (float)(v174 * v174));
      v71 = v224;
      v72 = *((float *)&v223 + 1);
      *(float *)&v152 = v174 * (float)(*(float *)&clear_value / v228);
      *((float *)&v152 + 1) = v175 * (float)(*(float *)&clear_value / v228);
      v73 = v176 * (float)(*(float *)&clear_value / v228);
      *((_QWORD *)v44 - 6) = v152;
      v153 = v73;
      *((float *)v44 - 10) = v73;
      v74 = *((float *)v44 + 1);
      v75 = *((float *)v44 - 1);
      v76 = *(float *)&v223 * *(float *)v44;
      v168 = (float)(v71 * *(float *)v44) - (float)(v72 * v74);
      v169 = (float)(*(float *)&v223 * v74) - (float)(v71 * v75);
      v170 = (float)(v72 * v75) - v76;
      v228 = sqrtf((float)((float)(v168 * v168) + (float)(v170 * v170)) + (float)(v169 * v169));
      v77 = v224;
      v78 = *((float *)&v223 + 1);
      v79 = *(float *)&v223;
      *(float *)&v148 = v168 * (float)(*(float *)&clear_value / v228);
      *((float *)&v148 + 1) = v169 * (float)(*(float *)&clear_value / v228);
      v80 = v170 * (float)(*(float *)&clear_value / v228);
      *((_QWORD *)v44 + 1) = v148;
      v149 = v80;
      *((float *)v44 + 4) = v80;
      v81 = *((float *)v44 + 14);
      v82 = *((float *)v44 + 15);
      v83 = *((float *)v44 + 13);
      *(float *)&v215 = (float)(v77 * v81) - (float)(v78 * v82);
      *((float *)&v215 + 1) = (float)(v79 * v82) - (float)(v77 * v83);
      v216 = (float)(v78 * v83) - (float)(v79 * v81);
      v228 = sqrtf(
               (float)((float)(*(float *)&v215 * *(float *)&v215) + (float)(v216 * v216))
             + (float)(*((float *)&v215 + 1) * *((float *)&v215 + 1)));
      *(float *)&v144 = *(float *)&v215 * (float)(*(float *)&clear_value / v228);
      *((float *)&v144 + 1) = *((float *)&v215 + 1) * (float)(*(float *)&clear_value / v228);
      v84 = v224;
      v85 = v159;
      v86 = v216 * (float)(*(float *)&clear_value / v228);
      *((_QWORD *)v44 + 8) = v144;
      v87 = v223;
      v145 = v86;
      *((float *)v44 + 18) = v86;
      *(_QWORD *)(v44 - 9) = v87;
      *((float *)v44 - 7) = v84;
      *(_QWORD *)(v44 + 5) = v87;
      *((float *)v44 + 7) = v84;
      *(_QWORD *)(v44 + 19) = v87;
      v158 = v225;
      v166 = v225;
      v88 = v225;
      *(float *)&v213.path = v225;
      *(float *)&v87 = v202.x;
      *((float *)v44 + 21) = v84;
      v89 = *(float *)&v87 * *(float *)&v87;
      *(float *)&v87 = v202.z;
      *((float *)v44 - 6) = v158;
      v90 = v167;
      *(v44 - 5) = v85;
      path = v213.path;
      v92 = *(float *)&v87 * *(float *)&v87;
      *(float *)&v87 = v202.y;
      *((float *)v44 + 8) = v88;
      id = v213.id;
      *((float *)v44 + 9) = v90;
      v44[22] = (vostok::memory::chunk_reader::chunk_type *)path;
      v44[23] = (vostok::memory::chunk_reader::chunk_type *)id;
      v94 = sqrtf((float)(v89 + v92) + (float)(*(float *)&v87 * *(float *)&v87));
      v21 = v164;
      v226 += 3;
      v225 = v94 + v225;
      v227 = v44 + 42;
      if ( v164 >= (unsigned int)v207 )
        break;
      v22 = v226;
      v13 = v207;
    }
    v5 = v220;
    v17 = v181;
  }
  v203.vtable = (boost::detail::function::vtable_base *)&_sbh_sizeHeaderList;
  HIWORD((&v203.vtable)[1]) = 1;
  LOWORD((&v203.vtable)[1]) = 3;
  *(_QWORD *)&v203.functor.obj_ptr = 0x5000000030004LL;
  *((_QWORD *)&v203.functor.data + 1) = 0x5000300000002LL;
  *((_QWORD *)&v203.functor.data + 2) = 0x2000100040002LL;
  v205 = 4;
  LOWORD(v95) = 0;
  v204 = 5;
  v220 = 0;
  if ( v208 )
  {
    do
    {
      v96 = 0;
      v97 = 3 * (_WORD)v95;
      do
      {
        *(_WORD *)v17 = v97 + *((_WORD *)&v203.vtable + v96++);
        v17 = (vostok::memory::chunk_reader::chunk_type **)((char *)v17 + 2);
      }
      while ( v96 < 0x12 );
      v95 = (vostok::render::user_render_surface_wire *)((char *)&v220->__vftable + 1);
      v220 = v95;
    }
    while ( (unsigned int)v95 < v208 );
  }
  *(float *)&v98 = COERCE_FLOAT(
                     vostok::render::resource_manager::create_buffer(
                       v185,
                       (bool)v5,
                       (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                       v219,
                       enum_buffer_type_vertex,
                       (vostok::render::untyped_buffer *)1,
                       0));
  v225 = 0.0;
  if ( *(float *)&v98 != 0.0 )
  {
    ++v98->m_reference_count;
    v225 = *(float *)&v98;
  }
  v99 = v221;
  v100 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  *((_BYTE *)&v115.l_ + 12) = 0;
  v115.l_.a4_.t_ = 0;
  v5->m_render_geometry.primitive_count = v221 / 3;
  v115.l_.a3_.t_ = (vostok::render::material_effects_instance_cook_data *)1;
  v115.l_.a1_.t_ = v189;
  HIDWORD(v115.f_.f_) = v100;
  v101 = v222;
  v5->m_render_geometry.index_count = v99;
  buffer = vostok::render::resource_manager::create_buffer(
             (unsigned int)v101,
             (bool)v5,
             (vostok::render::resource_manager *)HIDWORD(v115.f_.f_),
             v115.l_.a1_.t_,
             (vostok::render::enum_buffer_type)v115.l_.a3_.t_,
             (vostok::render::untyped_buffer *)v115.l_.a4_.t_,
             *((bool *)&v115.l_ + 12));
  v103 = 0;
  v219 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v103 = buffer;
    v219 = (vostok::memory::chunk_reader::chunk_type **)buffer;
  }
  declaration = vostok::render::resource_manager::create_declaration(
                  5u,
                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                  (stlp_std::forward_iterator_tag *)layout_wire);
  v105 = 0;
  v221 = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    v105 = declaration;
    v221 = (unsigned int)declaration;
  }
  geometry = vostok::render::resource_manager::create_geometry(
               v105,
               (vostok::render::untyped_buffer *)LODWORD(v225),
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               0x38u,
               v103);
  v107 = 0;
  if ( geometry )
  {
    ++geometry->m_reference_count;
    v107 = geometry;
  }
  m_object = v5->m_render_geometry.geom.m_object;
  v5->m_render_geometry.geom.m_object = v107;
  if ( m_object )
  {
    v11 = m_object->m_reference_count-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_object);
  }
  v109 = (vostok::render::enum_vertex_input_type *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                     (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                     0x10u);
  if ( v109 )
  {
    *v109 = v5->m_vertex_input_type;
    *((_DWORD *)v109 + 1) = 0;
    *((_DWORD *)v109 + 2) = 2;
    *((_BYTE *)v109 + 12) = 0;
    v226 = (vostok::memory::chunk_reader::chunk_type **)v109;
  }
  else
  {
    v226 = 0;
  }
  v127 = 0;
  v128 = 0;
  v128 = vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::get();
  v127 = v125;
  v126 = v226;
  v125[0] = &vostok::detail::concrete_type_helper<vostok::render::material_effects_instance_cook_data *>::`vftable';
  v110 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(
                   (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                   0x100u);
  memset((int)v110, 0, 0x100u);
  strcpy_s(v110, 0x100u, v117);
  LODWORD(v129) = vostok::render::user_render_surface::material_ready;
  HIDWORD(v129) = 0;
  *(_QWORD *)&v206.x = __PAIR64__((unsigned int)v226, (unsigned int)v5);
  v115.f_.f_ = (void (__thiscall *__ptr64)(vostok::render::user_render_surface *, vostok::resources::queries_result *, vostok::render::material_effects_instance_cook_data *, char *))v129;
  v115.l_.boost::_bi::storage3<boost::_bi::value<vostok::render::user_render_surface_wire *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *> > = (boost::_bi::storage3<boost::_bi::value<vostok::render::user_render_surface_wire *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *> >)__PAIR64__((unsigned int)v226, (unsigned int)v5);
  LODWORD(v130.y) = v110;
  v203.vtable = 0;
  *(_QWORD *)&v115.l_.a4_.t_ = *(_QWORD *)&v130.elements[1];
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::user_render_surface,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,char *>,boost::_bi::list4<boost::_bi::value<vostok::render::user_render_surface_wire *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>,boost::_bi::value<char *>>>>(
    0,
    (int)&v203,
    (int)v110,
    v115);
  v213.path = v117;
  v222 = (const vostok::variant<32> *)v125;
  v213.id = material_effects_instance_class;
  vostok::resources::query_resources(
    &v213,
    1u,
    &v203,
    (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
    &v222,
    0,
    assert_on_fail_true);
  if ( v203.vtable )
  {
    if ( ((int)v203.vtable & 1) == 0 )
    {
      v111 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v203.vtable & 0xFFFFFFFE);
      if ( v111 )
        v111(&v203.functor, &v203.functor, 2);
    }
    v203.vtable = 0;
  }
  if ( v127 )
  {
    (*(void (__thiscall **)(_DWORD *, vostok::memory::chunk_reader::chunk_type ***))(*v127 + 4))(v127, &v126);
    v127 = 0;
  }
  v112 = (vostok::render::res_declaration *)v221;
  if ( v221 )
  {
    v11 = (*(_DWORD *)v221)-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v112);
  }
  v113 = (vostok::render::res_state *)v219;
  if ( v219 )
  {
    v11 = *v219 == (vostok::memory::chunk_reader::chunk_type *)1;
    *v219 = (vostok::memory::chunk_reader::chunk_type *)((char *)*v219 - 1);
    if ( v11 )
      vostok::render::resource_manager::release(
        v113,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v114 = (vostok::render::res_state *)LODWORD(v225);
  if ( v225 != 0.0 )
  {
    v11 = (*(_DWORD *)LODWORD(v225))-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release(
        v114,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
}
