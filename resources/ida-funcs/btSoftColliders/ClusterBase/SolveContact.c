char __userpurge btSoftColliders::ClusterBase::SolveContact@<al>(
        btSoftColliders::ClusterBase *this@<ecx>,
        const btVector3 *a2@<edi>,
        const btGjkEpaSolver2::sResults *res,
        btSoftBody::Body ba,
        btSoftBody::Body bb,
        btSoftBody::CJoint *joint,
        int a7)
{
  int v7; // ebx
  float v8; // xmm0_4
  btVector3 *p_m_origin; // eax
  btSoftBody::Body *v10; // ecx
  btVector3 *v11; // eax
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm5_4
  float v15; // xmm6_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm4_4
  btSoftBody::Body *v20; // ecx
  float *v21; // eax
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  btSoftBody::Body *v25; // ecx
  float *v26; // eax
  btSoftBody::Body *v27; // ecx
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm2_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  const btMatrix3x3 *v35; // xmm0_4
  float v36; // xmm2_4
  btSoftBody::Body *v37; // ecx
  btSoftBody::Body *v38; // ecx
  const btMatrix3x3 *v39; // eax
  btSoftBody::Body *v40; // ecx
  btSoftBody::Body *v42; // [esp+4h] [ebp-C0h]
  const btMatrix3x3 *v43; // [esp+4h] [ebp-C0h]
  const btMatrix3x3 *v44; // [esp+10h] [ebp-B4h]
  const btVector3 *v45; // [esp+14h] [ebp-B0h]
  btVector3 v46; // [esp+24h] [ebp-A0h] BYREF
  float v47; // [esp+40h] [ebp-84h]
  btSoftBody::Body v48; // [esp+44h] [ebp-80h] BYREF
  int v49; // [esp+50h] [ebp-74h]
  btSoftBody::Body v50; // [esp+54h] [ebp-70h] BYREF
  int v51; // [esp+60h] [ebp-64h]
  float v52; // [esp+64h] [ebp-60h]
  float v53; // [esp+68h] [ebp-5Ch]
  float v54; // [esp+6Ch] [ebp-58h]
  int v55; // [esp+70h] [ebp-54h]
  btVector3 v56; // [esp+74h] [ebp-50h] BYREF
  float v57; // [esp+90h] [ebp-34h]
  _BYTE v58[48]; // [esp+94h] [ebp-30h] BYREF

  v7 = a7;
  if ( *((float *)&res->status + 2) <= ba.m_soft->m_framexform.m_basis.m_el[0].mVec128.m128_f32[0] )
    return 0;
  v52 = *(float *)&ba.m_soft->m_framerefs.m_capacity;
  v53 = *(float *)&ba.m_soft->m_framerefs.m_data;
  v54 = *(float *)&ba.m_soft->m_framerefs.m_ownsMemory;
  v55 = *((_DWORD *)&ba.m_soft->m_framerefs + 5);
  v8 = s_bm_current_air_resistance / fsqrt((float)((float)(v53 * v53) + (float)(v54 * v54)) + (float)(v52 * v52));
  v52 = v52 * v8;
  v53 = v53 * v8;
  v54 = v54 * v8;
  p_m_origin = &btSoftBody::Body::xform((btSoftBody::Body *)this, &ba.m_rigid)->m_origin;
  *(float *)&v50.m_soft = *(float *)&ba.m_soft->m_masses.m_ownsMemory - p_m_origin->mVec128.m128_f32[0];
  *(float *)&v50.m_rigid = *(float *)&ba.m_soft->m_nodes.m_allocator - p_m_origin->mVec128.m128_f32[1];
  *(float *)&v50.m_collisionObject = *(float *)&ba.m_soft->m_nodes.m_size - p_m_origin->mVec128.m128_f32[2];
  v51 = 0;
  v11 = &btSoftBody::Body::xform(v10, &bb.m_rigid)->m_origin;
  *(float *)&v48.m_soft = *(float *)&ba.m_soft->m_nodes.m_data - v11->mVec128.m128_f32[0];
  *(float *)&v48.m_rigid = *(float *)&ba.m_soft->m_nodes.m_ownsMemory - v11->mVec128.m128_f32[1];
  *(float *)&v48.m_collisionObject = *(float *)&ba.m_soft->m_framerefs.m_allocator - v11->mVec128.m128_f32[2];
  v49 = 0;
  btSoftBody::Body::velocity(&v50, &v46, (btVector3 *)&ba.m_rigid, a2);
  btSoftBody::Body::velocity(&v48, &v56, (btVector3 *)&bb.m_rigid, v45);
  v12 = v46.mVec128.m128_f32[1] - v56.mVec128.m128_f32[1];
  v13 = v46.mVec128.m128_f32[2] - v56.mVec128.m128_f32[2];
  v14 = v53;
  v15 = v54;
  v16 = v46.mVec128.m128_f32[0] - v56.mVec128.m128_f32[0];
  v17 = (float)((float)((float)(v46.mVec128.m128_f32[1] - v56.mVec128.m128_f32[1]) * v53)
              + (float)((float)(v46.mVec128.m128_f32[2] - v56.mVec128.m128_f32[2]) * v54))
      + (float)((float)(v46.mVec128.m128_f32[0] - v56.mVec128.m128_f32[0]) * v52);
  v18 = ba.m_soft->m_framexform.m_basis.m_el[0].mVec128.m128_f32[0] - *((float *)&res->status + 2);
  *(_DWORD *)(v7 + 16) = ba.m_rigid;
  *(_DWORD *)(v7 + 20) = ba.m_collisionObject;
  *(_DWORD *)(v7 + 24) = bb.m_soft;
  *(_DWORD *)(v7 + 28) = bb.m_rigid;
  v47 = v18;
  v19 = v52;
  *(_DWORD *)(v7 + 32) = bb.m_collisionObject;
  v57 = v17;
  v56.mVec128.m128_f32[0] = v16 - (float)(v19 * v17);
  v56.mVec128.m128_f32[1] = v12 - (float)(v14 * v17);
  v56.mVec128.m128_f32[2] = v13 - (float)(v15 * v17);
  *(_DWORD *)(v7 + 36) = joint;
  v21 = (float *)btSoftBody::Body::xform(v20, &ba.m_rigid);
  v22 = v21[5] * *(float *)&v50.m_rigid;
  v46.mVec128.m128_f32[0] = (float)((float)(v21[8] * *(float *)&v50.m_collisionObject)
                                  + (float)(v21[4] * *(float *)&v50.m_rigid))
                          + (float)(*v21 * *(float *)&v50.m_soft);
  v23 = (float)((float)(v21[9] * *(float *)&v50.m_collisionObject) + v22) + (float)(v21[1] * *(float *)&v50.m_soft);
  v24 = v21[6] * *(float *)&v50.m_rigid;
  v46.mVec128.m128_f32[1] = v23;
  v46.mVec128.m128_f32[2] = (float)((float)(v21[10] * *(float *)&v50.m_collisionObject) + v24)
                          + (float)(v21[2] * *(float *)&v50.m_soft);
  v46.mVec128.m128_i32[3] = 0;
  *(btVector3 *)(v7 + 48) = (btVector3)v46.mVec128;
  v26 = (float *)btSoftBody::Body::xform(v25, &bb.m_rigid);
  v28 = v26[5] * *(float *)&v48.m_rigid;
  v46.mVec128.m128_f32[0] = (float)((float)(v26[8] * *(float *)&v48.m_collisionObject)
                                  + (float)(v26[4] * *(float *)&v48.m_rigid))
                          + (float)(*v26 * *(float *)&v48.m_soft);
  v29 = (float)((float)(v26[9] * *(float *)&v48.m_collisionObject) + v28) + (float)(v26[1] * *(float *)&v48.m_soft);
  v30 = v26[6] * *(float *)&v48.m_rigid;
  v46.mVec128.m128_f32[1] = v29;
  v46.mVec128.m128_f32[2] = (float)((float)(v26[10] * *(float *)&v48.m_collisionObject) + v30)
                          + (float)(v26[2] * *(float *)&v48.m_soft);
  v46.mVec128.m128_i32[3] = 0;
  *(btVector3 *)(v7 + 64) = (btVector3)v46.mVec128;
  v31 = v52 * v47;
  *(btSoftBody::Body *)(v7 + 208) = v50;
  *(_DWORD *)(v7 + 220) = v51;
  *(btSoftBody::Body *)(v7 + 224) = v48;
  v46.mVec128.m128_f32[0] = v31;
  v32 = v53 * v47;
  *(_DWORD *)(v7 + 236) = v49;
  v46.mVec128.m128_f32[1] = v32;
  v46.mVec128.m128_f32[2] = v54 * v47;
  v46.mVec128.m128_i32[3] = 0;
  v33 = v56.mVec128.m128_f32[2];
  v34 = v56.mVec128.m128_f32[1];
  v35 = (const btMatrix3x3 *)LODWORD(s_bm_current_air_resistance);
  *(btVector3 *)(v7 + 96) = (btVector3)v46.mVec128;
  *(float *)(v7 + 240) = v52;
  *(float *)(v7 + 244) = v53;
  *(float *)(v7 + 248) = v54;
  *(_DWORD *)(v7 + 192) = 0;
  *(_DWORD *)(v7 + 196) = 0;
  *(_BYTE *)(v7 + 176) = 0;
  v36 = (float)((float)(v33 * v33) + (float)(v34 * v34)) + (float)(v56.mVec128.m128_f32[0] * v56.mVec128.m128_f32[0]);
  *(_DWORD *)(v7 + 80) = v35;
  *(_DWORD *)(v7 + 84) = v35;
  *(_DWORD *)(v7 + 88) = v35;
  *(_DWORD *)(v7 + 252) = v55;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*((float *)&res->status + 3) * v57) ^ _mask__NegFloat_) <= v36 )
    v35 = (const btMatrix3x3 *)*((_DWORD *)&res->status + 3);
  *(_DWORD *)(v7 + 256) = v35;
  v44 = btSoftBody::Body::invWorldInertia(v27, &bb.m_rigid);
  btSoftBody::Body::invMass(v37);
  v42 = v38;
  v39 = btSoftBody::Body::invWorldInertia(v38, &ba.m_rigid);
  v40 = v42;
  v43 = v39;
  btSoftBody::Body::invMass(v40);
  *(btMatrix3x3 *)(v7 + 128) = *ImpulseMatrix_0(
                                  (const btVector3 *)(v7 + 224),
                                  (const float *)&ba.m_rigid,
                                  (int)v58,
                                  v35,
                                  v43,
                                  (const btVector3 *)(v7 + 208),
                                  v35,
                                  v44);
  return 1;
}
