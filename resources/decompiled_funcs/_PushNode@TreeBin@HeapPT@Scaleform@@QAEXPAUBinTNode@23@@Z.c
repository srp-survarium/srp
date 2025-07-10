void __thiscall Scaleform::HeapPT::TreeBin::PushNode(
        Scaleform::HeapPT::TreeBin *this,
        Scaleform::HeapPT::BinTNode *node)
{
  unsigned int Size; // ebp
  unsigned int v4; // ecx
  unsigned __int8 v5; // al
  Scaleform::HeapPT::BinTNode *v6; // ebx
  Scaleform::HeapPT::BinTNode *pPrev; // eax
  int v8; // edi
  unsigned int v9; // edx
  int v10; // edi
  Scaleform::HeapPT::BinLNode *pNext; // ecx

  Size = node->Size;
  if ( Size >> 5 )
  {
    if ( Size >> 5 <= 0xFFFF )
    {
      v5 = Scaleform::Alg::UpperBit(node->Size >> 5);
      v4 = ((Size >> (v5 + 4)) & 1) + 2 * v5;
    }
    else
    {
      v4 = 31;
    }
  }
  else
  {
    v4 = 0;
  }
  node->Child[1] = 0;
  node->Child[0] = 0;
  node->Index = v4;
  v6 = (Scaleform::HeapPT::BinTNode *)&this->Roots[v4];
  if ( (this->Mask & (1 << v4)) != 0 )
  {
    pPrev = (Scaleform::HeapPT::BinTNode *)v6->pPrev;
    if ( v4 < 0x1F )
      v8 = 28 - (v4 >> 1);
    else
      LOBYTE(v8) = 0;
    v9 = Size << v8;
    if ( pPrev->Size == Size )
    {
LABEL_14:
      pNext = pPrev->pNext;
      pNext->pPrev = node;
      pPrev->pNext = node;
      node->pNext = pNext;
      node->pPrev = pPrev;
      node->Parent = 0;
    }
    else
    {
      while ( 1 )
      {
        v10 = (int)&pPrev->Child[v9 >> 31];
        v9 *= 2;
        if ( !*(_DWORD *)v10 )
          break;
        pPrev = *(Scaleform::HeapPT::BinTNode **)v10;
        if ( *(_DWORD *)(*(_DWORD *)v10 + 16) == Size )
          goto LABEL_14;
      }
      *(_DWORD *)v10 = node;
      node->Parent = pPrev;
      node->pPrev = node;
      node->pNext = node;
    }
  }
  else
  {
    this->Mask |= 1 << v4;
    v6->pPrev = node;
    node->Parent = v6;
    node->pPrev = node;
    node->pNext = node;
  }
}
