void __userpurge btDynamicsWorld::btDynamicsWorld(
        btDynamicsWorld *this@<esi>,
        btDispatcher *dispatcher@<eax>,
        btCollisionConfiguration *collisionConfiguration@<ecx>,
        btBroadphaseInterface *broadphase)
{
  float v4; // xmm1_4
  btStackAlloc *v5; // eax
  float v6; // xmm1_4

  v4 = s_bm_current_air_resistance;
  this->__vftable = (btDynamicsWorld_vtbl *)&btCollisionWorld::`vftable';
  this->m_collisionObjects.m_ownsMemory = 1;
  this->m_collisionObjects.m_data = 0;
  this->m_collisionObjects.m_size = 0;
  this->m_collisionObjects.m_capacity = 0;
  this->m_dispatcher1 = dispatcher;
  this->m_dispatchInfo.m_timeOfImpact = v4;
  this->m_dispatchInfo.m_timeStep = 0.0;
  this->m_dispatchInfo.m_stepCount = 0;
  this->m_dispatchInfo.m_dispatchFunc = 1;
  this->m_dispatchInfo.m_useContinuous = 1;
  this->m_dispatchInfo.m_debugDraw = 0;
  this->m_dispatchInfo.m_enableSatConvex = 0;
  this->m_dispatchInfo.m_enableSPU = 1;
  this->m_dispatchInfo.m_useEpa = 1;
  this->m_dispatchInfo.m_allowedCcdPenetration = FLOAT_0_039999999;
  this->m_dispatchInfo.m_useConvexConservativeDistanceUtil = 0;
  this->m_dispatchInfo.m_convexConservativeDistanceThreshold = 0.0;
  this->m_dispatchInfo.m_stackAllocator = 0;
  this->m_broadphasePairCache = broadphase;
  this->m_debugDrawer = 0;
  this->m_forceUpdateAllAabbs = 1;
  v5 = collisionConfiguration->getStackAllocator(collisionConfiguration);
  v6 = s_bm_current_air_resistance;
  this->m_stackAlloc = v5;
  this->m_dispatchInfo.m_stackAllocator = v5;
  this->m_internalTickCallback = 0;
  this->m_internalPreTickCallback = 0;
  this->m_worldUserInfo = 0;
  this->__vftable = (btDynamicsWorld_vtbl *)&btDynamicsWorld::`vftable';
  this->m_solverInfo.m_tau = FLOAT_0_60000002;
  this->m_solverInfo.m_friction = s_aim_transition_time;
  this->m_solverInfo.m_maxErrorReduction = FLOAT_20_0;
  this->m_solverInfo.m_damping = v6;
  this->m_solverInfo.m_restitution = 0.0;
  this->m_solverInfo.m_erp = FLOAT_0_2;
  this->m_solverInfo.m_globalCfm = 0.0;
  this->m_solverInfo.m_sor = v6;
  this->m_solverInfo.m_linearSlop = 0.0;
  this->m_solverInfo.m_splitImpulse = 0;
  this->m_solverInfo.m_numIterations = 10;
  this->m_solverInfo.m_erp2 = FLOAT_0_1;
  this->m_solverInfo.m_splitImpulsePenetrationThreshold = FLOAT_N0_02;
  this->m_solverInfo.m_warmstartingFactor = FLOAT_0_85000002;
  this->m_solverInfo.m_solverMode = 260;
  this->m_solverInfo.m_restingContactRestitutionThreshold = 2;
  this->m_solverInfo.m_minimumSolverBatchSize = 128;
}
