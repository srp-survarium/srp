Scaleform::HeapPT::BinTNode *__thiscall Scaleform::HeapPT::FreeBin::PullBest(
        Scaleform::HeapPT::FreeBin *this,
        unsigned int blocks)
{
  unsigned int v3; // ecx
  Scaleform::HeapPT::BinTNode *result; // eax
  Scaleform::HeapPT::BinLNode *pNext; // edx
  int v6; // edi
  int v7; // ecx
  unsigned __int8 *v8; // edx
  Scaleform::HeapPT::BinTNode *Best; // eax
  Scaleform::HeapPT::BinTNode *v10; // edi

  if ( blocks > 0x40 )
    goto LABEL_17;
  if ( blocks > 0x20 )
  {
    v6 = blocks - 33;
  }
  else
  {
    if ( this->ListBin1.Mask >> (blocks - 1) )
    {
      v3 = blocks - 1 + (unsigned __int8)Scaleform::Alg::LowerBit(this->ListBin1.Mask >> (blocks - 1));
      result = (Scaleform::HeapPT::BinTNode *)this->ListBin1.Roots[v3];
      pNext = result->pNext;
      if ( result == pNext )
      {
        this->ListBin1.Roots[v3] = 0;
        this->ListBin1.Mask &= ~(1 << v3);
      }
      else
      {
        this->ListBin1.Roots[v3] = pNext;
        result->pPrev->pNext = result->pNext;
        result->pNext->Scaleform::HeapPT::BinLNode::pPrev = result->pPrev;
      }
      if ( result )
      {
        this->FreeBlocks -= result->ShortSize;
        return result;
      }
    }
    v6 = 0;
  }
  if ( this->ListBin2.Mask >> v6
    && ((v7 = v6 + (unsigned __int8)Scaleform::Alg::LowerBit(this->ListBin2.Mask >> v6),
         result = (Scaleform::HeapPT::BinTNode *)this->ListBin2.Roots[v7],
         v8 = (unsigned __int8 *)result->pNext,
         result == (Scaleform::HeapPT::BinTNode *)v8)
      ? (Scaleform::HeapPT::BinLNode *)(this->ListBin2.Roots[v7] = 0, this->ListBin2.Mask &= ~(1 << v7))
      : (this->ListBin2.Roots[v7] = (Scaleform::HeapPT::BinLNode *)v8,
         result->pPrev->pNext = result->pNext,
         result->pNext->Scaleform::HeapPT::BinLNode::pPrev = result->pPrev),
        result) )
  {
    this->FreeBlocks -= result->Size;
  }
  else
  {
LABEL_17:
    Best = Scaleform::HeapPT::TreeBin::FindBest(&this->TreeBin1, blocks);
    v10 = Best;
    if ( Best )
    {
      v10 = (Scaleform::HeapPT::BinTNode *)Best->pNext;
      Scaleform::HeapPT::TreeBin::PullNode(&this->TreeBin1, v10);
      if ( v10 )
        this->FreeBlocks -= v10->Size;
    }
    return v10;
  }
  return result;
}
