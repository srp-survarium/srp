void __thiscall Scaleform::Render::GlyphQueue::releaseSlot(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::GlyphSlot *slot)
{
  Scaleform::Render::GlyphSlot *v2; // esi
  Scaleform::Render::Fence *pObject; // eax
  Scaleform::Render::FenceImpl *Data; // eax
  Scaleform::Render::Fence *v6; // ecx
  Scaleform::Render::GlyphBand *pBand; // eax
  unsigned __int16 RightSpace; // cx
  unsigned __int16 w; // dx
  Scaleform::Render::GlyphBand *v10; // eax
  Scaleform::Render::GlyphNode *pRoot; // eax
  Scaleform::Render::Fence *v12; // ecx
  int v13; // [esp+Ch] [ebp-8h]
  int v14; // [esp+10h] [ebp-4h]

  v2 = slot;
  if ( !slot->PinCount )
  {
    pObject = slot->SlotFence.pObject;
    if ( pObject )
    {
      if ( pObject->HasData )
      {
        Data = pObject->Data;
        if ( Data )
          Scaleform::Render::FenceImpl::WaitFence(Data, FenceType_Fragment);
      }
    }
    v6 = v2->SlotFence.pObject;
    if ( v6 )
      Scaleform::Render::Fence::Release(v6);
    v2->SlotFence.pObject = 0;
  }
  Scaleform::Render::GlyphQueue::releaseGlyphTree(this, v2->pRoot->pNext);
  Scaleform::Render::GlyphQueue::releaseGlyphTree(this, v2->pRoot->pNex2);
  while ( (Scaleform::List<Scaleform::Render::TextNotifier,Scaleform::Render::TextNotifier> *)v2->TextFields.Root.pNext != &v2->TextFields )
    this->pEvictNotifier->Evict(this->pEvictNotifier, v2->TextFields.Root.pNext->pText);
  if ( v2->pRoot->Param.pFont )
  {
    slot = (Scaleform::Render::GlyphSlot *)v2->pRoot;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,79>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>::RemoveAlt<Scaleform::Render::GlyphParamHash>(
      &this->GlyphHTable.mHash,
      (const Scaleform::Render::GlyphParamHash *)&slot);
  }
  pBand = v2->pBand;
  RightSpace = pBand->RightSpace;
  if ( RightSpace && v2 == pBand->Slots.Root.pPrevInBand )
  {
    v2->w += RightSpace;
    pBand->RightSpace = 0;
  }
  v2->pRoot->Param.pFont = 0;
  w = v2->w;
  LOWORD(v13) = v2->x;
  v10 = v2->pBand;
  HIWORD(v13) = v10->y;
  HIWORD(v14) = v10->h;
  pRoot = v2->pRoot;
  *(_DWORD *)&pRoot->mRect.x = v13;
  LOWORD(v14) = w;
  *(_DWORD *)&pRoot->mRect.w = v14;
  v2->pRoot->pNext = 0;
  v2->pRoot->pNex2 = 0;
  v2->Failures = 0;
  v12 = v2->SlotFence.pObject;
  if ( v12 )
    Scaleform::Render::Fence::Release(v12);
  v2->SlotFence.pObject = 0;
  if ( (v2->TextureId & 0x8000) != 0 )
  {
    v2->TextureId &= ~0x8000u;
    v2->pNextActive = this->ActiveSlots.Root.pNextActive;
    v2->pPrevActive = &this->ActiveSlots.Root;
    this->ActiveSlots.Root.pNextActive->pPrevActive = v2;
    this->ActiveSlots.Root.pNextActive = v2;
  }
}
