void __thiscall btDiscreteDynamicsWorld::predictUnconstraintMotion(btDiscreteDynamicsWorld *this, float timeStep)
{
  CProfileNode *Sub_Node; // ebx
  btDiscreteDynamicsWorld *v3; // edi
  int RecursionCounter; // eax
  btClock *v5; // ecx
  int v6; // eax
  btRigidBody *v7; // esi
  btRigidBody *v8; // ecx
  bool v9; // zf
  int *p_RecursionCounter; // esi
  int i; // [esp+18h] [ebp-8h]

  Sub_Node = CProfileManager::CurrentNode;
  v3 = this;
  if ( CProfileManager::CurrentNode->Name != "predictUnconstraintMotion" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  v5 = (btClock *)(RecursionCounter + 1);
  Sub_Node->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
  {
    Sub_Node->StartTime = btClock::getTimeMicroseconds(v5);
    Sub_Node = CProfileManager::CurrentNode;
  }
  v6 = 0;
  for ( i = 0; v6 < v3->m_nonStaticRigidBodies.m_size; i = v6 )
  {
    v7 = v3->m_nonStaticRigidBodies.m_data[v6];
    if ( (v7->m_collisionFlags & 3) == 0 )
    {
      btRigidBody::integrateVelocities((btRigidBody *)v5, timeStep);
      btRigidBody::applyDamping(v8, timeStep);
      btTransformUtil::integrateTransform(
        &v7->m_worldTransform,
        &v7->m_linearVelocity,
        &v7->m_angularVelocity,
        timeStep,
        &v7->m_interpolationWorldTransform);
      v6 = i;
      v3 = this;
    }
    ++v6;
  }
  v9 = Sub_Node->RecursionCounter-- == 1;
  p_RecursionCounter = &Sub_Node->RecursionCounter;
  if ( v9 && Sub_Node->TotalCalls )
  {
    Sub_Node->TotalTime = (double)(btClock::getTimeMicroseconds(v5) - Sub_Node->StartTime) * 0.001 + Sub_Node->TotalTime;
    Sub_Node = CProfileManager::CurrentNode;
  }
  if ( !*p_RecursionCounter )
    CProfileManager::CurrentNode = Sub_Node->Parent;
}
