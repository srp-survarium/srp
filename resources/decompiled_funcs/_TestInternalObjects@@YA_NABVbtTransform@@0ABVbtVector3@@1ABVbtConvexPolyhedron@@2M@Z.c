bool __usercall TestInternalObjects@<al>(
        const btTransform *trans1@<eax>,
        const btVector3 *delta_c@<esi>,
        const btVector3 *axis@<edx>,
        const btConvexPolyhedron *convex0@<edi>,
        const btTransform *trans0,
        const btConvexPolyhedron *convex1,
        float dmin)
{
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm1_4
  float v13; // xmm7_4
  float v14; // xmm2_4
  float v15; // xmm2_4
  float v16; // xmm2_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float m_radius; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v27; // [esp+68h] [ebp-20h]
  float v28; // [esp+6Ch] [ebp-1Ch]
  float v29; // [esp+70h] [ebp-18h]
  float v30; // [esp+74h] [ebp-14h]
  float v31; // [esp+78h] [ebp-10h]
  float v32; // [esp+78h] [ebp-10h]
  float v33; // [esp+80h] [ebp-8h]

  v7 = axis->mVec128.m128_f32[2];
  v8 = axis->mVec128.m128_f32[1];
  v27 = (float)((float)(delta_c->mVec128.m128_f32[1] * v8) + (float)(delta_c->mVec128.m128_f32[2] * v7))
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
  v31 = (float)((float)(trans1->m_basis.m_el[0].mVec128.m128_f32[0] * axis->mVec128.m128_f32[0])
              + (float)(trans1->m_basis.m_el[2].mVec128.m128_f32[0] * v7))
      + (float)(v8 * trans1->m_basis.m_el[1].mVec128.m128_f32[0]);
  v12 = (float)((float)(trans1->m_basis.m_el[1].mVec128.m128_f32[1] * v8)
              + (float)(trans1->m_basis.m_el[2].mVec128.m128_f32[1] * v7))
      + (float)(trans1->m_basis.m_el[0].mVec128.m128_f32[1] * axis->mVec128.m128_f32[0]);
  v13 = (float)((float)(trans1->m_basis.m_el[1].mVec128.m128_f32[2] * v8)
              + (float)(trans1->m_basis.m_el[2].mVec128.m128_f32[2] * v7))
      + (float)(trans1->m_basis.m_el[0].mVec128.m128_f32[2] * axis->mVec128.m128_f32[0]);
  v14 = convex0->m_extents.mVec128.m128_f32[0];
  if ( v9 < 0.0 )
    v14 = -v14;
  v28 = v14;
  v15 = convex0->m_extents.mVec128.m128_f32[1];
  if ( v10 < 0.0 )
    v15 = -v15;
  v29 = v15;
  v16 = convex0->m_extents.mVec128.m128_f32[2];
  if ( v11 < 0.0 )
    v16 = -v16;
  v30 = v16;
  v17 = v31;
  if ( v31 >= 0.0 )
    v32 = convex1->m_extents.mVec128.m128_f32[0];
  else
    v32 = -convex1->m_extents.mVec128.m128_f32[0];
  v18 = convex1->m_extents.mVec128.m128_f32[1];
  if ( v12 < 0.0 )
    v18 = -v18;
  if ( v13 >= 0.0 )
    v33 = convex1->m_extents.mVec128.m128_f32[2];
  else
    v33 = -convex1->m_extents.mVec128.m128_f32[2];
  v19 = (float)((float)(v12 * v18) + (float)(v13 * v33)) + (float)(v17 * v32);
  m_radius = convex0->m_radius;
  v21 = (float)((float)(v9 * v28) + (float)(v11 * v30)) + (float)(v10 * v29);
  if ( v21 > m_radius )
    m_radius = v21;
  v22 = convex1->m_radius;
  if ( v19 > v22 )
    v22 = v19;
  v23 = v22 + m_radius;
  v24 = v23 + v27;
  v25 = v23 - v27;
  if ( v25 > v24 )
    v25 = v24;
  return v25 <= dmin;
}
