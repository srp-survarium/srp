Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::PageType *__thiscall Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79>>::allocate(
        Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> > *this)
{
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::PageType *result; // eax
  unsigned int NumElementsInPage; // ecx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::PageType *v4; // eax
  void *pHeapOrPtr; // eax
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::PageType *LastPage; // ecx
  int v7; // [esp+4h] [ebp-4h] BYREF

  result = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::PageType *)this->FirstEmptySlot;
  if ( result )
  {
    this->FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::NodeType *)result->Data[0].pPrev;
  }
  else
  {
    NumElementsInPage = this->NumElementsInPage;
    if ( NumElementsInPage >= 0x7F )
    {
      pHeapOrPtr = this->pHeapOrPtr;
      v7 = 79;
      result = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::PageType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, pHeapOrPtr, 7116, &v7);
      result->pNext = 0;
      LastPage = this->LastPage;
      if ( LastPage )
        LastPage->pNext = result;
      else
        this->FirstPage = result;
      this->LastPage = result;
      this->NumElementsInPage = 1;
    }
    else
    {
      v4 = this->LastPage;
      this->NumElementsInPage = NumElementsInPage + 1;
      return (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,79> >::PageType *)((char *)v4 + 56 * NumElementsInPage);
    }
  }
  return result;
}
