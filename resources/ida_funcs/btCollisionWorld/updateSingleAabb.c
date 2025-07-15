void __usercall btCollisionWorld::updateSingleAabb(btCollisionWorld *this@<esi>, btCollisionObject *colObj@<edi>)
{
  bool v2; // zf
  float v3; // xmm5_4
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  int m_activationState1; // eax
  btIDebugDraw *m_debugDrawer; // ecx
  void (__thiscall *reportErrorWarning)(btIDebugDraw *, const char *); // edx
  float v12; // [esp+F0h] [ebp-50h] BYREF
  float v13; // [esp+F4h] [ebp-4Ch]
  float v14; // [esp+F8h] [ebp-48h]
  float v15; // [esp+FCh] [ebp-44h]
  float v16; // [esp+100h] [ebp-40h] BYREF
  float v17; // [esp+104h] [ebp-3Ch]
  float v18; // [esp+108h] [ebp-38h]
  float v19; // [esp+10Ch] [ebp-34h]
  float v20; // [esp+110h] [ebp-30h] BYREF
  float v21; // [esp+114h] [ebp-2Ch]
  float v22; // [esp+118h] [ebp-28h]
  float v23; // [esp+11Ch] [ebp-24h]
  float v24; // [esp+120h] [ebp-20h]
  float v25; // [esp+124h] [ebp-1Ch]
  float v26; // [esp+128h] [ebp-18h]
  float v27; // [esp+130h] [ebp-10h] BYREF
  float v28; // [esp+134h] [ebp-Ch]
  float v29; // [esp+138h] [ebp-8h]
  float v30; // [esp+13Ch] [ebp-4h]

  colObj->m_collisionShape->getAabb(
    colObj->m_collisionShape,
    &colObj->m_worldTransform,
    (btVector3 *)&v16,
    (btVector3 *)&v12);
  v2 = !this->m_dispatchInfo.m_useContinuous;
  v3 = v17 - gContactBreakingThreshold;
  v4 = v13 + gContactBreakingThreshold;
  v25 = gContactBreakingThreshold;
  v5 = v16 - gContactBreakingThreshold;
  v24 = gContactBreakingThreshold;
  v6 = gContactBreakingThreshold + v12;
  v7 = v18 - gContactBreakingThreshold;
  v8 = v14 + gContactBreakingThreshold;
  v26 = gContactBreakingThreshold;
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
      (btVector3 *)&v20);
    v22 = v22 + v26;
    v5 = v16;
    if ( v16 > (float)(v27 - v24) )
    {
      v5 = v27 - v24;
      v16 = v27 - v24;
    }
    v3 = v17;
    if ( v17 > (float)(v28 - v25) )
    {
      v3 = v28 - v25;
      v17 = v28 - v25;
    }
    v7 = v18;
    if ( v18 > (float)(v29 - v26) )
    {
      v7 = v29 - v26;
      v18 = v29 - v26;
    }
    if ( v19 > v30 )
      v19 = v30;
    v6 = v12;
    if ( (float)(v20 + v24) > v12 )
    {
      v6 = v20 + v24;
      v12 = v20 + v24;
    }
    v4 = v13;
    if ( (float)(v21 + v25) > v13 )
    {
      v4 = v21 + v25;
      v13 = v21 + v25;
    }
    v8 = v14;
    if ( v22 > v14 )
    {
      v8 = v22;
      v14 = v22;
    }
    if ( v23 > v15 )
      v15 = v23;
  }
  if ( (colObj->m_collisionFlags & 1) != 0
    || (float)((float)((float)((float)(v8 - v7) * (float)(v8 - v7)) + (float)((float)(v4 - v3) * (float)(v4 - v3)))
             + (float)((float)(v6 - v5) * (float)(v6 - v5))) < 1.0e12 )
  {
    this->m_broadphasePairCache->setAabb(
      this->m_broadphasePairCache,
      colObj->m_broadphaseHandle,
      (const btVector3 *)&v16,
      (const btVector3 *)&v12,
      this->m_dispatcher1);
  }
  else
  {
    m_activationState1 = colObj->m_activationState1;
    if ( m_activationState1 != 4 && m_activationState1 != 5 )
      colObj->m_activationState1 = 5;
    if ( reportMe )
    {
      if ( this->m_debugDrawer )
      {
        m_debugDrawer = this->m_debugDrawer;
        reportErrorWarning = m_debugDrawer->reportErrorWarning;
        reportMe = 0;
        reportErrorWarning(m_debugDrawer, "Overflow in AABB, object removed from simulation");
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
