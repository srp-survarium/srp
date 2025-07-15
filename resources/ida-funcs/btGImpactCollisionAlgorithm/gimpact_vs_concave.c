void __userpurge btGImpactCollisionAlgorithm::gimpact_vs_concave(
        btGImpactCollisionAlgorithm *this@<eax>,
        btCollisionObject *body1@<ecx>,
        btCollisionObject *body0,
        btGImpactShapeInterface *shape0,
        btConcaveShape *shape1,
        bool swapped)
{
  btConcaveShape_vtbl *v8; // eax
  btTransform *v9; // ecx
  float *v10; // eax
  float v11; // xmm5_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm7_4
  float v18; // xmm6_4
  float v19; // xmm7_4
  float v20; // xmm3_4
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm6_4
  float v24; // xmm5_4
  float v25; // xmm4_4
  float v26; // xmm6_4
  float v27; // xmm5_4
  float v28; // xmm6_4
  float v29; // xmm3_4
  float v30; // xmm6_4
  float v31; // xmm7_4
  float v32; // xmm5_4
  float v33; // xmm6_4
  float v34; // xmm7_4
  float v35; // xmm7_4
  float v36; // xmm6_4
  float v37; // xmm5_4
  float v38; // xmm7_4
  float v39; // xmm5_4
  float v40; // xmm6_4
  float v41; // xmm5_4
  float v42; // xmm6_4
  float v43; // xmm7_4
  float v44; // xmm5_4
  float v45; // xmm7_4
  float v46; // xmm5_4
  float v47; // xmm6_4
  float v48; // xmm7_4
  float v49; // xmm4_4
  float v50; // xmm6_4
  float v51; // xmm0_4
  btGImpactShapeInterface_vtbl *v52; // eax
  const float *v53; // [esp+0h] [ebp-130h]
  float v54; // [esp+Ch] [ebp-124h] BYREF
  btMatrix3x3 v55; // [esp+10h] [ebp-120h] BYREF
  _DWORD v56[5]; // [esp+44h] [ebp-ECh] BYREF
  bool v57; // [esp+58h] [ebp-D8h]
  float v58; // [esp+5Ch] [ebp-D4h]
  btVector3 v59; // [esp+60h] [ebp-D0h] BYREF
  btVector3 v60; // [esp+70h] [ebp-C0h] BYREF
  _DWORD v61[12]; // [esp+80h] [ebp-B0h] BYREF
  _DWORD v62[12]; // [esp+B0h] [ebp-80h] BYREF
  btVector3 v63; // [esp+E0h] [ebp-50h]
  btTransform v64; // [esp+F0h] [ebp-40h] BYREF

  v56[1] = this;
  v56[4] = shape0;
  v57 = swapped;
  v8 = shape1->__vftable;
  v56[0] = &btGImpactTriangleCallback::`vftable';
  v56[2] = body0;
  v56[3] = body1;
  v58 = v8->getMargin(shape1);
  v10 = (float *)btTransform::inverse(v9, (int)&body1->m_worldTransform, &v64);
  v11 = body0->m_worldTransform.m_origin.mVec128.m128_f32[1];
  v12 = body0->m_worldTransform.m_origin.mVec128.m128_f32[0];
  v13 = v10[1];
  v14 = *v10;
  v15 = body0->m_worldTransform.m_origin.mVec128.m128_f32[2];
  v16 = v10[2];
  v17 = v10[6];
  v55.m_el[2].mVec128.m128_f32[0] = (float)((float)((float)(*v10 * v12) + (float)(v13 * v11)) + (float)(v16 * v15))
                                  + v10[12];
  v18 = (float)(v10[5] * v11) + (float)(v17 * v15);
  v19 = v12 * v10[4];
  v20 = v12 * v10[8];
  v21 = (float)(v18 + v19) + v10[13];
  v22 = v10[10];
  v55.m_el[2].mVec128.m128_f32[1] = v21;
  v23 = v10[9] * v11;
  v24 = v10[10] * v15;
  v25 = body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
  v26 = v23 + v24;
  v27 = body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2];
  v55.m_el[2].mVec128.m128_f32[2] = (float)(v26 + v20) + v10[14];
  v28 = v10[9] * v25;
  v55.m_el[2].mVec128.m128_i32[3] = 0;
  v29 = body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2];
  v30 = v28 + (float)(v22 * v29);
  v31 = v10[8] * v27;
  v32 = body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1];
  v33 = v30 + v31;
  v34 = v10[9];
  v55.m_el[1].mVec128.m128_f32[1] = v33;
  v35 = (float)((float)(v34 * body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]) + (float)(v10[10] * v32))
      + (float)(v10[8] * body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]);
  v36 = body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0];
  v37 = body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
  v55.m_el[0].mVec128.m128_f32[1] = v35;
  v38 = (float)((float)(v10[9] * v36) + (float)(v10[10] * v37))
      + (float)(v10[8] * body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0]);
  v39 = body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1];
  v55.m_el[1].mVec128.m128_f32[2] = (float)((float)(v10[5] * v25) + (float)(v10[6] * v29))
                                  + (float)(body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v10[4]);
  v40 = v10[5] * v39;
  v41 = body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1];
  v55.m_el[1].mVec128.m128_f32[3] = v38;
  v42 = v40 + (float)(v10[6] * v41);
  v43 = v10[5];
  v44 = body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0];
  v55.m_el[1].mVec128.m128_f32[0] = v42 + (float)(body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v10[4]);
  v45 = v43 * v44;
  v46 = body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
  v47 = body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2];
  v55.m_el[0].mVec128.m128_f32[2] = (float)(v45 + (float)(v10[6] * v46))
                                  + (float)(body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v10[4]);
  v48 = (float)((float)(v14 * v47) + (float)(v13 * v25)) + (float)(v16 * v29);
  v49 = (float)(v16 * body0->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1])
      + (float)(v14 * body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]);
  v50 = v13 * body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1];
  v51 = (float)((float)(v14 * body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
              + (float)(v13 * body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0]))
      + (float)(v16 * v46);
  v55.m_el[0].mVec128.m128_f32[3] = v48;
  v54 = v49 + v50;
  v55.m_el[0].mVec128.m128_f32[0] = v51;
  btMatrix3x3::setValue(
    &v55,
    (int)v61,
    &v54,
    &v55.m_el[0].mVec128.m128_f32[3],
    &v55.m_el[0].mVec128.m128_f32[2],
    v55.m_el[1].mVec128.m128_f32,
    &v55.m_el[1].mVec128.m128_f32[2],
    &v55.m_el[1].mVec128.m128_f32[3],
    &v55.m_el[0].mVec128.m128_f32[1],
    &v55.m_el[1].mVec128.m128_f32[1],
    v53);
  v62[0] = v61[0];
  v62[1] = v61[1];
  v62[2] = v61[2];
  v62[3] = v61[3];
  v62[4] = v61[4];
  v62[5] = v61[5];
  v62[6] = v61[6];
  v62[7] = v61[7];
  v62[8] = v61[8];
  v62[9] = v61[9];
  v52 = shape0->__vftable;
  v62[10] = v61[10];
  v62[11] = v61[11];
  v63.mVec128 = (__m128)v55.m_el[2];
  v52->getAabb(shape0, (const btTransform *)v62, &v59, &v60);
  shape1->processAllTriangles(shape1, (btTriangleCallback *)v56, &v59, &v60);
}
