void __usercall btSoftBodyHelpers::Draw(
        float a1@<ebx>,
        int a2@<edi>,
        float a3@<esi>,
        btSoftBody *psb,
        btIDebugDraw *idraw,
        __int16 drawflags)
{
  float v6; // xmm0_4
  btSoftBody *v7; // esi
  float v8; // xmm2_4
  btSoftBody::Cluster **m_data; // eax
  btConvexHullComputer *v10; // ecx
  float v11; // xmm0_4
  int m_size; // ebx
  btVector3 *v13; // eax
  int v14; // eax
  btVector3 *p_m_x; // esi
  btVector3 **p_m_data; // edi
  btAlignedObjectArray<GrahamVector2> *v17; // ecx
  int v18; // esi
  float v19; // ebx
  float *v20; // eax
  float *v21; // edi
  float v22; // eax
  btAlignedObjectArray<GrahamVector2> *v23; // ecx
  btAlignedObjectArray<GrahamVector2> *v24; // ecx
  btAlignedObjectArray<GrahamVector2> *v25; // ecx
  btSoftBody::Anchor *v26; // ebx
  float *m_body; // eax
  float v28; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm6_4
  float v33; // xmm0_4
  unsigned int v34; // xmm2_4
  unsigned int v35; // xmm6_4
  const btVector3 *v36; // esi
  btIDebugDraw_vtbl *v37; // eax
  btSoftBody::Node *m_node; // ecx
  btSoftBody::Node *v39; // eax
  btSoftBody::Note *v40; // eax
  int v41; // esi
  float *m_coords; // edx
  float *v43; // ecx
  float v44; // xmm3_4
  float v45; // xmm1_4
  float v46; // xmm2_4
  btSoftBody::Joint *v47; // ebx
  int v48; // eax
  btSoftBody::Body *v49; // ecx
  btSoftBody::Body *v50; // ecx
  btSoftBody::Body *v51; // ecx
  float *v52; // eax
  float v53; // xmm1_4
  float v54; // xmm2_4
  float v55; // xmm3_4
  float v56; // xmm4_4
  btSoftBody::Body *v57; // ecx
  float *v58; // eax
  float v59; // xmm3_4
  float v60; // xmm2_4
  float v61; // xmm1_4
  float v62; // xmm4_4
  float v63; // xmm0_4
  float v64; // xmm4_4
  float v65; // xmm1_4
  float v66; // xmm0_4
  btIDebugDraw_vtbl *v67; // eax
  btIDebugDraw_vtbl *v68; // eax
  btIDebugDraw_vtbl *v69; // eax
  btIDebugDraw_vtbl *v70; // eax
  btSoftBody::Node *v71; // esi
  float v72; // xmm2_4
  btIDebugDraw_vtbl *v73; // eax
  float v74; // xmm2_4
  int v75; // xmm0_4
  float v76; // xmm2_4
  btIDebugDraw_vtbl *v77; // eax
  unsigned int v78; // xmm2_4
  int v79; // xmm1_4
  float v80; // xmm2_4
  float v81; // xmm2_4
  btIDebugDraw_vtbl *v82; // eax
  int v83; // esi
  btSoftBody::Link *v84; // eax
  float v85; // xmm5_4
  btSoftBody::Node *v86; // eax
  float v87; // xmm0_4
  float v88; // xmm2_4
  float v89; // xmm3_4
  float *m128_f32; // esi
  float v91; // xmm4_4
  btIDebugDraw_vtbl *v92; // eax
  float v93; // xmm0_4
  float v94; // xmm4_4
  unsigned int v95; // xmm2_4
  unsigned int v96; // xmm3_4
  float v97; // xmm0_4
  btIDebugDraw_vtbl *v98; // eax
  float v99; // xmm1_4
  char *v100; // esi
  float *v101; // eax
  float v102; // xmm0_4
  float v103; // xmm4_4
  float v104; // xmm3_4
  unsigned int v105; // xmm0_4
  float v106; // xmm6_4
  float v107; // xmm2_4
  float v108; // xmm0_4
  int v109; // eax
  float v110; // xmm4_4
  const btVector3 *v111; // eax
  float v112; // xmm2_4
  float v113; // xmm0_4
  float v114; // xmm4_4
  float v115; // xmm7_4
  float v116; // xmm2_4
  float v117; // xmm3_4
  float v118; // xmm4_4
  float v119; // xmm7_4
  float v120; // xmm2_4
  float v121; // xmm0_4
  float v122; // xmm7_4
  float v123; // xmm4_4
  btIDebugDraw_vtbl *v124; // eax
  float v125; // xmm4_4
  float v126; // xmm3_4
  float v127; // xmm5_4
  btIDebugDraw_vtbl *v128; // eax
  float v129; // xmm1_4
  btIDebugDraw_vtbl *v130; // eax
  float v131; // xmm2_4
  float v132; // xmm3_4
  float v133; // xmm0_4
  bool v134; // cc
  btSoftBody::Face *v135; // eax
  int v136; // esi
  int v137; // esi
  int v138; // esi
  float v139; // xmm4_4
  float v140; // xmm3_4
  btIDebugDraw_vtbl *v141; // eax
  btSoftBody::Tetra *v142; // eax
  int v143; // esi
  int v144; // esi
  int v145; // esi
  int v146; // esi
  float v147; // xmm2_4
  float v148; // xmm3_4
  float v149; // xmm4_4
  btIDebugDraw_vtbl *v150; // eax
  btIDebugDraw_vtbl *v151; // eax
  btIDebugDraw_vtbl *v152; // eax
  btIDebugDraw_vtbl *v153; // eax
  float *v154; // eax
  float v155; // xmm2_4
  float v156; // xmm3_4
  float v157; // xmm4_4
  unsigned int v158; // xmm1_4
  unsigned int v159; // xmm5_4
  btSoftBody::Body *v160; // ecx
  float *v161; // eax
  float v162; // xmm4_4
  float v163; // xmm3_4
  unsigned int v164; // xmm0_4
  float v165; // xmm5_4
  btSoftBody::Body *v166; // ecx
  const btTransform *v167; // eax
  btSoftBody::Body *v168; // ecx
  const btTransform *v169; // eax
  int v170; // [esp+C0h] [ebp-220h]
  float v171; // [esp+C4h] [ebp-21Ch]
  float v172; // [esp+C8h] [ebp-218h]
  float v173; // [esp+D8h] [ebp-208h]
  int v174; // [esp+D8h] [ebp-208h]
  int v175; // [esp+D8h] [ebp-208h]
  int v176; // [esp+D8h] [ebp-208h]
  int v177; // [esp+D8h] [ebp-208h]
  int v178; // [esp+D8h] [ebp-208h]
  int v179; // [esp+D8h] [ebp-208h]
  float v180; // [esp+D8h] [ebp-208h]
  int v181; // [esp+D8h] [ebp-208h]
  int v182; // [esp+D8h] [ebp-208h]
  int v183; // [esp+DCh] [ebp-204h]
  int v184; // [esp+DCh] [ebp-204h]
  int v185; // [esp+DCh] [ebp-204h]
  int v186; // [esp+DCh] [ebp-204h]
  int i; // [esp+DCh] [ebp-204h]
  int v188; // [esp+DCh] [ebp-204h]
  int v189; // [esp+DCh] [ebp-204h]
  int v190; // [esp+DCh] [ebp-204h]
  int v191; // [esp+DCh] [ebp-204h]
  float v192; // [esp+DCh] [ebp-204h]
  btVector3 v193; // [esp+E0h] [ebp-200h] BYREF
  float v194; // [esp+FCh] [ebp-1E4h]
  btVector3 v195; // [esp+100h] [ebp-1E0h] BYREF
  float v196; // [esp+118h] [ebp-1C8h]
  float v197; // [esp+11Ch] [ebp-1C4h]
  float v198; // [esp+120h] [ebp-1C0h] BYREF
  float v199; // [esp+124h] [ebp-1BCh]
  float v200; // [esp+128h] [ebp-1B8h]
  int v201; // [esp+12Ch] [ebp-1B4h]
  float v202; // [esp+130h] [ebp-1B0h] BYREF
  float v203; // [esp+134h] [ebp-1ACh]
  float v204; // [esp+138h] [ebp-1A8h]
  int v205; // [esp+13Ch] [ebp-1A4h]
  float v206; // [esp+140h] [ebp-1A0h] BYREF
  float v207; // [esp+144h] [ebp-19Ch]
  float v208; // [esp+148h] [ebp-198h]
  int v209; // [esp+14Ch] [ebp-194h]
  btVector3 v210; // [esp+150h] [ebp-190h] BYREF
  float v211; // [esp+16Ch] [ebp-174h]
  btVector3 v212; // [esp+170h] [ebp-170h] BYREF
  float v213; // [esp+180h] [ebp-160h] BYREF
  float v214; // [esp+184h] [ebp-15Ch]
  float v215; // [esp+188h] [ebp-158h]
  int v216; // [esp+18Ch] [ebp-154h]
  btVector3 v217; // [esp+190h] [ebp-150h] BYREF
  float v218; // [esp+1A8h] [ebp-138h]
  float v219; // [esp+1ACh] [ebp-134h]
  float v220; // [esp+1B0h] [ebp-130h] BYREF
  float v221; // [esp+1B4h] [ebp-12Ch]
  float v222; // [esp+1B8h] [ebp-128h]
  int v223; // [esp+1BCh] [ebp-124h]
  float v224; // [esp+1C4h] [ebp-11Ch]
  float v225; // [esp+1C8h] [ebp-118h]
  float v226; // [esp+1CCh] [ebp-114h]
  btVector3 v227; // [esp+1D0h] [ebp-110h] BYREF
  float coords; // [esp+1E0h] [ebp-100h] BYREF
  float v229; // [esp+1E4h] [ebp-FCh]
  float v230; // [esp+1E8h] [ebp-F8h]
  int v231; // [esp+1ECh] [ebp-F4h]
  float v232; // [esp+1F0h] [ebp-F0h]
  float v233; // [esp+1F4h] [ebp-ECh] BYREF
  float v234; // [esp+1F8h] [ebp-E8h]
  int v235; // [esp+1FCh] [ebp-E4h]
  float v236; // [esp+200h] [ebp-E0h]
  float v237; // [esp+204h] [ebp-DCh]
  float v238; // [esp+208h] [ebp-D8h] BYREF
  int v239; // [esp+20Ch] [ebp-D4h]
  float v240; // [esp+210h] [ebp-D0h]
  float v241; // [esp+214h] [ebp-CCh]
  float v242; // [esp+218h] [ebp-C8h]
  int v243; // [esp+21Ch] [ebp-C4h]
  float v244; // [esp+220h] [ebp-C0h] BYREF
  float v245; // [esp+224h] [ebp-BCh]
  float v246; // [esp+228h] [ebp-B8h]
  int v247; // [esp+22Ch] [ebp-B4h]
  btVector3 v248; // [esp+230h] [ebp-B0h] BYREF
  btVector3 v249; // [esp+240h] [ebp-A0h] BYREF
  float v250; // [esp+254h] [ebp-8Ch]
  float v251; // [esp+258h] [ebp-88h]
  float v252; // [esp+25Ch] [ebp-84h]
  btVector3 v253; // [esp+260h] [ebp-80h] BYREF
  char v254; // [esp+270h] [ebp-70h]
  float v255; // [esp+280h] [ebp-60h] BYREF
  float v256; // [esp+284h] [ebp-5Ch]
  float v257; // [esp+288h] [ebp-58h]
  int v258; // [esp+28Ch] [ebp-54h]
  float v259; // [esp+290h] [ebp-50h] BYREF
  float v260; // [esp+294h] [ebp-4Ch]
  float v261; // [esp+298h] [ebp-48h]
  int v262; // [esp+29Ch] [ebp-44h]
  _DWORD v263[4]; // [esp+2A0h] [ebp-40h] BYREF
  _DWORD v264[4]; // [esp+2B0h] [ebp-30h] BYREF
  _DWORD v265[4]; // [esp+2C0h] [ebp-20h] BYREF
  _DWORD v266[4]; // [esp+2D0h] [ebp-10h] BYREF

  v6 = s_bm_current_air_resistance;
  v172 = a1;
  v171 = a3;
  v7 = psb;
  v170 = a2;
  memset(v265, 0, sizeof(v265));
  v259 = s_bm_current_air_resistance;
  v260 = s_bm_current_air_resistance;
  v261 = s_bm_current_air_resistance;
  v262 = 0;
  *(float *)v263 = s_bm_current_air_resistance;
  memset(&v263[1], 0, 12);
  if ( (drawflags & 0x100) != 0 )
  {
    srand(0x70Eu);
    v183 = 0;
    if ( psb->m_clusters.m_size > 0 )
    {
      do
      {
        if ( v7->m_clusters.m_data[v183]->m_collide )
        {
          v173 = (float)(int)rand() * 0.000030518509;
          v194 = (float)(int)rand() * 0.000030518509;
          v8 = (float)(int)rand() * 0.000030518509;
          m_data = psb->m_clusters.m_data;
          v10 = (btConvexHullComputer *)v183;
          v11 = s_bm_current_air_resistance
              / fsqrt((float)((float)(v8 * v8) + (float)(v194 * v194)) + (float)(v173 * v173));
          v253.mVec128.m128_u64[1] = 0;
          v212.mVec128.m128_f32[2] = (float)(v11 * v173) * 0.75;
          v212.mVec128.m128_i32[3] = 0;
          v212.mVec128.m128_f32[0] = (float)(v11 * v8) * 0.75;
          v212.mVec128.m128_f32[1] = (float)(v11 * v194) * 0.75;
          v249.mVec128.m128_f32[0] = v212.mVec128.m128_f32[0];
          v249.mVec128.m128_f32[1] = v212.mVec128.m128_f32[1];
          v249.mVec128.m128_f32[2] = v212.mVec128.m128_f32[2];
          v249.mVec128.m128_i32[3] = 0;
          m_size = m_data[v183]->m_nodes.m_size;
          v254 = 1;
          if ( m_size > 0 )
          {
            v13 = (btVector3 *)btAlignedAllocInternal(16 * m_size);
            v254 = 1;
            v253.mVec128.m128_u64[1] = __PAIR64__((unsigned int)v13, m_size);
            v10 = (btConvexHullComputer *)m_size;
            do
            {
              if ( v13 )
                *v13 = (btVector3)v249.mVec128;
              ++v13;
              v10 = (btConvexHullComputer *)((char *)v10 - 1);
            }
            while ( v10 );
          }
          v14 = 0;
          v253.mVec128.m128_i32[1] = m_size;
          if ( m_size > 0 )
          {
            v10 = (btConvexHullComputer *)v253.mVec128.m128_i32[3];
            do
            {
              p_m_x = &psb->m_clusters.m_data[v183]->m_nodes.m_data[v14]->m_x;
              *(_DWORD *)&v10->vertices.m_allocator = p_m_x->mVec128.m128_i32[0];
              p_m_x = (btVector3 *)((char *)p_m_x + 4);
              v10->vertices.m_size = p_m_x->mVec128.m128_i32[0];
              p_m_x = (btVector3 *)((char *)p_m_x + 4);
              v10->vertices.m_capacity = p_m_x->mVec128.m128_i32[0];
              p_m_data = &v10->vertices.m_data;
              ++v14;
              v10 = (btConvexHullComputer *)((char *)v10 + 16);
              *p_m_data = (btVector3 *)p_m_x->mVec128.m128_i32[1];
            }
            while ( v14 < m_size );
          }
          LOBYTE(v232) = 1;
          v231 = 0;
          v229 = 0.0;
          v230 = 0.0;
          LOBYTE(v237) = 1;
          v236 = 0.0;
          v234 = 0.0;
          v235 = 0;
          LOBYTE(v242) = 1;
          v241 = 0.0;
          v239 = 0;
          v240 = 0.0;
          btConvexHullComputer::compute(v10, &coords, v253.mVec128.m128_i32[3], m_size, v170, v171, v172);
          v197 = 0.0;
          if ( v239 > 0 )
          {
            do
            {
              v17 = (btAlignedObjectArray<GrahamVector2> *)LODWORD(v197);
              v18 = LODWORD(v236) + 12 * *(_DWORD *)(LODWORD(v241) + 4 * LODWORD(v197));
              v19 = *(float *)(v18 + 8);
              v20 = (float *)(v18 + 12 * *(_DWORD *)(v18 + 4));
              v21 = &v20[3 * *(_DWORD *)v20];
              v22 = v20[2];
              while ( v21 != (float *)v18 )
              {
                v196 = v21[2];
                ((void (__thiscall *)(btIDebugDraw *, int, int, int, btVector3 *, _DWORD))idraw->drawTriangle)(
                  idraw,
                  v231 + 16 * LODWORD(v22),
                  v231 + 16 * LODWORD(v19),
                  v231 + 16 * LODWORD(v196),
                  &v249,
                  1.0);
                v21 += 3 * *((_DWORD *)v21 + 1) + 3 * LODWORD(v21[3 * *((_DWORD *)v21 + 1)]);
                v22 = v19;
                v19 = v196;
              }
              ++LODWORD(v197);
            }
            while ( SLODWORD(v197) < v239 );
          }
          btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v17, (int)&v238);
          btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v23, (int)&v233);
          btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v24, (int)&coords);
          btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v25, (int)&v253);
          v7 = psb;
        }
        ++v183;
      }
      while ( v183 < v7->m_clusters.m_size );
    }
    goto LABEL_19;
  }
  if ( (drawflags & 1) != 0 )
  {
    v188 = 0;
    if ( psb->m_nodes.m_size > 0 )
    {
      v177 = 0;
      do
      {
        v71 = &psb->m_nodes.m_data[v177];
        if ( (v71->m_material->m_flags & 1) != 0 )
        {
          v72 = v71->m_x.mVec128.m128_f32[0];
          v73 = idraw->__vftable;
          v212.mVec128.m128_u64[0] = LODWORD(v6);
          v217.mVec128.m128_f32[0] = v72 + 0.1;
          *(unsigned __int64 *)((char *)v217.mVec128.m128_u64 + 4) = *(unsigned __int64 *)((char *)v71->m_x.mVec128.m128_u64
                                                                                         + 4);
          v74 = v71->m_x.mVec128.m128_f32[0] - 0.1;
          v210.mVec128.m128_i32[1] = v71->m_x.mVec128.m128_i32[1];
          v75 = v71->m_x.mVec128.m128_i32[2];
          v212.mVec128.m128_u64[1] = 0;
          v217.mVec128.m128_i32[3] = 0;
          v210.mVec128.m128_f32[0] = v74;
          v210.mVec128.m128_u64[1] = (unsigned int)v75;
          v73->drawLine(idraw, &v210, &v217, &v212);
          v76 = v71->m_x.mVec128.m128_f32[1];
          v77 = idraw->__vftable;
          v214 = s_bm_current_air_resistance;
          v195.mVec128.m128_i32[0] = v71->m_x.mVec128.m128_i32[0];
          v195.mVec128.m128_f32[1] = v76 + 0.1;
          v195.mVec128.m128_u64[1] = v71->m_x.mVec128.m128_u32[2];
          v193.mVec128.m128_i32[0] = v71->m_x.mVec128.m128_i32[0];
          *(float *)&v78 = v71->m_x.mVec128.m128_f32[1] - 0.1;
          v79 = v71->m_x.mVec128.m128_i32[2];
          v213 = 0.0;
          v215 = 0.0;
          v216 = 0;
          *(unsigned __int64 *)((char *)v193.mVec128.m128_u64 + 4) = __PAIR64__(v79, v78);
          v193.mVec128.m128_i32[3] = 0;
          v77->drawLine(idraw, &v193, &v195, (const btVector3 *)&v213);
          v80 = v71->m_x.mVec128.m128_f32[2];
          v208 = s_bm_current_air_resistance;
          v202 = v71->m_x.mVec128.m128_f32[0];
          v203 = v71->m_x.mVec128.m128_f32[1];
          v204 = v80 + 0.1;
          v198 = v71->m_x.mVec128.m128_f32[0];
          v81 = v71->m_x.mVec128.m128_f32[1];
          v206 = 0.0;
          v207 = 0.0;
          v209 = 0;
          v205 = 0;
          v199 = v81;
          v82 = idraw->__vftable;
          v200 = v71->m_x.mVec128.m128_f32[2] - 0.1;
          v201 = 0;
          v82->drawLine(idraw, (const btVector3 *)&v198, (const btVector3 *)&v202, (const btVector3 *)&v206);
        }
        ++v188;
        ++v177;
        v6 = s_bm_current_air_resistance;
      }
      while ( v188 < psb->m_nodes.m_size );
    }
  }
  if ( (drawflags & 2) != 0 )
  {
    v83 = 0;
    if ( psb->m_links.m_size > 0 )
    {
      v178 = 0;
      do
      {
        v84 = &psb->m_links.m_data[v178];
        if ( (v84->m_material->m_flags & 1) != 0 )
          idraw->drawLine(idraw, &v84->m_n[0]->m_x, &v84->m_n[1]->m_x, (const btVector3 *)v265);
        ++v178;
        ++v83;
      }
      while ( v83 < psb->m_links.m_size );
      v6 = s_bm_current_air_resistance;
    }
  }
  v85 = c_anim_center;
  if ( (drawflags & 0x10) != 0 )
  {
    v189 = 0;
    if ( psb->m_nodes.m_size > 0 )
    {
      v179 = 0;
      do
      {
        v86 = &psb->m_nodes.m_data[v179];
        if ( (v86->m_material->m_flags & 1) != 0 )
        {
          v87 = v86->m_n.mVec128.m128_f32[0];
          v88 = v86->m_n.mVec128.m128_f32[1];
          v89 = v86->m_n.mVec128.m128_f32[2];
          m128_f32 = v86->m_x.mVec128.m128_f32;
          v91 = v86->m_x.mVec128.m128_f32[0];
          v92 = idraw->__vftable;
          v93 = v87 * v85;
          v94 = v91 + v93;
          v195.mVec128.m128_f32[0] = v93;
          *(float *)&v95 = v88 * v85;
          v199 = m128_f32[1] + *(float *)&v95;
          *(float *)&v96 = v89 * v85;
          v97 = m128_f32[2] + *(float *)&v96;
          *(unsigned __int64 *)((char *)v195.mVec128.m128_u64 + 4) = __PAIR64__(v96, v95);
          v198 = v94;
          v200 = v97;
          v201 = 0;
          v92->drawLine(idraw, (const btVector3 *)m128_f32, (const btVector3 *)&v198, (const btVector3 *)&v259);
          v98 = idraw->__vftable;
          v202 = v259 * 0.5;
          v203 = v260 * 0.5;
          v204 = v261 * 0.5;
          v206 = *m128_f32 - v195.mVec128.m128_f32[0];
          v207 = m128_f32[1] - v195.mVec128.m128_f32[1];
          v99 = m128_f32[2] - v195.mVec128.m128_f32[2];
          v205 = 0;
          v208 = v99;
          v209 = 0;
          v98->drawLine(idraw, (const btVector3 *)m128_f32, (const btVector3 *)&v206, (const btVector3 *)&v202);
          v85 = c_anim_center;
        }
        ++v189;
        ++v179;
      }
      while ( v189 < psb->m_nodes.m_size );
      v6 = s_bm_current_air_resistance;
    }
  }
  if ( (drawflags & 0x20) != 0 )
  {
    if ( (_S5_8 & 1) == 0 )
    {
      _S5_8 |= 1u;
      axis[0].mVec128.m128_u64[0] = LODWORD(v6);
      axis[0].mVec128.m128_u64[1] = 0;
      axis[1].mVec128.m128_i32[0] = 0;
      *(unsigned __int64 *)((char *)axis[1].mVec128.m128_u64 + 4) = LODWORD(v6);
      axis[1].mVec128.m128_i32[3] = 0;
      axis[2].mVec128.m128_u64[0] = 0;
      axis[2].mVec128.m128_u64[1] = LODWORD(v6);
    }
    v190 = 0;
    if ( psb->m_rcontacts.m_size > 0 )
    {
      v194 = 0.0;
      while ( 1 )
      {
        v100 = (char *)psb->m_rcontacts.m_data + LODWORD(v194);
        v101 = (float *)*((_DWORD *)v100 + 12);
        v102 = (float)((float)((float)(*((float *)v100 + 6) * v101[6]) + (float)(*((float *)v100 + 5) * v101[5]))
                     + (float)(v101[4] * *((float *)v100 + 4)))
             + *((float *)v100 + 8);
        v103 = v102 * *((float *)v100 + 4);
        v104 = *((float *)v100 + 6) * v102;
        *(float *)&v105 = v101[5] - (float)(*((float *)v100 + 5) * v102);
        v106 = v101[6] - v104;
        v193.mVec128.m128_f32[0] = v101[4] - v103;
        *(unsigned __int64 *)((char *)v193.mVec128.m128_u64 + 4) = __PAIR64__(LODWORD(v106), v105);
        v193.mVec128.m128_i32[3] = 0;
        v107 = *((float *)v100 + 4);
        v211 = *(float *)&v105;
        v108 = *((float *)v100 + 5);
        if ( v108 <= v107 )
        {
          if ( *((float *)v100 + 6) > v108 )
          {
            v109 = 1;
            goto LABEL_79;
          }
        }
        else if ( *((float *)v100 + 6) > v107 )
        {
          v109 = 0;
          goto LABEL_79;
        }
        v109 = 2;
LABEL_79:
        v110 = *((float *)v100 + 6);
        v111 = &axis[v109];
        v112 = *((float *)v100 + 4);
        v113 = (float)(v111->mVec128.m128_f32[2] * *((float *)v100 + 5)) - (float)(v111->mVec128.m128_f32[1] * v110);
        v114 = (float)(v111->mVec128.m128_f32[0] * v110) - (float)(v112 * v111->mVec128.m128_f32[2]);
        v115 = (float)(v112 * v111->mVec128.m128_f32[1]) - (float)(v111->mVec128.m128_f32[0] * *((float *)v100 + 5));
        v116 = s_bm_current_air_resistance
             / fsqrt((float)((float)(v113 * v113) + (float)(v115 * v115)) + (float)(v114 * v114));
        v213 = v113 * v116;
        v117 = v116 * v114;
        v118 = *((float *)v100 + 4);
        v119 = v116 * v115;
        v120 = (float)(*((float *)v100 + 6) * v117) - (float)(*((float *)v100 + 5) * v119);
        v180 = v118 * v119;
        v121 = *((float *)v100 + 6);
        v215 = v119;
        v122 = *((float *)v100 + 5);
        v195.mVec128.m128_f32[1] = v180 - (float)(v213 * v121);
        v195.mVec128.m128_f32[2] = (float)(v213 * v122) - (float)(v118 * v117);
        v123 = s_bm_current_air_resistance
             / fsqrt(
                 (float)((float)(v120 * v120) + (float)(v195.mVec128.m128_f32[2] * v195.mVec128.m128_f32[2]))
               + (float)(v195.mVec128.m128_f32[1] * v195.mVec128.m128_f32[1]));
        v210.mVec128.m128_f32[0] = v120 * v123;
        v210.mVec128.m128_f32[1] = v123 * v195.mVec128.m128_f32[1];
        v124 = idraw->__vftable;
        v196 = v215 * v85;
        v210.mVec128.m128_f32[2] = v123 * v195.mVec128.m128_f32[2];
        v125 = v213 * v85;
        v126 = v117 * v85;
        v198 = (float)(v213 * v85) + v193.mVec128.m128_f32[0];
        v199 = v211 + v126;
        v127 = v215 * v85;
        v200 = v106 + v127;
        v201 = 0;
        v202 = v193.mVec128.m128_f32[0] - v125;
        v203 = v211 - v126;
        v204 = v106 - v127;
        v205 = 0;
        v124->drawLine(idraw, (const btVector3 *)&v202, (const btVector3 *)&v198, (const btVector3 *)v263);
        v128 = idraw->__vftable;
        v206 = (float)(v210.mVec128.m128_f32[0] * 0.5) + v193.mVec128.m128_f32[0];
        v207 = (float)(v210.mVec128.m128_f32[1] * 0.5) + v193.mVec128.m128_f32[1];
        v208 = (float)(v210.mVec128.m128_f32[2] * 0.5) + v193.mVec128.m128_f32[2];
        v209 = 0;
        v212.mVec128.m128_f32[0] = v193.mVec128.m128_f32[0] - (float)(v210.mVec128.m128_f32[0] * 0.5);
        v212.mVec128.m128_f32[1] = v193.mVec128.m128_f32[1] - (float)(v210.mVec128.m128_f32[1] * 0.5);
        v212.mVec128.m128_f32[2] = v193.mVec128.m128_f32[2] - (float)(v210.mVec128.m128_f32[2] * 0.5);
        v212.mVec128.m128_i32[3] = 0;
        v128->drawLine(idraw, &v212, (const btVector3 *)&v206, (const btVector3 *)v263);
        v129 = *((float *)v100 + 4);
        v217.mVec128.m128_f32[0] = s_bm_current_air_resistance;
        *(unsigned __int64 *)((char *)v217.mVec128.m128_u64 + 4) = LODWORD(s_bm_current_air_resistance);
        v217.mVec128.m128_i32[3] = 0;
        v130 = idraw->__vftable;
        v131 = (float)((float)(*((float *)v100 + 5) * 0.5) * 3.0) + v193.mVec128.m128_f32[1];
        v132 = (float)((float)(*((float *)v100 + 6) * 0.5) * 3.0) + v193.mVec128.m128_f32[2];
        v220 = (float)((float)(v129 * 0.5) * 3.0) + v193.mVec128.m128_f32[0];
        v221 = v131;
        v222 = v132;
        v223 = 0;
        v130->drawLine(idraw, &v193, (const btVector3 *)&v220, &v217);
        ++v190;
        LODWORD(v194) += 144;
        if ( v190 >= psb->m_rcontacts.m_size )
          break;
        v85 = c_anim_center;
      }
    }
  }
  v133 = FLOAT_0_80000001;
  if ( (drawflags & 4) != 0 )
  {
    v191 = 0;
    v134 = psb->m_faces.m_size <= 0;
    v220 = 0.0;
    v221 = FLOAT_0_69999999;
    v222 = 0.0;
    v223 = 0;
    if ( !v134 )
    {
      v181 = 0;
      do
      {
        v135 = &psb->m_faces.m_data[v181];
        if ( (v135->m_material->m_flags & 1) != 0 )
        {
          v136 = (int)&v135->m_n[0]->m_x;
          coords = *(float *)v136;
          v136 += 4;
          v229 = *(float *)v136;
          v136 += 4;
          v230 = *(float *)v136;
          v231 = *(_DWORD *)(v136 + 4);
          v137 = (int)&v135->m_n[1]->m_x;
          v232 = *(float *)v137;
          v137 += 4;
          v233 = *(float *)v137;
          v137 += 4;
          v234 = *(float *)v137;
          v235 = *(_DWORD *)(v137 + 4);
          v138 = (int)&v135->m_n[2]->m_x;
          v236 = *(float *)v138;
          v138 += 4;
          v237 = *(float *)v138;
          v138 += 4;
          v238 = *(float *)v138;
          v239 = *(_DWORD *)(v138 + 4);
          v139 = (float)(v238 + (float)(v234 + v230)) * 0.33333334;
          v140 = (float)(v237 + (float)(v233 + v229)) * 0.33333334;
          v193.mVec128.m128_f32[0] = (float)((float)(coords + v232) + v236) * 0.33333334;
          v199 = (float)((float)(v237 - v140) * v133) + v140;
          v200 = (float)((float)(v238 - v139) * v133) + v139;
          v198 = (float)((float)(v236 - v193.mVec128.m128_f32[0]) * v133) + v193.mVec128.m128_f32[0];
          v203 = (float)((float)(v233 - v140) * v133) + v140;
          v204 = (float)((float)(v234 - v139) * v133) + v139;
          v202 = (float)((float)(v232 - v193.mVec128.m128_f32[0]) * v133) + v193.mVec128.m128_f32[0];
          v193.mVec128.m128_f32[2] = v139;
          v201 = 0;
          v205 = 0;
          v141 = idraw->__vftable;
          v206 = (float)((float)(coords - v193.mVec128.m128_f32[0]) * v133) + v193.mVec128.m128_f32[0];
          v207 = (float)((float)(v229 - v140) * v133) + v140;
          v208 = (float)((float)(v230 - v139) * v133) + v139;
          v209 = 0;
          ((void (__stdcall *)(float *, float *, float *, float *, _DWORD))v141->drawTriangle)(
            &v206,
            &v202,
            &v198,
            &v220,
            1.0);
          v133 = FLOAT_0_80000001;
        }
        ++v191;
        ++v181;
      }
      while ( v191 < psb->m_faces.m_size );
    }
  }
  if ( (drawflags & 8) != 0 )
  {
    v194 = 0.0;
    v134 = psb->m_tetras.m_size <= 0;
    v195.mVec128.m128_f32[0] = s_aim_transition_time;
    *(unsigned __int64 *)((char *)v195.mVec128.m128_u64 + 4) = __PAIR64__(
                                                                 LODWORD(FLOAT_0_69999999),
                                                                 LODWORD(s_aim_transition_time));
    v195.mVec128.m128_i32[3] = 0;
    if ( !v134 )
    {
      v182 = 0;
      do
      {
        v142 = &psb->m_tetras.m_data[v182];
        if ( (v142->m_material->m_flags & 1) != 0 )
        {
          v143 = (int)&v142->m_n[0]->m_x;
          coords = *(float *)v143;
          v143 += 4;
          v229 = *(float *)v143;
          v143 += 4;
          v230 = *(float *)v143;
          v231 = *(_DWORD *)(v143 + 4);
          v144 = (int)&v142->m_n[1]->m_x;
          v232 = *(float *)v144;
          v144 += 4;
          v233 = *(float *)v144;
          v144 += 4;
          v234 = *(float *)v144;
          v235 = *(_DWORD *)(v144 + 4);
          v145 = (int)&v142->m_n[2]->m_x;
          v236 = *(float *)v145;
          v145 += 4;
          v237 = *(float *)v145;
          v145 += 4;
          v238 = *(float *)v145;
          v239 = *(_DWORD *)(v145 + 4);
          v146 = (int)&v142->m_n[3]->m_x;
          v240 = *(float *)v146;
          v146 += 4;
          v241 = *(float *)v146;
          v146 += 4;
          v242 = *(float *)v146;
          v243 = *(_DWORD *)(v146 + 4);
          v249.mVec128.m128_f32[1] = v237 + (float)(v233 + v229);
          v249.mVec128.m128_f32[2] = v238 + (float)(v234 + v230);
          v147 = (float)(v240 + (float)(v236 + (float)(v232 + coords))) * 0.25;
          v148 = (float)(v241 + v249.mVec128.m128_f32[1]) * 0.25;
          v149 = (float)(v242 + v249.mVec128.m128_f32[2]) * 0.25;
          v211 = v238 - v149;
          v218 = v236 - v147;
          v219 = v237 - v148;
          v222 = (float)((float)(v238 - v149) * v133) + v149;
          v220 = (float)((float)(v236 - v147) * v133) + v147;
          v193.mVec128.m128_f32[0] = v147;
          v193.mVec128.m128_f32[1] = v148;
          v193.mVec128.m128_f32[2] = v149;
          v221 = (float)((float)(v237 - v148) * v133) + v148;
          v223 = 0;
          v196 = v232 - v147;
          v150 = idraw->__vftable;
          v197 = v233 - v148;
          v192 = v234 - v149;
          v198 = (float)((float)(v232 - v147) * v133) + v147;
          v199 = (float)((float)(v233 - v148) * v133) + v148;
          v200 = (float)((float)(v234 - v149) * v133) + v149;
          v224 = coords - v147;
          v225 = v229 - v148;
          v226 = v230 - v149;
          v201 = 0;
          v202 = (float)((float)(coords - v193.mVec128.m128_f32[0]) * v133) + v193.mVec128.m128_f32[0];
          v203 = (float)((float)(v229 - v148) * v133) + v148;
          v204 = (float)((float)(v230 - v149) * v133) + v149;
          v205 = 0;
          ((void (__thiscall *)(btIDebugDraw *, float *, float *, float *, btVector3 *, _DWORD))v150->drawTriangle)(
            idraw,
            &v202,
            &v198,
            &v220,
            &v195,
            1.0);
          v250 = v240 - v193.mVec128.m128_f32[0];
          v252 = v241 - v193.mVec128.m128_f32[1];
          v251 = v242 - v193.mVec128.m128_f32[2];
          v207 = (float)((float)(v241 - v193.mVec128.m128_f32[1]) * 0.80000001) + v193.mVec128.m128_f32[1];
          v208 = (float)((float)(v242 - v193.mVec128.m128_f32[2]) * 0.80000001) + v193.mVec128.m128_f32[2];
          v206 = (float)((float)(v240 - v193.mVec128.m128_f32[0]) * 0.80000001) + v193.mVec128.m128_f32[0];
          v209 = 0;
          v151 = idraw->__vftable;
          v212.mVec128.m128_f32[0] = (float)(v196 * 0.80000001) + v193.mVec128.m128_f32[0];
          v212.mVec128.m128_f32[1] = (float)(v197 * 0.80000001) + v193.mVec128.m128_f32[1];
          v212.mVec128.m128_f32[2] = (float)(v192 * 0.80000001) + v193.mVec128.m128_f32[2];
          v212.mVec128.m128_i32[3] = 0;
          v217.mVec128.m128_f32[0] = (float)(v224 * 0.80000001) + v193.mVec128.m128_f32[0];
          v217.mVec128.m128_f32[1] = (float)(v225 * 0.80000001) + v193.mVec128.m128_f32[1];
          v217.mVec128.m128_f32[2] = (float)(v226 * 0.80000001) + v193.mVec128.m128_f32[2];
          v217.mVec128.m128_i32[3] = 0;
          ((void (__thiscall *)(btIDebugDraw *, btVector3 *, btVector3 *, float *, btVector3 *, _DWORD))v151->drawTriangle)(
            idraw,
            &v217,
            &v212,
            &v206,
            &v195,
            1.0);
          v152 = idraw->__vftable;
          v210.mVec128.m128_f32[1] = (float)(v252 * 0.80000001) + v193.mVec128.m128_f32[1];
          v210.mVec128.m128_f32[2] = (float)(v251 * 0.80000001) + v193.mVec128.m128_f32[2];
          v213 = (float)(v218 * 0.80000001) + v193.mVec128.m128_f32[0];
          v214 = (float)(v219 * 0.80000001) + v193.mVec128.m128_f32[1];
          v215 = (float)(v211 * 0.80000001) + v193.mVec128.m128_f32[2];
          v210.mVec128.m128_f32[0] = (float)(v250 * 0.80000001) + v193.mVec128.m128_f32[0];
          v210.mVec128.m128_i32[3] = 0;
          v216 = 0;
          v255 = (float)(v196 * 0.80000001) + v193.mVec128.m128_f32[0];
          v256 = (float)(v197 * 0.80000001) + v193.mVec128.m128_f32[1];
          v257 = (float)(v192 * 0.80000001) + v193.mVec128.m128_f32[2];
          v258 = 0;
          ((void (__thiscall *)(btIDebugDraw *, float *, float *, btVector3 *, btVector3 *, _DWORD))v152->drawTriangle)(
            idraw,
            &v255,
            &v213,
            &v210,
            &v195,
            1.0);
          v153 = idraw->__vftable;
          v245 = (float)(v252 * 0.80000001) + v193.mVec128.m128_f32[1];
          v246 = (float)(v251 * 0.80000001) + v193.mVec128.m128_f32[2];
          v248.mVec128.m128_f32[0] = (float)(v224 * 0.80000001) + v193.mVec128.m128_f32[0];
          v248.mVec128.m128_f32[1] = (float)(v225 * 0.80000001) + v193.mVec128.m128_f32[1];
          v248.mVec128.m128_f32[2] = (float)(v226 * 0.80000001) + v193.mVec128.m128_f32[2];
          v244 = (float)(v250 * 0.80000001) + v193.mVec128.m128_f32[0];
          v247 = 0;
          v248.mVec128.m128_i32[3] = 0;
          v227.mVec128.m128_f32[0] = (float)(v218 * 0.80000001) + v193.mVec128.m128_f32[0];
          v227.mVec128.m128_f32[1] = (float)(v219 * 0.80000001) + v193.mVec128.m128_f32[1];
          v227.mVec128.m128_f32[2] = (float)(v211 * 0.80000001) + v193.mVec128.m128_f32[2];
          v227.mVec128.m128_i32[3] = 0;
          ((void (__thiscall *)(btIDebugDraw *, btVector3 *, btVector3 *, float *, btVector3 *, _DWORD))v153->drawTriangle)(
            idraw,
            &v227,
            &v248,
            &v244,
            &v195,
            1.0);
          v133 = FLOAT_0_80000001;
        }
        ++LODWORD(v194);
        ++v182;
      }
      while ( SLODWORD(v194) < psb->m_tetras.m_size );
    }
  }
LABEL_19:
  if ( (drawflags & 0x40) != 0 )
  {
    v184 = 0;
    if ( psb->m_anchors.m_size > 0 )
    {
      v174 = 0;
      do
      {
        v26 = &psb->m_anchors.m_data[v174];
        m_body = (float *)v26->m_body;
        v28 = v26->m_local.mVec128.m128_f32[2];
        v29 = v26->m_local.mVec128.m128_f32[1];
        v30 = m_body[13];
        v31 = m_body[14];
        v32 = m_body[10];
        m_body += 4;
        v33 = (float)((float)(v30 * v29) + (float)(v31 * v28)) + (float)(v26->m_local.mVec128.m128_f32[0] * m_body[8]);
        *(float *)&v34 = (float)((float)((float)(m_body[5] * v29) + (float)(v32 * v28))
                               + (float)(v26->m_local.mVec128.m128_f32[0] * m_body[4]))
                       + m_body[13];
        *(float *)&v35 = (float)((float)((float)(m_body[1] * v29) + (float)(m_body[2] * v28))
                               + (float)(*m_body * v26->m_local.mVec128.m128_f32[0]))
                       + m_body[12];
        v210.mVec128.m128_f32[2] = v33 + m_body[14];
        v210.mVec128.m128_u64[0] = __PAIR64__(v34, v35);
        v210.mVec128.m128_i32[3] = 0;
        v36 = &v26->m_node->m_x;
        v227.mVec128.m128_u64[0] = LODWORD(s_bm_current_air_resistance);
        v227.mVec128.m128_u64[1] = 0;
        drawVertex(idraw, v36, 0.25, &v227);
        v248.mVec128.m128_i32[0] = 0;
        *(unsigned __int64 *)((char *)v248.mVec128.m128_u64 + 4) = LODWORD(s_bm_current_air_resistance);
        v248.mVec128.m128_i32[3] = 0;
        drawVertex(idraw, &v210, 0.25, &v248);
        v37 = idraw->__vftable;
        v244 = s_bm_current_air_resistance;
        v245 = s_bm_current_air_resistance;
        v246 = s_bm_current_air_resistance;
        m_node = v26->m_node;
        v247 = 0;
        v37->drawLine(idraw, &m_node->m_x, &v210, (const btVector3 *)&v244);
        ++v184;
        ++v174;
      }
      while ( v184 < psb->m_anchors.m_size );
    }
    v185 = 0;
    if ( psb->m_nodes.m_size > 0 )
    {
      v175 = 0;
      do
      {
        v39 = &psb->m_nodes.m_data[v175];
        if ( (v39->m_material->m_flags & 1) != 0 && v39->m_im <= 0.0 )
        {
          v227.mVec128.m128_u64[0] = LODWORD(s_bm_current_air_resistance);
          v227.mVec128.m128_u64[1] = 0;
          drawVertex(idraw, &v39->m_x, 0.25, &v227);
        }
        ++v185;
        ++v175;
      }
      while ( v185 < psb->m_nodes.m_size );
    }
  }
  if ( (drawflags & 0x80u) != 0 )
  {
    v186 = 0;
    if ( psb->m_notes.m_size > 0 )
    {
      v176 = 0;
      do
      {
        v40 = &psb->m_notes.m_data[v176];
        v195.mVec128 = (__m128)v40->m_offset;
        v41 = 0;
        if ( v40->m_rank > 0 )
        {
          m_coords = v40->m_coords;
          do
          {
            v43 = (float *)*((_DWORD *)m_coords - 4);
            v44 = *m_coords;
            v45 = v43[5];
            v46 = v43[6];
            v195.mVec128.m128_f32[0] = (float)(*m_coords * v43[4]) + v195.mVec128.m128_f32[0];
            v195.mVec128.m128_f32[1] = v195.mVec128.m128_f32[1] + (float)(v45 * v44);
            ++v41;
            v195.mVec128.m128_f32[2] = v195.mVec128.m128_f32[2] + (float)(v46 * v44);
            ++m_coords;
          }
          while ( v41 < v40->m_rank );
        }
        idraw->draw3dText(idraw, &v195, v40->m_text);
        ++v186;
        ++v176;
      }
      while ( v186 < psb->m_notes.m_size );
    }
  }
  if ( (drawflags & 0x200) != 0 )
    btSoftBodyHelpers::DrawNodeTree(psb, idraw);
  if ( (drawflags & 0x400) != 0 )
    btSoftBodyHelpers::DrawFaceTree(psb, idraw);
  if ( (drawflags & 0x800) != 0 )
    btSoftBodyHelpers::DrawClusterTree(psb, idraw);
  if ( (drawflags & 0x1000) != 0 )
  {
    for ( i = 0; i < psb->m_joints.m_size; ++i )
    {
      v47 = psb->m_joints.m_data[i];
      v48 = v47->Type(v47);
      if ( v48 )
      {
        if ( v48 == 1 )
        {
          v193.mVec128 = (__m128)btSoftBody::Body::xform(v49, &v47->m_bodies[0].m_soft)->m_origin;
          v195.mVec128 = (__m128)btSoftBody::Body::xform(v50, &v47->m_bodies[1].m_soft)->m_origin;
          v52 = (float *)btSoftBody::Body::xform(v51, &v47->m_bodies[0].m_soft);
          v53 = v47->m_refs[0].mVec128.m128_f32[2];
          v54 = v47->m_refs[0].mVec128.m128_f32[1];
          v55 = v47->m_refs[0].mVec128.m128_f32[0];
          v56 = v52[6];
          v210.mVec128.m128_f32[0] = (float)((float)(v52[1] * v54) + (float)(v52[2] * v53)) + (float)(v55 * *v52);
          v210.mVec128.m128_f32[1] = (float)((float)(v52[5] * v54) + (float)(v56 * v53)) + (float)(v55 * v52[4]);
          v210.mVec128.m128_f32[2] = (float)((float)(v52[9] * v54) + (float)(v52[10] * v53)) + (float)(v52[8] * v55);
          v58 = (float *)btSoftBody::Body::xform(v57, &v47->m_bodies[1].m_soft);
          v59 = v47->m_refs[1].mVec128.m128_f32[1];
          v60 = v47->m_refs[1].mVec128.m128_f32[2];
          v61 = v47->m_refs[1].mVec128.m128_f32[0];
          v62 = v58[6];
          v213 = (float)((float)(v58[1] * v59) + (float)(v58[2] * v60)) + (float)(v61 * *v58);
          v63 = (float)(v58[5] * v59) + (float)(v62 * v60);
          v64 = v61 * v58[4];
          v65 = v61 * v58[8];
          v214 = v63 + v64;
          v66 = (float)(v58[9] * v59) + (float)(v58[10] * v60);
          v67 = idraw->__vftable;
          v219 = v210.mVec128.m128_f32[1] * 10.0;
          v215 = v66 + v65;
          v248.mVec128.m128_f32[1] = v193.mVec128.m128_f32[1] + (float)(v210.mVec128.m128_f32[1] * 10.0);
          v227.mVec128.m128_f32[0] = s_bm_current_air_resistance;
          *(unsigned __int64 *)((char *)v227.mVec128.m128_u64 + 4) = LODWORD(s_bm_current_air_resistance);
          v211 = v210.mVec128.m128_f32[0] * 10.0;
          v227.mVec128.m128_i32[3] = 0;
          v218 = v210.mVec128.m128_f32[2] * 10.0;
          v248.mVec128.m128_f32[0] = (float)(v210.mVec128.m128_f32[0] * 10.0) + v193.mVec128.m128_f32[0];
          v248.mVec128.m128_f32[2] = v193.mVec128.m128_f32[2] + (float)(v210.mVec128.m128_f32[2] * 10.0);
          v248.mVec128.m128_i32[3] = 0;
          v67->drawLine(idraw, &v193, &v248, &v227);
          v68 = idraw->__vftable;
          v244 = s_bm_current_air_resistance;
          v245 = s_bm_current_air_resistance;
          v226 = v213 * 10.0;
          v225 = v214 * 10.0;
          v246 = 0.0;
          v247 = 0;
          v224 = v215 * 10.0;
          v255 = (float)(v213 * 10.0) + v193.mVec128.m128_f32[0];
          v256 = (float)(v214 * 10.0) + v193.mVec128.m128_f32[1];
          v257 = (float)(v215 * 10.0) + v193.mVec128.m128_f32[2];
          v258 = 0;
          v68->drawLine(idraw, &v193, (const btVector3 *)&v255, (const btVector3 *)&v244);
          v221 = s_bm_current_air_resistance;
          v222 = s_bm_current_air_resistance;
          v220 = 0.0;
          v223 = 0;
          v69 = idraw->__vftable;
          v198 = v211 + v195.mVec128.m128_f32[0];
          v199 = v195.mVec128.m128_f32[1] + v219;
          v200 = v195.mVec128.m128_f32[2] + v218;
          v201 = 0;
          v69->drawLine(idraw, &v195, (const btVector3 *)&v198, (const btVector3 *)&v220);
          v70 = idraw->__vftable;
          v203 = s_bm_current_air_resistance;
          v204 = s_bm_current_air_resistance;
          v202 = 0.0;
          v205 = 0;
          v206 = v226 + v195.mVec128.m128_f32[0];
          v207 = v225 + v195.mVec128.m128_f32[1];
          v208 = v224 + v195.mVec128.m128_f32[2];
          v209 = 0;
          v70->drawLine(idraw, &v195, (const btVector3 *)&v206, (const btVector3 *)&v202);
        }
      }
      else
      {
        v154 = (float *)btSoftBody::Body::xform(v49, &v47->m_bodies[0].m_soft);
        v155 = v47->m_refs[0].mVec128.m128_f32[2];
        v156 = v47->m_refs[0].mVec128.m128_f32[1];
        v157 = v47->m_refs[0].mVec128.m128_f32[0];
        *(float *)&v158 = (float)((float)((float)(v154[5] * v156) + (float)(v154[6] * v155)) + (float)(v157 * v154[4]))
                        + v154[13];
        *(float *)&v159 = (float)((float)((float)(v154[1] * v156) + (float)(v154[2] * v155)) + (float)(*v154 * v157))
                        + v154[12];
        v217.mVec128.m128_f32[2] = (float)((float)((float)(v154[9] * v156) + (float)(v154[10] * v155))
                                         + (float)(v154[8] * v157))
                                 + v154[14];
        v217.mVec128.m128_u64[0] = __PAIR64__(v158, v159);
        v217.mVec128.m128_i32[3] = 0;
        v161 = (float *)btSoftBody::Body::xform(v160, &v47->m_bodies[1].m_soft);
        v162 = v47->m_refs[1].mVec128.m128_f32[1];
        v163 = v47->m_refs[1].mVec128.m128_f32[2];
        *(float *)&v164 = (float)((float)((float)(v161[9] * v162) + (float)(v161[10] * v163))
                                + (float)(v47->m_refs[1].mVec128.m128_f32[0] * v161[8]))
                        + v161[14];
        v165 = (float)((float)((float)(v161[1] * v162) + (float)(v161[2] * v163))
                     + (float)(v47->m_refs[1].mVec128.m128_f32[0] * *v161))
             + v161[12];
        v212.mVec128.m128_f32[1] = (float)((float)((float)(v161[5] * v162) + (float)(v161[6] * v163))
                                         + (float)(v47->m_refs[1].mVec128.m128_f32[0] * v161[4]))
                                 + v161[13];
        v212.mVec128.m128_u64[1] = v164;
        v212.mVec128.m128_f32[0] = v165;
        *(float *)v264 = s_bm_current_air_resistance;
        *(float *)&v264[1] = s_bm_current_air_resistance;
        v264[2] = 0;
        v264[3] = 0;
        v167 = btSoftBody::Body::xform(v166, &v47->m_bodies[0].m_soft);
        idraw->drawLine(idraw, &v167->m_origin, &v217, (const btVector3 *)v264);
        v266[0] = 0;
        *(float *)&v266[1] = s_bm_current_air_resistance;
        *(float *)&v266[2] = s_bm_current_air_resistance;
        v266[3] = 0;
        v169 = btSoftBody::Body::xform(v168, &v47->m_bodies[1].m_soft);
        idraw->drawLine(idraw, &v169->m_origin, &v212, (const btVector3 *)v266);
        v253.mVec128.m128_f32[0] = s_bm_current_air_resistance;
        *(unsigned __int64 *)((char *)v253.mVec128.m128_u64 + 4) = LODWORD(s_bm_current_air_resistance);
        v253.mVec128.m128_i32[3] = 0;
        drawVertex(idraw, &v217, 0.25, &v253);
        v249.mVec128.m128_i32[0] = 0;
        v249.mVec128.m128_f32[1] = s_bm_current_air_resistance;
        v249.mVec128.m128_u64[1] = LODWORD(s_bm_current_air_resistance);
        drawVertex(idraw, &v212, 0.25, &v249);
      }
    }
  }
}
