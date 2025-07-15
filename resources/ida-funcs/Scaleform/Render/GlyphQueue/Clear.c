void __thiscall Scaleform::Render::GlyphQueue::Clear(Scaleform::Render::GlyphQueue *this)
{
  Scaleform::Render::GlyphSlot *pNext; // ebx
  Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *i; // ebp
  Scaleform::AmpServer *Instance; // eax
  unsigned int v5; // ecx
  int v6; // edx
  Scaleform::List2<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot_Band> *p_Slots; // eax

  pNext = this->SlotQueue.Root.pNext;
  for ( i = &this->SlotQueue; pNext != (Scaleform::Render::GlyphSlot *)i; pNext = pNext->pNext )
  {
    while ( (Scaleform::List<Scaleform::Render::TextNotifier,Scaleform::Render::TextNotifier> *)pNext->TextFields.Root.pNext != &pNext->TextFields )
    {
      this->pEvictNotifier->Evict(this->pEvictNotifier, pNext->TextFields.Root.pNext->pText);
      Instance = Scaleform::AmpServer::GetInstance();
      Instance->IncrementFontThrashing(Instance);
    }
  }
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::KerningPairType,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeHashF> > *)&this->GlyphHTable);
  i->Root.pPrev = (Scaleform::Render::GlyphSlot *)i;
  i->Root.pNext = (Scaleform::Render::GlyphSlot *)i;
  this->ActiveSlots.Root.pPrevActive = &this->ActiveSlots.Root;
  this->ActiveSlots.Root.pNextActive = &this->ActiveSlots.Root;
  v5 = 0;
  if ( this->NumUsedBands )
  {
    v6 = 0;
    do
    {
      p_Slots = &this->Bands.Data[v6].Slots;
      ++v5;
      p_Slots->Root.pPrevInBand = &p_Slots->Root;
      p_Slots->Root.pNextInBand = &p_Slots->Root;
      ++v6;
    }
    while ( v5 < this->NumUsedBands );
  }
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79>>::ClearAndRelease(&this->Slots);
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79>>::ClearAndRelease(&this->Glyphs);
  this->SlotQueueSize = 0;
  this->NumUsedBands = 0;
}
