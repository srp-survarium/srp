void __thiscall CProfileNode::Get_Sub_Node(const char *name, const char *namea)
{
  CProfileNode *v2; // edi
  CProfileNode *Child; // eax
  CProfileNode *v4; // eax
  CProfileNode *v5; // eax

  v2 = CProfileManager::CurrentNode;
  Child = CProfileManager::CurrentNode->Child;
  if ( Child )
  {
    while ( Child->Name != namea )
    {
      Child = Child->Sibling;
      if ( !Child )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v4 = (CProfileNode *)operator new(0x24u);
    if ( v4 )
    {
      v4->Name = namea;
      v4->TotalCalls = 0;
      v4->TotalTime = 0.0;
      v4->StartTime = 0;
      v4->RecursionCounter = 0;
      v4->Parent = v2;
      v4->Child = 0;
      v4->Sibling = 0;
      v4->m_userPtr = 0;
      CProfileNode::Reset(v4);
      v5->Sibling = v2->Child;
      v2->Child = v5;
    }
    else
    {
      MEMORY[0x1C] = v2->Child;
      v2->Child = 0;
    }
  }
}
