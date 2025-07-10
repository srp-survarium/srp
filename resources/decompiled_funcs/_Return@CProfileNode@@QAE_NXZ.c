BOOL __thiscall CProfileNode::Return(CProfileNode *this)
{
  CProfileNode *v1; // esi
  bool v2; // zf

  v1 = CProfileManager::CurrentNode;
  v2 = CProfileManager::CurrentNode->RecursionCounter-- == 1;
  if ( v2 && v1->TotalCalls )
    v1->TotalTime = (double)((unsigned int)btClock::getTimeMicroseconds((btClock *)this) - v1->StartTime) * 0.001
                  + v1->TotalTime;
  return v1->RecursionCounter == 0;
}
