void __thiscall btCollisionWorld::rayTest(
        btCollisionWorld *this,
        const btVector3 *rayFromWorld,
        const btVector3 *rayToWorld,
        btCollisionWorld::RayResultCallback *resultCallback)
{
  btBroadphaseInterface *m_broadphasePairCache; // ecx
  _DWORD v6[4]; // [esp+10h] [ebp-110h] BYREF
  _DWORD v7[4]; // [esp+20h] [ebp-100h] BYREF
  btSingleRayCallback v8; // [esp+30h] [ebp-F0h] BYREF

  btSingleRayCallback::btSingleRayCallback(&v8, rayFromWorld, rayToWorld, resultCallback);
  m_broadphasePairCache = this->m_broadphasePairCache;
  memset(v7, 0, sizeof(v7));
  memset(v6, 0, sizeof(v6));
  m_broadphasePairCache->rayTest(
    m_broadphasePairCache,
    rayFromWorld,
    rayToWorld,
    &v8,
    (const btVector3 *)v6,
    (const btVector3 *)v7);
}
