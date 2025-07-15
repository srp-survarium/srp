void __userpurge btCollisionWorld::contactPairTest(
        btCollisionObject *colObjB@<edi>,
        btCollisionWorld *this,
        btCollisionObject *colObjA,
        btCollisionWorld::ContactResultCallback *resultCallback)
{
  btCollisionAlgorithm *v4; // esi
  void (__thiscall *processCollision)(btCollisionAlgorithm *, btCollisionObject *, btCollisionObject *, const btDispatcherInfo *, btManifoldResult *); // eax
  btManifoldResult v6; // [esp+D0h] [ebp-C0h] BYREF
  btCollisionWorld::ContactResultCallback *v7; // [esp+180h] [ebp-10h]

  v4 = this->m_dispatcher1->findAlgorithm(this->m_dispatcher1, colObjA, colObjB, 0);
  if ( v4 )
  {
    btManifoldResult::btManifoldResult(&v6, colObjA, colObjB);
    processCollision = v4->processCollision;
    v7 = resultCallback;
    v6.__vftable = (btManifoldResult_vtbl *)&btBridgedManifoldResult::`vftable';
    processCollision(v4, colObjA, colObjB, &this->m_dispatchInfo, &v6);
    ((void (__thiscall *)(btCollisionAlgorithm *, _DWORD))v4->~btCollisionAlgorithm)(v4, 0);
    this->m_dispatcher1->freeCollisionAlgorithm(this->m_dispatcher1, v4);
  }
}
