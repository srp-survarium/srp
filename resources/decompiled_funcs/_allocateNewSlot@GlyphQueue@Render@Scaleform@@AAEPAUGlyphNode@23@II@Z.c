Scaleform::Render::GlyphNode *__thiscall Scaleform::Render::GlyphQueue::allocateNewSlot(
        Scaleform::Render::GlyphQueue *this,
        unsigned int w,
        unsigned int h)
{
  unsigned int NumUsedBands; // ecx
  unsigned int NumBandsInTexture; // edi
  int v6; // eax
  int v7; // edx
  Scaleform::Render::GlyphBand *v8; // ecx
  unsigned __int16 v9; // ax
  unsigned int MaxSlotHeight; // eax
  Scaleform::Render::GlyphBand *Data; // edx
  unsigned int v12; // ecx
  unsigned int v13; // eax
  Scaleform::Render::GlyphBand *v14; // edi
  unsigned __int16 v15; // cx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::PageType *inited; // eax
  Scaleform::Render::GlyphSlot *pPrevInBand; // edx
  Scaleform::Render::GlyphSlot *pNextActive; // edx

  NumUsedBands = this->NumUsedBands;
  if ( (!NumUsedBands || this->Bands.Data[NumUsedBands - 1].RightSpace < w) && NumUsedBands < this->Bands.Size )
  {
    NumBandsInTexture = this->NumBandsInTexture;
    v6 = NumUsedBands / NumBandsInTexture;
    v7 = NumUsedBands % NumBandsInTexture;
    v8 = &this->Bands.Data[NumUsedBands];
    v8->TextureId = v6 + LOWORD(this->FirstTexture);
    v9 = v7 * LOWORD(this->MaxSlotHeight);
    v8->y = v9;
    if ( v7 + 1 == this->NumBandsInTexture )
      LOWORD(MaxSlotHeight) = this->TextureHeight - v9;
    else
      MaxSlotHeight = this->MaxSlotHeight;
    v8->h = MaxSlotHeight;
    v8->RightSpace = this->TextureWidth;
    v8->Slots.Root.pPrevInBand = &v8->Slots.Root;
    v8->Slots.Root.pNextInBand = &v8->Slots.Root;
    ++this->NumUsedBands;
  }
  Data = this->Bands.Data;
  v12 = this->NumUsedBands << 6;
  v13 = *(unsigned __int16 *)((char *)Data + v12 - 58);
  v14 = (Scaleform::Render::GlyphBand *)((char *)Data + v12 - 64);
  if ( w > v13 )
    return 0;
  v15 = *(_WORD *)((char *)Data + v12 - 58);
  if ( v13 - w >= w )
    v15 = w;
  inited = Scaleform::Render::GlyphQueue::initNewSlot(this, v14, this->TextureWidth - v13, v15);
  v14->RightSpace -= inited->Data[0].w;
  inited->Data[0].pPrev = this->SlotQueue.Root.pPrev;
  inited->Data[0].pNext = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
  this->SlotQueue.Root.pPrev->pNext = (Scaleform::Render::GlyphSlot *)inited;
  this->SlotQueue.Root.pPrev = (Scaleform::Render::GlyphSlot *)inited;
  ++this->SlotQueueSize;
  pPrevInBand = v14->Slots.Root.pPrevInBand;
  inited->Data[0].pNextInBand = &v14->Slots.Root;
  inited->Data[0].pPrevInBand = pPrevInBand;
  v14->Slots.Root.pPrevInBand->pNextInBand = (Scaleform::Render::GlyphSlot *)inited;
  v14->Slots.Root.pPrevInBand = (Scaleform::Render::GlyphSlot *)inited;
  pNextActive = this->ActiveSlots.Root.pNextActive;
  inited->Data[0].pPrevActive = &this->ActiveSlots.Root;
  inited->Data[0].pNextActive = pNextActive;
  this->ActiveSlots.Root.pNextActive->pPrevActive = (Scaleform::Render::GlyphSlot *)inited;
  this->ActiveSlots.Root.pNextActive = (Scaleform::Render::GlyphSlot *)inited;
  return Scaleform::Render::GlyphQueue::packGlyph(this, w, h, inited->Data);
}
