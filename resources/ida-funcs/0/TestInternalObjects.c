bool __usercall TestInternalObjects@<al>(
        const btTransform *trans1@<eax>,
        const btVector3 *delta_c@<esi>,
        const btVector3 *axis@<edx>,
        const btConvexPolyhedron *convex0@<edi>,
        const btTransform *trans0,
        const btConvexPolyhedron *convex1,
        float dmin)
{
  float v7; // xmm6_4
  float v8; // xmm5_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm1_4
  float v14; // xmm5_4
  int v15; // xmm6_4
  int v16; // xmm6_4
  int v17; // xmm6_4
  int v18; // xmm6_4
  float v19; // xmm6_4
  float v20; // xmm0_4
  float m_radius; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v28; // [esp+0h] [ebp-1Ch]
  float v29; // [esp+4h] [ebp-18h]
  float v30; // [esp+8h] [ebp-14h]
  float v31; // [esp+Ch] [ebp-10h]
  float v32; // [esp+10h] [ebp-Ch]
  float v33; // [esp+18h] [ebp-4h]

  v7 = axis->mVec128.m128_f32[2];
  v8 = axis->mVec128.m128_f32[1];
  v28 = (float)((float)(delta_c->mVec128.m128_f32[1] * v8) + (float)(delta_c->mVec128.m128_f32[2] * v7))
      + (float)(delta_c->mVec128.m128_f32[0] * axis->mVec128.m128_f32[0]);
  v9 = (float)((float)(v7 * trans0->m_basis.m_el[2].mVec128.m128_f32[0])
             + (float)(trans0->m_basis.m_el[0].mVec128.m128_f32[0] * axis->mVec128.m128_f32[0]))
     + (float)(v8 * trans0->m_basis.m_el[1].mVec128.m128_f32[0]);
  v10 = (float)((float)(trans0->m_basis.m_el[1].mVec128.m128_f32[1] * v8)
              + (float)(trans0->m_basis.m_el[2].mVec128.m128_f32[1] * v7))
      + (float)(trans0->m_basis.m_el[0].mVec128.m128_f32[1] * axis->mVec128.m128_f32[0]);
  v11 = (float)((float)(trans0->m_basis.m_el[1].mVec128.m128_f32[2] * v8)
              + (float)(trans0->m_basis.m_el[2].mVec128.m128_f32[2] * v7))
      + (float)(trans0->m_basis.m_el[0].mVec128.m128_f32[2] * axis->mVec128.m128_f32[0]);
  v12 = (float)((float)(trans1->m_basis.m_el[0].mVec128.m128_f32[0] * axis->mVec128.m128_f32[0])
              + (float)(trans1->m_basis.m_el[2].mVec128.m128_f32[0] * v7))
      + (float)(v8 * trans1->m_basis.m_el[1].mVec128.m128_f32[0]);
  v13 = (float)((float)(trans1->m_basis.m_el[1].mVec128.m128_f32[1] * v8)
              + (float)(trans1->m_basis.m_el[2].mVec128.m128_f32[1] * v7))
      + (float)(trans1->m_basis.m_el[0].mVec128.m128_f32[1] * axis->mVec128.m128_f32[0]);
  v14 = (float)((float)(trans1->m_basis.m_el[1].mVec128.m128_f32[2] * v8)
              + (float)(trans1->m_basis.m_el[2].mVec128.m128_f32[2] * v7))
      + (float)(trans1->m_basis.m_el[0].mVec128.m128_f32[2] * axis->mVec128.m128_f32[0]);
  v15 = convex0->m_extents.mVec128.m128_i32[0];
  if ( v9 < 0.0 )
    v15 ^= _mask__NegFloat_;
  v29 = *(float *)&v15;
  v16 = convex0->m_extents.mVec128.m128_i32[1];
  if ( v10 < 0.0 )
    v16 ^= _mask__NegFloat_;
  v30 = *(float *)&v16;
  v17 = convex0->m_extents.mVec128.m128_i32[2];
  if ( v11 < 0.0 )
    v17 ^= _mask__NegFloat_;
  v31 = *(float *)&v17;
  v18 = convex1->m_extents.mVec128.m128_i32[0];
  if ( v12 < 0.0 )
    v18 ^= _mask__NegFloat_;
  v32 = *(float *)&v18;
  v19 = convex1->m_extents.mVec128.m128_f32[1];
  if ( v13 < 0.0 )
    LODWORD(v19) ^= _mask__NegFloat_;
  if ( v14 >= 0.0 )
    v33 = convex1->m_extents.mVec128.m128_f32[2];
  else
    LODWORD(v33) = convex1->m_extents.mVec128.m128_i32[2] ^ _mask__NegFloat_;
  v20 = (float)((float)(v9 * v29) + (float)(v11 * v31)) + (float)(v10 * v30);
  m_radius = convex0->m_radius;
  v22 = (float)((float)(v13 * v19) + (float)(v14 * v33)) + (float)(v12 * v32);
  if ( v20 > m_radius )
    m_radius = v20;
  v23 = convex1->m_radius;
  if ( v22 > v23 )
    v23 = v22;
  v24 = v23 + m_radius;
  v25 = v24 + v28;
  v26 = v24 - v28;
  if ( v26 > v25 )
    v26 = v25;
  return v26 <= dmin;
}
