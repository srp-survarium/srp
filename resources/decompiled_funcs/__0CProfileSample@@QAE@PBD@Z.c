CProfileSample *__usercall CProfileSample::CProfileSample@<eax>(CProfileSample *this@<ecx>, CProfileSample *a2@<edi>)
{
  CProfileNode *Sub_Node; // eax
  int RecursionCounter; // ecx

  Sub_Node = CProfileManager::CurrentNode;
  if ( this != (CProfileSample *)CProfileManager::CurrentNode->Name )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
  return a2;
}
