double __thiscall btCollisionWorld::AllHitsRayResultCallback::addSingleResult(
        btCollisionWorld::AllHitsRayResultCallback *this,
        btCollisionWorld::LocalRayResult *rayResult,
        bool normalInWorldSpace)
{
  btCollisionWorld::LocalRayResult *v3; // edi
  int m_capacity; // ecx
  int m_size; // eax
  int v7; // ebx
  int v8; // edx
  int v9; // eax
  btCollisionObject **v10; // ecx
  btCollisionObject **m_data; // eax
  btCollisionObject **v12; // eax
  unsigned __int64 v13; // xmm0_8
  float *m_collisionObject; // eax
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  int v20; // ecx
  int v21; // eax
  int v22; // ebx
  btVector3 *v23; // edi
  int v24; // edx
  btVector3 *v25; // ecx
  int v26; // ebx
  btVector3 *v27; // eax
  btVector3 *v28; // eax
  btVector3 *v29; // eax
  btCollisionWorld::LocalShapeInfo *m_localShapeInfo; // eax
  int v31; // ecx
  int v32; // eax
  int v33; // ebx
  int v34; // edx
  int v35; // eax
  int *v36; // ecx
  int *v37; // eax
  int *v38; // eax
  int v39; // ecx
  int v40; // eax
  signed int v41; // eax
  bool *v42; // ebx
  int v43; // edi
  int i; // eax
  bool *v45; // eax
  bool *v46; // eax
  float m_hitFraction; // xmm1_4
  int v48; // ecx
  int v49; // eax
  int v50; // eax
  btVector3 *v51; // edi
  int v52; // edx
  btVector3 *v53; // ecx
  int v54; // ebx
  btVector3 *v55; // eax
  btVector3 *v56; // eax
  btVector3 *v57; // eax
  int v58; // ecx
  int v59; // eax
  int v60; // eax
  int v61; // edi
  float *v62; // eax
  int v63; // ebx
  unsigned int v64; // ecx
  float *v65; // eax
  float *v66; // eax
  float *v67; // eax
  bool m_is_shape_index; // [esp+A9h] [ebp-3Dh]
  btCollisionObject **v70; // [esp+AAh] [ebp-3Ch]
  int *v71; // [esp+AAh] [ebp-3Ch]
  int v72; // [esp+AAh] [ebp-3Ch]
  int v73; // [esp+AAh] [ebp-3Ch]
  float *v74; // [esp+AAh] [ebp-3Ch]
  int v75; // [esp+AEh] [ebp-38h]
  int m_triangleIndex; // [esp+AEh] [ebp-38h]
  int v77; // [esp+AEh] [ebp-38h]
  int v78; // [esp+B6h] [ebp-30h]
  int v79; // [esp+BAh] [ebp-2Ch]
  int v80; // [esp+C2h] [ebp-24h]
  unsigned __int64 v81; // [esp+C6h] [ebp-20h]
  unsigned __int64 v82; // [esp+D6h] [ebp-10h]
  unsigned __int64 v83; // [esp+D6h] [ebp-10h]
  unsigned __int64 v84; // [esp+DEh] [ebp-8h]

  v3 = rayResult;
  this->m_collisionObject = rayResult->m_collisionObject;
  m_capacity = this->m_collisionObjects.m_capacity;
  m_size = this->m_collisionObjects.m_size;
  if ( m_size == m_capacity )
  {
    v7 = 2 * m_size;
    if ( !m_size )
      v7 = 1;
    if ( m_capacity < v7 )
    {
      if ( v7 )
      {
        ++gNumAlignedAllocs;
        v70 = (btCollisionObject **)sAlignedAllocFunc(4 * v7, 16);
      }
      else
      {
        v70 = 0;
      }
      v8 = this->m_collisionObjects.m_size;
      v9 = 0;
      if ( v8 > 0 )
      {
        v10 = v70;
        do
        {
          if ( v10 )
          {
            *v10 = this->m_collisionObjects.m_data[v9];
            v3 = rayResult;
          }
          ++v9;
          ++v10;
        }
        while ( v9 < v8 );
      }
      m_data = this->m_collisionObjects.m_data;
      if ( m_data )
      {
        if ( this->m_collisionObjects.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(m_data);
        }
        this->m_collisionObjects.m_data = 0;
      }
      this->m_collisionObjects.m_data = v70;
      this->m_collisionObjects.m_ownsMemory = 1;
      this->m_collisionObjects.m_capacity = v7;
    }
  }
  v12 = &this->m_collisionObjects.m_data[this->m_collisionObjects.m_size];
  if ( v12 )
    *v12 = v3->m_collisionObject;
  ++this->m_collisionObjects.m_size;
  if ( normalInWorldSpace )
  {
    v82 = v3->m_hitNormalLocal.mVec128.m128_u64[0];
    v13 = v3->m_hitNormalLocal.mVec128.m128_u64[1];
  }
  else
  {
    m_collisionObject = (float *)this->m_collisionObject;
    v15 = v3->m_hitNormalLocal.mVec128.m128_f32[2];
    v16 = v3->m_hitNormalLocal.mVec128.m128_f32[1];
    v17 = v3->m_hitNormalLocal.mVec128.m128_f32[0];
    v18 = m_collisionObject[5];
    v19 = m_collisionObject[6];
    m_collisionObject += 4;
    *(float *)&v81 = (float)((float)(v18 * v16) + (float)(v19 * v15)) + (float)(v17 * *m_collisionObject);
    *((float *)&v81 + 1) = (float)((float)(m_collisionObject[5] * v16) + (float)(m_collisionObject[6] * v15))
                         + (float)(v17 * m_collisionObject[4]);
    v82 = v81;
    v13 = COERCE_UNSIGNED_INT(
            (float)((float)(m_collisionObject[9] * v16) + (float)(m_collisionObject[10] * v15))
          + (float)(m_collisionObject[8] * v17));
  }
  v20 = this->m_hitNormalWorld.m_capacity;
  v21 = this->m_hitNormalWorld.m_size;
  HIDWORD(v84) = HIDWORD(v13);
  if ( v21 == v20 )
  {
    if ( v21 )
    {
      v22 = 2 * v21;
      v75 = 2 * v21;
    }
    else
    {
      v22 = 1;
      v75 = 1;
    }
    if ( v20 < v22 )
    {
      if ( v22 )
      {
        ++gNumAlignedAllocs;
        v23 = (btVector3 *)sAlignedAllocFunc(16 * v22, 16);
      }
      else
      {
        v23 = 0;
      }
      if ( this->m_hitNormalWorld.m_size > 0 )
      {
        v24 = 0;
        v25 = v23;
        v26 = this->m_hitNormalWorld.m_size;
        do
        {
          if ( v25 )
          {
            v27 = this->m_hitNormalWorld.m_data;
            v25->mVec128.m128_u64[0] = v27[v24].mVec128.m128_u64[0];
            v25->mVec128.m128_u64[1] = v27[v24].mVec128.m128_u64[1];
          }
          ++v24;
          ++v25;
          --v26;
        }
        while ( v26 );
        v22 = v75;
      }
      v28 = this->m_hitNormalWorld.m_data;
      if ( v28 )
      {
        if ( this->m_hitNormalWorld.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v28);
        }
        this->m_hitNormalWorld.m_data = 0;
      }
      this->m_hitNormalWorld.m_data = v23;
      v3 = rayResult;
      this->m_hitNormalWorld.m_ownsMemory = 1;
      this->m_hitNormalWorld.m_capacity = v22;
    }
  }
  v29 = &this->m_hitNormalWorld.m_data[this->m_hitNormalWorld.m_size];
  if ( v29 )
  {
    v29->mVec128.m128_u64[0] = v82;
    v29->mVec128.m128_u64[1] = v13;
  }
  ++this->m_hitNormalWorld.m_size;
  m_triangleIndex = -1;
  m_is_shape_index = 0;
  if ( v3->m_localShapeInfo )
  {
    m_localShapeInfo = v3->m_localShapeInfo;
    m_triangleIndex = m_localShapeInfo->m_triangleIndex;
    m_is_shape_index = m_localShapeInfo->m_is_shape_index;
  }
  v31 = this->m_triangleIndex.m_capacity;
  v32 = this->m_triangleIndex.m_size;
  if ( v32 == v31 )
  {
    v33 = 2 * v32;
    if ( !v32 )
      v33 = 1;
    if ( v31 < v33 )
    {
      if ( v33 )
      {
        ++gNumAlignedAllocs;
        v71 = (int *)sAlignedAllocFunc(4 * v33, 16);
      }
      else
      {
        v71 = 0;
      }
      v34 = this->m_triangleIndex.m_size;
      v35 = 0;
      if ( v34 > 0 )
      {
        v36 = v71;
        do
        {
          if ( v36 )
          {
            *v36 = this->m_triangleIndex.m_data[v35];
            v3 = rayResult;
          }
          ++v35;
          ++v36;
        }
        while ( v35 < v34 );
      }
      v37 = this->m_triangleIndex.m_data;
      if ( v37 )
      {
        if ( this->m_triangleIndex.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v37);
        }
        this->m_triangleIndex.m_data = 0;
      }
      this->m_triangleIndex.m_data = v71;
      this->m_triangleIndex.m_ownsMemory = 1;
      this->m_triangleIndex.m_capacity = v33;
    }
  }
  v38 = &this->m_triangleIndex.m_data[this->m_triangleIndex.m_size];
  if ( v38 )
    *v38 = m_triangleIndex;
  ++this->m_triangleIndex.m_size;
  v39 = this->m_is_shape_index.m_capacity;
  v40 = this->m_is_shape_index.m_size;
  if ( v40 == v39 )
  {
    if ( v40 )
    {
      v41 = 2 * v40;
      v72 = v41;
    }
    else
    {
      v72 = 1;
      v41 = 1;
    }
    if ( v39 < v41 )
    {
      if ( v41 )
      {
        ++gNumAlignedAllocs;
        v42 = (bool *)sAlignedAllocFunc(v41, 16);
      }
      else
      {
        v42 = 0;
      }
      v43 = this->m_is_shape_index.m_size;
      for ( i = 0; i < v43; ++i )
      {
        if ( &v42[i] )
          v42[i] = this->m_is_shape_index.m_data[i];
      }
      v45 = this->m_is_shape_index.m_data;
      if ( v45 )
      {
        if ( this->m_is_shape_index.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v45);
        }
        this->m_is_shape_index.m_data = 0;
      }
      v3 = rayResult;
      this->m_is_shape_index.m_ownsMemory = 1;
      this->m_is_shape_index.m_data = v42;
      this->m_is_shape_index.m_capacity = v72;
    }
  }
  v46 = &this->m_is_shape_index.m_data[this->m_is_shape_index.m_size];
  if ( v46 )
    *v46 = m_is_shape_index;
  ++this->m_is_shape_index.m_size;
  m_hitFraction = v3->m_hitFraction;
  v48 = this->m_hitPointWorld.m_capacity;
  v49 = this->m_hitPointWorld.m_size;
  *(float *)&v83 = (float)(this->m_rayToWorld.mVec128.m128_f32[0] * m_hitFraction)
                 + (float)((float)(*(float *)&clear_value - m_hitFraction) * this->m_rayFromWorld.mVec128.m128_f32[0]);
  *((float *)&v83 + 1) = (float)(this->m_rayFromWorld.mVec128.m128_f32[1]
                               * (float)(*(float *)&clear_value - m_hitFraction))
                       + (float)(this->m_rayToWorld.mVec128.m128_f32[1] * m_hitFraction);
  *(float *)&v84 = (float)(this->m_rayFromWorld.mVec128.m128_f32[2] * (float)(*(float *)&clear_value - m_hitFraction))
                 + (float)(this->m_rayToWorld.mVec128.m128_f32[2] * m_hitFraction);
  if ( v49 == v48 )
  {
    if ( v49 )
    {
      v50 = 2 * v49;
      v73 = v50;
    }
    else
    {
      v50 = 1;
      v73 = 1;
    }
    if ( v48 < v50 )
    {
      if ( v50 )
      {
        ++gNumAlignedAllocs;
        v51 = (btVector3 *)sAlignedAllocFunc(16 * v73, 16);
      }
      else
      {
        v51 = 0;
      }
      if ( this->m_hitPointWorld.m_size > 0 )
      {
        v52 = 0;
        v53 = v51;
        v54 = this->m_hitPointWorld.m_size;
        do
        {
          if ( v53 )
          {
            v55 = this->m_hitPointWorld.m_data;
            v53->mVec128.m128_u64[0] = v55[v52].mVec128.m128_u64[0];
            v53->mVec128.m128_u64[1] = v55[v52].mVec128.m128_u64[1];
          }
          ++v52;
          ++v53;
          --v54;
        }
        while ( v54 );
      }
      v56 = this->m_hitPointWorld.m_data;
      if ( v56 )
      {
        if ( this->m_hitPointWorld.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v56);
        }
        this->m_hitPointWorld.m_data = 0;
      }
      this->m_hitPointWorld.m_data = v51;
      v3 = rayResult;
      this->m_hitPointWorld.m_ownsMemory = 1;
      this->m_hitPointWorld.m_capacity = v73;
    }
  }
  v57 = &this->m_hitPointWorld.m_data[this->m_hitPointWorld.m_size];
  if ( v57 )
  {
    v57->mVec128.m128_u64[0] = v83;
    v57->mVec128.m128_u64[1] = v84;
  }
  ++this->m_hitPointWorld.m_size;
  v58 = this->m_hitFractions.m_capacity;
  v59 = this->m_hitFractions.m_size;
  if ( v59 == v58 )
  {
    if ( v59 )
    {
      v60 = 2 * v59;
      v79 = v60;
    }
    else
    {
      v60 = 1;
      v79 = 1;
    }
    if ( v58 < v60 )
    {
      if ( v60 )
      {
        ++gNumAlignedAllocs;
        v74 = (float *)sAlignedAllocFunc(4 * v60, 16);
      }
      else
      {
        v74 = 0;
      }
      v61 = 0;
      v78 = this->m_hitFractions.m_size;
      if ( v78 >= 4 )
      {
        v62 = v74 + 2;
        v63 = -8 - (_DWORD)v74;
        v64 = ((unsigned int)(v78 - 4) >> 2) + 1;
        v61 = 4 * v64;
        v77 = 2;
        v80 = 4 * v64;
        do
        {
          if ( v62 != (float *)8 )
            *(v62 - 2) = *(float *)((char *)this->m_hitFractions.m_data + v63 + (unsigned int)v62);
          if ( v62 != (float *)4 )
            *(v62 - 1) = *(float *)((char *)this->m_hitFractions.m_data + v63 + (unsigned int)v62 + 4);
          if ( v62 )
          {
            v63 = -8 - (_DWORD)v74;
            *v62 = this->m_hitFractions.m_data[v77];
          }
          if ( v62 != (float *)-4 )
          {
            v63 = -8 - (_DWORD)v74;
            v61 = v80;
            v62[1] = *(float *)((char *)this->m_hitFractions.m_data + 4 - (_DWORD)v74 + (unsigned int)v62);
          }
          v77 += 4;
          v62 += 4;
          --v64;
        }
        while ( v64 );
      }
      if ( v61 < v78 )
      {
        v65 = &v74[v61];
        do
        {
          if ( v65 )
            *v65 = this->m_hitFractions.m_data[v61];
          ++v61;
          ++v65;
        }
        while ( v61 < v78 );
      }
      v66 = this->m_hitFractions.m_data;
      if ( v66 )
      {
        if ( this->m_hitFractions.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v66);
        }
        this->m_hitFractions.m_data = 0;
      }
      v3 = rayResult;
      this->m_hitFractions.m_ownsMemory = 1;
      this->m_hitFractions.m_data = v74;
      this->m_hitFractions.m_capacity = v79;
    }
  }
  v67 = &this->m_hitFractions.m_data[this->m_hitFractions.m_size];
  if ( v67 )
    *v67 = v3->m_hitFraction;
  ++this->m_hitFractions.m_size;
  return this->m_closestHitFraction;
}
