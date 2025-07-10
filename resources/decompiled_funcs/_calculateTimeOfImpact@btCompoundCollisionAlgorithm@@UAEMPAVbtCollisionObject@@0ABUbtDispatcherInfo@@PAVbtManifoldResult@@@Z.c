double __thiscall btCompoundCollisionAlgorithm::calculateTimeOfImpact(
        btCompoundCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  btCompoundCollisionAlgorithm *v5; // edx
  btCollisionObject *v6; // esi
  int v7; // edi
  int v8; // ebx
  btCollisionShape_vtbl *v9; // eax
  float v10; // xmm2_4
  float v11; // xmm1_4
  int v12; // eax
  float v13; // xmm0_4
  float v14; // xmm3_4
  btCollisionShape *v15; // ecx
  float v16; // xmm4_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  btCollisionAlgorithm *v20; // ecx
  double v21; // st7
  float v23; // [esp+404h] [ebp-CCh]
  float v24; // [esp+408h] [ebp-C8h]
  float v25; // [esp+40Ch] [ebp-C4h]
  float v26; // [esp+410h] [ebp-C0h]
  float v27; // [esp+414h] [ebp-BCh]
  float v28; // [esp+418h] [ebp-B8h]
  btCollisionObject *v29; // [esp+41Ch] [ebp-B4h]
  unsigned __int64 v30; // [esp+420h] [ebp-B0h]
  unsigned __int64 v31; // [esp+428h] [ebp-A8h]
  unsigned __int64 v32; // [esp+430h] [ebp-A0h]
  unsigned __int64 v33; // [esp+438h] [ebp-98h]
  unsigned __int64 v34; // [esp+440h] [ebp-90h]
  unsigned __int64 v35; // [esp+448h] [ebp-88h]
  unsigned __int64 v36; // [esp+450h] [ebp-80h]
  unsigned __int64 v37; // [esp+458h] [ebp-78h]
  btCollisionShape *v38; // [esp+474h] [ebp-5Ch]
  int m_size; // [esp+47Ch] [ebp-54h]
  unsigned int v40; // [esp+480h] [ebp-50h]
  btCollisionShape *m_collisionShape; // [esp+488h] [ebp-48h]
  unsigned __int64 v43; // [esp+490h] [ebp-40h]
  unsigned __int64 v44; // [esp+498h] [ebp-38h]
  unsigned __int64 v45; // [esp+4A0h] [ebp-30h]
  unsigned __int64 v46; // [esp+4B0h] [ebp-20h]
  unsigned __int64 v47; // [esp+4B8h] [ebp-18h]

  v5 = this;
  v6 = body1;
  if ( this->m_isSwapped )
  {
    v29 = body0;
  }
  else
  {
    v6 = body0;
    v29 = body1;
  }
  m_collisionShape = v6->m_collisionShape;
  v7 = 0;
  v24 = *(float *)&clear_value;
  m_size = this->m_childCollisionAlgorithms.m_size;
  if ( m_size > 0 )
  {
    HIDWORD(v44) = 0;
    v8 = 0;
    while ( 1 )
    {
      v9 = m_collisionShape[2].__vftable;
      v10 = *(float *)((char *)&v9->serializeSingleShape + v8);
      v11 = *(float *)((char *)&v9[1].~btCollisionShape + v8);
      v30 = v6->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
      v31 = v6->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
      v32 = v6->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[0];
      v33 = v6->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[1];
      v34 = v6->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[0];
      v35 = v6->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[1];
      v12 = (int)v9 + v8;
      v36 = v6->m_worldTransform.m_origin.mVec128.m128_u64[0];
      v37 = v6->m_worldTransform.m_origin.mVec128.m128_u64[1];
      v13 = *(float *)(v12 + 48);
      *(float *)&v43 = (float)((float)((float)(v13 * *(float *)&v30) + (float)(v10 * *((float *)&v30 + 1)))
                             + (float)(v11 * *(float *)&v31))
                     + *(float *)&v36;
      v14 = v13 * *(float *)&v32;
      v15 = *(btCollisionShape **)(v12 + 64);
      v16 = *(float *)(v12 + 24);
      *(float *)&v44 = (float)((float)((float)(v13 * *(float *)&v34) + (float)(v10 * *((float *)&v34 + 1)))
                             + (float)(v11 * *(float *)&v35))
                     + *(float *)&v37;
      v17 = *(float *)(v12 + 8);
      *((float *)&v43 + 1) = (float)((float)(v14 + (float)(v10 * *((float *)&v32 + 1))) + (float)(v11 * *(float *)&v33))
                           + *((float *)&v36 + 1);
      v18 = *(float *)(v12 + 40);
      v25 = *(float *)(v12 + 36);
      v28 = *(float *)(v12 + 20);
      v19 = *(float *)(v12 + 4);
      v26 = *(float *)(v12 + 32);
      v27 = *(float *)(v12 + 16);
      *(float *)&v40 = (float)((float)(*(float *)v12 * *(float *)&v34) + (float)(v27 * *((float *)&v34 + 1)))
                     + (float)(v26 * *(float *)&v35);
      *((float *)&v45 + 1) = (float)((float)(v19 * *(float *)&v30) + (float)(v28 * *((float *)&v30 + 1)))
                           + (float)(v25 * *(float *)&v31);
      *(float *)&v46 = (float)((float)(*(float *)v12 * *(float *)&v32) + (float)(v27 * *((float *)&v32 + 1)))
                     + (float)(v26 * *(float *)&v33);
      *(float *)&v45 = (float)((float)(*(float *)v12 * *(float *)&v30) + (float)(v27 * *((float *)&v30 + 1)))
                     + (float)(v26 * *(float *)&v31);
      *((float *)&v46 + 1) = (float)((float)(v19 * *(float *)&v32) + (float)(v28 * *((float *)&v32 + 1)))
                           + (float)(v25 * *(float *)&v33);
      HIDWORD(v47) = 0;
      v6->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0] = v45;
      v6->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                                                   (float)((float)(v17 * *(float *)&v30)
                                                                         + (float)(v16 * *((float *)&v30 + 1)))
                                                                 + (float)(v18 * *(float *)&v31));
      v6->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[0] = v46;
      *(float *)&v47 = (float)((float)(v17 * *(float *)&v32) + (float)(v16 * *((float *)&v32 + 1)))
                     + (float)(v18 * *(float *)&v33);
      v6->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[1] = v47;
      v6->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[0] = __PAIR64__(
                                                                   (float)((float)(v19 * *(float *)&v34)
                                                                         + (float)(v28 * *((float *)&v34 + 1)))
                                                                 + (float)(v25 * *(float *)&v35),
                                                                   v40);
      v6->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                                                   (float)((float)(v17 * *(float *)&v34)
                                                                         + (float)(v16 * *((float *)&v34 + 1)))
                                                                 + (float)(v18 * *(float *)&v35));
      v6->m_worldTransform.m_origin.mVec128.m128_u64[0] = v43;
      v6->m_worldTransform.m_origin.mVec128.m128_u64[1] = v44;
      v38 = v6->m_collisionShape;
      v6->m_collisionShape = v15;
      v20 = v5->m_childCollisionAlgorithms.m_data[v7];
      v21 = ((double (__thiscall *)(btCollisionAlgorithm *, btCollisionObject *, btCollisionObject *, const btDispatcherInfo *, btManifoldResult *))v20->calculateTimeOfImpact)(
              v20,
              v6,
              v29,
              dispatchInfo,
              resultOut);
      if ( v24 > v21 )
      {
        v23 = v21;
        v24 = v23;
      }
      v6->m_collisionShape = v38;
      v6->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0] = v30;
      v6->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1] = v31;
      v6->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[0] = v32;
      v6->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[1] = v33;
      v6->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[0] = v34;
      v6->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[1] = v35;
      v6->m_worldTransform.m_origin.mVec128.m128_u64[0] = v36;
      ++v7;
      v8 += 80;
      v6->m_worldTransform.m_origin.mVec128.m128_u64[1] = v37;
      if ( v7 >= m_size )
        break;
      v5 = this;
    }
  }
  return v24;
}
