void __thiscall btCollisionWorld::convexSweepTest(
        btCollisionWorld *this,
        const btCollisionWorld *castShape,
        btConvexShape *convexFromWorld,
        const btTransform *convexToWorld,
        const btTransform *resultCallback,
        btCollisionWorld::ConvexResultCallback *allowedCcdPenetration,
        float allowedCcdPenetrationa)
{
  CProfileNode *Sub_Node; // eax
  int RecursionCounter; // ecx
  CProfileNode *v9; // ecx
  float v10; // [esp+BA0h] [ebp-1F0h]
  btVector3 linvel; // [esp+BB0h] [ebp-1E0h] BYREF
  btTransform curTrans; // [esp+BC0h] [ebp-1D0h] BYREF
  btVector3 v13; // [esp+C00h] [ebp-190h] BYREF
  btTransform transform0; // [esp+C10h] [ebp-180h] BYREF
  btTransform transform1; // [esp+C50h] [ebp-140h] BYREF
  btVector3 temporalAabbMin; // [esp+C90h] [ebp-100h] BYREF
  btVector3 temporalAabbMax; // [esp+CA0h] [ebp-F0h] BYREF
  btVector3 angvel; // [esp+CB0h] [ebp-E0h] BYREF
  btSingleSweepCallback v19; // [esp+CC0h] [ebp-D0h] BYREF

  Sub_Node = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "convexSweepTest" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
  transform0 = *convexToWorld;
  transform1.m_basis.m_el[0].mVec128.m128_u64[0] = resultCallback->m_basis.m_el[0].mVec128.m128_u64[0];
  transform1.m_basis.m_el[0].mVec128.m128_u64[1] = resultCallback->m_basis.m_el[0].mVec128.m128_u64[1];
  transform1.m_basis.m_el[1] = resultCallback->m_basis.m_el[1];
  transform1.m_basis.m_el[2] = resultCallback->m_basis.m_el[2];
  transform1.m_origin.mVec128.m128_u64[0] = resultCallback->m_origin.mVec128.m128_u64[0];
  transform1.m_origin.mVec128.m128_u64[1] = resultCallback->m_origin.mVec128.m128_u64[1];
  btTransformUtil::calculateVelocity(&transform1, &v13, &angvel, &transform0, 1.0);
  memset(&linvel, 0, sizeof(linvel));
  curTrans.m_basis.m_el[0].mVec128.m128_u64[0] = (unsigned int)clear_value;
  memset(&curTrans.m_basis.m_el[0].m_floats[2], 0, 12);
  *(unsigned __int64 *)((char *)curTrans.m_basis.m_el[1].mVec128.m128_u64 + 4) = (unsigned int)clear_value;
  memset(&curTrans.m_basis.m_el[1].m_floats[3], 0, 12);
  curTrans.m_basis.m_el[2].mVec128.m128_u64[1] = (unsigned int)clear_value;
  memset(&curTrans.m_origin, 0, sizeof(curTrans.m_origin));
  btMatrix3x3::getRotation((btMatrix3x3 *)&v13, (float *)&transform0, (btQuaternion *)&v13);
  btMatrix3x3::setRotation((btMatrix3x3 *)&v13, (int)&curTrans);
  btCollisionShape::calculateTemporalAabb(
    convexFromWorld,
    &curTrans,
    &linvel,
    &angvel,
    v10,
    &temporalAabbMin,
    &temporalAabbMax);
  btSingleSweepCallback::btSingleSweepCallback(
    &v19,
    convexToWorld,
    resultCallback,
    convexFromWorld,
    castShape,
    allowedCcdPenetration,
    allowedCcdPenetrationa);
  castShape->m_broadphasePairCache->rayTest(
    castShape->m_broadphasePairCache,
    &transform0.m_origin,
    &transform1.m_origin,
    &v19,
    &temporalAabbMin,
    &temporalAabbMax);
  v19.__vftable = (btSingleSweepCallback_vtbl *)&btBroadphaseAabbCallback::`vftable';
  if ( CProfileNode::Return(v9) )
    CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
}
