void __thiscall btGImpactCollisionAlgorithm::gimpacttrimeshpart_vs_plane_collision(
        btGImpactCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        btCollisionObject *shape0,
        btStaticPlaneShape *shape1,
        float *swapped,
        char a7)
{
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  btStaticPlaneShape *v14; // esi
  btStaticPlaneShape_vtbl *v15; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm4_4
  float v21; // xmm3_4
  float v22; // xmm5_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm0_4
  btGImpactCollisionAlgorithm *v26; // ecx
  double v27; // st7
  int v28; // ebx
  int v29; // eax
  float v30; // xmm3_4
  double v31; // xmm0_8
  float v32; // xmm4_4
  float v33; // xmm5_4
  float v34; // [esp+1Ch] [ebp-D4h]
  float v35; // [esp+1Ch] [ebp-D4h]
  float v36; // [esp+1Ch] [ebp-D4h]
  btVector3 v37; // [esp+20h] [ebp-D0h] BYREF
  btVector3 v38; // [esp+30h] [ebp-C0h] BYREF
  float v39; // [esp+4Ch] [ebp-A4h]
  unsigned __int64 v40; // [esp+50h] [ebp-A0h] BYREF
  unsigned __int64 v41; // [esp+58h] [ebp-98h]
  btVector3 v42; // [esp+60h] [ebp-90h] BYREF
  btVector3 v43; // [esp+70h] [ebp-80h]
  btVector3 v44; // [esp+80h] [ebp-70h]
  btVector3 v45; // [esp+90h] [ebp-60h] BYREF
  btVector3 v46; // [esp+A0h] [ebp-50h]
  btTransform m_worldTransform; // [esp+B0h] [ebp-40h] BYREF

  m_worldTransform = body1->m_worldTransform;
  v40 = shape0->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
  v41 = shape0->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
  v42.mVec128 = (__m128)shape0->m_worldTransform.m_basis.m_el[1];
  v43.mVec128 = (__m128)shape0->m_worldTransform.m_basis.m_el[2];
  v8 = swapped[14];
  v9 = swapped[13];
  v44.mVec128 = (__m128)shape0->m_worldTransform.m_origin;
  v10 = (float)((float)(v8 * *(float *)&v41) + (float)(v9 * *((float *)&v40 + 1)))
      + (float)(*(float *)&v40 * swapped[12]);
  v11 = swapped[14] * v42.mVec128.m128_f32[2];
  v37.mVec128.m128_f32[0] = v10;
  v12 = (float)((float)(swapped[13] * v42.mVec128.m128_f32[1]) + v11) + (float)(v42.mVec128.m128_f32[0] * swapped[12]);
  v13 = swapped[14] * v43.mVec128.m128_f32[2];
  v37.mVec128.m128_f32[1] = v12;
  v14 = shape1;
  v15 = shape1->__vftable;
  v16 = (float)((float)(swapped[13] * v43.mVec128.m128_f32[1]) + v13) + (float)(v43.mVec128.m128_f32[0] * swapped[12]);
  v17 = swapped[14] * v44.mVec128.m128_f32[2];
  v37.mVec128.m128_f32[2] = v16;
  v37.mVec128.m128_f32[3] = (float)((float)((float)(swapped[13] * v44.mVec128.m128_f32[1]) + v17)
                                  + (float)(swapped[12] * v44.mVec128.m128_f32[0]))
                          + swapped[16];
  v15->getAabb(shape1, &m_worldTransform, (btVector3 *)&v40, &v42);
  v34 = ((double (__thiscall *)(float *))*(_DWORD *)(*(_DWORD *)swapped + 40))(swapped);
  v18 = (float)(v42.mVec128.m128_f32[0] + v34) + (float)(*(float *)&v40 - v34);
  *(float *)&v40 = *(float *)&v40 - v34;
  v19 = (float)(v42.mVec128.m128_f32[1] + v34) + (float)(*((float *)&v40 + 1) - v34);
  *((float *)&v40 + 1) = *((float *)&v40 + 1) - v34;
  *(float *)&v41 = *(float *)&v41 - v34;
  v42.mVec128.m128_f32[1] = v42.mVec128.m128_f32[1] + v34;
  v20 = v19 * 0.5;
  v21 = v18 * 0.5;
  v22 = (float)((float)(v42.mVec128.m128_f32[2] + v34) + *(float *)&v41) * 0.5;
  v42.mVec128.m128_f32[0] = v42.mVec128.m128_f32[0] + v34;
  v45.mVec128.m128_f32[1] = v42.mVec128.m128_f32[1] - v20;
  v42.mVec128.m128_f32[2] = v42.mVec128.m128_f32[2] + v34;
  v23 = v42.mVec128.m128_f32[2] - v22;
  v24 = (float)((float)(v22 * v16) + (float)(v20 * v37.mVec128.m128_f32[1])) + (float)(v21 * v37.mVec128.m128_f32[0]);
  v25 = (float)((float)(COERCE_FLOAT(LODWORD(v16) & _mask__AbsFloat_) * v23)
              + (float)(COERCE_FLOAT(v37.mVec128.m128_i32[1] & _mask__AbsFloat_) * (float)(v42.mVec128.m128_f32[1] - v20)))
      + (float)(COERCE_FLOAT(v37.mVec128.m128_i32[0] & _mask__AbsFloat_) * (float)(v42.mVec128.m128_f32[0] - v21));
  if ( v37.mVec128.m128_f32[3] <= (float)((float)(v25 + v24) + 0.000001)
    && (float)(v37.mVec128.m128_f32[3] + 0.000001) >= (float)(v24 - v25) )
  {
    shape1->__vftable[1].calculateSerializeBufferSize(shape1);
    v35 = shape1->getMargin(shape1);
    v27 = ((double (__thiscall *)(float *))*(_DWORD *)(*(_DWORD *)swapped + 40))(swapped);
    v28 = shape1[2].m_localAabbMin.mVec128.m128_i32[3];
    v39 = v27 + v35;
    if ( v28 )
    {
      v46.mVec128.m128_i32[3] = 0;
      do
      {
        v29 = v14[2].m_localAabbMin.mVec128.m128_i32[2] + --v28 * v14[2].m_localAabbMax.mVec128.m128_i32[1];
        if ( v14[2].m_localAabbMax.mVec128.m128_i32[0] == 1 )
        {
          v30 = *(float *)&v14[2].__vftable * *(double *)v29;
          v31 = *(float *)&v14[2].m_shapeType;
          v38.mVec128.m128_f32[0] = v30;
          v32 = v31 * *(double *)(v29 + 8);
          LODWORD(v31) = v14[2].m_userPointer;
          v38.mVec128.m128_f32[1] = v32;
          v33 = *(float *)&v31 * *(double *)(v29 + 16);
        }
        else
        {
          v30 = *(float *)&v14[2].__vftable * *(float *)v29;
          v38.mVec128.m128_f32[0] = v30;
          v32 = *(float *)(v29 + 4) * *(float *)&v14[2].m_shapeType;
          v38.mVec128.m128_f32[1] = v32;
          v33 = *(float *)(v29 + 8) * *(float *)&v14[2].m_userPointer;
        }
        v46.mVec128.m128_f32[0] = (float)((float)((float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v33)
                                                + (float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v32))
                                        + (float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v30))
                                + m_worldTransform.m_origin.mVec128.m128_f32[0];
        v46.mVec128.m128_f32[1] = (float)((float)((float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v33)
                                                + (float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v32))
                                        + (float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v30))
                                + m_worldTransform.m_origin.mVec128.m128_f32[1];
        v46.mVec128.m128_f32[2] = (float)((float)((float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v32)
                                                + (float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v33))
                                        + (float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v30))
                                + m_worldTransform.m_origin.mVec128.m128_f32[2];
        v38.mVec128 = v46.mVec128;
        v36 = (float)((float)((float)((float)(v46.mVec128.m128_f32[2] * v37.mVec128.m128_f32[2])
                                    + (float)(v46.mVec128.m128_f32[1] * v37.mVec128.m128_f32[1]))
                            + (float)(v46.mVec128.m128_f32[0] * v37.mVec128.m128_f32[0]))
                    - v37.mVec128.m128_f32[3])
            - v39;
        if ( v36 < 0.0 )
        {
          if ( a7 )
          {
            v45.mVec128.m128_i32[0] = v37.mVec128.m128_i32[0] ^ _mask__NegFloat_;
            v45.mVec128.m128_i32[1] = v37.mVec128.m128_i32[1] ^ _mask__NegFloat_;
            v45.mVec128.m128_u64[1] = v37.mVec128.m128_u32[2] ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
            btGImpactCollisionAlgorithm::addContactPoint(v26, (int)body0, shape0, body1, &v38, &v45, v36);
          }
          else
          {
            btGImpactCollisionAlgorithm::addContactPoint(v26, (int)body0, body1, shape0, &v38, &v37, v36);
          }
        }
        v14 = shape1;
      }
      while ( v28 );
    }
    ((void (__thiscall *)(btStaticPlaneShape *))v14->__vftable[1].serialize)(v14);
  }
}
