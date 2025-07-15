void __userpurge btSoftColliders::CollideSDF_RS::DoNode(
        btSoftColliders::CollideSDF_RS *this@<ecx>,
        const float *a2@<edi>,
        btSoftBody::Node *n,
        int a4)
{
  btSoftBody::Node *v4; // edi
  btSoftBody::RContact *v5; // xmm0_4
  bool v6; // zf
  btSoftBody::Material *m_material; // esi
  float v8; // xmm2_4
  float v9; // xmm1_4
  float *p_m_flags; // esi
  int v11; // eax
  float *v12; // esi
  btVector3 *VelocityInLocalPoint; // eax
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float *m_tag; // eax
  float v18; // xmm0_4
  btSoftBody::Material *v19; // ecx
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  double v24; // st7
  float v25; // xmm0_4
  btSoftBody::Node *v26; // edi
  void *v27; // esi
  float v28; // xmm0_4
  float v29; // xmm0_4
  btCollisionObject *v30; // ecx
  btCollisionObject *v31; // eax
  btSoftBody::RContact *v32; // eax
  int v33; // eax
  btSoftBody::RContact *v34; // ebx
  float v35; // eax
  btSoftBody::RContact *v36; // eax
  int v37; // edx
  float v38; // [esp+0h] [ebp-140h]
  btCollisionObject *v39; // [esp+Ch] [ebp-134h]
  btCollisionObject *v40; // [esp+Ch] [ebp-134h]
  btSoftBody::RContact *cti; // [esp+20h] [ebp-120h] BYREF
  float v43; // [esp+24h] [ebp-11Ch] BYREF
  float v44; // [esp+28h] [ebp-118h]
  int v45; // [esp+2Ch] [ebp-114h] BYREF
  float v46; // [esp+30h] [ebp-110h]
  float v47; // [esp+34h] [ebp-10Ch]
  float v48; // [esp+38h] [ebp-108h]
  int v49; // [esp+3Ch] [ebp-104h]
  btMatrix3x3 v50; // [esp+44h] [ebp-FCh] BYREF
  float v51; // [esp+74h] [ebp-CCh]
  float v52; // [esp+78h] [ebp-C8h]
  int v53; // [esp+7Ch] [ebp-C4h]
  btSoftBody::RContact __that; // [esp+80h] [ebp-C0h] BYREF
  _BYTE v55[48]; // [esp+110h] [ebp-30h] BYREF

  if ( *(float *)(a4 + 96) <= 0.0 )
  {
    v5 = (btSoftBody::RContact *)n->m_x.mVec128.m128_i32[0];
    v4 = n;
  }
  else
  {
    v4 = n;
    v5 = (btSoftBody::RContact *)*((_DWORD *)&n->btSoftBody::Feature + 3);
  }
  v6 = (*(_BYTE *)(a4 + 108) & 1) == 0;
  cti = v5;
  if ( v6
    && btSoftBody::checkContact(
         (btSoftBody *)&__that,
         (btCollisionObject *)v4->m_tag,
         (const btVector3 *)v4->m_material,
         (float *)(a4 + 16),
         &cti->m_cti,
         (int)&__that) )
  {
    m_material = (btSoftBody::Material *)*((_DWORD *)&v4->btSoftBody::Feature + 2);
    v8 = *(float *)(a4 + 96);
    v44 = v8;
    v9 = m_material ? m_material[17].m_kVST : 0.0;
    v50.m_el[1].mVec128.m128_f32[0] = v9;
    if ( (float)(v9 + v8) > 0.0 )
    {
      if ( !m_material )
        m_material = v4->m_material;
      p_m_flags = (float *)&m_material->m_flags;
      if ( (`btSoftColliders::CollideSDF_RS::DoNode'::`8'::`local static guard' & 1) == 0 )
      {
        `btSoftColliders::CollideSDF_RS::DoNode'::`8'::`local static guard' |= 1u;
        v45 = 0;
        cti = 0;
        v43 = 0.0;
        *(unsigned __int64 *)((char *)v50.m_el[1].mVec128.m128_u64 + 4) = 0;
        memset(&v50, 0, 16);
        btMatrix3x3::setValue(
          &v50,
          (int)&`btSoftColliders::CollideSDF_RS::DoNode'::`8'::iwiStatic,
          &v50.m_el[1].mVec128.m128_f32[2],
          &v50.m_el[0].mVec128.m128_f32[1],
          &v50.m_el[0].mVec128.m128_f32[2],
          &v50.m_el[1].mVec128.m128_f32[1],
          &v50.m_el[0].mVec128.m128_f32[3],
          &v43,
          (float *)&cti,
          (const float *)&v45,
          a2);
      }
      v11 = *((_DWORD *)&v4->btSoftBody::Feature + 2);
      if ( v11 )
        cti = (btSoftBody::RContact *)(v11 + 272);
      else
        cti = (btSoftBody::RContact *)&`btSoftColliders::CollideSDF_RS::DoNode'::`8'::iwiStatic;
      v50.m_el[1].mVec128.m128_f32[3] = *(float *)(a4 + 16) - p_m_flags[12];
      v50.m_el[2].mVec128.m128_f32[0] = *(float *)(a4 + 20) - p_m_flags[13];
      v50.m_el[2].mVec128.m128_f32[1] = *(float *)(a4 + 24) - p_m_flags[14];
      v50.m_el[2].mVec128.m128_i32[2] = 0;
      if ( v11 )
      {
        v12 = (float *)((char *)v4->m_tag + 460);
        VelocityInLocalPoint = btRigidBody::getVelocityInLocalPoint(
                                 (const btVector3 *)&v50.m_el[1].m_floats[3],
                                 (btVector3 *)&v50.m_el[2].m_floats[3],
                                 (btRigidBody *)v11);
        v14 = *v12;
        v46 = *v12 * VelocityInLocalPoint->mVec128.m128_f32[0];
        v47 = VelocityInLocalPoint->mVec128.m128_f32[1] * v14;
        v48 = VelocityInLocalPoint->mVec128.m128_f32[2] * v14;
      }
      else
      {
        v46 = 0.0;
        v47 = 0.0;
        v48 = 0.0;
      }
      v15 = *(float *)(a4 + 20) - *(float *)(a4 + 36);
      v16 = *(float *)(a4 + 24) - *(float *)(a4 + 40);
      m_tag = (float *)n->m_tag;
      v49 = 0;
      v18 = *(float *)(a4 + 16) - *(float *)(a4 + 32);
      v19 = n->m_material;
      v50.m_el[2].mVec128.m128_f32[3] = v46;
      v51 = v47;
      v52 = v48;
      v53 = 0;
      v20 = v18 - v46;
      v21 = v15 - v47;
      v22 = v16 - v48;
      v23 = (float)((float)(__that.m_cti.m_normal.mVec128.m128_f32[2] * v22)
                  + (float)(__that.m_cti.m_normal.mVec128.m128_f32[1] * v21))
          + (float)(v20 * __that.m_cti.m_normal.mVec128.m128_f32[0]);
      v24 = m_tag[115];
      v46 = v20 - (float)(__that.m_cti.m_normal.mVec128.m128_f32[0] * v23);
      v38 = v24;
      v25 = m_tag[81] * *(float *)&v19[11].m_flags;
      v50.m_el[0].mVec128.m128_f32[0] = v23;
      v47 = v21 - (float)(__that.m_cti.m_normal.mVec128.m128_f32[1] * v23);
      v48 = v22 - (float)(__that.m_cti.m_normal.mVec128.m128_f32[2] * v23);
      v43 = v25;
      __that.m_node = (btSoftBody::Node *)a4;
      __that.m_c0 = *ImpulseMatrix(
                       (int)v55,
                       v38,
                       LODWORD(v44),
                       (const btMatrix3x3 *)v50.m_el[1].mVec128.m128_i32[0],
                       (const btMatrix3x3 *)cti);
      __that.m_c1 = *(btVector3 *)((char *)&v50.m_el[1] + 12);
      v26 = n;
      v27 = n->m_tag;
      __that.m_c2 = *((float *)n->m_tag + 115) * v44;
      if ( (float)(COERCE_FLOAT(v50.m_el[0].mVec128.m128_i32[0] & _mask__AbsFloat_) * v43) <= (float)((float)((float)(v48 * v48) + (float)(v47 * v47)) + (float)(v46 * v46)) )
        v28 = s_bm_current_air_resistance - v43;
      else
        v28 = 0.0;
      v6 = (n->m_material[10].m_flags & 3) == 0;
      __that.m_c3 = v28;
      if ( v6 )
        v29 = *((float *)v27 + 83);
      else
        v29 = *((float *)v27 + 84);
      v30 = (btCollisionObject *)*((_DWORD *)v27 + 206);
      v31 = (btCollisionObject *)*((_DWORD *)v27 + 205);
      __that.m_c4 = v29;
      if ( v31 == v30 )
      {
        LODWORD(v43) = v31 ? 2 * (_DWORD)v31 : 1;
        if ( (int)v30 < SLODWORD(v43) )
        {
          if ( v43 == 0.0 )
          {
            cti = 0;
          }
          else
          {
            v32 = (btSoftBody::RContact *)btAlignedAllocInternal(144 * LODWORD(v43));
            v30 = v39;
            cti = v32;
          }
          v33 = *((_DWORD *)v27 + 205);
          if ( v33 > 0 )
          {
            v44 = 0.0;
            v34 = cti;
            v45 = v33;
            do
            {
              if ( v34 )
                btSoftBody::RContact::RContact(
                  v34,
                  (const btSoftBody::RContact *)(LODWORD(v44) + *((_DWORD *)v27 + 207)));
              LODWORD(v44) += 144;
              ++v34;
              --v45;
            }
            while ( v45 );
            v26 = n;
          }
          if ( *((_DWORD *)v27 + 207) )
          {
            if ( *((_BYTE *)v27 + 832) )
            {
              btAlignedFreeInternal(*((void **)v27 + 207));
              v30 = v40;
            }
            *((_DWORD *)v27 + 207) = 0;
          }
          *((_DWORD *)v27 + 207) = cti;
          v35 = v43;
          *((_BYTE *)v27 + 832) = 1;
          *((float *)v27 + 206) = v35;
        }
      }
      v36 = (btSoftBody::RContact *)(*((_DWORD *)v27 + 207) + 144 * *((_DWORD *)v27 + 205));
      if ( v36 )
        btSoftBody::RContact::RContact(v36, &__that);
      v37 = *((_DWORD *)&v26->btSoftBody::Feature + 2);
      ++*((_DWORD *)v27 + 205);
      if ( v37 )
        btCollisionObject::activate(v30, v37);
    }
  }
}
