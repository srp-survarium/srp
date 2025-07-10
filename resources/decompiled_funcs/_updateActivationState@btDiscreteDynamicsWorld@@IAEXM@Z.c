void __thiscall btDiscreteDynamicsWorld::updateActivationState(
        btDiscreteDynamicsWorld *this,
        float timeStep,
        float timeStepa)
{
  CProfileNode *Sub_Node; // esi
  int RecursionCounter; // ecx
  int v5; // edi
  bool v6; // al
  int v7; // edx
  int v8; // edx
  bool v9; // zf
  int *p_RecursionCounter; // edi

  Sub_Node = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "updateActivationState" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
  {
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
    Sub_Node = CProfileManager::CurrentNode;
  }
  v5 = 0;
  if ( *(int *)(LODWORD(timeStep) + 204) > 0 )
  {
    v6 = gDisableDeactivation;
    do
    {
      RecursionCounter = *(_DWORD *)(*(_DWORD *)(LODWORD(timeStep) + 212) + 4 * v5);
      if ( RecursionCounter )
      {
        v7 = *(_DWORD *)(RecursionCounter + 228);
        if ( v7 != 2 && v7 != 4 )
        {
          if ( (float)(*(float *)(RecursionCounter + 492) * *(float *)(RecursionCounter + 492)) <= (float)((float)((float)(*(float *)(RecursionCounter + 320) * *(float *)(RecursionCounter + 320)) + (float)(*(float *)(RecursionCounter + 324) * *(float *)(RecursionCounter + 324))) + (float)(*(float *)(RecursionCounter + 328) * *(float *)(RecursionCounter + 328)))
            || (float)(*(float *)(RecursionCounter + 496) * *(float *)(RecursionCounter + 496)) <= (float)((float)((float)(*(float *)(RecursionCounter + 336) * *(float *)(RecursionCounter + 336)) + (float)(*(float *)(RecursionCounter + 340) * *(float *)(RecursionCounter + 340))) + (float)(*(float *)(RecursionCounter + 344) * *(float *)(RecursionCounter + 344))) )
          {
            *(_DWORD *)(RecursionCounter + 232) = 0;
            if ( v7 != 5 )
              *(_DWORD *)(RecursionCounter + 228) = 0;
          }
          else
          {
            *(float *)(RecursionCounter + 232) = *(float *)(RecursionCounter + 232) + timeStepa;
          }
        }
        v8 = *(_DWORD *)(RecursionCounter + 228);
        if ( v8 != 4 )
        {
          if ( !v6 && (v8 == 2 || v8 == 3 || *(float *)(RecursionCounter + 232) > 2.0) )
          {
            if ( (*(_BYTE *)(RecursionCounter + 216) & 3) != 0 )
            {
              if ( v8 != 5 )
                *(_DWORD *)(RecursionCounter + 228) = 2;
            }
            else
            {
              if ( v8 == 1 )
                *(_DWORD *)(RecursionCounter + 228) = 3;
              if ( *(_DWORD *)(RecursionCounter + 228) == 2 )
              {
                *(_QWORD *)(RecursionCounter + 336) = 0;
                *(_QWORD *)(RecursionCounter + 344) = 0;
                *(_QWORD *)(RecursionCounter + 320) = 0;
                *(_QWORD *)(RecursionCounter + 328) = 0;
              }
            }
          }
          else if ( v8 != 5 )
          {
            *(_DWORD *)(RecursionCounter + 228) = 1;
          }
        }
      }
      ++v5;
    }
    while ( v5 < *(_DWORD *)(LODWORD(timeStep) + 204) );
  }
  v9 = Sub_Node->RecursionCounter-- == 1;
  p_RecursionCounter = &Sub_Node->RecursionCounter;
  if ( v9 && Sub_Node->TotalCalls )
  {
    Sub_Node->TotalTime = (double)(btClock::getTimeMicroseconds((btClock *)RecursionCounter) - Sub_Node->StartTime)
                        * 0.001
                        + Sub_Node->TotalTime;
    Sub_Node = CProfileManager::CurrentNode;
  }
  if ( !*p_RecursionCounter )
    CProfileManager::CurrentNode = Sub_Node->Parent;
}
