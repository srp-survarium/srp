void __thiscall btDiscreteDynamicsWorld::solveConstraints_::_2_::InplaceSolverIslandCallback::ProcessIsland(
        btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback *this,
        btCollisionObject **bodies,
        int numBodies,
        btPersistentManifold **manifolds,
        int numManifolds,
        int islandId)
{
  int v6; // edx
  int m_numConstraints; // eax
  btTypedConstraint **m_sortedConstraints; // ebx
  int m_islandTag1; // edi
  int v11; // eax
  btTypedConstraint **v12; // edi
  int v13; // edx
  btContactSolverInfo *m_solverInfo; // eax
  int m_capacity; // ecx
  int m_size; // eax
  int v17; // edi
  int v18; // edx
  int v19; // eax
  btCollisionObject **v20; // ecx
  btCollisionObject **v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // edi
  int v25; // edx
  int v26; // eax
  btPersistentManifold **v27; // ecx
  btPersistentManifold **v28; // eax
  int v29; // ecx
  int v30; // eax
  int v31; // edi
  int v32; // edx
  int v33; // eax
  btTypedConstraint **v34; // ecx
  btTypedConstraint **v35; // eax
  btContactSolverInfo *v36; // ecx
  btTypedConstraint **v37; // [esp+8h] [ebp-Ch]
  btCollisionObject **v38; // [esp+Ch] [ebp-8h]
  int v39; // [esp+10h] [ebp-4h]
  btPersistentManifold **v40; // [esp+20h] [ebp+Ch]
  btTypedConstraint **v41; // [esp+20h] [ebp+Ch]
  int i; // [esp+2Ch] [ebp+18h]
  int j; // [esp+2Ch] [ebp+18h]
  int k; // [esp+2Ch] [ebp+18h]

  v6 = 0;
  m_numConstraints = this->m_numConstraints;
  if ( islandId >= 0 )
  {
    v37 = 0;
    v39 = 0;
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
      v37 = &this->m_sortedConstraints[v6];
LABEL_12:
      if ( v6 < m_numConstraints )
      {
        v11 = m_numConstraints - v6;
        v12 = &this->m_sortedConstraints[v6];
        do
        {
          v13 = (*v12)->m_rbA->m_islandTag1;
          if ( v13 < 0 )
            v13 = (*v12)->m_rbB->m_islandTag1;
          if ( v13 == islandId )
            ++v39;
          ++v12;
          --v11;
        }
        while ( v11 );
      }
    }
    m_solverInfo = this->m_solverInfo;
    if ( m_solverInfo->m_minimumSolverBatchSize > 1 )
    {
      for ( i = 0; i < numBodies; ++i )
      {
        m_capacity = this->m_bodies.m_capacity;
        m_size = this->m_bodies.m_size;
        if ( m_size == m_capacity )
        {
          v17 = m_size ? 2 * m_size : 1;
          if ( m_capacity < v17 )
          {
            if ( v17 )
              v38 = (btCollisionObject **)btAlignedAllocInternal(4 * v17);
            else
              v38 = 0;
            v18 = this->m_bodies.m_size;
            v19 = 0;
            if ( v18 > 0 )
            {
              v20 = v38;
              do
              {
                if ( v20 )
                  *v20 = this->m_bodies.m_data[v19];
                ++v19;
                ++v20;
              }
              while ( v19 < v18 );
            }
            if ( this->m_bodies.m_data )
            {
              if ( this->m_bodies.m_ownsMemory )
                btAlignedFreeInternal(this->m_bodies.m_data);
              this->m_bodies.m_data = 0;
            }
            this->m_bodies.m_ownsMemory = 1;
            this->m_bodies.m_data = v38;
            this->m_bodies.m_capacity = v17;
          }
        }
        v21 = &this->m_bodies.m_data[this->m_bodies.m_size];
        if ( v21 )
          *v21 = bodies[i];
        ++this->m_bodies.m_size;
      }
      for ( j = 0; j < numManifolds; ++j )
      {
        v22 = this->m_manifolds.m_capacity;
        v23 = this->m_manifolds.m_size;
        if ( v23 == v22 )
        {
          v24 = v23 ? 2 * v23 : 1;
          if ( v22 < v24 )
          {
            if ( v24 )
              v40 = (btPersistentManifold **)btAlignedAllocInternal(4 * v24);
            else
              v40 = 0;
            v25 = this->m_manifolds.m_size;
            v26 = 0;
            if ( v25 > 0 )
            {
              v27 = v40;
              do
              {
                if ( v27 )
                  *v27 = this->m_manifolds.m_data[v26];
                ++v26;
                ++v27;
              }
              while ( v26 < v25 );
            }
            if ( this->m_manifolds.m_data )
            {
              if ( this->m_manifolds.m_ownsMemory )
                btAlignedFreeInternal(this->m_manifolds.m_data);
              this->m_manifolds.m_data = 0;
            }
            this->m_manifolds.m_ownsMemory = 1;
            this->m_manifolds.m_data = v40;
            this->m_manifolds.m_capacity = v24;
          }
        }
        v28 = &this->m_manifolds.m_data[this->m_manifolds.m_size];
        if ( v28 )
          *v28 = manifolds[j];
        ++this->m_manifolds.m_size;
      }
      for ( k = 0; k < v39; ++k )
      {
        v29 = this->m_constraints.m_capacity;
        v30 = this->m_constraints.m_size;
        if ( v30 == v29 )
        {
          v31 = v30 ? 2 * v30 : 1;
          if ( v29 < v31 )
          {
            if ( v31 )
              v41 = (btTypedConstraint **)btAlignedAllocInternal(4 * v31);
            else
              v41 = 0;
            v32 = this->m_constraints.m_size;
            v33 = 0;
            if ( v32 > 0 )
            {
              v34 = v41;
              do
              {
                if ( v34 )
                  *v34 = this->m_constraints.m_data[v33];
                ++v33;
                ++v34;
              }
              while ( v33 < v32 );
            }
            if ( this->m_constraints.m_data )
            {
              if ( this->m_constraints.m_ownsMemory )
                btAlignedFreeInternal(this->m_constraints.m_data);
              this->m_constraints.m_data = 0;
            }
            this->m_constraints.m_ownsMemory = 1;
            this->m_constraints.m_data = v41;
            this->m_constraints.m_capacity = v31;
          }
        }
        v35 = &this->m_constraints.m_data[this->m_constraints.m_size];
        if ( v35 )
          *v35 = v37[k];
        ++this->m_constraints.m_size;
      }
      v36 = this->m_solverInfo;
      if ( this->m_manifolds.m_size + this->m_constraints.m_size > v36->m_minimumSolverBatchSize )
        btDiscreteDynamicsWorld::solveConstraints_::_2_::InplaceSolverIslandCallback::processConstraints(
          (btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback *)v36,
          (int)this);
    }
    else if ( v39 + numManifolds )
    {
      this->m_solver->solveGroup(
        this->m_solver,
        bodies,
        numBodies,
        manifolds,
        numManifolds,
        v37,
        v39,
        m_solverInfo,
        this->m_debugDrawer,
        this->m_stackAlloc,
        this->m_dispatcher);
    }
  }
  else if ( m_numConstraints + numManifolds )
  {
    this->m_solver->solveGroup(
      this->m_solver,
      bodies,
      numBodies,
      manifolds,
      numManifolds,
      this->m_sortedConstraints,
      m_numConstraints,
      this->m_solverInfo,
      this->m_debugDrawer,
      this->m_stackAlloc,
      this->m_dispatcher);
  }
}
