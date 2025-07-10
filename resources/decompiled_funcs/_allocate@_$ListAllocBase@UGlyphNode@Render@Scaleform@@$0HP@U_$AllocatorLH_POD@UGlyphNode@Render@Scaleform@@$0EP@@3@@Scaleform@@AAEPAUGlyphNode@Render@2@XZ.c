Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::PageType *__thiscall Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79>>::allocate(
        Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> > *this)
{
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::PageType *result; // eax
  unsigned int NumElementsInPage; // ecx
  void *pHeapOrPtr; // eax
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::PageType *LastPage; // ecx
  int v6; // [esp+4h] [ebp-4h] BYREF

  result = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::PageType *)this->FirstEmptySlot;
  if ( result )
  {
    this->FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::NodeType *)result->Data[0].Param.pFont;
  }
  else
  {
    NumElementsInPage = this->NumElementsInPage;
    if ( NumElementsInPage >= 0x7F )
    {
      pHeapOrPtr = this->pHeapOrPtr;
      v6 = 79;
      result = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::PageType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, pHeapOrPtr, 5592, &v6);
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
      result = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::PageType *)((char *)this->LastPage + 44 * NumElementsInPage);
      this->NumElementsInPage = NumElementsInPage + 1;
    }
  }
  return result;
}
