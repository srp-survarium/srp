void __thiscall CProfileManager::Start_Profile(const char *name)
{
  CProfileNode *v1; // eax
  int RecursionCounter; // ecx

  v1 = CProfileManager::CurrentNode;
  if ( name != CProfileManager::CurrentNode->Name )
  {
    CProfileNode::Get_Sub_Node(name, name);
    CProfileManager::CurrentNode = v1;
  }
  RecursionCounter = v1->RecursionCounter;
  ++v1->TotalCalls;
  v1->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
    v1->StartTime = btClock::getTimeMicroseconds(0);
}
