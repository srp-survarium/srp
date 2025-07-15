void __thiscall btSoftRigidDynamicsWorld::predictUnconstraintMotion(btSoftRigidDynamicsWorld *this, float timeStep)
{
  btDiscreteDynamicsWorld::predictUnconstraintMotion(this, timeStep);
  ((void (__stdcall *)(_DWORD))this->m_softBodySolver->predictMotion)(LODWORD(timeStep));
}
