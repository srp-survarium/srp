void __thiscall btSoftRigidDynamicsWorld::internalSingleStepSimulation(btSoftRigidDynamicsWorld *this, float timeStep)
{
  btSoftRigidDynamicsWorld *v3; // ecx
  int i; // esi

  this->m_softBodySolver->optimize(this->m_softBodySolver, &this->m_softBodies, 0);
  this->m_softBodySolver->checkInitialized(this->m_softBodySolver);
  btDiscreteDynamicsWorld::internalSingleStepSimulation(this, timeStep);
  btSoftRigidDynamicsWorld::solveSoftBodiesConstraints(v3, (int)this, timeStep);
  for ( i = 0; i < this->m_softBodies.m_size; ++i )
    btSoftBody::defaultCollisionHandler(this->m_softBodies.m_data[i], this->m_softBodies.m_data[i]);
  this->m_softBodySolver->updateSoftBodies(this->m_softBodySolver);
}
