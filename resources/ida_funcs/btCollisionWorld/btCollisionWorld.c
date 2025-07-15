void __userpurge btCollisionWorld::btCollisionWorld(
        btCollisionWorld *this@<esi>,
        btCollisionConfiguration *collisionConfiguration@<ecx>,
        btDispatcher *dispatcher,
        btBroadphaseInterface *pairCache)
{
  const vostok::math::float4x4 *v4; // xmm1_4
  btStackAlloc *v5; // eax

  v4 = clear_value;
  this->__vftable = (btCollisionWorld_vtbl *)&btCollisionWorld::`vftable';
  this->m_collisionObjects.m_data = 0;
  this->m_collisionObjects.m_size = 0;
  this->m_collisionObjects.m_capacity = 0;
  this->m_collisionObjects.m_ownsMemory = 1;
  this->m_dispatcher1 = dispatcher;
  LODWORD(this->m_dispatchInfo.m_timeOfImpact) = v4;
  this->m_dispatchInfo.m_dispatchFunc = 1;
  this->m_dispatchInfo.m_useContinuous = 1;
  this->m_dispatchInfo.m_enableSPU = 1;
  this->m_dispatchInfo.m_useEpa = 1;
  this->m_dispatchInfo.m_timeStep = 0.0;
  this->m_dispatchInfo.m_stepCount = 0;
  this->m_dispatchInfo.m_debugDraw = 0;
  this->m_dispatchInfo.m_enableSatConvex = 0;
  this->m_dispatchInfo.m_allowedCcdPenetration = 0.039999999;
  this->m_dispatchInfo.m_useConvexConservativeDistanceUtil = 0;
  this->m_dispatchInfo.m_convexConservativeDistanceThreshold = 0.0;
  this->m_dispatchInfo.m_stackAllocator = 0;
  this->m_forceUpdateAllAabbs = 1;
  this->m_broadphasePairCache = pairCache;
  this->m_debugDrawer = 0;
  v5 = collisionConfiguration->getStackAllocator(collisionConfiguration);
  this->m_stackAlloc = v5;
  this->m_dispatchInfo.m_stackAllocator = v5;
}
