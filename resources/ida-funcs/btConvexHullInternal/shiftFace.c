char __userpurge btConvexHullInternal::shiftFace@<al>(
        btConvexHullInternal *a1@<ecx>,
        btConvexHullInternal::Face *a2@<edi>,
        float a3@<xmm0>,
        btConvexHullInternal *this,
        btConvexHullInternal::Face *face,
        btAlignedObjectArray<btConvexHullInternal::Vertex *> stack)
{
  btVector3 *BtNormal; // eax
  float v7; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  bool v11; // zf
  float v12; // xmm0_4
  float v13; // xmm0_4
  int v14; // edi
  int v15; // eax
  int v16; // ebx
  int x; // ecx
  int v19; // esi
  int v20; // ecx
  int nearbyVertex; // eax
  btConvexHullInternal::Edge *v22; // ebx
  btConvexHullInternal::Vertex *v23; // ecx
  int v24; // eax
  btConvexHullInternal::Rational128 *v25; // ecx
  btConvexHullInternal::Edge *next; // esi
  btConvexHullInternal::Rational128 *v27; // eax
  btConvexHullInternal::Rational128 *v28; // ecx
  btPairSet *v29; // ecx
  btConvexHullInternal::Rational128 *v30; // eax
  btConvexHullInternal::Rational128 *v31; // ecx
  btConvexHullInternal::Edge *v32; // edi
  int v33; // ecx
  btConvexHullInternal::Edge *v34; // esi
  btConvexHullInternal::Edge *v35; // ebx
  btConvexHullInternal::Rational128 *v36; // eax
  btConvexHullInternal::Rational128 *v37; // ecx
  btConvexHullInternal::Vertex *v38; // edx
  btConvexHullInternal::Rational128 *v39; // eax
  btConvexHullInternal::Rational128 *v40; // ecx
  btConvexHullInternal::Vertex *v41; // eax
  btConvexHullInternal::Edge *prev; // esi
  btConvexHullInternal::Edge ***p_edges; // ebx
  btConvexHullInternal::Rational128 *v44; // edi
  btConvexHullInternal::Rational128 *v45; // eax
  btConvexHullInternal::Rational128 *v46; // ecx
  int v47; // eax
  int v48; // edx
  btConvexHullInternal::Vertex *v49; // edx
  btConvexHullInternal::Vertex **p_target; // eax
  btConvexHullInternal::Edge **p_reverse; // esi
  btConvexHullInternal::Edge *v52; // eax
  btConvexHullInternal::Edge *v53; // ecx
  btConvexHullInternal::Edge *v54; // ecx
  btConvexHullInternal::Edge *v55; // edx
  btConvexHullInternal::Face *v56; // ebx
  __int64 v57; // rax
  int v58; // ecx
  __int64 v59; // rax
  unsigned int v60; // ebx
  int v61; // ecx
  btConvexHullInternal::Int128 *v62; // esi
  unsigned int v63; // ecx
  btConvexHullInternal::Int128 *v64; // eax
  btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *v65; // ecx
  btConvexHullInternal::Vertex *v66; // eax
  __int64 z; // rdi
  btConvexHullInternal::Int128 *v68; // eax
  btConvexHullInternal::Int128 *v69; // eax
  btConvexHullInternal::Int128 *v70; // eax
  btConvexHullInternal::Int128 *v71; // eax
  btConvexHullInternal::Int128 *v72; // eax
  btConvexHullInternal::Int128 *v73; // eax
  int y; // eax
  int v75; // ebx
  btConvexHullInternal::Int128 *v76; // eax
  unsigned int v77; // ecx
  btConvexHullInternal::Int128 *v78; // eax
  btConvexHullInternal::Int128 *v79; // eax
  btConvexHullInternal::Int128 *v80; // eax
  btConvexHullInternal::Int128 *v81; // eax
  int v82; // ebx
  btConvexHullInternal::Int128 *v83; // eax
  unsigned int v84; // ecx
  btConvexHullInternal::Int128 *v85; // eax
  btConvexHullInternal::Int128 *v86; // eax
  btConvexHullInternal::Int128 *v87; // eax
  btConvexHullInternal::Int128 *v88; // eax
  btConvexHullInternal::Int128 *v89; // eax
  btConvexHullInternal::Int128 *v90; // eax
  btConvexHullInternal::Int128 *v91; // ebx
  const void *v92; // eax
  double v93; // st7
  btConvexHullInternal::Vertex *v94; // esi
  double v95; // st7
  double v96; // st7
  btConvexHullInternal::Vertex **v97; // edx
  btConvexHullInternal::Edge *v98; // eax
  int v99; // eax
  int v100; // ecx
  int v101; // ebx
  btConvexHullInternal::Vertex **v102; // edi
  int v103; // ecx
  btConvexHullInternal::Vertex **v104; // edx
  btConvexHullInternal::Vertex **v105; // edx
  int v106; // eax
  int v107; // esi
  btConvexHullInternal::Vertex **v108; // eax
  btConvexHullInternal::Vertex **v109; // ebx
  int v110; // ecx
  btConvexHullInternal::Vertex **v111; // edx
  btConvexHullInternal::Vertex **v112; // edx
  int v113; // eax
  int v114; // esi
  btConvexHullInternal::Vertex **v115; // eax
  btConvexHullInternal::Vertex **v116; // ebx
  int v117; // ecx
  btConvexHullInternal::Vertex **v118; // edx
  btConvexHullInternal::Vertex **v119; // edx
  int v120; // eax
  btConvexHullInternal::Edge *v121; // eax
  btConvexHullInternal::Edge *v122; // ebx
  btConvexHullInternal::Edge *v123; // eax
  btConvexHullInternal::Edge *v124; // ecx
  btConvexHullInternal::Edge *v125; // eax
  btConvexHullInternal::Edge *v126; // ecx
  btConvexHullInternal::Edge *v127; // ebx
  btConvexHullInternal::Edge *v128; // eax
  int v129; // esi
  btConvexHullInternal::Vertex **v130; // ebx
  int v131; // ecx
  btConvexHullInternal::Vertex **v132; // edx
  btConvexHullInternal::Vertex **v133; // edx
  int v134; // eax
  btConvexHullInternal::Edge *v135; // eax
  int v136; // eax
  int v137; // esi
  btConvexHullInternal::Vertex **v138; // ebx
  int v139; // ecx
  int v140; // edx
  btConvexHullInternal::Vertex **v141; // eax
  btConvexHullInternal::Vertex **v142; // edx
  int v143; // esi
  btConvexHullInternal::Vertex **v144; // ebx
  int v145; // ecx
  btConvexHullInternal::Vertex **v146; // edx
  btConvexHullInternal::Vertex **v147; // ecx
  btConvexHullInternal::Vertex *v148; // edx
  btConvexHullInternal::Edge *v149; // ecx
  btConvexHullInternal::Edge *v150; // ecx
  btConvexHullInternal::Edge *edges; // eax
  btConvexHullInternal::Edge *reverse; // eax
  int m_size; // edx
  btConvexHullInternal::Vertex **m_data; // eax
  int v155; // ebx
  btConvexHullInternal::Vertex *v156; // esi
  btConvexHullInternal::Edge *v157; // ebx
  btConvexHullInternal::Vertex *v158; // edx
  btConvexHullInternal::Face *lastNearbyFace; // eax
  int v160; // edx
  int v161; // esi
  btConvexHullInternal::Vertex **v162; // eax
  btConvexHullInternal::Vertex **v163; // ebx
  int v164; // eax
  btConvexHullInternal::Vertex **v165; // ecx
  btConvexHullInternal::Vertex **v166; // ecx
  btConvexHullInternal::Edge **p_next; // ebx
  int v168; // edx
  btConvexHullInternal::Edge *v169; // eax
  int v170; // edx
  int v171; // esi
  _DWORD *v172; // eax
  _DWORD *v173; // ebx
  int v174; // eax
  _DWORD *v175; // ecx
  btConvexHullInternal::Vertex **v176; // ecx
  int v177; // edi
  btConvexHullInternal::Vertex **v178; // eax
  btConvexHullInternal::Vertex **v179; // ebx
  int v180; // ecx
  btConvexHullInternal::Vertex **v181; // esi
  btConvexHullInternal::Vertex **v182; // ecx
  btConvexHullInternal::Face *v183; // eax
  btConvexHullInternal::Face *i; // eax
  int v185; // eax
  int m_capacity; // edx
  int v187; // esi
  btConvexHullInternal::Vertex **v188; // edi
  int v189; // ecx
  int v190; // edx
  btConvexHullInternal::Vertex **v191; // eax
  btConvexHullInternal::Vertex **v192; // ecx
  btConvexHullInternal::Vertex **v193; // ebx
  int v194; // esi
  btConvexHullInternal::Vertex **v195; // edi
  int v196; // ecx
  int v197; // edx
  btConvexHullInternal::Vertex **v198; // eax
  btConvexHullInternal::Vertex **v199; // ecx
  int v200; // edi
  int v201; // edi
  _DWORD *v202; // eax
  _DWORD *v203; // ebx
  int v204; // ecx
  int v205; // esi
  _DWORD *v206; // edx
  int v207; // esi
  int v208; // edx
  btConvexHullInternal::Point32 *v209; // eax
  btConvexHullInternal::PointR128 v210; // [esp+7C42h] [ebp-430h] BYREF
  const btConvexHullInternal::Int128 *v211; // [esp+7C82h] [ebp-3F0h]
  char *v212; // [esp+7C96h] [ebp-3DCh]
  char v213; // [esp+7C9Dh] [ebp-3D5h]
  btConvexHullInternal::Vertex *v214; // [esp+7C9Eh] [ebp-3D4h]
  btConvexHullInternal::Edge *v215; // [esp+7CA2h] [ebp-3D0h]
  btConvexHullInternal::Edge *v216; // [esp+7CA6h] [ebp-3CCh]
  btConvexHullInternal::Rational128 *v217[2]; // [esp+7CAAh] [ebp-3C8h]
  int v218; // [esp+7CB2h] [ebp-3C0h]
  float v219; // [esp+7CB6h] [ebp-3BCh]
  btConvexHullInternal::Vertex *target; // [esp+7CBAh] [ebp-3B8h]
  int v221; // [esp+7CBEh] [ebp-3B4h]
  __int64 v222; // [esp+7CC2h] [ebp-3B0h]
  btConvexHullInternal::Int128 *v223; // [esp+7CCAh] [ebp-3A8h]
  btConvexHullInternal::Vertex *v224; // [esp+7CCEh] [ebp-3A4h]
  __int64 v225; // [esp+7CD2h] [ebp-3A0h]
  btConvexHullInternal::Int128 *v226; // [esp+7CDEh] [ebp-394h]
  __int64 v227; // [esp+7CE2h] [ebp-390h]
  unsigned __int64 v228; // [esp+7CEAh] [ebp-388h]
  __int64 v229; // [esp+7CF2h] [ebp-380h]
  __int64 a; // [esp+7CFAh] [ebp-378h]
  __int64 v231; // [esp+7D02h] [ebp-370h]
  __int64 v232; // [esp+7D0Ah] [ebp-368h]
  btConvexHullInternal::Point32 *p_origin; // [esp+7D12h] [ebp-360h]
  btConvexHullInternal::Edge ***v234; // [esp+7D16h] [ebp-35Ch]
  btConvexHullInternal::Point32 *p_dir0; // [esp+7D1Ah] [ebp-358h]
  btConvexHullInternal::Point32 *p_dir1; // [esp+7D1Eh] [ebp-354h]
  btConvexHullInternal::Int128 *v237[2]; // [esp+7D22h] [ebp-350h]
  __int64 v238; // [esp+7D2Ah] [ebp-348h]
  btConvexHullInternal::Point64 b; // [esp+7D32h] [ebp-340h] BYREF
  btConvexHullInternal::Int128 *v240[2]; // [esp+7D4Ah] [ebp-328h]
  unsigned int v241; // [esp+7D56h] [ebp-31Ch]
  btConvexHullInternal::Vertex *v242; // [esp+7D5Ah] [ebp-318h]
  btConvexHullInternal::Vertex **v243; // [esp+7D5Eh] [ebp-314h]
  btConvexHullInternal::Edge *v244; // [esp+7D62h] [ebp-310h]
  btConvexHullInternal::Int128 *v245; // [esp+7D66h] [ebp-30Ch]
  __int64 v246; // [esp+7D6Ah] [ebp-308h]
  btConvexHullInternal::Point32 v247; // [esp+7D72h] [ebp-300h] BYREF
  btConvexHullInternal::Rational128 v248; // [esp+7D82h] [ebp-2F0h] BYREF
  btConvexHullInternal::Point32 v249; // [esp+7DB2h] [ebp-2C0h] BYREF
  int v250; // [esp+7DCEh] [ebp-2A4h]
  btConvexHullInternal::Int128 v251; // [esp+7DD2h] [ebp-2A0h] BYREF
  btConvexHullInternal::Rational128 result; // [esp+7DE2h] [ebp-290h] BYREF
  btConvexHullInternal::Int128 v253; // [esp+7E2Ah] [ebp-248h] BYREF
  btConvexHullInternal::Int128 v254; // [esp+7E3Ah] [ebp-238h] BYREF
  btConvexHullInternal::Int128 v255; // [esp+7E4Ah] [ebp-228h] BYREF
  btConvexHullInternal::Int128 v256; // [esp+7E5Ah] [ebp-218h] BYREF
  btConvexHullInternal::Int128 v257; // [esp+7E6Ah] [ebp-208h] BYREF
  btConvexHullInternal::Int128 v258; // [esp+7E7Ah] [ebp-1F8h] BYREF
  btConvexHullInternal::Int128 v259; // [esp+7E8Ah] [ebp-1E8h] BYREF
  btConvexHullInternal::Int128 v260; // [esp+7E9Ah] [ebp-1D8h] BYREF
  btConvexHullInternal::Int128 v261; // [esp+7EAAh] [ebp-1C8h] BYREF
  btConvexHullInternal::Int128 v262; // [esp+7EBAh] [ebp-1B8h] BYREF
  btConvexHullInternal::Int128 v263; // [esp+7ECAh] [ebp-1A8h] BYREF
  btConvexHullInternal::Int128 v264; // [esp+7EDAh] [ebp-198h] BYREF
  btConvexHullInternal::Int128 v265; // [esp+7EEAh] [ebp-188h] BYREF
  btConvexHullInternal::Int128 denominator; // [esp+7EFAh] [ebp-178h] BYREF
  btConvexHullInternal::Int128 v267; // [esp+7F0Ah] [ebp-168h] BYREF
  btConvexHullInternal::Int128 v268; // [esp+7F1Ah] [ebp-158h] BYREF
  btConvexHullInternal::Int128 v269; // [esp+7F2Ah] [ebp-148h] BYREF
  btConvexHullInternal::Int128 v270; // [esp+7F3Ah] [ebp-138h] BYREF
  btConvexHullInternal::Int128 v271; // [esp+7F4Ah] [ebp-128h] BYREF
  btConvexHullInternal::Int128 v272; // [esp+7F5Ah] [ebp-118h] BYREF
  btConvexHullInternal::Int128 v273; // [esp+7F6Ah] [ebp-108h] BYREF
  btConvexHullInternal::Int128 v274; // [esp+7F7Ah] [ebp-F8h] BYREF
  btConvexHullInternal::Int128 v275; // [esp+7F8Ah] [ebp-E8h] BYREF
  btConvexHullInternal::Int128 v276; // [esp+7F9Ah] [ebp-D8h] BYREF
  btConvexHullInternal::Int128 v277; // [esp+7FAAh] [ebp-C8h] BYREF
  btConvexHullInternal::Int128 v278; // [esp+7FBAh] [ebp-B8h] BYREF
  btConvexHullInternal::Int128 v279; // [esp+7FCAh] [ebp-A8h] BYREF
  btConvexHullInternal::Int128 v280; // [esp+7FDAh] [ebp-98h] BYREF
  btConvexHullInternal::Int128 v281; // [esp+7FEAh] [ebp-88h] BYREF
  btConvexHullInternal::Rational128 v282; // [esp+7FFAh] [ebp-78h] BYREF
  btConvexHullInternal::Rational128 v283; // [esp+8022h] [ebp-50h] BYREF
  btConvexHullInternal::Rational128 v284; // [esp+804Ah] [ebp-28h] BYREF

  *(float *)&p_origin = -a3;
  BtNormal = btConvexHullInternal::getBtNormal(a1, (int)this, (int)&v249, face, a2);
  v7 = this->scaling.mVec128.m128_f32[0];
  v8 = BtNormal->mVec128.m128_f32[0] * (float)-a3;
  v9 = BtNormal->mVec128.m128_f32[1] * *(float *)&p_origin;
  v10 = BtNormal->mVec128.m128_f32[2] * *(float *)&p_origin;
  v11 = this->scaling.mVec128.m128_f32[0] == 0.0;
  *(float *)&v227 = BtNormal->mVec128.m128_f32[0] * *(float *)&p_origin;
  *((float *)&v227 + 1) = v9;
  v228 = LODWORD(v10);
  if ( !v11 )
    *(float *)&v227 = v8 / v7;
  v12 = this->scaling.mVec128.m128_f32[1];
  if ( v12 != 0.0 )
    *((float *)&v227 + 1) = v9 / v12;
  v13 = this->scaling.mVec128.m128_f32[2];
  if ( v13 != 0.0 )
    *(float *)&v228 = v10 / v13;
  v14 = (int)*((float *)&v227 + this->medAxis);
  v15 = (int)*((float *)&v227 + this->minAxis);
  v16 = (int)*((float *)&v227 + this->maxAxis);
  v247.z = v15;
  if ( !v14 && !v16 && !v15 )
  {
    if ( !stack.m_data || !stack.m_ownsMemory )
      return 1;
    ++gNumAlignedFree;
    sAlignedFreeFunc(stack.m_data);
    return 1;
  }
  p_dir0 = &face->dir0;
  p_dir1 = &face->dir1;
  btConvexHullInternal::Point32::cross(&face->dir1, &b, &face->dir0);
  x = face->origin.x;
  v19 = v247.z + face->origin.z;
  HIDWORD(v227) = v16 + face->origin.y;
  p_origin = &face->origin;
  v20 = v14 + x;
  v228 = (unsigned int)v19 | 0xFFFFFFFF00000000uLL;
  *(_QWORD *)v237 = v20;
  LODWORD(v227) = v20;
  v246 = SHIDWORD(v227);
  *(_QWORD *)v240 = v19;
  v241 = (unsigned __int64)(v19 * b.z) >> 32;
  v210.denominator.high = b.x;
  v210.denominator.low = v20;
  *(_QWORD *)v217 = v20 * b.x + SHIDWORD(v227) * b.y + v19 * b.z;
  if ( *(__int64 *)v217 >= btConvexHullInternal::Point32::dot(&face->origin, &b) )
  {
    if ( stack.m_data && stack.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(stack.m_data);
    }
    return 0;
  }
  nearbyVertex = (int)face->nearbyVertex;
  v22 = *(btConvexHullInternal::Edge **)(nearbyVertex + 8);
  v215 = v22;
  btConvexHullInternal::Vertex::dot((btConvexHullInternal::Vertex *)&b, nearbyVertex, &result, &b);
  v218 = btConvexHullInternal::Rational128::compare(v217[0], (int)&result, *(__int64 *)v217);
  if ( v218 < 0 )
  {
    while ( 1 )
    {
      btConvexHullInternal::Vertex::dot((btConvexHullInternal::Vertex *)&v248, (int)v22->target, &v248, &b);
      if ( btConvexHullInternal::Rational128::compare(&v248, &result) > 0 )
      {
        v218 = btConvexHullInternal::Rational128::compare(v25, (int)&v248, *(__int64 *)v217);
        if ( v218 >= 0 )
        {
          v214 = (btConvexHullInternal::Vertex *)v22;
          goto LABEL_32;
        }
        v22 = v22->reverse;
        result.numerator = (btConvexHullInternal::Int128)_mm_load_si128((const __m128i *)&v248);
        result.denominator = (btConvexHullInternal::Int128)_mm_load_si128((const __m128i *)&v248.denominator);
        *(_QWORD *)&result.sign = *(_QWORD *)&v248.sign;
        v215 = v22;
      }
      v22 = v22->prev;
      if ( v22 == v215 )
      {
        btPairSet::~btPairSet((btPairSet *)v25, (int)&stack);
        return 1;
      }
    }
  }
  while ( 1 )
  {
    btConvexHullInternal::Vertex::dot(v23, (int)v22->target, &v248, &b);
    if ( btConvexHullInternal::Rational128::compare(&v248, &result) < 0 )
      break;
LABEL_22:
    v22 = v22->prev;
    if ( v22 == v215 )
      goto LABEL_23;
  }
  v24 = btConvexHullInternal::Rational128::compare(v217[1], (int)&v248, *(__int64 *)v217);
  v22 = v22->reverse;
  result.numerator = (btConvexHullInternal::Int128)_mm_load_si128((const __m128i *)&v248);
  result.denominator = (btConvexHullInternal::Int128)_mm_load_si128((const __m128i *)&v248.denominator);
  *(_QWORD *)&result.sign = *(_QWORD *)&v248.sign;
  v215 = v22;
  if ( v24 >= 0 )
  {
    v218 = v24;
    goto LABEL_22;
  }
  v214 = (btConvexHullInternal::Vertex *)v22;
  if ( !v22 )
  {
LABEL_23:
    btPairSet::~btPairSet((btPairSet *)v23, (int)&stack);
    return 0;
  }
LABEL_32:
  if ( !v218 )
  {
    next = v214->edges->next;
    v210.denominator.high = *(_QWORD *)v217;
    v27 = btConvexHullInternal::Vertex::dot((btConvexHullInternal::Vertex *)&v282, (int)next->target, &v282, &b);
    if ( btConvexHullInternal::Rational128::compare(v28, (int)v27, *(__int64 *)v217) <= 0 )
    {
      do
      {
        next = next->next;
        if ( next == v214->edges )
          goto LABEL_347;
        v210.denominator.high = *(_QWORD *)v217;
        v30 = btConvexHullInternal::Vertex::dot((btConvexHullInternal::Vertex *)&v282, (int)next->target, &v282, &b);
      }
      while ( btConvexHullInternal::Rational128::compare(v31, (int)v30, *(__int64 *)v217) <= 0 );
    }
  }
  v32 = 0;
  v224 = 0;
  v212 = 0;
  while ( 2 )
  {
    v215 = v32;
LABEL_38:
    v33 = v218;
    if ( v218 )
    {
LABEL_43:
      v41 = v224;
      if ( v224 )
      {
        if ( v214 == v224 )
        {
          if ( v33 > 0 )
          {
            v150 = v215;
            v215->reverse->target = v32->target;
            edges = v41->edges;
            edges->next = v150;
            v150->prev = edges;
            reverse = v32->reverse;
            v150->next = reverse;
            reverse->prev = v150;
            goto LABEL_191;
          }
          if ( v215 == v32->reverse )
          {
LABEL_191:
            m_size = stack.m_size;
            m_data = stack.m_data;
          }
          else
          {
            v160 = stack.m_size;
            if ( stack.m_size != stack.m_capacity )
              goto LABEL_216;
            v161 = 2 * stack.m_size;
            if ( !stack.m_size )
              v161 = 1;
            if ( stack.m_capacity < v161 )
            {
              if ( v161 )
              {
                ++gNumAlignedAllocs;
                v162 = (btConvexHullInternal::Vertex **)sAlignedAllocFunc(4 * v161, 16);
                v160 = stack.m_size;
                v163 = v162;
              }
              else
              {
                v163 = 0;
              }
              v164 = 0;
              if ( v160 > 0 )
              {
                v165 = v163;
                do
                {
                  if ( v165 )
                  {
                    *v165 = stack.m_data[v164];
                    v32 = (btConvexHullInternal::Edge *)v212;
                  }
                  ++v164;
                  ++v165;
                }
                while ( v164 < v160 );
                v160 = stack.m_size;
              }
              if ( stack.m_data && stack.m_ownsMemory )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(stack.m_data);
                v160 = stack.m_size;
              }
              m_data = v163;
              stack.m_ownsMemory = 1;
              stack.m_data = v163;
              stack.m_capacity = v161;
            }
            else
            {
LABEL_216:
              m_data = stack.m_data;
            }
            v166 = &m_data[v160];
            if ( v166 )
            {
              *v166 = v32->target;
              m_data = stack.m_data;
              v160 = stack.m_size;
            }
            p_next = &v215->next;
            v168 = v160 + 1;
            for ( stack.m_size = v168; *p_next != v32->reverse; stack.m_size = v168 )
            {
              v169 = *p_next;
              target = (*p_next)->target;
              btConvexHullInternal::removeEdgePair(this, v169);
              v170 = stack.m_size;
              if ( stack.m_size != stack.m_capacity )
                goto LABEL_237;
              v171 = 2 * stack.m_size;
              if ( !stack.m_size )
                v171 = 1;
              if ( stack.m_capacity < v171 )
              {
                if ( v171 )
                {
                  ++gNumAlignedAllocs;
                  v172 = sAlignedAllocFunc(4 * v171, 16);
                  v170 = stack.m_size;
                  v173 = v172;
                }
                else
                {
                  v173 = 0;
                }
                v174 = 0;
                if ( v170 > 0 )
                {
                  v175 = v173;
                  do
                  {
                    if ( v175 )
                    {
                      *v175 = stack.m_data[v174];
                      v32 = (btConvexHullInternal::Edge *)v212;
                    }
                    ++v174;
                    ++v175;
                  }
                  while ( v174 < v170 );
                  v170 = stack.m_size;
                }
                if ( stack.m_data && stack.m_ownsMemory )
                {
                  ++gNumAlignedFree;
                  sAlignedFreeFunc(stack.m_data);
                  v170 = stack.m_size;
                }
                m_data = (btConvexHullInternal::Vertex **)v173;
                p_next = &v215->next;
                stack.m_ownsMemory = 1;
                stack.m_data = m_data;
                stack.m_capacity = v171;
              }
              else
              {
LABEL_237:
                m_data = stack.m_data;
              }
              v176 = &m_data[v170];
              if ( v176 )
              {
                *v176 = target;
                m_data = stack.m_data;
                v170 = stack.m_size;
              }
              v168 = v170 + 1;
            }
            if ( v168 == stack.m_capacity )
            {
              v177 = 2 * v168;
              if ( !v168 )
                v177 = 1;
              if ( stack.m_capacity < v177 )
              {
                if ( v177 )
                {
                  ++gNumAlignedAllocs;
                  v178 = (btConvexHullInternal::Vertex **)sAlignedAllocFunc(4 * v177, 16);
                  v168 = stack.m_size;
                  v179 = v178;
                  m_data = stack.m_data;
                }
                else
                {
                  v179 = 0;
                }
                v180 = 0;
                if ( v168 > 0 )
                {
                  v181 = v179;
                  do
                  {
                    if ( v181 )
                    {
                      *v181 = m_data[v180];
                      m_data = stack.m_data;
                    }
                    ++v180;
                    ++v181;
                  }
                  while ( v180 < v168 );
                  v168 = stack.m_size;
                }
                if ( m_data && stack.m_ownsMemory )
                {
                  ++gNumAlignedFree;
                  sAlignedFreeFunc(m_data);
                  v168 = stack.m_size;
                }
                m_data = v179;
                stack.m_ownsMemory = 1;
                stack.m_data = v179;
                stack.m_capacity = v177;
              }
            }
            v182 = &m_data[v168];
            if ( v182 )
            {
              *v182 = 0;
              m_data = stack.m_data;
              v168 = stack.m_size;
            }
            m_size = v168 + 1;
            stack.m_size = m_size;
          }
          v29 = (btPairSet *)*m_data;
          this->vertexList = *m_data;
          v216 = 0;
          if ( m_size > 0 )
          {
            v155 = (int)v216;
            do
            {
              v234 = (btConvexHullInternal::Edge ***)m_size;
              if ( v155 >= m_size )
                break;
              do
              {
                v29 = (btPairSet *)m_data[v155];
                v156 = m_data[v155 + 1];
                v157 = (btConvexHullInternal::Edge *)(v155 + 1);
                v224 = (btConvexHullInternal::Vertex *)v29;
                v213 = 0;
                v221 = (int)v156;
                if ( v156 )
                {
                  do
                  {
                    v158 = v224;
                    lastNearbyFace = v224->lastNearbyFace;
                    v157 = (btConvexHullInternal::Edge *)((char *)v157 + 1);
                    v29 = 0;
                    v216 = v157;
                    if ( lastNearbyFace )
                      lastNearbyFace->nextWithSameNearbyVertex = v156->firstNearbyFace;
                    else
                      v224->firstNearbyFace = v156->firstNearbyFace;
                    v183 = v156->lastNearbyFace;
                    if ( v183 )
                      v158->lastNearbyFace = v183;
                    for ( i = v156->firstNearbyFace; i; i = i->nextWithSameNearbyVertex )
                      i->nearbyVertex = v158;
                    v156->firstNearbyFace = 0;
                    v156->lastNearbyFace = 0;
                    if ( v156->edges )
                    {
                      do
                      {
                        v185 = stack.m_size;
                        m_capacity = stack.m_capacity;
                        if ( !v213 )
                        {
                          v213 = 1;
                          if ( stack.m_size == stack.m_capacity )
                          {
                            v187 = 2 * stack.m_size;
                            if ( !stack.m_size )
                              v187 = 1;
                            if ( stack.m_capacity < v187 )
                            {
                              if ( v187 )
                              {
                                ++gNumAlignedAllocs;
                                v188 = (btConvexHullInternal::Vertex **)sAlignedAllocFunc(4 * v187, 16);
                                v185 = stack.m_size;
                              }
                              else
                              {
                                v188 = 0;
                              }
                              v189 = 0;
                              v190 = v185;
                              if ( v185 > 0 )
                              {
                                v191 = v188;
                                do
                                {
                                  if ( v191 )
                                    *v191 = stack.m_data[v189];
                                  ++v189;
                                  ++v191;
                                }
                                while ( v189 < v190 );
                                v185 = stack.m_size;
                              }
                              if ( stack.m_data && stack.m_ownsMemory )
                              {
                                ++gNumAlignedFree;
                                sAlignedFreeFunc(stack.m_data);
                                v185 = stack.m_size;
                              }
                              m_capacity = v187;
                              stack.m_ownsMemory = 1;
                              stack.m_data = v188;
                              stack.m_capacity = v187;
                            }
                          }
                          v192 = &stack.m_data[v185];
                          if ( v192 )
                          {
                            *v192 = v224;
                            m_capacity = stack.m_capacity;
                            v185 = stack.m_size;
                          }
                          stack.m_size = ++v185;
                        }
                        v193 = (btConvexHullInternal::Vertex **)(*(_DWORD *)(v221 + 8) + 12);
                        target = (btConvexHullInternal::Vertex *)v193;
                        if ( v185 == m_capacity )
                        {
                          v194 = 2 * v185;
                          if ( !v185 )
                            v194 = 1;
                          if ( m_capacity < v194 )
                          {
                            if ( v194 )
                            {
                              ++gNumAlignedAllocs;
                              v195 = (btConvexHullInternal::Vertex **)sAlignedAllocFunc(4 * v194, 16);
                              v185 = stack.m_size;
                            }
                            else
                            {
                              v195 = 0;
                            }
                            v196 = 0;
                            v197 = v185;
                            if ( v185 > 0 )
                            {
                              v198 = v195;
                              do
                              {
                                if ( v198 )
                                {
                                  *v198 = stack.m_data[v196];
                                  v193 = &target->next;
                                }
                                ++v196;
                                ++v198;
                              }
                              while ( v196 < v197 );
                              v185 = stack.m_size;
                            }
                            if ( stack.m_data && stack.m_ownsMemory )
                            {
                              ++gNumAlignedFree;
                              sAlignedFreeFunc(stack.m_data);
                              v185 = stack.m_size;
                            }
                            stack.m_ownsMemory = 1;
                            stack.m_data = v195;
                            stack.m_capacity = v194;
                          }
                        }
                        v199 = &stack.m_data[v185];
                        if ( v199 )
                        {
                          *v199 = *v193;
                          v185 = stack.m_size;
                        }
                        v200 = v221;
                        stack.m_size = v185 + 1;
                        btConvexHullInternal::removeEdgePair(this, *(btConvexHullInternal::Edge **)(v221 + 8));
                      }
                      while ( *(_DWORD *)(v200 + 8) );
                      v157 = v216;
                    }
                    m_data = stack.m_data;
                    v156 = stack.m_data[(_DWORD)v157];
                    v221 = (int)v156;
                  }
                  while ( v156 );
                  m_size = stack.m_size;
                }
                v155 = (int)&v157->next + 1;
                v216 = (btConvexHullInternal::Edge *)v155;
                if ( v213 )
                {
                  if ( m_size == stack.m_capacity )
                  {
                    v201 = 2 * m_size;
                    if ( !m_size )
                      v201 = 1;
                    if ( stack.m_capacity < v201 )
                    {
                      if ( v201 )
                      {
                        ++gNumAlignedAllocs;
                        v202 = sAlignedAllocFunc(4 * v201, 16);
                        m_size = stack.m_size;
                        v203 = v202;
                        m_data = stack.m_data;
                      }
                      else
                      {
                        v203 = 0;
                      }
                      v204 = 0;
                      v205 = m_size;
                      if ( m_size > 0 )
                      {
                        v206 = v203;
                        do
                        {
                          if ( v206 )
                          {
                            *v206 = m_data[v204];
                            m_data = stack.m_data;
                          }
                          ++v204;
                          ++v206;
                        }
                        while ( v204 < v205 );
                        m_size = stack.m_size;
                      }
                      if ( m_data && stack.m_ownsMemory )
                      {
                        ++gNumAlignedFree;
                        sAlignedFreeFunc(m_data);
                        m_size = stack.m_size;
                      }
                      m_data = (btConvexHullInternal::Vertex **)v203;
                      v155 = (int)v216;
                      stack.m_ownsMemory = 1;
                      stack.m_data = m_data;
                      stack.m_capacity = v201;
                    }
                  }
                  v29 = (btPairSet *)&m_data[m_size];
                  if ( v29 )
                  {
                    *(_DWORD *)&v29->m_allocator = 0;
                    m_data = stack.m_data;
                    m_size = stack.m_size;
                  }
                  stack.m_size = ++m_size;
                }
              }
              while ( v155 < (int)v234 );
            }
            while ( v155 < m_size );
          }
          v207 = m_size;
          if ( m_size <= 0 )
          {
            if ( m_size < 0 && stack.m_capacity < 0 )
            {
              if ( m_data && stack.m_ownsMemory )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(m_data);
              }
              m_data = 0;
              stack.m_ownsMemory = 1;
              stack.m_data = 0;
              stack.m_capacity = 0;
            }
            if ( v207 < 0 )
            {
              v208 = v207;
              do
              {
                v29 = (btPairSet *)&m_data[v208];
                if ( &m_data[v208] )
                {
                  *(_DWORD *)&v29->m_allocator = 0;
                  m_data = stack.m_data;
                }
                ++v208;
              }
              while ( v208 < 0 );
            }
          }
          v209 = p_origin;
          *(_QWORD *)&p_origin->x = v227;
          stack.m_size = 0;
          *(_QWORD *)&v209->z = v228;
          goto LABEL_347;
        }
      }
      else
      {
        v224 = v214;
      }
      prev = v214->edges;
      target = v214;
      p_edges = (btConvexHullInternal::Edge ***)&v214->edges;
      v216 = v32;
      v44 = v217[0];
      v221 = v33;
      v234 = (btConvexHullInternal::Edge ***)&v214->edges;
      do
      {
        prev = prev->reverse->prev;
        v210.denominator.high = __PAIR64__((unsigned int)v217[1], (unsigned int)v44);
        v45 = btConvexHullInternal::Vertex::dot((btConvexHullInternal::Vertex *)&v284, (int)prev->target, &v284, &b);
        v47 = btConvexHullInternal::Rational128::compare(v46, (int)v45, v210.denominator.high);
        v48 = v47;
        v218 = v47;
      }
      while ( v47 < 0 );
      v214 = (btConvexHullInternal::Vertex *)prev;
      if ( v47 <= 0 )
      {
        v100 = stack.m_capacity;
        v120 = stack.m_size;
      }
      else
      {
        v49 = prev->target;
        p_target = &prev->target;
        p_reverse = &prev->reverse;
        v243 = p_target;
        v52 = *p_reverse;
        v53 = (*p_reverse)->prev;
        v242 = v49;
        v244 = v52;
        if ( v53 == v52 )
        {
          v49->edges = 0;
        }
        else
        {
          v49->edges = v53;
          v54 = v52->next;
          v55 = v52->prev;
          v55->next = v52->next;
          v54->prev = v55;
          v52->next = v52;
          v52->prev = v52;
        }
        v56 = v214->lastNearbyFace;
        btConvexHullInternal::Point32::cross(&v56->dir1, &v248, &v56->dir0);
        v212 = (char *)(*p_reverse)->face;
        btConvexHullInternal::Point32::cross(
          (const btConvexHullInternal::Point32 *)(v212 + 44),
          &result,
          (btConvexHullInternal::Point32 *)(v212 + 28));
        v232 = btConvexHullInternal::Point32::dot(p_dir0, (const btConvexHullInternal::Point64 *)&v248);
        a = btConvexHullInternal::Point32::dot(p_dir1, (const btConvexHullInternal::Point64 *)&v248);
        v229 = btConvexHullInternal::Point32::dot(p_dir0, (const btConvexHullInternal::Point64 *)&result);
        v57 = btConvexHullInternal::Point32::dot(p_dir1, (const btConvexHullInternal::Point64 *)&result);
        v58 = v56->origin.y - HIDWORD(v227);
        v231 = v57;
        HIDWORD(v57) = v56->origin.z - v228;
        v249.x = v56->origin.x - v227;
        v249.y = v58;
        v249.z = HIDWORD(v57);
        v249.index = -1;
        v59 = btConvexHullInternal::Point32::dot(&v249, (const btConvexHullInternal::Point64 *)&v248);
        v60 = v59;
        v61 = *((_DWORD *)v212 + 3) - v227;
        HIDWORD(v225) = HIDWORD(v59);
        HIDWORD(v59) = *((_DWORD *)v212 + 4) - HIDWORD(v227);
        LODWORD(v59) = *((_DWORD *)v212 + 5) - v228;
        LODWORD(v225) = v60;
        v247.x = v61;
        v247.y = HIDWORD(v59);
        v247.z = v59;
        v247.index = -1;
        v222 = btConvexHullInternal::Point32::dot(&v247, (const btConvexHullInternal::Point64 *)&result);
        v62 = btConvexHullInternal::Int128::mul(&v281, a, v229);
        v210.denominator.high = __PAIR64__(&v251, v63);
        v64 = btConvexHullInternal::Int128::mul(&v274, v232, v231);
        btConvexHullInternal::Int128::operator-(
          v62,
          (int)v64,
          (btConvexHullInternal::Int128 *)HIDWORD(v210.denominator.high),
          v211);
        v66 = btConvexHullInternal::Pool<btConvexHullInternal::Vertex>::newObject(v65, (int)&this->vertexPool);
        v66->point.index = -1;
        v66->copy = -1;
        v212 = (char *)v66;
        z = face->dir1.z;
        v238 = face->dir0.z;
        v223 = btConvexHullInternal::Int128::operator*(v240[0], &v251, &v276, *(__int64 *)v240);
        v68 = btConvexHullInternal::Int128::mul(&v278, z * __PAIR64__(HIDWORD(v225), v60), v229);
        HIDWORD(v210.denominator.high) = &v255;
        LODWORD(v210.denominator.high) = &v255;
        v226 = v68;
        HIDWORD(z) = btConvexHullInternal::Int128::mul(&v277, z * v222, v232);
        v69 = btConvexHullInternal::Int128::mul(&v257, v238 * v222, a);
        HIDWORD(v210.denominator.low) = &v271;
        LODWORD(v210.denominator.low) = &v271;
        LODWORD(z) = v69;
        LODWORD(v210.y.high) = v238;
        v70 = btConvexHullInternal::Int128::mul(&v259, v238 * __PAIR64__(HIDWORD(v225), v60), v231);
        v71 = btConvexHullInternal::Int128::operator-(
                (btConvexHullInternal::Int128 *)z,
                (int)v70,
                (btConvexHullInternal::Int128 *)HIDWORD(v210.denominator.low),
                (const btConvexHullInternal::Int128 *)v210.denominator.high);
        v72 = btConvexHullInternal::Int128::operator+(v71, (const btConvexHullInternal::Int128 *)HIDWORD(z), &v280);
        v73 = btConvexHullInternal::Int128::operator-(
                v226,
                (int)v72,
                (btConvexHullInternal::Int128 *)HIDWORD(v210.denominator.high),
                v211);
        v245 = btConvexHullInternal::Int128::operator+(v73, v223, &v261);
        HIDWORD(z) = face->dir1.y;
        y = face->dir0.y;
        v250 = y >> 31;
        v75 = y;
        v226 = btConvexHullInternal::Int128::operator*(&v273, &v251, &v273, v246);
        v76 = btConvexHullInternal::Int128::mul(&v263, SHIDWORD(z) * v225, v229);
        HIDWORD(v210.denominator.high) = &v279;
        LODWORD(v210.denominator.high) = &v279;
        v223 = v76;
        HIDWORD(z) = btConvexHullInternal::Int128::mul(&v265, SHIDWORD(z) * v222, v232);
        LODWORD(z) = btConvexHullInternal::Int128::mul(&v275, __PAIR64__(v250, v75) * v222, a);
        v210.denominator.low = __PAIR64__(&v267, v77);
        LODWORD(v210.y.high) = v75;
        v78 = btConvexHullInternal::Int128::mul(&v253, __PAIR64__(v250, v75) * v225, v231);
        v79 = btConvexHullInternal::Int128::operator-(
                (btConvexHullInternal::Int128 *)z,
                (int)v78,
                (btConvexHullInternal::Int128 *)HIDWORD(v210.denominator.low),
                (const btConvexHullInternal::Int128 *)v210.denominator.high);
        v80 = btConvexHullInternal::Int128::operator+(v79, (const btConvexHullInternal::Int128 *)HIDWORD(z), &v269);
        v81 = btConvexHullInternal::Int128::operator-(
                v223,
                (int)v80,
                (btConvexHullInternal::Int128 *)HIDWORD(v210.denominator.high),
                v211);
        v219 = COERCE_FLOAT(btConvexHullInternal::Int128::operator+(v81, v226, &v254));
        LODWORD(z) = p_dir1->x >> 31;
        HIDWORD(z) = p_dir1->x;
        v82 = p_dir0->x;
        v241 = p_dir0->x >> 31;
        v226 = btConvexHullInternal::Int128::operator*(v237[0], &v251, &v256, *(__int64 *)v237);
        v83 = btConvexHullInternal::Int128::mul(&v258, __PAIR64__(z, HIDWORD(z)) * v225, v229);
        v210.denominator.high = __PAIR64__(&v260, v84);
        v223 = v83;
        HIDWORD(z) = btConvexHullInternal::Int128::mul(&v262, __PAIR64__(z, HIDWORD(z)) * v222, v232);
        v85 = btConvexHullInternal::Int128::mul(&v264, __PAIR64__(v241, v82) * v222, a);
        HIDWORD(v210.denominator.low) = &denominator;
        LODWORD(v210.denominator.low) = &denominator;
        LODWORD(z) = v85;
        LODWORD(v210.y.high) = v82;
        v86 = btConvexHullInternal::Int128::mul(&v268, __PAIR64__(v241, v82) * v225, v231);
        v87 = btConvexHullInternal::Int128::operator-(
                (btConvexHullInternal::Int128 *)z,
                (int)v86,
                (btConvexHullInternal::Int128 *)HIDWORD(v210.denominator.low),
                (const btConvexHullInternal::Int128 *)v210.denominator.high);
        v88 = btConvexHullInternal::Int128::operator+(v87, (const btConvexHullInternal::Int128 *)HIDWORD(z), &v270);
        v89 = btConvexHullInternal::Int128::operator-(
                v223,
                (int)v88,
                (btConvexHullInternal::Int128 *)HIDWORD(v210.denominator.high),
                v211);
        v90 = btConvexHullInternal::Int128::operator+(v89, v226, &v272);
        btConvexHullInternal::PointR128::PointR128(
          &v210,
          &result.numerator,
          *v90,
          *(btConvexHullInternal::Int128 *)LODWORD(v219),
          *v245,
          v251);
        v91 = (btConvexHullInternal::Int128 *)(v212 + 24);
        qmemcpy(v212 + 24, v92, 0x40u);
        v219 = btConvexHullInternal::Int128::toScalar(v91);
        v93 = btConvexHullInternal::Int128::toScalar(v91 + 3);
        v94 = (btConvexHullInternal::Vertex *)v212;
        *((_DWORD *)v212 + 22) = (int)(v219 / v93);
        v219 = btConvexHullInternal::Int128::toScalar(v91 + 1);
        v95 = btConvexHullInternal::Int128::toScalar(v91 + 3);
        v94->point.y = (int)(v219 / v95);
        v219 = btConvexHullInternal::Int128::toScalar(v91 + 2);
        v96 = btConvexHullInternal::Int128::toScalar(v91 + 3);
        v97 = v243;
        v94->point.z = (int)(v219 / v96);
        v98 = v244;
        *v97 = v94;
        v94->edges = v98;
        v99 = stack.m_size;
        v100 = stack.m_capacity;
        if ( stack.m_size != stack.m_capacity )
          goto LABEL_69;
        v101 = 2 * stack.m_size;
        if ( !stack.m_size )
          v101 = 1;
        if ( stack.m_capacity < v101 )
        {
          if ( v101 )
          {
            ++gNumAlignedAllocs;
            v102 = (btConvexHullInternal::Vertex **)sAlignedAllocFunc(4 * v101, 16);
            v212 = (char *)v102;
            v99 = stack.m_size;
          }
          else
          {
            v102 = 0;
            v212 = 0;
          }
          v103 = 0;
          if ( v99 > 0 )
          {
            v104 = v102;
            do
            {
              if ( v104 )
                *v104 = stack.m_data[v103];
              ++v103;
              ++v104;
            }
            while ( v103 < v99 );
            v99 = stack.m_size;
            v102 = (btConvexHullInternal::Vertex **)v212;
          }
          if ( stack.m_data && stack.m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(stack.m_data);
            v99 = stack.m_size;
          }
          v100 = v101;
          stack.m_ownsMemory = 1;
          stack.m_data = v102;
          stack.m_capacity = v101;
        }
        else
        {
LABEL_69:
          v102 = stack.m_data;
        }
        v105 = &v102[v99];
        if ( v105 )
        {
          *v105 = v94;
          v102 = stack.m_data;
          v100 = stack.m_capacity;
          v99 = stack.m_size;
        }
        v106 = v99 + 1;
        stack.m_size = v106;
        if ( v106 == v100 )
        {
          v107 = 2 * v106;
          if ( !v106 )
            v107 = 1;
          if ( v100 < v107 )
          {
            if ( v107 )
            {
              ++gNumAlignedAllocs;
              v108 = (btConvexHullInternal::Vertex **)sAlignedAllocFunc(4 * v107, 16);
              v102 = stack.m_data;
              v109 = v108;
              v106 = stack.m_size;
            }
            else
            {
              v109 = 0;
            }
            v110 = 0;
            if ( v106 > 0 )
            {
              v111 = v109;
              do
              {
                if ( v111 )
                {
                  *v111 = v102[v110];
                  v102 = stack.m_data;
                }
                ++v110;
                ++v111;
              }
              while ( v110 < v106 );
              v106 = stack.m_size;
            }
            if ( v102 && stack.m_ownsMemory )
            {
              ++gNumAlignedFree;
              sAlignedFreeFunc(v102);
              v106 = stack.m_size;
            }
            v102 = v109;
            v100 = v107;
            stack.m_ownsMemory = 1;
            stack.m_data = v109;
            stack.m_capacity = v107;
          }
        }
        v112 = &v102[v106];
        if ( v112 )
        {
          *v112 = v242;
          v102 = stack.m_data;
          v100 = stack.m_capacity;
          v106 = stack.m_size;
        }
        v113 = v106 + 1;
        stack.m_size = v113;
        if ( v113 == v100 )
        {
          v114 = 2 * v113;
          if ( !v113 )
            v114 = 1;
          if ( v100 < v114 )
          {
            if ( v114 )
            {
              ++gNumAlignedAllocs;
              v115 = (btConvexHullInternal::Vertex **)sAlignedAllocFunc(4 * v114, 16);
              v102 = stack.m_data;
              v116 = v115;
              v113 = stack.m_size;
            }
            else
            {
              v116 = 0;
            }
            v117 = 0;
            if ( v113 > 0 )
            {
              v118 = v116;
              do
              {
                if ( v118 )
                {
                  *v118 = v102[v117];
                  v102 = stack.m_data;
                }
                ++v117;
                ++v118;
              }
              while ( v117 < v113 );
              v113 = stack.m_size;
            }
            if ( v102 && stack.m_ownsMemory )
            {
              ++gNumAlignedFree;
              sAlignedFreeFunc(v102);
              v113 = stack.m_size;
            }
            v102 = v116;
            v100 = v114;
            stack.m_ownsMemory = 1;
            stack.m_data = v116;
            stack.m_capacity = v114;
          }
        }
        v119 = &v102[v113];
        if ( v119 )
        {
          *v119 = 0;
          v100 = stack.m_capacity;
          v113 = stack.m_size;
        }
        p_edges = v234;
        v48 = v218;
        v120 = v113 + 1;
        stack.m_size = v120;
      }
      if ( !v48 && !v221 && (**p_edges)->target == (btConvexHullInternal::Vertex *)v214->firstNearbyFace )
      {
        v32 = **p_edges;
        v212 = (char *)v32;
        goto LABEL_123;
      }
      v32 = btConvexHullInternal::newEdgePair(
              (btConvexHullInternal *)v214->firstNearbyFace,
              this,
              (btConvexHullInternal::Vertex *)target->firstNearbyFace,
              (btConvexHullInternal::Vertex *)v214->firstNearbyFace);
      v212 = (char *)v32;
      if ( v221 )
      {
        if ( !v216 )
        {
LABEL_120:
          if ( !v218 )
          {
            v123 = v32->reverse;
            v124 = v214->edges->prev;
            v124->next = v123;
            v123->prev = v124;
          }
          v125 = v214->edges;
          v126 = v32->reverse;
          v126->next = v125;
          v125->prev = v126;
          v100 = stack.m_capacity;
          v120 = stack.m_size;
LABEL_123:
          v127 = v216;
          if ( v216 )
          {
            if ( v221 <= 0 )
            {
              if ( v32 != v216->reverse )
              {
                if ( v120 == v100 )
                {
                  v129 = 2 * v120;
                  if ( !v120 )
                    v129 = 1;
                  if ( v100 < v129 )
                  {
                    if ( v129 )
                    {
                      ++gNumAlignedAllocs;
                      v130 = (btConvexHullInternal::Vertex **)sAlignedAllocFunc(4 * v129, 16);
                      v120 = stack.m_size;
                    }
                    else
                    {
                      v130 = 0;
                    }
                    v131 = 0;
                    if ( v120 > 0 )
                    {
                      v132 = v130;
                      do
                      {
                        if ( v132 )
                        {
                          *v132 = stack.m_data[v131];
                          v32 = (btConvexHullInternal::Edge *)v212;
                        }
                        ++v131;
                        ++v132;
                      }
                      while ( v131 < v120 );
                      v120 = stack.m_size;
                    }
                    if ( stack.m_data && stack.m_ownsMemory )
                    {
                      ++gNumAlignedFree;
                      sAlignedFreeFunc(stack.m_data);
                      v120 = stack.m_size;
                    }
                    v100 = v129;
                    stack.m_data = v130;
                    v127 = v216;
                    stack.m_ownsMemory = 1;
                    stack.m_capacity = v129;
                  }
                }
                v133 = &stack.m_data[v120];
                if ( v133 )
                {
                  *v133 = v127->target;
                  v100 = stack.m_capacity;
                  v120 = stack.m_size;
                }
                v134 = v120 + 1;
                for ( stack.m_size = v134; v32->next != v127->reverse; stack.m_size = v134 )
                {
                  v135 = v32->next;
                  target = v32->next->target;
                  btConvexHullInternal::removeEdgePair(this, v135);
                  v136 = stack.m_size;
                  v100 = stack.m_capacity;
                  if ( stack.m_size == stack.m_capacity )
                  {
                    v137 = 2 * stack.m_size;
                    if ( !stack.m_size )
                      v137 = 1;
                    if ( stack.m_capacity < v137 )
                    {
                      if ( v137 )
                      {
                        ++gNumAlignedAllocs;
                        v138 = (btConvexHullInternal::Vertex **)sAlignedAllocFunc(4 * v137, 16);
                        v136 = stack.m_size;
                      }
                      else
                      {
                        v138 = 0;
                      }
                      v139 = 0;
                      v140 = v136;
                      if ( v136 > 0 )
                      {
                        v141 = v138;
                        do
                        {
                          if ( v141 )
                          {
                            *v141 = stack.m_data[v139];
                            v32 = (btConvexHullInternal::Edge *)v212;
                          }
                          ++v139;
                          ++v141;
                        }
                        while ( v139 < v140 );
                        v136 = stack.m_size;
                      }
                      if ( stack.m_data && stack.m_ownsMemory )
                      {
                        ++gNumAlignedFree;
                        sAlignedFreeFunc(stack.m_data);
                        v136 = stack.m_size;
                      }
                      v100 = v137;
                      stack.m_data = v138;
                      v127 = v216;
                      stack.m_ownsMemory = 1;
                      stack.m_capacity = v137;
                    }
                  }
                  v142 = &stack.m_data[v136];
                  if ( v142 )
                  {
                    *v142 = target;
                    v100 = stack.m_capacity;
                    v136 = stack.m_size;
                  }
                  v134 = v136 + 1;
                }
                if ( v134 == v100 )
                {
                  v143 = 2 * v134;
                  if ( !v134 )
                    v143 = 1;
                  if ( v100 < v143 )
                  {
                    if ( v143 )
                    {
                      ++gNumAlignedAllocs;
                      v144 = (btConvexHullInternal::Vertex **)sAlignedAllocFunc(4 * v143, 16);
                      v134 = stack.m_size;
                    }
                    else
                    {
                      v144 = 0;
                    }
                    v145 = 0;
                    if ( v134 > 0 )
                    {
                      v146 = v144;
                      do
                      {
                        if ( v146 )
                        {
                          *v146 = stack.m_data[v145];
                          v32 = (btConvexHullInternal::Edge *)v212;
                        }
                        ++v145;
                        ++v146;
                      }
                      while ( v145 < v134 );
                      v134 = stack.m_size;
                    }
                    if ( stack.m_data && stack.m_ownsMemory )
                    {
                      ++gNumAlignedFree;
                      sAlignedFreeFunc(stack.m_data);
                      v134 = stack.m_size;
                    }
                    stack.m_ownsMemory = 1;
                    stack.m_data = v144;
                    stack.m_capacity = v143;
                  }
                }
                v147 = &stack.m_data[v134];
                if ( v147 )
                {
                  *v147 = 0;
                  v134 = stack.m_size;
                }
                stack.m_size = v134 + 1;
              }
            }
            else
            {
              v128 = v216->reverse;
              v32->next = v128;
              v128->prev = v32;
            }
          }
          v11 = v215 == 0;
          v148 = v214;
          v149 = v32->reverse;
          v32->face = face;
          v149->face = v148->lastNearbyFace;
          if ( v11 )
            continue;
          goto LABEL_38;
        }
      }
      else
      {
        v121 = **p_edges;
        v32->next = v121;
        v121->prev = v32;
      }
      v122 = (btConvexHullInternal::Edge *)*p_edges;
      v122->next = v32;
      v32->prev = v122;
      goto LABEL_120;
    }
    break;
  }
  v34 = v214->edges->next;
  v210.denominator.high = *(_QWORD *)v217;
  v35 = v34;
  v36 = btConvexHullInternal::Vertex::dot((btConvexHullInternal::Vertex *)&v283, (int)v34->target, &v283, &b);
  if ( btConvexHullInternal::Rational128::compare(v37, (int)v36, v210.denominator.high) >= 0 )
  {
LABEL_42:
    v33 = v218;
    goto LABEL_43;
  }
  while ( 1 )
  {
    v38 = (btConvexHullInternal::Vertex *)v34->reverse;
    v34 = v34->next;
    v214 = v38;
    if ( v34 == v35 )
      break;
    v210.denominator.high = *(_QWORD *)v217;
    v39 = btConvexHullInternal::Vertex::dot((btConvexHullInternal::Vertex *)v217[0], (int)v34->target, &v283, &b);
    if ( btConvexHullInternal::Rational128::compare(v40, (int)v39, v210.denominator.high) >= 0 )
      goto LABEL_42;
  }
LABEL_347:
  btPairSet::~btPairSet(v29, (int)&stack);
  return 1;
}
