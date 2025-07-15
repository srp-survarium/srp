void __userpurge btCollisionWorld::rayTestSingle_::_22_::BridgeTriangleRaycastCallback::BridgeTriangleRaycastCallback(
        const btVector3 *from@<edi>,
        const btVector3 *to@<esi>,
        btCollisionWorld::RayResultCallback *resultCallback@<edx>,
        const btTransform *colObjWorldTransform@<ecx>,
        btCollisionWorld::rayTestSingle::__l22::BridgeTriangleRaycastCallback *this,
        btCollisionObject *collisionObject,
        btTriangleMeshShape *triangleMesh)
{
  unsigned int m_flags; // ebx
  unsigned __int64 v8; // xmm0_8

  m_flags = resultCallback->m_flags;
  this->__vftable = (btCollisionWorld::rayTestSingle::__l22::BridgeTriangleRaycastCallback_vtbl *)&btTriangleRaycastCallback::`vftable';
  this->m_from = (btVector3)from->mVec128;
  this->m_to.mVec128.m128_u64[0] = to->mVec128.m128_u64[0];
  v8 = to->mVec128.m128_u64[1];
  this->m_resultCallback = resultCallback;
  this->m_collisionObject = collisionObject;
  this->m_to.mVec128.m128_u64[1] = v8;
  LODWORD(v8) = clear_value;
  this->m_flags = m_flags;
  LODWORD(this->m_hitFraction) = v8;
  this->__vftable = (btCollisionWorld::rayTestSingle::__l22::BridgeTriangleRaycastCallback_vtbl *)&`btCollisionWorld::rayTestSingle'::`22'::BridgeTriangleRaycastCallback::`vftable';
  this->m_triangleMesh = triangleMesh;
  this->m_colObjWorldTransform = *colObjWorldTransform;
}
