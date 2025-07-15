Scaleform::Render::GlyphNode *__thiscall Scaleform::Render::GlyphQueue::FindGlyph(
        Scaleform::Render::GlyphQueue *this,
        const Scaleform::Render::GlyphParam *gp)
{
  Scaleform::HashLH<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash,79,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> > *p_GlyphHTable; // esi
  signed int v4; // eax
  int v5; // eax
  Scaleform::Render::GlyphNode **v6; // eax
  Scaleform::Render::GlyphNode *result; // eax
  Scaleform::Render::GlyphSlot *pSlot; // ecx

  p_GlyphHTable = &this->GlyphHTable;
  v4 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,79>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>::findIndexAlt<Scaleform::Render::GlyphParamHash>(
         &this->GlyphHTable.mHash,
         (const Scaleform::Render::GlyphParamHash *)&gp);
  if ( v4 < 0 )
    return 0;
  v5 = (int)&p_GlyphHTable->mHash.pTable[2 * v4 + 2];
  if ( !v5 )
    return 0;
  v6 = (Scaleform::Render::GlyphNode **)(v5 + 4);
  if ( !v6 )
    return 0;
  result = *v6;
  pSlot = result->pSlot;
  pSlot->pPrev->pNext = pSlot->pNext;
  pSlot->pNext->Scaleform::ListNode<Scaleform::Render::GlyphSlot>::$5BC0278F55994A57ED32D3AA213E1041::pPrev = pSlot->pPrev;
  pSlot->pPrev = this->SlotQueue.Root.pPrev;
  pSlot->pNext = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
  this->SlotQueue.Root.pPrev->pNext = pSlot;
  this->SlotQueue.Root.pPrev = pSlot;
  return result;
}
