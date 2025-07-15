void __thiscall btSoftRigidDynamicsWorld::internalSingleStepSimulation(btSoftRigidDynamicsWorld *this, float timeStep)
{
  int v3; // ebx

  v3 = 0;
  this->m_softBodySolver->optimize(this->m_softBodySolver, &this->m_softBodies, 0);
  this->m_softBodySolver->checkInitialized(this->m_softBodySolver);
  btDiscreteDynamicsWorld::internalSingleStepSimulation(this, timeStep);
  if ( this->m_softBodies.m_size )
    btSoftBody::solveClusters((int)&this->m_softBodies);
  ((void (__stdcall *)(_DWORD))this->m_softBodySolver->solveConstraints)(this->m_softBodySolver->m_timeScale * timeStep);
  if ( this->m_softBodies.m_size > 0 )
  {
    do
    {
      btSoftBody::defaultCollisionHandler(this->m_softBodies.m_data[v3], this->m_softBodies.m_data[v3]);
      ++v3;
    }
    while ( v3 < this->m_softBodies.m_size );
  }
  this->m_softBodySolver->updateSoftBodies(this->m_softBodySolver);
}
