Scaleform::Render::GlyphSlot *__thiscall Scaleform::Render::GlyphQueue::mergeSlotWithNeighbor(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::GlyphSlot *slot)
{
  Scaleform::Render::GlyphSlot *pNextInBand; // edi
  Scaleform::Render::GlyphNode *pRoot; // ebx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::NodeType *v5; // ebp
  int w; // edx
  Scaleform::Render::GlyphQueue *v7; // ecx
  unsigned __int16 v8; // si
  int v9; // eax
  unsigned __int16 TextureId; // ax
  int x; // [esp+8h] [ebp-14h]
  Scaleform::Render::GlyphBand *pBand; // [esp+10h] [ebp-Ch]
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::NodeType *v16; // [esp+14h] [ebp-8h]
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::NodeType *v17; // [esp+18h] [ebp-4h]
  char slota; // [esp+20h] [ebp+4h]

  pNextInBand = slot->pNextInBand;
  pBand = slot->pBand;
  slota = 1;
  if ( pNextInBand == (Scaleform::Render::GlyphSlot *)&pBand->Slots )
  {
    pNextInBand = slot->pPrevInBand;
    slota = 0;
    if ( pNextInBand == (Scaleform::Render::GlyphSlot *)&pBand->Slots )
      return 0;
  }
  if ( pNextInBand->w > slot->w )
    return 0;
  pRoot = pNextInBand->pRoot;
  v5 = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::NodeType *)slot->pRoot;
  Scaleform::Render::GlyphQueue::releaseSlot(this, slot);
  w = slot->w;
  x = slot->x;
  slot->pPrev->pNext = slot->pNext;
  v7 = this;
  slot->pNext->Scaleform::ListNode<Scaleform::Render::GlyphSlot>::$9D459D18FC34DE13F2F77A193E41D32A::pPrev = slot->pPrev;
  --this->SlotQueueSize;
  if ( (slot->TextureId & 0x8000u) == 0 )
  {
    slot->pPrevActive->pNextActive = slot->pNextActive;
    slot->pNextActive->pPrevActive = slot->pPrevActive;
  }
  slot->pPrevInBand->pNextInBand = slot->pNextInBand;
  slot->pNextInBand->pPrevInBand = slot->pPrevInBand;
  slot->pPrev = (Scaleform::Render::GlyphSlot *)this->Slots.FirstEmptySlot;
  this->Slots.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::NodeType *)slot;
  if ( pRoot->Param.pFont || pRoot->pNex2 )
  {
    v8 = x;
  }
  else
  {
    v8 = x;
    if ( pRoot->mRect.h == pBand->h )
    {
      v9 = pRoot->mRect.x;
      if ( slota ? x + w == v9 : v9 + pRoot->mRect.w == x )
      {
        v5->pNext = this->Glyphs.FirstEmptySlot;
        this->Glyphs.FirstEmptySlot = v5;
        if ( slota )
          pRoot->mRect.x = x;
        pRoot->mRect.w += w;
        goto LABEL_18;
      }
    }
  }
  v5[5].pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::NodeType *)pRoot;
  v5[6].pNext = 0;
  v5[4].pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::NodeType *)pNextInBand;
  HIWORD(v16) = pBand->y;
  HIWORD(v17) = pBand->h;
  LOWORD(v16) = v8;
  v5[7].pNext = v16;
  LOWORD(v17) = w;
  v5[8].pNext = v17;
  pNextInBand->pRoot = (Scaleform::Render::GlyphNode *)v5;
LABEL_18:
  if ( slota )
    pNextInBand->x = v8;
  TextureId = pNextInBand->TextureId;
  pNextInBand->w += w;
  if ( (TextureId & 0x8000) != 0 )
  {
    pNextInBand->TextureId = TextureId & 0x7FFF;
    pNextInBand->Failures = 0;
    pNextInBand->pNextActive = v7->ActiveSlots.Root.pNextActive;
    pNextInBand->pPrevActive = &v7->ActiveSlots.Root;
    v7->ActiveSlots.Root.pNextActive->pPrevActive = pNextInBand;
    v7->ActiveSlots.Root.pNextActive = pNextInBand;
  }
  return pNextInBand;
}
