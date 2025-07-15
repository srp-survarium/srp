void __thiscall btDefaultSoftBodySolver::processCollision(
        btDefaultSoftBodySolver *this,
        btSoftBody *softBody,
        btSoftBody *otherSoftBody)
{
  btSoftBody::defaultCollisionHandler(softBody, otherSoftBody);
}


// attributes: thunk
void __thiscall btDefaultSoftBodySolver::processCollision(
        btDefaultSoftBodySolver *this,
        btSoftBody *softBody,
        btCollisionObject *collisionObject)
{
  btSoftBody::defaultCollisionHandler((btSoftBody *)this, softBody);
}
