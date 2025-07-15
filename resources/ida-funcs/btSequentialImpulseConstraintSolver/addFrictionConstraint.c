btSolverConstraint *__userpurge btSequentialImpulseConstraintSolver::addFrictionConstraint@<eax>(
        btSequentialImpulseConstraintSolver *this@<ecx>,
        float a2@<xmm10>,
        btSequentialImpulseConstraintSolver *normalAxis,
        btSequentialImpulseConstraintSolver *solverBodyA,
        btRigidBody *solverBodyB,
        btManifoldPoint *frictionIndex,
        btManifoldPoint *cp,
        const btVector3 *rel_pos1,
        btCollisionObject *rel_pos2,
        btCollisionObject *colObj0,
        btManifoldPoint *colObj1,
        const btVector3 *relaxation,
        const btVector3 *desiredVelocity,
        float cfmSlip)
{
  int m_size; // ebx
  int m_capacity; // eax
  int v17; // esi
  btSolverConstraint *v18; // eax
  int v19; // edx
  btSolverConstraint *m_data; // eax
  btSolverConstraint *v21; // esi
  float v23; // [esp+Ch] [ebp-18h]
  float v24; // [esp+10h] [ebp-14h]
  float v25; // [esp+14h] [ebp-10h]
  btSolverConstraint *v26; // [esp+1Ch] [ebp-8h]
  int v27; // [esp+20h] [ebp-4h]
  int thisa; // [esp+28h] [ebp+4h]

  m_size = normalAxis->m_tmpSolverContactFrictionConstraintPool.m_size;
  m_capacity = normalAxis->m_tmpSolverContactFrictionConstraintPool.m_capacity;
  if ( m_size == m_capacity )
  {
    if ( m_size )
    {
      v17 = 2 * m_size;
      thisa = 2 * m_size;
    }
    else
    {
      thisa = 1;
      v17 = 1;
    }
    if ( m_capacity < v17 )
    {
      if ( v17 )
      {
        ++gNumAlignedAllocs;
        v26 = (btSolverConstraint *)sAlignedAllocFunc(192 * v17, 16);
      }
      else
      {
        v26 = 0;
      }
      if ( normalAxis->m_tmpSolverContactFrictionConstraintPool.m_size > 0 )
      {
        v18 = v26;
        v19 = 0;
        v27 = normalAxis->m_tmpSolverContactFrictionConstraintPool.m_size;
        do
        {
          if ( v18 )
          {
            qmemcpy(v18, &normalAxis->m_tmpSolverContactFrictionConstraintPool.m_data[v19], sizeof(btSolverConstraint));
            v17 = thisa;
          }
          ++v19;
          ++v18;
          --v27;
        }
        while ( v27 );
      }
      m_data = normalAxis->m_tmpSolverContactFrictionConstraintPool.m_data;
      if ( m_data )
      {
        if ( normalAxis->m_tmpSolverContactFrictionConstraintPool.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(m_data);
        }
        normalAxis->m_tmpSolverContactFrictionConstraintPool.m_data = 0;
      }
      normalAxis->m_tmpSolverContactFrictionConstraintPool.m_ownsMemory = 1;
      normalAxis->m_tmpSolverContactFrictionConstraintPool.m_data = v26;
      normalAxis->m_tmpSolverContactFrictionConstraintPool.m_capacity = v17;
    }
  }
  ++normalAxis->m_tmpSolverContactFrictionConstraintPool.m_size;
  v21 = &normalAxis->m_tmpSolverContactFrictionConstraintPool.m_data[m_size];
  v21->m_frictionIndex = (int)solverBodyB;
  btSequentialImpulseConstraintSolver::setupFrictionConstraint(
    v21,
    rel_pos2,
    (unsigned int)colObj0,
    a2,
    solverBodyA,
    frictionIndex,
    &cp->m_localPointA,
    rel_pos1,
    colObj1,
    relaxation,
    desiredVelocity,
    v23,
    v24,
    v25);
  return v21;
}
