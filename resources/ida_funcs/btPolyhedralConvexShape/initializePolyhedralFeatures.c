char __thiscall btPolyhedralConvexShape::initializePolyhedralFeatures(btPolyhedralConvexShape *this)
{
  btConvexPolyhedron *m_polyhedron; // eax
  int v3; // edi
  btConvexPolyhedron *v4; // eax
  int (__thiscall *getNumVertices)(btPolyhedralConvexShape *); // edx
  btAlignedObjectArray<btConvexHullInternal::Vertex *> *v6; // ebx
  int v7; // eax
  int v8; // ecx
  _QWORD *v9; // esi
  void *v10; // ebx
  _QWORD *v11; // eax
  char *v12; // ecx
  int v13; // edx
  btVector3 *v14; // eax
  int m_size; // edi
  __int64 *v16; // eax
  __int64 v17; // xmm0_8
  __int64 v18; // xmm1_8
  int v19; // ecx
  int v20; // esi
  void *v21; // eax
  btAlignedObjectArray<btConvexHullInternal::Vertex *> *v22; // ecx
  btFace *m_data; // esi
  btPolyhedralConvexShape *v24; // edi
  int v25; // ebx
  btAlignedObjectArray<btVector3> *p_m_vertices; // esi
  int v27; // ecx
  btAlignedObjectArray<btConvexHullInternal::Vertex *> *v28; // ecx
  int v29; // edx
  int v30; // edi
  btVector3 *v31; // eax
  btVector3 *v32; // eax
  __int64 v33; // xmm0_8
  __int64 v34; // xmm1_8
  int v35; // eax
  int v36; // edx
  __m128 *p_mVec128; // ecx
  btVector3 *v38; // esi
  int v39; // ecx
  int v40; // edx
  __m128 *v41; // eax
  unsigned __int64 v42; // xmm0_8
  float *m_plane; // esi
  btConvexHullComputer::Edge *v44; // ebx
  int targetVertex; // edi
  int v46; // ecx
  int v47; // eax
  int v48; // eax
  float v49; // edx
  int v50; // eax
  _DWORD *v51; // ecx
  void *v52; // eax
  int *v53; // eax
  btVector3 *v54; // edx
  int v55; // eax
  __m128 *v56; // edi
  float v57; // xmm1_4
  float v58; // xmm1_4
  float v59; // xmm1_4
  float v60; // xmm0_4
  float v61; // xmm0_4
  float v62; // xmm1_4
  float v63; // xmm0_4
  btVector3 *v64; // ebx
  float v65; // xmm3_4
  float v66; // xmm4_4
  _DWORD *v67; // ecx
  int v68; // edx
  int v69; // ecx
  int v70; // edx
  int v71; // edi
  int v72; // ebx
  _DWORD *v73; // esi
  _DWORD *v74; // eax
  char *v75; // edx
  int v76; // ecx
  int *v77; // eax
  int v78; // edi
  int v79; // esi
  int v80; // ebx
  _DWORD *v81; // eax
  btFace *v82; // eax
  float v83; // xmm0_4
  float v84; // xmm0_4
  int v85; // edx
  _DWORD *v86; // esi
  int v87; // ecx
  int v88; // edi
  _DWORD *v89; // esi
  _DWORD *v90; // eax
  char *v91; // edx
  int v92; // ecx
  _DWORD *v93; // eax
  int v94; // eax
  int v95; // ecx
  int v96; // esi
  float v97; // xmm3_4
  float v98; // xmm2_4
  float v99; // xmm0_4
  btFace *v100; // ebx
  float v101; // xmm4_4
  float v102; // xmm0_4
  float v103; // xmm0_4
  long double v104; // st7
  float v105; // xmm1_4
  float v106; // xmm5_4
  long double v107; // st7
  float v108; // xmm7_4
  float v109; // xmm6_4
  long double v110; // st7
  int v111; // edi
  int v112; // edx
  btVector3 *v113; // eoff
  float v114; // xmm1_4
  float v115; // xmm4_4
  float v116; // xmm5_4
  float v117; // xmm2_4
  int v118; // eax
  float v119; // xmm3_4
  float *v120; // ecx
  int v121; // ebx
  GrahamVector2 *v122; // eax
  GrahamVector2 *v123; // edi
  int v124; // edx
  GrahamVector2 *v125; // eax
  GrahamVector2 *v126; // ecx
  GrahamVector2 *v127; // eax
  float *v128; // eax
  float v129; // edx
  int v130; // esi
  unsigned int v131; // ecx
  unsigned int v132; // edx
  int v133; // ebx
  int v134; // eax
  btConvexHullInternal::Vertex **v135; // edi
  btConvexHullInternal::Vertex **v136; // eax
  char *v137; // edx
  int v138; // ecx
  btConvexHullInternal::Vertex **v139; // eax
  btConvexPolyhedron *v140; // ebx
  int v141; // ecx
  int v142; // eax
  btAlignedObjectArray<btFace> *v143; // ebx
  int v144; // eax
  btFace *v145; // eax
  btAlignedObjectArray<btConvexHullInternal::Vertex *> *v146; // ecx
  btFace *v147; // esi
  btFace *v148; // edi
  int v149; // edi
  btFace *v150; // esi
  int *v151; // eax
  btFace *v152; // esi
  bool v153; // zf
  btFace *v154; // eax
  btAlignedObjectArray<btConvexHullInternal::Vertex *> *v155; // ecx
  char *v156; // esi
  GrahamVector2 *v157; // eax
  btConvexPolyhedron *v158; // edi
  btAlignedObjectArray<btConvexHullInternal::Vertex *> *m_capacity; // ecx
  btAlignedObjectArray<btFace> *p_m_faces; // edi
  btFace *v161; // ebx
  int v162; // eax
  int v163; // eax
  btFace *v164; // eax
  btAlignedObjectArray<btConvexHullInternal::Vertex *> *v165; // ecx
  btFace *v166; // esi
  btFace *v167; // ebx
  int v168; // ebx
  btFace *v169; // esi
  int *v170; // eax
  btFace *v171; // esi
  btFace *v172; // eax
  int v173; // esi
  btAlignedObjectArray<btFace> *v174; // ecx
  btSoftBody::Cluster *v175; // ecx
  bool v177; // [esp+2B68h] [ebp-210h]
  int v178; // [esp+2B6Ch] [ebp-20Ch]
  float v179; // [esp+2B70h] [ebp-208h]
  float v180; // [esp+2B74h] [ebp-204h]
  int v181; // [esp+2B7Ch] [ebp-1FCh]
  btAlignedObjectArray<btConvexHullInternal::Vertex *> *p_otherArray; // [esp+2B7Ch] [ebp-1FCh]
  int v183; // [esp+2B7Ch] [ebp-1FCh]
  btFace *v184; // [esp+2B7Ch] [ebp-1FCh]
  int v185; // [esp+2B7Ch] [ebp-1FCh]
  int v186; // [esp+2B7Ch] [ebp-1FCh]
  int v187; // [esp+2B7Ch] [ebp-1FCh]
  int v188; // [esp+2B7Ch] [ebp-1FCh]
  int v189; // [esp+2B7Ch] [ebp-1FCh]
  char *v190; // [esp+2B80h] [ebp-1F8h]
  int v191; // [esp+2B80h] [ebp-1F8h]
  _DWORD *v192; // [esp+2B80h] [ebp-1F8h]
  int v193; // [esp+2B80h] [ebp-1F8h]
  int v194; // [esp+2B80h] [ebp-1F8h]
  int v195; // [esp+2B80h] [ebp-1F8h]
  int v196; // [esp+2B80h] [ebp-1F8h]
  int v197; // [esp+2B84h] [ebp-1F4h]
  int v198; // [esp+2B84h] [ebp-1F4h]
  int v199; // [esp+2B84h] [ebp-1F4h]
  int *p_m_orgIndex; // [esp+2B84h] [ebp-1F4h]
  btFace *v201; // [esp+2B84h] [ebp-1F4h]
  int i; // [esp+2B84h] [ebp-1F4h]
  btAlignedObjectArray<btConvexHullInternal::Vertex *> *v203; // [esp+2B88h] [ebp-1F0h]
  btAlignedObjectArray<btConvexHullInternal::Vertex *> *v204; // [esp+2B88h] [ebp-1F0h]
  btAlignedObjectArray<btConvexHullInternal::Vertex *> *v205; // [esp+2B88h] [ebp-1F0h]
  btAlignedObjectArray<btConvexHullInternal::Vertex *> *v206; // [esp+2B88h] [ebp-1F0h]
  _DWORD *v207; // [esp+2B8Ch] [ebp-1ECh]
  int v208; // [esp+2B8Ch] [ebp-1ECh]
  btFace *v209; // [esp+2B8Ch] [ebp-1ECh]
  int v210; // [esp+2B90h] [ebp-1E8h]
  int v211; // [esp+2B90h] [ebp-1E8h]
  float v213; // [esp+2B98h] [ebp-1E0h]
  __int64 v214; // [esp+2B98h] [ebp-1E0h]
  float v215; // [esp+2B98h] [ebp-1E0h]
  float v216; // [esp+2B9Ch] [ebp-1DCh]
  float v217; // [esp+2B9Ch] [ebp-1DCh]
  __int64 v218; // [esp+2BA0h] [ebp-1D8h]
  float v219; // [esp+2BA0h] [ebp-1D8h]
  float v220; // [esp+2BA0h] [ebp-1D8h]
  float v221; // [esp+2BA4h] [ebp-1D4h]
  int v222; // [esp+2BB0h] [ebp-1C8h]
  float v223; // [esp+2BB0h] [ebp-1C8h]
  btFace *v224; // [esp+2BB0h] [ebp-1C8h]
  btAlignedObjectArray<GrahamVector2> originalPoints; // [esp+2BB4h] [ebp-1C4h] BYREF
  int v226; // [esp+2BCCh] [ebp-1ACh]
  void *v227; // [esp+2BD4h] [ebp-1A4h]
  int v228; // [esp+2BE0h] [ebp-198h]
  int v229; // [esp+2BE4h] [ebp-194h]
  void *v230; // [esp+2BE8h] [ebp-190h]
  float v231; // [esp+2BF0h] [ebp-188h]
  float v232; // [esp+2BF4h] [ebp-184h]
  __int64 v233; // [esp+2BF8h] [ebp-180h]
  __int64 v234; // [esp+2C00h] [ebp-178h]
  float v235; // [esp+2C08h] [ebp-170h]
  float v236; // [esp+2C0Ch] [ebp-16Ch]
  float _X; // [esp+2C10h] [ebp-168h]
  btAlignedObjectArray<btConvexHullInternal::Vertex *> otherArray; // [esp+2C18h] [ebp-160h] BYREF
  __int64 v239; // [esp+2C2Ch] [ebp-14Ch]
  unsigned __int64 v240; // [esp+2C34h] [ebp-144h]
  btAlignedObjectArray<btFace> v241; // [esp+2C54h] [ebp-124h] BYREF
  unsigned __int64 v242; // [esp+2C68h] [ebp-110h]
  unsigned __int64 v243; // [esp+2C70h] [ebp-108h]
  __int64 v244; // [esp+2C78h] [ebp-100h]
  __int64 v245; // [esp+2C80h] [ebp-F8h]
  __m128i v246; // [esp+2C88h] [ebp-F0h] BYREF
  float v247; // [esp+2C98h] [ebp-E0h]
  float v248; // [esp+2C9Ch] [ebp-DCh]
  float v249; // [esp+2CA0h] [ebp-D8h]
  float v250; // [esp+2CA8h] [ebp-D0h]
  float v251; // [esp+2CACh] [ebp-CCh]
  float v252; // [esp+2CB0h] [ebp-C8h]
  btAlignedObjectArray<GrahamVector2> v253; // [esp+2CB4h] [ebp-C4h] BYREF
  btConvexHullComputer v254; // [esp+2CC8h] [ebp-B0h] BYREF
  void *ptr[2]; // [esp+2D10h] [ebp-68h]
  unsigned __int64 v256; // [esp+2D18h] [ebp-60h]
  unsigned __int64 v257; // [esp+2D20h] [ebp-58h]
  char *v258; // [esp+2D40h] [ebp-38h]
  void *v259[4]; // [esp+2D48h] [ebp-30h]
  __int64 v260; // [esp+2D58h] [ebp-20h]
  __int64 v261; // [esp+2D60h] [ebp-18h]
  float v262; // [esp+2D74h] [ebp-4h]

  m_polyhedron = this->m_polyhedron;
  v3 = 0;
  if ( m_polyhedron )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_polyhedron);
  }
  ++gNumAlignedAllocs;
  v4 = (btConvexPolyhedron *)sAlignedAllocFunc(0xA0u, 16);
  if ( v4 )
  {
    v4->__vftable = (btConvexPolyhedron_vtbl *)&btConvexPolyhedron::`vftable';
    v4->m_vertices.m_ownsMemory = 1;
    v4->m_vertices.m_data = 0;
    v4->m_vertices.m_size = 0;
    v4->m_vertices.m_capacity = 0;
    v4->m_faces.m_ownsMemory = 1;
    v4->m_faces.m_data = 0;
    v4->m_faces.m_size = 0;
    v4->m_faces.m_capacity = 0;
    v4->m_uniqueEdges.m_ownsMemory = 1;
    v4->m_uniqueEdges.m_data = 0;
    v4->m_uniqueEdges.m_size = 0;
    v4->m_uniqueEdges.m_capacity = 0;
  }
  else
  {
    v4 = 0;
  }
  this->m_polyhedron = v4;
  getNumVertices = this->getNumVertices;
  ptr[0] = 0;
  v6 = 0;
  v210 = 0;
  if ( getNumVertices(this) > 0 )
  {
    do
    {
      v7 = v3;
      if ( (btAlignedObjectArray<btConvexHullInternal::Vertex *> *)v3 == v6 )
      {
        v8 = 2 * v3;
        if ( !v3 )
          v8 = 1;
        v203 = (btAlignedObjectArray<btConvexHullInternal::Vertex *> *)v8;
        if ( (int)v6 < v8 )
        {
          if ( v8 )
          {
            ++gNumAlignedAllocs;
            v9 = sAlignedAllocFunc(16 * v8, 16);
          }
          else
          {
            v9 = 0;
          }
          v10 = ptr[0];
          if ( v3 > 0 )
          {
            v11 = v9;
            v12 = (char *)((char *)ptr[0] - (char *)v9);
            v13 = v3;
            do
            {
              if ( v11 )
              {
                *v11 = *(_QWORD *)((char *)v11 + (_DWORD)v12);
                v11[1] = *(_QWORD *)((char *)v11 + (_DWORD)v12 + 8);
              }
              v11 += 2;
              --v13;
            }
            while ( v13 );
          }
          if ( v10 )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v10);
          }
          v6 = v203;
          v7 = v3;
          ptr[0] = v9;
        }
      }
      ++v3;
      v14 = (btVector3 *)((char *)ptr[0] + 16 * v7);
      if ( v14 )
        *(__m128i *)v14 = v246;
      this->getVertex(this, v210++, v14);
    }
    while ( v210 < this->getNumVertices(this) );
  }
  v254.vertices.m_ownsMemory = 1;
  memset(&v254.vertices.m_size, 0, 12);
  v254.edges.m_ownsMemory = 1;
  memset(&v254.edges.m_size, 0, 12);
  v254.faces.m_ownsMemory = 1;
  memset(&v254.faces.m_size, 0, 12);
  btConvexHullComputer::compute(&v254, v3, (char *)ptr[0], v177, v178, v179, v180);
  m_size = v254.faces.m_size;
  v16 = 0;
  v258 = 0;
  if ( v254.faces.m_size >= 0 )
  {
    if ( v254.faces.m_size > 0 )
    {
      ++gNumAlignedAllocs;
      v16 = (__int64 *)sAlignedAllocFunc(16 * v254.faces.m_size, 16);
      v258 = (char *)v16;
    }
    if ( m_size > 0 )
    {
      v17 = v246.m128i_i64[1];
      v18 = v246.m128i_i64[0];
      v19 = m_size;
      do
      {
        if ( v16 )
        {
          *v16 = v18;
          v16[1] = v17;
        }
        v16 += 2;
        --v19;
      }
      while ( v19 );
    }
  }
  v241.m_ownsMemory = 1;
  v241.m_data = 0;
  v241.m_capacity = 0;
  otherArray.m_ownsMemory = 1;
  memset(&otherArray.m_size, 0, 12);
  if ( m_size >= 0 )
  {
    if ( m_size > 0 )
    {
      ++gNumAlignedAllocs;
      v241.m_ownsMemory = 1;
      v241.m_data = (btFace *)sAlignedAllocFunc(36 * m_size, 16);
      v241.m_capacity = m_size;
      m_data = v241.m_data;
      do
      {
        if ( m_data )
        {
          btAlignedObjectArray<int>::btAlignedObjectArray<int>(
            v22,
            (btAlignedObjectArray<btConvexHullInternal::Vertex *> *)m_data,
            &otherArray);
          *(_QWORD *)m_data->m_plane = v239;
          *(_QWORD *)&m_data->m_plane[2] = v240;
        }
        ++m_data;
        --m_size;
      }
      while ( m_size );
    }
  }
  else
  {
    v20 = 36 * m_size + 12;
    do
    {
      v21 = *(void **)v20;
      if ( *(_DWORD *)v20 )
      {
        if ( *(_BYTE *)(v20 + 4) )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v21);
        }
        *(_DWORD *)v20 = 0;
      }
      *(_BYTE *)(v20 + 4) = 1;
      *(_DWORD *)v20 = 0;
      *(_DWORD *)(v20 - 8) = 0;
      *(_DWORD *)(v20 - 4) = 0;
      v20 += 36;
    }
    while ( v20 < 12 );
  }
  v24 = this;
  v25 = v254.vertices.m_size;
  p_m_vertices = &this->m_polyhedron->m_vertices;
  v241.m_size = v254.faces.m_size;
  v27 = p_m_vertices->m_size;
  v181 = v27;
  if ( v254.vertices.m_size >= v27 )
  {
    if ( v254.vertices.m_size > v27 && p_m_vertices->m_capacity < v254.vertices.m_size )
    {
      if ( v254.vertices.m_size )
      {
        ++gNumAlignedAllocs;
        v204 = (btAlignedObjectArray<btConvexHullInternal::Vertex *> *)sAlignedAllocFunc(16 * v254.vertices.m_size, 16);
      }
      else
      {
        v204 = 0;
      }
      if ( p_m_vertices->m_size > 0 )
      {
        v28 = v204;
        v29 = 0;
        v30 = p_m_vertices->m_size;
        do
        {
          if ( v28 )
          {
            v31 = p_m_vertices->m_data;
            *(_QWORD *)&v28->m_allocator = v31[v29].mVec128.m128_u64[0];
            *(_QWORD *)&v28->m_capacity = v31[v29].mVec128.m128_u64[1];
          }
          ++v29;
          v28 = (btAlignedObjectArray<btConvexHullInternal::Vertex *> *)((char *)v28 + 16);
          --v30;
        }
        while ( v30 );
      }
      v32 = p_m_vertices->m_data;
      if ( v32 )
      {
        if ( p_m_vertices->m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v32);
        }
        p_m_vertices->m_data = 0;
      }
      v27 = v181;
      v24 = this;
      p_m_vertices->m_ownsMemory = 1;
      p_m_vertices->m_data = (btVector3 *)v204;
      p_m_vertices->m_capacity = v25;
    }
    if ( v27 < v25 )
    {
      v33 = v246.m128i_i64[1];
      v34 = v246.m128i_i64[0];
      v35 = v27;
      v36 = v25 - v27;
      do
      {
        p_mVec128 = &p_m_vertices->m_data[v35].mVec128;
        if ( p_mVec128 )
        {
          p_mVec128->m128_u64[0] = v34;
          p_mVec128->m128_u64[1] = v33;
        }
        ++v35;
        --v36;
      }
      while ( v36 );
    }
  }
  p_m_vertices->m_size = v25;
  v38 = v254.vertices.m_data;
  if ( v25 > 0 )
  {
    v39 = 0;
    v40 = v25;
    do
    {
      v41 = &v24->m_polyhedron->m_vertices.m_data[v39].mVec128;
      v41->m128_u64[0] = v38[v39].mVec128.m128_u64[0];
      v42 = v38[v39++].mVec128.m128_u64[1];
      --v40;
      v41->m128_u64[1] = v42;
    }
    while ( v40 );
  }
  v197 = 0;
  if ( v254.faces.m_size > 0 )
  {
    HIDWORD(v218) = 0;
    v190 = v258 + 8;
    m_plane = v241.m_data->m_plane;
    do
    {
      v44 = &v254.edges.m_data[v254.faces.m_data[v197]];
      v232 = *(float *)&v44;
      v205 = 0;
      p_otherArray = &otherArray;
      do
      {
        targetVertex = v44[v44->reverse].targetVertex;
        v46 = *((_DWORD *)m_plane - 3);
        v47 = *((_DWORD *)m_plane - 4);
        if ( v47 == v46 )
        {
          if ( v47 )
          {
            v48 = 2 * v47;
            v211 = v48;
          }
          else
          {
            v211 = 1;
            v48 = 1;
          }
          if ( v46 < v48 )
          {
            if ( v48 )
            {
              ++gNumAlignedAllocs;
              v207 = sAlignedAllocFunc(4 * v211, 16);
            }
            else
            {
              v207 = 0;
            }
            v49 = *(m_plane - 4);
            v50 = 0;
            v231 = v49;
            if ( SLODWORD(v49) > 0 )
            {
              v51 = v207;
              do
              {
                if ( v51 )
                {
                  *v51 = *(_DWORD *)(*((_DWORD *)m_plane - 2) + 4 * v50);
                  v49 = v231;
                }
                ++v50;
                ++v51;
              }
              while ( v50 < SLODWORD(v49) );
            }
            v52 = (void *)*((_DWORD *)m_plane - 2);
            if ( v52 )
            {
              if ( *((_BYTE *)m_plane - 4) )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(v52);
              }
              *(m_plane - 2) = 0.0;
            }
            *((_BYTE *)m_plane - 4) = 1;
            *((_DWORD *)m_plane - 2) = v207;
            *((_DWORD *)m_plane - 3) = v211;
          }
        }
        v53 = (int *)(*((_DWORD *)m_plane - 2) + 4 * *((_DWORD *)m_plane - 4));
        if ( v53 )
          *v53 = targetVertex;
        v54 = v254.vertices.m_data;
        ++*((_DWORD *)m_plane - 4);
        v55 = v44->targetVertex;
        v56 = &v54[targetVertex].mVec128;
        v242 = v56->m128_u64[0];
        v243 = v56->m128_u64[1];
        v55 *= 16;
        v244 = *(__int64 *)((char *)v54->mVec128.m128_i64 + v55);
        v245 = *(__int64 *)((char *)&v54->mVec128.m128_i64[1] + v55);
        v219 = *(float *)&v245 - *(float *)&v243;
        v216 = *((float *)&v244 + 1) - *((float *)&v242 + 1);
        v213 = *(float *)&v244 - *(float *)&v242;
        v231 = 1.0
             / sqrtf(
                 (float)((float)((float)(*(float *)&v245 - *(float *)&v243) * (float)(*(float *)&v245 - *(float *)&v243))
                       + (float)((float)(*((float *)&v244 + 1) - *((float *)&v242 + 1))
                               * (float)(*((float *)&v244 + 1) - *((float *)&v242 + 1))))
               + (float)((float)(*(float *)&v244 - *(float *)&v242) * (float)(*(float *)&v244 - *(float *)&v242)));
        *(float *)&v214 = v213 * v231;
        *((float *)&v214 + 1) = v231 * v216;
        *(float *)&v218 = v231 * v219;
        if ( (int)v205 < 2 )
        {
          v205 = (btAlignedObjectArray<btConvexHullInternal::Vertex *> *)((char *)v205 + 1);
          *(_QWORD *)&p_otherArray->m_allocator = v214;
          *(_QWORD *)&p_otherArray->m_capacity = v218;
          p_otherArray = (btAlignedObjectArray<btConvexHullInternal::Vertex *> *)((char *)p_otherArray + 16);
        }
        v44 += v44->reverse + v44[v44->reverse].next;
      }
      while ( v44 != (btConvexHullComputer::Edge *)LODWORD(v232) );
      v57 = 1.0e30;
      if ( v205 == (btAlignedObjectArray<btConvexHullInternal::Vertex *> *)2 )
      {
        *(float *)&v233 = (float)(*(float *)&otherArray.m_size * *((float *)&v239 + 1))
                        - (float)(*(float *)&otherArray.m_capacity * *(float *)&v239);
        *((float *)&v233 + 1) = (float)(*(float *)&otherArray.m_capacity * *(float *)&otherArray.m_ownsMemory)
                              - (float)(*(float *)&otherArray.m_allocator * *((float *)&v239 + 1));
        v58 = (float)(*(float *)&otherArray.m_allocator * *(float *)&v239)
            - (float)(*(float *)&otherArray.m_size * *(float *)&otherArray.m_ownsMemory);
        HIDWORD(v234) = 0;
        *((_QWORD *)v190 - 1) = v233;
        *(float *)&v234 = v58;
        *(_QWORD *)v190 = v234;
        v59 = *((float *)v190 - 1);
        v60 = *(float *)v190;
        v250 = *((float *)v190 - 2);
        v252 = v59;
        v251 = v60;
        v232 = 1.0 / sqrtf((float)((float)(v250 * v250) + (float)(v59 * v59)) + (float)(v60 * v60));
        v61 = v232;
        *((float *)v190 - 2) = v250 * v232;
        v62 = v252 * v61;
        v63 = v61 * v251;
        *((float *)v190 - 1) = v62;
        v57 = 1.0e30;
        *(float *)v190 = v63;
        *m_plane = *((float *)v190 - 2);
        m_plane[1] = *((float *)v190 - 1);
        m_plane[2] = *(float *)v190;
        m_plane[3] = 1.0e30;
      }
      else
      {
        *((_DWORD *)v190 - 2) = 0;
        *((_DWORD *)v190 - 1) = 0;
        *(_DWORD *)v190 = 0;
        *((_DWORD *)v190 + 1) = 0;
      }
      if ( *((int *)m_plane - 4) > 0 )
      {
        v67 = (_DWORD *)*((_DWORD *)m_plane - 2);
        v68 = *((_DWORD *)m_plane - 4);
        do
        {
          v64 = this->m_polyhedron->m_vertices.m_data;
          v65 = *((float *)v190 - 1);
          v66 = *((float *)v190 - 2);
          if ( v57 > (float)((float)((float)(v64[*v67].mVec128.m128_f32[1] * v65)
                                   + (float)(v64[*v67].mVec128.m128_f32[2] * *(float *)v190))
                           + (float)(v66 * v64[*v67].mVec128.m128_f32[0])) )
            v57 = (float)((float)(v64[*v67].mVec128.m128_f32[1] * v65)
                        + (float)(v64[*v67].mVec128.m128_f32[2] * *(float *)v190))
                + (float)(v66 * v64[*v67].mVec128.m128_f32[0]);
          ++v67;
          --v68;
        }
        while ( v68 );
      }
      m_plane[3] = -v57;
      m_plane += 9;
      ++v197;
      v190 += 16;
    }
    while ( v197 < v254.faces.m_size );
  }
  v69 = 0;
  v70 = 0;
  v227 = 0;
  v226 = 0;
  v191 = 0;
  if ( v254.faces.m_size > 0 )
  {
    v71 = 0;
    do
    {
      if ( v71 == v70 )
      {
        v72 = 2 * v71;
        if ( !v71 )
          v72 = 1;
        v183 = v72;
        if ( v70 < v72 )
        {
          if ( v72 )
          {
            ++gNumAlignedAllocs;
            v73 = sAlignedAllocFunc(4 * v72, 16);
          }
          else
          {
            v73 = 0;
          }
          if ( v71 > 0 )
          {
            v74 = v73;
            v75 = (char *)((_BYTE *)v227 - (_BYTE *)v73);
            v76 = v71;
            do
            {
              if ( v74 )
              {
                *v74 = *(_DWORD *)((char *)v74 + (_DWORD)v75);
                v72 = v183;
              }
              ++v74;
              --v76;
            }
            while ( v76 );
          }
          if ( v227 )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v227);
          }
          v69 = v191;
          v227 = v73;
          v70 = v72;
        }
      }
      v77 = (int *)((char *)v227 + 4 * v71);
      if ( v77 )
        *v77 = v69;
      ++v69;
      ++v71;
      v191 = v69;
    }
    while ( v69 < v254.faces.m_size );
    v226 = v71;
    while ( v226 )
    {
      v78 = v226;
      v79 = *((_DWORD *)v227 + v226 - 1);
      v80 = 1;
      ++gNumAlignedAllocs;
      v81 = sAlignedAllocFunc(4u, 16);
      v230 = v81;
      v229 = 1;
      if ( v81 )
        *v81 = v79;
      v82 = &v241.m_data[v79];
      *(float *)&v242 = v82->m_plane[0];
      v83 = v82->m_plane[1];
      v226 = v78 - 1;
      *((float *)&v242 + 1) = v83;
      v84 = v82->m_plane[2];
      v228 = 1;
      *(float *)&v243 = v84;
      v198 = v78 - 2;
      if ( v78 - 2 < 0 )
        goto LABEL_251;
      v85 = v226;
      v192 = (char *)v227 + 4 * v226 - 4;
      v86 = v227;
      do
      {
        v87 = v86[v198];
        v222 = v87;
        if ( (float)((float)((float)(v241.m_data[v87].m_plane[2] * *(float *)&v243)
                           + (float)(v241.m_data[v87].m_plane[1] * *((float *)&v242 + 1)))
                   + (float)(v241.m_data[v87].m_plane[0] * *(float *)&v242)) > 0.99900001 )
        {
          if ( v80 == v229 )
          {
            v88 = 2 * v80;
            if ( !v80 )
              v88 = 1;
            if ( v229 < v88 )
            {
              if ( v88 )
              {
                ++gNumAlignedAllocs;
                v89 = sAlignedAllocFunc(4 * v88, 16);
              }
              else
              {
                v89 = 0;
              }
              if ( v80 > 0 )
              {
                v90 = v89;
                v91 = (char *)((_BYTE *)v230 - (_BYTE *)v89);
                v92 = v80;
                do
                {
                  if ( v90 )
                  {
                    *v90 = *(_DWORD *)((char *)v90 + (_DWORD)v91);
                    v80 = v228;
                  }
                  ++v90;
                  --v92;
                }
                while ( v92 );
              }
              if ( v230 )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(v230);
              }
              v87 = v222;
              v85 = v226;
              v230 = v89;
              v86 = v227;
              v229 = v88;
            }
          }
          v93 = (char *)v230 + 4 * v80;
          if ( v93 )
            *v93 = v87;
          ++v80;
          v94 = 0;
          v228 = v80;
          if ( v85 > 0 )
          {
            while ( v86[v94] != v87 )
            {
              if ( ++v94 >= v85 )
                goto LABEL_154;
            }
            if ( v94 < v85 )
            {
              v95 = v86[v94];
              v86[v94] = *v192;
              --v85;
              *v192 = v95;
              v226 = v85;
              --v192;
            }
          }
        }
LABEL_154:
        --v198;
      }
      while ( v198 >= 0 );
      if ( v80 <= 1 )
      {
LABEL_251:
        for ( i = 0; i < v228; ++i )
        {
          v158 = this->m_polyhedron;
          m_capacity = (btAlignedObjectArray<btConvexHullInternal::Vertex *> *)v158->m_faces.m_capacity;
          p_m_faces = &v158->m_faces;
          v161 = &v241.m_data[*((_DWORD *)v230 + i)];
          v162 = p_m_faces->m_size;
          v224 = v161;
          if ( (btAlignedObjectArray<btConvexHullInternal::Vertex *> *)v162 == m_capacity )
          {
            v163 = v162 ? 2 * v162 : 1;
            v206 = (btAlignedObjectArray<btConvexHullInternal::Vertex *> *)v163;
            if ( (int)m_capacity < v163 )
            {
              if ( v163 )
              {
                ++gNumAlignedAllocs;
                v164 = (btFace *)sAlignedAllocFunc(36 * v163, 16);
              }
              else
              {
                v164 = 0;
              }
              v165 = (btAlignedObjectArray<btConvexHullInternal::Vertex *> *)p_m_faces->m_size;
              v209 = v164;
              if ( (int)v165 > 0 )
              {
                v196 = 0;
                v166 = v164;
                v188 = p_m_faces->m_size;
                do
                {
                  if ( v166 )
                  {
                    v167 = &p_m_faces->m_data[v196];
                    btAlignedObjectArray<int>::btAlignedObjectArray<int>(
                      v165,
                      (btAlignedObjectArray<btConvexHullInternal::Vertex *> *)v166,
                      (const btAlignedObjectArray<btConvexHullInternal::Vertex *> *)v167);
                    *(_QWORD *)v166->m_plane = *(_QWORD *)v167->m_plane;
                    *(_QWORD *)&v166->m_plane[2] = *(_QWORD *)&v167->m_plane[2];
                  }
                  ++v196;
                  ++v166;
                  --v188;
                }
                while ( v188 );
              }
              if ( p_m_faces->m_size > 0 )
              {
                v168 = 0;
                v189 = p_m_faces->m_size;
                do
                {
                  v169 = p_m_faces->m_data;
                  v170 = v169[v168].m_indices.m_data;
                  v171 = &v169[v168];
                  if ( v170 )
                  {
                    if ( v171->m_indices.m_ownsMemory )
                    {
                      ++gNumAlignedFree;
                      sAlignedFreeFunc(v170);
                    }
                    v171->m_indices.m_data = 0;
                  }
                  ++v168;
                  v153 = v189-- == 1;
                  v171->m_indices.m_ownsMemory = 1;
                  v171->m_indices.m_data = 0;
                  v171->m_indices.m_size = 0;
                  v171->m_indices.m_capacity = 0;
                }
                while ( !v153 );
              }
              v172 = p_m_faces->m_data;
              if ( v172 )
              {
                if ( p_m_faces->m_ownsMemory )
                {
                  ++gNumAlignedFree;
                  sAlignedFreeFunc(v172);
                }
                p_m_faces->m_data = 0;
              }
              m_capacity = v206;
              v161 = v224;
              p_m_faces->m_ownsMemory = 1;
              p_m_faces->m_data = v209;
              p_m_faces->m_capacity = (int)v206;
            }
          }
          v173 = (int)&p_m_faces->m_data[p_m_faces->m_size];
          if ( v173 )
          {
            btAlignedObjectArray<int>::btAlignedObjectArray<int>(
              m_capacity,
              (btAlignedObjectArray<btConvexHullInternal::Vertex *> *)v173,
              (const btAlignedObjectArray<btConvexHullInternal::Vertex *> *)v161);
            *(_QWORD *)(v173 + 20) = *(_QWORD *)v161->m_plane;
            *(_QWORD *)(v173 + 28) = *(_QWORD *)&v161->m_plane[2];
          }
          ++p_m_faces->m_size;
        }
      }
      else
      {
        v96 = 0;
        originalPoints.m_ownsMemory = 1;
        memset(&originalPoints.m_size, 0, 12);
        v199 = 0;
        do
        {
          v97 = v241.m_data[*((_DWORD *)v230 + v199)].m_plane[2];
          v98 = v241.m_data[*((_DWORD *)v230 + v199)].m_plane[0];
          v99 = v241.m_data[*((_DWORD *)v230 + v199)].m_plane[1];
          v100 = &v241.m_data[*((_DWORD *)v230 + v199)];
          v101 = v99 - (float)(v97 * 0.0);
          *((float *)&v244 + 1) = (float)(v97 * 0.0) - v98;
          v235 = v98;
          v236 = v99;
          v102 = v99 * 0.0;
          *(float *)&v245 = (float)(v98 * 0.0) - v102;
          v103 = (float)(v102 + (float)(v98 * 0.0)) + v97;
          v184 = v100;
          _X = v97;
          *(float *)&v244 = v101;
          if ( v103 >= -0.9999998807907104 )
          {
            v110 = sqrtf((float)(v103 + *(float *)&clear_value) * 2.0);
            v223 = v110;
            v221 = v110 * 0.5;
            v108 = (float)(*(float *)&clear_value / v223) * *((float *)&v244 + 1);
            v109 = v221;
            v105 = *(float *)&v244 * (float)(*(float *)&clear_value / v223);
            v220 = (float)(*(float *)&clear_value / v223) * *(float *)&v245;
            v106 = v220;
          }
          else
          {
            if ( fabsf(_X) <= hsqt2 )
            {
              v107 = 1.0 / sqrtf((float)(v236 * v236) + (float)(v235 * v235));
              v106 = 0.0;
              *(float *)&v233 = -(v236 * v107);
              v105 = *(float *)&v233;
              *((float *)&v233 + 1) = v107 * v235;
            }
            else
            {
              v104 = 1.0 / sqrtf((float)(_X * _X) + (float)(v236 * v236));
              v105 = 0.0;
              *((float *)&v233 + 1) = -(_X * v104);
              *(float *)&v234 = v104 * v236;
              v106 = *(float *)&v234;
            }
            v108 = *((float *)&v233 + 1);
            v109 = 0.0;
            v220 = v106;
            v221 = 0.0;
          }
          v217 = v108;
          v215 = v105;
          v193 = 0;
          if ( v100->m_indices.m_size > 0 )
          {
            v111 = 0;
            v247 = -v105;
            LODWORD(v248) = LODWORD(v108) ^ 0x80000000;
            v249 = -v106;
            v246.m128i_i64[1] = 0;
            while ( 1 )
            {
              v112 = v100->m_indices.m_data[v111];
              v113 = &this->m_polyhedron->m_vertices.m_data[v112];
              v256 = v113->mVec128.m128_u64[0];
              v257 = v113->mVec128.m128_u64[1];
              v114 = (float)((float)(*(float *)&v257 * v108) + (float)(*(float *)&v256 * v109))
                   - (float)(*((float *)&v256 + 1) * v106);
              v115 = (float)((float)(*((float *)&v256 + 1) * v109) + (float)(*(float *)&v256 * v106))
                   - (float)(v215 * *(float *)&v257);
              v108 = v217;
              v262 = (float)((float)-(float)(*(float *)&v256 * v215) - (float)(*((float *)&v256 + 1) * v217))
                   - (float)(*(float *)&v257 * v220);
              v116 = (float)((float)(*(float *)&v257 * v109) + (float)(v215 * *((float *)&v256 + 1)))
                   - (float)(*(float *)&v256 * v217);
              v109 = v221;
              v118 = 0;
              *(float *)v246.m128i_i32 = (float)((float)((float)(v249 * v115) + (float)(v247 * v262))
                                               + (float)(v114 * v221))
                                       - (float)(v248 * v116);
              *(float *)&v246.m128i_i32[1] = (float)((float)((float)(v248 * v262) + (float)(v115 * v221))
                                                   + (float)(v247 * v116))
                                           - (float)(v114 * v249);
              if ( v96 <= 0 )
              {
LABEL_170:
                *(__m128i *)v259 = _mm_load_si128(&v246);
                HIDWORD(v260) = v112;
                if ( v96 == originalPoints.m_capacity )
                {
                  v121 = 2 * v96;
                  if ( !v96 )
                    v121 = 1;
                  if ( originalPoints.m_capacity < v121 )
                  {
                    if ( v121 )
                    {
                      ++gNumAlignedAllocs;
                      v122 = (GrahamVector2 *)sAlignedAllocFunc(32 * v121, 16);
                      v96 = originalPoints.m_size;
                      v109 = v221;
                      v108 = v217;
                      v123 = v122;
                    }
                    else
                    {
                      v123 = 0;
                    }
                    if ( v96 > 0 )
                    {
                      v124 = 0;
                      v125 = v123;
                      do
                      {
                        if ( v125 )
                        {
                          v126 = &originalPoints.m_data[v124];
                          v125->mVec128.m128_u64[0] = originalPoints.m_data[v124].mVec128.m128_u64[0];
                          v125->mVec128.m128_u64[1] = v126->mVec128.m128_u64[1];
                          *(_QWORD *)&v125->m_angle = *(_QWORD *)&v126->m_angle;
                          *(_QWORD *)(&v125->m_orgIndex + 1) = *(_QWORD *)(&v126->m_orgIndex + 1);
                        }
                        ++v124;
                        ++v125;
                        --v96;
                      }
                      while ( v96 );
                      v96 = originalPoints.m_size;
                    }
                    if ( originalPoints.m_data && originalPoints.m_ownsMemory )
                    {
                      ++gNumAlignedFree;
                      sAlignedFreeFunc(originalPoints.m_data);
                      v96 = originalPoints.m_size;
                      v109 = v221;
                      v108 = v217;
                    }
                    originalPoints.m_data = v123;
                    v111 = v193;
                    originalPoints.m_ownsMemory = 1;
                    originalPoints.m_capacity = v121;
                  }
                }
                v127 = &originalPoints.m_data[v96];
                if ( v127 )
                {
                  v127->btVector3 = *(btVector3 *)v259;
                  *(_QWORD *)&v127->m_angle = v260;
                  *(_QWORD *)(&v127->m_orgIndex + 1) = v261;
                  v96 = originalPoints.m_size;
                }
                v100 = v184;
                originalPoints.m_size = ++v96;
              }
              else
              {
                v120 = &originalPoints.m_data->mVec128.m128_f32[2];
                while ( 1 )
                {
                  v117 = (float)((float)((float)(v248
                                               * (float)((float)((float)-(float)(*(float *)&v256 * v215)
                                                               - (float)(*((float *)&v256 + 1) * v217))
                                                       - (float)(*(float *)&v257 * v220)))
                                       + (float)(v115 * v221))
                               + (float)(v247 * v116))
                       - (float)(v114 * v249);
                  v119 = (float)((float)((float)(v249 * v115) + (float)(v247 * v262)) + (float)(v114 * v221))
                       - (float)(v248 * v116);
                  if ( (float)((float)((float)((float)(v119 - *(v120 - 2)) * (float)(v119 - *(v120 - 2)))
                                     + (float)((float)-*v120 * (float)-*v120))
                             + (float)((float)(v117 - *(v120 - 1)) * (float)(v117 - *(v120 - 1)))) < 0.001 )
                    break;
                  ++v118;
                  v120 += 8;
                  if ( v118 >= v96 )
                    goto LABEL_170;
                }
              }
              v193 = ++v111;
              if ( v111 >= v100->m_indices.m_size )
                break;
              v106 = v220;
            }
          }
          ++v199;
        }
        while ( v199 < v228 );
        v128 = v241.m_data[*(_DWORD *)v230].m_plane;
        v129 = v241.m_data[*(_DWORD *)v230].m_plane[1];
        v130 = 0;
        *(float *)&v239 = *v128;
        v131 = *((_DWORD *)v128 + 2);
        *((float *)&v239 + 1) = v129;
        v132 = *((_DWORD *)v128 + 3);
        v133 = 0;
        otherArray.m_ownsMemory = 1;
        memset(&otherArray.m_size, 0, 12);
        v240 = __PAIR64__(v132, v131);
        v253.m_ownsMemory = 1;
        memset(&v253.m_size, 0, 12);
        GrahamScanConvexHull2D(&v253, &originalPoints);
        if ( v253.m_size > 0 )
        {
          p_m_orgIndex = &v253.m_data->m_orgIndex;
          v185 = v253.m_size;
          do
          {
            if ( v130 == v133 )
            {
              v134 = 2 * v130;
              if ( !v130 )
                v134 = 1;
              v194 = v134;
              if ( v133 < v134 )
              {
                if ( v134 )
                {
                  ++gNumAlignedAllocs;
                  v135 = (btConvexHullInternal::Vertex **)sAlignedAllocFunc(4 * v134, 16);
                }
                else
                {
                  v135 = 0;
                }
                if ( v130 > 0 )
                {
                  v136 = v135;
                  v137 = (char *)((char *)otherArray.m_data - (char *)v135);
                  v138 = v130;
                  do
                  {
                    if ( v136 )
                      *v136 = *(btConvexHullInternal::Vertex **)((char *)v136 + (_DWORD)v137);
                    ++v136;
                    --v138;
                  }
                  while ( v138 );
                }
                if ( otherArray.m_data && otherArray.m_ownsMemory )
                {
                  ++gNumAlignedFree;
                  sAlignedFreeFunc(otherArray.m_data);
                }
                v133 = v194;
                otherArray.m_ownsMemory = 1;
                otherArray.m_data = v135;
                otherArray.m_capacity = v194;
              }
            }
            v139 = &otherArray.m_data[v130];
            if ( v139 )
              *v139 = (btConvexHullInternal::Vertex *)*p_m_orgIndex;
            p_m_orgIndex += 8;
            ++v130;
            --v185;
          }
          while ( v185 );
          otherArray.m_size = v130;
        }
        v140 = this->m_polyhedron;
        v141 = v140->m_faces.m_capacity;
        v142 = v140->m_faces.m_size;
        v143 = &v140->m_faces;
        if ( v142 == v141 )
        {
          v144 = v142 ? 2 * v142 : 1;
          v208 = v144;
          if ( v141 < v144 )
          {
            if ( v144 )
            {
              ++gNumAlignedAllocs;
              v145 = (btFace *)sAlignedAllocFunc(36 * v144, 16);
            }
            else
            {
              v145 = 0;
            }
            v146 = (btAlignedObjectArray<btConvexHullInternal::Vertex *> *)v143->m_size;
            v201 = v145;
            if ( (int)v146 > 0 )
            {
              v195 = 0;
              v147 = v145;
              v186 = v143->m_size;
              do
              {
                if ( v147 )
                {
                  v148 = &v143->m_data[v195];
                  btAlignedObjectArray<int>::btAlignedObjectArray<int>(
                    v146,
                    (btAlignedObjectArray<btConvexHullInternal::Vertex *> *)v147,
                    (const btAlignedObjectArray<btConvexHullInternal::Vertex *> *)v148);
                  *(_QWORD *)v147->m_plane = *(_QWORD *)v148->m_plane;
                  *(_QWORD *)&v147->m_plane[2] = *(_QWORD *)&v148->m_plane[2];
                }
                ++v195;
                ++v147;
                --v186;
              }
              while ( v186 );
            }
            if ( v143->m_size > 0 )
            {
              v149 = 0;
              v187 = v143->m_size;
              do
              {
                v150 = v143->m_data;
                v151 = v150[v149].m_indices.m_data;
                v152 = &v150[v149];
                if ( v151 )
                {
                  if ( v152->m_indices.m_ownsMemory )
                  {
                    ++gNumAlignedFree;
                    sAlignedFreeFunc(v151);
                  }
                  v152->m_indices.m_data = 0;
                }
                ++v149;
                v153 = v187-- == 1;
                v152->m_indices.m_ownsMemory = 1;
                v152->m_indices.m_data = 0;
                v152->m_indices.m_size = 0;
                v152->m_indices.m_capacity = 0;
              }
              while ( !v153 );
            }
            v154 = v143->m_data;
            if ( v154 )
            {
              if ( v143->m_ownsMemory )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(v154);
              }
              v143->m_data = 0;
            }
            v143->m_ownsMemory = 1;
            v143->m_data = v201;
            v143->m_capacity = v208;
          }
        }
        v155 = (btAlignedObjectArray<btConvexHullInternal::Vertex *> *)v143->m_data;
        v156 = (char *)v155 + 36 * v143->m_size;
        if ( v156 )
        {
          btAlignedObjectArray<int>::btAlignedObjectArray<int>(
            v155,
            (btAlignedObjectArray<btConvexHullInternal::Vertex *> *)v156,
            &otherArray);
          *(_QWORD *)(v156 + 20) = v239;
          *(_QWORD *)(v156 + 28) = v240;
        }
        v157 = v253.m_data;
        ++v143->m_size;
        if ( v157 && v253.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v157);
        }
        if ( otherArray.m_data && otherArray.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(otherArray.m_data);
        }
        if ( originalPoints.m_data && originalPoints.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(originalPoints.m_data);
        }
        originalPoints.m_ownsMemory = 1;
        memset(&originalPoints.m_size, 0, 12);
      }
      if ( v230 )
      {
        ++gNumAlignedFree;
        sAlignedFreeFunc(v230);
      }
    }
  }
  btConvexPolyhedron::initialize((btConvexPolyhedron *)this);
  if ( v227 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v227);
  }
  btAlignedObjectArray<btFace>::~btAlignedObjectArray<btFace>(v174, &v241);
  if ( v258 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v258);
  }
  btConvexHullComputer::~btConvexHullComputer(v175, (int)&v254);
  if ( ptr[0] )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(ptr[0]);
  }
  return 1;
}
