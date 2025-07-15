void __thiscall Scaleform::Render::GlyphQueue::~GlyphQueue(Scaleform::Render::GlyphQueue *this)
{
  Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79> >::PageType *FirstPage; // eax
  Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79> >::PageType *pNext; // esi
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::PageType *v4; // eax
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::PageType *v5; // esi
  Scaleform::Render::Fence *pObject; // ecx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::PageType *v7; // eax
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::PageType *v8; // esi

  FirstPage = this->Notifiers.FirstPage;
  if ( FirstPage )
  {
    do
    {
      pNext = FirstPage->pNext;
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, FirstPage);
      FirstPage = pNext;
    }
    while ( pNext );
  }
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::KerningPairType,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeHashF> > *)&this->GlyphHTable);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Bands.Data);
  v4 = this->Glyphs.FirstPage;
  if ( v4 )
  {
    do
    {
      v5 = v4->pNext;
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
      v4 = v5;
    }
    while ( v5 );
  }
  pObject = this->ActiveSlots.Root.SlotFence.pObject;
  if ( pObject )
    Scaleform::Render::Fence::Release(pObject);
  v7 = this->Slots.FirstPage;
  if ( v7 )
  {
    do
    {
      v8 = v7->pNext;
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
      v7 = v8;
    }
    while ( v8 );
  }
}
