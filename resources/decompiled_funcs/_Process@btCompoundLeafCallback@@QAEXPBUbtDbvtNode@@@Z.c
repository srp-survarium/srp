void __userpurge btCompoundLeafCallback::Process(
        btCompoundLeafCallback *this@<ecx>,
        btCompoundLeafCallback *a2@<eax>,
        const btDbvtNode *leaf)
{
  int dataAsInt; // edi
  const btDispatcherInfo *m_dispatchInfo; // edx
  bool v6; // zf
  btCollisionObject *m_compoundColObj; // eax
  float v8; // xmm7_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm1_4
  float v12; // xmm6_4
  float v13; // xmm2_4
  unsigned __int64 v14; // xmm0_8
  float v15; // xmm1_4
  int v16; // xmm2_4
  int v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm1_4
  float v23; // xmm5_4
  __m128i v24; // xmm7
  const btDispatcherInfo *v25; // ecx
  __m128i v26; // [esp+16Ch] [ebp-A0h] BYREF
  __m128i v27; // [esp+17Ch] [ebp-90h] BYREF
  float v28; // [esp+194h] [ebp-78h]
  float v29; // [esp+198h] [ebp-74h]
  float v30; // [esp+19Ch] [ebp-70h]
  btCollisionShape *v31; // [esp+1A0h] [ebp-6Ch]
  float v32; // [esp+1A4h] [ebp-68h]
  float v33; // [esp+1A8h] [ebp-64h]
  float v34; // [esp+1ACh] [ebp-60h]
  float v35; // [esp+1B0h] [ebp-5Ch]
  float v36; // [esp+1B4h] [ebp-58h]
  float v37; // [esp+1B8h] [ebp-54h]
  unsigned __int64 v38; // [esp+1BCh] [ebp-50h]
  unsigned __int64 v39; // [esp+1C4h] [ebp-48h]
  unsigned __int64 v40; // [esp+1CCh] [ebp-40h]
  unsigned __int64 v41; // [esp+1D4h] [ebp-38h]
  unsigned __int64 v42; // [esp+1DCh] [ebp-30h]
  unsigned __int64 _X; // [esp+1E4h] [ebp-28h]
  unsigned __int64 v44; // [esp+1ECh] [ebp-20h]
  unsigned __int64 v45; // [esp+1F4h] [ebp-18h]
  __m128i v46; // [esp+1FCh] [ebp-10h] BYREF

  dataAsInt = leaf->dataAsInt;
  m_dispatchInfo = a2->m_dispatchInfo;
  v6 = m_dispatchInfo->m_debugDraw == 0;
  v31 = (btCollisionShape *)*((_DWORD *)&a2->m_compoundColObj->m_collisionShape[2].__vftable[1].getBoundingSphere
                            + 20 * dataAsInt);
  if ( !v6 && (m_dispatchInfo->m_debugDraw->getDebugMode(m_dispatchInfo->m_debugDraw) & 2) != 0 )
  {
    m_compoundColObj = a2->m_compoundColObj;
    v8 = leaf->volume.mx.mVec128.m128_f32[0];
    v9 = leaf->volume.mi.mVec128.m128_f32[0];
    v10 = leaf->volume.mi.mVec128.m128_f32[1];
    v11 = leaf->volume.mx.mVec128.m128_f32[1];
    v12 = leaf->volume.mi.mVec128.m128_f32[2];
    v13 = leaf->volume.mx.mVec128.m128_f32[2];
    v38 = a2->m_compoundColObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
    v14 = m_compoundColObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
    m_compoundColObj = (btCollisionObject *)((char *)m_compoundColObj + 16);
    v39 = v14;
    v40 = m_compoundColObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
    v41 = m_compoundColObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
    v42 = m_compoundColObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[0];
    _X = m_compoundColObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[1];
    v44 = m_compoundColObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[0];
    v45 = m_compoundColObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[1];
    v15 = v11 - v10;
    *(float *)v27.m128i_i32 = (float)(v8 - v9) * 0.5;
    *(float *)&v16 = (float)(v13 - v12) * 0.5;
    *(float *)&v17 = (float)(v10 + leaf->volume.mx.mVec128.m128_f32[1]) * 0.5;
    v18 = (float)(v12 + leaf->volume.mx.mVec128.m128_f32[2]) * 0.5;
    *(float *)&v27.m128i_i32[1] = v15 * 0.5;
    v27.m128i_i32[2] = v16;
    *(float *)v26.m128i_i32 = (float)(v9 + v8) * 0.5;
    v26.m128i_i32[1] = v17;
    v34 = fabsf(*(float *)&_X);
    v28 = fabsf(*((float *)&v42 + 1));
    v29 = fabsf(*(float *)&v42);
    v37 = fabsf(*(float *)&v41);
    v30 = fabsf(*((float *)&v40 + 1));
    v32 = fabsf(*(float *)&v40);
    v36 = fabsf(*(float *)&v14);
    v33 = fabsf(*((float *)&v38 + 1));
    v35 = fabsf(*(float *)&v38);
    v19 = (float)((float)((float)(*(float *)&v14 * v18) + (float)(*((float *)&v38 + 1) * *(float *)&v17))
                + (float)(*(float *)&v38 * *(float *)v26.m128i_i32))
        + *(float *)&v44;
    v20 = (float)((float)((float)(*(float *)&v41 * v18) + (float)(*((float *)&v40 + 1) * *(float *)&v17))
                + (float)(*(float *)&v40 * *(float *)v26.m128i_i32))
        + *((float *)&v44 + 1);
    v21 = (float)((float)((float)(*(float *)&_X * v18) + (float)(*((float *)&v42 + 1) * *(float *)&v17))
                + (float)(*(float *)&v42 * *(float *)v26.m128i_i32))
        + *(float *)&v45;
    *(float *)&v14 = (float)((float)(*(float *)&v27.m128i_i32[2] * v36) + (float)((float)(v15 * 0.5) * v33))
                   + (float)(v35 * *(float *)v27.m128i_i32);
    v22 = (float)((float)((float)(v15 * 0.5) * v30) + (float)(*(float *)&v27.m128i_i32[2] * v37))
        + (float)(v32 * *(float *)v27.m128i_i32);
    v23 = (float)((float)(*(float *)&v27.m128i_i32[1] * v28) + (float)(*(float *)&v27.m128i_i32[2] * v34))
        + (float)(*(float *)v27.m128i_i32 * v29);
    *(float *)v26.m128i_i32 = (float)((float)((float)((float)(*(float *)&v39 * v18)
                                                    + (float)(*((float *)&v38 + 1) * *(float *)&v26.m128i_i32[1]))
                                            + (float)(*(float *)&v38 * *(float *)v26.m128i_i32))
                                    + *(float *)&v44)
                            - *(float *)&v14;
    *(float *)&v26.m128i_i32[1] = v20 - v22;
    *(float *)&v26.m128i_i32[2] = v21 - v23;
    v24 = _mm_load_si128(&v26);
    *(float *)v26.m128i_i32 = *(float *)&v14 + v19;
    *(float *)&v26.m128i_i32[1] = v22 + v20;
    v26.m128i_i64[1] = COERCE_UNSIGNED_INT(v23 + v21);
    v27 = _mm_load_si128(&v26);
    v46 = v24;
    v26.m128i_i64[0] = (unsigned int)clear_value;
    v25 = a2->m_dispatchInfo;
    v26.m128i_i64[1] = 0;
    v25->m_debugDraw->drawAabb(
      v25->m_debugDraw,
      (const btVector3 *)&v46,
      (const btVector3 *)&v27,
      (const btVector3 *)&v26);
  }
  btCompoundLeafCallback::ProcessChildShape(a2, dataAsInt, v31);
}
