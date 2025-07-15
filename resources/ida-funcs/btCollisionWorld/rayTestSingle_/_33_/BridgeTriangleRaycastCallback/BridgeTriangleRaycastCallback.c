void __userpurge btCollisionWorld::rayTestSingle_::_33_::BridgeTriangleRaycastCallback::BridgeTriangleRaycastCallback(
        btCollisionWorld::rayTestSingle::__l33::BridgeTriangleRaycastCallback *this@<eax>,
        const btVector3 *from,
        const btVector3 *to,
        btCollisionWorld::RayResultCallback *resultCallback,
        btCollisionObject *collisionObject,
        btTriangleMeshShape *triangleMesh)
{
  _DWORD *v6; // eax
  _DWORD *v7; // edx

  btTriangleRaycastCallback::btTriangleRaycastCallback(this, resultCallback->m_flags, from, to);
  v6[17] = collisionObject;
  v6[16] = resultCallback;
  v6[18] = triangleMesh;
  *v6 = &`btCollisionWorld::rayTestSingle'::`33'::BridgeTriangleRaycastCallback::`vftable';
  v6[20] = *v7;
  v6[21] = v7[1];
  v6[22] = v7[2];
  v6[23] = v7[3];
  v6[24] = v7[4];
  v6[25] = v7[5];
  v6[26] = v7[6];
  v6[27] = v7[7];
  v6[28] = v7[8];
  v6[29] = v7[9];
  v6[30] = v7[10];
  v6[31] = v7[11];
  v6[32] = v7[12];
  v6[33] = v7[13];
  v6[34] = v7[14];
  v6[35] = v7[15];
}
