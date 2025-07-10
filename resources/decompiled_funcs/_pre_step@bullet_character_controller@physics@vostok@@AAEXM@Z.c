void __usercall vostok::physics::bullet_character_controller::pre_step(
        vostok::physics::bullet_character_controller *this@<ecx>,
        int a2@<esi>,
        double a3@<st0>)
{
  CProfileNode *Sub_Node; // eax
  vostok::physics::bullet_character_controller *RecursionCounter; // ecx
  _QWORD *v5; // eax
  __int64 v6; // xmm0_8
  int v7; // edi
  vostok::physics::bullet_character_controller *v8; // ecx
  double i; // st7
  int v10; // eax

  Sub_Node = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "pre_step" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = (vostok::physics::bullet_character_controller *)Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = (int)&RecursionCounter->__vftable + 1;
  if ( !RecursionCounter )
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
  v5 = (_QWORD *)(*(_DWORD *)(a2 + 136) + 64);
  *(_QWORD *)(a2 + 64) = *v5;
  v6 = v5[1];
  *(_QWORD *)(a2 + 72) = v6;
  v7 = 0;
  for ( i = vostok::physics::bullet_character_controller::recover_from_penetration(RecursionCounter, a2, a3);
        *(float *)&v6 > 0.050000001;
        i = vostok::physics::bullet_character_controller::recover_from_penetration(v8, a2, i) )
  {
    if ( ++v7 > 3 )
      break;
  }
  v10 = *(_DWORD *)(a2 + 136);
  *(_QWORD *)(a2 + 48) = *(_QWORD *)(v10 + 64);
  *(_QWORD *)(a2 + 56) = *(_QWORD *)(v10 + 72);
  if ( CProfileNode::Return((CProfileNode *)(a2 + 48)) )
    CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
}
