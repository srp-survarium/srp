void __thiscall Scaleform::Render::GlyphQueue::splitSlot(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::GlyphSlot *slot,
        __int16 w)
{
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::PageType *inited; // eax
  Scaleform::Render::GlyphNode *pRoot; // ecx
  Scaleform::Render::GlyphSlot *pNextInBand; // ecx

  inited = Scaleform::Render::GlyphQueue::initNewSlot(this, slot->pBand, w + slot->x, slot->w - w);
  pRoot = slot->pRoot;
  slot->w = w;
  pRoot->mRect.w = w;
  inited->Data[0].pNext = this->SlotQueue.Root.pNext;
  inited->Data[0].pPrev = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
  this->SlotQueue.Root.pNext->pPrev = (Scaleform::Render::GlyphSlot *)inited;
  this->SlotQueue.Root.pNext = (Scaleform::Render::GlyphSlot *)inited;
  ++this->SlotQueueSize;
  pNextInBand = slot->pNextInBand;
  inited->Data[0].pPrevInBand = slot;
  inited->Data[0].pNextInBand = pNextInBand;
  pNextInBand->pPrevInBand = (Scaleform::Render::GlyphSlot *)inited;
  slot->pNextInBand = (Scaleform::Render::GlyphSlot *)inited;
  inited->Data[0].pNextActive = this->ActiveSlots.Root.pNextActive;
  inited->Data[0].pPrevActive = &this->ActiveSlots.Root;
  this->ActiveSlots.Root.pNextActive->pPrevActive = (Scaleform::Render::GlyphSlot *)inited;
  this->ActiveSlots.Root.pNextActive = (Scaleform::Render::GlyphSlot *)inited;
}
