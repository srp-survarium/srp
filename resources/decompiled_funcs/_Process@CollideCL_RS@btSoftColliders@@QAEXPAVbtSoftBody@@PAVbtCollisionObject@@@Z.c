void __userpurge btSoftColliders::CollideCL_RS::Process(
        btSoftColliders::CollideCL_RS *this@<esi>,
        btCollisionObject *colOb@<eax>,
        btSoftBody *ps)
{
  btCollisionShape *m_collisionShape; // ecx
  btCollisionShape_vtbl *v5; // edx
  double v6; // st7
  float v7; // ecx
  double v8; // st7
  btSoftBody *psb; // eax
  btCollisionObject *m_colObj; // ecx
  float *p_kDF; // eax
  bool v12; // cc
  btVector3 v13; // xmm0
  btDbvtNode *m_root; // ebx
  float v15[7]; // [esp+94h] [ebp-4Ch] BYREF
  __m128i v16; // [esp+B0h] [ebp-30h] BYREF
  btDbvtAabbMm vol; // [esp+C0h] [ebp-20h] BYREF

  this->psb = ps;
  this->m_colObj = colOb;
  this->idt = ps->m_sst.isdt;
  m_collisionShape = colOb->m_collisionShape;
  v5 = m_collisionShape->__vftable;
  v15[2] = *(float *)&ps->m_collisionShape;
  v6 = ((double (__thiscall *)(btCollisionShape *))v5->getMargin)(m_collisionShape);
  v7 = v15[2];
  v15[2] = v6;
  v8 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)LODWORD(v7) + 40))(LODWORD(v7));
  psb = this->psb;
  m_colObj = this->m_colObj;
  this->m_margin = v8 + v15[2];
  p_kDF = &psb->m_cfg.kDF;
  v12 = m_colObj->m_friction <= *p_kDF;
  v15[2] = m_colObj->m_friction;
  if ( v12 )
    p_kDF = &v15[2];
  this->friction = *p_kDF;
  colOb->m_collisionShape->getAabb(
    colOb->m_collisionShape,
    &colOb->m_worldTransform,
    (btVector3 *)&v15[3],
    (btVector3 *)&v16);
  v13.mVec128 = (__m128)_mm_load_si128((const __m128i *)&v15[3]);
  m_root = ps->m_cdbvt.m_root;
  vol.mx = (btVector3)_mm_load_si128(&v16);
  vol.mi = (btVector3)v13.mVec128;
  v13.mVec128.m128_i32[0] = LODWORD(this->m_margin);
  vol.mi.mVec128.m128_f32[0] = v15[3] - v13.mVec128.m128_f32[0];
  vol.mi.mVec128.m128_f32[1] = vol.mi.mVec128.m128_f32[1] - v13.mVec128.m128_f32[0];
  vol.mi.mVec128.m128_f32[2] = vol.mi.mVec128.m128_f32[2] - v13.mVec128.m128_f32[0];
  vol.mx.mVec128.m128_f32[1] = vol.mx.mVec128.m128_f32[1] + v13.mVec128.m128_f32[0];
  vol.mx.mVec128.m128_f32[0] = vol.mx.mVec128.m128_f32[0] + v13.mVec128.m128_f32[0];
  vol.mx.mVec128.m128_f32[2] = vol.mx.mVec128.m128_f32[2] + v13.mVec128.m128_f32[0];
  if ( m_root )
    btDbvt::collideTV<btSoftColliders::CollideCL_RS>(m_root, &vol, this);
}
