void __thiscall btSoftRigidDynamicsWorld::rayTest(
        btSoftRigidDynamicsWorld *this,
        const btVector3 *rayFromWorld,
        const btVector3 *rayToWorld,
        btCollisionWorld::RayResultCallback *resultCallback)
{
  CProfileNode *v4; // eax
  int RecursionCounter; // ecx
  btBroadphaseInterface *m_broadphasePairCache; // ecx
  CProfileNode *v8; // ecx
  _DWORD v10[4]; // [esp+100h] [ebp-110h] BYREF
  _DWORD v11[4]; // [esp+110h] [ebp-100h] BYREF
  btSoftSingleRayCallback v12; // [esp+120h] [ebp-F0h] BYREF

  v4 = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "rayTest" )
  {
    CProfileNode::Get_Sub_Node((const char *)this, "rayTest");
    CProfileManager::CurrentNode = v4;
  }
  RecursionCounter = v4->RecursionCounter;
  ++v4->TotalCalls;
  v4->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
    v4->StartTime = btClock::getTimeMicroseconds(0);
  btSoftSingleRayCallback::btSoftSingleRayCallback(&v12, rayFromWorld, rayToWorld, this, resultCallback);
  m_broadphasePairCache = this->m_broadphasePairCache;
  memset(v10, 0, sizeof(v10));
  memset(v11, 0, sizeof(v11));
  m_broadphasePairCache->rayTest(
    m_broadphasePairCache,
    rayFromWorld,
    rayToWorld,
    &v12,
    (const btVector3 *)v11,
    (const btVector3 *)v10);
  v12.__vftable = (btSoftSingleRayCallback_vtbl *)&btBroadphaseAabbCallback::`vftable';
  if ( CProfileNode::Return(v8) )
    CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
}
