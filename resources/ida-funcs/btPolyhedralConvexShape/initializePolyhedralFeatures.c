char __thiscall btPolyhedralConvexShape::initializePolyhedralFeatures(btPolyhedralConvexShape *this)
{
  btConvexPolyhedron *m_polyhedron; // eax
  btConvexPolyhedron *v3; // eax
  btPolyhedralConvexShape_vtbl *v4; // eax
  btConvexHullComputer *v5; // ecx
  int v6; // edi
  _DWORD *v7; // eax
  int v8; // edx
  char *v9; // ecx
  btVector3 *v10; // eax
  btAlignedObjectArray<GrahamVector2> *v11; // ecx
  int v12; // ebx
  char *v13; // eax
  float *v14; // eax
  int v15; // esi
  btFace *v16; // eax
  btFace *v17; // edi
  int v18; // ecx
  btConvexPolyhedron *v19; // ebx
  btFace *m_size; // edi
  int v21; // esi
  btAlignedObjectArray<btVector3> *p_m_vertices; // ebx
  void *v23; // eax
  int v24; // eax
  int v25; // edx
  __m128 *p_mVec128; // esi
  int v27; // eax
  int *v28; // edi
  int *v29; // edi
  int v30; // eax
  int *v31; // esi
  __m128 *v32; // edi
  float *m_plane; // ebx
  int v34; // esi
  int v35; // ecx
  int v36; // eax
  int v37; // edi
  int v38; // edx
  int v39; // eax
  _DWORD *v40; // ecx
  _DWORD *v41; // eax
  int m_capacity; // eax
  int *v43; // esi
  int v44; // esi
  float v45; // xmm1_4
  btFace *v46; // edi
  float v47; // xmm5_4
  float v48; // xmm1_4
  float v49; // xmm0_4
  float v50; // xmm3_4
  int v51; // edi
  float v52; // xmm2_4
  float v53; // xmm3_4
  _DWORD *v54; // edx
  int *v55; // esi
  int v56; // edi
  _DWORD *v57; // eax
  _DWORD *v58; // ebx
  _DWORD *v59; // eax
  int *v60; // eax
  int v61; // esi
  _DWORD *v62; // eax
  int v63; // ecx
  btFace *v64; // esi
  float v65; // xmm0_4
  float v66; // xmm0_4
  int *m_data; // edi
  int v68; // ebx
  _DWORD *v69; // esi
  _DWORD *v70; // eax
  char *v71; // ecx
  _DWORD *v72; // eax
  int LinearSearch; // eax
  int *v74; // eax
  int v75; // edx
  int v76; // xmm2_4
  btFace *v77; // ebx
  float v78; // xmm7_4
  float v79; // xmm4_4
  float v80; // xmm5_4
  float v81; // xmm3_4
  float v82; // xmm5_4
  float v83; // xmm6_4
  float v84; // xmm1_4
  float v85; // xmm6_4
  float v86; // xmm3_4
  int v87; // xmm5_4
  float v88; // xmm1_4
  float v89; // xmm3_4
  float v90; // xmm3_4
  float v91; // xmm1_4
  float v92; // xmm5_4
  float v93; // xmm5_4
  float v94; // xmm4_4
  bool v95; // cc
  int v96; // eax
  int v97; // esi
  float v98; // xmm1_4
  float v99; // xmm6_4
  int v100; // edx
  float v101; // xmm3_4
  float v102; // xmm4_4
  int *v103; // ecx
  btFace *v104; // edx
  int v105; // eax
  GrahamVector2 *v106; // edi
  float *v107; // esi
  int v108; // edi
  int v109; // ebx
  int *v110; // esi
  int *v111; // eax
  char *v112; // ecx
  int v113; // edx
  int *v114; // eax
  btConvexPolyhedron *v115; // edi
  btAlignedObjectArray<GrahamVector2> *v116; // ecx
  int v117; // eax
  btAlignedObjectArray<btFace> *v118; // edi
  int v119; // eax
  btFace *v120; // eax
  btFace *v121; // esi
  int v122; // ebx
  int v123; // ebx
  btFace *v124; // eax
  btFace *v125; // eax
  btAlignedObjectArray<GrahamVector2> *v126; // ecx
  btAlignedObjectArray<GrahamVector2> *v127; // ecx
  btConvexPolyhedron *v128; // edi
  int v129; // eax
  btAlignedObjectArray<btFace> *p_m_faces; // edi
  int v131; // eax
  btFace *v132; // eax
  btFace *v133; // esi
  btFace *v134; // eax
  btAlignedObjectArray<GrahamVector2> *v135; // ecx
  btAlignedObjectArray<btFace> *v136; // ecx
  btAlignedObjectArray<GrahamVector2> *v137; // ecx
  btAlignedObjectArray<GrahamVector2> *v138; // ecx
  btAlignedObjectArray<GrahamVector2> *v139; // ecx
  btAlignedObjectArray<GrahamVector2> *v140; // ecx
  btAlignedObjectArray<GrahamVector2> *v141; // ecx
  btAlignedObjectArray<GrahamVector2> *v143; // [esp-4h] [ebp-1D4h]
  btAlignedObjectArray<GrahamVector2> *v144; // [esp-4h] [ebp-1D4h]
  int v145; // [esp-4h] [ebp-1D4h]
  int v146; // [esp-4h] [ebp-1D4h]
  int v147; // [esp-4h] [ebp-1D4h]
  int v148; // [esp-4h] [ebp-1D4h]
  btAlignedObjectArray<GrahamVector2> *v149; // [esp-4h] [ebp-1D4h]
  btAlignedObjectArray<GrahamVector2> *v150; // [esp-4h] [ebp-1D4h]
  int v151; // [esp-4h] [ebp-1D4h]
  int v152; // [esp-4h] [ebp-1D4h]
  int v153; // [esp+0h] [ebp-1D0h]
  float v154; // [esp+4h] [ebp-1CCh]
  float v155; // [esp+8h] [ebp-1C8h]
  btFace *v156; // [esp+14h] [ebp-1BCh]
  btFace *v157; // [esp+14h] [ebp-1BCh]
  btFace *v158; // [esp+14h] [ebp-1BCh]
  int v159; // [esp+14h] [ebp-1BCh]
  int v160; // [esp+14h] [ebp-1BCh]
  btFace *v161; // [esp+14h] [ebp-1BCh]
  int *p_m_orgIndex; // [esp+14h] [ebp-1BCh]
  btFace *v163; // [esp+14h] [ebp-1BCh]
  btFace *v164; // [esp+14h] [ebp-1BCh]
  btFace *v165; // [esp+14h] [ebp-1BCh]
  btFace *v166; // [esp+18h] [ebp-1B8h]
  btFace *v167; // [esp+18h] [ebp-1B8h]
  btFace *v168; // [esp+18h] [ebp-1B8h]
  btFace *v169; // [esp+18h] [ebp-1B8h]
  btFace *v170; // [esp+18h] [ebp-1B8h]
  btFace *v171; // [esp+18h] [ebp-1B8h]
  btFace *v172; // [esp+18h] [ebp-1B8h]
  btFace *v173; // [esp+18h] [ebp-1B8h]
  int v174; // [esp+1Ch] [ebp-1B4h]
  int v175; // [esp+1Ch] [ebp-1B4h]
  int v176; // [esp+1Ch] [ebp-1B4h]
  int v177; // [esp+1Ch] [ebp-1B4h]
  int v178; // [esp+20h] [ebp-1B0h]
  int v179; // [esp+20h] [ebp-1B0h]
  int v180; // [esp+20h] [ebp-1B0h]
  int v181; // [esp+20h] [ebp-1B0h]
  int v182; // [esp+20h] [ebp-1B0h]
  _DWORD *v183; // [esp+24h] [ebp-1ACh]
  int v184; // [esp+24h] [ebp-1ACh]
  _DWORD *v185; // [esp+24h] [ebp-1ACh]
  int v186; // [esp+24h] [ebp-1ACh]
  int i; // [esp+24h] [ebp-1ACh]
  btFace *p_that; // [esp+28h] [ebp-1A8h] BYREF
  btPolyhedralConvexShape *v189; // [esp+2Ch] [ebp-1A4h]
  float v190; // [esp+30h] [ebp-1A0h]
  float v191; // [esp+34h] [ebp-19Ch]
  float v192; // [esp+38h] [ebp-198h]
  float v193; // [esp+3Ch] [ebp-194h]
  btAlignedObjectArray<GrahamVector2> originalPoints; // [esp+40h] [ebp-190h] BYREF
  int v195; // [esp+54h] [ebp-17Ch] BYREF
  int v196; // [esp+58h] [ebp-178h]
  int v197; // [esp+5Ch] [ebp-174h]
  void *v198; // [esp+60h] [ebp-170h]
  int v199; // [esp+64h] [ebp-16Ch]
  char v200[4]; // [esp+68h] [ebp-168h] BYREF
  int stride; // [esp+6Ch] [ebp-164h]
  int v202; // [esp+70h] [ebp-160h]
  void *ptr; // [esp+74h] [ebp-15Ch]
  int v204; // [esp+78h] [ebp-158h]
  btAlignedObjectArray<int> v205; // [esp+7Ch] [ebp-154h] BYREF
  float v206; // [esp+90h] [ebp-140h]
  float v207; // [esp+94h] [ebp-13Ch]
  float v208; // [esp+98h] [ebp-138h]
  int v209; // [esp+9Ch] [ebp-134h]
  btFace __that; // [esp+A0h] [ebp-130h] BYREF
  int v211; // [esp+D0h] [ebp-100h]
  int v212; // [esp+D4h] [ebp-FCh]
  int v213; // [esp+D8h] [ebp-F8h]
  int v214; // [esp+DCh] [ebp-F4h]
  _DWORD v215[2]; // [esp+ECh] [ebp-E4h] BYREF
  int v216; // [esp+F4h] [ebp-DCh]
  btFace *v217; // [esp+F8h] [ebp-D8h]
  int v218; // [esp+FCh] [ebp-D4h]
  float v219; // [esp+100h] [ebp-D0h]
  float v220; // [esp+104h] [ebp-CCh]
  float v221; // [esp+108h] [ebp-C8h]
  int v222; // [esp+10Ch] [ebp-C4h]
  float v223; // [esp+110h] [ebp-C0h]
  float v224; // [esp+114h] [ebp-BCh]
  float v225; // [esp+118h] [ebp-B8h]
  int v226; // [esp+11Ch] [ebp-B4h]
  int coords; // [esp+124h] [ebp-ACh] BYREF
  int v228; // [esp+128h] [ebp-A8h]
  int v229; // [esp+12Ch] [ebp-A4h]
  int v230; // [esp+130h] [ebp-A0h]
  int v231; // [esp+134h] [ebp-9Ch]
  _DWORD v232[3]; // [esp+138h] [ebp-98h] BYREF
  int v233; // [esp+144h] [ebp-8Ch]
  int v234; // [esp+148h] [ebp-88h]
  int v235; // [esp+14Ch] [ebp-84h] BYREF
  int v236; // [esp+150h] [ebp-80h]
  int v237; // [esp+154h] [ebp-7Ch]
  int v238; // [esp+158h] [ebp-78h]
  int v239; // [esp+15Ch] [ebp-74h]
  _DWORD v240[2]; // [esp+160h] [ebp-70h] BYREF
  int v241; // [esp+168h] [ebp-68h]
  char *v242; // [esp+16Ch] [ebp-64h]
  int v243; // [esp+170h] [ebp-60h]
  int v244; // [esp+174h] [ebp-5Ch]
  btFace *v245; // [esp+178h] [ebp-58h]
  btAlignedObjectArray<GrahamVector2> hull; // [esp+17Ch] [ebp-54h] BYREF
  int v247; // [esp+190h] [ebp-40h]
  float v248; // [esp+194h] [ebp-3Ch]
  int v249; // [esp+198h] [ebp-38h]
  int v250; // [esp+19Ch] [ebp-34h]
  float v251; // [esp+1ACh] [ebp-24h]
  _DWORD v252[8]; // [esp+1B0h] [ebp-20h] BYREF

  m_polyhedron = this->m_polyhedron;
  v189 = this;
  if ( m_polyhedron )
    btAlignedFreeInternal(m_polyhedron);
  v3 = (btConvexPolyhedron *)btAlignedAllocInternal(0xA0u);
  if ( v3 )
  {
    v3->__vftable = (btConvexPolyhedron_vtbl *)&btConvexPolyhedron::`vftable';
    v3->m_vertices.m_ownsMemory = 1;
    v3->m_vertices.m_data = 0;
    v3->m_vertices.m_size = 0;
    v3->m_vertices.m_capacity = 0;
    v3->m_faces.m_ownsMemory = 1;
    v3->m_faces.m_data = 0;
    v3->m_faces.m_size = 0;
    v3->m_faces.m_capacity = 0;
    v3->m_uniqueEdges.m_ownsMemory = 1;
    v3->m_uniqueEdges.m_data = 0;
    v3->m_uniqueEdges.m_size = 0;
    v3->m_uniqueEdges.m_capacity = 0;
  }
  else
  {
    v3 = 0;
  }
  this->m_polyhedron = v3;
  v4 = this->__vftable;
  LOBYTE(v204) = 1;
  ptr = 0;
  stride = 0;
  v202 = 0;
  v178 = 0;
  if ( v4->getNumVertices(this) > 0 )
  {
    do
    {
      v6 = stride;
      v156 = (btFace *)stride;
      if ( stride == v202 )
      {
        v174 = stride ? 2 * stride : 1;
        if ( v202 < v174 )
        {
          if ( v174 )
            v183 = btAlignedAllocInternal(16 * v174);
          else
            v183 = 0;
          if ( stride > 0 )
          {
            v7 = v183;
            v8 = stride;
            v9 = (char *)((_BYTE *)ptr - (_BYTE *)v183);
            do
            {
              if ( v7 )
              {
                *v7 = *(_DWORD *)((char *)v7 + (_DWORD)v9);
                v7[1] = *(_DWORD *)((char *)v7 + (_DWORD)v9 + 4);
                v7[2] = *(_DWORD *)((char *)v7 + (_DWORD)v9 + 8);
                v7[3] = *(_DWORD *)((char *)v7 + (_DWORD)v9 + 12);
                v6 = (int)v156;
              }
              v7 += 4;
              --v8;
            }
            while ( v8 );
          }
          if ( ptr )
            btAlignedFreeInternal(ptr);
          ptr = v183;
          LOBYTE(v204) = 1;
          v202 = v174;
        }
      }
      ++stride;
      v10 = (btVector3 *)((char *)ptr + 16 * v6);
      if ( v10 )
      {
        v10->mVec128.m128_i32[0] = v247;
        v10->mVec128.m128_f32[1] = v248;
        v10->mVec128.m128_i32[2] = v249;
        v10->mVec128.m128_i32[3] = v250;
      }
      this->getVertex(this, v178++, v10);
    }
    while ( v178 < this->getNumVertices(this) );
  }
  LOBYTE(v231) = 1;
  v230 = 0;
  v228 = 0;
  v229 = 0;
  LOBYTE(v234) = 1;
  v233 = 0;
  v232[1] = 0;
  v232[2] = 0;
  LOBYTE(v239) = 1;
  v238 = 0;
  v236 = 0;
  v237 = 0;
  btConvexHullComputer::compute(v5, &coords, (int)ptr, stride, v153, v154, v155);
  v12 = v236;
  LOBYTE(v243) = 1;
  v242 = 0;
  v241 = 0;
  if ( v236 >= 0 )
  {
    if ( v236 > 0 )
    {
      v13 = (char *)btAlignedAllocInternal(16 * v236);
      v11 = v143;
      LOBYTE(v243) = 1;
      v242 = v13;
      v241 = v12;
    }
    if ( v12 > 0 )
    {
      v14 = (float *)v242;
      v11 = (btAlignedObjectArray<GrahamVector2> *)v12;
      do
      {
        if ( v14 )
        {
          *(_DWORD *)v14 = v247;
          v14[1] = v248;
          *((_DWORD *)v14 + 2) = v249;
          *((_DWORD *)v14 + 3) = v250;
        }
        v14 += 4;
        v11 = (btAlignedObjectArray<GrahamVector2> *)((char *)v11 - 1);
      }
      while ( v11 );
    }
  }
  v240[1] = v12;
  LOBYTE(v218) = 1;
  v217 = 0;
  v216 = 0;
  __that.m_indices.m_ownsMemory = 1;
  memset(&__that.m_indices.m_size, 0, 12);
  if ( v12 >= 0 )
  {
    if ( v12 > 0 )
    {
      v16 = (btFace *)btAlignedAllocInternal(36 * v12);
      v11 = v144;
      LOBYTE(v218) = 1;
      v217 = v16;
      v216 = v12;
      v17 = v16;
      do
      {
        if ( v17 )
          btFace::btFace(v17);
        ++v17;
        --v12;
      }
      while ( v12 );
    }
  }
  else
  {
    v15 = 36 * v12;
    do
    {
      btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v11, v15);
      v15 += 36;
    }
    while ( v15 < 0 );
  }
  v215[1] = v236;
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v11, (int)&__that);
  v19 = v189->m_polyhedron;
  m_size = (btFace *)v19->m_vertices.m_size;
  v21 = v228;
  p_m_vertices = &v19->m_vertices;
  v157 = m_size;
  if ( v228 >= (int)m_size )
  {
    if ( v228 > (int)m_size && p_m_vertices->m_capacity < v228 )
    {
      if ( v228 )
      {
        v23 = btAlignedAllocInternal(16 * v228);
        v18 = v145;
        v184 = (int)v23;
      }
      else
      {
        v184 = 0;
      }
      v24 = p_m_vertices->m_size;
      if ( v24 > 0 )
      {
        v18 = v184;
        v25 = 0;
        do
        {
          if ( v18 )
          {
            p_mVec128 = &p_m_vertices->m_data[v25].mVec128;
            *(_DWORD *)v18 = p_mVec128->m128_i32[0];
            p_mVec128 = (__m128 *)((char *)p_mVec128 + 4);
            *(_DWORD *)(v18 + 4) = p_mVec128->m128_i32[0];
            p_mVec128 = (__m128 *)((char *)p_mVec128 + 4);
            *(_DWORD *)(v18 + 8) = p_mVec128->m128_i32[0];
            *(_DWORD *)(v18 + 12) = p_mVec128->m128_i32[1];
            m_size = v157;
            v21 = v228;
          }
          ++v25;
          v18 += 16;
          --v24;
        }
        while ( v24 );
      }
      if ( p_m_vertices->m_data )
      {
        if ( p_m_vertices->m_ownsMemory )
        {
          btAlignedFreeInternal(p_m_vertices->m_data);
          v18 = v146;
        }
        p_m_vertices->m_data = 0;
      }
      p_m_vertices->m_ownsMemory = 1;
      p_m_vertices->m_data = (btVector3 *)v184;
      p_m_vertices->m_capacity = v21;
    }
    if ( (int)m_size < v21 )
    {
      v27 = (int)m_size;
      v18 = v21 - (_DWORD)m_size;
      do
      {
        v28 = (int *)&p_m_vertices->m_data[v27];
        if ( v28 )
        {
          *v28 = v247;
          v29 = v28 + 1;
          *(float *)v29++ = v248;
          *v29 = v249;
          v29[1] = v250;
          v21 = v228;
        }
        ++v27;
        --v18;
      }
      while ( v18 );
    }
  }
  p_m_vertices->m_size = v21;
  if ( v21 > 0 )
  {
    v18 = v228;
    v30 = 0;
    do
    {
      v31 = (int *)(v30 * 16 + v230);
      v32 = &v189->m_polyhedron->m_vertices.m_data[v30].mVec128;
      v32->m128_i32[0] = *(_DWORD *)(v30 * 16 + v230);
      ++v31;
      v32 = (__m128 *)((char *)v32 + 4);
      v32->m128_i32[0] = *v31++;
      v32 = (__m128 *)((char *)v32 + 4);
      v32->m128_i32[0] = *v31;
      ++v30;
      --v18;
      v32->m128_i32[1] = v31[1];
    }
    while ( v18 );
  }
  v175 = 0;
  if ( v236 > 0 )
  {
    v222 = 0;
    v158 = (btFace *)(v242 + 8);
    m_plane = v217->m_plane;
    do
    {
      v179 = 0;
      v245 = (btFace *)(v233 + 12 * *(_DWORD *)(v238 + 4 * v175));
      v166 = v245;
      p_that = &__that;
      do
      {
        v34 = *(&v166->m_indices.m_capacity + 3 * v166->m_indices.m_size);
        v35 = *((_DWORD *)m_plane - 3);
        v36 = *((_DWORD *)m_plane - 4);
        v244 = v34;
        if ( v36 == v35 )
        {
          v37 = v36 ? 2 * v36 : 1;
          if ( v35 < v37 )
          {
            if ( v37 )
              v185 = btAlignedAllocInternal(4 * v37);
            else
              v185 = 0;
            v38 = *((_DWORD *)m_plane - 4);
            v39 = 0;
            if ( v38 > 0 )
            {
              v40 = v185;
              do
              {
                if ( v40 )
                {
                  *v40 = *(_DWORD *)(*((_DWORD *)m_plane - 2) + 4 * v39);
                  v34 = v244;
                }
                ++v39;
                ++v40;
              }
              while ( v39 < v38 );
            }
            if ( *((_DWORD *)m_plane - 2) )
            {
              if ( *((_BYTE *)m_plane - 4) )
                btAlignedFreeInternal(*((void **)m_plane - 2));
              *(m_plane - 2) = 0.0;
            }
            *((_BYTE *)m_plane - 4) = 1;
            *((_DWORD *)m_plane - 2) = v185;
            *((_DWORD *)m_plane - 3) = v37;
          }
        }
        v41 = (_DWORD *)(*((_DWORD *)m_plane - 2) + 4 * *((_DWORD *)m_plane - 4));
        if ( v41 )
          *v41 = v34;
        ++*((_DWORD *)m_plane - 4);
        m_capacity = v166->m_indices.m_capacity;
        v43 = (int *)(v230 + 16 * v34);
        v211 = *v43++;
        v212 = *v43++;
        v213 = *v43;
        v214 = v43[1];
        v44 = v230 + 16 * m_capacity;
        v223 = *(float *)v44;
        v44 += 4;
        v224 = *(float *)v44;
        v44 += 4;
        v225 = *(float *)v44;
        v226 = *(_DWORD *)(v44 + 4);
        v45 = s_bm_current_air_resistance
            / fsqrt(
                (float)((float)((float)(v223 - *(float *)&v211) * (float)(v223 - *(float *)&v211))
                      + (float)((float)(v225 - *(float *)&v213) * (float)(v225 - *(float *)&v213)))
              + (float)((float)(v224 - *(float *)&v212) * (float)(v224 - *(float *)&v212)));
        v219 = (float)(v223 - *(float *)&v211) * v45;
        v220 = v45 * (float)(v224 - *(float *)&v212);
        v221 = v45 * (float)(v225 - *(float *)&v213);
        if ( v179 < 2 )
        {
          v46 = p_that;
          ++v179;
          p_that = (btFace *)((char *)p_that + 16);
          *(float *)&v46->m_indices.m_allocator = v219;
          v46 = (btFace *)((char *)v46 + 4);
          *(float *)&v46->m_indices.m_allocator = v220;
          v46 = (btFace *)((char *)v46 + 4);
          *(float *)&v46->m_indices.m_allocator = v221;
          v46->m_indices.m_size = v222;
        }
        v166 = (btFace *)((char *)v166
                        + 12 * *((_DWORD *)&v166->m_indices.m_allocator + 3 * v166->m_indices.m_size)
                        + 12 * v166->m_indices.m_size);
      }
      while ( v166 != v245 );
      v47 = FLOAT_1_0e30;
      v18 = (int)&v158[-1].m_plane[2];
      if ( v179 == 2 )
      {
        v206 = (float)(__that.m_plane[1] * *(float *)&__that.m_indices.m_size)
             - (float)(__that.m_plane[0] * *(float *)&__that.m_indices.m_capacity);
        v207 = (float)(*(float *)&__that.m_indices.m_ownsMemory * *(float *)&__that.m_indices.m_capacity)
             - (float)(*(float *)&__that.m_indices.m_allocator * __that.m_plane[1]);
        v208 = (float)(*(float *)&__that.m_indices.m_allocator * __that.m_plane[0])
             - (float)(*(float *)&__that.m_indices.m_ownsMemory * *(float *)&__that.m_indices.m_size);
        v209 = 0;
        *(float *)v18 = v206;
        *(float *)(v18 + 4) = v207;
        *(float *)&v158->m_indices.m_allocator = v208;
        *(_DWORD *)(v18 + 12) = v209;
        v48 = v158[-1].m_plane[3];
        v49 = *(float *)&v158->m_indices.m_allocator;
        v50 = s_bm_current_air_resistance
            / fsqrt((float)((float)(*(float *)v18 * *(float *)v18) + (float)(v48 * v48)) + (float)(v49 * v49));
        *(float *)v18 = *(float *)v18 * v50;
        v158[-1].m_plane[3] = v48 * v50;
        *(float *)&v158->m_indices.m_allocator = v49 * v50;
        *m_plane = *(float *)v18;
        m_plane[1] = v158[-1].m_plane[3];
        m_plane[2] = *(float *)&v158->m_indices.m_allocator;
        m_plane[3] = FLOAT_1_0e30;
      }
      else
      {
        *(_DWORD *)v18 = 0;
        v158[-1].m_plane[3] = 0.0;
        *(_DWORD *)&v158->m_indices.m_allocator = 0;
        v158->m_indices.m_size = 0;
      }
      v51 = *((_DWORD *)m_plane - 4);
      if ( v51 > 0 )
      {
        v53 = *(float *)v18;
        v54 = (_DWORD *)*((_DWORD *)m_plane - 2);
        do
        {
          v18 = (int)&v189->m_polyhedron->m_vertices.m_data[*v54];
          v52 = v158[-1].m_plane[3];
          if ( v47 > (float)((float)((float)(*(float *)(v18 + 4) * v52)
                                   + (float)(*(float *)(v18 + 8) * *(float *)&v158->m_indices.m_allocator))
                           + (float)(v53 * *(float *)v18)) )
            v47 = (float)((float)(*(float *)(v18 + 4) * v52)
                        + (float)(*(float *)(v18 + 8) * *(float *)&v158->m_indices.m_allocator))
                + (float)(v53 * *(float *)v18);
          ++v54;
          --v51;
        }
        while ( v51 );
      }
      ++v175;
      v158 = (btFace *)((char *)v158 + 16);
      *((_DWORD *)m_plane + 3) = LODWORD(v47) ^ _mask__NegFloat_;
      m_plane += 9;
    }
    while ( v175 < v236 );
  }
  v55 = 0;
  v56 = 0;
  v205.m_ownsMemory = 1;
  memset(&v205.m_size, 0, 12);
  v180 = 0;
  if ( v236 > 0 )
  {
    do
    {
      if ( v56 == v205.m_capacity )
      {
        v159 = v56 ? 2 * v56 : 1;
        if ( v205.m_capacity < v159 )
        {
          if ( v159 )
          {
            v57 = btAlignedAllocInternal(4 * v159);
            v18 = v147;
            v58 = v57;
          }
          else
          {
            v58 = 0;
          }
          if ( v56 > 0 )
          {
            v59 = v58;
            v18 = (char *)v55 - (char *)v58;
            v167 = (btFace *)v56;
            do
            {
              if ( v59 )
                *v59 = *(_DWORD *)((char *)v59 + v18);
              ++v59;
              v167 = (btFace *)((char *)v167 - 1);
            }
            while ( v167 );
          }
          if ( v55 )
          {
            btAlignedFreeInternal(v55);
            v18 = v148;
          }
          v205.m_ownsMemory = 1;
          v55 = v58;
          v205.m_capacity = v159;
        }
      }
      v60 = &v55[v56];
      if ( v60 )
      {
        v18 = v180;
        *v60 = v180;
      }
      ++v56;
      ++v180;
    }
    while ( v180 < v236 );
    v205.m_size = v56;
    v205.m_data = v55;
    if ( v56 )
    {
      while ( 1 )
      {
        v61 = v55[v56 - 1];
        v62 = btAlignedAllocInternal(4u);
        v63 = 1;
        LOBYTE(v199) = 1;
        v198 = v62;
        v197 = 1;
        if ( v62 )
          *v62 = v61;
        v64 = &v217[v61];
        v219 = v64->m_plane[0];
        v65 = v64->m_plane[1];
        v205.m_size = v56 - 1;
        v220 = v65;
        v66 = v64->m_plane[2];
        v196 = 1;
        v221 = v66;
        v160 = v56 - 2;
        if ( v56 - 2 < 0 )
          goto LABEL_234;
        m_data = v205.m_data;
        v68 = 1;
        do
        {
          p_that = (btFace *)m_data[v160];
          if ( (float)((float)((float)(v217[(_DWORD)p_that].m_plane[0] * v219)
                             + (float)(v217[(_DWORD)p_that].m_plane[2] * v221))
                     + (float)(v217[(_DWORD)p_that].m_plane[1] * v220)) > 0.99900001 )
          {
            if ( v68 == v197 )
            {
              v69 = 0;
              v176 = v68 ? 2 * v68 : 1;
              if ( v197 < v176 )
              {
                if ( v176 )
                  v69 = btAlignedAllocInternal(4 * v176);
                if ( v68 > 0 )
                {
                  v70 = v69;
                  v71 = (char *)((_BYTE *)v198 - (_BYTE *)v69);
                  v168 = (btFace *)v68;
                  do
                  {
                    if ( v70 )
                      *v70 = *(_DWORD *)((char *)v70 + (_DWORD)v71);
                    ++v70;
                    v168 = (btFace *)((char *)v168 - 1);
                  }
                  while ( v168 );
                }
                if ( v198 )
                  btAlignedFreeInternal(v198);
                LOBYTE(v199) = 1;
                v198 = v69;
                v197 = v176;
              }
            }
            v72 = (char *)v198 + 4 * v68;
            if ( v72 )
              *v72 = p_that;
            ++v68;
            LinearSearch = btAlignedObjectArray<int>::findLinearSearch(&v205, (int *)&p_that);
            v63 = v205.m_size;
            if ( LinearSearch < v205.m_size )
            {
              v63 = v205.m_size - 1;
              v74 = &m_data[LinearSearch];
              v75 = *v74;
              *v74 = m_data[v205.m_size - 1];
              m_data[v63] = v75;
              v205.m_size = v63;
            }
          }
          --v160;
        }
        while ( v160 >= 0 );
        v196 = v68;
        if ( v68 <= 1 )
        {
LABEL_234:
          for ( i = 0; i < v196; ++i )
          {
            v128 = v189->m_polyhedron;
            v63 = v128->m_faces.m_capacity;
            v129 = v128->m_faces.m_size;
            p_m_faces = &v128->m_faces;
            if ( v129 == v63 )
            {
              v131 = v129 ? 2 * v129 : 1;
              v182 = v131;
              if ( v63 < v131 )
              {
                if ( v131 )
                {
                  v132 = (btFace *)btAlignedAllocInternal(36 * v131);
                  v63 = v151;
                  v173 = v132;
                }
                else
                {
                  v173 = 0;
                }
                if ( p_m_faces->m_size > 0 )
                {
                  v164 = 0;
                  v133 = v173;
                  p_that = (btFace *)p_m_faces->m_size;
                  do
                  {
                    if ( v133 )
                      btFace::btFace(v133);
                    ++v164;
                    ++v133;
                    p_that = (btFace *)((char *)p_that - 1);
                  }
                  while ( p_that );
                }
                if ( p_m_faces->m_size > 0 )
                {
                  v165 = 0;
                  p_that = (btFace *)p_m_faces->m_size;
                  do
                  {
                    btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
                      (btAlignedObjectArray<GrahamVector2> *)v63,
                      (int)v165++ + (unsigned int)p_m_faces->m_data);
                    p_that = (btFace *)((char *)p_that - 1);
                  }
                  while ( p_that );
                }
                if ( p_m_faces->m_data )
                {
                  if ( p_m_faces->m_ownsMemory )
                  {
                    btAlignedFreeInternal(p_m_faces->m_data);
                    v63 = v152;
                  }
                  p_m_faces->m_data = 0;
                }
                p_m_faces->m_data = v173;
                p_m_faces->m_ownsMemory = 1;
                p_m_faces->m_capacity = v182;
              }
            }
            v134 = &p_m_faces->m_data[p_m_faces->m_size];
            if ( v134 )
              btFace::btFace(v134);
            ++p_m_faces->m_size;
          }
        }
        else
        {
          originalPoints.m_ownsMemory = 1;
          memset(&originalPoints.m_size, 0, 12);
          v186 = 0;
          v76 = _mask__NegFloat_;
          do
          {
            v77 = &v217[*((_DWORD *)v198 + v186)];
            v78 = v77->m_plane[2];
            v79 = v77->m_plane[1];
            v80 = v77->m_plane[0];
            v81 = v79 - (float)(v78 * 0.0);
            v248 = (float)(v78 * 0.0) - v80;
            v82 = v80 * 0.0;
            v83 = v82 - (float)(v79 * 0.0);
            v84 = (float)((float)(v79 * 0.0) + v82) + v78;
            if ( v84 >= -0.9999998807907104 )
            {
              v94 = fsqrt((float)(v84 + s_bm_current_air_resistance) * 2.0);
              v93 = (float)(s_bm_current_air_resistance / v94) * v248;
              v190 = v81 * (float)(s_bm_current_air_resistance / v94);
              v192 = (float)(s_bm_current_air_resistance / v94) * v83;
              v193 = v94 * 0.5;
            }
            else
            {
              v85 = v77->m_plane[2];
              if ( COERCE_FLOAT(LODWORD(v85) & _mask__AbsFloat_) <= hsqt2 )
              {
                v90 = v77->m_plane[0];
                v91 = s_bm_current_air_resistance / fsqrt((float)(v90 * v90) + (float)(v79 * v79));
                v92 = v91 * v79;
                v88 = v91 * v90;
                v87 = LODWORD(v92) ^ v76;
                v89 = 0.0;
              }
              else
              {
                v86 = s_bm_current_air_resistance / fsqrt((float)(v85 * v85) + (float)(v79 * v79));
                *(float *)&v87 = 0.0;
                LODWORD(v88) = COERCE_UNSIGNED_INT(v86 * v85) ^ v76;
                v89 = v86 * v79;
              }
              v190 = *(float *)&v87;
              v93 = v88;
              v192 = v89;
              v193 = 0.0;
            }
            v181 = 0;
            v95 = v77->m_indices.m_size <= 0;
            v191 = v93;
            if ( !v95 )
            {
              v211 = LODWORD(v190) ^ v76;
              v212 = LODWORD(v93) ^ v76;
              v213 = LODWORD(v192) ^ v76;
              v226 = 0;
              v225 = 0.0;
              while ( 1 )
              {
                v96 = v77->m_indices.m_data[v181];
                v97 = (int)&v189->m_polyhedron->m_vertices.m_data[v96];
                v206 = *(float *)v97;
                v97 += 4;
                v207 = *(float *)v97;
                v97 += 4;
                v208 = *(float *)v97;
                v209 = *(_DWORD *)(v97 + 4);
                v98 = (float)((float)(v208 * v93) + (float)(v206 * v193)) - (float)(v207 * v192);
                v99 = (float)((float)(v208 * v193) + (float)(v190 * v207)) - (float)(v206 * v191);
                v251 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v206 * v190) ^ v76) - (float)(v207 * v191))
                     - (float)(v208 * v192);
                v100 = 0;
                v223 = (float)((float)((float)(*(float *)&v213
                                             * (float)((float)((float)(v207 * v193) + (float)(v206 * v192))
                                                     - (float)(v190 * v208)))
                                     + (float)(*(float *)&v211 * v251))
                             + (float)(v98 * v193))
                     - (float)(*(float *)&v212 * v99);
                v224 = (float)((float)((float)(*(float *)&v212 * v251)
                                     + (float)((float)((float)((float)(v207 * v193) + (float)(v206 * v192))
                                                     - (float)(v190 * v208))
                                             * v193))
                             + (float)(*(float *)&v211 * v99))
                     - (float)(v98 * *(float *)&v213);
                if ( originalPoints.m_size <= 0 )
                {
LABEL_165:
                  *(float *)v252 = v223;
                  *(float *)&v252[1] = v224;
                  *(float *)&v252[2] = v225;
                  v252[3] = v226;
                  v252[5] = v96;
                  if ( originalPoints.m_size == originalPoints.m_capacity )
                  {
                    v177 = originalPoints.m_size ? 2 * originalPoints.m_size : 1;
                    if ( originalPoints.m_capacity < v177 )
                    {
                      if ( v177 )
                      {
                        v76 = _mask__NegFloat_;
                        v161 = (btFace *)btAlignedAllocInternal(32 * v177);
                      }
                      else
                      {
                        v161 = 0;
                      }
                      if ( originalPoints.m_size > 0 )
                      {
                        v104 = v161;
                        v105 = 0;
                        v169 = (btFace *)originalPoints.m_size;
                        do
                        {
                          if ( v104 )
                            qmemcpy(v104, &originalPoints.m_data[v105], 0x20u);
                          ++v105;
                          v104 = (btFace *)((char *)v104 + 32);
                          v169 = (btFace *)((char *)v169 - 1);
                        }
                        while ( v169 );
                      }
                      if ( originalPoints.m_data && originalPoints.m_ownsMemory )
                      {
                        btAlignedFreeInternal(originalPoints.m_data);
                        v76 = _mask__NegFloat_;
                      }
                      originalPoints.m_data = (GrahamVector2 *)v161;
                      originalPoints.m_ownsMemory = 1;
                      originalPoints.m_capacity = v177;
                    }
                  }
                  v106 = &originalPoints.m_data[originalPoints.m_size];
                  if ( v106 )
                    qmemcpy(v106, v252, sizeof(GrahamVector2));
                  ++originalPoints.m_size;
                }
                else
                {
                  v103 = &originalPoints.m_data->mVec128.m128_i32[2];
                  while ( 1 )
                  {
                    v101 = (float)((float)((float)(*(float *)&v212 * v251)
                                         + (float)((float)((float)((float)(v207 * v193) + (float)(v206 * v192))
                                                         - (float)(v190 * v208))
                                                 * v193))
                                 + (float)(*(float *)&v211 * v99))
                         - (float)(v98 * *(float *)&v213);
                    v102 = (float)((float)((float)(*(float *)&v213
                                                 * (float)((float)((float)(v207 * v193) + (float)(v206 * v192))
                                                         - (float)(v190 * v208)))
                                         + (float)(*(float *)&v211 * v251))
                                 + (float)(v98 * v193))
                         - (float)(*(float *)&v212 * v99);
                    if ( (float)((float)((float)(COERCE_FLOAT(*v103 ^ v76) * COERCE_FLOAT(*v103 ^ v76))
                                       + (float)((float)(v101 - *((float *)v103 - 1))
                                               * (float)(v101 - *((float *)v103 - 1))))
                               + (float)((float)(v102 - *((float *)v103 - 2)) * (float)(v102 - *((float *)v103 - 2)))) < 0.001 )
                      break;
                    ++v100;
                    v103 += 8;
                    if ( v100 >= originalPoints.m_size )
                      goto LABEL_165;
                  }
                }
                if ( ++v181 >= v77->m_indices.m_size )
                  break;
                v93 = v191;
              }
            }
            ++v186;
          }
          while ( v186 < v196 );
          v107 = v217[*(_DWORD *)v198].m_plane;
          __that.m_indices.m_ownsMemory = 1;
          memset(&__that.m_indices.m_size, 0, 12);
          __that.m_plane[0] = *v107++;
          __that.m_plane[1] = *v107++;
          __that.m_plane[2] = *v107;
          __that.m_plane[3] = v107[1];
          hull.m_ownsMemory = 1;
          memset(&hull.m_size, 0, 12);
          GrahamScanConvexHull2D(&originalPoints, &hull);
          if ( hull.m_size > 0 )
          {
            v108 = __that.m_indices.m_size;
            p_m_orgIndex = &hull.m_data->m_orgIndex;
            p_that = (btFace *)hull.m_size;
            do
            {
              if ( v108 == __that.m_indices.m_capacity )
              {
                v109 = v108 ? 2 * v108 : 1;
                v170 = (btFace *)v109;
                if ( __that.m_indices.m_capacity < v109 )
                {
                  if ( v109 )
                    v110 = (int *)btAlignedAllocInternal(4 * v109);
                  else
                    v110 = 0;
                  if ( v108 > 0 )
                  {
                    v111 = v110;
                    v112 = (char *)((char *)__that.m_indices.m_data - (char *)v110);
                    v113 = v108;
                    do
                    {
                      if ( v111 )
                      {
                        *v111 = *(int *)((char *)v111 + (_DWORD)v112);
                        v109 = (int)v170;
                      }
                      ++v111;
                      --v113;
                    }
                    while ( v113 );
                  }
                  if ( __that.m_indices.m_data && __that.m_indices.m_ownsMemory )
                    btAlignedFreeInternal(__that.m_indices.m_data);
                  __that.m_indices.m_ownsMemory = 1;
                  __that.m_indices.m_data = v110;
                  __that.m_indices.m_capacity = v109;
                }
              }
              v114 = &__that.m_indices.m_data[v108];
              if ( v114 )
                *v114 = *p_m_orgIndex;
              p_m_orgIndex += 8;
              ++v108;
              p_that = (btFace *)((char *)p_that - 1);
            }
            while ( p_that );
            __that.m_indices.m_size = v108;
          }
          v115 = v189->m_polyhedron;
          v116 = (btAlignedObjectArray<GrahamVector2> *)v115->m_faces.m_capacity;
          v117 = v115->m_faces.m_size;
          v118 = &v115->m_faces;
          if ( (btAlignedObjectArray<GrahamVector2> *)v117 == v116 )
          {
            v119 = v117 ? 2 * v117 : 1;
            p_that = (btFace *)v119;
            if ( (int)v116 < v119 )
            {
              if ( v119 )
              {
                v120 = (btFace *)btAlignedAllocInternal(36 * v119);
                v116 = v149;
                v163 = v120;
              }
              else
              {
                v163 = 0;
              }
              if ( v118->m_size > 0 )
              {
                v121 = v163;
                v122 = 0;
                v171 = (btFace *)v118->m_size;
                do
                {
                  if ( v121 )
                    btFace::btFace(v121);
                  v122 += 36;
                  ++v121;
                  v171 = (btFace *)((char *)v171 - 1);
                }
                while ( v171 );
              }
              if ( v118->m_size > 0 )
              {
                v123 = 0;
                v172 = (btFace *)v118->m_size;
                do
                {
                  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
                    v116,
                    (int)&v118->m_data[v123++]);
                  v172 = (btFace *)((char *)v172 - 1);
                }
                while ( v172 );
              }
              if ( v118->m_data )
              {
                if ( v118->m_ownsMemory )
                {
                  btAlignedFreeInternal(v118->m_data);
                  v116 = v150;
                }
                v118->m_data = 0;
              }
              v118->m_data = v163;
              v124 = p_that;
              v118->m_ownsMemory = 1;
              v118->m_capacity = (int)v124;
            }
          }
          v125 = &v118->m_data[v118->m_size];
          if ( v125 )
            btFace::btFace(v125);
          ++v118->m_size;
          btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v116, (int)&hull);
          btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v126, (int)&__that);
          btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v127, (int)&originalPoints);
        }
        btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
          (btAlignedObjectArray<GrahamVector2> *)v63,
          (int)&v195);
        if ( !v205.m_size )
          break;
        v56 = v205.m_size;
        v55 = v205.m_data;
      }
    }
  }
  btConvexPolyhedron::initialize((btConvexPolyhedron *)v18, (int)v189->m_polyhedron);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v135, (int)&v205);
  btAlignedObjectArray<btFace>::~btAlignedObjectArray<btFace>(v136, (int)v215);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v137, (int)v240);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v138, (int)&v235);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v139, (int)v232);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v140, (int)&coords);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v141, (int)v200);
  return 1;
}
