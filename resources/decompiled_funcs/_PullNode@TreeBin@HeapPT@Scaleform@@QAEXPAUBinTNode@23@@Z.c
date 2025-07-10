void __thiscall Scaleform::HeapPT::TreeBin::PullNode(
        Scaleform::HeapPT::TreeBin *this,
        Scaleform::HeapPT::BinTNode *node)
{
  Scaleform::HeapPT::BinTNode *pPrev; // eax
  Scaleform::HeapPT::BinTNode *Parent; // edi
  Scaleform::HeapPT::BinLNode *pNext; // ecx
  Scaleform::HeapPT::BinTNode **v6; // esi
  Scaleform::HeapPT::BinTNode **Child; // ecx
  unsigned int Index; // ecx
  bool v9; // zf
  Scaleform::HeapPT::BinTNode **v10; // ecx
  Scaleform::HeapPT::BinTNode *v11; // ecx
  Scaleform::HeapPT::BinTNode *v12; // edx

  pPrev = (Scaleform::HeapPT::BinTNode *)node->pPrev;
  Parent = node->Parent;
  if ( node->pPrev == node )
  {
    pPrev = node->Child[1];
    v6 = &node->Child[1];
    if ( pPrev || (pPrev = node->Child[0], v6 = node->Child, pPrev) )
    {
      while ( 1 )
      {
        Child = &pPrev->Child[1];
        if ( !pPrev->Child[1] )
        {
          Child = pPrev->Child;
          if ( !pPrev->Child[0] )
            break;
        }
        pPrev = *Child;
        v6 = Child;
      }
      *v6 = 0;
    }
  }
  else
  {
    pNext = node->pNext;
    pNext->pPrev = pPrev;
    pPrev->pNext = pNext;
  }
  if ( Parent )
  {
    Index = node->Index;
    v9 = node == this->Roots[Index];
    v10 = &this->Roots[Index];
    if ( v9 )
    {
      *v10 = pPrev;
      if ( !pPrev )
      {
        this->Mask &= ~(1 << node->Index);
        return;
      }
    }
    else
    {
      Parent->Child[Parent->Child[0] != node] = pPrev;
      if ( !pPrev )
        return;
    }
    pPrev->Parent = Parent;
    v11 = node->Child[0];
    if ( v11 )
    {
      pPrev->Child[0] = v11;
      v11->Parent = pPrev;
    }
    v12 = node->Child[1];
    if ( v12 )
    {
      pPrev->Child[1] = v12;
      v12->Parent = pPrev;
    }
  }
}
