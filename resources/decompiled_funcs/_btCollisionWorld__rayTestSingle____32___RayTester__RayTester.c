void __userpurge btCollisionWorld::rayTestSingle_::_32_::RayTester::RayTester(
        btCollisionWorld::rayTestSingle::__l32::RayTester *this@<ecx>,
        btCollisionWorld::rayTestSingle::__l32::RayTester **a2@<eax>,
        const btCompoundShape *collisionObject,
        const btTransform *compoundShape,
        btCollisionWorld::rayTestSingle::__l32::RayTester *colObjWorldTransform,
        btCollisionWorld::rayTestSingle::__l32::RayTester *rayFromTrans,
        btCollisionWorld::RayResultCallback *rayToTrans,
        btCollisionWorld::RayResultCallback *resultCallback)
{
  *a2 = this;
  a2[1] = (btCollisionWorld::rayTestSingle::__l32::RayTester *)collisionObject;
  a2[2] = (btCollisionWorld::rayTestSingle::__l32::RayTester *)compoundShape;
  a2[3] = colObjWorldTransform;
  a2[4] = rayFromTrans;
  a2[5] = (btCollisionWorld::rayTestSingle::__l32::RayTester *)rayToTrans;
}
