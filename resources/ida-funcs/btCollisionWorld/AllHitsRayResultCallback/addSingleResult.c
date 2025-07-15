double __thiscall btCollisionWorld::AllHitsRayResultCallback::addSingleResult(
        btCollisionWorld::AllHitsRayResultCallback *this,
        btCollisionWorld::LocalRayResult *rayResult,
        bool normalInWorldSpace)
{
  int m_capacity; // ecx
  int m_size; // eax
  int v6; // esi
  int v7; // edx
  int v8; // eax
  btCollisionObject **v9; // ecx
  btCollisionObject **v10; // eax
  btVector3 *p_m_hitNormalLocal; // esi
  float *m_collisionObject; // eax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  int v20; // ecx
  int v21; // eax
  int *v22; // esi
  int v23; // eax
  __m128 *p_mVec128; // ecx
  int v25; // edx
  btVector3 *v26; // esi
  btVector3 *v27; // edi
  int *v28; // edi
  btCollisionWorld::LocalShapeInfo *m_localShapeInfo; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // esi
  int v33; // edx
  int v34; // eax
  int *v35; // ecx
  int *v36; // eax
  int v37; // ecx
  int v38; // eax
  int v39; // edi
  int i; // eax
  bool *v41; // eax
  float m_hitFraction; // xmm1_4
  int v43; // ecx
  int v44; // eax
  float v45; // xmm3_4
  int v46; // eax
  __m128 *v47; // ecx
  int v48; // edx
  btVector3 *v49; // esi
  btVector3 *v50; // edi
  int *v51; // edi
  int v52; // ecx
  int v53; // eax
  int v54; // esi
  int v55; // edx
  int v56; // eax
  float *v57; // ecx
  float *v58; // eax
  bool m_is_shape_index; // [esp+17h] [ebp-29h]
  btCollisionObject **size; // [esp+18h] [ebp-28h]
  signed int sizea; // [esp+18h] [ebp-28h]
  unsigned int sizeb; // [esp+18h] [ebp-28h]
  int sizec; // [esp+18h] [ebp-28h]
  signed int sized; // [esp+18h] [ebp-28h]
  btVector3 *v66; // [esp+1Ch] [ebp-24h]
  int *v67; // [esp+1Ch] [ebp-24h]
  bool *v68; // [esp+1Ch] [ebp-24h]
  btVector3 *v69; // [esp+1Ch] [ebp-24h]
  float *v70; // [esp+1Ch] [ebp-24h]
  float v71; // [esp+20h] [ebp-20h] BYREF
  float v72; // [esp+24h] [ebp-1Ch]
  float v73; // [esp+28h] [ebp-18h]
  int v74; // [esp+2Ch] [ebp-14h]
  int v75; // [esp+30h] [ebp-10h]
  int v76; // [esp+34h] [ebp-Ch]
  int v77; // [esp+38h] [ebp-8h]
  int v78; // [esp+3Ch] [ebp-4h]

  this->m_collisionObject = rayResult->m_collisionObject;
  m_capacity = this->m_collisionObjects.m_capacity;
  m_size = this->m_collisionObjects.m_size;
  if ( m_size == m_capacity )
  {
    v6 = m_size ? 2 * m_size : 1;
    if ( m_capacity < v6 )
    {
      if ( v6 )
        size = (btCollisionObject **)btAlignedAllocInternal(4 * v6);
      else
        size = 0;
      v7 = this->m_collisionObjects.m_size;
      v8 = 0;
      if ( v7 > 0 )
      {
        v9 = size;
        do
        {
          if ( v9 )
            *v9 = this->m_collisionObjects.m_data[v8];
          ++v8;
          ++v9;
        }
        while ( v8 < v7 );
      }
      if ( this->m_collisionObjects.m_data )
      {
        if ( this->m_collisionObjects.m_ownsMemory )
          btAlignedFreeInternal(this->m_collisionObjects.m_data);
        this->m_collisionObjects.m_data = 0;
      }
      this->m_collisionObjects.m_ownsMemory = 1;
      this->m_collisionObjects.m_data = size;
      this->m_collisionObjects.m_capacity = v6;
    }
  }
  v10 = &this->m_collisionObjects.m_data[this->m_collisionObjects.m_size];
  if ( v10 )
    *v10 = rayResult->m_collisionObject;
  ++this->m_collisionObjects.m_size;
  if ( normalInWorldSpace )
  {
    p_m_hitNormalLocal = &rayResult->m_hitNormalLocal;
  }
  else
  {
    m_collisionObject = (float *)this->m_collisionObject;
    v13 = rayResult->m_hitNormalLocal.mVec128.m128_f32[2];
    v14 = rayResult->m_hitNormalLocal.mVec128.m128_f32[1];
    v15 = rayResult->m_hitNormalLocal.mVec128.m128_f32[0];
    v16 = m_collisionObject[5];
    v17 = m_collisionObject[6];
    m_collisionObject += 4;
    v18 = (float)((float)(v16 * v14) + (float)(v17 * v13)) + (float)(v15 * *m_collisionObject);
    v19 = m_collisionObject[6];
    v71 = v18;
    v72 = (float)((float)(m_collisionObject[5] * v14) + (float)(v19 * v13)) + (float)(m_collisionObject[4] * v15);
    v73 = (float)((float)(m_collisionObject[9] * v14) + (float)(m_collisionObject[10] * v13))
        + (float)(m_collisionObject[8] * v15);
    v74 = 0;
    p_m_hitNormalLocal = (btVector3 *)&v71;
  }
  v20 = this->m_hitNormalWorld.m_capacity;
  v21 = this->m_hitNormalWorld.m_size;
  v75 = p_m_hitNormalLocal->mVec128.m128_i32[0];
  v22 = &p_m_hitNormalLocal->mVec128.m128_i32[1];
  v76 = *v22++;
  v77 = *v22;
  v78 = v22[1];
  if ( v21 == v20 )
  {
    sizea = v21 ? 2 * v21 : 1;
    if ( v20 < sizea )
    {
      if ( sizea )
        v66 = (btVector3 *)btAlignedAllocInternal(16 * sizea);
      else
        v66 = 0;
      v23 = this->m_hitNormalWorld.m_size;
      if ( v23 > 0 )
      {
        p_mVec128 = &v66->mVec128;
        v25 = 0;
        do
        {
          if ( p_mVec128 )
          {
            v26 = &this->m_hitNormalWorld.m_data[v25];
            p_mVec128->m128_i32[0] = v26->mVec128.m128_i32[0];
            v26 = (btVector3 *)((char *)v26 + 4);
            p_mVec128->m128_i32[1] = v26->mVec128.m128_i32[0];
            v26 = (btVector3 *)((char *)v26 + 4);
            p_mVec128->m128_i32[2] = v26->mVec128.m128_i32[0];
            p_mVec128->m128_i32[3] = v26->mVec128.m128_i32[1];
          }
          ++v25;
          ++p_mVec128;
          --v23;
        }
        while ( v23 );
      }
      if ( this->m_hitNormalWorld.m_data )
      {
        if ( this->m_hitNormalWorld.m_ownsMemory )
          btAlignedFreeInternal(this->m_hitNormalWorld.m_data);
        this->m_hitNormalWorld.m_data = 0;
      }
      this->m_hitNormalWorld.m_data = v66;
      this->m_hitNormalWorld.m_ownsMemory = 1;
      this->m_hitNormalWorld.m_capacity = sizea;
    }
  }
  v27 = &this->m_hitNormalWorld.m_data[this->m_hitNormalWorld.m_size];
  if ( v27 )
  {
    v27->mVec128.m128_i32[0] = v75;
    v28 = &v27->mVec128.m128_i32[1];
    *v28++ = v76;
    *v28 = v77;
    v28[1] = v78;
  }
  ++this->m_hitNormalWorld.m_size;
  sizeb = -1;
  m_is_shape_index = 0;
  if ( rayResult->m_localShapeInfo )
  {
    m_localShapeInfo = rayResult->m_localShapeInfo;
    sizeb = m_localShapeInfo->m_triangleIndex;
    m_is_shape_index = m_localShapeInfo->m_is_shape_index;
  }
  v30 = this->m_triangleIndex.m_capacity;
  v31 = this->m_triangleIndex.m_size;
  if ( v31 == v30 )
  {
    v32 = v31 ? 2 * v31 : 1;
    if ( v30 < v32 )
    {
      if ( v32 )
        v67 = (int *)btAlignedAllocInternal(4 * v32);
      else
        v67 = 0;
      v33 = this->m_triangleIndex.m_size;
      v34 = 0;
      if ( v33 > 0 )
      {
        v35 = v67;
        do
        {
          if ( v35 )
            *v35 = this->m_triangleIndex.m_data[v34];
          ++v34;
          ++v35;
        }
        while ( v34 < v33 );
      }
      if ( this->m_triangleIndex.m_data )
      {
        if ( this->m_triangleIndex.m_ownsMemory )
          btAlignedFreeInternal(this->m_triangleIndex.m_data);
        this->m_triangleIndex.m_data = 0;
      }
      this->m_triangleIndex.m_ownsMemory = 1;
      this->m_triangleIndex.m_data = v67;
      this->m_triangleIndex.m_capacity = v32;
    }
  }
  v36 = &this->m_triangleIndex.m_data[this->m_triangleIndex.m_size];
  if ( v36 )
    *v36 = sizeb;
  ++this->m_triangleIndex.m_size;
  v37 = this->m_is_shape_index.m_capacity;
  v38 = this->m_is_shape_index.m_size;
  if ( v38 == v37 )
  {
    sizec = v38 ? 2 * v38 : 1;
    if ( v37 < sizec )
    {
      if ( sizec )
        v68 = (bool *)btAlignedAllocInternal(sizec);
      else
        v68 = 0;
      v39 = this->m_is_shape_index.m_size;
      for ( i = 0; i < v39; ++i )
      {
        if ( &v68[i] )
          v68[i] = this->m_is_shape_index.m_data[i];
      }
      if ( this->m_is_shape_index.m_data )
      {
        if ( this->m_is_shape_index.m_ownsMemory )
          btAlignedFreeInternal(this->m_is_shape_index.m_data);
        this->m_is_shape_index.m_data = 0;
      }
      this->m_is_shape_index.m_data = v68;
      this->m_is_shape_index.m_ownsMemory = 1;
      this->m_is_shape_index.m_capacity = sizec;
    }
  }
  v41 = &this->m_is_shape_index.m_data[this->m_is_shape_index.m_size];
  if ( v41 )
    *v41 = m_is_shape_index;
  ++this->m_is_shape_index.m_size;
  m_hitFraction = rayResult->m_hitFraction;
  v43 = this->m_hitPointWorld.m_capacity;
  v44 = this->m_hitPointWorld.m_size;
  v45 = this->m_rayToWorld.mVec128.m128_f32[1];
  v71 = (float)(m_hitFraction * this->m_rayToWorld.mVec128.m128_f32[0])
      + (float)(this->m_rayFromWorld.mVec128.m128_f32[0] * (float)(s_bm_current_air_resistance - m_hitFraction));
  v72 = (float)(this->m_rayFromWorld.mVec128.m128_f32[1] * (float)(s_bm_current_air_resistance - m_hitFraction))
      + (float)(v45 * m_hitFraction);
  v73 = (float)(this->m_rayFromWorld.mVec128.m128_f32[2] * (float)(s_bm_current_air_resistance - m_hitFraction))
      + (float)(this->m_rayToWorld.mVec128.m128_f32[2] * m_hitFraction);
  if ( v44 == v43 )
  {
    sized = v44 ? 2 * v44 : 1;
    if ( v43 < sized )
    {
      if ( sized )
        v69 = (btVector3 *)btAlignedAllocInternal(16 * sized);
      else
        v69 = 0;
      v46 = this->m_hitPointWorld.m_size;
      if ( v46 > 0 )
      {
        v47 = &v69->mVec128;
        v48 = 0;
        do
        {
          if ( v47 )
          {
            v49 = &this->m_hitPointWorld.m_data[v48];
            v47->m128_i32[0] = v49->mVec128.m128_i32[0];
            v49 = (btVector3 *)((char *)v49 + 4);
            v47->m128_i32[1] = v49->mVec128.m128_i32[0];
            v49 = (btVector3 *)((char *)v49 + 4);
            v47->m128_i32[2] = v49->mVec128.m128_i32[0];
            v47->m128_i32[3] = v49->mVec128.m128_i32[1];
          }
          ++v48;
          ++v47;
          --v46;
        }
        while ( v46 );
      }
      if ( this->m_hitPointWorld.m_data )
      {
        if ( this->m_hitPointWorld.m_ownsMemory )
          btAlignedFreeInternal(this->m_hitPointWorld.m_data);
        this->m_hitPointWorld.m_data = 0;
      }
      this->m_hitPointWorld.m_data = v69;
      this->m_hitPointWorld.m_ownsMemory = 1;
      this->m_hitPointWorld.m_capacity = sized;
    }
  }
  v50 = &this->m_hitPointWorld.m_data[this->m_hitPointWorld.m_size];
  if ( v50 )
  {
    v50->mVec128.m128_f32[0] = v71;
    v51 = &v50->mVec128.m128_i32[1];
    *(float *)v51++ = v72;
    *(float *)v51 = v73;
    v51[1] = v74;
  }
  ++this->m_hitPointWorld.m_size;
  v52 = this->m_hitFractions.m_capacity;
  v53 = this->m_hitFractions.m_size;
  if ( v53 == v52 )
  {
    v54 = v53 ? 2 * v53 : 1;
    if ( v52 < v54 )
    {
      if ( v54 )
        v70 = (float *)btAlignedAllocInternal(4 * v54);
      else
        v70 = 0;
      v55 = this->m_hitFractions.m_size;
      v56 = 0;
      if ( v55 > 0 )
      {
        v57 = v70;
        do
        {
          if ( v57 )
            *v57 = this->m_hitFractions.m_data[v56];
          ++v56;
          ++v57;
        }
        while ( v56 < v55 );
      }
      if ( this->m_hitFractions.m_data )
      {
        if ( this->m_hitFractions.m_ownsMemory )
          btAlignedFreeInternal(this->m_hitFractions.m_data);
        this->m_hitFractions.m_data = 0;
      }
      this->m_hitFractions.m_ownsMemory = 1;
      this->m_hitFractions.m_data = v70;
      this->m_hitFractions.m_capacity = v54;
    }
  }
  v58 = &this->m_hitFractions.m_data[this->m_hitFractions.m_size];
  if ( v58 )
    *v58 = rayResult->m_hitFraction;
  ++this->m_hitFractions.m_size;
  return this->m_closestHitFraction;
}
