void __thiscall btSoftBody::defaultCollisionHandler(btSoftBody *this, btSoftBody *pco, btCollisionObject *pcoa)
{
  char m_internalType; // al
  btCollisionShape *m_collisionShape; // ecx
  btCollisionShape_vtbl *v5; // edx
  int v6; // esi
  float (__thiscall *getMargin)(btCollisionShape *); // eax
  __m128i v8; // xmm0
  long double v9; // st7
  const btDbvtNode *m_root; // edi
  float v11; // [esp+4A8h] [ebp-D0h]
  btSoftColliders::CollideCL_RS v12; // [esp+4ACh] [ebp-CCh] BYREF
  float v13; // [esp+4C8h] [ebp-B0h]
  float vol; // [esp+4CCh] [ebp-ACh]
  float vol_4; // [esp+4D0h] [ebp-A8h]
  btDbvtAabbMm vol_12; // [esp+4D8h] [ebp-A0h] BYREF
  unsigned __int64 v17; // [esp+508h] [ebp-70h]
  unsigned __int64 v18; // [esp+510h] [ebp-68h]
  __m128i v19; // [esp+518h] [ebp-60h] BYREF
  __m128i v20[4]; // [esp+528h] [ebp-50h] BYREF
  unsigned __int64 v21; // [esp+568h] [ebp-10h]
  unsigned __int64 v22; // [esp+570h] [ebp-8h]

  if ( (pco->m_cfg.collisions & 0xF) == 1 )
  {
    m_internalType = pcoa->m_internalType;
    m_collisionShape = pco->m_collisionShape;
    v5 = m_collisionShape->__vftable;
    v17 = pcoa->m_worldTransform.m_origin.mVec128.m128_u64[0];
    v18 = pcoa->m_worldTransform.m_origin.mVec128.m128_u64[1];
    v21 = pcoa->m_worldTransform.m_origin.mVec128.m128_u64[0];
    v22 = pcoa->m_worldTransform.m_origin.mVec128.m128_u64[1];
    v6 = m_internalType & 2;
    getMargin = v5->getMargin;
    v13 = *(float *)&v17 - *(float *)&v21;
    vol = *((float *)&v17 + 1) - *((float *)&v21 + 1);
    vol_4 = *(float *)&v18 - *(float *)&v22;
    v11 = getMargin(m_collisionShape);
    pcoa->m_collisionShape->getAabb(
      pcoa->m_collisionShape,
      &pcoa->m_worldTransform,
      (btVector3 *)&v19,
      (btVector3 *)v20);
    v8 = _mm_load_si128(&v19);
    vol_12.mi.mVec128.m128_i32[3] = v8.m128i_i32[3];
    vol_12.mi.mVec128.m128_f32[0] = *(float *)v19.m128i_i32 - v11;
    vol_12.mx = (btVector3)_mm_load_si128(v20);
    vol_12.mi.mVec128.m128_f32[1] = *(float *)&v8.m128i_i32[1] - v11;
    vol_12.mi.mVec128.m128_f32[2] = *(float *)&v8.m128i_i32[2] - v11;
    LODWORD(v12.erp) = pco;
    LODWORD(v12.idt) = pcoa;
    vol_12.mx.mVec128.m128_f32[0] = vol_12.mx.mVec128.m128_f32[0] + v11;
    LODWORD(v12.m_margin) = v6 != 0 ? pcoa : 0;
    vol_12.mx.mVec128.m128_f32[1] = vol_12.mx.mVec128.m128_f32[1] + v11;
    vol_12.mx.mVec128.m128_f32[2] = v11 + vol_12.mx.mVec128.m128_f32[2];
    v9 = sqrtf((float)((float)(vol_4 * vol_4) + (float)(vol * vol)) + (float)(v13 * v13));
    m_root = pco->m_ndbvt.m_root;
    v12.friction = v9 + v11;
    v12.threshold = v11;
    if ( m_root )
      btDbvt::collideTV<btSoftColliders::CollideSDF_RS>(&vol_12, m_root, (btSoftColliders::CollideSDF_RS *)&v12);
  }
  else if ( (pco->m_cfg.collisions & 0xF) == 2 )
  {
    LODWORD(v12.erp) = clear_value;
    memset(&v12.idt, 0, 16);
    btSoftColliders::CollideCL_RS::Process(&v12, pcoa, pco);
  }
}
