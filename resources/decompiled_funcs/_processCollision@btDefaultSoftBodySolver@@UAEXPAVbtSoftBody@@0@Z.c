void __thiscall btDefaultSoftBodySolver::processCollision(
        btDefaultSoftBodySolver *this,
        btSoftBody *softBody,
        btSoftBody *otherSoftBody)
{
  btSoftBody::defaultCollisionHandler(softBody, otherSoftBody);
}
