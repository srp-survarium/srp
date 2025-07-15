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


Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79> >::PageType *__thiscall Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79>>::allocate(
        Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79> > *this)
{
  Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79> >::PageType *result; // eax
  unsigned int NumElementsInPage; // ecx
  void *pHeapOrPtr; // eax
  Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79> >::PageType *LastPage; // ecx
  int v6; // [esp+4h] [ebp-4h] BYREF

  result = (Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79> >::PageType *)this->FirstEmptySlot;
  if ( result )
  {
    this->FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79> >::NodeType *)result->Data[0].pPrev;
  }
  else
  {
    NumElementsInPage = this->NumElementsInPage;
    if ( NumElementsInPage >= 0x7F )
    {
      pHeapOrPtr = this->pHeapOrPtr;
      v6 = 79;
      result = (Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79> >::PageType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, pHeapOrPtr, 2036, &v6);
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
      result = (Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79> >::PageType *)((char *)this->LastPage + 16 * NumElementsInPage);
      this->NumElementsInPage = NumElementsInPage + 1;
    }
  }
  return result;
}


Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *__thiscall Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2>>::allocate(
        Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> > *this)
{
  Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *result; // eax
  unsigned int NumElementsInPage; // ecx
  void *pHeapOrPtr; // eax
  Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *LastPage; // ecx
  int v6; // [esp+4h] [ebp-4h] BYREF

  result = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *)this->FirstEmptySlot;
  if ( result )
  {
    this->FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::NodeType *)result->Data[0].Data;
  }
  else
  {
    NumElementsInPage = this->NumElementsInPage;
    if ( NumElementsInPage >= 0x7F )
    {
      pHeapOrPtr = this->pHeapOrPtr;
      v6 = 2;
      result = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, pHeapOrPtr, 1020, &v6);
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
      result = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *)((char *)this->LastPage + 8 * NumElementsInPage);
      this->NumElementsInPage = NumElementsInPage + 1;
    }
  }
  return result;
}


Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *__thiscall Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2>>::allocate(
        Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> > *this)
{
  Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *result; // eax
  unsigned int NumElementsInPage; // ecx
  void *pHeapOrPtr; // eax
  Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *LastPage; // ecx
  int v6; // [esp+4h] [ebp-4h] BYREF

  result = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *)this->FirstEmptySlot;
  if ( result )
  {
    this->FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::NodeType *)result->Data[0].pPrev;
  }
  else
  {
    NumElementsInPage = this->NumElementsInPage;
    if ( NumElementsInPage >= 0x7F )
    {
      pHeapOrPtr = this->pHeapOrPtr;
      v6 = 2;
      result = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, pHeapOrPtr, 4068, &v6);
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
      result = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *)((char *)this->LastPage + 32 * NumElementsInPage);
      this->NumElementsInPage = NumElementsInPage + 1;
    }
  }
  return result;
}


Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *__thiscall Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2>>::allocate(
        Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> > *this)
{
  Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *result; // eax
  unsigned int NumElementsInPage; // ecx
  Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *v4; // eax
  void *pHeapOrPtr; // eax
  Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *LastPage; // ecx
  int v7; // [esp+4h] [ebp-4h] BYREF

  result = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *)this->FirstEmptySlot;
  if ( result )
  {
    this->FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)result->Data[0].RSContext;
  }
  else
  {
    NumElementsInPage = this->NumElementsInPage;
    if ( NumElementsInPage >= 0x7F )
    {
      pHeapOrPtr = this->pHeapOrPtr;
      v7 = 2;
      result = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, pHeapOrPtr, 3056, &v7);
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
      return (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *)((char *)v4 + 24 * NumElementsInPage);
    }
  }
  return result;
}
