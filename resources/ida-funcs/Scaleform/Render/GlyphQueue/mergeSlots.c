void __thiscall Scaleform::Render::GlyphQueue::mergeSlots(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::GlyphSlot *from,
        Scaleform::Render::GlyphSlot *to,
        unsigned __int16 w)
{
  Scaleform::Render::GlyphSlot *i; // esi
  Scaleform::Render::GlyphSlot *pNextInBand; // ebp
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::NodeType *pRoot; // eax
  Scaleform::Render::GlyphNode *v8; // ecx

  for ( i = from; ; i = pNextInBand )
  {
    pNextInBand = i->pNextInBand;
    Scaleform::Render::GlyphQueue::releaseSlot(this, i);
    if ( i != from )
    {
      pRoot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::NodeType *)i->pRoot;
      pRoot->pNext = this->Glyphs.FirstEmptySlot;
      this->Glyphs.FirstEmptySlot = pRoot;
      i->pPrev->pNext = i->pNext;
      i->pNext->Scaleform::ListNode<Scaleform::Render::GlyphSlot>::$9D459D18FC34DE13F2F77A193E41D32A::pPrev = i->pPrev;
      --this->SlotQueueSize;
      if ( (i->TextureId & 0x8000u) == 0 )
      {
        i->pPrevActive->pNextActive = i->pNextActive;
        i->pNextActive->pPrevActive = i->pPrevActive;
      }
      i->pPrevInBand->pNextInBand = i->pNextInBand;
      i->pNextInBand->pPrevInBand = i->pPrevInBand;
      i->pPrev = (Scaleform::Render::GlyphSlot *)this->Slots.FirstEmptySlot;
      this->Slots.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::NodeType *)i;
    }
    if ( i == to )
      break;
  }
  v8 = from->pRoot;
  from->w = w;
  v8->mRect.w = w;
  from->pPrev->pNext = from->pNext;
  from->pNext->Scaleform::ListNode<Scaleform::Render::GlyphSlot>::$9D459D18FC34DE13F2F77A193E41D32A::pPrev = from->pPrev;
  from->pNext = this->SlotQueue.Root.pNext;
  from->pPrev = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
  this->SlotQueue.Root.pNext->pPrev = from;
  this->SlotQueue.Root.pNext = from;
}
