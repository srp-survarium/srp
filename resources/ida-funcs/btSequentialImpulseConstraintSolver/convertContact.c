void __userpurge btSequentialImpulseConstraintSolver::convertContact(
        btSequentialImpulseConstraintSolver *this@<ecx>,
        btVector3 *a2@<edi>,
        btVector3 *manifold,
        const btContactSolverInfo *infoGlobal,
        btManifoldPoint *a5)
{
  const btContactSolverInfo *v5; // edx
  __m128 v6; // xmm1
  float *i; // ebx
  btVector3 *v8; // edi
  int v9; // esi
  int v10; // eax
  int v11; // eax
  char *v12; // edx
  int v13; // eax
  btSolverConstraint *v14; // ecx
  btRigidBody *FixedBody; // eax
  btRigidBody *v16; // esi
  btRigidBody *v17; // eax
  btSequentialImpulseConstraintSolver *v18; // ecx
  btSequentialImpulseConstraintSolver *v19; // ecx
  float v20; // xmm2_4
  float v21; // xmm3_4
  float *v22; // eax
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm2_4
  float v26; // xmm4_4
  float v27; // xmm5_4
  float v28; // xmm6_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm1_4
  btVector3 *v33; // edx
  float v34; // xmm7_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  float v37; // xmm3_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  __m128 v42; // xmm1
  float v43; // xmm2_4
  float v44; // xmm4_4
  btVector3 *v45; // edx
  btCollisionObject *v46; // eax
  btSolverConstraint *v47; // edx
  btSequentialImpulseConstraintSolver *v48; // ecx
  btVector3 *v49; // edx
  btCollisionObject *v50; // eax
  btSolverConstraint *v51; // edx
  btSequentialImpulseConstraintSolver *v52; // ecx
  btVector3 *v53; // [esp+Ch] [ebp-90h]
  float v54; // [esp+Ch] [ebp-90h]
  float m_restitution; // [esp+20h] [ebp-7Ch]
  int m_numIterations; // [esp+24h] [ebp-78h]
  btManifoldPoint *v57; // [esp+28h] [ebp-74h] BYREF
  btRigidBody *v58; // [esp+2Ch] [ebp-70h]
  int v59; // [esp+30h] [ebp-6Ch]
  int v60; // [esp+34h] [ebp-68h]
  char *v61; // [esp+38h] [ebp-64h]
  btVector3 v62; // [esp+3Ch] [ebp-60h] BYREF
  btVector3 v63; // [esp+4Ch] [ebp-50h] BYREF
  btVector3 v64; // [esp+5Ch] [ebp-40h] BYREF
  float v65; // [esp+6Ch] [ebp-30h]
  float v66; // [esp+70h] [ebp-2Ch]
  float v67; // [esp+74h] [ebp-28h]
  int v68; // [esp+78h] [ebp-24h]
  float v69; // [esp+7Ch] [ebp-20h]
  float v70; // [esp+80h] [ebp-1Ch]
  float v71; // [esp+84h] [ebp-18h]
  int v72; // [esp+88h] [ebp-14h]
  float v73[4]; // [esp+8Ch] [ebp-10h] BYREF

  v5 = infoGlobal;
  m_restitution = infoGlobal[16].m_restitution;
  v53 = a2;
  m_numIterations = infoGlobal[16].m_numIterations;
  if ( ((*(_BYTE *)(LODWORD(m_restitution) + 244) & 2) != 0 ? LODWORD(m_restitution) : 0) != 0
    && (v6 = (__m128)*(unsigned int *)((*(_BYTE *)(LODWORD(infoGlobal[16].m_restitution) + 244) & 2) != 0
                                     ? LODWORD(infoGlobal[16].m_restitution) + 0x160
                                     : 352),
        v6.m128_f32[0] != 0.0)
    || ((*(_BYTE *)(infoGlobal[16].m_numIterations + 244) & 2) != 0 ? infoGlobal[16].m_numIterations : 0) != 0
    && (v6 = (__m128)*(unsigned int *)((*(_BYTE *)(infoGlobal[16].m_numIterations + 244) & 2) != 0
                                     ? infoGlobal[16].m_numIterations + 0x160
                                     : 352),
        v6.m128_f32[0] != 0.0) )
  {
    v62.mVec128.m128_i32[1] = 0;
    if ( SLODWORD(infoGlobal[16].m_maxErrorReduction) > 0 )
    {
      for ( i = &infoGlobal->m_restitution; v5[16].m_erp < i[20]; i += 72 )
      {
LABEL_46:
        if ( ++v62.mVec128.m128_i32[1] >= SLODWORD(v5[16].m_maxErrorReduction) )
          return;
      }
      v8 = manifold;
      v9 = manifold->mVec128.m128_i32[2];
      v58 = (btRigidBody *)v9;
      v10 = manifold->mVec128.m128_i32[3];
      v62.mVec128.m128_i32[3] = v9;
      if ( v9 == v10 )
      {
        v59 = v9 ? 2 * v9 : 1;
        if ( v10 < v59 )
        {
          if ( v59 )
            v61 = (char *)btAlignedAllocInternal(192 * v59);
          else
            v61 = 0;
          v11 = manifold->mVec128.m128_i32[2];
          if ( v11 > 0 )
          {
            v60 = 0;
            v12 = v61;
            v62.mVec128.m128_i32[2] = v11;
            do
            {
              if ( v12 )
              {
                qmemcpy(v12, (const void *)(v60 + v8[1].mVec128.m128_i32[0]), 0xC0u);
                v8 = manifold;
                v9 = v62.mVec128.m128_i32[3];
              }
              v60 += 192;
              v12 += 192;
              --v62.mVec128.m128_i32[2];
            }
            while ( v62.mVec128.m128_i32[2] );
          }
          if ( v8[1].mVec128.m128_i32[0] )
          {
            if ( v8[1].mVec128.m128_i8[4] )
              btAlignedFreeInternal((void *)v8[1].mVec128.m128_i32[0]);
            v8[1].mVec128.m128_i32[0] = 0;
          }
          v8[1].mVec128.m128_i32[0] = (int)v61;
          v13 = v59;
          v8[1].mVec128.m128_i8[4] = 1;
          v8->mVec128.m128_i32[3] = v13;
        }
      }
      ++v8->mVec128.m128_i32[2];
      v14 = (btSolverConstraint *)(v8[1].mVec128.m128_i32[0] + 192 * v9);
      FixedBody = (*(_BYTE *)(LODWORD(m_restitution) + 244) & 2) != 0 ? (btRigidBody *)LODWORD(m_restitution) : 0;
      v16 = (*(_BYTE *)(m_numIterations + 244) & 2) != 0 ? (btRigidBody *)m_numIterations : 0;
      v59 = (int)v14;
      v62.mVec128.m128_u64[1] = __PAIR64__((unsigned int)FixedBody, (unsigned int)v16);
      if ( !FixedBody )
      {
        FixedBody = btSequentialImpulseConstraintSolver::getFixedBody((btRigidBody *)v14);
        v14 = (btSolverConstraint *)v59;
      }
      v14->m_companionIdA = (int)FixedBody;
      if ( v16 )
      {
        v17 = v16;
      }
      else
      {
        v17 = btSequentialImpulseConstraintSolver::getFixedBody((btRigidBody *)v14);
        v14 = (btSolverConstraint *)v59;
      }
      v14->m_companionIdB = (int)v17;
      v14->m_originalContactPoint = i;
      btSequentialImpulseConstraintSolver::setupContactConstraint(
        (btCollisionObject *)m_numIterations,
        &v64,
        (btSequentialImpulseConstraintSolver *)v14,
        (btSolverConstraint *)LODWORD(m_restitution),
        (btCollisionObject *)i,
        a5,
        (const btContactSolverInfo *)v73,
        &v62,
        (float *)&v57,
        &v63,
        v53);
      v18 = (btSequentialImpulseConstraintSolver *)v59;
      *(_DWORD *)(v59 + 124) = v8[3].mVec128.m128_i32[0];
      if ( (a5->m_positionWorldOnA.mVec128.m128_i8[12] & 0x20) != 0 && *((_BYTE *)i + 116) )
      {
        btSequentialImpulseConstraintSolver::addFrictionConstraint(
          v18,
          v6,
          v8,
          (btSolverConstraint *)(i + 40),
          v58,
          (const btVector3 *)i,
          (btRigidBody *)&v64,
          (btRigidBody *)&v63,
          (btCollisionObject *)LODWORD(m_restitution),
          (btCollisionObject *)m_numIterations,
          v57,
          COERCE_CONST_BTVECTOR3_(i[32]),
          COERCE_BTSOLVERCONSTRAINT_(i[34]),
          v54);
        if ( (a5->m_positionWorldOnA.mVec128.m128_i8[12] & 0x10) != 0 )
          btSequentialImpulseConstraintSolver::addFrictionConstraint(
            v19,
            v6,
            v8,
            (btSolverConstraint *)(i + 44),
            v58,
            (const btVector3 *)i,
            (btRigidBody *)&v64,
            (btRigidBody *)&v63,
            (btCollisionObject *)LODWORD(m_restitution),
            (btCollisionObject *)m_numIterations,
            v57,
            COERCE_CONST_BTVECTOR3_(i[33]),
            COERCE_BTSOLVERCONSTRAINT_(i[35]),
            *(float *)&v53);
        goto LABEL_45;
      }
      v20 = i[18] * v62.mVec128.m128_f32[0];
      v21 = v73[0] - (float)(i[16] * v62.mVec128.m128_f32[0]);
      v66 = v73[1] - (float)(i[17] * v62.mVec128.m128_f32[0]);
      v65 = v21;
      v22 = i + 40;
      v67 = v73[2] - v20;
      v68 = 0;
      i[40] = v21;
      i[41] = v66;
      i[42] = v67;
      *((_DWORD *)i + 43) = v68;
      v23 = (float)((float)(i[40] * i[40]) + (float)(i[41] * i[41])) + (float)(i[42] * i[42]);
      if ( (a5->m_positionWorldOnA.mVec128.m128_i8[12] & 0x40) != 0 || v23 <= 0.00000011920929 )
      {
        v33 = (btVector3 *)(i + 44);
        v38 = i[17] * i[17];
        if ( COERCE_FLOAT((_DWORD)i[18] & _mask__AbsFloat_) <= hsqt2 )
        {
          v6 = (__m128)LODWORD(s_bm_current_air_resistance);
          v43 = v38 + (float)(i[16] * i[16]);
          v6.m128_f32[0] = s_bm_current_air_resistance / fsqrt(v43);
          *(_DWORD *)v22 = COERCE_UNSIGNED_INT(v6.m128_f32[0] * i[17]) ^ _mask__NegFloat_;
          v44 = v6.m128_f32[0] * i[16];
          i[42] = 0.0;
          i[41] = v44;
          v33->mVec128.m128_i32[0] = COERCE_UNSIGNED_INT(i[18] * v44) ^ _mask__NegFloat_;
          v6.m128_f32[0] = v6.m128_f32[0] * v43;
          i[45] = *v22 * i[18];
          i[46] = v6.m128_f32[0];
        }
        else
        {
          v39 = s_bm_current_air_resistance;
          v40 = v38 + (float)(i[18] * i[18]);
          *v22 = 0.0;
          v41 = v39 / fsqrt(v40);
          *((_DWORD *)i + 41) = COERCE_UNSIGNED_INT(v41 * i[18]) ^ _mask__NegFloat_;
          i[42] = v41 * i[17];
          v33->mVec128.m128_f32[0] = v41 * v40;
          v42 = (__m128)*((unsigned int *)i + 42);
          v42.m128_f32[0] = v42.m128_f32[0] * i[16];
          v6 = _mm_xor_ps(v42, (__m128)(unsigned int)_mask__NegFloat_);
          i[45] = v6.m128_f32[0];
          i[46] = i[41] * i[16];
        }
        if ( (a5->m_positionWorldOnA.mVec128.m128_i8[12] & 0x10) == 0 )
          goto LABEL_44;
      }
      else
      {
        v24 = fsqrt(v23);
        v6 = (__m128)LODWORD(s_bm_current_air_resistance);
        v6.m128_f32[0] = s_bm_current_air_resistance / v24;
        *v22 = *v22 * (float)(s_bm_current_air_resistance / v24);
        i[41] = i[41] * v6.m128_f32[0];
        v25 = i[42] * v6.m128_f32[0];
        i[42] = v25;
        if ( (a5->m_positionWorldOnA.mVec128.m128_i8[12] & 0x10) == 0 )
        {
LABEL_44:
          applyAnisotropicFriction((btCollisionObject *)LODWORD(m_restitution), (btVector3 *)i + 10);
          applyAnisotropicFriction((btCollisionObject *)m_numIterations, v49);
          btSequentialImpulseConstraintSolver::addFrictionConstraint(
            v52,
            v6,
            manifold,
            v51,
            v58,
            (const btVector3 *)i,
            (btRigidBody *)&v64,
            (btRigidBody *)&v63,
            (btCollisionObject *)LODWORD(m_restitution),
            v50,
            v57,
            COERCE_CONST_BTVECTOR3_(0.0),
            COERCE_BTSOLVERCONSTRAINT_(0.0),
            v54);
          v16 = (btRigidBody *)v62.mVec128.m128_i32[2];
          v8 = manifold;
          *((_BYTE *)i + 116) = 1;
LABEL_45:
          btSequentialImpulseConstraintSolver::setFrictionConstraintImpulse(
            (btRigidBody *)v62.mVec128.m128_i32[3],
            v16,
            (const btContactSolverInfo *)a5,
            v6,
            (btSequentialImpulseConstraintSolver *)v8,
            (btSolverConstraint *)v59,
            (btManifoldPoint *)i);
          v5 = infoGlobal;
          goto LABEL_46;
        }
        v26 = i[18];
        v27 = i[41];
        v28 = i[17];
        v29 = v25;
        v30 = (float)(v27 * v26) - (float)(v25 * v28);
        v31 = i[16];
        v69 = v30;
        v32 = *v22;
        v33 = (btVector3 *)(i + 44);
        v34 = (float)(v31 * v29) - (float)(*v22 * v26);
        v72 = 0;
        v71 = (float)(v32 * v28) - (float)(v31 * v27);
        v70 = v34;
        i[44] = v69;
        i[45] = v70;
        i[46] = v71;
        *((_DWORD *)i + 47) = v72;
        v6 = (__m128)*((unsigned int *)i + 45);
        v35 = i[44];
        v36 = i[46];
        v37 = s_bm_current_air_resistance
            / fsqrt((float)((float)(v35 * v35) + (float)(v6.m128_f32[0] * v6.m128_f32[0])) + (float)(v36 * v36));
        v6.m128_f32[0] = v6.m128_f32[0] * v37;
        i[44] = v35 * v37;
        i[45] = v6.m128_f32[0];
        i[46] = v36 * v37;
      }
      applyAnisotropicFriction((btCollisionObject *)LODWORD(m_restitution), v33);
      applyAnisotropicFriction((btCollisionObject *)m_numIterations, v45);
      btSequentialImpulseConstraintSolver::addFrictionConstraint(
        v48,
        v6,
        manifold,
        v47,
        v58,
        (const btVector3 *)i,
        (btRigidBody *)&v64,
        (btRigidBody *)&v63,
        (btCollisionObject *)LODWORD(m_restitution),
        v46,
        v57,
        COERCE_CONST_BTVECTOR3_(0.0),
        COERCE_BTSOLVERCONSTRAINT_(0.0),
        v54);
      goto LABEL_44;
    }
  }
}
