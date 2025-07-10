void __thiscall Scaleform::HeapPT::FreeBin::Push(Scaleform::HeapPT::FreeBin *this, Scaleform::HeapPT::BinTNode *node)
{
  unsigned int ShortSize; // ecx
  Scaleform::HeapPT::BinLNode *v4; // esi
  unsigned int v5; // ecx
  Scaleform::HeapPT::BinLNode *v6; // esi
  unsigned int v7; // ecx

  ShortSize = node->ShortSize;
  if ( ShortSize >= 0x21 )
    ShortSize = node->Size;
  this->FreeBlocks += ShortSize;
  if ( ShortSize > 0x20 )
  {
    if ( ShortSize > 0x40 )
    {
      Scaleform::HeapPT::TreeBin::PushNode(&this->TreeBin1, node);
    }
    else
    {
      v6 = this->ListBin1.Roots[ShortSize];
      v7 = ShortSize - 33;
      if ( v6 )
      {
        node->pPrev = v6;
        node->pNext = v6->pNext;
        v6->pNext->pPrev = node;
        v6->pNext = node;
      }
      else
      {
        node->pNext = node;
        node->pPrev = node;
      }
      this->ListBin2.Roots[v7] = node;
      this->ListBin2.Mask |= 1 << v7;
    }
  }
  else
  {
    v4 = (Scaleform::HeapPT::BinLNode *)*(&this->ListBin1.Mask + ShortSize);
    v5 = ShortSize - 1;
    if ( v4 )
    {
      node->pPrev = v4;
      node->pNext = v4->pNext;
      v4->pNext->pPrev = node;
      v4->pNext = node;
    }
    else
    {
      node->pNext = node;
      node->pPrev = node;
    }
    this->ListBin1.Roots[v5] = node;
    this->ListBin1.Mask |= 1 << v5;
  }
}
