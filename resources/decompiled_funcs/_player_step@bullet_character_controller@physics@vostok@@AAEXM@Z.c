void __userpurge vostok::physics::bullet_character_controller::player_step(
        vostok::physics::bullet_character_controller *this@<ecx>,
        int a2@<eax>,
        float dt)
{
  CProfileNode *Sub_Node; // eax
  vostok::physics::bullet_character_controller *RecursionCounter; // ecx
  float v6; // xmm0_4
  char v7; // al
  float v8; // xmm0_4
  float v9; // xmm1_4
  int v10; // ecx
  CProfileNode *v11; // ecx
  const btVector3 *v12; // [esp+90h] [ebp-60h]
  btVector3 pos_up_correction; // [esp+A0h] [ebp-50h] BYREF
  btTransform worldTrans; // [esp+B0h] [ebp-40h] BYREF

  Sub_Node = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "player_step" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = (vostok::physics::bullet_character_controller *)Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = (int)&RecursionCounter->__vftable + 1;
  if ( !RecursionCounter )
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
  v6 = *(float *)(a2 + 232);
  *(_BYTE *)(a2 + 261) = 1;
  *(_BYTE *)(a2 + 256) = COERCE_FLOAT(LODWORD(v6) & 0x7FFFFFFF) < 0.001;
  v7 = *(_BYTE *)(a2 + 257);
  if ( v7 )
  {
    v8 = *(float *)(a2 + 20) / dt;
  }
  else
  {
    v9 = v6 - (float)(*(float *)(a2 + 252) * dt);
    v8 = -*(float *)(a2 + 236);
    if ( v8 < v9 )
    {
      if ( *(float *)(a2 + 240) < v9 )
        v8 = *(float *)(a2 + 240);
      else
        v8 = v9;
    }
  }
  *(float *)(a2 + 232) = v8;
  memset(&pos_up_correction, 0, sizeof(pos_up_correction));
  if ( !v7 )
    vostok::physics::bullet_character_controller::step_up(
      (vostok::physics::bullet_character_controller *)a2,
      &pos_up_correction);
  if ( !*(_BYTE *)(a2 + 259) )
  {
    vostok::physics::bullet_character_controller::step_forward_and_strafe(
      (vostok::physics::bullet_character_controller *)(a2 + 16),
      a2,
      (const btVector3 *)(a2 + 16));
    *(_BYTE *)(a2 + 259) = 1;
  }
  if ( !*(_BYTE *)(a2 + 257) )
    vostok::physics::bullet_character_controller::step_down(RecursionCounter, a2, dt, &pos_up_correction, v12);
  v10 = *(_DWORD *)(a2 + 136);
  worldTrans.m_basis.m_el[0].mVec128.m128_u64[0] = *(_QWORD *)(v10 + 16);
  worldTrans.m_basis.m_el[0].mVec128.m128_u64[1] = *(_QWORD *)(v10 + 24);
  worldTrans.m_basis.m_el[1] = *(btVector3 *)(v10 + 32);
  worldTrans.m_basis.m_el[2] = *(btVector3 *)(v10 + 48);
  worldTrans.m_origin = *(btVector3 *)(a2 + 48);
  btCollisionObject::setWorldTransform((btCollisionObject *)v10, &worldTrans);
  if ( CProfileNode::Return(v11) )
    CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
}
