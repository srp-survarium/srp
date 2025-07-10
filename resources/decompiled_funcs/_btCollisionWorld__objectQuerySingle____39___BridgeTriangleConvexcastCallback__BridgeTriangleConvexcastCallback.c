void __userpurge btCollisionWorld::objectQuerySingle_::_39_::BridgeTriangleConvexcastCallback::BridgeTriangleConvexcastCallback(
        btCollisionWorld::objectQuerySingle::__l39::BridgeTriangleConvexcastCallback *this@<esi>,
        const btConvexShape *castShape@<edi>,
        const btTransform *from,
        const btTransform *to,
        btCollisionWorld::ConvexResultCallback *resultCallback,
        btCollisionObject *collisionObject,
        btConcaveShape *triangleMesh,
        const btTransform *triangleToWorld)
{
  float triangleCollisionMargin; // [esp+0h] [ebp-8h]

  triangleCollisionMargin = triangleMesh->getMargin(triangleMesh);
  btTriangleConvexcastCallback::btTriangleConvexcastCallback(
    this,
    castShape,
    from,
    to,
    triangleToWorld,
    triangleCollisionMargin);
  this->m_triangleMesh = triangleMesh;
  this->__vftable = (btCollisionWorld::objectQuerySingle::__l39::BridgeTriangleConvexcastCallback_vtbl *)&`btCollisionWorld::objectQuerySingle'::`39'::BridgeTriangleConvexcastCallback::`vftable';
  this->m_resultCallback = resultCallback;
  this->m_collisionObject = collisionObject;
}
