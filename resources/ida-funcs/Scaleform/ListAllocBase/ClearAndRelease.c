void __thiscall Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79>>::ClearAndRelease(
        Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> > *this)
{
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::PageType *FirstPage; // eax
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::PageType *pNext; // esi

  FirstPage = this->FirstPage;
  if ( this->FirstPage )
  {
    do
    {
      pNext = FirstPage->pNext;
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, FirstPage);
      FirstPage = pNext;
    }
    while ( pNext );
  }
  this->FirstPage = 0;
  this->LastPage = 0;
  this->NumElementsInPage = 127;
  this->FirstEmptySlot = 0;
}


void __thiscall Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79>>::ClearAndRelease(
        Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> > *this)
{
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::PageType *FirstPage; // eax
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::PageType *pNext; // esi

  FirstPage = this->FirstPage;
  if ( this->FirstPage )
  {
    do
    {
      pNext = FirstPage->pNext;
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, FirstPage);
      FirstPage = pNext;
    }
    while ( pNext );
  }
  this->FirstPage = 0;
  this->LastPage = 0;
  this->NumElementsInPage = 127;
  this->FirstEmptySlot = 0;
}
