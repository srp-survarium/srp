void __thiscall Scaleform::Render::GlyphQueue::MergeEmptySlots(Scaleform::Render::GlyphQueue *this)
{
  Scaleform::Render::GlyphBand *v2; // eax
  Scaleform::Render::GlyphSlot *pNextInBand; // esi
  Scaleform::List2<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot_Band> *p_Slots; // ebp
  Scaleform::Render::GlyphSlot *v5; // edi
  unsigned __int16 v6; // ax
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::NodeType *pRoot; // ecx
  unsigned __int16 x; // dx
  Scaleform::Render::GlyphNode *v9; // ecx
  int v10; // [esp+4h] [ebp-8h]
  unsigned int i; // [esp+8h] [ebp-4h]

  i = 0;
  if ( this->NumUsedBands )
  {
    v10 = 0;
    do
    {
      v2 = &this->Bands.Data[v10];
      pNextInBand = v2->Slots.Root.pNextInBand;
      p_Slots = &v2->Slots;
      while ( pNextInBand != (Scaleform::Render::GlyphSlot *)p_Slots )
      {
        v5 = pNextInBand->pNextInBand;
        if ( v5 == (Scaleform::Render::GlyphSlot *)p_Slots )
          break;
        if ( (int)v5->pRoot->pNext
           | (int)v5->pRoot->pNex2
           | (int)pNextInBand->pRoot->pNext
           | (int)pNextInBand->pRoot->pNex2 )
        {
          pNextInBand = pNextInBand->pNextInBand;
        }
        else
        {
          Scaleform::Render::GlyphQueue::releaseSlot(this, pNextInBand);
          Scaleform::Render::GlyphQueue::releaseSlot(this, v5);
          v6 = pNextInBand->w + v5->w;
          pRoot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::NodeType *)v5->pRoot;
          pRoot->pNext = this->Glyphs.FirstEmptySlot;
          this->Glyphs.FirstEmptySlot = pRoot;
          v5->pPrev->pNext = v5->pNext;
          v5->pNext->Scaleform::ListNode<Scaleform::Render::GlyphSlot>::$5BC0278F55994A57ED32D3AA213E1041::pPrev = v5->pPrev;
          --this->SlotQueueSize;
          if ( (v5->TextureId & 0x8000u) == 0 )
          {
            v5->pPrevActive->pNextActive = v5->pNextActive;
            v5->pNextActive->pPrevActive = v5->pPrevActive;
          }
          v5->pPrevInBand->pNextInBand = v5->pNextInBand;
          v5->pNextInBand->pPrevInBand = v5->pPrevInBand;
          v5->pPrev = (Scaleform::Render::GlyphSlot *)this->Slots.FirstEmptySlot;
          this->Slots.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::NodeType *)v5;
          x = pNextInBand->x;
          v9 = pNextInBand->pRoot;
          pNextInBand->w = v6;
          v9->mRect.x = x;
          pNextInBand->pRoot->mRect.y = pNextInBand->pBand->y;
          pNextInBand->pRoot->mRect.w = v6;
          pNextInBand->pRoot->mRect.h = pNextInBand->pBand->h;
          pNextInBand->pPrev->pNext = pNextInBand->pNext;
          pNextInBand->pNext->Scaleform::ListNode<Scaleform::Render::GlyphSlot>::$5BC0278F55994A57ED32D3AA213E1041::pPrev = pNextInBand->pPrev;
          pNextInBand->pNext = this->SlotQueue.Root.pNext;
          pNextInBand->pPrev = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
          this->SlotQueue.Root.pNext->pPrev = pNextInBand;
          this->SlotQueue.Root.pNext = pNextInBand;
        }
      }
      ++v10;
      ++i;
    }
    while ( i < this->NumUsedBands );
  }
}
