Scaleform::Render::GlyphNode *__thiscall Scaleform::Render::GlyphQueue::AllocateGlyph(
        Scaleform::Render::GlyphQueue *this,
        const Scaleform::Render::GlyphParam *gp,
        Scaleform::Render::GlyphNode *w,
        Scaleform::Render::GlyphNode *h)
{
  Scaleform::Render::GlyphNode *v4; // ebx
  Scaleform::Render::GlyphNode *v6; // edi
  Scaleform::Render::GlyphNode *SpaceInSlots; // eax
  Scaleform::Render::GlyphSlot *pSlot; // eax
  Scaleform::Render::GlyphSlot *pPrev; // edx
  Scaleform::HashLH<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash,79,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> > *p_GlyphHTable; // esi
  signed int v11; // eax
  int v12; // eax

  v4 = h;
  if ( (unsigned int)h < this->MinSlotSpace )
    this->MinSlotSpace = (unsigned int)h;
  v6 = w;
  if ( (unsigned int)w < this->MinSlotSpace )
    this->MinSlotSpace = (unsigned int)w;
  SpaceInSlots = Scaleform::Render::GlyphQueue::findSpaceInSlots(this, (unsigned int)v6, (unsigned int)v4);
  h = SpaceInSlots;
  if ( !SpaceInSlots )
  {
    SpaceInSlots = Scaleform::Render::GlyphQueue::allocateNewSlot(this, (unsigned int)v6, (unsigned int)v4);
    h = SpaceInSlots;
    if ( !SpaceInSlots )
    {
      SpaceInSlots = Scaleform::Render::GlyphQueue::evictOldSlot(this, (unsigned int)v6, (unsigned int)v4);
      h = SpaceInSlots;
      if ( !SpaceInSlots )
        return 0;
    }
  }
  SpaceInSlots->Param.pFont = gp->pFont;
  *(_DWORD *)&h->Param.GlyphIndex = *(_DWORD *)&gp->GlyphIndex;
  *(_DWORD *)&h->Param.Flags = *(_DWORD *)&gp->Flags;
  *(_DWORD *)&h->Param.BlurY = *(_DWORD *)&gp->BlurY;
  h->Origin.x = 0;
  h->Origin.y = 0;
  pSlot = h->pSlot;
  pSlot->pPrev->pNext = pSlot->pNext;
  pSlot->pNext->Scaleform::ListNode<Scaleform::Render::GlyphSlot>::$9D459D18FC34DE13F2F77A193E41D32A::pPrev = pSlot->pPrev;
  pPrev = this->SlotQueue.Root.pPrev;
  pSlot->pNext = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
  pSlot->pPrev = pPrev;
  this->SlotQueue.Root.pPrev->pNext = pSlot;
  this->SlotQueue.Root.pPrev = pSlot;
  p_GlyphHTable = &this->GlyphHTable;
  w = h;
  v11 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,79>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>::findIndexAlt<Scaleform::Render::GlyphParamHash>(
          &p_GlyphHTable->mHash,
          (const Scaleform::Render::GlyphParamHash *)&w);
  if ( v11 < 0 || (v12 = (int)&p_GlyphHTable->mHash.pTable[2 * v11 + 2]) == 0 || v12 == -4 )
    Scaleform::Hash<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,79>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,79>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>>::Add(
      p_GlyphHTable,
      (const Scaleform::Render::GlyphParamHash *)&w,
      &h);
  return h;
}
