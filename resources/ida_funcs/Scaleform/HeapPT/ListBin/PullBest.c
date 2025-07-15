Scaleform::HeapPT::BinLNode *__thiscall Scaleform::HeapPT::ListBin::PullBest(
        Scaleform::HeapPT::ListBin *this,
        unsigned int idx,
        unsigned int blocks,
        char shift,
        unsigned int alignMask)
{
  unsigned int v6; // edx
  Scaleform::HeapPT::BinLNode *result; // eax
  int v8; // esi
  Scaleform::HeapPT::BinLNode **i; // ebx
  Scaleform::HeapPT::BinLNode *v10; // ecx
  Scaleform::HeapPT::BinLNode *pNext; // edx

  v6 = this->Mask >> idx;
  result = 0;
  if ( v6 )
  {
    v8 = idx + (unsigned __int8)Scaleform::Alg::LowerBit(v6);
    for ( i = &this->Roots[v8]; ; ++i )
    {
      result = Scaleform::HeapPT::ListBin::FindAligned(this, *i, blocks, shift, alignMask);
      if ( result )
        break;
      if ( (unsigned int)++v8 >= 0x20 )
        return result;
    }
    v10 = this->Roots[v8];
    if ( result != v10 )
      goto LABEL_9;
    pNext = v10->pNext;
    if ( v10 != pNext )
    {
      this->Roots[v8] = pNext;
LABEL_9:
      result->pPrev->pNext = result->pNext;
      result->pNext->pPrev = result->pPrev;
      return result;
    }
    this->Roots[v8] = 0;
    this->Mask &= ~(1 << v8);
  }
  return result;
}
