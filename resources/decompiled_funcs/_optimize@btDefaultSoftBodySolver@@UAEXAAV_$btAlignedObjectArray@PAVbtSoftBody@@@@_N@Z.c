void __thiscall btDefaultSoftBodySolver::optimize(
        btDefaultSoftBodySolver *this,
        btAlignedObjectArray<btSoftBody *> *softBodies,
        bool forceUpdate)
{
  btAlignedObjectArray<btSoftBody *>::copyFromArray(
    (btAlignedObjectArray<btSoftBody *> *)this,
    (int)&this->m_softBodySet,
    softBodies);
}
