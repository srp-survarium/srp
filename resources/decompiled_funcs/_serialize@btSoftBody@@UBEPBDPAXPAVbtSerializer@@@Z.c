const char *__thiscall btSoftBody::serialize(btSoftBody *this, int *dataBuffer, btSerializer *serializer)
{
  btSerializer *v3; // ebx
  int *v4; // edi
  int m_size; // ecx
  void *v7; // eax
  btSerializer_vtbl *v8; // edx
  btChunk *v9; // eax
  SoftBodyLinkData *m_oldPtr; // ecx
  int v11; // eax
  SoftBodyMaterialData *v12; // eax
  btChunk *v13; // eax
  float *v14; // ecx
  int v15; // eax
  void *v16; // eax
  btSerializer_vtbl *v17; // edx
  int v18; // eax
  int v19; // edi
  char *v20; // eax
  btSoftBody::Node *m_data; // ecx
  unsigned int v22; // eax
  btSoftBody::Node *v23; // edx
  btSoftBody::Node *v24; // edx
  void *v25; // eax
  btSoftBody::Node *v26; // eax
  int v27; // ecx
  double v28; // st7
  float *v29; // eax
  btSoftBody::Node *v30; // edx
  btSoftBody::Node *v31; // eax
  double v32; // st7
  float *v33; // eax
  float *v34; // eax
  int v35; // eax
  void *v36; // eax
  btSerializer_vtbl *v37; // edx
  btChunk *v38; // eax
  SoftBodyLinkData *v39; // ecx
  btSoftBody::Material *v40; // edx
  btSoftBody::Link *v41; // eax
  SoftBodyMaterialData *v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  int v46; // eax
  double v47; // st7
  bool v48; // zf
  int v49; // eax
  void *v50; // eax
  btSerializer_vtbl *v51; // edx
  int v52; // eax
  int v53; // edi
  SoftBodyLinkData *v54; // eax
  char *v55; // eax
  void *v56; // eax
  SoftBodyLinkData *v57; // ecx
  btSoftBody::Face *v58; // eax
  double v59; // st7
  float *v60; // eax
  int v61; // eax
  int v62; // eax
  int v63; // eax
  int v64; // eax
  int v65; // eax
  int v66; // eax
  int v67; // eax
  void *v68; // eax
  btSerializer_vtbl *v69; // edx
  int v70; // eax
  int v71; // ecx
  char *p_m_kVST; // edx
  int v73; // ecx
  btChunk *p_m_number; // edx
  btSoftBody::Tetra *v75; // eax
  double v76; // st7
  float *v77; // eax
  double v78; // st7
  int v79; // eax
  int v80; // eax
  int v81; // eax
  SoftBodyLinkData *v82; // edx
  bool v83; // cc
  btSoftBody::Material *v84; // edx
  int v85; // ecx
  btSoftBody::Tetra *v86; // eax
  void *v87; // eax
  double v88; // st7
  int v89; // eax
  void *v90; // eax
  btSerializer_vtbl *v91; // edx
  int v92; // eax
  int v93; // edi
  int v94; // ecx
  char *v95; // ecx
  char *v96; // edx
  int v97; // eax
  int v98; // ecx
  double v99; // st7
  int v100; // ecx
  float *v101; // eax
  btSoftBody::Anchor *v102; // edx
  int v103; // eax
  int v104; // eax
  btSoftBody::Anchor *v105; // edx
  void *v106; // eax
  btSoftBody::Material *v107; // ecx
  int *v108; // eax
  int v109; // edx
  double v110; // st7
  btSoftBody::Material *v111; // ecx
  int v112; // eax
  void *v113; // eax
  int m_kAST_low; // eax
  btChunk *v115; // eax
  float *v116; // edx
  int v117; // eax
  btVector3 *v118; // ecx
  double v119; // st7
  float *m128_f32; // ecx
  double v121; // st7
  double m_volume; // st7
  float *v123; // eax
  int v124; // edx
  double v125; // st7
  double v126; // st7
  float *v127; // eax
  int v128; // edx
  double v129; // st7
  double v130; // st7
  int v131; // eax
  void *v132; // eax
  int m_kVST_low; // ecx
  btChunk *v134; // eax
  float *v135; // edx
  int v136; // ecx
  double v137; // st7
  int v138; // eax
  double v139; // st7
  btHashMap<btInternalVertexPair,btInternalEdge> *v140; // ecx
  int v141; // eax
  void *v142; // eax
  btChunk *v143; // eax
  char *v144; // edi
  int v145; // ebx
  double m_adamping; // st7
  float *v147; // eax
  double v148; // st7
  btVector3 *p_m_com; // eax
  btVector3 *m_dimpulses; // eax
  float *v151; // eax
  double v152; // st7
  btTransform *p_m_framexform; // eax
  float *v154; // ecx
  int v155; // edx
  double v156; // st7
  int v157; // edx
  int v158; // edx
  int *v159; // ecx
  float *v160; // eax
  int v161; // edx
  int *v162; // ecx
  float *v163; // eax
  float *v164; // eax
  double v165; // st7
  float *v166; // eax
  double v167; // st7
  float *v168; // eax
  double v169; // st7
  void *v170; // eax
  btSerializer_vtbl *v171; // edx
  int v172; // eax
  float *v173; // edx
  int v174; // eax
  btVector3 *v175; // ecx
  double v176; // st7
  float *v177; // ecx
  double v178; // st7
  void *v179; // eax
  btChunk *v180; // eax
  float *v181; // edx
  int v182; // ecx
  double v183; // st7
  int v184; // edx
  double v185; // st7
  void *v186; // eax
  btSerializer_vtbl *v187; // edx
  int v188; // eax
  int v189; // ecx
  int Index; // eax
  int *v191; // eax
  int v192; // edx
  int v193; // ecx
  int v194; // eax
  int v195; // eax
  btSerializer_vtbl *v196; // edx
  int v197; // eax
  int v198; // edi
  btSoftBody::Joint *v199; // ecx
  float *v200; // eax
  double v201; // st7
  float *v202; // eax
  double v203; // st7
  _DWORD *v204; // eax
  int v205; // ecx
  btSoftBody::Material *mat; // [esp+178h] [ebp-78h]
  btSoftBody::Material *mata; // [esp+178h] [ebp-78h]
  int matb; // [esp+178h] [ebp-78h]
  btSoftBody::Material *matc; // [esp+178h] [ebp-78h]
  btSoftBody::Material *matd; // [esp+178h] [ebp-78h]
  int mate; // [esp+178h] [ebp-78h]
  int matf; // [esp+178h] [ebp-78h]
  int matg; // [esp+178h] [ebp-78h]
  btHashPtr i; // [esp+17Ch] [ebp-74h] BYREF
  SoftBodyLinkData *memPtr; // [esp+184h] [ebp-6Ch] BYREF
  int j; // [esp+188h] [ebp-68h]
  btChunk *chunk; // [esp+18Ch] [ebp-64h]
  int numElem; // [esp+190h] [ebp-60h]
  btChunk *v220; // [esp+194h] [ebp-5Ch]
  btHashPtr key; // [esp+198h] [ebp-58h] BYREF
  btHashMap<btHashPtr,int> m_nodeIndexMap; // [esp+1A0h] [ebp-50h] BYREF

  v3 = serializer;
  v4 = dataBuffer;
  btCollisionObject::serialize(this, dataBuffer, serializer);
  m_size = this->m_materials.m_size;
  m_nodeIndexMap.m_hashTable.m_ownsMemory = 1;
  memset(&m_nodeIndexMap.m_hashTable.m_size, 0, 12);
  m_nodeIndexMap.m_next.m_ownsMemory = 1;
  memset(&m_nodeIndexMap.m_next.m_size, 0, 12);
  m_nodeIndexMap.m_valueArray.m_ownsMemory = 1;
  memset(&m_nodeIndexMap.m_valueArray.m_size, 0, 12);
  m_nodeIndexMap.m_keyArray.m_ownsMemory = 1;
  memset(&m_nodeIndexMap.m_keyArray.m_size, 0, 12);
  dataBuffer[71] = m_size;
  if ( m_size )
    v7 = serializer->getUniquePointer(serializer, &this->m_materials);
  else
    v7 = 0;
  dataBuffer[63] = (int)v7;
  if ( v7 )
  {
    v8 = serializer->__vftable;
    j = dataBuffer[71];
    v9 = v8->allocate(serializer, 4u, j);
    m_oldPtr = (SoftBodyLinkData *)v9->m_oldPtr;
    chunk = v9;
    memPtr = m_oldPtr;
    i.m_hashValues[0] = 0;
    if ( j > 0 )
    {
      v11 = i.m_hashValues[0];
      do
      {
        mat = this->m_materials.m_data[v11];
        if ( mat )
          v12 = (SoftBodyMaterialData *)serializer->getUniquePointer(serializer, mat);
        else
          v12 = 0;
        memPtr->m_material = v12;
        if ( !serializer->findPointer(serializer, mat) )
        {
          v13 = serializer->allocate(serializer, 16, 1);
          v14 = (float *)v13->m_oldPtr;
          v14[3] = *(float *)&mat->m_flags;
          v14[1] = mat->m_kAST;
          *v14 = mat->m_kLST;
          v14[2] = mat->m_kVST;
          serializer->finalizeChunk(serializer, v13, "SoftBodyMaterialData", 1414349395, mat);
        }
        memPtr = (SoftBodyLinkData *)((char *)memPtr + 4);
        v11 = ++i.m_hashValues[0];
      }
      while ( i.m_hashValues[0] < j );
    }
    serializer->finalizeChunk(serializer, chunk, "SoftBodyMaterialData", 1497453121, &this->m_materials);
  }
  v15 = this->m_nodes.m_size;
  dataBuffer[72] = v15;
  if ( v15 )
    v16 = serializer->getUniquePointer(serializer, &this->m_nodes);
  else
    v16 = 0;
  dataBuffer[64] = (int)v16;
  if ( v16 )
  {
    v17 = serializer->__vftable;
    i.m_hashValues[0] = dataBuffer[72];
    v18 = (int)v17->allocate(serializer, 100u, i.m_hashValues[0]);
    v19 = *(_DWORD *)(v18 + 8);
    numElem = v18;
    v20 = 0;
    for ( memPtr = 0; (int)memPtr < i.m_hashValues[0]; memPtr = (SoftBodyLinkData *)((char *)memPtr + 1) )
    {
      m_data = this->m_nodes.m_data;
      v22 = (unsigned int)v20;
      *(float *)(v19 + 52) = m_data[v22].m_f.mVec128.m128_f32[0];
      *(float *)(v19 + 56) = m_data[v22].m_f.mVec128.m128_f32[1];
      *(float *)(v19 + 60) = m_data[v22].m_f.mVec128.m128_f32[2];
      *(float *)(v19 + 64) = m_data[v22].m_f.mVec128.m128_f32[3];
      v23 = this->m_nodes.m_data;
      j = v22 * 112;
      *(float *)(v19 + 88) = v23[v22].m_area;
      *(_DWORD *)(v19 + 92) = (int)(*((_DWORD *)&this->m_nodes.m_data[v22] + 27) << 31) >> 31;
      *(float *)(v19 + 84) = this->m_nodes.m_data[v22].m_im;
      v24 = this->m_nodes.m_data;
      if ( v24[v22].m_material )
        v25 = serializer->getUniquePointer(serializer, *(btSoftBody::Material **)((char *)&v24->m_material + j));
      else
        v25 = 0;
      *(_DWORD *)v19 = v25;
      v26 = this->m_nodes.m_data;
      v27 = j;
      v28 = *(float *)((char *)v26->m_n.mVec128.m128_f32 + j);
      v29 = (float *)((char *)v26->m_n.mVec128.m128_f32 + j);
      *(float *)(v19 + 68) = v28;
      *(float *)(v19 + 72) = v29[1];
      *(float *)(v19 + 76) = v29[2];
      *(float *)(v19 + 80) = v29[3];
      v30 = this->m_nodes.m_data;
      *(float *)(v19 + 4) = *(float *)((char *)v30->m_x.mVec128.m128_f32 + v27);
      *(float *)(v19 + 8) = *(float *)((char *)&v30->m_x.mVec128.m128_f32[1] + v27);
      *(float *)(v19 + 12) = *(float *)((char *)&v30->m_x.mVec128.m128_f32[2] + v27);
      *(float *)(v19 + 16) = *(float *)((char *)&v30->m_x.mVec128.m128_f32[3] + v27);
      v31 = this->m_nodes.m_data;
      v32 = *(float *)((char *)v31->m_q.mVec128.m128_f32 + v27);
      v33 = (float *)((char *)v31->m_q.mVec128.m128_f32 + v27);
      *(float *)(v19 + 20) = v32;
      *(float *)(v19 + 24) = v33[1];
      *(float *)(v19 + 28) = v33[2];
      *(float *)(v19 + 32) = v33[3];
      v34 = (float *)((char *)this->m_nodes.m_data->m_v.mVec128.m128_f32 + v27);
      *(float *)(v19 + 36) = *v34;
      *(float *)(v19 + 40) = v34[1];
      *(float *)(v19 + 44) = v34[2];
      *(float *)(v19 + 48) = v34[3];
      key.m_hashValues[0] = (int)this->m_nodes.m_data + v27;
      btHashMap<btHashPtr,btCollisionShape *>::insert(
        (btHashMap<btHashPtr,int> *)&memPtr,
        &m_nodeIndexMap,
        &key,
        (int *)&memPtr);
      v20 = (char *)&memPtr->m_material + 1;
      v19 += 100;
    }
    serializer->finalizeChunk(serializer, (btChunk *)numElem, "SoftBodyNodeData", 1145979475, &this->m_nodes);
    v4 = dataBuffer;
  }
  v35 = this->m_links.m_size;
  v4[73] = v35;
  if ( v35 )
    v36 = serializer->getUniquePointer(serializer, this->m_links.m_data);
  else
    v36 = 0;
  v4[65] = (int)v36;
  if ( v36 )
  {
    v37 = serializer->__vftable;
    j = v4[73];
    v38 = v37->allocate(serializer, 20u, j);
    v39 = (SoftBodyLinkData *)v38->m_oldPtr;
    chunk = v38;
    memPtr = v39;
    if ( j > 0 )
    {
      v40 = 0;
      mata = 0;
      do
      {
        v39->m_bbending = (int)(*(_DWORD *)((char *)this->m_links.m_data + (unsigned int)v40 + 20) << 31) >> 31;
        v41 = this->m_links.m_data;
        if ( *(_DWORD *)((char *)&v40->m_kLST + (_DWORD)v41) )
        {
          v42 = (SoftBodyMaterialData *)serializer->getUniquePointer(
                                          serializer,
                                          *(btSoftBody::Material **)((char *)&v41->m_material + (_DWORD)mata));
          v39 = memPtr;
          v40 = mata;
        }
        else
        {
          v42 = 0;
        }
        v39->m_material = v42;
        v43 = *(int *)((char *)this->m_links.m_data->m_n + (unsigned int)v40);
        if ( v43 )
        {
          numElem = v43 - (unsigned int)this->m_nodes.m_data;
          v44 = numElem / 112;
          v40 = mata;
        }
        else
        {
          v44 = -1;
        }
        v39->m_nodeIndices[0] = v44;
        v45 = *(int *)((char *)&this->m_links.m_data->m_n[1] + (unsigned int)v40);
        if ( v45 )
        {
          numElem = v45 - (unsigned int)this->m_nodes.m_data;
          v46 = numElem / 112;
          v40 = mata;
        }
        else
        {
          v46 = -1;
        }
        v39->m_nodeIndices[1] = v46;
        v47 = *(float *)((char *)&this->m_links.m_data->m_n[2] + (unsigned int)v40);
        v40 = (btSoftBody::Material *)((char *)v40 + 64);
        v39->m_restLength = v47;
        ++v39;
        v48 = j-- == 1;
        mata = v40;
        memPtr = v39;
      }
      while ( !v48 );
    }
    serializer->finalizeChunk(serializer, chunk, "SoftBodyLinkData", 1497453121, this->m_links.m_data);
  }
  v49 = this->m_faces.m_size;
  v4[74] = v49;
  if ( v49 )
    v50 = serializer->getUniquePointer(serializer, this->m_faces.m_data);
  else
    v50 = 0;
  v4[66] = (int)v50;
  if ( v50 )
  {
    v51 = serializer->__vftable;
    j = dataBuffer[74];
    v52 = (int)v51->allocate(serializer, 36u, j);
    v53 = *(_DWORD *)(v52 + 8);
    numElem = v52;
    if ( j > 0 )
    {
      v54 = 0;
      memPtr = 0;
      matb = 12;
      do
      {
        v55 = (char *)this->m_faces.m_data + (unsigned int)v54;
        if ( *((_DWORD *)v55 + 1) )
          v56 = serializer->getUniquePointer(serializer, *((_DWORD *)v55 + 1));
        else
          v56 = 0;
        v57 = memPtr;
        *(_DWORD *)(v53 + 16) = v56;
        v58 = this->m_faces.m_data;
        v59 = *(float *)((char *)v58->m_normal.mVec128.m128_f32 + (_DWORD)v57);
        v60 = (float *)((char *)v58->m_normal.mVec128.m128_f32 + (_DWORD)v57);
        *(float *)v53 = v59;
        *(float *)(v53 + 4) = v60[1];
        *(float *)(v53 + 8) = v60[2];
        *(float *)(v53 + 12) = v60[3];
        v61 = *(_DWORD *)((char *)this->m_faces.m_data + matb - 4);
        if ( v61 )
          v62 = (signed int)(v61 - (unsigned int)this->m_nodes.m_data) / 112;
        else
          v62 = -1;
        *(_DWORD *)(v53 + 20) = v62;
        v63 = *(int *)((char *)&this->m_faces.m_data->m_tag + matb);
        if ( v63 )
          v64 = (signed int)(v63 - (unsigned int)this->m_nodes.m_data) / 112;
        else
          v64 = -1;
        *(_DWORD *)(v53 + 24) = v64;
        v65 = *(int *)((char *)&this->m_faces.m_data->m_material + matb);
        if ( v65 )
          v66 = (signed int)(v65 - (unsigned int)this->m_nodes.m_data) / 112;
        else
          v66 = -1;
        matb += 64;
        *(_DWORD *)(v53 + 28) = v66;
        v54 = (SoftBodyLinkData *)((char *)memPtr + 64);
        *(float *)(v53 + 32) = *(float *)((char *)&memPtr[2].m_nodeIndices[1] + (unsigned int)this->m_faces.m_data);
        v53 += 36;
        v48 = j-- == 1;
        memPtr = v54;
      }
      while ( !v48 );
    }
    serializer->finalizeChunk(serializer, (btChunk *)numElem, "SoftBodyFaceData", 1497453121, this->m_faces.m_data);
    v4 = dataBuffer;
  }
  v67 = this->m_tetras.m_size;
  v4[75] = v67;
  if ( v67 )
    v68 = serializer->getUniquePointer(serializer, this->m_tetras.m_data);
  else
    v68 = 0;
  v4[67] = (int)v68;
  if ( v68 )
  {
    v69 = serializer->__vftable;
    memPtr = (SoftBodyLinkData *)v4[75];
    v70 = (int)v69->allocate(serializer, 100u, (int)memPtr);
    v71 = *(_DWORD *)(v70 + 8);
    key.m_hashValues[0] = v70;
    if ( (int)memPtr > 0 )
    {
      p_m_kVST = 0;
      v73 = v71 + 8;
      matc = 0;
      j = v73;
      numElem = (int)memPtr;
      do
      {
        p_m_number = (btChunk *)(p_m_kVST + 32);
        i.m_hashValues[0] = 0;
        chunk = p_m_number;
        memPtr = (SoftBodyLinkData *)(v73 + 60);
        do
        {
          v75 = this->m_tetras.m_data;
          v76 = *(float *)((char *)&p_m_number->m_chunkCode + (_DWORD)v75);
          v77 = (float *)((char *)v75 + (_DWORD)p_m_number);
          *(float *)(v73 - 8) = v76;
          *(float *)(v73 - 4) = v77[1];
          *(float *)v73 = v77[2];
          v78 = v77[3];
          v79 = i.m_hashValues[0];
          *(float *)(v73 + 4) = v78;
          v80 = *(int *)((char *)this->m_tetras.m_data->m_n + v79);
          if ( v80 )
          {
            v220 = (btChunk *)(v80 - (unsigned int)this->m_nodes.m_data);
            v81 = (int)v220 / 112;
          }
          else
          {
            v81 = -1;
          }
          v82 = memPtr;
          memPtr = (SoftBodyLinkData *)((char *)memPtr + 4);
          v82->m_material = (SoftBodyMaterialData *)v81;
          p_m_number = (btChunk *)&chunk->m_number;
          v73 += 16;
          v83 = i.m_hashValues[0] + 116 < 464;
          chunk = (btChunk *)((char *)chunk + 16);
          i.m_hashValues[0] += 116;
        }
        while ( v83 );
        v84 = matc;
        v85 = j;
        *(float *)(j + 80) = *(float *)((char *)&matc[4].m_flags + (unsigned int)this->m_tetras.m_data);
        *(float *)(v85 + 84) = *(float *)((char *)&matc[5].m_tag + (unsigned int)this->m_tetras.m_data);
        v86 = this->m_tetras.m_data;
        if ( *(btSoftBody::Material **)((char *)&v86->m_material + (_DWORD)matc) )
        {
          v87 = serializer->getUniquePointer(
                  serializer,
                  *(btSoftBody::Material **)((char *)&v86->m_material + (_DWORD)matc));
          v84 = matc;
          v85 = j;
        }
        else
        {
          v87 = 0;
        }
        *(_DWORD *)(v85 + 56) = v87;
        v88 = *(float *)((char *)&v84[1].m_kLST + (unsigned int)this->m_tetras.m_data);
        p_m_kVST = (char *)&v84[5].m_kVST;
        *(float *)(v85 + 76) = v88;
        v73 = v85 + 100;
        v48 = numElem-- == 1;
        matc = (btSoftBody::Material *)p_m_kVST;
        j = v73;
      }
      while ( !v48 );
    }
    serializer->finalizeChunk(
      serializer,
      (btChunk *)key.m_hashValues[0],
      "SoftBodyTetraData",
      1497453121,
      this->m_tetras.m_data);
  }
  v89 = this->m_anchors.m_size;
  v4[76] = v89;
  if ( v89 )
    v90 = serializer->getUniquePointer(serializer, this->m_anchors.m_data);
  else
    v90 = 0;
  v4[68] = (int)v90;
  if ( v90 )
  {
    v91 = serializer->__vftable;
    numElem = dataBuffer[76];
    v92 = (int)v91->allocate(serializer, 92u, numElem);
    v93 = *(_DWORD *)(v92 + 8);
    v220 = (btChunk *)v92;
    if ( numElem > 0 )
    {
      v94 = 0;
      j = 0;
      chunk = (btChunk *)numElem;
      do
      {
        v95 = (char *)&this->m_anchors.m_data->m_c0 + v94;
        v96 = v95 + 12;
        v97 = v93 + 4;
        key.m_hashValues[0] = (int)&v95[-v93];
        numElem = 3;
        do
        {
          v98 = key.m_hashValues[0];
          *(float *)(v97 - 4) = *((float *)v96 - 3);
          v97 += 16;
          v99 = *(float *)(v98 + v97 - 16);
          v96 += 16;
          v48 = numElem-- == 1;
          *(float *)(v97 - 16) = v99;
          *(float *)(v97 - 12) = *((float *)v96 - 5);
          *(float *)(v97 - 8) = *((float *)v96 - 4);
        }
        while ( !v48 );
        v100 = j;
        v101 = (float *)((char *)this->m_anchors.m_data->m_c1.mVec128.m128_f32 + j);
        *(float *)(v93 + 48) = *v101;
        *(float *)(v93 + 52) = v101[1];
        *(float *)(v93 + 56) = v101[2];
        *(float *)(v93 + 60) = v101[3];
        *(float *)(v93 + 88) = *(float *)((char *)&this->m_anchors.m_data->m_c2 + v100);
        v102 = this->m_anchors.m_data;
        *(float *)(v93 + 64) = *(float *)((char *)v102->m_local.mVec128.m128_f32 + v100);
        *(float *)(v93 + 68) = *(float *)((char *)&v102->m_local.mVec128.m128_f32[1] + v100);
        *(float *)(v93 + 72) = *(float *)((char *)&v102->m_local.mVec128.m128_f32[2] + v100);
        *(float *)(v93 + 76) = *(float *)((char *)&v102->m_local.mVec128.m128_f32[3] + v100);
        v103 = *(int *)((char *)&this->m_anchors.m_data->m_node + v100);
        if ( v103 )
        {
          key.m_hashValues[0] = v103 - (unsigned int)this->m_nodes.m_data;
          v104 = key.m_hashValues[0] / 112;
        }
        else
        {
          v104 = -1;
        }
        *(_DWORD *)(v93 + 84) = v104;
        v105 = this->m_anchors.m_data;
        if ( *(btRigidBody **)((char *)&v105->m_body + v100) )
        {
          v106 = serializer->getUniquePointer(serializer, *(btRigidBody **)((char *)&v105->m_body + v100));
          v100 = j;
        }
        else
        {
          v106 = 0;
        }
        *(_DWORD *)(v93 + 80) = v106;
        v94 = v100 + 128;
        v93 += 92;
        v48 = chunk == (btChunk *)1;
        chunk = (btChunk *)((char *)chunk - 1);
        j = v94;
      }
      while ( !v48 );
    }
    serializer->finalizeChunk(serializer, v220, "SoftRigidAnchorData", 1497453121, this->m_anchors.m_data);
    v4 = dataBuffer;
  }
  v4[86] = SLODWORD(this->m_cfg.kDF);
  v4[80] = SLODWORD(this->m_cfg.kVCF);
  v4[84] = SLODWORD(this->m_cfg.kPR);
  v4[79] = this->m_cfg.aeromodel;
  v4[83] = SLODWORD(this->m_cfg.kLF);
  v4[82] = SLODWORD(this->m_cfg.kDG);
  v4[101] = this->m_cfg.piterations;
  v4[102] = this->m_cfg.diterations;
  v4[103] = this->m_cfg.citerations;
  v4[100] = this->m_cfg.viterations;
  v4[98] = SLODWORD(this->m_cfg.maxvolume);
  v4[81] = SLODWORD(this->m_cfg.kDP);
  v4[87] = SLODWORD(this->m_cfg.kMT);
  v4[104] = this->m_cfg.collisions;
  v4[85] = SLODWORD(this->m_cfg.kVC);
  v4[88] = SLODWORD(this->m_cfg.kCHR);
  v4[89] = SLODWORD(this->m_cfg.kKHR);
  v4[90] = SLODWORD(this->m_cfg.kSHR);
  v4[91] = SLODWORD(this->m_cfg.kAHR);
  v4[99] = SLODWORD(this->m_cfg.timescale);
  v4[98] = SLODWORD(this->m_cfg.maxvolume);
  v4[92] = SLODWORD(this->m_cfg.kSRHR_CL);
  v4[93] = SLODWORD(this->m_cfg.kSKHR_CL);
  v4[94] = SLODWORD(this->m_cfg.kSSHR_CL);
  v4[95] = SLODWORD(this->m_cfg.kSR_SPLT_CL);
  v4[96] = SLODWORD(this->m_cfg.kSK_SPLT_CL);
  v4[97] = SLODWORD(this->m_cfg.kSS_SPLT_CL);
  v4[62] = (int)serializer->getUniquePointer(serializer, &this->m_pose);
  v220 = serializer->allocate(serializer, 192, 1);
  matd = (btSoftBody::Material *)v220->m_oldPtr;
  v107 = matd + 5;
  v108 = &this->m_pose.m_aqq.m_el[0].mVec128.m128_i32[1];
  v109 = 3;
  do
  {
    v110 = *((float *)v108 - 1);
    v108 += 4;
    *(float *)&v107[-1].m_flags = v110;
    v107 = (btSoftBody::Material *)((char *)v107 + 16);
    --v109;
    v107[-1].m_kLST = *((float *)v108 - 4);
    v107[-1].m_kAST = *((float *)v108 - 3);
    v107[-1].m_kVST = *((float *)v108 - 2);
  }
  while ( v109 );
  v111 = matd;
  matd[9].m_tag = (void *)this->m_pose.m_bframe;
  matd[8].m_flags = this->m_pose.m_bvolume;
  matd[7].m_kLST = this->m_pose.m_com.mVec128.m128_f32[0];
  matd[7].m_kAST = this->m_pose.m_com.mVec128.m128_f32[1];
  matd[7].m_kVST = this->m_pose.m_com.mVec128.m128_f32[2];
  *(float *)&matd[7].m_flags = this->m_pose.m_com.mVec128.m128_f32[3];
  v112 = this->m_pose.m_pos.m_size;
  LODWORD(matd[8].m_kAST) = v112;
  if ( v112 )
  {
    v113 = serializer->getUniquePointer(serializer, this->m_pose.m_pos.m_data);
    v111 = matd;
  }
  else
  {
    v113 = 0;
  }
  v111[8].m_tag = v113;
  m_kAST_low = LODWORD(v111[8].m_kAST);
  j = m_kAST_low;
  if ( m_kAST_low )
  {
    v115 = serializer->allocate(serializer, 16, m_kAST_low);
    v116 = (float *)v115->m_oldPtr;
    key.m_hashValues[0] = (int)v115;
    if ( j > 0 )
    {
      v117 = 0;
      numElem = j;
      do
      {
        v118 = this->m_pose.m_pos.m_data;
        v119 = v118[v117].mVec128.m128_f32[0];
        m128_f32 = v118[v117].mVec128.m128_f32;
        *v116 = v119;
        ++v117;
        v121 = m128_f32[1];
        v116 += 4;
        v48 = numElem-- == 1;
        *(v116 - 3) = v121;
        *(v116 - 2) = m128_f32[2];
        *(v116 - 1) = m128_f32[3];
      }
      while ( !v48 );
      v115 = (btChunk *)key.m_hashValues[0];
    }
    serializer->finalizeChunk(serializer, v115, "btVector3FloatData", 1497453121, this->m_pose.m_pos.m_data);
    v111 = matd;
  }
  m_volume = this->m_pose.m_volume;
  numElem = (int)&v111->m_kAST;
  v111[9].m_kLST = m_volume;
  v123 = &this->m_pose.m_rot.m_el[0].mVec128.m128_f32[1];
  chunk = (btChunk *)3;
  do
  {
    v124 = numElem;
    *(float *)(numElem - 8) = *(v123 - 1);
    v124 += 16;
    v125 = *v123;
    v123 += 4;
    v48 = chunk == (btChunk *)1;
    chunk = (btChunk *)((char *)chunk - 1);
    *(float *)(v124 - 20) = v125;
    v126 = *(v123 - 3);
    numElem = v124;
    *(float *)(v124 - 16) = v126;
    *(float *)(v124 - 12) = *(v123 - 2);
  }
  while ( !v48 );
  numElem = (int)&v111[2].m_kVST;
  v127 = &this->m_pose.m_scl.m_el[0].mVec128.m128_f32[1];
  chunk = (btChunk *)3;
  do
  {
    v128 = numElem;
    *(float *)(numElem - 4) = *(v127 - 1);
    v128 += 16;
    v129 = *v127;
    v127 += 4;
    v48 = chunk == (btChunk *)1;
    chunk = (btChunk *)((char *)chunk - 1);
    *(float *)(v128 - 16) = v129;
    v130 = *(v127 - 3);
    numElem = v128;
    *(float *)(v128 - 12) = v130;
    *(float *)(v128 - 8) = *(v127 - 2);
  }
  while ( !v48 );
  v131 = this->m_pose.m_wgh.m_size;
  LODWORD(v111[8].m_kVST) = v131;
  if ( v131 )
  {
    v132 = serializer->getUniquePointer(serializer, this->m_pose.m_wgh.m_data);
    v111 = matd;
  }
  else
  {
    v132 = 0;
  }
  LODWORD(v111[8].m_kLST) = v132;
  m_kVST_low = LODWORD(v111[8].m_kVST);
  mate = m_kVST_low;
  if ( m_kVST_low )
  {
    v134 = serializer->allocate(serializer, 4, m_kVST_low);
    v135 = (float *)v134->m_oldPtr;
    v136 = 0;
    key.m_hashValues[0] = (int)v134;
    j = (int)v135;
    if ( mate >= 4 )
    {
      do
      {
        v137 = this->m_pose.m_wgh.m_data[v136];
        v136 += 4;
        *v135 = v137;
        v138 = j;
        v135[1] = this->m_pose.m_wgh.m_data[v136 - 3];
        *(float *)(v138 + 8) = this->m_pose.m_wgh.m_data[v136 - 2];
        *(float *)(v138 + 12) = this->m_pose.m_wgh.m_data[v136 - 1];
        v135 = (float *)(v138 + 16);
        j = v138 + 16;
      }
      while ( v136 < mate - 3 );
    }
    for ( ; v136 < mate; ++v135 )
    {
      v139 = this->m_pose.m_wgh.m_data[v136++];
      *v135 = v139;
    }
    serializer->finalizeChunk(
      serializer,
      (btChunk *)key.m_hashValues[0],
      "float",
      1497453121,
      this->m_pose.m_wgh.m_data);
  }
  serializer->finalizeChunk(serializer, v220, "SoftBodyPoseData", 1497453121, &this->m_pose);
  v141 = this->m_clusters.m_size;
  v4[77] = v141;
  if ( v141 )
    v142 = serializer->getUniquePointer(serializer, *this->m_clusters.m_data);
  else
    v142 = 0;
  v4[69] = (int)v142;
  j = v4[77];
  if ( j )
  {
    v143 = serializer->allocate(serializer, 348, j);
    v144 = (char *)v143->m_oldPtr;
    v220 = v143;
    if ( j > 0 )
    {
      v145 = 0;
      memPtr = (SoftBodyLinkData *)j;
      do
      {
        m_adamping = this->m_clusters.m_data[v145]->m_adamping;
        numElem = 3;
        *((float *)v144 + 80) = m_adamping;
        v147 = (float *)this->m_clusters.m_data[v145];
        v148 = v147[88];
        v147 += 88;
        *((float *)v144 + 64) = v148;
        *((float *)v144 + 65) = v147[1];
        *((float *)v144 + 66) = v147[2];
        *((float *)v144 + 67) = v147[3];
        *((_DWORD *)v144 + 86) = this->m_clusters.m_data[v145]->m_clusterIndex;
        *((_DWORD *)v144 + 85) = this->m_clusters.m_data[v145]->m_collide;
        p_m_com = &this->m_clusters.m_data[v145]->m_com;
        *((float *)v144 + 40) = p_m_com->mVec128.m128_f32[0];
        *((float *)v144 + 41) = p_m_com->mVec128.m128_f32[1];
        *((float *)v144 + 42) = p_m_com->mVec128.m128_f32[2];
        *((float *)v144 + 43) = p_m_com->mVec128.m128_f32[3];
        *((_DWORD *)v144 + 84) = this->m_clusters.m_data[v145]->m_containsAnchor;
        m_dimpulses = this->m_clusters.m_data[v145]->m_dimpulses;
        *((float *)v144 + 52) = m_dimpulses->mVec128.m128_f32[0];
        *((float *)v144 + 53) = m_dimpulses->mVec128.m128_f32[1];
        *((float *)v144 + 54) = m_dimpulses->mVec128.m128_f32[2];
        *((float *)v144 + 55) = m_dimpulses->mVec128.m128_f32[3];
        v151 = (float *)this->m_clusters.m_data[v145];
        v152 = v151[76];
        v151 += 76;
        *((float *)v144 + 56) = v152;
        *((float *)v144 + 57) = v151[1];
        *((float *)v144 + 58) = v151[2];
        *((float *)v144 + 59) = v151[3];
        p_m_framexform = &this->m_clusters.m_data[v145]->m_framexform;
        j = (int)&this->m_clusters.m_data[v145]->m_framexform.m_basis.m_el[0].mVec128.m128_i32[3];
        v154 = (float *)(v144 + 4);
        key.m_hashValues[0] = (char *)p_m_framexform - v144;
        do
        {
          v155 = key.m_hashValues[0];
          *(v154 - 1) = *(float *)(j - 12);
          v154 += 4;
          v156 = *(float *)((char *)v154 + v155 - 16);
          v157 = j;
          *(v154 - 4) = v156;
          v157 += 16;
          v48 = numElem-- == 1;
          *(v154 - 3) = *(float *)(v157 - 20);
          j = v157;
          *(v154 - 2) = *(float *)(v157 - 16);
        }
        while ( !v48 );
        *((float *)v144 + 12) = p_m_framexform->m_origin.mVec128.m128_f32[0];
        *((float *)v144 + 13) = p_m_framexform->m_origin.mVec128.m128_f32[1];
        *((float *)v144 + 14) = p_m_framexform->m_origin.mVec128.m128_f32[2];
        *((float *)v144 + 15) = p_m_framexform->m_origin.mVec128.m128_f32[3];
        *((float *)v144 + 74) = this->m_clusters.m_data[v145]->m_idmass;
        v158 = 3;
        *((float *)v144 + 75) = this->m_clusters.m_data[v145]->m_imass;
        v159 = &this->m_clusters.m_data[v145]->m_invwi.m_el[0].mVec128.m128_i32[2];
        v160 = (float *)(v144 + 116);
        do
        {
          v160 += 4;
          *(v160 - 5) = *((float *)v159 - 2);
          v159 += 4;
          --v158;
          *(v160 - 4) = *((float *)v159 - 5);
          *(v160 - 3) = *((float *)v159 - 4);
          *(v160 - 2) = *((float *)v159 - 3);
        }
        while ( v158 );
        v161 = 3;
        *((float *)v144 + 79) = this->m_clusters.m_data[v145]->m_ldamping;
        v162 = &this->m_clusters.m_data[v145]->m_locii.m_el[0].mVec128.m128_i32[2];
        v163 = (float *)(v144 + 68);
        do
        {
          v163 += 4;
          *(v163 - 5) = *((float *)v162 - 2);
          v162 += 4;
          --v161;
          *(v163 - 4) = *((float *)v162 - 5);
          *(v163 - 3) = *((float *)v162 - 4);
          *(v163 - 2) = *((float *)v162 - 3);
        }
        while ( v161 );
        v164 = (float *)this->m_clusters.m_data[v145];
        v165 = v164[84];
        v164 += 84;
        *((float *)v144 + 60) = v165;
        *((float *)v144 + 61) = v164[1];
        *((float *)v144 + 62) = v164[2];
        *((float *)v144 + 63) = v164[3];
        *((float *)v144 + 81) = this->m_clusters.m_data[v145]->m_matching;
        *((float *)v144 + 82) = this->m_clusters.m_data[v145]->m_maxSelfCollisionImpulse;
        *((float *)v144 + 78) = this->m_clusters.m_data[v145]->m_ndamping;
        *((float *)v144 + 79) = this->m_clusters.m_data[v145]->m_ldamping;
        *((float *)v144 + 80) = this->m_clusters.m_data[v145]->m_adamping;
        *((float *)v144 + 83) = this->m_clusters.m_data[v145]->m_selfCollisionImpulseFactor;
        *((_DWORD *)v144 + 71) = this->m_clusters.m_data[v145]->m_framerefs.m_size;
        *((_DWORD *)v144 + 73) = this->m_clusters.m_data[v145]->m_masses.m_size;
        *((_DWORD *)v144 + 72) = this->m_clusters.m_data[v145]->m_nodes.m_size;
        *((_DWORD *)v144 + 76) = this->m_clusters.m_data[v145]->m_nvimpulses;
        v166 = (float *)this->m_clusters.m_data[v145];
        v167 = v166[64];
        v166 += 64;
        *((float *)v144 + 44) = v167;
        *((float *)v144 + 45) = v166[1];
        *((float *)v144 + 46) = v166[2];
        *((float *)v144 + 47) = v166[3];
        v168 = (float *)this->m_clusters.m_data[v145];
        v169 = v168[68];
        v168 += 68;
        *((float *)v144 + 48) = v169;
        *((float *)v144 + 49) = v168[1];
        *((float *)v144 + 50) = v168[2];
        *((float *)v144 + 51) = v168[3];
        v48 = *((_DWORD *)v144 + 71) == 0;
        *((_DWORD *)v144 + 77) = this->m_clusters.m_data[v145]->m_ndimpulses;
        if ( v48 )
          v170 = 0;
        else
          v170 = serializer->getUniquePointer(serializer, this->m_clusters.m_data[v145]->m_framerefs.m_data);
        *((_DWORD *)v144 + 68) = v170;
        if ( v170 )
        {
          v171 = serializer->__vftable;
          numElem = *((_DWORD *)v144 + 71);
          v172 = (int)v171->allocate(serializer, 16u, numElem);
          v173 = *(float **)(v172 + 8);
          key.m_hashValues[0] = v172;
          if ( numElem > 0 )
          {
            v174 = 0;
            do
            {
              v175 = this->m_clusters.m_data[v145]->m_framerefs.m_data;
              v176 = v175[v174].mVec128.m128_f32[0];
              v177 = v175[v174].mVec128.m128_f32;
              *v173 = v176;
              ++v174;
              v178 = v177[1];
              v173 += 4;
              v48 = numElem-- == 1;
              *(v173 - 3) = v178;
              *(v173 - 2) = v177[2];
              *(v173 - 1) = v177[3];
            }
            while ( !v48 );
          }
          serializer->finalizeChunk(
            serializer,
            (btChunk *)key.m_hashValues[0],
            "btVector3FloatData",
            1497453121,
            this->m_clusters.m_data[v145]->m_framerefs.m_data);
        }
        if ( *((_DWORD *)v144 + 73) )
          v179 = serializer->getUniquePointer(serializer, this->m_clusters.m_data[v145]->m_masses.m_data);
        else
          v179 = 0;
        *((_DWORD *)v144 + 70) = v179;
        if ( v179 )
        {
          matf = *((_DWORD *)v144 + 73);
          v180 = serializer->allocate(serializer, 4, matf);
          v181 = (float *)v180->m_oldPtr;
          v182 = 0;
          key.m_hashValues[0] = (int)v180;
          j = (int)v181;
          if ( matf >= 4 )
          {
            do
            {
              v183 = this->m_clusters.m_data[v145]->m_masses.m_data[v182];
              v182 += 4;
              *v181 = v183;
              v181[1] = this->m_clusters.m_data[v145]->m_masses.m_data[v182 - 3];
              *(float *)(j + 8) = this->m_clusters.m_data[v145]->m_masses.m_data[v182 - 2];
              v184 = j;
              *(float *)(j + 12) = this->m_clusters.m_data[v145]->m_masses.m_data[v182 - 1];
              v181 = (float *)(v184 + 16);
              j = (int)v181;
            }
            while ( v182 < matf - 3 );
          }
          for ( ; v182 < matf; ++v181 )
          {
            v185 = this->m_clusters.m_data[v145]->m_masses.m_data[v182++];
            *v181 = v185;
          }
          serializer->finalizeChunk(
            serializer,
            (btChunk *)key.m_hashValues[0],
            "float",
            1497453121,
            this->m_clusters.m_data[v145]->m_masses.m_data);
        }
        if ( *((_DWORD *)v144 + 72) )
          v186 = serializer->getUniquePointer(serializer, &this->m_clusters.m_data[v145]->m_nodes);
        else
          v186 = 0;
        *((_DWORD *)v144 + 69) = v186;
        if ( v186 )
        {
          v187 = serializer->__vftable;
          chunk = (btChunk *)*((_DWORD *)v144 + 73);
          v188 = (int)v187->allocate(serializer, 4u, (int)chunk);
          v189 = *(_DWORD *)(v188 + 8);
          key.m_hashValues[0] = v188;
          numElem = v189;
          j = 0;
          if ( (int)chunk > 0 )
          {
            do
            {
              i.m_hashValues[0] = (int)this->m_clusters.m_data[v145]->m_nodes.m_data[j];
              Index = btHashMap<btHashPtr,int>::findIndex(&m_nodeIndexMap, &i);
              if ( Index == -1 )
                v191 = 0;
              else
                v191 = &m_nodeIndexMap.m_valueArray.m_data[Index];
              v192 = *v191;
              v193 = numElem;
              v194 = j + 1;
              *(_DWORD *)numElem = v192;
              j = v194;
              numElem = v193 + 4;
            }
            while ( v194 < (int)chunk );
          }
          serializer->finalizeChunk(
            serializer,
            (btChunk *)key.m_hashValues[0],
            "int",
            1497453121,
            &this->m_clusters.m_data[v145]->m_nodes);
        }
        ++v145;
        v144 += 348;
        memPtr = (SoftBodyLinkData *)((char *)memPtr - 1);
      }
      while ( memPtr );
      v143 = v220;
      v3 = serializer;
    }
    v3->finalizeChunk(v3, v143, "SoftBodyClusterData", 1497453121, *(void **)this->m_clusters.m_data);
    v4 = dataBuffer;
  }
  v4[78] = this->m_joints.m_size;
  if ( this->m_joints.m_size )
    v195 = (int)v3->getUniquePointer(v3, this->m_joints.m_data);
  else
    v195 = 0;
  v4[70] = v195;
  if ( v195 )
  {
    v196 = v3->__vftable;
    numElem = this->m_joints.m_size;
    v197 = (int)v196->allocate(v3, 104u, numElem);
    v198 = *(_DWORD *)(v197 + 8);
    key.m_hashValues[0] = v197;
    for ( matg = 0; matg < numElem; ++matg )
    {
      v199 = this->m_joints.m_data[matg];
      *(_DWORD *)(v198 + 96) = v199->Type(v199);
      v200 = (float *)this->m_joints.m_data[matg];
      v201 = v200[12];
      v200 += 12;
      *(float *)(v198 + 8) = v201;
      *(float *)(v198 + 12) = v200[1];
      *(float *)(v198 + 16) = v200[2];
      *(float *)(v198 + 20) = v200[3];
      v202 = (float *)this->m_joints.m_data[matg];
      v203 = v202[16];
      v202 += 16;
      *(float *)(v198 + 24) = v203;
      *(float *)(v198 + 28) = v202[1];
      *(float *)(v198 + 32) = v202[2];
      *(float *)(v198 + 36) = v202[3];
      *(float *)(v198 + 40) = this->m_joints.m_data[matg]->m_cfm;
      *(float *)(v198 + 44) = this->m_joints.m_data[matg]->m_erp;
      *(float *)(v198 + 48) = this->m_joints.m_data[matg]->m_split;
      *(_DWORD *)(v198 + 52) = this->m_joints.m_data[matg]->m_delete;
      v204 = (_DWORD *)(v198 + 72);
      v205 = 4;
      do
      {
        *(v204 - 4) = 0;
        *v204++ = 0;
        --v205;
      }
      while ( v205 );
      *(_DWORD *)v198 = 0;
      *(_DWORD *)(v198 + 4) = 0;
      if ( this->m_joints.m_data[matg]->m_bodies[0].m_soft )
      {
        *(_DWORD *)(v198 + 88) = 1;
        *(_DWORD *)v198 = v3->getUniquePointer(v3, this->m_joints.m_data[matg]->m_bodies[0].m_soft);
      }
      if ( this->m_joints.m_data[matg]->m_bodies[0].m_collisionObject )
      {
        *(_DWORD *)(v198 + 88) = 3;
        *(_DWORD *)v198 = v3->getUniquePointer(v3, this->m_joints.m_data[matg]->m_bodies[0].m_collisionObject);
      }
      if ( this->m_joints.m_data[matg]->m_bodies[0].m_rigid )
      {
        *(_DWORD *)(v198 + 88) = 2;
        *(_DWORD *)v198 = v3->getUniquePointer(v3, this->m_joints.m_data[matg]->m_bodies[0].m_rigid);
      }
      if ( this->m_joints.m_data[matg]->m_bodies[1].m_soft )
      {
        *(_DWORD *)(v198 + 92) = 1;
        *(_DWORD *)(v198 + 4) = v3->getUniquePointer(v3, this->m_joints.m_data[matg]->m_bodies[1].m_soft);
      }
      if ( this->m_joints.m_data[matg]->m_bodies[1].m_collisionObject )
      {
        *(_DWORD *)(v198 + 92) = 3;
        *(_DWORD *)(v198 + 4) = v3->getUniquePointer(v3, this->m_joints.m_data[matg]->m_bodies[1].m_collisionObject);
      }
      if ( this->m_joints.m_data[matg]->m_bodies[1].m_rigid )
      {
        *(_DWORD *)(v198 + 92) = 2;
        *(_DWORD *)(v198 + 4) = v3->getUniquePointer(v3, this->m_joints.m_data[matg]->m_bodies[1].m_rigid);
      }
      v198 += 104;
    }
    v3->finalizeChunk(v3, (btChunk *)key.m_pointer, "btSoftBodyJointData", 1497453121, this->m_joints.m_data);
  }
  btHashMap<btHashPtr,int>::~btHashMap<btHashPtr,int>(v140, (int)&m_nodeIndexMap);
  return "btSoftBodyFloatData";
}
