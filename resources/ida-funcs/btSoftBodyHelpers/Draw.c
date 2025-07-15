void __usercall btSoftBodyHelpers::Draw(
        btIDebugDraw *idraw@<ecx>,
        float a2@<ebx>,
        __int64 a3@<esi:edi>,
        btSoftBody *psb,
        __int16 drawflags)
{
  const vostok::math::float4x4 *v5; // xmm3_4
  char v6; // al
  btSoftBody *v8; // esi
  int v9; // ebx
  long double v10; // st7
  btSoftBody::Cluster **m_data; // edx
  btVector3 *v12; // eax
  int m_size; // ebx
  unsigned __int64 v14; // xmm0_8
  unsigned __int64 v15; // xmm1_8
  unsigned __int64 *v16; // ecx
  int v17; // edx
  int v18; // edx
  btVector3 *v19; // esi
  btVector3 *p_m_x; // ecx
  int v21; // ecx
  int v22; // ebx
  int v23; // esi
  float v24; // eax
  _DWORD *v25; // esi
  btSoftBody::Anchor *v26; // ebx
  float *m_body; // eax
  float v28; // xmm6_4
  float v29; // xmm5_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm7_4
  unsigned int v33; // xmm0_4
  float v34; // xmm1_4
  const btVector3 *v35; // esi
  void (__thiscall *v36)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // edx
  btSoftBody::Node *v37; // eax
  btSoftBody *v38; // ecx
  int v39; // ebx
  btSoftBody::Node *v40; // eax
  btSoftBody::Material *v41; // edx
  const btVector3 *v42; // eax
  btSoftBody::Note *v43; // ecx
  int v44; // esi
  float v45; // xmm6_4
  float v46; // xmm5_4
  float v47; // xmm4_4
  float *m_coords; // edx
  float *v49; // eax
  btSoftBody *v50; // esi
  int v51; // esi
  float v52; // xmm0_4
  btSoftBody::Node *v53; // esi
  btIDebugDraw_vtbl *v54; // eax
  float v55; // xmm1_4
  void (__thiscall *drawLine)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // edx
  float v57; // xmm0_4
  float v58; // xmm2_4
  btIDebugDraw_vtbl *v59; // eax
  void (__thiscall *v60)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // edx
  float v61; // xmm2_4
  int v62; // xmm1_4
  float v63; // xmm2_4
  float v64; // xmm2_4
  void (__thiscall *v65)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // edx
  btSoftBody::Link *v66; // eax
  btSoftBody::Material *m_material; // ecx
  btSoftBody::Link *v68; // eax
  float v69; // xmm5_4
  btSoftBody::Node *v70; // eax
  float v71; // xmm1_4
  float v72; // xmm2_4
  void (__thiscall *v73)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // edx
  float *m128_f32; // esi
  unsigned int v75; // xmm1_4
  unsigned int v76; // xmm2_4
  float v77; // xmm0_4
  void (__thiscall *v78)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // eax
  float v79; // xmm1_4
  int v80; // ebx
  btSoftBody::RContact *v81; // esi
  float *m_node; // eax
  float v83; // xmm0_4
  float v84; // xmm2_4
  float v85; // xmm1_4
  unsigned int v86; // xmm0_4
  float v87; // xmm3_4
  float v88; // xmm1_4
  float v89; // xmm0_4
  int v90; // eax
  float v91; // xmm6_4
  float v92; // xmm4_4
  const btVector3 *v93; // eax
  float v94; // xmm5_4
  float v95; // xmm7_4
  float v96; // xmm0_4
  float v97; // xmm1_4
  float v98; // xmm3_4
  float v99; // xmm6_4
  long double v100; // st7
  float v101; // xmm6_4
  float v102; // xmm7_4
  float v103; // xmm4_4
  float v104; // xmm0_4
  float v105; // xmm2_4
  float v106; // xmm1_4
  btIDebugDraw_vtbl *v107; // eax
  void (__thiscall *v108)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // edx
  btIDebugDraw_vtbl *v109; // eax
  float v110; // xmm1_4
  float v111; // xmm2_4
  btIDebugDraw_vtbl *v112; // eax
  void (__thiscall *v113)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // edx
  float v114; // xmm0_4
  int v115; // esi
  bool v116; // cc
  btSoftBody::Face *v117; // eax
  btSoftBody::Material *v118; // ecx
  btSoftBody::Face *v119; // eax
  btSoftBody::Node *v120; // ecx
  __int64 v121; // xmm1_8
  btSoftBody::Node *v122; // ecx
  btSoftBody::Node *v123; // eax
  float v124; // xmm2_4
  float v125; // xmm3_4
  void (__thiscall *drawTriangle)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *, const btVector3 *, float); // edx
  int v127; // ebx
  int v128; // esi
  btSoftBody *v129; // ecx
  btSoftBody::Tetra *v130; // eax
  btSoftBody::Material *v131; // edx
  btSoftBody::Tetra *v132; // eax
  btSoftBody::Node *v133; // ecx
  btSoftBody::Node *v134; // ecx
  btSoftBody::Node *v135; // ecx
  btSoftBody::Node *v136; // eax
  float v137; // xmm1_4
  float v138; // xmm2_4
  float v139; // xmm3_4
  void (__thiscall *v140)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *, const btVector3 *, float); // eax
  void (__thiscall *v141)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *, const btVector3 *, float); // edx
  void (__thiscall *v142)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *, const btVector3 *, float); // eax
  btIDebugDraw_vtbl *v143; // edx
  btSoftBody::Joint *v144; // ebx
  int v145; // eax
  btSoftBody::Body *v146; // ecx
  btSoftBody::Body *v147; // ecx
  btSoftBody::Body *v148; // ecx
  float *v149; // eax
  float v150; // xmm1_4
  float v151; // xmm2_4
  float v152; // xmm3_4
  float v153; // xmm4_4
  btSoftBody::Body *v154; // ecx
  float *v155; // eax
  float v156; // xmm1_4
  float v157; // xmm2_4
  float v158; // xmm3_4
  float v159; // xmm4_4
  void (__thiscall *v160)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // edx
  btIDebugDraw_vtbl *v161; // eax
  void (__thiscall *v162)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // edx
  void (__thiscall *v163)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // edx
  void (__thiscall *v164)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // edx
  float *v165; // eax
  float v166; // xmm2_4
  float v167; // xmm3_4
  float v168; // xmm4_4
  unsigned int v169; // xmm1_4
  unsigned int v170; // xmm5_4
  btSoftBody::Body *v171; // ecx
  float *v172; // eax
  float v173; // xmm4_4
  float v174; // xmm3_4
  float v175; // xmm2_4
  unsigned int v176; // xmm0_4
  float v177; // xmm5_4
  btSoftBody::Body *v178; // ecx
  const btTransform *v179; // eax
  btSoftBody::Body *v180; // ecx
  const btTransform *v181; // eax
  const btDbvtNode *m_root; // [esp+2610h] [ebp-228h]
  const btDbvtNode *v183; // [esp+2610h] [ebp-228h]
  const btDbvtNode *v184; // [esp+2610h] [ebp-228h]
  __int64 lcolor_4; // [esp+2628h] [ebp-210h]
  float lcolor_12; // [esp+2630h] [ebp-208h]
  float v187; // [esp+2634h] [ebp-204h]
  int v188; // [esp+263Ch] [ebp-1FCh]
  int v189; // [esp+263Ch] [ebp-1FCh]
  int k; // [esp+263Ch] [ebp-1FCh]
  int v191; // [esp+263Ch] [ebp-1FCh]
  int v192; // [esp+263Ch] [ebp-1FCh]
  int v193; // [esp+263Ch] [ebp-1FCh]
  int v194; // [esp+263Ch] [ebp-1FCh]
  int v195; // [esp+263Ch] [ebp-1FCh]
  float v196; // [esp+263Ch] [ebp-1FCh]
  int v197; // [esp+263Ch] [ebp-1FCh]
  int i; // [esp+2640h] [ebp-1F8h]
  int v199; // [esp+2640h] [ebp-1F8h]
  int v200; // [esp+2640h] [ebp-1F8h]
  int v201; // [esp+2640h] [ebp-1F8h]
  int v202; // [esp+2640h] [ebp-1F8h]
  int v203; // [esp+2640h] [ebp-1F8h]
  float v204; // [esp+2640h] [ebp-1F8h]
  float v205; // [esp+2644h] [ebp-1F4h]
  float v206; // [esp+2644h] [ebp-1F4h]
  float v207; // [esp+2644h] [ebp-1F4h]
  float v208; // [esp+2644h] [ebp-1F4h]
  float v209; // [esp+2644h] [ebp-1F4h]
  float v210; // [esp+2644h] [ebp-1F4h]
  btVector3 v211; // [esp+2648h] [ebp-1F0h] BYREF
  btVector3 v212; // [esp+2658h] [ebp-1E0h] BYREF
  btVector3 v213; // [esp+2668h] [ebp-1D0h] BYREF
  btVector3 v214; // [esp+2678h] [ebp-1C0h] BYREF
  float v215; // [esp+2690h] [ebp-1A8h]
  float v216; // [esp+2694h] [ebp-1A4h]
  float v217; // [esp+2698h] [ebp-1A0h] BYREF
  float v218; // [esp+269Ch] [ebp-19Ch]
  float v219; // [esp+26A0h] [ebp-198h]
  int v220; // [esp+26A4h] [ebp-194h]
  btVector3 v221; // [esp+26A8h] [ebp-190h] BYREF
  float v222; // [esp+26B8h] [ebp-180h] BYREF
  float v223; // [esp+26BCh] [ebp-17Ch]
  float v224; // [esp+26C0h] [ebp-178h]
  int v225; // [esp+26C4h] [ebp-174h]
  float v226; // [esp+26C8h] [ebp-170h] BYREF
  float v227; // [esp+26CCh] [ebp-16Ch]
  float v228; // [esp+26D0h] [ebp-168h]
  int v229; // [esp+26D4h] [ebp-164h]
  float v230; // [esp+26DCh] [ebp-15Ch]
  float v231; // [esp+26E0h] [ebp-158h]
  float j; // [esp+26E4h] [ebp-154h]
  btVector3 v233; // [esp+26E8h] [ebp-150h] BYREF
  __int64 v234; // [esp+26F8h] [ebp-140h] BYREF
  float v235; // [esp+2700h] [ebp-138h]
  __int64 v236; // [esp+2704h] [ebp-134h]
  btVector3 v237; // [esp+2714h] [ebp-124h] BYREF
  int v238; // [esp+2724h] [ebp-114h]
  float v239; // [esp+2728h] [ebp-110h] BYREF
  float v240; // [esp+272Ch] [ebp-10Ch]
  float v241; // [esp+2730h] [ebp-108h]
  int v242; // [esp+2734h] [ebp-104h]
  float v243; // [esp+2738h] [ebp-100h] BYREF
  float v244; // [esp+273Ch] [ebp-FCh]
  float v245; // [esp+2740h] [ebp-F8h]
  int v246; // [esp+2744h] [ebp-F4h]
  float v247; // [esp+274Ch] [ebp-ECh]
  float v248; // [esp+2750h] [ebp-E8h]
  float v249; // [esp+2754h] [ebp-E4h]
  btVector3 v250; // [esp+2758h] [ebp-E0h] BYREF
  _BYTE v251[64]; // [esp+2768h] [ebp-D0h] BYREF
  float v252; // [esp+27A8h] [ebp-90h] BYREF
  float v253; // [esp+27ACh] [ebp-8Ch]
  float v254; // [esp+27B0h] [ebp-88h]
  int v255; // [esp+27B4h] [ebp-84h]
  btVector3 v256; // [esp+27B8h] [ebp-80h] BYREF
  float v257; // [esp+27C8h] [ebp-70h] BYREF
  float v258; // [esp+27CCh] [ebp-6Ch]
  float v259; // [esp+27D0h] [ebp-68h]
  int v260; // [esp+27D4h] [ebp-64h]
  float v261; // [esp+27D8h] [ebp-60h] BYREF
  float v262; // [esp+27DCh] [ebp-5Ch]
  float v263; // [esp+27E0h] [ebp-58h]
  int v264; // [esp+27E4h] [ebp-54h]
  const vostok::math::float4x4 *v265; // [esp+27E8h] [ebp-50h] BYREF
  const vostok::math::float4x4 *v266; // [esp+27ECh] [ebp-4Ch]
  const vostok::math::float4x4 *v267; // [esp+27F0h] [ebp-48h]
  int v268; // [esp+27F4h] [ebp-44h]
  _DWORD v269[7]; // [esp+27F8h] [ebp-40h] BYREF
  void *ptr; // [esp+2814h] [ebp-24h]
  _DWORD v271[4]; // [esp+2828h] [ebp-10h] BYREF

  v5 = clear_value;
  v6 = drawflags;
  lcolor_12 = a2;
  lcolor_4 = a3;
  memset(v271, 0, sizeof(v271));
  v265 = clear_value;
  v266 = clear_value;
  v267 = clear_value;
  v268 = 0;
  v269[0] = clear_value;
  memset(&v269[1], 0, 12);
  if ( (drawflags & 0x100) != 0 )
  {
    srand(0x70Eu);
    v188 = 0;
    if ( psb->m_clusters.m_size > 0 )
    {
      v8 = psb;
      v9 = 0;
      do
      {
        if ( v8->m_clusters.m_data[v9]->m_collide )
        {
          v216 = (float)(int)rand() * 0.000030518509;
          v237.mVec128.m128_f32[0] = (float)(int)rand() * 0.000030518509;
          v250.mVec128.m128_f32[0] = (float)(int)rand() * 0.000030518509;
          v10 = sqrtf(
                  (float)((float)(v250.mVec128.m128_f32[0] * v250.mVec128.m128_f32[0])
                        + (float)(v237.mVec128.m128_f32[0] * v237.mVec128.m128_f32[0]))
                + (float)(v216 * v216));
          m_data = v8->m_clusters.m_data;
          v12 = 0;
          ptr = 0;
          v205 = 1.0 / v10;
          v233.mVec128.m128_f32[0] = (float)(v205 * v250.mVec128.m128_f32[0]) * 0.75;
          v233.mVec128.m128_f32[1] = (float)(v205 * v237.mVec128.m128_f32[0]) * 0.75;
          v233.mVec128.m128_f32[2] = (float)(v205 * v216) * 0.75;
          v233.mVec128.m128_i32[3] = 0;
          v250.mVec128 = (__m128)_mm_load_si128((const __m128i *)&v233);
          m_size = m_data[v9]->m_nodes.m_size;
          if ( m_size > 0 )
          {
            ++gNumAlignedAllocs;
            v12 = (btVector3 *)sAlignedAllocFunc(16 * m_size, 16);
            ptr = v12;
            v14 = v250.mVec128.m128_u64[1];
            v15 = v250.mVec128.m128_u64[0];
            v16 = (unsigned __int64 *)v12;
            v17 = m_size;
            do
            {
              if ( v16 )
              {
                *v16 = v15;
                v16[1] = v14;
              }
              v16 += 2;
              --v17;
            }
            while ( v17 );
          }
          v18 = 0;
          if ( m_size > 0 )
          {
            v19 = v12;
            do
            {
              p_m_x = &psb->m_clusters.m_data[v188]->m_nodes.m_data[v18]->m_x;
              *v19 = (btVector3)p_m_x->mVec128;
              ++v18;
              ++v19;
            }
            while ( v18 < m_size );
            v12 = (btVector3 *)ptr;
          }
          v251[16] = 1;
          memset(&v251[4], 0, 12);
          v251[36] = 1;
          memset(&v251[24], 0, 12);
          v251[56] = 1;
          memset(&v251[44], 0, 12);
          btConvexHullComputer::compute(
            (btConvexHullComputer *)v251,
            m_size,
            (char *)v12,
            lcolor_4,
            SHIDWORD(lcolor_4),
            lcolor_12,
            v187);
          for ( i = 0; i < *(int *)&v251[44]; ++i )
          {
            v22 = *(_DWORD *)&v251[32] + 12 * *(_DWORD *)(*(_DWORD *)&v251[52] + 4 * i);
            v21 = 3 * *(_DWORD *)(v22 + 12 * *(_DWORD *)(v22 + 4));
            v23 = v22 + 12 * *(_DWORD *)(v22 + 4) + 12 * *(_DWORD *)(v22 + 12 * *(_DWORD *)(v22 + 4));
            v24 = *(float *)(v22 + 8);
            v215 = *(float *)(v22 + 12 * *(_DWORD *)(v22 + 4) + 8);
            for ( j = v24; v23 != v22; j = v206 )
            {
              v206 = *(float *)(v23 + 8);
              ((void (__thiscall *)(btIDebugDraw *, int, int, int, btVector3 *, _DWORD))idraw->drawTriangle)(
                idraw,
                *(_DWORD *)&v251[12] + 16 * LODWORD(v215),
                *(_DWORD *)&v251[12] + 16 * LODWORD(j),
                *(_DWORD *)&v251[12] + 16 * LODWORD(v206),
                &v250,
                1.0);
              v25 = (_DWORD *)(v23 + 12 * *(_DWORD *)(v23 + 4));
              v21 = 3 * *v25;
              v23 = (int)&v25[3 * *v25];
              v215 = j;
            }
          }
          btConvexHullComputer::~btConvexHullComputer((btSoftBody::Cluster *)v21, (int)v251);
          if ( ptr )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(ptr);
          }
        }
        v8 = psb;
        v9 = ++v188;
      }
      while ( v188 < psb->m_clusters.m_size );
    }
    v5 = clear_value;
    goto LABEL_22;
  }
  v51 = 0;
  if ( (drawflags & 1) != 0 )
  {
    v192 = 0;
    if ( psb->m_nodes.m_size > 0 )
    {
      v52 = FLOAT_0_1;
      v201 = 0;
      do
      {
        v53 = &psb->m_nodes.m_data[v201];
        if ( (v53->m_material->m_flags & 1) != 0 )
        {
          v54 = idraw->__vftable;
          v213.mVec128.m128_f32[0] = v53->m_x.mVec128.m128_f32[0] + v52;
          *(unsigned __int64 *)((char *)v213.mVec128.m128_u64 + 4) = *(unsigned __int64 *)((char *)v53->m_x.mVec128.m128_u64
                                                                                         + 4);
          v55 = v53->m_x.mVec128.m128_f32[0] - v52;
          drawLine = v54->drawLine;
          v227 = v53->m_x.mVec128.m128_f32[1];
          v57 = v53->m_x.mVec128.m128_f32[2];
          v233.mVec128.m128_u64[0] = (unsigned int)v5;
          v233.mVec128.m128_u64[1] = 0;
          v213.mVec128.m128_i32[3] = 0;
          v226 = v55;
          v228 = v57;
          v229 = 0;
          drawLine(idraw, (const btVector3 *)&v226, &v213, &v233);
          v58 = v53->m_x.mVec128.m128_f32[1];
          v59 = idraw->__vftable;
          v237.mVec128.m128_u64[1] = (unsigned int)clear_value;
          v211.mVec128.m128_i32[0] = v53->m_x.mVec128.m128_i32[0];
          v211.mVec128.m128_f32[1] = v58 + 0.1;
          v211.mVec128.m128_u64[1] = v53->m_x.mVec128.m128_u32[2];
          v212.mVec128.m128_i32[0] = v53->m_x.mVec128.m128_i32[0];
          v60 = v59->drawLine;
          v61 = v53->m_x.mVec128.m128_f32[1] - 0.1;
          v62 = v53->m_x.mVec128.m128_i32[2];
          v237.mVec128.m128_i32[1] = 0;
          v238 = 0;
          v212.mVec128.m128_f32[1] = v61;
          v212.mVec128.m128_u64[1] = (unsigned int)v62;
          v60(idraw, &v212, &v211, (btVector3 *)&v237.m_floats[1]);
          v63 = v53->m_x.mVec128.m128_f32[2];
          v235 = *(float *)&clear_value;
          v217 = v53->m_x.mVec128.m128_f32[0];
          v218 = v53->m_x.mVec128.m128_f32[1];
          v219 = v63 + 0.1;
          v222 = v53->m_x.mVec128.m128_f32[0];
          v64 = v53->m_x.mVec128.m128_f32[1];
          v234 = 0;
          LODWORD(v236) = 0;
          v220 = 0;
          v65 = idraw->drawLine;
          v223 = v64;
          v224 = v53->m_x.mVec128.m128_f32[2] - 0.1;
          v225 = 0;
          v65(idraw, (const btVector3 *)&v222, (const btVector3 *)&v217, (const btVector3 *)&v234);
          v52 = FLOAT_0_1;
          v5 = clear_value;
        }
        ++v201;
        ++v192;
      }
      while ( v192 < psb->m_nodes.m_size );
      v6 = drawflags;
      v51 = 0;
    }
  }
  if ( (v6 & 2) != 0 )
  {
    v193 = 0;
    if ( psb->m_links.m_size > 0 )
    {
      do
      {
        v66 = psb->m_links.m_data;
        m_material = v66[v51].m_material;
        v68 = &v66[v51];
        if ( (m_material->m_flags & 1) != 0 )
        {
          idraw->drawLine(idraw, &v68->m_n[0]->m_x, &v68->m_n[1]->m_x, (const btVector3 *)v271);
          v5 = clear_value;
        }
        ++v51;
        ++v193;
      }
      while ( v193 < psb->m_links.m_size );
      v6 = drawflags;
    }
  }
  v69 = FLOAT_0_5;
  if ( (v6 & 0x10) != 0 )
  {
    v194 = 0;
    if ( psb->m_nodes.m_size > 0 )
    {
      v202 = 0;
      do
      {
        v70 = &psb->m_nodes.m_data[v202];
        if ( (v70->m_material->m_flags & 1) != 0 )
        {
          v71 = v70->m_n.mVec128.m128_f32[1];
          v72 = v70->m_n.mVec128.m128_f32[2];
          v73 = idraw->drawLine;
          m128_f32 = v70->m_x.mVec128.m128_f32;
          v211.mVec128.m128_f32[0] = v70->m_n.mVec128.m128_f32[0] * v69;
          v222 = v211.mVec128.m128_f32[0] + v70->m_x.mVec128.m128_f32[0];
          *(float *)&v75 = v71 * v69;
          v223 = v70->m_x.mVec128.m128_f32[1] + *(float *)&v75;
          *(float *)&v76 = v72 * v69;
          v77 = v70->m_x.mVec128.m128_f32[2] + *(float *)&v76;
          *(unsigned __int64 *)((char *)v211.mVec128.m128_u64 + 4) = __PAIR64__(v76, v75);
          v224 = v77;
          v225 = 0;
          v73(idraw, &v70->m_x, (const btVector3 *)&v222, (const btVector3 *)&v265);
          v78 = idraw->drawLine;
          v217 = *(float *)&v265 * 0.5;
          v218 = *(float *)&v266 * 0.5;
          v219 = *(float *)&v267 * 0.5;
          *(float *)&v234 = *m128_f32 - v211.mVec128.m128_f32[0];
          *((float *)&v234 + 1) = m128_f32[1] - v211.mVec128.m128_f32[1];
          v79 = m128_f32[2] - v211.mVec128.m128_f32[2];
          v220 = 0;
          v235 = v79;
          LODWORD(v236) = 0;
          v78(idraw, (const btVector3 *)m128_f32, (const btVector3 *)&v234, (const btVector3 *)&v217);
          v69 = FLOAT_0_5;
          v5 = clear_value;
        }
        ++v202;
        ++v194;
      }
      while ( v194 < psb->m_nodes.m_size );
      v6 = drawflags;
    }
  }
  if ( (v6 & 0x20) != 0 )
  {
    if ( (_S5_2 & 1) == 0 )
    {
      _S5_2 |= 1u;
      axis[0].mVec128.m128_i32[0] = (int)v5;
      dword_4C2B134 = 0;
      dword_4C2B138 = 0;
      dword_4C2B13C = 0;
      dword_4C2B140 = 0;
      dword_4C2B144 = (int)v5;
      dword_4C2B148 = 0;
      dword_4C2B14C = 0;
      dword_4C2B150 = 0;
      dword_4C2B154 = 0;
      dword_4C2B158 = (int)v5;
      dword_4C2B15C = 0;
    }
    v80 = 0;
    if ( psb->m_rcontacts.m_size > 0 )
    {
      v203 = 0;
      while ( 1 )
      {
        v81 = &psb->m_rcontacts.m_data[v203];
        m_node = (float *)v81->m_node;
        v83 = (float)((float)((float)(v81->m_cti.m_normal.mVec128.m128_f32[2] * m_node[6])
                            + (float)(v81->m_cti.m_normal.mVec128.m128_f32[1] * m_node[5]))
                    + (float)(v81->m_cti.m_normal.mVec128.m128_f32[0] * m_node[4]))
            + v81->m_cti.m_offset;
        v84 = v81->m_cti.m_normal.mVec128.m128_f32[1] * v83;
        v85 = v81->m_cti.m_normal.mVec128.m128_f32[0] * v83;
        *(float *)&v86 = m_node[6] - (float)(v81->m_cti.m_normal.mVec128.m128_f32[2] * v83);
        v87 = m_node[5] - v84;
        v212.mVec128.m128_f32[0] = m_node[4] - v85;
        v212.mVec128.m128_f32[1] = v87;
        v212.mVec128.m128_u64[1] = v86;
        v88 = v81->m_cti.m_normal.mVec128.m128_f32[1];
        v230 = *(float *)&v86;
        v89 = v81->m_cti.m_normal.mVec128.m128_f32[0];
        v231 = v87;
        if ( v88 <= v89 )
        {
          v90 = 1;
          if ( v81->m_cti.m_normal.mVec128.m128_f32[2] <= v88 )
LABEL_69:
            v90 = 2;
        }
        else
        {
          if ( v81->m_cti.m_normal.mVec128.m128_f32[2] <= v89 )
            goto LABEL_69;
          v90 = 0;
        }
        v91 = v81->m_cti.m_normal.mVec128.m128_f32[2];
        v92 = v81->m_cti.m_normal.mVec128.m128_f32[1];
        v93 = &axis[v90];
        v94 = v93->mVec128.m128_f32[2];
        v95 = v93->mVec128.m128_f32[1];
        v96 = (float)(v94 * v92) - (float)(v95 * v91);
        v97 = v93->mVec128.m128_f32[0] * v91;
        v98 = v93->mVec128.m128_f32[0] * v92;
        v99 = v81->m_cti.m_normal.mVec128.m128_f32[0];
        v211.mVec128.m128_f32[0] = v96;
        v211.mVec128.m128_f32[1] = v97 - (float)(v99 * v94);
        v211.mVec128.m128_f32[2] = (float)(v99 * v95) - v98;
        v100 = sqrtf(
                 (float)((float)(v96 * v96) + (float)(v211.mVec128.m128_f32[2] * v211.mVec128.m128_f32[2]))
               + (float)(v211.mVec128.m128_f32[1] * v211.mVec128.m128_f32[1]));
        v101 = v81->m_cti.m_normal.mVec128.m128_f32[2];
        v102 = v81->m_cti.m_normal.mVec128.m128_f32[1];
        v103 = v81->m_cti.m_normal.mVec128.m128_f32[0];
        v207 = 1.0 / v100;
        v104 = (float)(v101 * (float)(v207 * v211.mVec128.m128_f32[1]))
             - (float)(v102 * (float)(v207 * v211.mVec128.m128_f32[2]));
        v227 = v207 * v211.mVec128.m128_f32[1];
        v228 = v207 * v211.mVec128.m128_f32[2];
        v226 = v211.mVec128.m128_f32[0] * v207;
        v237.mVec128.m128_f32[1] = v104;
        v105 = (float)((float)(v211.mVec128.m128_f32[0] * v207) * v102)
             - (float)(v103 * (float)(v207 * v211.mVec128.m128_f32[1]));
        v106 = (float)(v103 * (float)(v207 * v211.mVec128.m128_f32[2]))
             - (float)((float)(v211.mVec128.m128_f32[0] * v207) * v101);
        v237.mVec128.m128_f32[2] = v106;
        v237.mVec128.m128_f32[3] = v105;
        v208 = 1.0 / sqrtf((float)((float)(v104 * v104) + (float)(v105 * v105)) + (float)(v106 * v106));
        v107 = idraw->__vftable;
        v213.mVec128.m128_f32[0] = v237.mVec128.m128_f32[1] * v208;
        v213.mVec128.m128_f32[1] = v208 * v237.mVec128.m128_f32[2];
        v213.mVec128.m128_f32[2] = v208 * v237.mVec128.m128_f32[3];
        v222 = (float)(v226 * 0.5) + v212.mVec128.m128_f32[0];
        v223 = v231 + (float)(v227 * 0.5);
        v108 = v107->drawLine;
        v224 = v230 + (float)(v228 * 0.5);
        v225 = 0;
        v217 = v212.mVec128.m128_f32[0] - (float)(v226 * 0.5);
        v218 = v231 - (float)(v227 * 0.5);
        v219 = v230 - (float)(v228 * 0.5);
        v220 = 0;
        v108(idraw, (const btVector3 *)&v217, (const btVector3 *)&v222, (const btVector3 *)v269);
        v109 = idraw->__vftable;
        *(float *)&v234 = (float)(v213.mVec128.m128_f32[0] * 0.5) + v212.mVec128.m128_f32[0];
        *((float *)&v234 + 1) = (float)(v213.mVec128.m128_f32[1] * 0.5) + v212.mVec128.m128_f32[1];
        v235 = (float)(v213.mVec128.m128_f32[2] * 0.5) + v212.mVec128.m128_f32[2];
        LODWORD(v236) = 0;
        v233.mVec128.m128_f32[0] = v212.mVec128.m128_f32[0] - (float)(v213.mVec128.m128_f32[0] * 0.5);
        v233.mVec128.m128_f32[1] = v212.mVec128.m128_f32[1] - (float)(v213.mVec128.m128_f32[1] * 0.5);
        v233.mVec128.m128_f32[2] = v212.mVec128.m128_f32[2] - (float)(v213.mVec128.m128_f32[2] * 0.5);
        v233.mVec128.m128_i32[3] = 0;
        v109->drawLine(idraw, &v233, (const btVector3 *)&v234, (const btVector3 *)v269);
        v110 = v81->m_cti.m_normal.mVec128.m128_f32[1];
        v111 = v81->m_cti.m_normal.mVec128.m128_f32[2];
        v112 = idraw->__vftable;
        v243 = *(float *)&clear_value;
        v244 = *(float *)&clear_value;
        v113 = v112->drawLine;
        v114 = (float)((float)(v81->m_cti.m_normal.mVec128.m128_f32[0] * 0.5) * 3.0) + v212.mVec128.m128_f32[0];
        v245 = 0.0;
        v246 = 0;
        v239 = v114;
        v240 = (float)((float)(v110 * 0.5) * 3.0) + v212.mVec128.m128_f32[1];
        v241 = (float)((float)(v111 * 0.5) * 3.0) + v212.mVec128.m128_f32[2];
        v242 = 0;
        v113(idraw, &v212, (const btVector3 *)&v239, (const btVector3 *)&v243);
        ++v203;
        if ( ++v80 >= psb->m_rcontacts.m_size )
        {
          v5 = clear_value;
          break;
        }
      }
    }
  }
  if ( (drawflags & 4) != 0 )
  {
    v115 = 0;
    v116 = psb->m_faces.m_size <= 0;
    v239 = 0.0;
    v240 = 0.69999999;
    v241 = 0.0;
    v242 = 0;
    v195 = 0;
    if ( !v116 )
    {
      do
      {
        v117 = psb->m_faces.m_data;
        v118 = v117[v115].m_material;
        v119 = &v117[v115];
        if ( (v118->m_flags & 1) != 0 )
        {
          v120 = v119->m_n[0];
          *(_QWORD *)v251 = v120->m_x.mVec128.m128_u64[0];
          v121 = v120->m_x.mVec128.m128_i64[1];
          v122 = v119->m_n[1];
          v123 = v119->m_n[2];
          *(_QWORD *)&v251[8] = v121;
          *(_QWORD *)&v251[16] = v122->m_x.mVec128.m128_u64[0];
          *(_QWORD *)&v251[24] = v122->m_x.mVec128.m128_u64[1];
          *(_QWORD *)&v251[32] = v123->m_x.mVec128.m128_u64[0];
          *(_QWORD *)&v251[40] = v123->m_x.mVec128.m128_u64[1];
          v124 = (float)(*(float *)&v251[36] + (float)(*(float *)&v251[20] + *(float *)&v251[4])) * 0.33333334;
          v125 = (float)(*(float *)&v251[40] + (float)(*(float *)&v251[24] + *(float *)&v121)) * 0.33333334;
          *(float *)&v121 = (float)((float)(*(float *)v251 + *(float *)&v251[16]) + *(float *)&v251[32]) * 0.33333334;
          v213.mVec128.m128_f32[0] = *(float *)&v251[32] - *(float *)&v121;
          v213.mVec128.m128_f32[1] = *(float *)&v251[36] - v124;
          v213.mVec128.m128_f32[2] = *(float *)&v251[40] - v125;
          v226 = (float)(*(float *)&v251[32] - *(float *)&v121) * 0.80000001;
          v227 = (float)(*(float *)&v251[36] - v124) * 0.80000001;
          v228 = (float)(*(float *)&v251[40] - v125) * 0.80000001;
          v243 = v226 + *(float *)&v121;
          v244 = v227 + v124;
          v245 = v228 + v125;
          v256.mVec128.m128_f32[1] = *(float *)&v251[20] - v124;
          v250.mVec128.m128_f32[0] = (float)(*(float *)&v251[16] - *(float *)&v121) * 0.80000001;
          v250.mVec128.m128_f32[2] = (float)(*(float *)&v251[24] - v125) * 0.80000001;
          v223 = (float)((float)(*(float *)&v251[20] - v124) * 0.80000001) + v124;
          v246 = 0;
          v222 = v250.mVec128.m128_f32[0] + *(float *)&v121;
          drawTriangle = idraw->drawTriangle;
          v224 = v250.mVec128.m128_f32[2] + v125;
          v225 = 0;
          v217 = (float)((float)(*(float *)v251 - *(float *)&v121) * 0.80000001) + *(float *)&v121;
          v218 = (float)((float)(*(float *)&v251[4] - v124) * 0.80000001) + v124;
          v219 = (float)((float)(*(float *)&v251[8] - v125) * 0.80000001) + v125;
          v220 = 0;
          ((void (__thiscall *)(btIDebugDraw *, float *, float *, float *, float *, _DWORD))drawTriangle)(
            idraw,
            &v217,
            &v222,
            &v243,
            &v239,
            1.0);
          v5 = clear_value;
        }
        ++v115;
        ++v195;
      }
      while ( v195 < psb->m_faces.m_size );
    }
  }
  if ( (drawflags & 8) != 0 )
  {
    v127 = 0;
    v116 = psb->m_tetras.m_size <= 0;
    v211.mVec128.m128_f32[0] = s_aim_transition_time;
    v211.mVec128.m128_f32[1] = s_aim_transition_time;
    v211.mVec128.m128_u64[1] = 1060320051;
    if ( !v116 )
    {
      v128 = 0;
      v129 = psb;
      do
      {
        v130 = v129->m_tetras.m_data;
        v131 = v130[v128].m_material;
        v132 = &v130[v128];
        if ( (v131->m_flags & 1) != 0 )
        {
          v133 = v132->m_n[0];
          *(_QWORD *)v251 = v133->m_x.mVec128.m128_u64[0];
          *(_QWORD *)&v251[8] = v133->m_x.mVec128.m128_u64[1];
          v134 = v132->m_n[1];
          *(_QWORD *)&v251[16] = v134->m_x.mVec128.m128_u64[0];
          *(_QWORD *)&v251[24] = v134->m_x.mVec128.m128_u64[1];
          v135 = v132->m_n[2];
          v136 = v132->m_n[3];
          *(_QWORD *)&v251[32] = v135->m_x.mVec128.m128_u64[0];
          *(_QWORD *)&v251[40] = v135->m_x.mVec128.m128_u64[1];
          *(_QWORD *)&v251[48] = v136->m_x.mVec128.m128_u64[0];
          *(_QWORD *)&v251[56] = v136->m_x.mVec128.m128_u64[1];
          v250.mVec128.m128_f32[1] = *(float *)&v251[36] + (float)(*(float *)&v251[20] + *(float *)&v251[4]);
          v250.mVec128.m128_f32[2] = *(float *)&v251[40] + (float)(*(float *)&v251[24] + *(float *)&v251[8]);
          v137 = (float)(*(float *)&v251[48]
                       + (float)(*(float *)&v251[32] + (float)(*(float *)&v251[16] + *(float *)v251)))
               * 0.25;
          v138 = (float)(*(float *)&v251[52] + v250.mVec128.m128_f32[1]) * 0.25;
          v139 = (float)(*(float *)&v251[56] + v250.mVec128.m128_f32[2]) * 0.25;
          v230 = *(float *)&v251[32] - v137;
          v213.mVec128.m128_f32[0] = *(float *)&v251[32] - v137;
          v231 = *(float *)&v251[36] - v138;
          v213.mVec128.m128_f32[1] = *(float *)&v251[36] - v138;
          v209 = *(float *)&v251[40] - v139;
          v213.mVec128.m128_f32[2] = *(float *)&v251[40] - v139;
          v226 = (float)(*(float *)&v251[32] - v137) * 0.80000001;
          v227 = (float)(*(float *)&v251[36] - v138) * 0.80000001;
          v228 = (float)(*(float *)&v251[40] - v139) * 0.80000001;
          v239 = v226 + v137;
          v240 = v227 + v138;
          v212.mVec128.m128_f32[0] = v137;
          v212.mVec128.m128_f32[1] = v138;
          v212.mVec128.m128_f32[2] = v139;
          v140 = idraw->drawTriangle;
          v241 = v228 + v139;
          v215 = *(float *)&v251[16] - v137;
          *(float *)&v269[5] = *(float *)&v251[20] - v138;
          v216 = *(float *)&v251[20] - v138;
          v256.mVec128.m128_f32[0] = (float)(*(float *)&v251[16] - v137) * 0.80000001;
          v237.mVec128.m128_f32[0] = *(float *)&v251[24] - v139;
          v256.mVec128.m128_f32[2] = (float)(*(float *)&v251[24] - v139) * 0.80000001;
          v244 = (float)((float)(*(float *)&v251[20] - v138) * 0.80000001) + v138;
          v243 = v256.mVec128.m128_f32[0] + v137;
          v245 = v256.mVec128.m128_f32[2] + v139;
          v247 = *(float *)v251 - v137;
          v248 = *(float *)&v251[4] - v138;
          v249 = *(float *)&v251[8] - v139;
          v242 = 0;
          v246 = 0;
          v222 = (float)((float)(*(float *)v251 - v137) * 0.80000001) + v137;
          v223 = (float)((float)(*(float *)&v251[4] - v138) * 0.80000001) + v138;
          v224 = (float)((float)(*(float *)&v251[8] - v139) * 0.80000001) + v139;
          v225 = 0;
          ((void (__thiscall *)(btIDebugDraw *, float *, float *, float *, btVector3 *, _DWORD))v140)(
            idraw,
            &v222,
            &v243,
            &v239,
            &v211,
            1.0);
          v204 = *(float *)&v251[48] - v212.mVec128.m128_f32[0];
          j = *(float *)&v251[52] - v212.mVec128.m128_f32[1];
          v196 = *(float *)&v251[56] - v212.mVec128.m128_f32[2];
          v141 = idraw->drawTriangle;
          v217 = (float)((float)(*(float *)&v251[48] - v212.mVec128.m128_f32[0]) * 0.80000001)
               + v212.mVec128.m128_f32[0];
          v218 = (float)((float)(*(float *)&v251[52] - v212.mVec128.m128_f32[1]) * 0.80000001)
               + v212.mVec128.m128_f32[1];
          v219 = (float)((float)(*(float *)&v251[56] - v212.mVec128.m128_f32[2]) * 0.80000001)
               + v212.mVec128.m128_f32[2];
          *(float *)&v234 = (float)(v215 * 0.80000001) + v212.mVec128.m128_f32[0];
          *((float *)&v234 + 1) = (float)(v216 * 0.80000001) + v212.mVec128.m128_f32[1];
          v235 = (float)(v237.mVec128.m128_f32[0] * 0.80000001) + v212.mVec128.m128_f32[2];
          v220 = 0;
          LODWORD(v236) = 0;
          v233.mVec128.m128_f32[0] = (float)(v247 * 0.80000001) + v212.mVec128.m128_f32[0];
          v233.mVec128.m128_f32[1] = (float)(v248 * 0.80000001) + v212.mVec128.m128_f32[1];
          v233.mVec128.m128_f32[2] = (float)(v249 * 0.80000001) + v212.mVec128.m128_f32[2];
          v233.mVec128.m128_i32[3] = 0;
          ((void (__thiscall *)(btIDebugDraw *, btVector3 *, __int64 *, float *, btVector3 *, _DWORD))v141)(
            idraw,
            &v233,
            &v234,
            &v217,
            &v211,
            1.0);
          v237.mVec128.m128_f32[1] = (float)(v204 * 0.80000001) + v212.mVec128.m128_f32[0];
          v237.mVec128.m128_f32[2] = (float)(j * 0.80000001) + v212.mVec128.m128_f32[1];
          v237.mVec128.m128_f32[3] = (float)(v196 * 0.80000001) + v212.mVec128.m128_f32[2];
          v257 = (float)(v230 * 0.80000001) + v212.mVec128.m128_f32[0];
          v258 = (float)(v231 * 0.80000001) + v212.mVec128.m128_f32[1];
          v238 = 0;
          v259 = (float)(v209 * 0.80000001) + v212.mVec128.m128_f32[2];
          v260 = 0;
          v142 = idraw->drawTriangle;
          v261 = (float)(v215 * 0.80000001) + v212.mVec128.m128_f32[0];
          v262 = (float)(v216 * 0.80000001) + v212.mVec128.m128_f32[1];
          v263 = (float)(v237.mVec128.m128_f32[0] * 0.80000001) + v212.mVec128.m128_f32[2];
          v264 = 0;
          ((void (__thiscall *)(btIDebugDraw *, float *, float *, float *, btVector3 *, _DWORD))v142)(
            idraw,
            &v261,
            &v257,
            &v237.m_floats[1],
            &v211,
            1.0);
          v143 = idraw->__vftable;
          v252 = (float)(v204 * 0.80000001) + v212.mVec128.m128_f32[0];
          v253 = (float)(j * 0.80000001) + v212.mVec128.m128_f32[1];
          v254 = (float)(v196 * 0.80000001) + v212.mVec128.m128_f32[2];
          v221.mVec128.m128_f32[0] = (float)(v247 * 0.80000001) + v212.mVec128.m128_f32[0];
          v221.mVec128.m128_f32[1] = (float)(v248 * 0.80000001) + v212.mVec128.m128_f32[1];
          v221.mVec128.m128_f32[2] = (float)(v249 * 0.80000001) + v212.mVec128.m128_f32[2];
          v255 = 0;
          v221.mVec128.m128_i32[3] = 0;
          v214.mVec128.m128_f32[0] = (float)(v230 * 0.80000001) + v212.mVec128.m128_f32[0];
          v214.mVec128.m128_f32[1] = (float)(v231 * 0.80000001) + v212.mVec128.m128_f32[1];
          v214.mVec128.m128_f32[2] = (float)(v209 * 0.80000001) + v212.mVec128.m128_f32[2];
          v214.mVec128.m128_i32[3] = 0;
          ((void (__thiscall *)(btIDebugDraw *, btVector3 *, btVector3 *, float *, btVector3 *, _DWORD))v143->drawTriangle)(
            idraw,
            &v214,
            &v221,
            &v252,
            &v211,
            1.0);
          v5 = clear_value;
          v129 = psb;
        }
        ++v127;
        ++v128;
      }
      while ( v127 < v129->m_tetras.m_size );
    }
  }
LABEL_22:
  if ( (drawflags & 0x40) != 0 )
  {
    v189 = 0;
    if ( psb->m_anchors.m_size > 0 )
    {
      v199 = 0;
      do
      {
        v26 = &psb->m_anchors.m_data[v199];
        m_body = (float *)v26->m_body;
        v28 = v26->m_local.mVec128.m128_f32[1];
        v29 = v26->m_local.mVec128.m128_f32[2];
        v30 = m_body[13];
        v31 = m_body[14];
        v32 = m_body[10];
        m_body += 4;
        *(float *)&v33 = (float)((float)((float)(v30 * v28) + (float)(v31 * v29))
                               + (float)(v26->m_local.mVec128.m128_f32[0] * m_body[8]))
                       + m_body[14];
        v34 = (float)((float)((float)(m_body[5] * v28) + (float)(v32 * v29))
                    + (float)(v26->m_local.mVec128.m128_f32[0] * m_body[4]))
            + m_body[13];
        v213.mVec128.m128_f32[0] = (float)((float)((float)(m_body[1] * v28) + (float)(m_body[2] * v29))
                                         + (float)(v26->m_local.mVec128.m128_f32[0] * *m_body))
                                 + m_body[12];
        v213.mVec128.m128_f32[1] = v34;
        v213.mVec128.m128_u64[1] = v33;
        v35 = &v26->m_node->m_x;
        v214.mVec128.m128_u64[0] = (unsigned int)v5;
        v214.mVec128.m128_u64[1] = 0;
        drawVertex(idraw, v35, 0.25, &v214);
        v221.mVec128.m128_i32[0] = 0;
        *(unsigned __int64 *)((char *)v221.mVec128.m128_u64 + 4) = (unsigned int)clear_value;
        v221.mVec128.m128_i32[3] = 0;
        drawVertex(idraw, &v213, 0.25, &v221);
        v36 = idraw->drawLine;
        v37 = v26->m_node;
        v252 = *(float *)&clear_value;
        v253 = *(float *)&clear_value;
        v254 = *(float *)&clear_value;
        v255 = 0;
        v36(idraw, &v37->m_x, &v213, (const btVector3 *)&v252);
        ++v199;
        v5 = clear_value;
        ++v189;
      }
      while ( v189 < psb->m_anchors.m_size );
    }
    v38 = psb;
    v39 = 0;
    for ( k = 0; k < v38->m_nodes.m_size; ++k )
    {
      v40 = v38->m_nodes.m_data;
      v41 = v40[v39].m_material;
      v42 = (const btVector3 *)&v40[v39];
      if ( (v41->m_flags & 1) != 0 && v42[6].mVec128.m128_f32[0] <= 0.0 )
      {
        v214.mVec128.m128_u64[0] = (unsigned int)v5;
        v214.mVec128.m128_u64[1] = 0;
        drawVertex(idraw, v42 + 1, 0.25, &v214);
        v5 = clear_value;
        v38 = psb;
      }
      ++v39;
    }
  }
  if ( (drawflags & 0x80u) == 0 )
  {
    v50 = psb;
  }
  else
  {
    v191 = 0;
    if ( psb->m_notes.m_size > 0 )
    {
      v200 = 0;
      do
      {
        v43 = &psb->m_notes.m_data[v200];
        v44 = 0;
        v211.mVec128 = (__m128)v43->m_offset;
        if ( v43->m_rank > 0 )
        {
          v45 = v211.mVec128.m128_f32[2];
          v46 = v211.mVec128.m128_f32[1];
          v47 = v211.mVec128.m128_f32[0];
          m_coords = v43->m_coords;
          do
          {
            v49 = (float *)*((_DWORD *)m_coords - 4);
            v47 = (float)(*m_coords * v49[4]) + v47;
            v46 = v46 + (float)(v49[5] * *m_coords);
            v45 = v45 + (float)(v49[6] * *m_coords);
            ++v44;
            v211.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v46), LODWORD(v47));
            v211.mVec128.m128_f32[2] = v45;
            ++m_coords;
          }
          while ( v44 < v43->m_rank );
        }
        idraw->draw3dText(idraw, &v211, v43->m_text);
        ++v200;
        ++v191;
      }
      while ( v191 < psb->m_notes.m_size );
      v5 = clear_value;
    }
    v50 = psb;
  }
  if ( (drawflags & 0x200) != 0 )
  {
    m_root = v50->m_ndbvt.m_root;
    v214.mVec128.m128_i32[0] = (int)v5;
    v214.mVec128.m128_i32[1] = (int)v5;
    v214.mVec128.m128_u64[1] = (unsigned int)v5;
    v221.mVec128.m128_u64[0] = (unsigned int)v5;
    v221.mVec128.m128_u64[1] = (unsigned int)v5;
    drawTree(idraw, m_root, 0, &v221, &v214, 0, -1);
    v5 = clear_value;
  }
  if ( (drawflags & 0x400) != 0 )
  {
    v183 = v50->m_fdbvt.m_root;
    v214.mVec128.m128_u64[0] = (unsigned int)v5;
    v214.mVec128.m128_u64[1] = 0;
    v221.mVec128.m128_i32[0] = 0;
    *(unsigned __int64 *)((char *)v221.mVec128.m128_u64 + 4) = (unsigned int)v5;
    v221.mVec128.m128_i32[3] = 0;
    drawTree(idraw, v183, 0, &v221, &v214, 0, -1);
    v5 = clear_value;
  }
  if ( (drawflags & 0x800) != 0 )
  {
    v184 = v50->m_cdbvt.m_root;
    v214.mVec128.m128_u64[0] = (unsigned int)v5;
    v214.mVec128.m128_u64[1] = 0;
    v221.mVec128.m128_i32[0] = 0;
    v221.mVec128.m128_i32[1] = (int)v5;
    v221.mVec128.m128_u64[1] = (unsigned int)v5;
    drawTree(idraw, v184, 0, &v221, &v214, 0, -1);
  }
  if ( (drawflags & 0x1000) != 0 )
  {
    v197 = 0;
    if ( v50->m_joints.m_size > 0 )
    {
      while ( 1 )
      {
        v144 = v50->m_joints.m_data[v197];
        v145 = v144->Type(v144);
        if ( !v145 )
          break;
        if ( v145 == 1 )
        {
          v212.mVec128 = (__m128)btSoftBody::Body::xform(v146, &v144->m_bodies[0].m_soft)->m_origin;
          v211.mVec128 = (__m128)btSoftBody::Body::xform(v147, &v144->m_bodies[1].m_soft)->m_origin;
          v149 = (float *)btSoftBody::Body::xform(v148, &v144->m_bodies[0].m_soft);
          v150 = v144->m_refs[0].mVec128.m128_f32[2];
          v151 = v144->m_refs[0].mVec128.m128_f32[1];
          v152 = v144->m_refs[0].mVec128.m128_f32[0];
          v153 = v149[6];
          v213.mVec128.m128_f32[0] = (float)((float)(v149[1] * v151) + (float)(v149[2] * v150)) + (float)(*v149 * v152);
          v213.mVec128.m128_f32[1] = (float)((float)(v149[5] * v151) + (float)(v153 * v150)) + (float)(v149[4] * v152);
          v213.mVec128.m128_f32[2] = (float)((float)(v149[9] * v151) + (float)(v149[10] * v150))
                                   + (float)(v149[8] * v152);
          v155 = (float *)btSoftBody::Body::xform(v154, &v144->m_bodies[1].m_soft);
          v156 = v144->m_refs[1].mVec128.m128_f32[2];
          v157 = v144->m_refs[1].mVec128.m128_f32[1];
          v158 = v144->m_refs[1].mVec128.m128_f32[0];
          v159 = v155[6];
          v226 = (float)((float)(v155[1] * v157) + (float)(v155[2] * v156)) + (float)(v158 * *v155);
          v227 = (float)((float)(v155[5] * v157) + (float)(v159 * v156)) + (float)(v158 * v155[4]);
          v228 = (float)((float)(v155[9] * v157) + (float)(v155[10] * v156)) + (float)(v155[8] * v158);
          v214.mVec128.m128_i32[0] = (int)clear_value;
          *(unsigned __int64 *)((char *)v214.mVec128.m128_u64 + 4) = (unsigned int)clear_value;
          v160 = idraw->drawLine;
          v210 = v213.mVec128.m128_f32[0] * 10.0;
          v231 = v213.mVec128.m128_f32[1] * 10.0;
          v221.mVec128.m128_f32[1] = v212.mVec128.m128_f32[1] + (float)(v213.mVec128.m128_f32[1] * 10.0);
          v214.mVec128.m128_i32[3] = 0;
          v230 = v213.mVec128.m128_f32[2] * 10.0;
          v221.mVec128.m128_f32[0] = (float)(v213.mVec128.m128_f32[0] * 10.0) + v212.mVec128.m128_f32[0];
          v221.mVec128.m128_f32[2] = v212.mVec128.m128_f32[2] + (float)(v213.mVec128.m128_f32[2] * 10.0);
          v221.mVec128.m128_i32[3] = 0;
          v160(idraw, &v212, &v221, &v214);
          v161 = idraw->__vftable;
          v252 = *(float *)&clear_value;
          v253 = *(float *)&clear_value;
          v249 = v226 * 10.0;
          v248 = v227 * 10.0;
          v162 = v161->drawLine;
          v247 = v228 * 10.0;
          v254 = 0.0;
          v255 = 0;
          v261 = (float)(v226 * 10.0) + v212.mVec128.m128_f32[0];
          v262 = (float)(v227 * 10.0) + v212.mVec128.m128_f32[1];
          v263 = (float)(v228 * 10.0) + v212.mVec128.m128_f32[2];
          v264 = 0;
          v162(idraw, &v212, (const btVector3 *)&v261, (const btVector3 *)&v252);
          v258 = *(float *)&clear_value;
          v259 = *(float *)&clear_value;
          v239 = v210 + v211.mVec128.m128_f32[0];
          v257 = 0.0;
          v260 = 0;
          v240 = v211.mVec128.m128_f32[1] + v231;
          v163 = idraw->drawLine;
          v241 = v211.mVec128.m128_f32[2] + v230;
          v242 = 0;
          v163(idraw, &v211, (const btVector3 *)&v239, (const btVector3 *)&v257);
          v164 = idraw->drawLine;
          v244 = *(float *)&clear_value;
          v245 = *(float *)&clear_value;
          v243 = 0.0;
          v246 = 0;
          v222 = v249 + v211.mVec128.m128_f32[0];
          v223 = v248 + v211.mVec128.m128_f32[1];
          v224 = v247 + v211.mVec128.m128_f32[2];
          v225 = 0;
          v164(idraw, &v211, (const btVector3 *)&v222, (const btVector3 *)&v243);
LABEL_97:
          v50 = psb;
        }
        if ( ++v197 >= v50->m_joints.m_size )
          return;
      }
      LODWORD(v215) = v144->m_bodies;
      v165 = (float *)btSoftBody::Body::xform(v146, &v144->m_bodies[0].m_soft);
      v166 = v144->m_refs[0].mVec128.m128_f32[2];
      v167 = v144->m_refs[0].mVec128.m128_f32[1];
      v168 = v144->m_refs[0].mVec128.m128_f32[0];
      *(float *)&v169 = (float)((float)((float)(v165[5] * v167) + (float)(v165[6] * v166)) + (float)(v165[4] * v168))
                      + v165[13];
      *(float *)&v170 = (float)((float)((float)(v165[1] * v167) + (float)(v165[2] * v166)) + (float)(*v165 * v168))
                      + v165[12];
      v237.mVec128.m128_f32[3] = (float)((float)((float)(v165[9] * v167) + (float)(v165[10] * v166))
                                       + (float)(v165[8] * v168))
                               + v165[14];
      *(unsigned __int64 *)((char *)v237.mVec128.m128_u64 + 4) = __PAIR64__(v169, v170);
      v238 = 0;
      LODWORD(v216) = &v144->m_bodies[1];
      v172 = (float *)btSoftBody::Body::xform(v171, &v144->m_bodies[1].m_soft);
      v173 = v144->m_refs[1].mVec128.m128_f32[1];
      v174 = v144->m_refs[1].mVec128.m128_f32[2];
      v175 = v144->m_refs[1].mVec128.m128_f32[0];
      *(float *)&v176 = (float)((float)((float)(v172[9] * v173) + (float)(v172[10] * v174)) + (float)(v172[8] * v175))
                      + v172[14];
      v177 = (float)((float)((float)(v172[1] * v173) + (float)(v172[2] * v174)) + (float)(v175 * *v172)) + v172[12];
      v233.mVec128.m128_f32[1] = (float)((float)((float)(v172[5] * v173) + (float)(v172[6] * v174))
                                       + (float)(v175 * v172[4]))
                               + v172[13];
      v233.mVec128.m128_u64[1] = v176;
      v233.mVec128.m128_f32[0] = v177;
      v217 = *(float *)&clear_value;
      v218 = *(float *)&clear_value;
      v219 = 0.0;
      v220 = 0;
      v179 = btSoftBody::Body::xform(v178, (_DWORD *)LODWORD(v215));
      idraw->drawLine(idraw, &v179->m_origin, (btVector3 *)&v237.m_floats[1], (const btVector3 *)&v217);
      LODWORD(v234) = 0;
      HIDWORD(v234) = clear_value;
      v235 = *(float *)&clear_value;
      LODWORD(v236) = 0;
      v181 = btSoftBody::Body::xform(v180, (_DWORD *)LODWORD(v216));
      idraw->drawLine(idraw, &v181->m_origin, &v233, (const btVector3 *)&v234);
      v256.mVec128.m128_i32[0] = (int)clear_value;
      *(unsigned __int64 *)((char *)v256.mVec128.m128_u64 + 4) = (unsigned int)clear_value;
      v256.mVec128.m128_i32[3] = 0;
      drawVertex(idraw, (btVector3 *)&v237.m_floats[1], 0.25, &v256);
      v250.mVec128.m128_i32[0] = 0;
      v250.mVec128.m128_i32[1] = (int)clear_value;
      v250.mVec128.m128_u64[1] = (unsigned int)clear_value;
      drawVertex(idraw, &v233, 0.25, &v250);
      goto LABEL_97;
    }
  }
}
