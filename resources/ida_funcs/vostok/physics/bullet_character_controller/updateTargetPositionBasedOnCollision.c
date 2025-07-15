btVector3 *__userpurge vostok::physics::bullet_character_controller::updateTargetPositionBasedOnCollision@<eax>(
        vostok::physics::bullet_character_controller *this@<ecx>,
        int a2@<eax>,
        int a3@<esi>,
        btVector3 *result,
        const btVector3 *hitNormal,
        const btVector3 *target_pos,
        float __formal,
        float normalMag)
{
  CProfileNode *Sub_Node; // eax
  int RecursionCounter; // ecx
  float v11; // xmm1_4
  float v12; // xmm2_4
  CProfileNode *v13; // ecx
  float v14; // xmm0_4
  long double v15; // st7
  float v16; // xmm4_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v20; // [esp+48h] [ebp-1Ch]
  float v21; // [esp+48h] [ebp-1Ch]
  float v22; // [esp+4Ch] [ebp-18h]
  float v23; // [esp+50h] [ebp-14h]
  float v24; // [esp+54h] [ebp-10h]
  float v25; // [esp+54h] [ebp-10h]
  float v26; // [esp+58h] [ebp-Ch]
  float v27; // [esp+5Ch] [ebp-8h]

  Sub_Node = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "updateTargetPositionBasedOnCollision" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
  v11 = hitNormal->mVec128.m128_f32[1] - *(float *)(a2 + 52);
  v12 = hitNormal->mVec128.m128_f32[2] - *(float *)(a2 + 56);
  *(_QWORD *)a3 = *(_QWORD *)(a2 + 48);
  *(_QWORD *)(a3 + 8) = *(_QWORD *)(a2 + 56);
  v24 = hitNormal->mVec128.m128_f32[0] - *(float *)(a2 + 48);
  v20 = sqrtf((float)((float)(v11 * v11) + (float)(v24 * v24)) + (float)(v12 * v12));
  v23 = v20;
  if ( v20 > 0.00000011920929 )
  {
    v14 = (float)((float)((float)(result->mVec128.m128_f32[0] * (float)(v24 * (float)(*(float *)&clear_value / v20)))
                        + (float)(result->mVec128.m128_f32[2] * (float)(v12 * (float)(*(float *)&clear_value / v20))))
                + (float)(result->mVec128.m128_f32[1] * (float)(v11 * (float)(*(float *)&clear_value / v20))))
        * 2.0;
    v22 = result->mVec128.m128_f32[0];
    v27 = (float)(v12 * (float)(*(float *)&clear_value / v20)) - (float)(result->mVec128.m128_f32[2] * v14);
    v26 = (float)(v11 * (float)(*(float *)&clear_value / v20)) - (float)(result->mVec128.m128_f32[1] * v14);
    v25 = (float)(v24 * (float)(*(float *)&clear_value / v20)) - (float)(result->mVec128.m128_f32[0] * v14);
    v15 = sqrtf((float)((float)(v27 * v27) + (float)(v26 * v26)) + (float)(v25 * v25));
    v16 = result->mVec128.m128_f32[2];
    v21 = 1.0 / v15;
    v17 = (float)((float)(v16 * (float)(v27 * v21)) + (float)(result->mVec128.m128_f32[1] * (float)(v26 * v21)))
        + (float)(v22 * (float)(v25 * v21));
    v18 = (float)((float)(v26 * v21) - (float)(result->mVec128.m128_f32[1] * v17)) * v23;
    *(float *)a3 = *(float *)a3 + (float)((float)((float)(v25 * v21) - (float)(v22 * v17)) * v23);
    *(float *)(a3 + 4) = *(float *)(a3 + 4) + v18;
    *(float *)(a3 + 8) = *(float *)(a3 + 8) + (float)((float)((float)(v27 * v21) - (float)(v16 * v17)) * v23);
  }
  if ( CProfileNode::Return(v13) )
    CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
  return (btVector3 *)a3;
}
