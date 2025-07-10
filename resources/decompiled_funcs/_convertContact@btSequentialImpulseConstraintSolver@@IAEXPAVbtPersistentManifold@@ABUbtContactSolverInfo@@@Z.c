void __userpurge btSequentialImpulseConstraintSolver::convertContact(
        btSequentialImpulseConstraintSolver *this@<ecx>,
        btVector3 *a2@<edi>,
        float a3@<xmm10>,
        btSequentialImpulseConstraintSolver *manifold,
        btPersistentManifold *infoGlobal,
        const btContactSolverInfo *infoGlobala)
{
  const btContactSolverInfo *v6; // edx
  bool v7; // cc
  float *i; // ebx
  btSequentialImpulseConstraintSolver *v9; // edi
  btRigidBody *m_size; // edx
  btRigidBody *m_capacity; // eax
  btRigidBody *v12; // esi
  int v13; // edx
  btRigidBody *v14; // eax
  btRigidBody *v15; // eax
  int v16; // edx
  btSolverConstraint *m_data; // eax
  btRigidBody *v18; // ecx
  btSolverConstraint *v19; // edx
  btRigidBody *FixedBody; // eax
  btRigidBody *v21; // ecx
  btRigidBody *v22; // esi
  btRigidBody *v23; // eax
  btRigidBody *v24; // esi
  float v25; // xmm2_4
  float v26; // xmm3_4
  float *v27; // esi
  bool v28; // zf
  float v29; // xmm0_4
  long double v30; // st7
  float v31; // xmm3_4
  float v32; // xmm5_4
  float v33; // xmm2_4
  float v34; // xmm4_4
  float v35; // xmm1_4
  float v36; // xmm6_4
  float v37; // xmm5_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  long double v40; // st7
  btVector3 *v41; // ecx
  long double v42; // st7
  float v43; // xmm0_4
  float v44; // xmm0_4
  long double v45; // st7
  long double v46; // st7
  btVector3 *v47; // ecx
  btCollisionObject *v48; // eax
  btSequentialImpulseConstraintSolver *v49; // ecx
  btVector3 *v50; // ecx
  btCollisionObject *v51; // eax
  btCollisionObject *v52; // edx
  btVector3 *v53; // [esp+548h] [ebp-A0h]
  float v54; // [esp+548h] [ebp-A0h]
  btCollisionObject *colObj; // [esp+558h] [ebp-90h]
  float v56; // [esp+55Ch] [ebp-8Ch]
  int v57; // [esp+560h] [ebp-88h]
  btSolverConstraint *v58; // [esp+560h] [ebp-88h]
  btRigidBody *v59; // [esp+564h] [ebp-84h]
  float v60; // [esp+564h] [ebp-84h]
  float v61; // [esp+564h] [ebp-84h]
  float v62; // [esp+564h] [ebp-84h]
  btManifoldPoint *v63; // [esp+568h] [ebp-80h] BYREF
  btRigidBody *v64; // [esp+56Ch] [ebp-7Ch]
  btRigidBody *solverBodyB; // [esp+570h] [ebp-78h]
  btRigidBody *v66; // [esp+574h] [ebp-74h]
  float v67; // [esp+578h] [ebp-70h]
  int v68; // [esp+57Ch] [ebp-6Ch]
  float v69; // [esp+580h] [ebp-68h]
  float v70; // [esp+584h] [ebp-64h]
  float v71; // [esp+588h] [ebp-60h]
  float v72; // [esp+58Ch] [ebp-5Ch]
  btVector3 v73; // [esp+590h] [ebp-58h] BYREF
  btVector3 v74; // [esp+5A8h] [ebp-40h] BYREF
  __int64 v75; // [esp+5B8h] [ebp-30h]
  __int64 v76; // [esp+5C0h] [ebp-28h]
  __int64 v77; // [esp+5C8h] [ebp-20h]
  __int64 v78; // [esp+5D0h] [ebp-18h]
  btVector3 v79; // [esp+5D8h] [ebp-10h] BYREF

  v6 = (const btContactSolverInfo *)infoGlobal;
  v56 = *(float *)&infoGlobal->m_body0;
  v53 = a2;
  colObj = (btCollisionObject *)infoGlobal->m_body1;
  if ( ((*(_BYTE *)(LODWORD(v56) + 244) & 2) != 0 ? LODWORD(v56) : 0) != 0
    && *((*((_BYTE *)infoGlobal->m_body0 + 244) & 2) != 0 ? (float *)((char *)infoGlobal->m_body0 + 352) : (float *)352) != 0.0
    || ((*((_BYTE *)infoGlobal->m_body1 + 244) & 2) != 0 ? infoGlobal->m_body1 : 0) != 0
    && *((*((_BYTE *)infoGlobal->m_body1 + 244) & 2) != 0 ? (float *)((char *)infoGlobal->m_body1 + 352) : (float *)352) != 0.0 )
  {
    v7 = infoGlobal->m_cachedPoints <= 0;
    v68 = 0;
    if ( !v7 )
    {
      for ( i = infoGlobal->m_pointCache[0].m_localPointA.mVec128.m128_f32; v6[16].m_erp < i[20]; i += 72 )
      {
LABEL_48:
        v7 = ++v68 < SLODWORD(v6[16].m_maxErrorReduction);
        if ( !v7 )
          return;
      }
      v9 = manifold;
      m_size = (btRigidBody *)manifold->m_tmpSolverContactConstraintPool.m_size;
      m_capacity = (btRigidBody *)manifold->m_tmpSolverContactConstraintPool.m_capacity;
      v12 = m_size;
      solverBodyB = m_size;
      v59 = m_size;
      if ( m_size == m_capacity )
      {
        if ( m_size )
        {
          v13 = 2 * (_DWORD)m_size;
          v57 = 2 * (_DWORD)v12;
        }
        else
        {
          v57 = 1;
          v13 = 1;
        }
        if ( (int)m_capacity < v13 )
        {
          if ( v13 )
          {
            ++gNumAlignedAllocs;
            v14 = (btRigidBody *)sAlignedAllocFunc(192 * v13, 16);
            v13 = v57;
            v64 = v14;
          }
          else
          {
            v64 = 0;
          }
          if ( manifold->m_tmpSolverContactConstraintPool.m_size > 0 )
          {
            v15 = v64;
            v16 = 0;
            v66 = (btRigidBody *)manifold->m_tmpSolverContactConstraintPool.m_size;
            do
            {
              if ( v15 )
              {
                qmemcpy(v15, &v9->m_tmpSolverContactConstraintPool.m_data[v16], 0xC0u);
                v12 = v59;
                v9 = manifold;
              }
              ++v16;
              v15 = (btRigidBody *)((char *)v15 + 192);
              v66 = (btRigidBody *)((char *)v66 - 1);
            }
            while ( v66 );
            v13 = v57;
          }
          m_data = v9->m_tmpSolverContactConstraintPool.m_data;
          if ( m_data )
          {
            if ( v9->m_tmpSolverContactConstraintPool.m_ownsMemory )
            {
              ++gNumAlignedFree;
              sAlignedFreeFunc(m_data);
              v13 = v57;
            }
            v9->m_tmpSolverContactConstraintPool.m_data = 0;
          }
          v18 = v64;
          v9->m_tmpSolverContactConstraintPool.m_ownsMemory = 1;
          v9->m_tmpSolverContactConstraintPool.m_data = (btSolverConstraint *)v18;
          v9->m_tmpSolverContactConstraintPool.m_capacity = v13;
        }
      }
      ++v9->m_tmpSolverContactConstraintPool.m_size;
      v21 = (btRigidBody *)colObj;
      v19 = &v9->m_tmpSolverContactConstraintPool.m_data[(_DWORD)v12];
      FixedBody = (*(_BYTE *)(LODWORD(v56) + 244) & 2) != 0 ? (btRigidBody *)LODWORD(v56) : 0;
      LOBYTE(v21) = colObj->m_internalType & 2;
      v22 = (char)v21 != 0 ? (btRigidBody *)colObj : 0;
      v58 = v19;
      v64 = FixedBody;
      v66 = v22;
      if ( !FixedBody )
      {
        FixedBody = btSequentialImpulseConstraintSolver::getFixedBody(v21, a3);
        v19 = v58;
      }
      v19->m_companionIdA = (int)FixedBody;
      if ( v22 )
      {
        v23 = v22;
      }
      else
      {
        v23 = btSequentialImpulseConstraintSolver::getFixedBody(v21, a3);
        v19 = v58;
      }
      v19->m_companionIdB = (int)v23;
      v19->m_originalContactPoint = i;
      btSequentialImpulseConstraintSolver::setupContactConstraint(
        v19,
        (btManifoldPoint *)i,
        &v74,
        (btSequentialImpulseConstraintSolver *)LODWORD(v56),
        colObj,
        infoGlobala,
        &v79,
        &v73,
        (float *)&v63,
        (btVector3 *)&v73.m_floats[2],
        v53);
      v58->m_frictionIndex = v9->m_tmpSolverContactFrictionConstraintPool.m_size;
      if ( (infoGlobala->m_solverMode & 0x20) != 0 && *((_BYTE *)i + 116) )
      {
        v24 = solverBodyB;
        btSequentialImpulseConstraintSolver::addFrictionConstraint(
          (btSequentialImpulseConstraintSolver *)(i + 40),
          a3,
          v9,
          (btSequentialImpulseConstraintSolver *)(i + 40),
          solverBodyB,
          (btManifoldPoint *)i,
          (btManifoldPoint *)&v74,
          (btVector3 *)&v73.m_floats[2],
          (btCollisionObject *)LODWORD(v56),
          colObj,
          v63,
          COERCE_CONST_BTVECTOR3_(i[32]),
          COERCE_CONST_BTVECTOR3_(i[34]),
          v54);
        if ( (infoGlobala->m_solverMode & 0x10) != 0 )
          btSequentialImpulseConstraintSolver::addFrictionConstraint(
            (btSequentialImpulseConstraintSolver *)(i + 44),
            a3,
            v9,
            (btSequentialImpulseConstraintSolver *)(i + 44),
            v24,
            (btManifoldPoint *)i,
            (btManifoldPoint *)&v74,
            (btVector3 *)&v73.m_floats[2],
            (btCollisionObject *)LODWORD(v56),
            colObj,
            v63,
            COERCE_CONST_BTVECTOR3_(i[33]),
            COERCE_CONST_BTVECTOR3_(i[35]),
            *(float *)&v53);
        goto LABEL_47;
      }
      v25 = i[18] * v73.mVec128.m128_f32[0];
      v26 = v79.mVec128.m128_f32[0] - (float)(v73.mVec128.m128_f32[0] * i[16]);
      *((float *)&v75 + 1) = v79.mVec128.m128_f32[1] - (float)(i[17] * v73.mVec128.m128_f32[0]);
      *(float *)&v76 = v79.mVec128.m128_f32[2] - v25;
      HIDWORD(v76) = 0;
      v27 = i + 40;
      *(float *)&v75 = v26;
      *((_QWORD *)i + 20) = v75;
      *((_QWORD *)i + 21) = v76;
      v28 = (infoGlobala->m_solverMode & 0x40) == 0;
      v29 = (float)((float)(i[40] * i[40]) + (float)(i[41] * i[41])) + (float)(i[42] * i[42]);
      v70 = v29;
      if ( v28 && v29 > 0.00000011920929 )
      {
        v30 = 1.0 / sqrtf(v70);
        *v27 = *v27 * v30;
        i[41] = i[41] * v30;
        i[42] = v30 * i[42];
        if ( (infoGlobala->m_solverMode & 0x10) == 0 )
        {
LABEL_46:
          applyAnisotropicFriction((btCollisionObject *)LODWORD(v56), (btVector3 *)i + 10);
          applyAnisotropicFriction(colObj, v50);
          btSequentialImpulseConstraintSolver::addFrictionConstraint(
            (btSequentialImpulseConstraintSolver *)solverBodyB,
            a3,
            v9,
            (btSequentialImpulseConstraintSolver *)(i + 40),
            solverBodyB,
            (btManifoldPoint *)i,
            (btManifoldPoint *)&v74,
            (btVector3 *)&v73.m_floats[2],
            v52,
            v51,
            v63,
            COERCE_CONST_BTVECTOR3_(0.0),
            COERCE_CONST_BTVECTOR3_(0.0),
            v54);
          *((_BYTE *)i + 116) = 1;
LABEL_47:
          btSequentialImpulseConstraintSolver::setFrictionConstraintImpulse(
            v64,
            v66,
            v9,
            v58,
            (btManifoldPoint *)i,
            infoGlobala);
          v6 = (const btContactSolverInfo *)infoGlobal;
          goto LABEL_48;
        }
        v31 = i[41];
        v32 = i[42];
        v33 = i[18];
        v34 = i[17];
        v35 = i[16];
        *(float *)&v77 = (float)(v31 * v33) - (float)(v32 * v34);
        v36 = v35 * v32;
        v37 = *v27;
        v78 = COERCE_UNSIGNED_INT((float)(*v27 * v34) - (float)(v35 * v31));
        *((float *)&v77 + 1) = v36 - (float)(v37 * v33);
        *((_QWORD *)i + 22) = v77;
        *((_QWORD *)i + 23) = v78;
        v38 = i[45];
        v39 = i[46];
        v71 = i[44];
        v72 = v38;
        v73.mVec128.m128_f32[1] = v39;
        v40 = sqrtf((float)((float)(v71 * v71) + (float)(v38 * v38)) + (float)(v39 * v39));
        v41 = (btVector3 *)(i + 44);
        v60 = 1.0 / v40;
        i[44] = v71 * v60;
        i[45] = v72 * v60;
        i[46] = v73.mVec128.m128_f32[1] * v60;
      }
      else
      {
        if ( fabsf(i[18]) <= hsqt2 )
        {
          v69 = (float)(i[17] * i[17]) + (float)(i[16] * i[16]);
          v45 = 1.0 / sqrtf(v69);
          v62 = v45;
          *v27 = -(i[17] * v45);
          v46 = v45 * i[16];
          i[42] = 0.0;
          i[41] = v46;
          i[44] = -(float)(i[18] * i[41]);
          i[45] = i[18] * *v27;
          v44 = v62 * v69;
        }
        else
        {
          v67 = (float)(i[17] * i[17]) + (float)(i[18] * i[18]);
          v42 = 1.0 / sqrtf(v67);
          *v27 = 0.0;
          v61 = v42;
          v43 = v61 * v67;
          i[41] = -(i[18] * v42);
          i[42] = v42 * i[17];
          i[44] = v43;
          i[45] = -(float)(i[42] * i[16]);
          v44 = i[41] * i[16];
        }
        i[46] = v44;
        if ( (infoGlobala->m_solverMode & 0x10) == 0 )
          goto LABEL_46;
        v41 = (btVector3 *)(i + 44);
      }
      applyAnisotropicFriction((btCollisionObject *)LODWORD(v56), v41);
      applyAnisotropicFriction(colObj, v47);
      btSequentialImpulseConstraintSolver::addFrictionConstraint(
        v49,
        a3,
        v9,
        v49,
        solverBodyB,
        (btManifoldPoint *)i,
        (btManifoldPoint *)&v74,
        (btVector3 *)&v73.m_floats[2],
        (btCollisionObject *)LODWORD(v56),
        v48,
        v63,
        COERCE_CONST_BTVECTOR3_(0.0),
        COERCE_CONST_BTVECTOR3_(0.0),
        v54);
      goto LABEL_46;
    }
  }
}
