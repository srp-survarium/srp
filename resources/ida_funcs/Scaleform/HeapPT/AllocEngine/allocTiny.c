Scaleform::List<Scaleform::HeapPT::AllocEngine::TinyBlock,Scaleform::HeapPT::AllocEngine::TinyBlock> *__thiscall Scaleform::HeapPT::AllocEngine::allocTiny(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned int sizeIdx)
{
  Scaleform::List<Scaleform::HeapPT::AllocEngine::TinyBlock,Scaleform::HeapPT::AllocEngine::TinyBlock> *result; // eax

  result = (Scaleform::List<Scaleform::HeapPT::AllocEngine::TinyBlock,Scaleform::HeapPT::AllocEngine::TinyBlock> *)this->TinyBlocks[sizeIdx].Root.pNext;
  if ( result != &this->TinyBlocks[sizeIdx]
    || (result = (Scaleform::List<Scaleform::HeapPT::AllocEngine::TinyBlock,Scaleform::HeapPT::AllocEngine::TinyBlock> *)Scaleform::HeapPT::AllocEngine::allocSegmentTiny(this, sizeIdx)) != 0 )
  {
    result->Root.pPrev->pNext = result->Root.pNext;
    result->Root.pNext->pPrev = result->Root.pPrev;
    ++result[1].Root.pPrev[1].pNext;
    this->TinyFreeSpace -= (sizeIdx + 1) << this->MinAlignShift;
  }
  return result;
}
