void __usercall btCollisionWorld::updateSingleAabb(btCollisionWorld *this@<esi>, btCollisionObject *colObj@<edi>)
{
  bool v2; // zf
  float v3; // xmm5_4
  float v4; // xmm4_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  btCollisionObject *m_broadphasePairCache; // ecx
  btIDebugDraw *m_debugDrawer; // ecx
  btIDebugDraw_vtbl *v11; // eax
  float v12; // [esp+18h] [ebp-50h] BYREF
  float v13; // [esp+1Ch] [ebp-4Ch]
  float v14; // [esp+20h] [ebp-48h]
  float v15; // [esp+24h] [ebp-44h]
  float v16; // [esp+28h] [ebp-40h] BYREF
  float v17; // [esp+2Ch] [ebp-3Ch]
  float v18; // [esp+30h] [ebp-38h]
  float v19; // [esp+34h] [ebp-34h]
  float v20; // [esp+38h] [ebp-30h]
  float v21; // [esp+3Ch] [ebp-2Ch]
  float v22; // [esp+40h] [ebp-28h]
  float v23; // [esp+48h] [ebp-20h] BYREF
  float v24; // [esp+4Ch] [ebp-1Ch]
  float v25; // [esp+50h] [ebp-18h]
  float v26; // [esp+54h] [ebp-14h]
  float v27; // [esp+58h] [ebp-10h] BYREF
  float v28; // [esp+5Ch] [ebp-Ch]
  float v29; // [esp+60h] [ebp-8h]
  float v30; // [esp+64h] [ebp-4h]

  colObj->m_collisionShape->getAabb(
    colObj->m_collisionShape,
    &colObj->m_worldTransform,
    (btVector3 *)&v16,
    (btVector3 *)&v12);
  v2 = !this->m_dispatchInfo.m_useContinuous;
  v3 = v17 - gContactBreakingThreshold;
  v4 = v18 - gContactBreakingThreshold;
  v5 = v13 + gContactBreakingThreshold;
  v21 = gContactBreakingThreshold;
  v22 = gContactBreakingThreshold;
  v6 = v14 + gContactBreakingThreshold;
  v7 = v16 - gContactBreakingThreshold;
  v20 = gContactBreakingThreshold;
  v8 = gContactBreakingThreshold + v12;
  v16 = v16 - gContactBreakingThreshold;
  v17 = v17 - gContactBreakingThreshold;
  v18 = v18 - gContactBreakingThreshold;
  v12 = gContactBreakingThreshold + v12;
  v13 = v13 + gContactBreakingThreshold;
  v14 = v14 + gContactBreakingThreshold;
  if ( !v2 && colObj->m_internalType == 2 )
  {
    colObj->m_collisionShape->getAabb(
      colObj->m_collisionShape,
      &colObj->m_interpolationWorldTransform,
      (btVector3 *)&v27,
      (btVector3 *)&v23);
    v25 = v25 + v22;
    v7 = v16;
    if ( v16 > (float)(v27 - v20) )
    {
      v7 = v27 - v20;
      v16 = v27 - v20;
    }
    v3 = v17;
    if ( v17 > (float)(v28 - v21) )
    {
      v3 = v28 - v21;
      v17 = v28 - v21;
    }
    v4 = v18;
    if ( v18 > (float)(v29 - v22) )
    {
      v4 = v29 - v22;
      v18 = v29 - v22;
    }
    if ( v19 > v30 )
      v19 = v30;
    v8 = v12;
    if ( (float)(v23 + v20) > v12 )
    {
      v8 = v23 + v20;
      v12 = v23 + v20;
    }
    v5 = v13;
    if ( (float)(v24 + v21) > v13 )
    {
      v5 = v24 + v21;
      v13 = v24 + v21;
    }
    v6 = v14;
    if ( v25 > v14 )
    {
      v6 = v25;
      v14 = v25;
    }
    if ( v26 > v15 )
      v15 = v26;
  }
  m_broadphasePairCache = (btCollisionObject *)this->m_broadphasePairCache;
  if ( (colObj->m_collisionFlags & 1) != 0
    || (float)((float)((float)((float)(v6 - v4) * (float)(v6 - v4)) + (float)((float)(v5 - v3) * (float)(v5 - v3)))
             + (float)((float)(v8 - v7) * (float)(v8 - v7))) < 1.0e12 )
  {
    ((void (__thiscall *)(btCollisionObject *, btBroadphaseProxy *, float *, float *, btDispatcher *))m_broadphasePairCache->calculateSerializeBufferSize)(
      m_broadphasePairCache,
      colObj->m_broadphaseHandle,
      &v16,
      &v12,
      this->m_dispatcher1);
  }
  else
  {
    btCollisionObject::setActivationState(m_broadphasePairCache, (int)colObj, 5);
    if ( reportMe )
    {
      if ( this->m_debugDrawer )
      {
        m_debugDrawer = this->m_debugDrawer;
        v11 = m_debugDrawer->__vftable;
        reportMe = 0;
        v11->reportErrorWarning(m_debugDrawer, "Overflow in AABB, object removed from simulation");
        this->m_debugDrawer->reportErrorWarning(
          this->m_debugDrawer,
          "If you can reproduce this, please email bugs@continuousphysics.com\n");
        this->m_debugDrawer->reportErrorWarning(
          this->m_debugDrawer,
          "Please include above information, your Platform, version of OS.\n");
        this->m_debugDrawer->reportErrorWarning(this->m_debugDrawer, "Thanks.\n");
      }
    }
  }
}
