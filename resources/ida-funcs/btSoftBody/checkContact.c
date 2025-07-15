char __userpurge btSoftBody::checkContact@<al>(
        btSoftBody *this@<ecx>,
        float a2@<xmm10>,
        btCollisionObject *colObj,
        const btVector3 *x,
        float *margin,
        btSoftBody::sCti *cti,
        btVector3 *a6)
{
  btVector3 *v7; // esi
  int v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  btCollisionShape *shape; // [esp+20h] [ebp-54h]
  btVector3 normal; // [esp+24h] [ebp-50h] BYREF
  btVector3 xa; // [esp+34h] [ebp-40h]
  btMatrix3x3 v17; // [esp+44h] [ebp-30h] BYREF

  shape = (btCollisionShape *)x[12].mVec128.m128_i32[3];
  if ( ((x[15].mVec128.m128_i8[4] & 2) != 0 ? (unsigned int)x : 0) != 0 )
    v7 = (x[15].mVec128.m128_i8[4] & 2) != 0 ? (btVector3 *)&x[1] : (btVector3 *)16;
  else
    v7 = (btVector3 *)&x[1];
  normal.mVec128.m128_f32[0] = *margin - v7[3].mVec128.m128_f32[0];
  normal.mVec128.m128_f32[1] = margin[1] - v7[3].mVec128.m128_f32[1];
  normal.mVec128.m128_f32[2] = margin[2] - v7[3].mVec128.m128_f32[2];
  btMatrix3x3::btMatrix3x3(
    (btMatrix3x3 *)v7,
    &v17,
    v7[1].mVec128.m128_f32,
    v7[2].mVec128.m128_f32,
    &v7->mVec128.m128_f32[1],
    &v7[1].mVec128.m128_f32[1],
    &v7[2].mVec128.m128_f32[1],
    &v7->mVec128.m128_f32[2],
    &v7[1].mVec128.m128_f32[2],
    &v7[2].mVec128.m128_f32[2]);
  xa.mVec128.m128_f32[0] = (float)((float)(v17.m_el[0].mVec128.m128_f32[2] * normal.mVec128.m128_f32[2])
                                 + (float)(v17.m_el[0].mVec128.m128_f32[0] * normal.mVec128.m128_f32[0]))
                         + (float)(v17.m_el[0].mVec128.m128_f32[1] * normal.mVec128.m128_f32[1]);
  xa.mVec128.m128_f32[1] = (float)((float)(v17.m_el[1].mVec128.m128_f32[2] * normal.mVec128.m128_f32[2])
                                 + (float)(v17.m_el[1].mVec128.m128_f32[0] * normal.mVec128.m128_f32[0]))
                         + (float)(v17.m_el[1].mVec128.m128_f32[1] * normal.mVec128.m128_f32[1]);
  v8 = colObj[2].m_interpolationLinearVelocity.mVec128.m128_i32[1];
  xa.mVec128.m128_f32[2] = (float)((float)(v17.m_el[2].mVec128.m128_f32[2] * normal.mVec128.m128_f32[2])
                                 + (float)(v17.m_el[2].mVec128.m128_f32[0] * normal.mVec128.m128_f32[0]))
                         + (float)(v17.m_el[2].mVec128.m128_f32[1] * normal.mVec128.m128_f32[1]);
  xa.mVec128.m128_i32[3] = 0;
  v9 = btSparseSdf<3>::Evaluate((btSparseSdf<3> *)(v8 + 64), a2, shape, &normal, *(float *)&cti);
  if ( v9 >= 0.0 )
    return 0;
  a6->mVec128.m128_i32[0] = (int)x;
  v10 = v7[1].mVec128.m128_f32[2] * normal.mVec128.m128_f32[2];
  xa.mVec128.m128_f32[0] = (float)((float)(v7->mVec128.m128_f32[1] * normal.mVec128.m128_f32[1])
                                 + (float)(v7->mVec128.m128_f32[2] * normal.mVec128.m128_f32[2]))
                         + (float)(v7->mVec128.m128_f32[0] * normal.mVec128.m128_f32[0]);
  v11 = (float)((float)(v7[1].mVec128.m128_f32[1] * normal.mVec128.m128_f32[1]) + v10)
      + (float)(v7[1].mVec128.m128_f32[0] * normal.mVec128.m128_f32[0]);
  v12 = v7[2].mVec128.m128_f32[2] * normal.mVec128.m128_f32[2];
  xa.mVec128.m128_f32[1] = v11;
  xa.mVec128.m128_f32[2] = (float)((float)(v7[2].mVec128.m128_f32[1] * normal.mVec128.m128_f32[1]) + v12)
                         + (float)(v7[2].mVec128.m128_f32[0] * normal.mVec128.m128_f32[0]);
  xa.mVec128.m128_i32[3] = 0;
  a6[1] = (btVector3)xa.mVec128;
  a6[2].mVec128.m128_i32[0] = COERCE_UNSIGNED_INT(
                                (float)((float)(a6[1].mVec128.m128_f32[2]
                                              * (float)(margin[2] - (float)(a6[1].mVec128.m128_f32[2] * v9)))
                                      + (float)(a6[1].mVec128.m128_f32[1]
                                              * (float)(margin[1] - (float)(a6[1].mVec128.m128_f32[1] * v9))))
                              + (float)((float)(*margin - (float)(a6[1].mVec128.m128_f32[0] * v9))
                                      * a6[1].mVec128.m128_f32[0]))
                            ^ _mask__NegFloat_;
  return 1;
}
