void __thiscall Scaleform::HeapPT::FreeBin::Pull(Scaleform::HeapPT::FreeBin *this, Scaleform::HeapPT::BinTNode *node)
{
  unsigned int ShortSize; // ecx
  Scaleform::HeapPT::BinTNode *v4; // esi
  unsigned int v5; // ecx
  Scaleform::HeapPT::BinLNode *v6; // edi
  Scaleform::HeapPT::BinLNode *v7; // esi
  unsigned int v8; // ecx
  Scaleform::HeapPT::BinLNode *pNext; // edi

  ShortSize = node->ShortSize;
  if ( ShortSize >= 0x21 )
    ShortSize = node->Size;
  this->FreeBlocks -= ShortSize;
  if ( ShortSize > 0x20 )
  {
    if ( ShortSize > 0x40 )
    {
      Scaleform::HeapPT::TreeBin::PullNode(&this->TreeBin1, node);
    }
    else
    {
      v7 = this->ListBin1.Roots[ShortSize];
      v8 = ShortSize - 33;
      if ( node != v7 )
        goto LABEL_7;
      pNext = v7->pNext;
      if ( v7 == pNext )
      {
        this->ListBin2.Roots[v8] = 0;
        this->ListBin2.Mask &= ~(1 << v8);
      }
      else
      {
        this->ListBin2.Roots[v8] = pNext;
        node->pPrev->pNext = node->pNext;
        node->pNext->Scaleform::HeapPT::BinLNode::pPrev = node->pPrev;
      }
    }
  }
  else
  {
    v4 = (Scaleform::HeapPT::BinTNode *)*(&this->ListBin1.Mask + ShortSize);
    v5 = ShortSize - 1;
    if ( node != v4 )
    {
LABEL_7:
      node->pPrev->pNext = node->pNext;
      node->pNext->Scaleform::HeapPT::BinLNode::pPrev = node->pPrev;
      return;
    }
    v6 = v4->pNext;
    if ( v4 != v6 )
    {
      this->ListBin1.Roots[v5] = v6;
      goto LABEL_7;
    }
    this->ListBin1.Roots[v5] = 0;
    this->ListBin1.Mask &= ~(1 << v5);
  }
}
