void __thiscall Scaleform::Render::GlyphQueue::splitGlyph(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::GlyphSlot *slot,
        bool left,
        __int16 w)
{
  Scaleform::Render::GlyphNode *pRoot; // ebp
  unsigned __int16 v5; // bx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::PageType *inited; // eax
  Scaleform::Render::GlyphSlot *pPrevInBand; // ecx
  Scaleform::Render::GlyphSlot *pNextInBand; // ecx
  Scaleform::Render::GlyphSlot *pNext; // edx

  pRoot = slot->pRoot;
  v5 = pRoot->mRect.w - w;
  if ( left )
  {
    inited = Scaleform::Render::GlyphQueue::initNewSlot(this, slot->pBand, pRoot->mRect.x, v5);
    pPrevInBand = slot->pPrevInBand;
    inited->Data[0].pNextInBand = slot;
    inited->Data[0].pPrevInBand = pPrevInBand;
    pPrevInBand->pNextInBand = (Scaleform::Render::GlyphSlot *)inited;
    slot->x += v5;
    LOWORD(pPrevInBand) = slot->x;
    slot->pPrevInBand = (Scaleform::Render::GlyphSlot *)inited;
    pRoot->mRect.x = (unsigned __int16)pPrevInBand;
  }
  else
  {
    inited = Scaleform::Render::GlyphQueue::initNewSlot(this, slot->pBand, w + pRoot->mRect.x, v5);
    pNextInBand = slot->pNextInBand;
    inited->Data[0].pPrevInBand = slot;
    inited->Data[0].pNextInBand = pNextInBand;
    pNextInBand->pPrevInBand = (Scaleform::Render::GlyphSlot *)inited;
    slot->pNextInBand = (Scaleform::Render::GlyphSlot *)inited;
  }
  pRoot->mRect.w = w;
  slot->w -= v5;
  pNext = this->SlotQueue.Root.pNext;
  inited->Data[0].pPrev = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
  inited->Data[0].pNext = pNext;
  this->SlotQueue.Root.pNext->pPrev = (Scaleform::Render::GlyphSlot *)inited;
  this->SlotQueue.Root.pNext = (Scaleform::Render::GlyphSlot *)inited;
  ++this->SlotQueueSize;
  inited->Data[0].pNextActive = this->ActiveSlots.Root.pNextActive;
  inited->Data[0].pPrevActive = &this->ActiveSlots.Root;
  this->ActiveSlots.Root.pNextActive->pPrevActive = (Scaleform::Render::GlyphSlot *)inited;
  this->ActiveSlots.Root.pNextActive = (Scaleform::Render::GlyphSlot *)inited;
}
