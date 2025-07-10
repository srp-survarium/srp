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
