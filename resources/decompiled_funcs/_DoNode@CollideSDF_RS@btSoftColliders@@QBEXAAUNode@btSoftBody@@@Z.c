void __userpurge btSoftColliders::CollideSDF_RS::DoNode(
        btSoftColliders::CollideSDF_RS *this@<ecx>,
        const float *a2@<edi>,
        const btSoftColliders::CollideSDF_RS *n,
        btSoftBody::Node *na)
{
  const btMatrix3x3 *stamargin_low; // xmm0_4
  bool v5; // zf
  float *m128_f32; // esi
  btSoftBody::Material *m_rigidBody; // eax
  float m_im; // xmm2_4
  float v9; // xmm1_4
  float *p_m_flags; // eax
  btRigidBody *v11; // ecx
  btVector3 *VelocityInLocalPoint; // eax
  float v13; // xmm0_4
  btSoftBody::Material *m_colObj1; // edx
  float v15; // xmm1_4
  float v16; // xmm2_4
  float *psb; // eax
  float v18; // xmm1_4
  double v19; // st7
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  btMatrix3x3 *v24; // eax
  btSoftBody::Node *v25; // ebx
  float *v26; // esi
  long double v27; // st7
  float v28; // xmm0_4
  float v29; // xmm0_4
  int v30; // ecx
  int v31; // eax
  int v32; // edi
  const btMatrix3x3 *v33; // edi
  int v34; // ebx
  void *v35; // eax
  const btMatrix3x3 *v36; // edx
  btCollisionObject *v37; // ecx
  float dt; // [esp+8D4h] [ebp-13Ch]
  const btSoftBody::RContact *v39; // [esp+8E0h] [ebp-130h]
  const btMatrix3x3 *zy; // [esp+8F0h] [ebp-120h] BYREF
  int v41; // [esp+8F4h] [ebp-11Ch]
  float v42; // [esp+8F8h] [ebp-118h]
  btMatrix3x3 v43; // [esp+8FCh] [ebp-114h] BYREF
  float zx; // [esp+92Ch] [ebp-E4h] BYREF
  btVector3 rel_pos; // [esp+930h] [ebp-E0h] BYREF
  btVector3 v46; // [esp+940h] [ebp-D0h] BYREF
  btSoftBody::RContact cti; // [esp+950h] [ebp-C0h] BYREF

  v39 = (const btSoftBody::RContact *)a2;
  if ( na->m_im <= 0.0 )
    stamargin_low = (const btMatrix3x3 *)LODWORD(n->stamargin);
  else
    stamargin_low = (const btMatrix3x3 *)LODWORD(n->dynmargin);
  v5 = (*((_BYTE *)na + 108) & 1) == 0;
  zy = stamargin_low;
  if ( v5 )
  {
    m128_f32 = na->m_x.mVec128.m128_f32;
    if ( btSoftBody::checkContact(n->psb, n->m_colObj1, &na->m_x, *(float *)&zy, &cti.m_cti) )
    {
      m_rigidBody = (btSoftBody::Material *)n->m_rigidBody;
      m_im = na->m_im;
      v42 = m_im;
      v9 = m_rigidBody ? m_rigidBody[17].m_kVST : 0.0;
      v43.m_el[1].mVec128.m128_f32[1] = v9;
      if ( (float)(v9 + m_im) > 0.0 )
      {
        if ( !m_rigidBody )
          m_rigidBody = (btSoftBody::Material *)n->m_colObj1;
        p_m_flags = (float *)&m_rigidBody->m_flags;
        v41 = (int)p_m_flags;
        if ( (`btSoftColliders::CollideSDF_RS::DoNode'::`8'::`local static guard' & 1) == 0 )
        {
          `btSoftColliders::CollideSDF_RS::DoNode'::`8'::`local static guard' |= 1u;
          zy = 0;
          zx = 0.0;
          memset(&v43.m_el[1].m_floats[2], 0, 24);
          v43.m_el[0].mVec128.m128_i32[0] = 0;
          btMatrix3x3::btMatrix3x3(
            &v43,
            &`btSoftColliders::CollideSDF_RS::DoNode'::`8'::iwiStatic,
            &v43.m_el[2].mVec128.m128_f32[3],
            &v43.m_el[1].mVec128.m128_f32[2],
            &v43.m_el[2].mVec128.m128_f32[2],
            &v43.m_el[2].mVec128.m128_f32[1],
            &v43.m_el[1].mVec128.m128_f32[3],
            v43.m_el[2].mVec128.m128_f32,
            &zx,
            (const float *)&zy,
            a2);
          p_m_flags = (float *)v41;
        }
        v11 = n->m_rigidBody;
        if ( v11 )
          zy = &v11->m_invInertiaTensorWorld;
        else
          zy = &`btSoftColliders::CollideSDF_RS::DoNode'::`8'::iwiStatic;
        rel_pos.mVec128.m128_f32[0] = *m128_f32 - p_m_flags[12];
        rel_pos.mVec128.m128_f32[1] = na->m_x.mVec128.m128_f32[1] - p_m_flags[13];
        rel_pos.mVec128.m128_f32[2] = na->m_x.mVec128.m128_f32[2] - p_m_flags[14];
        rel_pos.mVec128.m128_i32[3] = 0;
        if ( v11 )
        {
          v43.m_el[0].mVec128.m128_i32[0] = (int)&n->psb->m_sst;
          VelocityInLocalPoint = btRigidBody::getVelocityInLocalPoint(&rel_pos, &v46, v11);
          v13 = *(float *)v43.m_el[0].mVec128.m128_i32[0];
          v43.m_el[0].mVec128.m128_f32[1] = *(float *)v43.m_el[0].mVec128.m128_i32[0]
                                          * VelocityInLocalPoint->mVec128.m128_f32[0];
          v43.m_el[0].mVec128.m128_f32[2] = VelocityInLocalPoint->mVec128.m128_f32[1] * v13;
          v43.m_el[0].mVec128.m128_f32[3] = VelocityInLocalPoint->mVec128.m128_f32[2] * v13;
        }
        else
        {
          memset(&v43.m_el[0].m_floats[1], 0, 12);
        }
        m_colObj1 = (btSoftBody::Material *)n->m_colObj1;
        v15 = na->m_x.mVec128.m128_f32[1] - na->m_q.mVec128.m128_f32[1];
        v16 = na->m_x.mVec128.m128_f32[2] - na->m_q.mVec128.m128_f32[2];
        v43.m_el[1].mVec128.m128_i32[0] = 0;
        v46.mVec128.m128_u64[0] = *(unsigned __int64 *)((char *)v43.m_el[0].mVec128.m128_u64 + 4);
        psb = (float *)n->psb;
        v18 = v15 - v43.m_el[0].mVec128.m128_f32[2];
        v19 = n->psb->m_cfg.kDF * *(float *)&m_colObj1[11].m_flags;
        v46.mVec128.m128_u64[1] = *(unsigned __int64 *)((char *)&v43.m_el[0].mVec128.m128_u64[1] + 4);
        v20 = *m128_f32 - na->m_q.mVec128.m128_f32[0];
        *(float *)&v41 = v19;
        v21 = v16 - v43.m_el[0].mVec128.m128_f32[3];
        v22 = v20 - v43.m_el[0].mVec128.m128_f32[1];
        dt = psb[115];
        v23 = (float)((float)(cti.m_cti.m_normal.mVec128.m128_f32[2] * v21)
                    + (float)(cti.m_cti.m_normal.mVec128.m128_f32[1] * v18))
            + (float)((float)(v20 - v43.m_el[0].mVec128.m128_f32[1]) * cti.m_cti.m_normal.mVec128.m128_f32[0]);
        v43.m_el[0].mVec128.m128_f32[0] = v23;
        v43.m_el[0].mVec128.m128_f32[1] = v22 - (float)(cti.m_cti.m_normal.mVec128.m128_f32[0] * v23);
        v43.m_el[0].mVec128.m128_f32[2] = v18 - (float)(cti.m_cti.m_normal.mVec128.m128_f32[1] * v23);
        v43.m_el[0].mVec128.m128_f32[3] = v21 - (float)(cti.m_cti.m_normal.mVec128.m128_f32[2] * v23);
        cti.m_node = na;
        v24 = ImpulseMatrix_0(dt, v42, v43.m_el[1].mVec128.m128_f32[1], zy, &rel_pos);
        v25 = (btSoftBody::Node *)n;
        v26 = (float *)n->psb;
        cti.m_c0 = *v24;
        cti.m_c1 = (btVector3)_mm_load_si128((const __m128i *)&rel_pos);
        cti.m_c2 = v26[115] * v42;
        v43.m_el[1].mVec128.m128_f32[1] = v43.m_el[0].mVec128.m128_f32[3] * v43.m_el[0].mVec128.m128_f32[3]
                                        + v43.m_el[0].mVec128.m128_f32[2] * v43.m_el[0].mVec128.m128_f32[2]
                                        + v43.m_el[0].mVec128.m128_f32[1] * v43.m_el[0].mVec128.m128_f32[1];
        v27 = fabsf(v43.m_el[0].mVec128.m128_f32[0]);
        if ( v27 * *(float *)&v41 <= v43.m_el[1].mVec128.m128_f32[1] )
          v28 = *(float *)&clear_value - *(float *)&v41;
        else
          v28 = 0.0;
        v5 = (n->m_colObj1->m_collisionFlags & 3) == 0;
        cti.m_c3 = v28;
        if ( v5 )
          v29 = v26[83];
        else
          v29 = v26[84];
        v30 = *((_DWORD *)v26 + 206);
        v31 = *((_DWORD *)v26 + 205);
        cti.m_c4 = v29;
        if ( v31 == v30 )
        {
          if ( v31 )
          {
            v32 = 2 * v31;
            v41 = 2 * v31;
          }
          else
          {
            v41 = 1;
            v32 = 1;
          }
          if ( v30 < v32 )
          {
            if ( v32 )
            {
              ++gNumAlignedAllocs;
              zy = (const btMatrix3x3 *)sAlignedAllocFunc(144 * v32, 16);
            }
            else
            {
              zy = 0;
            }
            if ( *((int *)v26 + 205) > 0 )
            {
              v33 = zy;
              v34 = 0;
              v42 = v26[205];
              do
              {
                if ( v33 )
                  btSoftBody::RContact::RContact((btSoftBody::RContact *)(v34 + *((_DWORD *)v26 + 207)), v39);
                v34 += 144;
                v33 += 3;
                --LODWORD(v42);
              }
              while ( v42 != 0.0 );
              v32 = v41;
              v25 = (btSoftBody::Node *)n;
            }
            v35 = (void *)*((_DWORD *)v26 + 207);
            if ( v35 )
            {
              if ( *((_BYTE *)v26 + 832) )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(v35);
              }
              v26[207] = 0.0;
            }
            v36 = zy;
            *((_BYTE *)v26 + 832) = 1;
            *((_DWORD *)v26 + 207) = v36;
            *((_DWORD *)v26 + 206) = v32;
          }
        }
        if ( *((_DWORD *)v26 + 207) + 144 * *((_DWORD *)v26 + 205) )
          btSoftBody::RContact::RContact(&cti, v39);
        v37 = (btCollisionObject *)*((_DWORD *)&v25->btSoftBody::Feature + 2);
        ++*((_DWORD *)v26 + 205);
        if ( v37 )
          btCollisionObject::activate(v37, (bool)v39);
      }
    }
  }
}
