void __thiscall btDiscreteDynamicsWorld::solveConstraints_::_2_::InplaceSolverIslandCallback::ProcessIsland(
        btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback *this,
        btCollisionObject **bodies,
        int numBodies,
        btPersistentManifold **manifolds,
        int numManifolds,
        int islandId)
{
  int v6; // eax
  int v8; // eax
  int m_numConstraints; // ecx
  btTypedConstraint **m_sortedConstraints; // ebp
  int m_islandTag1; // edi
  int v12; // ebx
  btTypedConstraint **v13; // edi
  int v14; // ecx
  int v15; // edx
  btContactSolverInfo *m_solverInfo; // eax
  int v17; // edi
  int v18; // ebp
  int m_capacity; // ecx
  int m_size; // eax
  btCollisionObject **v21; // ebx
  int v22; // edx
  int v23; // eax
  btCollisionObject **v24; // ecx
  btCollisionObject **m_data; // eax
  btCollisionObject **v26; // eax
  int v27; // ebp
  int v28; // ecx
  int v29; // eax
  btPersistentManifold **v30; // ebx
  int v31; // edx
  int v32; // eax
  btPersistentManifold **v33; // ecx
  btPersistentManifold **v34; // eax
  btPersistentManifold **v35; // eax
  int v36; // ebp
  int v37; // ecx
  int v38; // eax
  btTypedConstraint **v39; // ebx
  int v40; // edx
  int v41; // eax
  btTypedConstraint **v42; // ecx
  btTypedConstraint **v43; // eax
  btTypedConstraint **v44; // eax
  btContactSolverInfo *v45; // ecx
  int numCurConstraints; // [esp+Ch] [ebp-8h]
  btTypedConstraint **startConstraint; // [esp+10h] [ebp-4h]
  int i; // [esp+28h] [ebp+14h]
  int ia; // [esp+28h] [ebp+14h]
  int ib; // [esp+28h] [ebp+14h]

  v6 = 0;
  if ( islandId >= 0 )
  {
    m_numConstraints = this->m_numConstraints;
    startConstraint = 0;
    numCurConstraints = 0;
    if ( m_numConstraints > 0 )
    {
      m_sortedConstraints = this->m_sortedConstraints;
      while ( 1 )
      {
        m_islandTag1 = (*m_sortedConstraints)->m_rbA->m_islandTag1;
        if ( m_islandTag1 < 0 )
          m_islandTag1 = (*m_sortedConstraints)->m_rbB->m_islandTag1;
        if ( m_islandTag1 == islandId )
          break;
        ++v6;
        ++m_sortedConstraints;
        if ( v6 >= m_numConstraints )
          goto LABEL_12;
      }
      startConstraint = &this->m_sortedConstraints[v6];
LABEL_12:
      if ( v6 < m_numConstraints )
      {
        v12 = 0;
        v13 = &this->m_sortedConstraints[v6];
        v14 = m_numConstraints - v6;
        do
        {
          v15 = (*v13)->m_rbA->m_islandTag1;
          if ( v15 < 0 )
            v15 = (*v13)->m_rbB->m_islandTag1;
          if ( v15 == islandId )
            ++v12;
          ++v13;
          --v14;
        }
        while ( v14 );
        numCurConstraints = v12;
      }
    }
    m_solverInfo = this->m_solverInfo;
    v17 = 1;
    if ( m_solverInfo->m_minimumSolverBatchSize > 1 )
    {
      v18 = 0;
      for ( i = 0; v18 < numBodies; i = v18 )
      {
        m_capacity = this->m_bodies.m_capacity;
        m_size = this->m_bodies.m_size;
        if ( m_size == m_capacity )
        {
          if ( m_size )
            v17 = 2 * m_size;
          if ( m_capacity < v17 )
          {
            if ( v17 )
            {
              ++gNumAlignedAllocs;
              v21 = (btCollisionObject **)sAlignedAllocFunc(4 * v17, 16);
            }
            else
            {
              v21 = 0;
            }
            v22 = this->m_bodies.m_size;
            v23 = 0;
            if ( v22 > 0 )
            {
              v24 = v21;
              do
              {
                if ( v24 )
                  *v24 = this->m_bodies.m_data[v23];
                ++v23;
                ++v24;
              }
              while ( v23 < v22 );
              v18 = i;
            }
            m_data = this->m_bodies.m_data;
            if ( m_data )
            {
              if ( this->m_bodies.m_ownsMemory )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(m_data);
              }
              this->m_bodies.m_data = 0;
            }
            this->m_bodies.m_ownsMemory = 1;
            this->m_bodies.m_data = v21;
            this->m_bodies.m_capacity = v17;
          }
        }
        v26 = &this->m_bodies.m_data[this->m_bodies.m_size];
        if ( v26 )
          *v26 = bodies[v18];
        v17 = 1;
        ++this->m_bodies.m_size;
        ++v18;
      }
      v27 = 0;
      for ( ia = 0; v27 < numManifolds; ia = v27 )
      {
        v28 = this->m_manifolds.m_capacity;
        v29 = this->m_manifolds.m_size;
        if ( v29 == v28 )
        {
          if ( v29 )
            v17 = 2 * v29;
          if ( v28 < v17 )
          {
            if ( v17 )
            {
              ++gNumAlignedAllocs;
              v30 = (btPersistentManifold **)sAlignedAllocFunc(4 * v17, 16);
            }
            else
            {
              v30 = 0;
            }
            v31 = this->m_manifolds.m_size;
            v32 = 0;
            if ( v31 > 0 )
            {
              v33 = v30;
              do
              {
                if ( v33 )
                  *v33 = this->m_manifolds.m_data[v32];
                ++v32;
                ++v33;
              }
              while ( v32 < v31 );
              v27 = ia;
            }
            v34 = this->m_manifolds.m_data;
            if ( v34 )
            {
              if ( this->m_manifolds.m_ownsMemory )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(v34);
              }
              this->m_manifolds.m_data = 0;
            }
            this->m_manifolds.m_ownsMemory = 1;
            this->m_manifolds.m_data = v30;
            this->m_manifolds.m_capacity = v17;
          }
        }
        v35 = &this->m_manifolds.m_data[this->m_manifolds.m_size];
        if ( v35 )
          *v35 = manifolds[v27];
        v17 = 1;
        ++this->m_manifolds.m_size;
        ++v27;
      }
      v36 = 0;
      for ( ib = 0; v36 < numCurConstraints; ib = v36 )
      {
        v37 = this->m_constraints.m_capacity;
        v38 = this->m_constraints.m_size;
        if ( v38 == v37 )
        {
          if ( v38 )
            v17 = 2 * v38;
          if ( v37 < v17 )
          {
            if ( v17 )
            {
              ++gNumAlignedAllocs;
              v39 = (btTypedConstraint **)sAlignedAllocFunc(4 * v17, 16);
            }
            else
            {
              v39 = 0;
            }
            v40 = this->m_constraints.m_size;
            v41 = 0;
            if ( v40 > 0 )
            {
              v42 = v39;
              do
              {
                if ( v42 )
                  *v42 = this->m_constraints.m_data[v41];
                ++v41;
                ++v42;
              }
              while ( v41 < v40 );
              v36 = ib;
            }
            v43 = this->m_constraints.m_data;
            if ( v43 )
            {
              if ( this->m_constraints.m_ownsMemory )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(v43);
              }
              this->m_constraints.m_data = 0;
            }
            this->m_constraints.m_ownsMemory = 1;
            this->m_constraints.m_data = v39;
            this->m_constraints.m_capacity = v17;
          }
        }
        v44 = &this->m_constraints.m_data[this->m_constraints.m_size];
        if ( v44 )
          *v44 = startConstraint[v36];
        v17 = 1;
        ++this->m_constraints.m_size;
        ++v36;
      }
      v45 = this->m_solverInfo;
      if ( this->m_manifolds.m_size + this->m_constraints.m_size > v45->m_minimumSolverBatchSize )
        btDiscreteDynamicsWorld::solveConstraints_::_2_::InplaceSolverIslandCallback::processConstraints(
          (btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback *)v45,
          (int)this);
    }
    else if ( numCurConstraints + numManifolds )
    {
      this->m_solver->solveGroup(
        this->m_solver,
        bodies,
        numBodies,
        manifolds,
        numManifolds,
        startConstraint,
        numCurConstraints,
        m_solverInfo,
        this->m_debugDrawer,
        this->m_stackAlloc,
        this->m_dispatcher);
    }
  }
  else
  {
    v8 = this->m_numConstraints;
    if ( v8 + numManifolds )
      this->m_solver->solveGroup(
        this->m_solver,
        bodies,
        numBodies,
        manifolds,
        numManifolds,
        this->m_sortedConstraints,
        v8,
        this->m_solverInfo,
        this->m_debugDrawer,
        this->m_stackAlloc,
        this->m_dispatcher);
  }
}
